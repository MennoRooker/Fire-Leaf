from __future__ import annotations

import re
from typing import Dict, List, Optional

from .parsing import (
    ENCOUNTER_KIND_ORDER,
    ENCOUNTER_KIND_TITLES,
    parse_define_ints,
    parse_firered_encounters,
    parse_item_names,
    parse_layouts_by_id,
    parse_map_layout_records,
    parse_mon_symbol_to_png_path,
    parse_move_names,
    parse_move_types,
    parse_ordered_species_front_symbols,
    parse_ordered_trainer_front_symbols,
    parse_parties,
    parse_species_info_types_and_abilities,
    parse_species_names,
    parse_trainer_class_names,
    parse_trainer_symbol_to_png_path,
    parse_trainers,
    parse_tileset_metatile_paths,
    parse_type_icon_specs,
    pretty_token,
)


MANUAL_SECTION_INSERTS: List[tuple[str, List[str]]] = [
    ("Oak's Lab", ["Route 1", "Viridian City"]),
]

SECTION_THEME_OVERRIDES: Dict[str, str] = {
    "pewter city": "city-pewter",
    "cerulean city": "city-cerulean",
    "vermilion city": "city-vermilion",
    "celadon city": "city-celadon",
    "fuchsia city": "city-fuchsia",
    "saffron city": "city-saffron",
    "viridian city": "city-viridian",
    "cinnabar island": "city-cinnabar",
    "pewter city gym": "gym-pewter",
    "cerulean city gym": "gym-cerulean",
    "vermilion city gym": "gym-vermilion",
    "celadon city gym": "gym-celadon",
    "fuchsia city gym": "gym-fuchsia",
    "saffron city gym": "gym-saffron",
    "viridian city gym": "gym-viridian",
    "cinnabar island gym": "gym-cinnabar",
    "cinnabar gym": "gym-cinnabar",
    "vermillion city gym": "gym-vermilion",
    # Elite Four
    "e4-1": "e4-lorelei",
    "e4-2": "e4-bruno",
    "e4-3": "e4-agatha",
    "e4-4": "e4-lance",
}

SECTION_MAP_TOKEN_OVERRIDES: Dict[str, str] = {
    "oak's lab": "PALLET_TOWN_PROFESSOR_OAKS_LAB",
}


def slugify(name: str) -> str:
    s = re.sub(r"[^A-Za-z0-9]+", "_", name).strip("_")
    return s.lower() or "section"


def normalize_for_match(name: str) -> str:
    return slugify(name).upper().replace("_", "")


def camel_words(name: str) -> str:
    return re.sub(r"([a-z0-9])([A-Z])", r"\1 \2", name.replace("_", " ")).strip()


def map_token_to_section_name(map_token: str) -> str:
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
    trainers = parse_trainers()
    parties_data = parse_parties()
    parties = parties_data["parties"]
    party_section_order = parties_data["sectionOrder"]
    species_names = parse_species_names()
    move_names = parse_move_names()
    trainer_class_names = parse_trainer_class_names()
    move_types = parse_move_types()
    species_info = parse_species_info_types_and_abilities()
    item_names = parse_item_names()
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
    encounter_map_by_section: Dict[str, str] = {}
    for map_token in encounter_map_tokens:
        section_name = map_token_to_section_name(map_token)
        encounter_map_by_section.setdefault(section_name, map_token)

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

    def resolve_section_map_record(section_name: str) -> Optional[Dict[str, str]]:
        override = SECTION_MAP_TOKEN_OVERRIDES.get(section_name.strip().lower())
        if override and override in map_by_token:
            return map_by_token[override]

        encounter_token = encounter_map_by_section.get(section_name)
        if encounter_token and encounter_token in map_by_token:
            return map_by_token[encounter_token]

        section_key = normalize_for_match(section_name)
        if section_key in map_by_norm_section:
            return map_by_norm_section[section_key]

        # Fallback for manually titled sections that are only partial map names.
        # We pick the shortest matching map candidate to reduce false positives.
        candidates: List[tuple[int, Dict[str, str]]] = []
        for record in map_records:
            map_norm = normalize_for_match(record["mapToken"])
            if section_key and section_key in map_norm:
                candidates.append((len(map_norm), record))

        if candidates:
            candidates.sort(key=lambda x: x[0])
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
        if not (primary_metatiles and secondary_metatiles):
            return None

        return {
            "mapId": map_record["mapId"],
            "mapName": map_record["mapName"],
            "mapToken": map_record["mapToken"],
            "layoutId": str(layout.get("id", "")),
            "width": int(layout.get("width", 0)),
            "height": int(layout.get("height", 0)),
            "blockdataPath": blockdata_path,
            "primary": {
                "tileset": primary_tileset,
                "metatilesPath": primary_metatiles,
                "tilesPngPath": primary_metatiles.replace("metatiles.bin", "tiles.png"),
            },
            "secondary": {
                "tileset": secondary_tileset,
                "metatilesPath": secondary_metatiles,
                "tilesPngPath": secondary_metatiles.replace("metatiles.bin", "tiles.png"),
            },
        }

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

    def get_section_encounters(section_name: str) -> Optional[Dict[str, object]]:
        section_key_norm = normalize_for_match(section_name)
        if not section_key_norm:
            return None

        # Gym sections should never show wild encounters.
        if resolve_section_theme(section_name).startswith("gym") or re.search(r"\bgym\b", section_name.lower()):
            return None

        preferred_map_token = encounter_map_by_section.get(section_name)
        if preferred_map_token:
            chosen = wild_encounters["byMap"][preferred_map_token]
        else:
            candidates: List[tuple[int, str]] = []
            for map_token in encounter_map_tokens:
                map_token_norm = map_token.replace("_", "")
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
            chosen = wild_encounters["byMap"][candidates[0][1]]
        left_panels: List[Dict[str, object]] = []
        right_panels: List[Dict[str, object]] = []

        for encounter_kind in ENCOUNTER_KIND_ORDER:
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
    for map_token in encounter_map_tokens:
        section_name = map_token_to_section_name(map_token)
        if section_filter and section_filter.lower() != section_name.lower():
            continue
        sections.setdefault(section_name, [])

    for trainer_id, trainer in trainers.items():
        party = parties.get(trainer["partyName"])
        if not party:
            continue
        section = str(party["section"])
        if section_filter and section_filter.lower() != section.lower():
            continue

        trainer_name = trainer["trainerName"].strip() or trainer_id.replace("TRAINER_", "").replace("_", " ").title()
        if trainer_id.startswith("TRAINER_RIVAL_") or trainer_name.upper() == "TERRY":
            trainer_name = "Rival"

        trainer_obj: Dict[str, object] = {
            "id": trainer_id,
            "name": trainer_name,
            "class": trainer_class_names.get(trainer["trainerClass"], pretty_token(trainer["trainerClass"], "TRAINER_CLASS_")),
            "sprite": trainer_pic_path(trainer["trainerPic"]),
            "partyMacro": trainer["partyMacro"],
            "mons": [],
        }

        for mon in party["mons"]:
            species_token = str(mon.get("species", "SPECIES_NONE"))
            sp_info = species_info.get(species_token, {"types": [], "abilities": []})
            ability_token = str(mon.get("ability", ""))
            if not ability_token:
                abilities = sp_info.get("abilities", [])
                ability_token = str(abilities[0]) if abilities else ""
            mon_obj: Dict[str, object] = {
                "speciesToken": species_token,
                "speciesName": species_names.get(species_token, pretty_token(species_token, "SPECIES_")),
                "level": str(mon.get("lvl", "0")),
                "sprite": species_front_path(species_token),
                "types": list(sp_info.get("types", [])),
                "nature": pretty_token(str(mon.get("nature", "")), "NATURE_") if mon.get("nature") else "-",
                "ability": pretty_token(ability_token, "ABILITY_") if ability_token else "-",
                "itemToken": str(mon.get("heldItem", "ITEM_NONE")),
                "moves": [],
            }

            item_token = mon_obj["itemToken"]
            if item_token == "ITEM_NONE":
                mon_obj["itemName"] = "-"
            else:
                item_name = item_names.get(item_token, pretty_token(item_token, "ITEM_"))
                mon_obj["itemName"] = "-" if item_name and set(item_name) == {"?"} else item_name

            for move_token in mon.get("moves", []):
                move_token = str(move_token)
                mon_obj["moves"].append({
                    "token": move_token,
                    "name": move_names.get(move_token, pretty_token(move_token, "MOVE_")),
                    "type": move_types.get(move_token, ""),
                })

            trainer_obj["mons"].append(mon_obj)

        sections.setdefault(section, []).append(trainer_obj)

    for _, insert_names in MANUAL_SECTION_INSERTS:
        for name in insert_names:
            sections.setdefault(name, [])

    ordered_section_names: List[str] = [name for name in party_section_order if name in sections]
    for anchor_name, insert_names in MANUAL_SECTION_INSERTS:
        if anchor_name not in ordered_section_names:
            continue
        insert_pos = ordered_section_names.index(anchor_name) + 1
        for name in insert_names:
            if name not in sections:
                continue
            if name in ordered_section_names:
                old_idx = ordered_section_names.index(name)
                ordered_section_names.pop(old_idx)
                if old_idx < insert_pos:
                    insert_pos -= 1
            ordered_section_names.insert(insert_pos, name)
            insert_pos += 1

    section_name_set = set(ordered_section_names)
    for name in sections.keys():
        if name not in section_name_set:
            ordered_section_names.append(name)
            section_name_set.add(name)

    return {
        "sections": [
            {
                "name": name,
                "slug": slugify(name),
                "theme": resolve_section_theme(name),
                "mapImage": f"docs/maps/{slugify(name)}.png",
                "mapRender": build_map_render(name),
                "encounters": get_section_encounters(name),
                "trainers": sections[name],
            }
            for name in ordered_section_names
        ],
        "typeIcons": type_icon_specs,
    }