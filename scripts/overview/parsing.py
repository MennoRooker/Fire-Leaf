from __future__ import annotations

import ast
from functools import lru_cache
import json
import re
import sys
from pathlib import Path
from typing import Any, Dict, List, Optional


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


@lru_cache(maxsize=1)
def parse_tileset_tiles_png_paths() -> Dict[str, str]:
    """Map gTileset_* symbols to the tiles.png used at runtime (via headers.h + graphics.h)."""
    headers_text = read_text("src/data/tilesets/headers.h")
    graphics_text = read_text("src/data/tilesets/graphics.h")

    tiles_symbol_to_png: Dict[str, str] = {}
    for tiles_symbol, bin_path in re.findall(
        r"const u32\s+(gTilesetTiles_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U32\(\"([^\"]+)\"\);",
        graphics_text,
    ):
        png_path = re.sub(r"\.4bpp(?:\.lz)?$", ".png", bin_path)
        tiles_symbol_to_png[tiles_symbol] = png_path

    out: Dict[str, str] = {}
    header_re = re.compile(
        r"const struct Tileset\s+(gTileset_[A-Za-z0-9_]+)\s*=\s*\{(.*?)\};",
        re.S,
    )
    tiles_ref_re = re.compile(r"\.tiles\s*=\s*(gTilesetTiles_[A-Za-z0-9_]+)")

    for match in header_re.finditer(headers_text):
        tileset_symbol = match.group(1)
        tiles_ref = tiles_ref_re.search(match.group(2))
        if not tiles_ref:
            continue
        png_path = tiles_symbol_to_png.get(tiles_ref.group(1))
        if png_path:
            out[tileset_symbol] = png_path

    return out


def resolve_tileset_tiles_png_path(tileset_symbol: str, metatiles_rel_path: Optional[str] = None) -> Optional[str]:
    """Resolve tiles.png for a tileset symbol, following shared tile sources from headers.h."""
    mapped = parse_tileset_tiles_png_paths().get(tileset_symbol)
    if mapped and (ROOT / mapped).is_file():
        return mapped

    if metatiles_rel_path:
        return resolve_tiles_png_path(metatiles_rel_path)

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


def parse_nature_stat_modifiers() -> Dict[str, List[int]]:
    text = read_text("src/pokemon.c")
    table_match = re.search(
        r"static const s8 sNatureStatTable\[NUM_NATURES\]\[NUM_NATURE_STATS\]\s*=\s*\{(.*?)\n\};",
        text,
        re.S,
    )
    if not table_match:
        return {}

    body = table_match.group(1)
    line_re = re.compile(
        r"\[(NATURE_[A-Z0-9_]+)\]\s*=\s*\{\s*([+\-]?\d+)\s*,\s*([+\-]?\d+)\s*,\s*([+\-]?\d+)\s*,\s*([+\-]?\d+)\s*,\s*([+\-]?\d+)\s*\}",
        re.M,
    )

    out: Dict[str, List[int]] = {}
    for nature, a, b, c, d, e in line_re.findall(body):
        out[nature] = [int(a), int(b), int(c), int(d), int(e)]
    return out


def parse_nature_constants() -> Dict[int, str]:
    text = read_text("include/constants/pokemon.h")
    out: Dict[int, str] = {}
    for token, value_s in re.findall(r"^\s*#define\s+(NATURE_[A-Z0-9_]+)\s+(\d+)\s*$", text, flags=re.M):
        if token == "NUM_NATURES":
            continue
        out[int(value_s)] = token
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


@lru_cache(maxsize=1)
def parse_tmhm_move_tokens_by_item_token() -> Dict[str, str]:
    """Map ITEM_TMxx/ITEM_HMxx tokens to MOVE_* tokens from sTMHMMoves."""
    text = read_text("src/data/party_menu.h")
    table_match = re.search(r"static const u16\s+sTMHMMoves\[\]\s*=\s*\{(.*?)\n\};", text, re.S)
    if not table_match:
        return {}

    move_tokens = re.findall(r"\b(MOVE_[A-Z0-9_]+)\b", table_match.group(1))
    if not move_tokens:
        return {}

    item_ids = parse_define_ints("include/constants/items.h", "ITEM_")
    tm_start = item_ids.get("ITEM_TM01")
    if tm_start is None:
        tm_start = item_ids.get("ITEM_TM01_FOCUS_PUNCH")
    if tm_start is None:
        return {}

    # ITEM_TMxx/ITEM_HMxx defines are numeric and canonical in this project.
    item_token_by_id = {
        item_id: token
        for token, item_id in item_ids.items()
        if re.fullmatch(r"ITEM_(?:TM|HM)\d{2}", token)
    }

    out: Dict[str, str] = {}
    for offset, move_token in enumerate(move_tokens):
        item_token = item_token_by_id.get(tm_start + offset)
        if item_token:
            out[item_token] = move_token

    return out


@lru_cache(maxsize=1)
def parse_level_up_learnsets_by_species() -> Dict[str, List[Dict[str, object]]]:
    learnsets_text = read_text("src/data/pokemon/level_up_learnsets.h")
    pointers_text = read_text("src/data/pokemon/level_up_learnset_pointers.h")

    moves_by_symbol: Dict[str, List[Dict[str, object]]] = {}
    learnset_re = re.compile(r"static const u16\s+(s[A-Za-z0-9_]+)\[\]\s*=\s*\{(.*?)\n\};", re.S)
    move_re = re.compile(r"LEVEL_UP_MOVE\(\s*(\d+)\s*,\s*(MOVE_[A-Z0-9_]+)\s*\)")

    for symbol, body in learnset_re.findall(learnsets_text):
        moves: List[Dict[str, object]] = []
        for lvl_s, move_token in move_re.findall(body):
            moves.append({"level": int(lvl_s), "move": move_token})
        moves_by_symbol[symbol] = moves

    out: Dict[str, List[Dict[str, object]]] = {}
    ptr_re = re.compile(r"\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*(s[A-Za-z0-9_]+)")
    for species_token, symbol in ptr_re.findall(pointers_text):
        out[species_token] = list(moves_by_symbol.get(symbol, []))

    return out


@lru_cache(maxsize=1)
def parse_charmap_single_byte_table() -> Dict[str, int]:
    text = read_text("charmap.txt")
    out: Dict[str, int] = {}
    line_re = re.compile(r"^\s*('(?:\\.|[^'])*')\s*=\s*([0-9A-Fa-f]{2})\s*$")

    for line in text.splitlines():
        m = line_re.match(line)
        if not m:
            continue
        quoted, byte_hex = m.groups()
        try:
            ch = ast.literal_eval(quoted)
        except (SyntaxError, ValueError):
            continue
        if isinstance(ch, str) and len(ch) == 1 and ch not in out:
            out[ch] = int(byte_hex, 16)

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


def parse_item_prices() -> Dict[str, int]:
    data = json.loads(read_text("src/data/items.json"))
    out: Dict[str, int] = {}
    for item in data.get("items", []):
        item_id = str(item.get("itemId", "")).strip()
        if not item_id:
            continue
        try:
            out[item_id] = int(item.get("price", 0) or 0)
        except (TypeError, ValueError):
            out[item_id] = 0
    return out


def _normalize_map_token(map_token: str) -> str:
    parts: List[str] = []
    for raw in map_token.split("_"):
        token = raw.strip()
        if not token:
            continue
        expanded = re.sub(r"([A-Za-z])(\d)", r"\1_\2", token)
        expanded = re.sub(r"(\d)([A-Za-z])", r"\1_\2", expanded)
        parts.extend(part for part in expanded.split("_") if part)
    return "_".join(parts)


def _map_token_to_display_name(map_token: str) -> str:
    token = _normalize_map_token(map_token)
    parts: List[str] = []
    floor_parts: List[str] = []
    for raw in token.split("_"):
        value = raw.strip()
        if not value:
            continue
        upper = value.upper()
        if len(upper) == 1 and upper in ("B", "F"):
            floor_parts.append(upper)
            continue
        if upper.isdigit():
            floor_parts.append(upper)
            continue
        if floor_parts:
            parts.append("".join(floor_parts))
            floor_parts = []
        if re.fullmatch(r"B\d+F|\d+F", upper):
            parts.append(upper)
        elif len(upper) <= 2 and upper.isalpha():
            parts.append(upper)
        else:
            parts.append(upper[:1] + upper[1:].lower())

    if floor_parts:
        parts.append("".join(floor_parts))

    return " ".join(parts) or pretty_token(token, "")


def _section_map_token_for_internal_map(map_token: str) -> str:
    token = _normalize_map_token(map_token)
    if token.endswith("_MART"):
        return token[: -len("_MART")]
    if "_DEPARTMENT_STORE_" in token:
        return token.split("_DEPARTMENT_STORE_", 1)[0]
    if "_GAME_CORNER_" in token:
        return token.split("_GAME_CORNER_", 1)[0]
    if token.startswith("INDIGO_PLATEAU_"):
        return "INDIGO_PLATEAU"
    return token


def _label_blocks(script_text: str) -> Dict[str, str]:
    out: Dict[str, str] = {}
    labels = list(re.finditer(r"(?m)^([A-Za-z0-9_]+)::\s*$", script_text))
    for idx, match in enumerate(labels):
        label = match.group(1)
        start = match.end()
        end = labels[idx + 1].start() if idx + 1 < len(labels) else len(script_text)
        out[label] = script_text[start:end]
    return out


def _item_table_tokens(label_block: str) -> List[str]:
    tokens: List[str] = []
    for line in label_block.splitlines():
        item_match = re.search(r"\.2byte\s+([A-Z0-9_]+)", line)
        if not item_match:
            continue
        token = item_match.group(1)
        if token == "ITEM_NONE":
            break
        if token.startswith("ITEM_"):
            tokens.append(token)
    return tokens


def _iter_map_scripts() -> List[Dict[str, str]]:
    out: List[Dict[str, str]] = []
    for map_json in sorted((ROOT / "data" / "maps").glob("*/map.json")):
        scripts_inc = map_json.parent / "scripts.inc"
        if not scripts_inc.is_file():
            continue
        map_data = json.loads(map_json.read_text(encoding="utf-8"))
        map_id = str(map_data.get("id", "")).strip()
        if not map_id.startswith("MAP_"):
            continue
        map_token = map_id[4:]
        out.append(
            {
                "mapToken": map_token,
                "scriptsPath": scripts_inc.relative_to(ROOT).as_posix(),
                "scriptsText": scripts_inc.read_text(encoding="utf-8"),
            }
        )
    return out


def _shop_label_from_script_name(script_label: str, table_label: str) -> str:
    lowered = script_label.lower()
    table_lowered = table_label.lower()
    if "clerktms" in lowered:
        return "TMs"
    if "clerkberries" in lowered:
        return "Berries"
    if "clerksupplements" in lowered:
        return "Supplements"
    if "clerkitems" in lowered:
        return "Main Counter"
    if "prizeroom" in table_lowered:
        return "Prize Counter"
    return "Shop"


def _shop_variant_label(table_label: str) -> str:
    token = table_label.lower()
    if "shopinitial" in token:
        return "Initial"
    if "shopexpanded1" in token:
        return "Expanded 1"
    if "shopexpanded2" in token:
        return "Expanded 2"
    if "shopexpanded3" in token:
        return "Expanded 3"
    return ""


def _shop_location_label(map_token: str) -> str:
    token = _normalize_map_token(map_token)
    if "_DEPARTMENT_STORE_" in token:
        floor = token.split("_DEPARTMENT_STORE_", 1)[1].replace("_", "")
        return f"Department Store {floor}"
    if token.endswith("_MART"):
        return "Mart"
    if "_GAME_CORNER_PRIZE_ROOM" in token:
        return "Game Corner Prize Room"
    return _map_token_to_display_name(token)


@lru_cache(maxsize=1)
def parse_shops_by_section_map_token() -> Dict[str, List[Dict[str, object]]]:
    item_names = parse_item_names()
    item_prices = parse_item_prices()
    species_names = parse_species_names()
    out: Dict[str, List[Dict[str, object]]] = {}
    seen_shop_keys: set[tuple[str, str, str, str]] = set()

    for map_script in _iter_map_scripts():
        map_token = str(map_script["mapToken"])
        scripts_text = str(map_script["scriptsText"])
        section_token = _section_map_token_for_internal_map(map_token)
        blocks = _label_blocks(scripts_text)
        table_items: Dict[str, List[str]] = {}
        for label, block in blocks.items():
            tokens = _item_table_tokens(block)
            if tokens:
                table_items[label] = tokens

        for script_label, block in blocks.items():
            for table_label in re.findall(r"\bpokemart\s+([A-Za-z0-9_]+)", block):
                items = table_items.get(table_label, [])
                if not items:
                    continue
                location_label = _shop_location_label(map_token)
                shop_label = _shop_label_from_script_name(script_label, table_label)
                variant_label = _shop_variant_label(table_label)
                dedupe_key = (section_token, location_label, shop_label, variant_label)
                if dedupe_key in seen_shop_keys:
                    continue
                seen_shop_keys.add(dedupe_key)

                offers: List[Dict[str, object]] = []
                for item_token in items:
                    offers.append(
                        {
                            "offerType": "item",
                            "token": item_token,
                            "name": item_names.get(item_token, pretty_token(item_token, "ITEM_")),
                            "cost": int(item_prices.get(item_token, 0)),
                            "currency": "money",
                        }
                    )

                out.setdefault(section_token, []).append(
                    {
                        "locationLabel": location_label,
                        "shopLabel": shop_label,
                        "variantLabel": variant_label,
                        "currency": "money",
                        "offers": offers,
                    }
                )

        if _normalize_map_token(map_token) != "CELADON_CITY_GAME_CORNER_PRIZE_ROOM":
            continue

        tm_offers: Dict[str, int] = {}
        mon_offers: Dict[str, int] = {}
        for token, cost_s in re.findall(
            r"setvar\s+VAR_TEMP_1,\s*(ITEM_TM\d+)\s*\n\s*setvar\s+VAR_TEMP_2,\s*(\d+)",
            scripts_text,
        ):
            tm_offers[token] = int(cost_s)
        for token, cost_s in re.findall(
            r"setvar\s+VAR_TEMP_1,\s*(SPECIES_[A-Z0-9_]+)\s*\n\s*setvar\s+VAR_TEMP_2,\s*(\d+)",
            scripts_text,
        ):
            mon_offers[token] = int(cost_s)

        if tm_offers:
            out.setdefault(section_token, []).append(
                {
                    "locationLabel": "Game Corner Prize Room",
                    "shopLabel": "TMs",
                    "variantLabel": "",
                    "currency": "coins",
                    "offers": [
                        {
                            "offerType": "item",
                            "token": token,
                            "name": item_names.get(token, pretty_token(token, "ITEM_")),
                            "cost": int(cost),
                            "currency": "coins",
                        }
                        for token, cost in sorted(tm_offers.items(), key=lambda kv: kv[1])
                    ],
                }
            )

        if mon_offers:
            out.setdefault(section_token, []).append(
                {
                    "locationLabel": "Game Corner Prize Room",
                    "shopLabel": "Pokémon",
                    "variantLabel": "",
                    "currency": "coins",
                    "offers": [
                        {
                            "offerType": "pokemon",
                            "token": token,
                            "name": species_names.get(token, pretty_token(token, "SPECIES_")),
                            "cost": int(cost),
                            "currency": "coins",
                        }
                        for token, cost in sorted(mon_offers.items(), key=lambda kv: kv[1])
                    ],
                }
            )

    for entries in out.values():
        entries.sort(key=lambda e: (str(e.get("locationLabel", "")).lower(), str(e.get("shopLabel", "")).lower(), str(e.get("variantLabel", "")).lower()))

    return out


MOVETUTOR_MOVE_TOKEN: Dict[str, str] = {
    "MOVETUTOR_MEGA_PUNCH": "MOVE_MEGA_PUNCH",
    "MOVETUTOR_SWORDS_DANCE": "MOVE_SWORDS_DANCE",
    "MOVETUTOR_MEGA_KICK": "MOVE_MEGA_KICK",
    "MOVETUTOR_BODY_SLAM": "MOVE_BODY_SLAM",
    "MOVETUTOR_DOUBLE_EDGE": "MOVE_DOUBLE_EDGE",
    "MOVETUTOR_COUNTER": "MOVE_COUNTER",
    "MOVETUTOR_SEISMIC_TOSS": "MOVE_SEISMIC_TOSS",
    "MOVETUTOR_MIMIC": "MOVE_MIMIC",
    "MOVETUTOR_METRONOME": "MOVE_METRONOME",
    "MOVETUTOR_SOFT_BOILED": "MOVE_SOFT_BOILED",
    "MOVETUTOR_DREAM_EATER": "MOVE_DREAM_EATER",
    "MOVETUTOR_THUNDER_WAVE": "MOVE_THUNDER_WAVE",
    "MOVETUTOR_EXPLOSION": "MOVE_EXPLOSION",
    "MOVETUTOR_ROCK_SLIDE": "MOVE_ROCK_SLIDE",
    "MOVETUTOR_SUBSTITUTE": "MOVE_SUBSTITUTE",
    "MOVETUTOR_FRENZY_PLANT": "MOVE_FRENZY_PLANT",
    "MOVETUTOR_BLAST_BURN": "MOVE_BLAST_BURN",
    "MOVETUTOR_HYDRO_CANNON": "MOVE_HYDRO_CANNON",
}

MOVETUTOR_PAYMENT_ITEM: Dict[str, str] = {
    "MOVETUTOR_DOUBLE_EDGE": "ITEM_RED_SHARD",
    "MOVETUTOR_ROCK_SLIDE": "ITEM_RED_SHARD",
    "MOVETUTOR_EXPLOSION": "ITEM_RED_SHARD",
    "MOVETUTOR_MEGA_PUNCH": "ITEM_RED_SHARD",
    "MOVETUTOR_MEGA_KICK": "ITEM_RED_SHARD",
    "MOVETUTOR_BODY_SLAM": "ITEM_RED_SHARD",
    "MOVETUTOR_BLAST_BURN": "ITEM_RED_SHARD",
    "MOVETUTOR_DREAM_EATER": "ITEM_BLUE_SHARD",
    "MOVETUTOR_HYDRO_CANNON": "ITEM_BLUE_SHARD",
    "MOVETUTOR_THUNDER_WAVE": "ITEM_YELLOW_SHARD",
    "MOVETUTOR_SEISMIC_TOSS": "ITEM_YELLOW_SHARD",
    "MOVETUTOR_COUNTER": "ITEM_YELLOW_SHARD",
    "MOVETUTOR_METRONOME": "ITEM_YELLOW_SHARD",
    "MOVETUTOR_SOFT_BOILED": "ITEM_GREEN_SHARD",
    "MOVETUTOR_SUBSTITUTE": "ITEM_GREEN_SHARD",
    "MOVETUTOR_SWORDS_DANCE": "ITEM_GREEN_SHARD",
    "MOVETUTOR_FRENZY_PLANT": "ITEM_GREEN_SHARD",
}


def _map_token_from_script_label_prefix(label_prefix: str) -> str:
    expanded = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", label_prefix)
    return _normalize_map_token(expanded.upper())


@lru_cache(maxsize=1)
def parse_move_tutors_by_section_map_token() -> Dict[str, List[Dict[str, object]]]:
    move_names = parse_move_names()
    item_names = parse_item_names()
    out: Dict[str, List[Dict[str, object]]] = {}
    seen: set[tuple[str, str, str, str]] = set()

    tutor_script_text = read_text("data/scripts/move_tutors.inc")
    tutor_blocks = _label_blocks(tutor_script_text)

    object_gfx_to_info = parse_object_event_gfx_to_info_symbol()
    graphics_info_tables = parse_object_event_graphics_info_tables()
    pic_tables = parse_object_event_pic_tables()
    pic_symbol_to_png = parse_object_event_pic_symbol_to_png_path()

    def _npc_gfx_png_path(gfx_token: str) -> str:
        info_symbol = object_gfx_to_info.get(gfx_token, "")
        if not info_symbol:
            return ""
        info = graphics_info_tables.get(info_symbol)
        if not info:
            return ""
        pic_table_symbol = str(info.get("picTable", ""))
        if not pic_table_symbol:
            return ""
        pic_table = pic_tables.get(pic_table_symbol)
        if not pic_table:
            return ""
        pic_symbol = str(pic_table.get("picSymbol", ""))
        if not pic_symbol:
            return ""
        return str(pic_symbol_to_png.get(pic_symbol, ""))

    map_scripts = _iter_map_scripts()
    map_script_blocks: Dict[str, Dict[str, str]] = {}
    map_npc_gfx_by_script: Dict[str, Dict[str, str]] = {}
    for map_script in map_scripts:
        map_token = str(map_script["mapToken"])
        normalized_map_token = _normalize_map_token(map_token)
        scripts_text = str(map_script["scriptsText"])
        script_blocks = _label_blocks(scripts_text)
        map_script_blocks[map_token] = script_blocks
        map_script_blocks.setdefault(normalized_map_token, script_blocks)

        scripts_path = str(map_script.get("scriptsPath", ""))
        map_json_path = ROOT / scripts_path.replace("scripts.inc", "map.json")
        script_to_gfx: Dict[str, str] = {}
        if map_json_path.is_file():
            try:
                map_data = json.loads(map_json_path.read_text(encoding="utf-8"))
            except Exception:
                map_data = {}
            for event in map_data.get("object_events", []):
                if not isinstance(event, dict):
                    continue
                if str(event.get("type", "")) != "object":
                    continue
                script_label = str(event.get("script", "")).strip()
                gfx_token = str(event.get("graphics_id", "")).strip()
                if not script_label or not gfx_token:
                    continue
                script_to_gfx.setdefault(script_label, gfx_token)
            map_npc_gfx_by_script[map_token] = script_to_gfx
            map_npc_gfx_by_script.setdefault(normalized_map_token, script_to_gfx)

    def _resolve_npc_for_script(map_token: str, script_label: str) -> tuple[str, str]:
        gfx_token = str(map_npc_gfx_by_script.get(map_token, {}).get(script_label, ""))
        if not gfx_token:
            return "", ""
        return gfx_token, _npc_gfx_png_path(gfx_token)

    tutor_by_target_label: Dict[str, Dict[str, object]] = {}
    for label, body in tutor_blocks.items():
        tutor_match = re.search(r"setvar\s+VAR_0x8005,\s*(MOVETUTOR_[A-Z_]+)", body)
        if tutor_match:
            tutor_token = tutor_match.group(1)
            move_token = MOVETUTOR_MOVE_TOKEN.get(tutor_token, "")
            payment_item = MOVETUTOR_PAYMENT_ITEM.get(tutor_token, "ITEM_NONE")
            tutor_by_target_label[label] = {
                "moveToken": move_token,
                "moveName": move_names.get(move_token, pretty_token(move_token, "MOVE_")) if move_token else "Move Tutor",
                "paymentItemToken": payment_item,
                "paymentItemName": item_names.get(payment_item, pretty_token(payment_item, "ITEM_")) if payment_item != "ITEM_NONE" else "",
                "paymentCount": 1,
                "notes": "",
            }

    tutor_by_target_label["EventScript_MimicTutor"] = {
        "moveToken": "MOVE_MIMIC",
        "moveName": move_names.get("MOVE_MIMIC", "Mimic"),
        "paymentItemToken": "ITEM_POKE_DOLL",
        "paymentItemName": item_names.get("ITEM_POKE_DOLL", "Poke Doll"),
        "paymentCount": 1,
        "notes": "",
    }

    for label, meta in tutor_by_target_label.items():
        if "_EventScript_" not in label or label.startswith("EventScript_"):
            continue
        map_prefix = label.split("_EventScript_", 1)[0]
        map_token = _map_token_from_script_label_prefix(map_prefix)
        section_token = _section_map_token_for_internal_map(map_token)
        npc_gfx_token, npc_icon_path = _resolve_npc_for_script(map_token, label)
        if not npc_gfx_token:
            continue
        key = (section_token, map_token, str(meta.get("moveToken", "")), str(meta.get("paymentItemToken", "")))
        if key in seen:
            continue
        seen.add(key)
        out.setdefault(section_token, []).append(
            {
                "locationLabel": _map_token_to_display_name(map_token),
                "npcGfxToken": npc_gfx_token,
                "npcIconPath": npc_icon_path,
                **meta,
            }
        )

    for map_script in map_scripts:
        map_token = str(map_script["mapToken"])
        scripts_text = str(map_script["scriptsText"])
        section_token = _section_map_token_for_internal_map(map_token)
        label_blocks = map_script_blocks.get(map_token, {})

        def find_source_tutor_script(target_label: str) -> str:
            source_labels = [
                label_name
                for label_name, body in label_blocks.items()
                if re.search(rf"\bgoto\s+{re.escape(target_label)}\b", body)
            ]
            for source_label in source_labels:
                if source_label in map_npc_gfx_by_script.get(map_token, {}):
                    return source_label
            return source_labels[0] if source_labels else ""

        for target in re.findall(r"\bgoto\s+([A-Za-z0-9_]*Tutor)\b", scripts_text):
            meta = tutor_by_target_label.get(target)
            if not meta:
                continue
            source_script = find_source_tutor_script(target)
            npc_gfx_token, npc_icon_path = _resolve_npc_for_script(map_token, source_script)
            key = (section_token, map_token, str(meta.get("moveToken", "")), str(meta.get("paymentItemToken", "")))
            if key in seen:
                continue
            seen.add(key)
            out.setdefault(section_token, []).append(
                {
                    "locationLabel": _map_token_to_display_name(map_token),
                    "npcGfxToken": npc_gfx_token,
                    "npcIconPath": npc_icon_path,
                    **meta,
                }
            )

        if re.search(r"EventScript_EggMoveTutor", scripts_text) and re.search(r"checkitem\s+ITEM_HEART_SCALE", scripts_text):
            egg_script_label = ""
            for script_label in map_npc_gfx_by_script.get(map_token, {}):
                if script_label.endswith("_EventScript_EggMoveTutor"):
                    egg_script_label = script_label
                    break
            egg_gfx_token, egg_icon_path = _resolve_npc_for_script(map_token, egg_script_label)
            egg_key = (section_token, map_token, "MOVE_EGG_MOVE", "ITEM_HEART_SCALE")
            if egg_key not in seen:
                seen.add(egg_key)
                out.setdefault(section_token, []).append(
                    {
                        "locationLabel": _map_token_to_display_name(map_token),
                        "npcGfxToken": egg_gfx_token,
                        "npcIconPath": egg_icon_path,
                        "moveToken": "MOVE_EGG_MOVE",
                        "moveName": "Egg Move",
                        "paymentItemToken": "ITEM_HEART_SCALE",
                        "paymentItemName": item_names.get("ITEM_HEART_SCALE", "Heart Scale"),
                        "paymentCount": 1,
                    }
                )

        if re.search(r"_EventScript_MoveManiac::", scripts_text) and re.search(r"\bChooseMonForMoveRelearner\b", scripts_text):
            relearn_script_label = ""
            for script_label in map_npc_gfx_by_script.get(map_token, {}):
                if script_label.endswith("_EventScript_MoveManiac"):
                    relearn_script_label = script_label
                    break
            relearn_gfx_token, relearn_icon_path = _resolve_npc_for_script(map_token, relearn_script_label)
            relearn_key = (section_token, map_token, "MOVE_RELEARNER", "MUSHROOM_OPTIONS")
            if relearn_key not in seen:
                seen.add(relearn_key)
                out.setdefault(section_token, []).append(
                    {
                        "locationLabel": _map_token_to_display_name(map_token),
                        "npcGfxToken": relearn_gfx_token,
                        "npcIconPath": relearn_icon_path,
                        "moveToken": "MOVE_RELEARNER",
                        "moveName": "Move Relearner",
                        "paymentItemToken": "ITEM_BIG_MUSHROOM",
                        "paymentItemName": item_names.get("ITEM_BIG_MUSHROOM", "Big Mushroom"),
                        "paymentCount": 1,
                        "paymentOptions": [
                            {
                                "itemToken": "ITEM_BIG_MUSHROOM",
                                "itemName": item_names.get("ITEM_BIG_MUSHROOM", "Big Mushroom"),
                                "count": 1,
                            },
                            {
                                "itemToken": "ITEM_TINY_MUSHROOM",
                                "itemName": item_names.get("ITEM_TINY_MUSHROOM", "Tiny Mushroom"),
                                "count": 2,
                            },
                        ],
                        "notes": "",
                    }
                )

    cape_brink_section = _section_map_token_for_internal_map("TWO_ISLAND_CAPE_BRINK_HOUSE")
    cape_brink_location = _map_token_to_display_name("TWO_ISLAND_CAPE_BRINK_HOUSE")
    cape_brink_script_map = map_npc_gfx_by_script.get("TWO_ISLAND_CAPE_BRINK_HOUSE", {})
    cape_brink_script_label = ""
    for script_label in cape_brink_script_map:
        if script_label.endswith("_EventScript_StarterTutor"):
            cape_brink_script_label = script_label
            break
    if not cape_brink_script_label and cape_brink_script_map:
        cape_brink_script_label = next(iter(cape_brink_script_map.keys()))
    cape_brink_gfx_token, cape_brink_icon_path = _resolve_npc_for_script("TWO_ISLAND_CAPE_BRINK_HOUSE", cape_brink_script_label)

    starter_rows = [
        ("MOVE_FRENZY_PLANT", "ITEM_GREEN_SHARD", "Lead Venusaur with max friendship"),
        ("MOVE_BLAST_BURN", "ITEM_RED_SHARD", "Lead Charizard with max friendship"),
        ("MOVE_HYDRO_CANNON", "ITEM_BLUE_SHARD", "Lead Blastoise with max friendship"),
    ]
    for move_token, payment_item, notes in starter_rows:
        key = (cape_brink_section, "TWO_ISLAND_CAPE_BRINK_HOUSE", move_token, payment_item)
        if key in seen:
            continue
        seen.add(key)
        out.setdefault(cape_brink_section, []).append(
            {
                "locationLabel": cape_brink_location,
                "npcGfxToken": cape_brink_gfx_token,
                "npcIconPath": cape_brink_icon_path,
                "moveToken": move_token,
                "moveName": move_names.get(move_token, pretty_token(move_token, "MOVE_")),
                "paymentItemToken": payment_item,
                "paymentItemName": item_names.get(payment_item, pretty_token(payment_item, "ITEM_")),
                "paymentCount": 1,
                "notes": notes,
            }
        )

    for entries in out.values():
        entries.sort(
            key=lambda e: (
                str(e.get("locationLabel", "")).lower(),
                str(e.get("moveName", "")).lower(),
                str(e.get("paymentItemName", "")).lower(),
            )
        )

    return out


@lru_cache(maxsize=1)
def parse_npc_gift_items_by_section_map_token() -> Dict[str, List[Dict[str, object]]]:
    item_names = parse_item_names()
    out: Dict[str, List[Dict[str, object]]] = {}

    direct_giveitem_re = re.compile(r"\bgiveitem\s+(ITEM_[A-Z0-9_]+)(?:\s*,\s*(\d+))?")
    giveitem_msg_re = re.compile(r"\bgiveitem_msg\s+[^\n]*?,\s*(ITEM_[A-Z0-9_]+)(?:\s*,\s*(\d+))?")

    for map_script in _iter_map_scripts():
        map_token = str(map_script["mapToken"])
        scripts_text = str(map_script["scriptsText"])
        section_token = _section_map_token_for_internal_map(map_token)
        seen_tokens: set[tuple[str, int]] = set()

        for token, qty_s in direct_giveitem_re.findall(scripts_text):
            if token not in item_names:
                continue
            qty = int(qty_s) if qty_s else 1
            key = (token, qty)
            if key in seen_tokens:
                continue
            seen_tokens.add(key)
            out.setdefault(section_token, []).append(
                {
                    "itemToken": token,
                    "quantity": qty,
                    "isHidden": False,
                    "source": "npc_gift",
                }
            )

        for token, qty_s in giveitem_msg_re.findall(scripts_text):
            if token not in item_names:
                continue
            qty = int(qty_s) if qty_s else 1
            key = (token, qty)
            if key in seen_tokens:
                continue
            seen_tokens.add(key)
            out.setdefault(section_token, []).append(
                {
                    "itemToken": token,
                    "quantity": qty,
                    "isHidden": False,
                    "source": "npc_gift",
                }
            )

    return out


def parse_item_icon_table() -> Dict[str, Dict[str, str]]:
    text = read_text("src/data/item_icon_table.h")
    out: Dict[str, Dict[str, str]] = {}
    row_re = re.compile(
        r"\[(ITEM_[A-Z0-9_]+)\]\s*=\s*\{\s*(gItemIcon_[A-Za-z0-9_]+)\s*,\s*(gItemIconPalette_[A-Za-z0-9_]+)\s*\}",
        re.M,
    )
    for item_token, icon_symbol, palette_symbol in row_re.findall(text):
        out[item_token] = {
            "iconSymbol": icon_symbol,
            "paletteSymbol": palette_symbol,
        }
    return out


def parse_item_icon_symbol_to_paths() -> Dict[str, Dict[str, str]]:
    text = read_text("src/data/graphics/items.h")
    icon_path_by_symbol: Dict[str, str] = {}
    palette_path_by_symbol: Dict[str, str] = {}

    icon_re = re.compile(r"const u32\s+(gItemIcon_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U32\(\"([^\"]+)\"\);")
    palette_re = re.compile(r"const u32\s+(gItemIconPalette_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U32\(\"([^\"]+)\"\);")

    for symbol, path in icon_re.findall(text):
        icon_path_by_symbol[symbol] = path.replace(".4bpp.lz", ".png")

    for symbol, path in palette_re.findall(text):
        palette_path_by_symbol[symbol] = path

    return {
        "icons": icon_path_by_symbol,
        "palettes": palette_path_by_symbol,
    }


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


def _item_script_suffix_to_token(script_name: str, item_name_lookup: Dict[str, str]) -> Optional[str]:
    suffix_match = re.search(r"EventScript_Item([A-Za-z0-9_]+)$", script_name)
    if not suffix_match:
        return None

    suffix = suffix_match.group(1).strip()
    if not suffix:
        return None

    compact = re.sub(r"[^A-Za-z0-9]", "", suffix).upper()
    if not compact:
        return None

    if compact.startswith("TM") and compact[2:].isdigit():
        token = f"ITEM_{compact}"
        return token if token in item_name_lookup.values() else None
    if compact.startswith("HM") and compact[2:].isdigit():
        token = f"ITEM_{compact}"
        return token if token in item_name_lookup.values() else None

    return item_name_lookup.get(compact)


@lru_cache(maxsize=1)
def parse_map_items_by_map() -> Dict[str, List[Dict[str, object]]]:
    """Parse item-ball and hidden-item pickups from data/maps/*/map.json."""
    item_names = parse_item_names()
    item_lookup = {re.sub(r"[^A-Za-z0-9]", "", token[5:]).upper(): token for token in item_names}
    out: Dict[str, List[Dict[str, object]]] = {}

    for map_json in sorted((ROOT / "data" / "maps").glob("*/map.json")):
        data = json.loads(map_json.read_text(encoding="utf-8"))
        map_id = str(data.get("id", "")).strip()
        if not map_id.startswith("MAP_"):
            continue

        map_token = map_id[4:]
        map_items: List[Dict[str, object]] = []
        seen: set[tuple[object, ...]] = set()

        for event in data.get("bg_events", []):
            if not isinstance(event, dict) or str(event.get("type", "")) != "hidden_item":
                continue
            item_token = str(event.get("item", "")).strip()
            if not item_token or item_token == "ITEM_NONE":
                continue

            quantity = int(event.get("quantity", 1) or 1)
            hidden_key = (
                "hidden_item",
                item_token,
                int(event.get("x", 0)),
                int(event.get("y", 0)),
                int(event.get("elevation", 0)),
                str(event.get("flag", "")),
            )
            if hidden_key in seen:
                continue
            seen.add(hidden_key)
            if item_token not in item_names:
                continue

            map_items.append(
                {
                    "itemToken": item_token,
                    "quantity": quantity,
                    "isHidden": True,
                    "x": int(event.get("x", 0)),
                    "y": int(event.get("y", 0)),
                    "elevation": int(event.get("elevation", 0)),
                    "flag": str(event.get("flag", "")),
                    "script": "",
                }
            )

        for event in data.get("object_events", []):
            if not isinstance(event, dict):
                continue
            if str(event.get("type", "")) != "object":
                continue
            if str(event.get("graphics_id", "")) != "OBJ_EVENT_GFX_ITEM_BALL":
                continue

            item_token = _item_script_suffix_to_token(str(event.get("script", "")), item_lookup)
            if not item_token or item_token not in item_names:
                continue

            visible_key = (
                "item_ball",
                item_token,
                int(event.get("x", 0)),
                int(event.get("y", 0)),
                int(event.get("elevation", 0)),
                str(event.get("flag", "")),
                str(event.get("script", "")),
            )
            if visible_key in seen:
                continue
            seen.add(visible_key)

            map_items.append(
                {
                    "itemToken": item_token,
                    "quantity": 1,
                    "isHidden": False,
                    "x": int(event.get("x", 0)),
                    "y": int(event.get("y", 0)),
                    "elevation": int(event.get("elevation", 0)),
                    "flag": str(event.get("flag", "")),
                    "script": str(event.get("script", "")),
                }
            )

        if map_items:
            out[map_token] = map_items

    return out


@lru_cache(maxsize=1)
def parse_object_event_pic_symbol_to_png_path() -> Dict[str, str]:
    text = read_text("src/data/object_events/object_event_graphics.h")
    out: Dict[str, str] = {}
    pattern = re.compile(r"const u(?:16|32)\s+(gObjectEventPic_[A-Za-z0-9_]+)\[\]\s*=\s*INCBIN_U(?:16|32)\(\"([^\"]+)\"\);")
    for symbol, path in pattern.findall(text):
        png_path = path
        if png_path.endswith(".4bpp.lz"):
            png_path = png_path[: -len(".4bpp.lz")] + ".png"
        elif png_path.endswith(".4bpp"):
            png_path = png_path[: -len(".4bpp")] + ".png"
        else:
            continue
        out[symbol] = png_path
    return out


@lru_cache(maxsize=1)
def parse_object_event_pic_tables() -> Dict[str, Dict[str, Any]]:
    text = read_text("src/data/object_events/object_event_pic_tables.h")
    out: Dict[str, Dict[str, Any]] = {}
    table_re = re.compile(r"static const struct SpriteFrameImage\s+(sPicTable_[A-Za-z0-9_]+)\[\]\s*=\s*\{(.*?)\n\};", re.S)
    frame_re = re.compile(r"overworld_frame\((gObjectEventPic_[A-Za-z0-9_]+),\s*(\d+)\s*,\s*(\d+)\s*,\s*(\d+)\)")

    for table_symbol, body in table_re.findall(text):
        frames = frame_re.findall(body)
        if not frames:
            continue
        pic_symbol, tiles_w_s, tiles_h_s, frame_idx_s = frames[0]
        # Each pic-table entry maps an animation frame index to a source frame
        # in the sprite sheet (the 4th overworld_frame() argument). Standard NPC
        # sheets are laid out as a horizontal strip, so frameX == sourceFrame * frameW.
        out[table_symbol] = {
            "picSymbol": pic_symbol,
            "tilesW": int(tiles_w_s),
            "tilesH": int(tiles_h_s),
            "frame": int(frame_idx_s),
            "sourceFrames": [int(entry[3]) for entry in frames],
            "frameCount": len(frames),
        }
    return out


@lru_cache(maxsize=1)
def parse_object_event_graphics_info_tables() -> Dict[str, Dict[str, Any]]:
    text = read_text("src/data/object_events/object_event_graphics_info.h")
    out: Dict[str, Dict[str, Any]] = {}
    info_re = re.compile(r"const struct ObjectEventGraphicsInfo\s+(gObjectEventGraphicsInfo_[A-Za-z0-9_]+)\s*=\s*\{(.*?)\n\};", re.S)

    for info_symbol, body in info_re.findall(text):
        images_match = re.search(r"\.images\s*=\s*(sPicTable_[A-Za-z0-9_]+)", body)
        width_match = re.search(r"\.width\s*=\s*(-?\d+)", body)
        height_match = re.search(r"\.height\s*=\s*(-?\d+)", body)
        inanimate_match = re.search(r"\.inanimate\s*=\s*(TRUE|FALSE)", body)
        if not images_match:
            continue
        out[info_symbol] = {
            "picTable": images_match.group(1),
            "width": int(width_match.group(1)) if width_match else 16,
            "height": int(height_match.group(1)) if height_match else 16,
            # Inanimate objects (trees, rocks, boulders, item balls, ...) never
            # turn to face a direction; their extra frames are interaction
            # animations, so they must always render frame 0.
            "inanimate": bool(inanimate_match and inanimate_match.group(1) == "TRUE"),
        }
    return out


@lru_cache(maxsize=1)
def parse_initial_movement_facing_directions() -> Dict[str, str]:
    """Map MOVEMENT_TYPE_* to the DIR_* an object faces when first placed.

    Mirrors gInitialMovementTypeFacingDirections[] in src/event_object_movement.c,
    which is what porymap uses to orient event sprites in the map editor.
    """
    text = read_text("src/event_object_movement.c")
    table_match = re.search(
        r"gInitialMovementTypeFacingDirections\s*\[[^\]]*\]\s*=\s*\{(.*?)\n\};",
        text,
        re.S,
    )
    out: Dict[str, str] = {}
    if not table_match:
        return out
    for movement_type, direction in re.findall(
        r"\[(MOVEMENT_TYPE_[A-Z0-9_]+)\]\s*=\s*(DIR_[A-Z]+)",
        table_match.group(1),
    ):
        out[movement_type] = direction
    return out


@lru_cache(maxsize=1)
def parse_object_event_gfx_to_info_symbol() -> Dict[str, str]:
    text = read_text("src/data/object_events/object_event_graphics_info_pointers.h")
    out: Dict[str, str] = {}
    pointer_re = re.compile(r"\[(OBJ_EVENT_GFX_[A-Z0-9_]+)\]\s*=\s*&\s*(gObjectEventGraphicsInfo_[A-Za-z0-9_]+)")
    for gfx_token, info_symbol in pointer_re.findall(text):
        out[gfx_token] = info_symbol
    return out


def parse_map_object_events(map_json_rel_path: str) -> List[Dict[str, Any]]:
    """Return every object event placed on a map (matching porymap's view).

    Flag-gated events (the Route 22 rival, hidden Team Rocket grunts, cuttable
    trees, rock-smash rocks, strength boulders, ...) are intentionally kept here
    even though the game hides them behind flags during normal play.
    """
    map_data = json.loads(read_text(map_json_rel_path))
    out: List[Dict[str, Any]] = []
    seen: set = set()

    for idx, event in enumerate(map_data.get("object_events", []), start=1):
        if not isinstance(event, dict):
            continue
        if str(event.get("type", "")) != "object":
            continue

        gfx_token = str(event.get("graphics_id", ""))
        if not gfx_token:
            continue

        try:
            x = int(event.get("x", 0))
            y = int(event.get("y", 0))
        except (TypeError, ValueError):
            continue

        movement_type = str(event.get("movement_type", ""))
        dedupe_key = (gfx_token, x, y, movement_type)
        if dedupe_key in seen:
            continue
        seen.add(dedupe_key)

        out.append({
            "objectId": idx,
            "localId": str(event.get("local_id", "")),
            "graphicsId": gfx_token,
            "x": x,
            "y": y,
            "movementType": movement_type,
        })

    return out


def parse_trainers() -> Dict[str, Dict[str, str]]:
    text = read_text("src/data/trainers.h")
    out: Dict[str, Dict[str, str]] = {}
    entry_re = re.compile(r"\[(TRAINER_[A-Z0-9_]+)\]\s*=\s*\{(.*?)\n\s*\},", re.S)
    for trainer_id, body in entry_re.findall(text):
        cls = re.search(r"\.trainerClass\s*=\s*(TRAINER_CLASS_[A-Z0-9_]+)", body)
        pic = re.search(r"\.trainerPic\s*=\s*(TRAINER_PIC_[A-Z0-9_]+)", body)
        name = re.search(r"\.trainerName\s*=\s*_\(\"([^\"]*)\"\)", body)
        encounter = re.search(r"\.encounterMusic_gender\s*=\s*([^,\n]+)", body)
        double_battle = re.search(r"\.doubleBattle\s*=\s*(TRUE|FALSE)", body)
        party = re.search(r"\.party\s*=\s*([A-Z0-9_]+)\((sParty_[A-Za-z0-9_]+)\)", body)
        if not party:
            continue
        encounter_expr = encounter.group(1).strip() if encounter else ""
        out[trainer_id] = {
            "trainerClass": cls.group(1) if cls else "TRAINER_CLASS_NONE",
            "trainerPic": pic.group(1) if pic else "TRAINER_PIC_YOUNGSTER",
            "trainerName": name.group(1) if name else "",
            "encounterMusicGender": encounter_expr,
            "isFemale": "F_TRAINER_FEMALE" in encounter_expr,
            "doubleBattle": bool(double_battle and double_battle.group(1) == "TRUE"),
            "partyMacro": party.group(1),
            "partyName": party.group(2),
        }
    return out


@lru_cache(maxsize=1)
def parse_vs_seeker_rematch_stages() -> Dict[str, int]:
    """Map rematch trainer ids to VS Seeker unlock stage (1..5).

    Stage indices match IsRematchStageUnlocked() in src/vs_seeker.c:
      1: got VS Seeker
      2: reached Celadon City
      3: reached Fuchsia City
      4: game clear
      5: post-game link unlock
    """
    text = read_text("src/vs_seeker.c")
    table_match = re.search(
        r"static const struct RematchData sRematches\[\]\s*=\s*\{(.*?)\n\};",
        text,
        re.S,
    )
    if not table_match:
        return {}

    body = table_match.group(1)
    rematch_stage_by_trainer: Dict[str, int] = {}

    entry_re = re.compile(r"\{\s*\{([^{}]*)\}\s*,\s*MAP\([^)]*\)\s*\}", re.S)
    for trainer_list_raw in entry_re.findall(body):
        slots = [token.strip() for token in trainer_list_raw.split(",") if token.strip()]
        if len(slots) <= 1:
            continue

        base_trainer_id = slots[0]

        for stage, trainer_id in enumerate(slots[1:], start=1):
            if trainer_id == "SKIP":
                continue
            if not trainer_id.startswith("TRAINER_"):
                continue
            if trainer_id == base_trainer_id:
                continue
            rematch_stage_by_trainer.setdefault(trainer_id, stage)

    return rematch_stage_by_trainer


def extract_top_level_brace_blocks(text: str) -> List[str]:
    # Trainer party files often comment out individual mon entries in-place.
    # Strip line comments before scanning braces so those placeholder blocks
    # are not treated as real party members.
    text = "\n".join(line.split("//", 1)[0] for line in text.splitlines())
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
    for key in ("iv", "lvl", "species", "heldItem", "nature", "ability", "abilitySlot"):
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
    floor_re = re.compile(r"^(?:B\d+F|\d+F|Deck)$", re.I)
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
