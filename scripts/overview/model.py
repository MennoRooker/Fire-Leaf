from __future__ import annotations

import json
import re
import sys
from pathlib import Path
from typing import Dict, List, Optional, Union

SectionOrderEntry = Union[str, int]
SectionOrderPlan = List[SectionOrderEntry]

from .parsing import (
    ENCOUNTER_KIND_ORDER,
    ENCOUNTER_KIND_TITLES,
    parse_charmap_single_byte_table,
    parse_define_ints,
    parse_firered_encounters,
    parse_item_names,
    parse_item_icon_table,
    parse_item_icon_symbol_to_paths,
    parse_level_up_learnsets_by_species,
    parse_layouts_by_id,
    parse_map_layout_records,
    parse_mon_symbol_to_png_path,
    parse_move_names,
    parse_move_types,
    parse_nature_constants,
    parse_nature_stat_modifiers,
    parse_ordered_species_front_symbols,
    parse_ordered_trainer_front_symbols,
    parse_parties,
    parse_species_info_types_and_abilities,
    parse_species_names,
    parse_trainer_class_names,
    parse_trainer_symbol_to_png_path,
    parse_trainers,
    parse_tileset_metatile_paths,
    resolve_tileset_tiles_png_path,
    parse_type_icon_specs,
    pretty_token
)


SECTION_THEME_OVERRIDES: Dict[str, str] = {
    "pewter city": "city-pewter",
    "pewter city gym": "gym-pewter",
    "cerulean city": "city-cerulean",
    "cerulean city gym": "gym-cerulean",
    "vermilion city": "city-vermilion",
    "vermillion city gym": "gym-vermilion",
    "celadon city": "city-celadon",
    "celadon city gym": "gym-celadon",
    "saffron city dojo": "city-cinnabar",
    "fuchsia city": "city-fuchsia",
    "saffron city": "city-saffron",
    "viridian city": "city-viridian",
    "cinnabar island": "city-cinnabar",
    "cinnabar island gym": "gym-cinnabar",
    "fuchsia city gym": "gym-fuchsia",
    "saffron city gym": "gym-saffron",
    "viridian city gym": "gym-viridian",
    # Elite Four
    "lorelei": "e4-lorelei",
    "bruno": "e4-bruno",
    "agatha": "e4-agatha",
    "lance": "e4-lance",
}

SECTION_MAP_TOKEN_OVERRIDES: Dict[str, str] = {
    "oak's lab": "PALLET_TOWN_PROFESSOR_OAKS_LAB",
}

OVERVIEW_DIR = Path(__file__).resolve().parent


def load_section_overrides() -> Dict[str, object]:
    path = OVERVIEW_DIR / "section_overrides.json"
    if not path.exists():
        return {"sections": {}, "merges": {}}
    data = json.loads(path.read_text(encoding="utf-8"))
    return {
        "sections": data.get("sections", {}),
        "merges": data.get("merges", {}),
    }


def load_section_order_plan() -> SectionOrderPlan:
    path = OVERVIEW_DIR / "section_order.json"
    if not path.exists():
        return []
    data = json.loads(path.read_text(encoding="utf-8"))
    raw_plan = data.get("plan", [])
    if not isinstance(raw_plan, list):
        print("Warning: section_order.json 'plan' must be an array.", file=sys.stderr)
        return []

    plan: SectionOrderPlan = []
    for idx, entry in enumerate(raw_plan):
        if isinstance(entry, str):
            name = entry.strip()
            if name:
                plan.append(name)
            continue
        if isinstance(entry, int) and not isinstance(entry, bool):
            if entry < 0:
                print(f"Warning: section_order.json plan[{idx}] must be non-negative, got {entry}.", file=sys.stderr)
                continue
            if entry:
                plan.append(entry)
            continue
        print(
            f"Warning: section_order.json plan[{idx}] must be a string or integer, got {type(entry).__name__}.",
            file=sys.stderr,
        )
    return plan


def planned_section_names(plan: SectionOrderPlan) -> List[str]:
    return [entry for entry in plan if isinstance(entry, str)]


def apply_section_order_plan(
    plan: SectionOrderPlan,
    standard_order: List[str],
    available_sections: set[str],
) -> List[str]:
    """Build section order from an explicit plan plus trainer_parties.h standard order."""
    standard_queue = [name for name in standard_order if name in available_sections]
    placed: set[str] = set()
    result: List[str] = []
    queue_idx = 0

    def next_from_standard() -> Optional[str]:
        nonlocal queue_idx
        while queue_idx < len(standard_queue):
            name = standard_queue[queue_idx]
            queue_idx += 1
            if name not in placed:
                return name
        return None

    def place(name: str, source: str) -> None:
        if name in placed:
            print(f"Warning: section order plan repeats '{name}' ({source}); skipping duplicate.", file=sys.stderr)
            return
        if name not in available_sections:
            print(f"Warning: section order plan references unknown section '{name}' ({source}); skipping.", file=sys.stderr)
            return
        result.append(name)
        placed.add(name)

    for idx, entry in enumerate(plan):
        if isinstance(entry, int):
            for _ in range(entry):
                name = next_from_standard()
                if name is None:
                    print(
                        f"Warning: section order plan[{idx}] requested {entry} standard sections, "
                        "but the standard-order queue ran out early.",
                        file=sys.stderr,
                    )
                    break
                place(name, f"plan[{idx}] auto")
            continue
        place(entry, f"plan[{idx}]")

    while True:
        name = next_from_standard()
        if name is None:
            break
        place(name, "remaining standard order")

    return result


def apply_section_merges(
    sections: Dict[str, List[Dict[str, object]]],
    ordered_section_names: List[str],
    merge_overrides: Dict[str, object],
) -> tuple[Dict[str, List[Dict[str, object]]], List[str], Dict[str, List[Dict[str, object]]]]:
    if not merge_overrides:
        return sections, ordered_section_names, {}

    merge_sources: set[str] = set()
    names = list(ordered_section_names)
    trainer_groups: Dict[str, List[Dict[str, object]]] = {}

    for merge_name, merge_cfg in merge_overrides.items():
        if not isinstance(merge_cfg, dict):
            continue
        sources = [str(s) for s in merge_cfg.get("sources", [])]
        if not sources:
            continue

        source_labels = merge_cfg.get("sourceLabels")
        if not isinstance(source_labels, list):
            source_labels = []

        merge_sources.update(sources)
        groups: List[Dict[str, object]] = []
        combined: List[Dict[str, object]] = []
        for idx, source in enumerate(sources):
            source_trainers = list(sections.get(source, []))
            if idx < len(source_labels):
                label = str(source_labels[idx])
            elif source.startswith(f"{merge_name} "):
                label = source[len(merge_name) + 1 :]
            else:
                label = source
            groups.append({"label": label, "trainers": source_trainers})
            combined.extend(source_trainers)

        sections[merge_name] = combined
        if len(groups) > 1:
            trainer_groups[merge_name] = groups

        insert_idx = len(names)
        for source in sources:
            if source in names:
                insert_idx = min(insert_idx, names.index(source))
        names = [n for n in names if n not in sources]
        if merge_name in names:
            names.remove(merge_name)
        names.insert(insert_idx, merge_name)

    for source in merge_sources:
        sections.pop(source, None)

    return sections, names, trainer_groups


def lookup_map_record(map_token: str, map_by_token: Dict[str, Dict[str, str]]) -> Optional[Dict[str, str]]:
    candidates = [
        map_token,
        normalize_map_token(map_token),
        map_token.replace("_", ""),
        normalize_map_token(map_token).replace("_", ""),
    ]
    for candidate in candidates:
        if candidate and candidate in map_by_token:
            return map_by_token[candidate]

    variants = {
        map_token.replace("_", ""),
        map_token.replace("SAFFRON_CITY_SILPH_CO", "SILPH_CO"),
    }
    for variant in variants:
        if variant and variant in map_by_token:
            return map_by_token[variant]
    return None


def slugify(name: str) -> str:
    s = re.sub(r"[^A-Za-z0-9]+", "_", name).strip("_")
    return s.lower() or "section"


def normalize_for_match(name: str) -> str:
    return slugify(name).upper().replace("_", "")


def normalize_map_token(map_token: str) -> str:
    """Insert underscores between letter/digit boundaries within each token segment."""
    parts: List[str] = []
    for raw in map_token.split("_"):
        token = raw.strip()
        if not token:
            continue
        expanded = re.sub(r"([A-Za-z])(\d)", r"\1_\2", token)
        expanded = re.sub(r"(\d)([A-Za-z])", r"\1_\2", expanded)
        parts.extend(part for part in expanded.split("_") if part)
    return "_".join(parts)


def build_section_name_registry(names: List[str]) -> Dict[str, str]:
    registry: Dict[str, str] = {}
    for name in names:
        norm = normalize_for_match(name)
        if norm:
            registry.setdefault(norm, name)
    return registry


def resolve_canonical_section_name(name: str, registry: Dict[str, str]) -> str:
    norm = normalize_for_match(name)
    if norm and norm in registry:
        return registry[norm]
    return name


def is_redundant_section_name(name: str, known_names: set[str]) -> bool:
    norm = normalize_for_match(name)
    if not norm:
        return False
    known_norms = {normalize_for_match(known) for known in known_names}
    if norm in known_norms:
        return True
    prefix = f"{name} "
    return any(known.startswith(prefix) for known in known_names)


def camel_words(name: str) -> str:
    return re.sub(r"([a-z0-9])([A-Z])", r"\1 \2", name.replace("_", " ")).strip()


def map_token_to_section_name(map_token: str) -> str:
    map_token = normalize_map_token(map_token)
    parts: List[str] = []
    for raw in map_token.split("_"):
        token = raw.strip()
        if not token:
            continue
        upper = token.upper()
        if re.fullmatch(r"B\d+F|\d+F", upper):
            parts.append(upper)
        elif len(upper) <= 2 and upper.isalpha():
            parts.append(upper)
        else:
            parts.append(upper[:1] + upper[1:].lower())
    return " ".join(parts) or pretty_token(map_token, "")


def resolve_section_theme(section_name: str) -> str:
    key = section_name.strip().lower()
    if key in SECTION_THEME_OVERRIDES:
        return SECTION_THEME_OVERRIDES[key]

    if key in {
        "route 19 water",
        "route 20 east",
        "route 20 west",
        "route 21 north",
        "route 21 south",
    }:
        return "route-water"

    if "safari zone" in key:
        return "forest"

    if "forest" in key:
        return "forest"

    cave_markers = (
        "cave",
        "tunnel",
        "mt.",
        "mount",
        "rock tunnel",
        "victory road",
        "hideout",
        "rocket hideout",
        "pokemon tower",
    )
    if any(marker in key for marker in cave_markers):
        return "cave"
    if re.search(r"\broute\b", key):
        return "route"
    if re.search(r"\bgym\b", key):
        return "gym-generic"
    if any(token in key for token in ("city", "town", "island")):
        return "city-generic"
    return "default"


def build_model(section_filter: Optional[str]) -> Dict[str, object]:
    overrides = load_section_overrides()
    section_overrides: Dict[str, Dict[str, object]] = dict(overrides.get("sections", {}))
    merge_overrides: Dict[str, object] = dict(overrides.get("merges", {}))

    trainers = parse_trainers()
    parties_data = parse_parties()
    parties = parties_data["parties"]
    party_section_order = parties_data["sectionOrder"]
    species_names = parse_species_names()
    move_names = parse_move_names()
    trainer_class_names = parse_trainer_class_names()
    move_types = parse_move_types()
    nature_constants = parse_nature_constants()
    nature_stat_modifiers = parse_nature_stat_modifiers()
    level_up_learnsets = parse_level_up_learnsets_by_species()
    charmap_single_byte = parse_charmap_single_byte_table()
    species_info = parse_species_info_types_and_abilities()
    item_names = parse_item_names()
    item_icon_table = parse_item_icon_table()
    item_icon_paths = parse_item_icon_symbol_to_paths()
    trainer_pic_ids = parse_define_ints("include/constants/trainers.h", "TRAINER_PIC_")
    species_ids = parse_define_ints("include/constants/species.h", "SPECIES_")
    trainer_front_syms = parse_ordered_trainer_front_symbols()
    mon_front_syms = parse_ordered_species_front_symbols()
    trainer_sym_to_png = parse_trainer_symbol_to_png_path()
    mon_sym_to_png = parse_mon_symbol_to_png_path()
    type_icon_specs = parse_type_icon_specs()
    wild_encounters = parse_firered_encounters()
    layouts_by_id = parse_layouts_by_id()
    map_layout_data = parse_map_layout_records()
    map_records = list(map_layout_data["records"])
    map_by_token = dict(map_layout_data["byToken"])
    metatile_paths_by_symbol = parse_tileset_metatile_paths()
    encounter_map_tokens = list(wild_encounters["byMap"].keys())
    section_name_registry = build_section_name_registry(party_section_order)
    encounter_map_by_section: Dict[str, str] = {}
    for map_token in encounter_map_tokens:
        normalized_token = normalize_map_token(map_token)
        section_name = resolve_canonical_section_name(
            map_token_to_section_name(normalized_token),
            section_name_registry,
        )
        encounter_map_by_section.setdefault(section_name, normalized_token)

    map_by_norm_section: Dict[str, Dict[str, str]] = {}
    for record in map_records:
        candidates = {
            map_token_to_section_name(record["mapToken"]),
            camel_words(record["mapName"]),
            record["mapName"],
        }
        for candidate in candidates:
            norm = normalize_for_match(candidate)
            if norm:
                map_by_norm_section.setdefault(norm, record)

    def override_map_token(section_name: str) -> Optional[str]:
        sect_cfg = section_overrides.get(section_name, {})
        if isinstance(sect_cfg, dict) and sect_cfg.get("mapToken"):
            return str(sect_cfg["mapToken"])
        merge_cfg = merge_overrides.get(section_name, {})
        if isinstance(merge_cfg, dict) and merge_cfg.get("mapToken"):
            return str(merge_cfg["mapToken"])
        return None

    def override_encounters_map_token(section_name: str) -> Optional[str]:
        sect_cfg = section_overrides.get(section_name, {})
        if isinstance(sect_cfg, dict) and sect_cfg.get("encountersMapToken"):
            return str(sect_cfg["encountersMapToken"])
        return override_map_token(section_name)

    def resolve_section_map_record(section_name: str) -> Optional[Dict[str, str]]:
        json_token = override_map_token(section_name)
        if json_token:
            record = lookup_map_record(json_token, map_by_token)
            if record:
                return record

        override = SECTION_MAP_TOKEN_OVERRIDES.get(section_name.strip().lower())
        if override:
            record = lookup_map_record(override, map_by_token)
            if record:
                return record

        encounter_token = encounter_map_by_section.get(section_name)
        if encounter_token:
            record = lookup_map_record(encounter_token, map_by_token)
            if record:
                return record

        section_key = normalize_for_match(section_name)
        if section_key in map_by_norm_section:
            return map_by_norm_section[section_key]

        # Fallback for manually titled sections that are only partial map names.
        # Prefer the most specific (longest) compatible token and avoid
        # numeric prefix collisions like ROUTE1 matching ROUTE19.
        candidates: List[tuple[int, Dict[str, str]]] = []
        for record in map_records:
            map_norm = normalize_for_match(record["mapToken"])
            if not section_key:
                continue

            if section_key.startswith(map_norm) and len(section_key) > len(map_norm):
                next_ch = section_key[len(map_norm)]
                if next_ch.isdigit():
                    continue

            if map_norm.startswith(section_key) and len(map_norm) > len(section_key):
                next_ch = map_norm[len(section_key)]
                if next_ch.isdigit():
                    continue

            if section_key in map_norm or map_norm in section_key:
                candidates.append((len(map_norm), record))

        if candidates:
            candidates.sort(key=lambda x: x[0], reverse=True)
            return candidates[0][1]

        return None

    def tileset_to_metatile_path(tileset_symbol: str) -> Optional[str]:
        metatiles_symbol = tileset_symbol.replace("gTileset_", "gMetatiles_")
        return metatile_paths_by_symbol.get(metatiles_symbol)

    def build_map_render(section_name: str) -> Optional[Dict[str, object]]:
        map_record = resolve_section_map_record(section_name)
        if not map_record:
            return None

        layout = layouts_by_id.get(map_record["layout"])
        if not layout:
            return None

        primary_tileset = str(layout.get("primary_tileset", ""))
        secondary_tileset = str(layout.get("secondary_tileset", ""))
        blockdata_path = str(layout.get("blockdata_filepath", ""))
        if not (primary_tileset and secondary_tileset and blockdata_path):
            return None

        primary_metatiles = tileset_to_metatile_path(primary_tileset)
        secondary_metatiles = tileset_to_metatile_path(secondary_tileset)
        primary_tiles_png = (
            resolve_tileset_tiles_png_path(primary_tileset, primary_metatiles) 
            if primary_metatiles 
            else None
        )
        secondary_tiles_png = (
            resolve_tileset_tiles_png_path(secondary_tileset, secondary_metatiles) 
            if secondary_metatiles 
            else None
        )
        if not (primary_metatiles and secondary_metatiles and primary_tiles_png and secondary_tiles_png):
            return None

        result: Dict[str, object] = {
            "mapId": map_record["mapId"],
            "mapName": map_record["mapName"],
            "mapToken": map_record["mapToken"],
            "mapJsonPath": map_record["mapJsonPath"],
            "layoutId": str(layout.get("id", "")),
            "width": int(layout.get("width", 0)),
            "height": int(layout.get("height", 0)),
            "blockdataPath": blockdata_path,
            "primary": {
                "tileset": primary_tileset,
                "metatilesPath": primary_metatiles,
                "tilesPngPath": primary_tiles_png,
            },
            "secondary": {
                "tileset": secondary_tileset,
                "metatilesPath": secondary_metatiles,
                "tilesPngPath": secondary_tiles_png,
            },
        }
        sect_cfg = section_overrides.get(section_name, {})
        if isinstance(sect_cfg, dict) and sect_cfg.get("crop"):
            result["crop"] = sect_cfg["crop"]
        return result

    def trainer_pic_path(pic_token: str) -> str:
        idx = trainer_pic_ids.get(pic_token)
        if idx is None or idx >= len(trainer_front_syms):
            return "graphics/trainers/front_pics/youngster_front_pic.png"
        return trainer_sym_to_png.get(trainer_front_syms[idx], "graphics/trainers/front_pics/youngster_front_pic.png")

    def species_front_path(species_token: str) -> str:
        if species_token == "SPECIES_CASTFORM":
            return "graphics/pokemon/castform/normal/front.png"
        idx = species_ids.get(species_token)
        if idx is None or idx >= len(mon_front_syms):
            return "graphics/pokemon/question_mark/front.png"
        return mon_sym_to_png.get(mon_front_syms[idx], "graphics/pokemon/question_mark/front.png")

    def format_nature_effect(nature_token: str) -> str:
        mods = nature_stat_modifiers.get(nature_token)
        if not mods:
            return ""

        stat_labels = ["atk", "def", "spd", "spatk", "spdef"]
        raised = ""
        lowered = ""
        for idx, mod in enumerate(mods):
            if mod > 0:
                raised = stat_labels[idx]
            elif mod < 0:
                lowered = stat_labels[idx]

        if not raised and not lowered:
            return "(neutral)"
        if raised and lowered:
            return f"(+{raised}/-{lowered})"
        if raised:
            return f"(+{raised})"
        return f"(-{lowered})"

    def encode_string_for_name_hash(text: str) -> int:
        total = 0
        for ch in text:
            total = (total + charmap_single_byte.get(ch, ord(ch) & 0xFF)) & 0xFFFFFFFF
        return total

    def level_up_default_moves(species_token: str, level: int) -> List[str]:
        entries = level_up_learnsets.get(species_token, [])
        learned: List[str] = []
        for entry in entries:
            move_level = int(entry.get("level", 0))
            if move_level > level:
                continue
            move_token = str(entry.get("move", ""))
            if not move_token or move_token == "MOVE_NONE":
                continue
            if move_token in learned:
                continue
            if len(learned) < 4:
                learned.append(move_token)
            else:
                learned = learned[1:] + [move_token]
        return learned

    def resolve_wild_encounter(map_token: Optional[str]) -> Optional[Dict[str, object]]:
        if not map_token:
            return None
        by_map = wild_encounters["byMap"]
        candidates = [
            map_token,
            normalize_map_token(map_token),
            map_token.replace("_", ""),
            normalize_map_token(map_token).replace("_", ""),
        ]
        for candidate in candidates:
            if candidate and candidate in by_map:
                return by_map[candidate]
        return None

    def get_section_encounters(section_name: str, hidden_kinds: Optional[set] = None) -> Optional[Dict[str, object]]:
        hidden_kinds = hidden_kinds or set()
        if hidden_kinds.issuperset(ENCOUNTER_KIND_ORDER):
            return None
        
        section_key_norm = normalize_for_match(section_name)
        if not section_key_norm:
            return None

        # Gym sections should never show wild encounters.
        if resolve_section_theme(section_name).startswith("gym") or re.search(r"\bgym\b", section_name.lower()):
            return None

        preferred_map_token = override_encounters_map_token(section_name)
        chosen = resolve_wild_encounter(preferred_map_token)

        if chosen is None and encounter_map_by_section.get(section_name):
            chosen = resolve_wild_encounter(encounter_map_by_section.get(section_name))

        if chosen is None:
            candidates: List[tuple[int, str]] = []
            for map_token in encounter_map_tokens:
                map_token_norm = normalize_map_token(map_token).replace("_", "")
                score = -1
                if map_token_norm == section_key_norm:
                    score = 4
                elif map_token_norm.startswith(section_key_norm):
                    score = 3
                elif section_key_norm.startswith(map_token_norm):
                    score = 2
                elif section_key_norm in map_token_norm:
                    score = 1
                if score >= 0:
                    candidates.append((score, map_token))

            if not candidates:
                return None

            candidates.sort(key=lambda x: (x[0], len(x[1])), reverse=True)
            chosen = resolve_wild_encounter(candidates[0][1])

        if chosen is None:
            return None

        left_panels: List[Dict[str, object]] = []
        right_panels: List[Dict[str, object]] = []

        for encounter_kind in ENCOUNTER_KIND_ORDER:
            if encounter_kind in hidden_kinds:
                continue
            kind_data = chosen.get("types", {}).get(encounter_kind)
            if not kind_data:
                continue
            slots: List[Dict[str, object]] = []
            rates = wild_encounters["ratesByType"].get(encounter_kind, [])
            for idx, mon in enumerate(kind_data.get("mons", [])):
                species_token = str(mon.get("species", "SPECIES_NONE"))
                min_level = int(mon.get("min_level", 0))
                max_level = int(mon.get("max_level", 0))
                slots.append(
                    {
                        "rarity": rates[idx] if idx < len(rates) else 0,
                        "speciesName": species_names.get(species_token, pretty_token(species_token, "SPECIES_")),
                        "sprite": species_front_path(species_token),
                        "level": f"{min_level}-{max_level}" if min_level != max_level else str(min_level),
                    }
                )
            if not slots:
                continue

            panel = {
                "kind": encounter_kind,
                "title": ENCOUNTER_KIND_TITLES.get(encounter_kind, encounter_kind),
                "encounterRate": kind_data.get("encounterRate", 0),
                "slots": slots,
            }
            if encounter_kind == "fishing_mons":
                rod_groups: List[Dict[str, object]] = []
                if slots[:2]:
                    rod_groups.append({"label": "Old Rod", "icon": "graphics/items/icons/old_rod.png", "slots": slots[:2]})
                if slots[2:5]:
                    rod_groups.append({"label": "Good Rod", "icon": "graphics/items/icons/good_rod.png", "slots": slots[2:5]})
                if slots[5:]:
                    rod_groups.append({"label": "Super Rod", "icon": "graphics/items/icons/super_rod.png", "slots": slots[5:]})
                if rod_groups:
                    panel["rodGroups"] = rod_groups

            if encounter_kind in ("land_mons", "rock_smash_mons"):
                left_panels.append(panel)
            else:
                right_panels.append(panel)

        has_land_family = bool(left_panels)
        has_aquatic_family = bool(right_panels)
        if not (has_land_family or has_aquatic_family):
            return None
        return {
            "map": chosen.get("map", ""),
            "mode": "dual" if has_land_family and has_aquatic_family else "single",
            "hasLandFamily": has_land_family,
            "hasAquaticFamily": has_aquatic_family,
            "leftPanels": left_panels,
            "rightPanels": right_panels,
            "singlePanels": left_panels if has_land_family else right_panels,
        }

    sections: Dict[str, List[Dict[str, object]]] = {}
    known_section_names: set[str] = set()

    def is_major_trainer(trainer_id: str, trainer_class_token: str) -> bool:
        token = trainer_class_token.upper()
        trainer_key = trainer_id.upper()
        return (
            "LEADER" in token
            or "ELITE_FOUR" in token
            or "CHAMPION" in token
            or "RIVAL" in token
            or trainer_key.startswith("TRAINER_LEADER_")
            or trainer_key.startswith("TRAINER_ELITE_FOUR_")
            or trainer_key.startswith("TRAINER_CHAMPION_")
            or trainer_key.startswith("TRAINER_RIVAL_")
        )

    def resolve_trainer_theme(trainer_class_token: str) -> str:
        token = trainer_class_token.upper()
        token_parts = set(token.split("_"))

        def has_any_part(*parts: str) -> bool:
            return any(part in token_parts for part in parts)

        if has_any_part("YOUNGSTER", "LASS", "TWINS"):
            return "kid"
        if has_any_part("GENTLEMAN", "GAMER"):
            return "gentleman"
        if has_any_part("HIKER"):
            return "hiker"
        if has_any_part("BEAUTY"):
            return "beauty"
        if has_any_part("BIKER"):
            return "biker"
        if has_any_part("BIRD", "KEEPER"):
            return "birdkeeper"
        if has_any_part("SWIMMER", "TUBER", "TRIATHLETE", "FISHERMAN", "SAILOR") or (
            has_any_part("SIS") and has_any_part("BRO")
        ):
            return "swimmer"
        if has_any_part("PSYCHIC", "CHANNELER") or (
            has_any_part("HEX") and has_any_part("MANIAC")
        ):
            return "psychic"
        if has_any_part("PICNICKER", "CAMPER") or (
            has_any_part("AROMA") and has_any_part("LADY")
        ) or (
            has_any_part("RUIN") and has_any_part("MANIAC")
        ):
            return "camper"
        if has_any_part("ROCKET", "SCIENTIST", "BURGLAR", "BOSS"):
            return "thug"
        if has_any_part("CRUSH", "TAMER", "NINJA") or (
            has_any_part("BLACK") and has_any_part("BELT")
        ) or (
            has_any_part("BATTLE") and has_any_part("GIRL")
        ) or (
            has_any_part("CUE") and has_any_part("BALL")
        ):
            return "fighter"
        if has_any_part("RANGER") or (
            has_any_part("BUG") and (has_any_part("CATCHER") or has_any_part("MANIAC"))
        ):
            return "bug"
        return "default"
    
    # Persist the order of trainers as in trainer_parties.h
    party_order_index = {name: idx for idx, name in enumerate(parties.keys())}
    ordered_trainers = sorted(
        trainers.items(),
        key=lambda kv: party_order_index.get(kv[1]["partyName"], len(party_order_index))
    )

    for trainer_id, trainer in ordered_trainers:
        party = parties.get(trainer["partyName"])
        if not party:
            continue
        section = resolve_canonical_section_name(str(party["section"]), section_name_registry)
        if section_filter and section_filter.lower() != section.lower():
            continue

        trainer_name = trainer["trainerName"].strip() or trainer_id.replace("TRAINER_", "").replace("_", " ").title()
        if trainer_id.startswith("TRAINER_RIVAL_") or trainer_name.upper() == "TERRY":
            trainer_name = "Rival"

        trainer_class_token = str(trainer["trainerClass"])

        trainer_obj: Dict[str, object] = {
            "id": trainer_id,
            "name": trainer_name,
            "class": trainer_class_names.get(trainer_class_token, pretty_token(trainer_class_token, "TRAINER_CLASS_")),
            "theme": resolve_trainer_theme(trainer_class_token),
            "isMajor": is_major_trainer(trainer_id, trainer_class_token),
            "sprite": trainer_pic_path(trainer["trainerPic"]),
            "partyMacro": trainer["partyMacro"],
            "mons": [],
        }

        party_macro = str(trainer.get("partyMacro", ""))
        has_custom_moves = "CUSTOM_MOVES" in party_macro
        has_nature_ability = "NATURE_ABILITY" in party_macro

        # Matches CreateNPCTrainerParty personality pre-seed rules for default trainer data.
        if bool(trainer.get("doubleBattle")):
            generated_personality_base = 0x80
        elif bool(trainer.get("isFemale")):
            generated_personality_base = 0x78
        else:
            generated_personality_base = 0x88

        generated_name_hash = 0
        trainer_name_hash_text = str(trainer.get("trainerName", ""))

        for mon in party["mons"]:
            species_token = str(mon.get("species", "SPECIES_NONE"))
            level_s = str(mon.get("lvl", "0"))
            try:
                mon_level = int(level_s, 10)
            except ValueError:
                mon_level = 0

            sp_info = species_info.get(species_token, {"types": [], "abilities": []})
            ability_token = str(mon.get("ability", ""))
            nature_token = str(mon.get("nature", ""))

            if nature_token.isdigit():
                nature_token = nature_constants.get(int(nature_token), "")

            if not has_nature_ability:
                generated_name_hash = (generated_name_hash + encode_string_for_name_hash(trainer_name_hash_text)) & 0xFFFFFFFF
                generated_name_hash = (generated_name_hash + encode_string_for_name_hash(species_names.get(species_token, ""))) & 0xFFFFFFFF
                generated_personality = (generated_personality_base + ((generated_name_hash << 8) & 0xFFFFFFFF)) & 0xFFFFFFFF
                generated_nature = nature_constants.get(generated_personality % 25, "")
                if not nature_token:
                    nature_token = generated_nature

            if not ability_token:
                abilities = sp_info.get("abilities", [])
                ability_slot_raw = str(mon.get("abilitySlot", "")).strip()
                ability_index = 0
                if ability_slot_raw.isdigit():
                    ability_index = int(ability_slot_raw)

                if ability_index == 1 and len(abilities) > 1 and str(abilities[1]) and str(abilities[1]) != "ABILITY_NONE":
                    ability_token = str(abilities[1])
                elif abilities and str(abilities[0]) and str(abilities[0]) != "ABILITY_NONE":
                    ability_token = str(abilities[0])
                elif len(abilities) > 1 and str(abilities[1]) and str(abilities[1]) != "ABILITY_NONE":
                    ability_token = str(abilities[1])

            move_tokens = [str(move) for move in mon.get("moves", []) if str(move)]
            if not move_tokens and not has_custom_moves:
                move_tokens = level_up_default_moves(species_token, mon_level)

            mon_obj: Dict[str, object] = {
                "speciesToken": species_token,
                "speciesName": species_names.get(species_token, pretty_token(species_token, "SPECIES_")),
                "level": level_s,
                "sprite": species_front_path(species_token),
                "types": list(sp_info.get("types", [])),
                "nature": pretty_token(nature_token, "NATURE_") if nature_token else "-",
                "natureEffect": format_nature_effect(nature_token) if nature_token else "",
                "ability": pretty_token(ability_token, "ABILITY_") if ability_token else "-",
                "itemToken": str(mon.get("heldItem", "ITEM_NONE")),
                "moves": [],
            }

            item_token = mon_obj["itemToken"]
            if item_token == "ITEM_NONE":
                mon_obj["itemName"] = "-"
                mon_obj["itemIconPath"] = ""
                mon_obj["itemPalettePath"] = ""
            else:
                item_name = item_names.get(item_token, pretty_token(item_token, "ITEM_"))
                mon_obj["itemName"] = "-" if item_name and set(item_name) == {"?"} else item_name

                icon_entry = item_icon_table.get(item_token, {})
                icon_symbol = str(icon_entry.get("iconSymbol", ""))
                palette_symbol = str(icon_entry.get("paletteSymbol", ""))
                mon_obj["itemIconPath"] = str(item_icon_paths.get("icons", {}).get(icon_symbol, ""))
                mon_obj["itemPalettePath"] = str(item_icon_paths.get("palettes", {}).get(palette_symbol, ""))

            for move_token in move_tokens:
                mon_obj["moves"].append({
                    "token": move_token,
                    "name": move_names.get(move_token, pretty_token(move_token, "MOVE_")),
                    "type": move_types.get(move_token, ""),
                })

            trainer_obj["mons"].append(mon_obj)

        sections.setdefault(section, []).append(trainer_obj)
        known_section_names.add(section)

    section_order_plan = load_section_order_plan()
    for name in planned_section_names(section_order_plan):
        sections.setdefault(name, [])
        known_section_names.add(name)

    for map_token in encounter_map_tokens:
        normalized_token = normalize_map_token(map_token)
        section_name = resolve_canonical_section_name(
            map_token_to_section_name(normalized_token),
            section_name_registry,
        )
        if section_filter and section_filter.lower() != section_name.lower():
            continue
        if is_redundant_section_name(section_name, known_section_names):
            continue
        sections.setdefault(section_name, [])
        known_section_names.add(section_name)

    if section_order_plan:
        ordered_section_names = apply_section_order_plan(
            section_order_plan,
            party_section_order,
            set(sections.keys()),
        )
    else:
        ordered_section_names = [name for name in party_section_order if name in sections]

    section_name_set = set(ordered_section_names)
    for name in sections.keys():
        if name in section_name_set:
            continue
        if is_redundant_section_name(name, section_name_set):
            continue
        ordered_section_names.append(name)
        section_name_set.add(name)

    sections, ordered_section_names, trainer_groups = apply_section_merges(sections, ordered_section_names, merge_overrides)

    def section_map_scale_max(section_name: str) -> Optional[float]:
        sect_cfg = section_overrides.get(section_name, {})
        if not isinstance(sect_cfg, dict):
            return None
        raw = sect_cfg.get("mapScaleMax")
        if raw is None:
            return None
        try:
            value = float(raw)
        except (TypeError, ValueError):
            return None
        if value <= 0 or value > 1:
            return None
        return value

    def section_full_height(section_name: str) -> bool:
        sect_cfg = section_overrides.get(section_name, {})
        if not isinstance(sect_cfg, dict):
            return False
        return bool(sect_cfg.get("fullHeight"))
    
    def section_hidden_encounter_kinds(section_name: str) -> set:
        sect_cfg = section_overrides.get(section_name, {})
        if not isinstance(sect_cfg, dict):
            return set()
        raw = sect_cfg.get("hideEncounters")
        if raw is True:
            return set(ENCOUNTER_KIND_ORDER)
        if isinstance(raw, (list, tuple)):
            valid = set(ENCOUNTER_KIND_ORDER)
            return {str(item) for item in raw if str(item) in valid}
        return set()

    return {
        "sections": [
            {
                "name": name,
                "slug": slugify(name),
                "theme": resolve_section_theme(name),
                "mapImage": f"docs/maps/{slugify(name)}.png",
                "mapRender": build_map_render(name),
                "mapScaleMax": section_map_scale_max(name),
                "fullHeight": section_full_height(name),
                "encounters": get_section_encounters(name, section_hidden_encounter_kinds(name)),
                "trainers": sections[name],
                "trainerGroups": trainer_groups.get(name, []),
            }
            for name in ordered_section_names
            if name in sections and (not section_filter or section_filter.lower() == name.lower())
        ],
        "typeIcons": type_icon_specs,
    }
