from __future__ import annotations

from functools import lru_cache
import json
import re
import sys
from pathlib import Path
from typing import Dict, List, Optional


ROOT = Path(__file__).resolve().parents[2]


def resolve_tiles_png_path(metatiles_rel_path: str) -> Optional[str]:
    """Resolve tiles.png for a metatiles.bin path (standard tileset dir or map_preview fallback)."""
    tileset_dir = (ROOT / metatiles_rel_path).parent
    standard = tileset_dir / "tiles.png"
    if standard.is_file():
        return standard.relative_to(ROOT).as_posix()

    preview = ROOT / "graphics" / "map_preview" / tileset_dir.name / "tiles.png"
    if preview.is_file():
        return preview.relative_to(ROOT).as_posix()

    return None

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


def read_text(rel_path: str) -> str:
    return (ROOT / rel_path).read_text(encoding="utf-8")


def pretty_token(token: str, prefix: str) -> str:
    if token.startswith(prefix):
        token = token[len(prefix):]
    words = token.lower().split("_")
    return " ".join(w.capitalize() for w in words if w)


def strip_macro_string(raw: str) -> str:
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

    for match in start_re.finditer(text):
        species = match.group(1)
        body_start = match.end()
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
        types_match = re.search(r"\.types\s*=\s*\{\s*(TYPE_[A-Z0-9_]+)\s*,\s*(TYPE_[A-Z0-9_]+)\s*\}", body)
        abilities_match = re.search(r"\.abilities\s*=\s*\{\s*(ABILITY_[A-Z0-9_]+)\s*,\s*(ABILITY_[A-Z0-9_]+)\s*\}", body)
        types = []
        if types_match:
            types = [types_match.group(1), types_match.group(2)]
            if types[0] == types[1]:
                types = [types[0]]
        abilities = [abilities_match.group(1), abilities_match.group(2)] if abilities_match else []
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
    for symbol, path in re.findall(r"const u32\s+(gTrainerFrontPic_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U32\(\"([^\"]+)\"\);", text):
        out[symbol] = path.replace(".4bpp.lz", ".png")
    return out


def parse_mon_symbol_to_png_path() -> Dict[str, str]:
    text = read_text("src/data/graphics/pokemon.h")
    out: Dict[str, str] = {}
    for symbol, path in re.findall(r"const u32\s+(gMonFrontPic_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U32\(\"([^\"]+)\"\);", text):
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
    icon_re = re.compile(r"\[(TYPE_[A-Z0-9_]+)\s*\+\s*1\]\s*=\s*\{\s*(\d+)\s*,\s*(\d+)\s*,\s*(0x[0-9A-Fa-f]+|\d+)\s*\}", re.M)
    for type_token, width_s, height_s, offset_s in icon_re.findall(text):
        width = int(width_s)
        height = int(height_s)
        offset = int(offset_s, 0)
        out[type_token] = {"w": width, "h": height, "x": (offset % 16) * 8, "y": (offset // 16) * 8}
    return out


def parse_firered_encounters() -> Dict[str, object]:
    data = json.loads(read_text("src/data/wild_encounters.json"))
    groups = data.get("wild_encounter_groups", [])
    target_group = next((group for group in groups if group.get("for_maps")), None)
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
            if encounter_kind in enc:
                encounter_entry = enc[encounter_kind]
                type_data[encounter_kind] = {
                    "encounterRate": int(encounter_entry.get("encounter_rate", 0)),
                    "mons": encounter_entry.get("mons", []),
                }
        if not type_data:
            continue
        map_name = str(enc.get("map", ""))
        map_token = map_name[4:] if map_name.startswith("MAP_") else map_name
        by_map[map_token] = {"map": map_name, "baseLabel": base_label, "types": type_data}

    return {"ratesByType": rates_by_type, "byMap": by_map}


@lru_cache(maxsize=1)
def parse_layouts_by_id() -> Dict[str, Dict[str, object]]:
    data = json.loads(read_text("data/layouts/layouts.json"))
    out: Dict[str, Dict[str, object]] = {}
    for layout in data.get("layouts", []):
        layout_id = str(layout.get("id", "")).strip()
        if layout_id:
            out[layout_id] = layout
    return out


@lru_cache(maxsize=1)
def parse_tileset_metatile_paths() -> Dict[str, str]:
    text = read_text("src/data/tilesets/metatiles.h")
    out: Dict[str, str] = {}
    pattern = re.compile(r"const u16\s+(gMetatiles_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U16\(\"([^\"]+)\"\);")
    for symbol, path in pattern.findall(text):
        out[symbol] = path
    return out


@lru_cache(maxsize=1)
def parse_map_layout_records() -> Dict[str, object]:
    maps_dir = ROOT / "data" / "maps"
    records: List[Dict[str, str]] = []
    by_token: Dict[str, Dict[str, str]] = {}

    for map_json in sorted(maps_dir.glob("*/map.json")):
        data = json.loads(map_json.read_text(encoding="utf-8"))
        map_id = str(data.get("id", "")).strip()
        layout_id = str(data.get("layout", "")).strip()
        map_name = str(data.get("name", "")).strip()
        if not map_id.startswith("MAP_") or not layout_id:
            continue

        map_token = map_id[4:]
        rel_map_json = map_json.relative_to(ROOT).as_posix()
        record = {
            "mapId": map_id,
            "mapToken": map_token,
            "mapName": map_name,
            "layout": layout_id,
            "mapJsonPath": rel_map_json,
        }
        records.append(record)
        by_token.setdefault(map_token, record)

    return {"records": records, "byToken": by_token}


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


def extract_top_level_brace_blocks(text: str) -> List[str]:
    blocks: List[str] = []
    depth = 0
    start = -1
    for i, ch in enumerate(text):
        if ch == "{":
            if depth == 0:
                start = i + 1
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0 and start >= 0:
                blocks.append(text[start:i])
                start = -1
    return blocks


def parse_party_mon(mon_block: str) -> Dict[str, object]:
    out: Dict[str, object] = {}
    for key in ("iv", "lvl", "species", "heldItem", "nature", "ability"):
        match = re.search(rf"\.{key}\s*=\s*([^,\n]+)", mon_block)
        if match:
            out[key] = match.group(1).strip()

    moves_match = re.search(r"\.moves\s*=\s*\{([^}]*)\}", mon_block, re.S)
    if moves_match:
        out["moves"] = [token.strip() for token in moves_match.group(1).split(",") if token.strip() and token.strip() != "MOVE_NONE"]
    else:
        out["moves"] = []

    out.setdefault("lvl", "0")
    out.setdefault("species", "SPECIES_NONE")
    out.setdefault("nature", "")
    out.setdefault("ability", "")
    out.setdefault("heldItem", "ITEM_NONE")
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
    floor_re = re.compile(r"^(?:B\d+F|\d+F)$", re.I)
    head_re = re.compile(r"^\s*static const struct\s+(\w+)\s+(sParty_[A-Za-z0-9_]+)\[\]\s*=\s*\{\s*$")
    current_parent = ""

    i = 0
    while i < len(lines):
        line = lines[i]
        if "Start of actual trainer data" in line:
            started = True
        if not started:
            i += 1
            continue

        section_match = sec_re.match(line)
        if section_match:
            title = section_match.group(1).strip()
            if title:
                if floor_re.match(title) and current_parent:
                    current_section = f"{current_parent} {title}"
                else:
                    current_parent = title
                    current_section = title
                if current_section not in seen_sections:
                    section_order.append(current_section)
                    seen_sections.add(current_section)

        head_match = head_re.match(line)
        if not head_match:
            i += 1
            continue

        struct_type = head_match.group(1)
        party_name = head_match.group(2)
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
        section_name = current_section
        # Protect against accidental section spillover when trailing party blocks
        # appear after the final CHAMPION header without a new section marker.
        if current_section == "CHAMPION" and not party_name.startswith("sParty_Champion"):
            section_name = "Unsorted"

        if section_name == "Unsorted" and section_name not in seen_sections:
            section_order.append(section_name)
            seen_sections.add(section_name)

        out[party_name] = {
            "section": section_name,
            "structType": struct_type,
            "mons": [parse_party_mon(mon_block) for mon_block in extract_top_level_brace_blocks(body)],
        }
        i += 1

    section_sizes: Dict[str, int] = {}
    for party in out.values():
        section = str(party.get("section", "Unsorted"))
        section_sizes[section] = section_sizes.get(section, 0) + 1
    for section, size in sorted(section_sizes.items(), key=lambda kv: kv[1], reverse=True):
        if size > 80:
            print(f"Warning: parse_parties section '{section}' has {size} parties.", file=sys.stderr)

    return {"parties": out, "sectionOrder": section_order}
