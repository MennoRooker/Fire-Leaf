(function () {
	"use strict";

	const STORAGE_KEY = "overview-state-v1";
	const SCROLL_SAVE_DEBOUNCE_MS = 150;

	let scrollSaveTimer = null;

	function safeParse(raw) {
		if (!raw) {
			return null;
		}
		try {
			return JSON.parse(raw);
		} catch (_err) {
			return null;
		}
	}

	function safeLoadState() {
		try {
			return safeParse(localStorage.getItem(STORAGE_KEY));
		} catch (_err) {
			return null;
		}
	}

	function safeSaveState(state) {
		try {
			localStorage.setItem(STORAGE_KEY, JSON.stringify(state));
		} catch (_err) {
			// Ignore quota/privacy-mode failures.
		}
	}

	function collectState() {
		const controlStates = {};
		const controls = document.querySelectorAll(".overview-toggle-input[id]");
		for (const control of controls) {
			controlStates[control.id] = !!control.checked;
		}

		let starterToken = "";
		const starterToggles = document.querySelectorAll(".starter-filter-toggle");
		for (const toggle of starterToggles) {
			if (!toggle.checked) {
				continue;
			}
			starterToken = toggle.getAttribute("data-starter-token") || "";
			break;
		}

		const sectionStates = {};
		const sectionToggles = document.querySelectorAll(".section-collapse-toggle");
		for (const toggle of sectionToggles) {
			const contentId = toggle.getAttribute("aria-controls") || "";
			if (!contentId) {
				continue;
			}
			sectionStates[contentId] = toggle.getAttribute("aria-expanded") === "true";
		}

		return {
			scrollY: Math.max(0, Math.round(window.scrollY || window.pageYOffset || 0)),
			controls: controlStates,
			starterToken,
			sections: sectionStates,
		};
	}

	function dispatchChange(input) {
		input.dispatchEvent(new Event("change", { bubbles: true }));
	}

	function restoreControls(state) {
		const controls = state && state.controls && typeof state.controls === "object" ? state.controls : null;
		if (!controls) {
			return;
		}

		for (const [id, checked] of Object.entries(controls)) {
			const input = document.getElementById(id);
			if (!input || input.checked === !!checked) {
				continue;
			}
			input.checked = !!checked;
			dispatchChange(input);
		}
	}

	function restoreStarterFilter(state) {
		const token = state && typeof state.starterToken === "string" ? state.starterToken : "";
		const toggles = document.querySelectorAll(".starter-filter-toggle");
		if (!toggles.length) {
			return;
		}

		if (!token) {
			for (const toggle of toggles) {
				if (!toggle.checked) {
					continue;
				}
				toggle.checked = false;
				dispatchChange(toggle);
			}
			return;
		}

		const matchingToggle = document.querySelector(`.starter-filter-toggle[data-starter-token="${token}"]`);
		if (!matchingToggle || matchingToggle.checked) {
			return;
		}

		matchingToggle.checked = true;
		dispatchChange(matchingToggle);
	}

	function restoreSectionStates(state) {
		const sections = state && state.sections && typeof state.sections === "object" ? state.sections : null;
		if (!sections) {
			return;
		}

		for (const [contentId, expanded] of Object.entries(sections)) {
			const toggle = document.querySelector(`.section-collapse-toggle[aria-controls="${contentId}"]`);
			const content = document.getElementById(contentId);
			if (!toggle || !content) {
				continue;
			}

			const shouldBeExpanded = !!expanded;
			toggle.setAttribute("aria-expanded", shouldBeExpanded ? "true" : "false");
			content.hidden = !shouldBeExpanded;
		}
	}

	function restoreScroll(state) {
		const scrollY = state && Number.isFinite(state.scrollY) ? state.scrollY : 0;
		if (scrollY <= 0) {
			return;
		}

		const apply = () => {
			window.scrollTo(0, scrollY);
		};

		// Apply immediately, then again after likely layout-affecting work
		// (map fitting, image decode, font metrics) to avoid ending up slightly high.
		apply();
		requestAnimationFrame(() => {
			apply();
			requestAnimationFrame(apply);
		});
		window.setTimeout(apply, 120);
		window.setTimeout(apply, 320);
		window.addEventListener("load", () => {
			apply();
			window.setTimeout(apply, 80);
		}, { once: true });
	}

	function saveNow() {
		safeSaveState(collectState());
	}

	function scheduleScrollSave() {
		if (scrollSaveTimer !== null) {
			window.clearTimeout(scrollSaveTimer);
		}
		scrollSaveTimer = window.setTimeout(() => {
			scrollSaveTimer = null;
			saveNow();
		}, SCROLL_SAVE_DEBOUNCE_MS);
	}

	function restoreState() {
		const state = safeLoadState();
		if (!state) {
			return;
		}

		restoreControls(state);
		restoreStarterFilter(state);
		restoreSectionStates(state);

		// Run after layout so hidden/expanded state is reflected before scrolling.
		requestAnimationFrame(() => {
			restoreScroll(state);
		});
	}

	function setupPersistence() {
		document.addEventListener("change", (event) => {
			const target = event.target;
			if (!(target instanceof HTMLInputElement)) {
				return;
			}
			if (!target.classList.contains("overview-toggle-input") && !target.classList.contains("starter-filter-toggle")) {
				return;
			}
			saveNow();
		});

		document.addEventListener("click", (event) => {
			const target = event.target;
			if (!(target instanceof Element) || !target.closest(".section-collapse-toggle")) {
				return;
			}
			requestAnimationFrame(saveNow);
		});

		window.addEventListener("scroll", scheduleScrollSave, { passive: true });
		window.addEventListener("pagehide", saveNow);
		window.addEventListener("beforeunload", saveNow);
	}

	function init() {
		restoreState();
		setupPersistence();
	}

	if (document.readyState === "loading") {
		document.addEventListener("DOMContentLoaded", init);
	} else {
		init();
	}
})();
