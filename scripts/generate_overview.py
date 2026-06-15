#!/usr/bin/env python3
"""
Generate an overview page from existing project data.

Output:
  docs/OVERVIEW.html

Optional:
  python3 scripts/generate_overview.py --section "Route 2"

Run with --section to specify 1 map section to generate.
"""

from __future__ import annotations

import argparse
import html
import json
import os
import re
from pathlib import Path
from typing import Dict, List, Optional


ROOT = Path(__file__).resolve().parents[1]

# Insert extra sections relative to trainer_parties section comments.
# Format: ("Anchor Section", ["Section To Insert", "Another Section"])
# Each inserted section is placed immediately after its anchor, in listed order.
# This keeps trainer_parties ordering as the base and lets you place maps between
# canonical sections (for example Route 1 and Viridian City after Oak's Lab).
MANUAL_SECTION_INSERTS: List[tuple[str, List[str]]] = [
    ("Oak's Lab", ["Route 1", "Viridian City"]),
]


def read_text(rel_path: str) -> str:
    return (ROOT / rel_path).read_text(encoding="utf-8")


def pretty_token(token: str, prefix: str) -> str:
    if token.startswith(prefix):
        token = token[len(prefix):]
    words = token.lower().split("_")
    return " ".join(w.capitalize() for w in words if w)


def strip_macro_string(raw: str) -> str:
    # _("NAME") -> NAME
    if raw.startswith('_("') and raw.endswith('")'):
        return raw[3:-2]
    return raw


def parse_define_ints(rel_path: str, prefix: str) -> Dict[str, int]:
    text = read_text(rel_path)
    out: Dict[str, int] = {}
    for name, value in re.findall(r"^\s*#define\s+([A-Z0-9_]+)\s+(\d+)\s*$", text, flags=re.M):
        if name.startswith(prefix):
            out[name] = int(value)
    return out


def parse_species_names() -> Dict[str, str]:
    text = read_text("src/data/text/species_names.h")
    out: Dict[str, str] = {}
    for key, name in re.findall(r"\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*_(\"[^\"]*\")", text):
        out[key] = strip_macro_string(f"_({name})")
    return out


def parse_move_names() -> Dict[str, str]:
    text = read_text("src/data/text/move_names.h")
    out: Dict[str, str] = {}
    for key, name in re.findall(r"\[(MOVE_[A-Z0-9_]+)\]\s*=\s*_(\"[^\"]*\")", text):
        out[key] = strip_macro_string(f"_({name})")
    return out


def parse_trainer_class_names() -> Dict[str, str]:
    text = read_text("src/data/text/trainer_class_names.h")
    out: Dict[str, str] = {}
    for key, name in re.findall(r"\[(TRAINER_CLASS_[A-Z0-9_]+)\]\s*=\s*_(\"[^\"]*\")", text):
        out[key] = strip_macro_string(f"_({name})")
    return out


def parse_move_types() -> Dict[str, str]:
    text = read_text("src/data/battle_moves.h")
    out: Dict[str, str] = {}
    entry_re = re.compile(r"\[(MOVE_[A-Z0-9_]+)\]\s*=\s*\{(.*?)\n\s*\},", re.S)
    for move, body in entry_re.findall(text):
        m = re.search(r"\.type\s*=\s*(TYPE_[A-Z0-9_]+)", body)
        if m:
            out[move] = m.group(1)
    return out


def parse_species_info_types_and_abilities() -> Dict[str, Dict[str, object]]:
    text = read_text("src/data/pokemon/species_info.h")
    out: Dict[str, Dict[str, object]] = {}
    start_re = re.compile(r"^\s*\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*\{\s*$", re.M)

    for m in start_re.finditer(text):
        species = m.group(1)
        body_start = m.end()
        depth = 1
        i = body_start
        while i < len(text) and depth > 0:
            ch = text[i]
            if ch == "{":
                depth += 1
            elif ch == "}":
                depth -= 1
            i += 1

        if depth != 0:
            continue

        body = text[body_start : i - 1]
        t = re.search(
            r"\.types\s*=\s*\{\s*(TYPE_[A-Z0-9_]+)\s*,\s*(TYPE_[A-Z0-9_]+)\s*\}",
            body,
        )
        a = re.search(
            r"\.abilities\s*=\s*\{\s*(ABILITY_[A-Z0-9_]+)\s*,\s*(ABILITY_[A-Z0-9_]+)\s*\}",
            body,
        )
        if t:
            types = [t.group(1), t.group(2)]
            if types[0] == types[1]:
                types = [types[0]]
        else:
            types = []
        abilities = [a.group(1), a.group(2)] if a else []
        out[species] = {"types": types, "abilities": abilities}
    return out


def parse_item_names() -> Dict[str, str]:
    data = json.loads(read_text("src/data/items.json"))
    out: Dict[str, str] = {}
    for item in data.get("items", []):
        item_id = item.get("itemId")
        english = item.get("english")
        if item_id and english:
            out[item_id] = english
    return out


def parse_trainer_symbol_to_png_path() -> Dict[str, str]:
    text = read_text("src/data/graphics/trainers.h")
    out: Dict[str, str] = {}
    for symbol, path in re.findall(
        r"const u32\s+(gTrainerFrontPic_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U32\(\"([^\"]+)\"\);",
        text,
    ):
        out[symbol] = path.replace(".4bpp.lz", ".png")
    return out


def parse_mon_symbol_to_png_path() -> Dict[str, str]:
    text = read_text("src/data/graphics/pokemon.h")
    out: Dict[str, str] = {}
    for symbol, path in re.findall(
        r"const u32\s+(gMonFrontPic_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U32\(\"([^\"]+)\"\);",
        text,
    ):
        out[symbol] = path.replace(".4bpp.lz", ".png")
    return out


def parse_ordered_trainer_front_symbols() -> List[str]:
    text = read_text("src/data/trainer_graphics/front_pic_tables.h")
    return re.findall(r"TRAINER_SPRITE\([A-Z0-9_]+,\s*(gTrainerFrontPic_[A-Za-z0-9_]+)", text)


def parse_ordered_species_front_symbols() -> List[str]:
    text = read_text("src/data/pokemon_graphics/front_pic_table.h")
    return re.findall(r"SPECIES_SPRITE\([A-Z0-9_]+,\s*(gMonFrontPic_[A-Za-z0-9_]+)", text)


def parse_type_icon_specs() -> Dict[str, Dict[str, int]]:
    text = read_text("src/list_menu.c")
    out: Dict[str, Dict[str, int]] = {}
    icon_re = re.compile(
        r"\[(TYPE_[A-Z0-9_]+)\s*\+\s*1\]\s*=\s*\{\s*(\d+)\s*,\s*(\d+)\s*,\s*(0x[0-9A-Fa-f]+|\d+)\s*\}",
        re.M,
    )
    for type_token, width_s, height_s, offset_s in icon_re.findall(text):
        width = int(width_s)
        height = int(height_s)
        offset = int(offset_s, 0)
        # gMenuInfoElements_Gfx is treated as 128x128 4bpp sheet (16x16 tiles).
        tile_x = (offset % 16) * 8
        tile_y = (offset // 16) * 8
        out[type_token] = {
            "w": width,
            "h": height,
            "x": tile_x,
            "y": tile_y,
        }
    return out


ENCOUNTER_KIND_ORDER = [
    "land_mons",
    "rock_smash_mons",
    "water_mons",
    "fishing_mons",
]

ENCOUNTER_KIND_TITLES = {
    "land_mons": "Land",
    "rock_smash_mons": "Rock Smash",
    "water_mons": "Surf",
    "fishing_mons": "Fishing",
}


def parse_firered_encounters() -> Dict[str, object]:
    data = json.loads(read_text("src/data/wild_encounters.json"))
    groups = data.get("wild_encounter_groups", [])

    target_group = None
    for group in groups:
        if group.get("for_maps"):
            target_group = group
            break

    if not target_group:
        return {"ratesByType": {}, "byMap": {}}

    rates_by_type: Dict[str, List[int]] = {}
    for field in target_group.get("fields", []):
        field_type = str(field.get("type", ""))
        if field_type in ENCOUNTER_KIND_ORDER:
            rates_by_type[field_type] = [int(x) for x in field.get("encounter_rates", [])]

    by_map: Dict[str, Dict[str, object]] = {}
    for enc in target_group.get("encounters", []):
        base_label = str(enc.get("base_label", ""))
        if not base_label.endswith("_FireRed"):
            continue

        type_data: Dict[str, Dict[str, object]] = {}
        for encounter_kind in ENCOUNTER_KIND_ORDER:
            if encounter_kind not in enc:
                continue

            encounter_entry = enc[encounter_kind]
            type_data[encounter_kind] = {
                "encounterRate": int(encounter_entry.get("encounter_rate", 0)),
                "mons": encounter_entry.get("mons", []),
            }

        if not type_data:
            continue

        map_name = str(enc.get("map", ""))
        map_token = map_name[4:] if map_name.startswith("MAP_") else map_name
        by_map[map_token] = {
            "map": map_name,
            "baseLabel": base_label,
            "types": type_data,
        }

    return {"ratesByType": rates_by_type, "byMap": by_map}


def parse_trainers() -> Dict[str, Dict[str, str]]:
    text = read_text("src/data/trainers.h")
    out: Dict[str, Dict[str, str]] = {}
    entry_re = re.compile(r"\[(TRAINER_[A-Z0-9_]+)\]\s*=\s*\{(.*?)\n\s*\},", re.S)
    for trainer_id, body in entry_re.findall(text):
        cls = re.search(r"\.trainerClass\s*=\s*(TRAINER_CLASS_[A-Z0-9_]+)", body)
        pic = re.search(r"\.trainerPic\s*=\s*(TRAINER_PIC_[A-Z0-9_]+)", body)
        name = re.search(r"\.trainerName\s*=\s*_\(\"([^\"]*)\"\)", body)
        party = re.search(r"\.party\s*=\s*([A-Z0-9_]+)\((sParty_[A-Za-z0-9_]+)\)", body)
        if not party:
            continue
        out[trainer_id] = {
            "trainerClass": cls.group(1) if cls else "TRAINER_CLASS_NONE",
            "trainerPic": pic.group(1) if pic else "TRAINER_PIC_YOUNGSTER",
            "trainerName": name.group(1) if name else "",
            "partyMacro": party.group(1),
            "partyName": party.group(2),
        }
    return out


def extract_top_level_brace_blocks(s: str) -> List[str]:
    blocks: List[str] = []
    depth = 0
    start = -1
    for i, ch in enumerate(s):
        if ch == "{":
            if depth == 0:
                start = i + 1
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0 and start >= 0:
                blocks.append(s[start:i])
                start = -1
    return blocks


def parse_party_mon(mon_block: str) -> Dict[str, object]:
    out: Dict[str, object] = {}

    for key in ("iv", "lvl", "species", "heldItem", "nature", "ability"):
        m = re.search(rf"\.{key}\s*=\s*([^,\n]+)", mon_block)
        if m:
            out[key] = m.group(1).strip()

    m_moves = re.search(r"\.moves\s*=\s*\{([^}]*)\}", mon_block, re.S)
    if m_moves:
        out["moves"] = [
            token.strip()
            for token in m_moves.group(1).split(",")
            if token.strip() and token.strip() != "MOVE_NONE"
        ]
    else:
        out["moves"] = []

    if "lvl" not in out:
        out["lvl"] = "0"

    if "species" not in out:
        out["species"] = "SPECIES_NONE"

    if "nature" not in out:
        out["nature"] = ""
    if "ability" not in out:
        out["ability"] = ""
    if "heldItem" not in out:
        out["heldItem"] = "ITEM_NONE"

    return out


def parse_parties() -> Dict[str, object]:
    text = read_text("src/data/trainer_parties.h")
    lines = text.splitlines()

    started = False
    current_section = "Unsorted"
    out: Dict[str, Dict[str, object]] = {}
    section_order: List[str] = []
    seen_sections = set()

    sec_re = re.compile(r"^\s*//\s*=+\s*(.*?)\s*=+\s*//\s*$")
    head_re = re.compile(r"^\s*static const struct\s+(\w+)\s+(sParty_[A-Za-z0-9_]+)\[\]\s*=\s*\{\s*$")

    i = 0
    while i < len(lines):
        line = lines[i]

        if "Start of actual trainer data" in line:
            started = True

        if not started:
            i += 1
            continue

        msec = sec_re.match(line)
        if msec:
            title = msec.group(1).strip()
            if title:
                current_section = title
                if current_section not in seen_sections:
                    section_order.append(current_section)
                    seen_sections.add(current_section)

        mhead = head_re.match(line)
        if not mhead:
            i += 1
            continue

        struct_type = mhead.group(1)
        party_name = mhead.group(2)

        block_lines = [line]
        i += 1
        while i < len(lines):
            block_lines.append(lines[i])
            if lines[i].strip() == "};":
                break
            i += 1

        block_text = "\n".join(block_lines)
        body_match = re.search(r"\{(.*)\}\s*;\s*$", block_text, re.S)
        body = body_match.group(1) if body_match else ""

        mons: List[Dict[str, object]] = []
        for mon_block in extract_top_level_brace_blocks(body):
            mon = parse_party_mon(mon_block)
            mons.append(mon)

        out[party_name] = {
            "section": current_section,
            "structType": struct_type,
            "mons": mons,
        }
        i += 1

    return {"parties": out, "sectionOrder": section_order}


def slugify(name: str) -> str:
    s = re.sub(r"[^A-Za-z0-9]+", "_", name).strip("_")
    return s.lower() or "section"


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
}


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

    def trainer_pic_path(pic_token: str) -> str:
        idx = trainer_pic_ids.get(pic_token)
        if idx is None or idx >= len(trainer_front_syms):
            return "graphics/trainers/front_pics/youngster_front_pic.png"
        sym = trainer_front_syms[idx]
        return trainer_sym_to_png.get(sym, "graphics/trainers/front_pics/youngster_front_pic.png")

    def species_front_path(species_token: str) -> str:
        idx = species_ids.get(species_token)
        if idx is None or idx >= len(mon_front_syms):
            return "graphics/pokemon/question_mark/front.png"
        sym = mon_front_syms[idx]
        return mon_sym_to_png.get(sym, "graphics/pokemon/question_mark/front.png")

    def get_section_encounters(section_name: str) -> Optional[Dict[str, object]]:
        section_key = slugify(section_name).upper()
        section_key_norm = section_key.replace("_", "")
        if not section_key:
            return None

        candidates: List[tuple[int, str]] = []
        for map_token in wild_encounters["byMap"].keys():
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

            if encounter_kind == "fishing_mons" and slots:
                rod_groups: List[Dict[str, object]] = []
                old_slots = slots[:2]
                good_slots = slots[2:5]
                super_slots = slots[5:]
                if old_slots:
                    rod_groups.append({"label": "Old Rod", "icon": "graphics/items/icons/old_rod.png", "slots": old_slots})
                if good_slots:
                    rod_groups.append({"label": "Good Rod", "icon": "graphics/items/icons/good_rod.png", "slots": good_slots})
                if super_slots:
                    rod_groups.append({"label": "Super Rod", "icon": "graphics/items/icons/super_rod.png", "slots": super_slots})
                panel["rodGroups"] = rod_groups

            if encounter_kind in ("land_mons", "rock_smash_mons"):
                left_panels.append(panel)
            else:
                right_panels.append(panel)

        has_land_family = bool(left_panels)
        has_aquatic_family = bool(right_panels)
        has_any = has_land_family or has_aquatic_family
        if not has_any:
            return None

        if has_land_family and has_aquatic_family:
            mode = "dual"
        else:
            mode = "single"

        single_panels: List[Dict[str, object]] = left_panels if has_land_family else right_panels

        return {
            "map": chosen.get("map", ""),
            "mode": mode,
            "hasLandFamily": has_land_family,
            "hasAquaticFamily": has_aquatic_family,
            "leftPanels": left_panels,
            "rightPanels": right_panels,
            "singlePanels": single_panels,
        }

    sections: Dict[str, List[Dict[str, object]]] = {}

    for trainer_id, t in trainers.items():
        party_name = t["partyName"]
        party = parties.get(party_name)
        if not party:
            continue

        section = str(party["section"])
        if section_filter and section_filter.lower() != section.lower():
            continue

        trainer_name = t["trainerName"].strip()
        if not trainer_name:
            trainer_name = trainer_id.replace("TRAINER_", "").replace("_", " ").title()
        if trainer_id.startswith("TRAINER_RIVAL_"):
            trainer_name = "Rival"
        if trainer_name.upper() == "TERRY":
            trainer_name = "Rival"

        class_name = trainer_class_names.get(t["trainerClass"], pretty_token(t["trainerClass"], "TRAINER_CLASS_"))
        trainer_obj: Dict[str, object] = {
            "id": trainer_id,
            "name": trainer_name,
            "class": class_name,
            "sprite": trainer_pic_path(t["trainerPic"]),
            "partyMacro": t["partyMacro"],
            "mons": [],
        }

        for mon in party["mons"]:
            species_token = str(mon.get("species", "SPECIES_NONE"))
            sp_info = species_info.get(species_token, {"types": [], "abilities": []})
            types = list(sp_info.get("types", []))

            ability_token = str(mon.get("ability", ""))
            if not ability_token and sp_info.get("abilities"):
                ability_token = str(sp_info["abilities"][0])

            mon_obj: Dict[str, object] = {
                "speciesToken": species_token,
                "speciesName": species_names.get(species_token, pretty_token(species_token, "SPECIES_")),
                "level": str(mon.get("lvl", "0")),
                "sprite": species_front_path(species_token),
                "types": types,
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
                # Some placeholder item strings are rendered as only '?' chars.
                mon_obj["itemName"] = "-" if item_name and set(item_name) == {"?"} else item_name

            for move_token in mon.get("moves", []):
                move_token = str(move_token)
                m_type = move_types.get(move_token, "")
                mon_obj["moves"].append(
                    {
                        "token": move_token,
                        "name": move_names.get(move_token, pretty_token(move_token, "MOVE_")),
                        "type": m_type,
                    }
                )

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

    ordered_sections = []
    for name in ordered_section_names:
        ordered_sections.append(
            {
                "name": name,
                "slug": slugify(name),
                "theme": resolve_section_theme(name),
                "mapImage": f"docs/maps/{slugify(name)}.png",
                "encounters": get_section_encounters(name),
                "trainers": sections[name],
            }
        )

    return {
        "sections": ordered_sections,
        "typeIcons": type_icon_specs,
    }


def render_html(model: Dict[str, object], out_path: Path) -> None:
    type_icons = model["typeIcons"]
    sections = model["sections"]
    output_dir = out_path.parent

    def asset_url(rel_path: str) -> str:
        return os.path.relpath(ROOT / rel_path, output_dir).replace("\\", "/")

    css = """
:root {
  --bg: #f2eee8;
  --panel: #e4ddd4;
  --ink: #1f1a16;
  --line: #5b5651;
  --accent: #b56f3a;
}
body {
  margin: 0;
  background: linear-gradient(180deg, #f6f2ec 0%, #eae2d8 100%);
  color: var(--ink);
  font-family: "Trebuchet MS", Verdana, sans-serif;
}
.wrap {
  width: min(1400px, 98vw);
  margin: 20px auto;
}
h1 { margin: 0 0 8px 0; }
.hint { margin: 0 0 18px 0; color: #4a433d; }
.section {
    --section-bg: #efe9e0;
    --section-head-bg: #ddd2c4;
    --map-pane-bg: #d8d0c4;
    --map-left-bg: #cfc7bb;
    --enc-bg: #efefef;
    --enc-panel-bg: #f4f4f4;
    --enc-kind-bg: #e2e2e2;
    --enc-line: #908a83;
    --enc-grid-line: #8f8f8f;
    --enc-th-bg: #dedede;
    --trainer-card-bg: #e4ddd4;
    --trainer-left-bg: #e0d8ce;
    --mon-bg: #f8f5ef;
    --mon-head-bg: #d2c4b4;
    --mon-body-bg: #f8f5ef;
    --moves-bg: #f6f2eb;
  border: 3px solid var(--line);
    background: var(--section-bg);
  margin: 16px 0 30px;
}
.section-head {
  border-bottom: 3px solid var(--line);
  padding: 10px 12px;
    background: var(--section-head-bg);
  display: flex;
  justify-content: space-between;
  align-items: center;
}
.map-pane {
    min-height: 120px;
    background: var(--map-pane-bg);
    display: grid;
    align-items: stretch;
  padding: 10px;
    border-bottom: 3px solid var(--line);
    gap: 10px;
}
.map-pane--map-only {
    grid-template-columns: minmax(0, 1fr);
}
.map-pane--single {
    grid-template-columns: minmax(0, 3fr) minmax(220px, 1fr);
}
.map-pane--dual {
    grid-template-columns: minmax(0, 1fr) minmax(0, 1fr);
}
.map-left {
    border: 2px solid var(--line);
    background: var(--map-left-bg);
    display: flex;
    align-items: center;
    justify-content: center;
    min-height: 160px;
    position: relative;
}
.map-left img { max-width: 100%; max-height: 100%; image-rendering: pixelated; }
.map-fallback { display: none; color: #574d42; font-size: 16px; }
.encounters {
    border: 2px solid var(--line);
    background: var(--enc-bg);
    display: flex;
    flex-direction: column;
    gap: 8px;
    padding: 8px;
}
.enc-family-head {
    padding: 2px 0 0;
    font-size: 16px;
    font-weight: 700;
    letter-spacing: 1px;
    text-transform: uppercase;
}
.enc-columns {
    display: grid;
    grid-template-columns: 1fr 1fr;
    gap: 8px;
    min-height: 0;
}
.enc-col {
    display: flex;
    flex-direction: column;
    gap: 8px;
}
.enc-panel {
    border: 2px solid var(--enc-line);
    background: var(--enc-panel-bg);
}
.enc-kind-head {
    border-bottom: 2px solid var(--enc-line);
    padding: 4px 8px;
    font-size: 14px;
    font-weight: 700;
    text-transform: uppercase;
    letter-spacing: 0.6px;
    background: var(--enc-kind-bg);
}
.enc-grid { width: 100%; border-collapse: collapse; font-size: 14px; }
.enc-grid th, .enc-grid td { border-bottom: 1px solid var(--enc-grid-line); padding: 4px 6px; }
.enc-grid tbody tr { height: 40px; }
.enc-grid th { background: var(--enc-th-bg); font-weight: 700; }
.enc-grid .rarity { width: 58px; text-align: center; font-weight: 700; }
.enc-grid .rarity-very-low { background: #9ae28f; }
.enc-grid .rarity-low { background: #c4e788; }
.enc-grid .rarity-mid { background: #e6ca82; }
.enc-grid .rarity-high { background: #eca169; }
.enc-grid .rarity-very-high { background: #ea8080; }
.enc-grid .rarity-other { background: #d7d7d7; }
.enc-grid .species-cell { display: flex; align-items: center; gap: 8px; }
.enc-grid .species-cell img { width: 32px; height: 32px; image-rendering: pixelated; }
.enc-grid .lvl { width: 62px; text-align: center; font-weight: 700; font-size: 11px; }
.enc-grid .rod-header td {
    background: var(--enc-kind-bg);
    font-weight: 700;
    font-size: 12px;
    text-transform: uppercase;
    letter-spacing: 0.5px;
    border-top: 2px solid var(--enc-line);
    padding: 3px 6px;
    height: auto;
}
.enc-grid .rod-header td img {
    width: 20px;
    height: 20px;
    image-rendering: pixelated;
    vertical-align: middle;
    margin-right: 5px;
}
.enc-placeholder {
    padding: 14px 10px;
    text-align: center;
    color: #5b5651;
    font-size: 15px;
}
.cards {
  display: grid;
  gap: 10px;
  padding: 10px;
  grid-template-columns: repeat(auto-fill, minmax(900px, 1fr));
}
.trainer-card {
  border: 3px solid var(--line);
    background: var(--trainer-card-bg);
}
.trainer-main {
  display: grid;
  grid-template-columns: 180px 1fr;
}
.trainer-left {
  border-right: 3px solid var(--line);
    background: var(--trainer-left-bg);
  text-align: center;
  padding: 6px;
}
.trainer-left img {
  width: 128px;
  height: 128px;
  image-rendering: pixelated;
}
.trainer-class { font-size: 13px; letter-spacing: 1px; }
.trainer-name { font-weight: 800; font-size: 30px; line-height: 1.0; }
.mons {
  display: grid;
  grid-template-columns: repeat(auto-fill, minmax(180px, 1fr));
}
.mon {
  border-left: 3px solid var(--line);
  border-bottom: 3px solid var(--line);
    background: var(--mon-bg);
}
.mons .mon:last-child {
    border-right: 3px solid var(--line);
}
.mon-head {
  border-bottom: 3px solid var(--line);
    background: var(--mon-head-bg);
  text-align: center;
  padding: 4px;
}
.mon-head img {
  width: 96px;
  height: 96px;
  image-rendering: pixelated;
}
.mon-name { font-size: 30px; font-weight: 800; line-height: 1.0; }
.lvl { font-size: 30px; font-weight: 800; margin-top: -6px; }
.types {
  display: flex;
  justify-content: center;
  gap: 4px;
  margin-top: 4px;
  min-height: 14px;
}
.type-icon {
  display: inline-block;
  image-rendering: pixelated;
    background-image: url("__TYPE_ICON_URL__");
  background-repeat: no-repeat;
}
.mon-body { padding: 6px; text-align: center; font-size: 30px; line-height: 1.25; }
.mon-body .item { font-size: 28px; }
.moves {
  border-top: 3px solid var(--line);
    background: var(--moves-bg);
  padding: 4px 6px;
  font-size: 30px;
  line-height: 1.15;
}
.move-row { display: flex; align-items: center; justify-content: center; gap: 6px; }

.section[data-theme='route'] {
    --section-bg: #f1ead8;
    --section-head-bg: #d6ccb4;
    --map-pane-bg: #e4dcc8;
    --map-left-bg: #d6ceb8;
    --enc-bg: #eef3e4;
    --enc-panel-bg: #f5f8ef;
    --enc-kind-bg: #dde8cb;
    --trainer-card-bg: #e5dccd;
    --trainer-left-bg: #d8d2c0;
    --mon-bg: #f7f2e8;
    --mon-head-bg: #d8ccb8;
    --moves-bg: #f3eee3;
}

.section[data-theme='forest'] {
    --section-bg: #d8e5d2;
    --section-head-bg: #b2c9aa;
    --map-pane-bg: #c4d7bc;
    --map-left-bg: #b8cbaa;
    --enc-bg: #dbe9d3;
    --enc-panel-bg: #edf4e8;
    --enc-kind-bg: #cadfc0;
    --enc-line: #5d7852;
    --enc-grid-line: #6a8560;
    --enc-th-bg: #c2d7ba;
    --trainer-card-bg: #d4e1cf;
    --trainer-left-bg: #bfd1b7;
    --mon-bg: #eef5e9;
    --mon-head-bg: #b7caaa;
    --moves-bg: #e9f1e3;
}

.section[data-theme='cave'] {
    --section-bg: #e0d8ce;
    --section-head-bg: #c2b5a7;
    --map-pane-bg: #cec4b8;
    --map-left-bg: #bbb0a2;
    --enc-bg: #e6dfd6;
    --enc-panel-bg: #f0eae1;
    --enc-kind-bg: #d4c9bc;
    --enc-line: #6f665e;
    --enc-grid-line: #7e756c;
    --enc-th-bg: #d1c4b7;
    --trainer-card-bg: #dbd2c8;
    --trainer-left-bg: #c9bcad;
    --mon-bg: #f2ece5;
    --mon-head-bg: #c3b5a6;
    --moves-bg: #eee6dd;
}

.section[data-theme='city-generic'] {
    --section-bg: #e9e6df;
    --section-head-bg: #ccc6bb;
    --map-pane-bg: #d7d2c7;
    --map-left-bg: #c8c2b6;
    --enc-bg: #ece9e2;
    --enc-panel-bg: #f5f2ec;
    --enc-kind-bg: #dad4c9;
    --trainer-card-bg: #e3ddd3;
    --trainer-left-bg: #d3ccbf;
    --mon-bg: #f7f3ec;
    --mon-head-bg: #d0c5b5;
    --moves-bg: #f2ede4;
}

.section[data-theme='city-pewter'],
.section[data-theme='gym-pewter'] {
    --section-bg: #efe9e0;
    --section-head-bg: #ddd2c4;
    --map-pane-bg: #d8d0c4;
    --map-left-bg: #cfc7bb;
    --enc-bg: #efefef;
    --enc-panel-bg: #f4f4f4;
    --enc-kind-bg: #e2e2e2;
    --trainer-card-bg: #e4ddd4;
    --trainer-left-bg: #e0d8ce;
    --mon-bg: #f8f5ef;
    --mon-head-bg: #d2c4b4;
    --moves-bg: #f6f2eb;
}

.section[data-theme='city-cerulean'],
.section[data-theme='gym-cerulean'] {
    --section-bg: #d3deea;
    --section-head-bg: #3f84c2;
    --map-pane-bg: #c3d3e3;
    --map-left-bg: #adc3d9;
    --enc-bg: #d8e5f2;
    --enc-panel-bg: #e9f1f8;
    --enc-kind-bg: #b9d1e9;
    --enc-line: #3f6484;
    --enc-grid-line: #4f7494;
    --enc-th-bg: #b6cde3;
    --trainer-card-bg: #cbdae8;
    --trainer-left-bg: #c0d4e7;
    --mon-bg: #e9f0f7;
    --mon-head-bg: #3f84c2;
    --moves-bg: #e5edf5;
}

.section[data-theme='city-vermilion'],
.section[data-theme='gym-vermilion'] {
    --section-bg: #efe0d3;
    --section-head-bg: #d98749;
    --map-pane-bg: #e5d0be;
    --map-left-bg: #ddc2ab;
    --enc-bg: #f2e6db;
    --enc-panel-bg: #f7eee6;
    --enc-kind-bg: #ecd2bf;
    --trainer-card-bg: #e8d7c8;
    --trainer-left-bg: #dfc8b2;
    --mon-bg: #f7efe7;
    --mon-head-bg: #e1b894;
    --moves-bg: #f3e8de;
}

.section[data-theme='city-celadon'],
.section[data-theme='gym-celadon'] {
    --section-bg: #dde8d8;
    --section-head-bg: #7ea96d;
    --map-pane-bg: #cfddca;
    --map-left-bg: #c1d0bb;
    --enc-bg: #e4eedf;
    --enc-panel-bg: #f1f6ee;
    --enc-kind-bg: #cfe1c6;
    --trainer-card-bg: #d7e3d1;
    --trainer-left-bg: #c6d8be;
    --mon-bg: #eef4ea;
    --mon-head-bg: #aec7a2;
    --moves-bg: #e8f0e2;
}

.section[data-theme='city-fuchsia'],
.section[data-theme='gym-fuchsia'] {
    --section-bg: #eadbea;
    --section-head-bg: #b16cab;
    --map-pane-bg: #dec9de;
    --map-left-bg: #d2b8d1;
    --enc-bg: #efe3ef;
    --enc-panel-bg: #f7eff7;
    --enc-kind-bg: #e2c9e1;
    --trainer-card-bg: #e3d3e2;
    --trainer-left-bg: #d8c2d7;
    --mon-bg: #f5edf5;
    --mon-head-bg: #ccadd0;
    --moves-bg: #f1e8f1;
}

.section[data-theme='city-saffron'],
.section[data-theme='gym-saffron'] {
    --section-bg: #f0e6c9;
    --section-head-bg: #ceac4a;
    --map-pane-bg: #e7d9b7;
    --map-left-bg: #dfcc9d;
    --enc-bg: #f5edd8;
    --enc-panel-bg: #fbf5e8;
    --enc-kind-bg: #eddcae;
    --trainer-card-bg: #ebdec0;
    --trainer-left-bg: #e1cf9f;
    --mon-bg: #f9f4e4;
    --mon-head-bg: #e1ca87;
    --moves-bg: #f5eed8;
}

.section[data-theme='city-viridian'],
.section[data-theme='gym-viridian'] {
    --section-bg: #d8e8d7;
    --section-head-bg: #6f9a64;
    --map-pane-bg: #c7dbc3;
    --map-left-bg: #b8cfb3;
    --enc-bg: #deebdb;
    --enc-panel-bg: #eef5ec;
    --enc-kind-bg: #c8dcc1;
    --trainer-card-bg: #d2e0ce;
    --trainer-left-bg: #bdd2b7;
    --mon-bg: #edf4ea;
    --mon-head-bg: #abc6a0;
    --moves-bg: #e6efe3;
}

.section[data-theme='city-cinnabar'],
.section[data-theme='gym-cinnabar'] {
    --section-bg: #edd9d2;
    --section-head-bg: #c06049;
    --map-pane-bg: #e2c6bc;
    --map-left-bg: #d8b4a7;
    --enc-bg: #f1e0da;
    --enc-panel-bg: #f8ece8;
    --enc-kind-bg: #e8c7bc;
    --trainer-card-bg: #e7d2ca;
    --trainer-left-bg: #dabeb3;
    --mon-bg: #f6ece9;
    --mon-head-bg: #d8a897;
    --moves-bg: #f2e4de;
}

@media (max-width: 1200px) {
    .map-pane {
        min-height: 90px;
        grid-template-columns: 1fr;
    }
    .enc-columns {
        grid-template-columns: 1fr;
    }
}
"""
    css = css.replace("__TYPE_ICON_URL__", asset_url("graphics/interface/menu_info.png"))

    html_chunks: List[str] = []
    html_chunks.append("<!doctype html><html><head><meta charset='utf-8'>")
    html_chunks.append("<meta name='viewport' content='width=device-width, initial-scale=1'>")
    html_chunks.append("<title>Overview</title>")
    html_chunks.append("<style>")
    html_chunks.append(css)

    for t, spec in sorted(type_icons.items()):
        html_chunks.append(
            f".type-{t} {{ width:{spec['w']}px; height:{spec['h']}px; background-position:-{spec['x']}px -{spec['y']}px; }}"
        )

    html_chunks.append("</style></head><body><div class='wrap'>")
    html_chunks.append("<h1>Overview</h1>")
    html_chunks.append(
        "<p class='hint'>Map images are optional. Place route screenshots in docs/maps using section slug names.</p>"
    )

    def render_encounter_panel(panel: Dict[str, object]) -> None:
        kind = str(panel.get("kind", ""))
        is_non_land = kind != "land_mons"

        def get_rarity_class(rarity: int) -> str:
            if is_non_land:
                if rarity >= 40:
                    return "rarity-very-low"
                if rarity >= 25:
                    return "rarity-low"
                if rarity >= 5:
                    return "rarity-mid"
                if rarity >= 2:
                    return "rarity-high"
                return "rarity-very-high"
            fixed = {20: "rarity-very-low", 10: "rarity-low", 5: "rarity-mid", 4: "rarity-high", 1: "rarity-very-high"}
            return fixed.get(rarity, "rarity-other")

        def render_slot_row(slot: Dict[str, object]) -> None:
            e_name = html.escape(str(slot["speciesName"]))
            e_lvl = html.escape(str(slot["level"]))
            rarity = int(slot.get("rarity", 0))
            e_rarity = html.escape(f"{rarity}%")
            rarity_class = get_rarity_class(rarity)
            e_sprite = html.escape(asset_url(str(slot["sprite"])))
            html_chunks.append("<tr>")
            html_chunks.append(f"<td class='rarity {rarity_class}'>{e_rarity}</td>")
            html_chunks.append("<td><div class='species-cell'>")
            html_chunks.append(f"<img src='{e_sprite}' alt='{e_name}'>")
            html_chunks.append(f"<span>{e_name}</span>")
            html_chunks.append("</div></td>")
            html_chunks.append(f"<td class='lvl'>{e_lvl}</td>")
            html_chunks.append("</tr>")

        panel_title = html.escape(str(panel.get("title", "Encounter")))
        html_chunks.append("<section class='enc-panel'>")
        html_chunks.append(f"<div class='enc-kind-head'>{panel_title}</div>")
        html_chunks.append("<table class='enc-grid'>")
        html_chunks.append("<thead><tr><th class='rarity'>Rarity</th><th>Pokemon</th><th class='lvl'>Level</th></tr></thead>")
        html_chunks.append("<tbody>")
        rod_groups = panel.get("rodGroups")
        if rod_groups:
            for group in rod_groups:
                group_label = html.escape(str(group.get("label", "")))
                group_icon = html.escape(asset_url(str(group.get("icon", ""))))
                html_chunks.append("<tr class='rod-header'>")
                html_chunks.append(f"<td colspan='3'><img src='{group_icon}' alt='{group_label}'>{group_label}</td>")
                html_chunks.append("</tr>")
                for slot in group.get("slots", []):
                    render_slot_row(slot)
        else:
            for slot in panel.get("slots", []):
                render_slot_row(slot)
        html_chunks.append("</tbody></table>")
        html_chunks.append("</section>")

    for sec in sections:
        section_name = html.escape(str(sec["name"]))
        map_img = html.escape(asset_url(str(sec["mapImage"])))
        encounters = sec.get("encounters")
        pane_mode = "map-only"
        if encounters and encounters.get("mode") == "dual":
            pane_mode = "dual"
        elif encounters and encounters.get("mode") == "single":
            pane_mode = "single"

        section_theme = html.escape(str(sec.get("theme", "default")))

        html_chunks.append(f"<section class='section' data-theme='{section_theme}'>")
        html_chunks.append(f"<div class='section-head'><strong>{section_name}</strong><span>{len(sec['trainers'])} trainers</span></div>")
        html_chunks.append(f"<div class='map-pane map-pane--{pane_mode}'>")
        html_chunks.append("<div class='map-left'>")
        html_chunks.append(
            f"<img src='{map_img}' alt='Map for {section_name}' onerror=\"this.style.display='none';this.parentElement.querySelector('.map-fallback').style.display='block';\">"
        )
        html_chunks.append("<div class='map-fallback'>No map image yet</div>")
        html_chunks.append("</div>")

        if encounters:
            html_chunks.append("<aside class='encounters'>")
            html_chunks.append("<div class='enc-family-head'>Wild Encounters (FireRed)</div>")

            if encounters.get("mode") == "dual":
                html_chunks.append("<div class='enc-columns'>")
                html_chunks.append("<div class='enc-col'>")
                for panel in encounters.get("leftPanels", []):
                    render_encounter_panel(panel)
                html_chunks.append("</div>")
                html_chunks.append("<div class='enc-col'>")
                for panel in encounters.get("rightPanels", []):
                    render_encounter_panel(panel)
                html_chunks.append("</div>")
                html_chunks.append("</div>")
            else:
                for panel in encounters.get("singlePanels", []):
                    render_encounter_panel(panel)

            html_chunks.append("</aside>")

        html_chunks.append("</div>")
        html_chunks.append("<div class='cards'>")

        for tr in sec["trainers"]:
            trainer_name = html.escape(str(tr["name"]))
            trainer_class = html.escape(str(tr["class"]))
            trainer_sprite = html.escape(asset_url(str(tr["sprite"])))
            html_chunks.append("<article class='trainer-card'><div class='trainer-main'>")
            html_chunks.append("<div class='trainer-left'>")
            html_chunks.append(f"<img src='{trainer_sprite}' alt='{trainer_name}'>")
            html_chunks.append(f"<div class='trainer-class'>{trainer_class}</div>")
            html_chunks.append(f"<div class='trainer-name'>{trainer_name}</div>")
            html_chunks.append("</div>")

            html_chunks.append("<div class='mons'>")
            for mon in tr["mons"]:
                mon_name = html.escape(str(mon["speciesName"]))
                mon_sprite = html.escape(asset_url(str(mon["sprite"])))
                lvl = html.escape(str(mon["level"]))
                nature = html.escape(str(mon["nature"]))
                ability = html.escape(str(mon["ability"]))
                item_name = html.escape(str(mon["itemName"]))

                html_chunks.append("<div class='mon'>")
                html_chunks.append("<div class='mon-head'>")
                html_chunks.append(f"<img src='{mon_sprite}' alt='{mon_name}'>")
                html_chunks.append(f"<div class='mon-name'>{mon_name}</div>")
                html_chunks.append(f"<div class='lvl'>{lvl}</div>")

                html_chunks.append("<div class='types'>")
                for t in mon["types"]:
                    if t in type_icons:
                        html_chunks.append(f"<span class='type-icon type-{t}' title='{html.escape(t)}'></span>")
                html_chunks.append("</div></div>")

                html_chunks.append("<div class='mon-body'>")
                html_chunks.append(f"<div>{nature}</div>")
                html_chunks.append(f"<div>{ability}</div>")
                html_chunks.append(f"<div class='item'>{item_name}</div>")
                html_chunks.append("</div>")

                html_chunks.append("<div class='moves'>")
                if mon["moves"]:
                    for mv in mon["moves"]:
                        mv_name = html.escape(str(mv["name"]))
                        mv_type = str(mv.get("type", ""))
                        html_chunks.append("<div class='move-row'>")
                        html_chunks.append(f"<span>{mv_name}</span>")
                        if mv_type in type_icons:
                            html_chunks.append(f"<span class='type-icon type-{mv_type}' title='{html.escape(mv_type)}'></span>")
                        html_chunks.append("</div>")
                else:
                    html_chunks.append("<div class='move-row'><span>-</span></div>")
                html_chunks.append("</div>")

                html_chunks.append("</div>")

            html_chunks.append("</div>")
            html_chunks.append("</div></article>")

        html_chunks.append("</div></section>")

    html_chunks.append("</div></body></html>")

    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text("\n".join(html_chunks), encoding="utf-8")


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate overview HTML")
    parser.add_argument("--section", help="Only render one section title (case-insensitive)")
    args = parser.parse_args()

    model = build_model(args.section)
    out_path = ROOT / "docs" / "OVERVIEW.html"
    render_html(model, out_path)

    print(f"Wrote: {out_path}")
    print(f"Sections rendered: {len(model['sections'])}")


if __name__ == "__main__":
    main()
