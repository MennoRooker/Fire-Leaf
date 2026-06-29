(function () {
  "use strict";

  const NUM_TILES_PRIMARY = 640;
  const NUM_METATILES_PRIMARY = 640;
  const NUM_PALS_PRIMARY = 7;

  function decodeBase64ToU16(base64Text) {
    const binary = atob(base64Text);
    const byteLen = binary.length;
    const out = new Uint16Array(Math.floor(byteLen / 2));
    for (let i = 0, j = 0; i + 1 < byteLen; i += 2, j += 1) {
      out[j] = binary.charCodeAt(i) | (binary.charCodeAt(i + 1) << 8);
    }
    return out;
  }

  function decodeBase64ToBytes(base64Text) {
    const binary = atob(base64Text);
    const out = new Uint8Array(binary.length);
    for (let i = 0; i < binary.length; i += 1) {
      out[i] = binary.charCodeAt(i);
    }
    return out;
  }

  function decodePalettes(palettesB64) {
    const banks = [];
    for (const palB64 of palettesB64 || []) {
      const bytes = decodeBase64ToBytes(palB64);
      const bank = [];
      const text = new TextDecoder().decode(bytes);
      if (text.startsWith("JASC-PAL")) {
        const lines = text.split(/\r?\n/).map((line) => line.trim()).filter(Boolean);
        for (let i = 3; i < lines.length && bank.length < 16; i += 1) {
          const parts = lines[i].split(/\s+/);
          if (parts.length >= 3) {
            bank.push([
              Math.min(255, parseInt(parts[0], 10) || 0),
              Math.min(255, parseInt(parts[1], 10) || 0),
              Math.min(255, parseInt(parts[2], 10) || 0),
            ]);
          }
        }
      } else {
        for (let i = 0; i + 1 < bytes.length && bank.length < 16; i += 2) {
          const bgr555 = bytes[i] | (bytes[i + 1] << 8);
          const r5 = bgr555 & 0x1f;
          const g5 = (bgr555 >> 5) & 0x1f;
          const b5 = (bgr555 >> 10) & 0x1f;
          bank.push([
            (r5 << 3) | (r5 >> 2),
            (g5 << 3) | (g5 >> 2),
            (b5 << 3) | (b5 >> 2),
          ]);
        }
      }
      while (bank.length < 16) {
        bank.push([0, 0, 0]);
      }
      banks.push(bank);
    }
    while (banks.length < 16) {
      banks.push(Array.from({ length: 16 }, () => [0, 0, 0]));
    }
    return banks;
  }

  function decodeTilePixelBuffer(tilePixelSpec) {
    if (!tilePixelSpec || !tilePixelSpec.pixelsB64) {
      throw new Error("Missing tile pixel buffer");
    }
    return {
      width: tilePixelSpec.width | 0,
      height: tilePixelSpec.height | 0,
      pixels: decodeBase64ToBytes(tilePixelSpec.pixelsB64),
    };
  }

  const objectSpriteImageCache = new Map();

  function loadObjectSpriteImage(url) {
    if (!url) {
      return Promise.resolve(null);
    }
    if (objectSpriteImageCache.has(url)) {
      return objectSpriteImageCache.get(url);
    }

    const imagePromise = new Promise((resolve) => {
      const img = new Image();
      img.onload = () => resolve(img);
      img.onerror = () => resolve(null);
      img.src = url;
    });

    objectSpriteImageCache.set(url, imagePromise);
    return imagePromise;
  }

  async function drawObjectEvents(ctx, payload, xStart, yStart) {
    const objects = Array.isArray(payload.objects) ? payload.objects : [];
    if (!objects.length) {
      return;
    }

    for (const object of objects) {
      const url = String(object.spriteUrl || "");
      const img = await loadObjectSpriteImage(url);
      if (!img) {
        continue;
      }

      const mapX = Number(object.x);
      const mapY = Number(object.y);
      if (!Number.isFinite(mapX) || !Number.isFinite(mapY)) {
        continue;
      }

      const frameX = Number(object.frameX) || 0;
      const frameY = Number(object.frameY) || 0;
      const frameW = Number(object.frameW) || 16;
      const frameH = Number(object.frameH) || 16;
      const drawW = Number(object.drawW) || frameW;
      const drawH = Number(object.drawH) || frameH;

      const dx = Math.floor((mapX - xStart) * 16 + 8 - (drawW / 2));
      const dy = Math.floor((mapY - yStart) * 16 + 16 - drawH);

      // Event-object sprites are anchored near tile bottom center in-game.
      // East-facing sprites reuse the west frame mirrored horizontally, just
      // like the standard object-event anim tables.
      if (object.flip) {
        ctx.save();
        ctx.translate(dx + drawW, dy);
        ctx.scale(-1, 1);
        ctx.drawImage(img, frameX, frameY, frameW, frameH, 0, 0, drawW, drawH);
        ctx.restore();
      } else {
        ctx.drawImage(img, frameX, frameY, frameW, frameH, dx, dy, drawW, drawH);
      }
    }
  }

  function paintTile(out, outW, outH, primaryTiles, secondaryTiles, primaryPalettes, secondaryPalettes, tileRef, dx, dy) {
    const tileId = tileRef & 0x3ff;
    const hFlip = (tileRef & 0x400) !== 0;
    const vFlip = (tileRef & 0x800) !== 0;
    const paletteBank = (tileRef >> 12) & 0xf;
    const tileSource = tileId < NUM_TILES_PRIMARY ? primaryTiles : secondaryTiles;
    const localTileId = tileId < NUM_TILES_PRIMARY ? tileId : tileId - NUM_TILES_PRIMARY;
    const tileTexW = tileSource.width;
    const paletteBanks = paletteBank < NUM_PALS_PRIMARY ? primaryPalettes : secondaryPalettes;
    const pal = paletteBanks[paletteBank] || paletteBanks[0];
    const sx = (localTileId % Math.floor(tileTexW / 8)) * 8;
    const sy = Math.floor(localTileId / Math.floor(tileTexW / 8)) * 8;

    for (let py = 0; py < 8; py += 1) {
      for (let px = 0; px < 8; px += 1) {
        const srcX = sx + (hFlip ? 7 - px : px);
        const srcY = sy + (vFlip ? 7 - py : py);
        const srcIdx = srcY * tileTexW + srcX;
        const colorIndex = tileSource.pixels[srcIdx] & 0xf;
        if (colorIndex === 0) {
          continue;
        }
        const tx = dx + px;
        const ty = dy + py;
        if (tx < 0 || ty < 0 || tx >= outW || ty >= outH) {
          continue;
        }
        const [r, g, b] = pal[colorIndex] || [0, 0, 0];
        const di = (ty * outW + tx) * 4;
        out[di] = r;
        out[di + 1] = g;
        out[di + 2] = b;
        out[di + 3] = 255;
      }
    }
  }

  function drawMetatile(out, outW, outH, metatileRefs, primaryTiles, secondaryTiles, primaryPalettes, secondaryPalettes, blockX, blockY) {
    const px = blockX * 16;
    const py = blockY * 16;

    paintTile(out, outW, outH, primaryTiles, secondaryTiles, primaryPalettes, secondaryPalettes, metatileRefs[0], px, py);
    paintTile(out, outW, outH, primaryTiles, secondaryTiles, primaryPalettes, secondaryPalettes, metatileRefs[1], px + 8, py);
    paintTile(out, outW, outH, primaryTiles, secondaryTiles, primaryPalettes, secondaryPalettes, metatileRefs[2], px, py + 8);
    paintTile(out, outW, outH, primaryTiles, secondaryTiles, primaryPalettes, secondaryPalettes, metatileRefs[3], px + 8, py + 8);

    paintTile(out, outW, outH, primaryTiles, secondaryTiles, primaryPalettes, secondaryPalettes, metatileRefs[4], px, py);
    paintTile(out, outW, outH, primaryTiles, secondaryTiles, primaryPalettes, secondaryPalettes, metatileRefs[5], px + 8, py);
    paintTile(out, outW, outH, primaryTiles, secondaryTiles, primaryPalettes, secondaryPalettes, metatileRefs[6], px, py + 8);
    paintTile(out, outW, outH, primaryTiles, secondaryTiles, primaryPalettes, secondaryPalettes, metatileRefs[7], px + 8, py + 8);
  }

  async function renderCanvas(canvas, payload) {
    const width = payload.width | 0;
    const height = payload.height | 0;
    if (width <= 0 || height <= 0) {
      throw new Error("Invalid map dimensions");
    }

    const crop = payload.crop || {};
    const x0 = crop.x0 != null ? Number(crop.x0) : 0;
    const x1 = crop.x1 != null ? Number(crop.x1) : 1;
    const y0 = crop.y0 != null ? Number(crop.y0) : 0;
    const y1 = crop.y1 != null ? Number(crop.y1) : 1;
    const xStart = Math.max(0, Math.floor(width * x0));
    const xEnd = Math.min(width, Math.ceil(width * x1));
    const yStart = Math.max(0, Math.floor(height * y0));
    const yEnd = Math.min(height, Math.ceil(height * y1));
    const cropWidth = xEnd - xStart;
    const cropHeight = yEnd - yStart;
    if (cropWidth <= 0 || cropHeight <= 0) {
      throw new Error("Invalid map crop");
    }

    const blockdata = decodeBase64ToU16(payload.blockdataB64);
    const primaryMetatiles = decodeBase64ToU16(payload.primaryMetatilesB64);
    const secondaryMetatiles = decodeBase64ToU16(payload.secondaryMetatilesB64);
    const primaryPalettes = decodePalettes(payload.primaryPalettesB64 || []);
    const secondaryPalettes = decodePalettes(payload.secondaryPalettesB64 || []);
    const primaryTiles = decodeTilePixelBuffer(payload.primaryTilePixels);
    const secondaryTiles = decodeTilePixelBuffer(payload.secondaryTilePixels);

    const secondaryMetatileCount = Math.floor(secondaryMetatiles.length / 8);

    const pixelWidth = cropWidth * 16;
    const pixelHeight = cropHeight * 16;
    canvas.width = pixelWidth;
    canvas.height = pixelHeight;

    const ctx = canvas.getContext("2d", { alpha: true, willReadFrequently: false });
    if (!ctx) {
      throw new Error("Could not get canvas context");
    }
    ctx.imageSmoothingEnabled = false;

    const imageData = ctx.createImageData(pixelWidth, pixelHeight);
    const out = imageData.data;

    const blockCount = Math.min(blockdata.length, width * height);
    for (let i = 0; i < blockCount; i += 1) {
      const block = blockdata[i] & 0x3ff;
      const x = i % width;
      const y = Math.floor(i / width);
      if (x < xStart || x >= xEnd || y < yStart || y >= yEnd) {
        continue;
      }

      if (block < NUM_METATILES_PRIMARY) {
        const base = block * 8;
        if (base + 8 > primaryMetatiles.length) {
          continue;
        }
        drawMetatile(out, pixelWidth, pixelHeight, primaryMetatiles.subarray(base, base + 8), primaryTiles, secondaryTiles, primaryPalettes, secondaryPalettes, x - xStart, y - yStart);
      } else {
        const secondaryBlock = block - NUM_METATILES_PRIMARY;
        if (secondaryBlock < 0 || secondaryBlock >= secondaryMetatileCount) {
          continue;
        }
        const base = secondaryBlock * 8;
        drawMetatile(out, pixelWidth, pixelHeight, secondaryMetatiles.subarray(base, base + 8), primaryTiles, secondaryTiles, primaryPalettes, secondaryPalettes, x - xStart, y - yStart);
      }
    }

    ctx.putImageData(imageData, 0, 0);
    await drawObjectEvents(ctx, payload, xStart, yStart);
  }

  function showFallback(mapLeft, message) {
    const fallback = mapLeft.querySelector(".map-fallback");
    if (!fallback) {
      return;
    }
    if (message) {
      fallback.textContent = message;
    }
    mapLeft.classList.remove("map-ready");
  }

  function getMapFullHeightPx() {
    const raw = getComputedStyle(document.documentElement).getPropertyValue("--map-full-height").trim();
    const value = parseFloat(raw);
    if (Number.isFinite(value) && value > 0) {
      return value;
    }
    return 900;
  }

  function isFullHeight(payload, canvas) {
    if (payload && payload.fullHeight) {
      return true;
    }
    const raw = canvas.getAttribute("data-map-full-height");
    return raw === "true" || raw === "1";
  }

  function readMapScaleMax(canvas, payload) {
    if (payload && payload.mapScaleMax != null) {
      const fromPayload = Number(payload.mapScaleMax);
      if (Number.isFinite(fromPayload) && fromPayload > 0 && fromPayload <= 1) {
        return fromPayload;
      }
    }

    const raw = canvas.getAttribute("data-map-scale-max");
    if (raw == null || raw == "" ) {
      return 1;
    }
    const value = Number(raw);
    if (!Number.isFinite(value) || value <= 0 || value > 1) {
      return 1;
    }
    return value;
  }

  function getAvailableMapWidth(mapLeft) {
    const mapPane = mapLeft.closest(".map-pane");
    if (!mapPane) {
      return mapLeft.clientWidth;
    }

    const paneStyle = getComputedStyle(mapPane);
    const paneWidth = mapPane.getBoundingClientRect().width;
    const panePadding =
      (parseFloat(paneStyle.paddingLeft) || 0) +
      (parseFloat(paneStyle.paddingRight) || 0);
    let availableWidth = paneWidth - panePadding;

    const encounters = mapPane.querySelector(".encounters");
    if (encounters) {
      const encountersWidth = encounters.getBoundingClientRect().width;
      const columnGap =
        parseFloat(paneStyle.columnGap) ||
        parseFloat(paneStyle.gap) ||
        0;
      availableWidth -= encountersWidth + columnGap;
    }

    const mapLeftStyle = getComputedStyle(mapLeft);
    const borderWidth =
      (parseFloat(mapLeftStyle.borderLeftWidth) || 0) +
      (parseFloat(mapLeftStyle.borderRightWidth) || 0);
    availableWidth -= borderWidth;

    return Math.max(0, Math.floor(availableWidth));
  }

  function fitCanvasToContainer(canvas, mapLeft, payload) {
    const intrinsicW = canvas.width;
    const intrinsicH = canvas.height;
    if (intrinsicW <= 0 || intrinsicH <= 0) {
      return;
    }

    const mapPane = mapLeft.closest(".map-pane");
    const hasEncounters = Boolean(mapPane && mapPane.querySelector(".encounters"));
    const containerW = getAvailableMapWidth(mapLeft);
    if (containerW <= 0) {
      return;
    }

    const fullHeight = isFullHeight(payload, canvas);
    const mapFullHeightPx = getMapFullHeightPx();

    // Never force the container to a fixed height. fullHeight only raises the
    // ceiling the map may scale up to (mapFullHeightPx); the border still
    // shrink-wraps the scaled canvas, so maps limited by width stop short of
    // 900px instead of leaving vertical gaps.
    mapLeft.style.minHeight = "";

    let scale;
    if (fullHeight) {
      scale = Math.min(containerW / intrinsicW, mapFullHeightPx / intrinsicH)
    }
    else if (hasEncounters) {
      const containerH = mapLeft.clientHeight;
      if (containerH <= 0) {
        return;
      }
      scale = Math.min(containerW / intrinsicW, containerH / intrinsicH);
    } else {
      scale = containerW / intrinsicW;
    }

    scale *= readMapScaleMax(canvas, payload);

    if (!Number.isFinite(scale) || scale <= 0) {
      return;
    }

    canvas.style.width = `${Math.floor(intrinsicW * scale)}px`;
    canvas.style.height = `${Math.floor(intrinsicH * scale)}px`;
  }

  function observeMapFit(canvas, mapLeft, payload) {
    const mapPane = mapLeft.closest(".map-pane");
    const refit = () => {
      if (!mapLeft.classList.contains("map-ready")) {
        return;
      }
      fitCanvasToContainer(canvas, mapLeft, payload);
    };

    if (typeof ResizeObserver === "undefined") {
      window.addEventListener("resize", refit);
      return;
    }

    const observer = new ResizeObserver(refit);
    observer.observe(mapLeft);
    if (mapPane) {
      observer.observe(mapPane);
    }
  }

  function markShortTrainerParties() {
    const cards = document.querySelectorAll(".trainer-card");
    for (const card of cards) {
      const mons = card.querySelector(".mons");
      if (!mons) {
        continue;
      }

      const monCount = mons.querySelectorAll(":scope > .mon").length;
      if (monCount > 0 && monCount < 6) {
        card.classList.add("trainer-card--party-trim");
      } else {
        card.classList.remove("trainer-card--party-trim");
      }
    }
  }

  async function init() {
    markShortTrainerParties();

    const dataEl = document.getElementById("overview-map-data");
    if (!dataEl || !dataEl.textContent) {
      return;
    }

    let data;
    try {
      data = JSON.parse(dataEl.textContent);
    } catch (_err) {
      return;
    }

    const canvases = document.querySelectorAll(".map-canvas[data-map-key]");
    for (const canvas of canvases) {
      const key = canvas.getAttribute("data-map-key") || "";
      const payload = data[key];
      const mapLeft = canvas.closest(".map-left");
      if (!mapLeft) {
        continue;
      }
      if (!payload) {
        showFallback(mapLeft, "No map data available yet");
        continue;
      }

      try {
        await renderCanvas(canvas, payload);
        fitCanvasToContainer(canvas, mapLeft, payload);
        mapLeft.classList.add("map-ready");
        observeMapFit(canvas, mapLeft, payload);
      } catch (_err) {
        showFallback(mapLeft, "No map image yet");
      }
    }

    requestAnimationFrame(() => {
      for (const canvas of canvases) {
        const key = canvas.getAttribute("data-map-key") || "";
        const payload = data[key]
        const mapLeft = canvas.closest(".map-left");
        if (mapLeft && mapLeft.classList.contains("map-ready")) {
          fitCanvasToContainer(canvas, mapLeft, payload);
        }
      }
    });
  }

  if (document.readyState === "loading") {
    document.addEventListener("DOMContentLoaded", init);
  } else {
    init();
  }
})();
