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
    parse_map_items_by_map,
    parse_move_tutors_by_section_map_token,
    parse_mon_symbol_to_png_path,
    parse_npc_gift_items_by_section_map_token,
    parse_trade_gift_pokemon_by_section_map_token,
    parse_move_names,
    parse_tmhm_move_tokens_by_item_token,
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
    parse_vs_seeker_rematch_stages,
    parse_shops_by_section_map_token,
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
    "vermilion city gym": "gym-vermilion",
    "celadon city": "city-celadon",
    "celadon city gym": "gym-celadon",
    "saffron city dojo": "city-cinnabar",
    "fuchsia city": "city-fuchsia",
    "lavender town": "city-lavender",
    "saffron city": "city-saffron",
    "viridian city": "city-viridian",
    "cinnabar island": "city-cinnabar",
    "cinnabar island gym": "gym-cinnabar",
    "indigo plateau": "indigo-plateau",
    "fuchsia city gym": "gym-fuchsia",
    "saffron city gym": "gym-saffron",
    "viridian city gym": "gym-viridian",
    # League
    "lorelei": "e4-lorelei",
    "bruno": "e4-bruno",
    "agatha": "e4-agatha",
    "lance": "e4-lance",
    "champion": "champion",
}

SECTION_MAP_TOKEN_OVERRIDES: Dict[str, str] = {
    "oak's lab": "PALLET_TOWN_PROFESSOR_OAKS_LAB",
}

OVERVIEW_DIR = Path(__file__).resolve().parent

REMATCH_CHECKPOINT_BY_STAGE: Dict[int, str] = {
    1: "getting VS Seeker",
    2: "reaching Celadon City",
    3: "reaching Fuchsia City",
    4: "becoming Champion",
    5: "delivering the Sapphire",
}


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


def should_skip_encounter_section(section_name: str, known_names: set[str]) -> bool:
    """Determine if an encounter-generated section should be skipped as redundant.
    
    This handles the specific cases where map encounters create duplicate section
    names that should be filtered because they're already covered by trainer sections.
    """
    name_lower = section_name.lower()
    
    # Diglett's Cave is already covered by trainer section
    if "diglett" in name_lower and "cave" in name_lower:
        return True
    
    # Pokémon Mansion floors are already covered by trainer sections
    if "pokémon mansion" in name_lower or "pokemon mansion" in name_lower:
        return True
    
    # Pokémon Tower floors are already covered by dedicated Pokémon Tower sections
    if re.search(r"pokémon\s*tower\s+\d+\s*f", name_lower) or re.search(r"pokemon\s*tower\s+\d+\s*f", name_lower):
        return True
    
    # Mt. Ember variants are already covered by Mt. Ember, Mt. Ember Path, Mt. Ember Summit
    if re.search(r"mt\.?\s*ember", name_lower):
        if "mt. ember" not in {n.lower() for n in known_names}:
            # Only skip if "Mt. Ember" already exists in known sections
            pass
        elif section_name.lower() not in {"mt. ember", "mt. ember path", "mt. ember summit"}:
            # Skip variants like "Mt. Ember Exterior", "Mt. Ember Entrance", etc.
            return True
    
    # Four Island Icefall Cave - all variants should be skipped
    # User wants only specific Icefall Cave entry if any
    if "icefall cave" in name_lower and ("four island" in name_lower or "entrance" in name_lower):
        return True
    
    # Five Island Lost Cave - all variants should be skipped
    # User wants only specific Lost Cave entry if any  
    if "lost cave" in name_lower and ("five island" in name_lower or "room" in name_lower):
        return True
    
    # Island-prefixed versions should be skipped if the non-prefixed versions exist
    # (or versions without the island prefix but with directional/positional suffixes)
    island_prefixes = [
        "one island ",
        "two island ",
        "three island ",
    ]
    for prefix in island_prefixes:
        if name_lower.startswith(prefix):
            base_name = name_lower[len(prefix):]
            known_names_lower = {n.lower() for n in known_names}
            
            # Check for exact match of base name
            if base_name in known_names_lower:
                return True
            
            # Check for base name with directional suffixes (North, South, East, West, etc.)
            directional_terms = ["north", "south", "east", "west", "upper", "lower", "left", "right", "inner", "outer"]
            for term in directional_terms:
                if any(f"{base_name} {term}" in n.lower() or f"{term} {base_name}" in n.lower() for n in known_names_lower):
                    return True
            
            # For specific cases like "One Island Kindle Road" matching both "Kindle Road North" and "Kindle Road South"
            if base_name.startswith("kindle") and any("kindle road" in n.lower() for n in known_names_lower):
                return True
            
            if base_name == "bond bridge" and any("bond bridge" in n.lower() for n in known_names_lower):
                return True
    
    # Berry Forest variants - filter out if base exists
    if "berry forest" in name_lower:
        if any("berry forest" in n.lower() for n in known_names):
            # Only keep the plain "Berry Forest", skip variants
            if section_name.lower() != "berry forest":
                return True
    
    return False


def camel_words(name: str) -> str:
    return re.sub(r"([a-z0-9])([A-Z])", r"\1 \2", name.replace("_", " ")).strip()


def map_token_to_section_name(map_token: str) -> str:
    map_token = normalize_map_token(map_token)
    parts: List[str] = []
    floor_parts: List[str] = []  # Accumulate floor letters/digits
    
    for raw in map_token.split("_"):
        token = raw.strip()
        if not token:
            continue
        upper = token.upper()
        
        # Handle floor formatting: collect B, digits, and F without spaces
        if len(upper) == 1 and upper in ("B", "F"):
            floor_parts.append(upper)
        elif upper.isdigit():
            floor_parts.append(upper)
        else:
            # If we have accumulated floor parts, join them without spaces
            if floor_parts:
                parts.append("".join(floor_parts))
                floor_parts = []
            
            # Process non-floor tokens
            if re.fullmatch(r"B\d+F|\d+F", upper):
                parts.append(upper)
            elif len(upper) <= 2 and upper.isalpha():
                parts.append(upper)
            else:
                parts.append(upper[:1] + upper[1:].lower())
    
    # Flush any remaining floor parts
    if floor_parts:
        parts.append("".join(floor_parts))
    
    return " ".join(parts) or pretty_token(map_token, "")


def resolve_section_theme(section_name: str) -> str:
    key = section_name.strip().lower()
    if key in SECTION_THEME_OVERRIDES:
        return SECTION_THEME_OVERRIDES[key]

    if "mt. moon" in key or "mt moon" in key:
        return "moon"

    if "diglett" in key and "cave" in key:
        return "diglett-cave"

    if "rock tunnel" in key:
        return "rock-tunnel"

    if "pokémon mansion" in key or "pokemon mansion" in key:
        return "mansion"

    if key in {
        "one island",
        "two island",
        "three island",
        "four island",
        "five island",
        "six island",
        "seven island",
    }:
        return "islands"

    if "mt. ember" in key or "mt ember" in key:
        return "ember"

    if "victory road" in key:
        return "victory-road"

    if "cerulean cave" in key:
        return "cerulean-cave"

    if "pokémon tower" in key:
        return "tower-ghost"

    if "s.s. anne" in key:
        return "route-water"
    
    if "seafoam" in key:
        return "ice"
    
    if key in {
        "treasure beach",
        "kindle road south",
        "kindle road north",
        "cape brink",
        "three island port",
        "bond bridge",
    }:
        return "route"

    if key in {
        "route 12 north",
        "route 19",
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
    
    if "pallet" in key:
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


def infer_player_starter_from_rival_party(party_name: str) -> Optional[str]:
    party = party_name.lower()
    if "charmander" in party:
        return "SPECIES_BULBASAUR"
    if "squirtle" in party:
        return "SPECIES_CHARMANDER"
    if "bulbasaur" in party:
        return "SPECIES_SQUIRTLE"
    return None


def is_starter_variant_trainer(trainer_id: str, trainer_name: str) -> bool:
    trainer_id_upper = trainer_id.upper()
    trainer_name_upper = trainer_name.upper()
    return (
        trainer_id_upper.startswith("TRAINER_RIVAL_")
        or trainer_id_upper.startswith("TRAINER_CHAMPION_")
        or trainer_name_upper == "RIVAL"
        or trainer_name_upper == "CHAMPION"
    )


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
    tmhm_move_tokens_by_item_token = parse_tmhm_move_tokens_by_item_token()
    rematch_stage_by_trainer = parse_vs_seeker_rematch_stages()
    item_icon_table = parse_item_icon_table()
    item_icon_paths = parse_item_icon_symbol_to_paths()
    map_items_by_token = parse_map_items_by_map()
    npc_gift_items_by_section_token = parse_npc_gift_items_by_section_map_token()
    trade_gifts_by_section_token = parse_trade_gift_pokemon_by_section_map_token()
    shops_by_section_token = parse_shops_by_section_map_token()
    tutors_by_section_token = parse_move_tutors_by_section_map_token()
    trainer_pic_ids = parse_define_ints("include/constants/trainers.h", "TRAINER_PIC_")
    species_ids = parse_define_ints("include/constants/species.h", "SPECIES_")
    pokemon_define_ints = parse_define_ints("include/constants/pokemon.h", "")
    type_ids = parse_define_ints("include/constants/pokemon.h", "TYPE_")
    type_token_by_id = {value: token for token, value in type_ids.items()}
    max_per_stat_ivs = int(pokemon_define_ints.get("MAX_PER_STAT_IVS", 31))
    use_random_ivs = int(pokemon_define_ints.get("USE_RANDOM_IVS", max_per_stat_ivs + 1))
    number_of_mon_types = int(pokemon_define_ints.get("NUMBER_OF_MON_TYPES", 18))
    type_mystery_id = int(type_ids.get("TYPE_MYSTERY", 9))
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

    tmhm_move_name_by_item_token: Dict[str, str] = {}
    for item_token, move_token in tmhm_move_tokens_by_item_token.items():
        if not item_token or not move_token:
            continue
        tmhm_move_name_by_item_token[item_token] = move_names.get(move_token, pretty_token(move_token, "MOVE_"))
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
            return "graphics/pokemon/question_mark/circled/front.png"
        return mon_sym_to_png.get(mon_front_syms[idx], "graphics/pokemon/question_mark/circled/front.png")

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

    def resolve_int_token(value: object) -> Optional[int]:
        token = str(value).strip()
        if not token:
            return None
        if re.fullmatch(r"-?\d+", token):
            return int(token, 10)
        if re.fullmatch(r"0x[0-9a-fA-F]+", token):
            return int(token, 16)
        mapped = pokemon_define_ints.get(token)
        if mapped is not None:
            return int(mapped)
        return None

    def hidden_power_type_from_trainer_iv(iv_value: Optional[int]) -> str:
        # Matches CalcHiddenPowerTypeFromIVs in src/pokemon.c.
        if iv_value is None or iv_value >= use_random_ivs:
            return "TYPE_MYSTERY"

        hp_iv = iv_value
        attack_iv = iv_value
        defense_iv = iv_value
        speed_iv = iv_value
        sp_attack_iv = iv_value
        sp_defense_iv = iv_value

        type_bits = (hp_iv & 1)
        type_bits += (attack_iv & 1) * 2
        type_bits += (defense_iv & 1) * 4
        type_bits += (speed_iv & 1) * 8
        type_bits += (sp_attack_iv & 1) * 16
        type_bits += (sp_defense_iv & 1) * 32

        hidden_power_type_id = ((number_of_mon_types - 3) * type_bits) // 63 + 1
        if hidden_power_type_id >= type_mystery_id:
            hidden_power_type_id += 1

        return type_token_by_id.get(hidden_power_type_id, "TYPE_MYSTERY")

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
            trainer_key == "TRAINER_BLACK_BELT_KOICHI"
            or
            "LEADER" in token
            or "ELITE_FOUR" in token
            or "CHAMPION" in token
            or "RIVAL" in token
            or "BOSS" in token
            or trainer_key.startswith("TRAINER_LEADER_")
            or trainer_key.startswith("TRAINER_ELITE_FOUR_")
            or trainer_key.startswith("TRAINER_CHAMPION_")
            or trainer_key.startswith("TRAINER_RIVAL_")
            or trainer_key.startswith("TRAINER_BOSS_")
        )

    def resolve_trainer_theme(trainer_class_token: str, trainer_id: str) -> str:
        trainer_key = trainer_id.upper()
        if "GIOVANNI" in trainer_key:
            return "thug"

        token = trainer_class_token.upper()
        token_parts = set(token.split("_"))

        def has_any_part(*parts: str) -> bool:
            return any(part in token_parts for part in parts)

        if has_any_part("RIVAL", "CHAMPION"):
            return "rival"
        if has_any_part("YOUNGSTER", "LASS", "TWINS"):
            return "kid"
        if has_any_part("GENTLEMAN", "GAMER"):
            return "gentleman"
        if has_any_part("HIKER"):
            return "hiker"
        if has_any_part("BEAUTY", "LADY", "BREEDER", "PAINTER"):
            return "beauty"
        if has_any_part("BIKER", "NERD", "ENGINEER", "POKEMANIAC", "SCIENTIST"):
            return "maniac"
        if has_any_part("ROCKER"):
            return "rocker"
        if has_any_part("COUPLE"):
            return "couple"
        if has_any_part("COOLTRAINER"):
            return "cooltrainer"
        if has_any_part("BIRDKEEPER") or has_any_part("BIRD", "KEEPER"):
            return "birdkeeper"
        if has_any_part("SWIMMER", "TUBER", "TRIATHLETE", "FISHERMAN", "SAILOR") or (
            has_any_part("SIS") and has_any_part("BRO")
        ):
            return "swimmer"
        if has_any_part("PSYCHIC", "CHANNELER", "JUGGLER") or (
            has_any_part("HEX") and has_any_part("MANIAC")
        ):
            return "psychic"
        if has_any_part("PICNICKER", "CAMPER") or (
            has_any_part("AROMA") and has_any_part("LADY")
        ) or (
            has_any_part("RUIN") and has_any_part("MANIAC")
        ):
            return "camper"
        if has_any_part("ROCKET", "BURGLAR"):
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
        
        # Skip duplicate/redundant sections
        sections_to_skip = {
            "Digletts Cave",  # Duplicate of Diglett's Cave
        }
        if section in sections_to_skip:
            continue

        trainer_name = trainer["trainerName"].strip() or trainer_id.replace("TRAINER_", "").replace("_", " ").title()
        if trainer_id.startswith("TRAINER_RIVAL_") or trainer_name.upper() == "TERRY":
            trainer_name = "Rival"

        trainer_class_token = str(trainer["trainerClass"])

        trainer_obj: Dict[str, object] = {
            "id": trainer_id,
            "name": trainer_name,
            "class": trainer_class_names.get(trainer_class_token, pretty_token(trainer_class_token, "TRAINER_CLASS_")),
            "theme": resolve_trainer_theme(trainer_class_token, trainer_id),
            "isMajor": is_major_trainer(trainer_id, trainer_class_token),
            "sprite": trainer_pic_path(trainer["trainerPic"]),
            "partyMacro": trainer["partyMacro"],
            "isRematchCard": False,
            "rematchStage": 0,
            "rematchCheckpointText": "",
            "starterFilterScope": False,
            "playerStarterToken": "",
            "mons": [],
        }

        rematch_stage = int(rematch_stage_by_trainer.get(trainer_id, 0))
        if rematch_stage:
            checkpoint = REMATCH_CHECKPOINT_BY_STAGE.get(rematch_stage, "reaching the next VS Seeker checkpoint")
            trainer_obj["isRematchCard"] = True
            trainer_obj["rematchStage"] = rematch_stage
            trainer_obj["rematchCheckpointText"] = f"Rematch after {checkpoint}"

        # Rival teams encode the rival's starter in the party name.
        # Show the player's chosen starter instead.
        player_starter_token = None
        if is_starter_variant_trainer(trainer_id, trainer_name):
            player_starter_token = infer_player_starter_from_rival_party(str(trainer.get("partyName", "")))
        if player_starter_token:
            trainer_obj["starterFilterScope"] = True
            trainer_obj["playerStarterToken"] = player_starter_token
            trainer_obj["playerPickedName"] = species_names.get(
                player_starter_token,
                pretty_token(player_starter_token, "SPECIES_"),
            )
            trainer_obj["playerPickedSprite"] = species_front_path(player_starter_token)

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
                mon_obj["itemIconPath"] = str(item_icon_paths.get("icons", {}).get(icon_symbol, ""))
                if item_token == "ITEM_VS_SEEKER":
                    mon_obj["itemPalettePath"] = ""
                else:
                    palette_symbol = str(icon_entry.get("paletteSymbol", ""))
                    mon_obj["itemPalettePath"] = str(item_icon_paths.get("palettes", {}).get(palette_symbol, ""))

            for move_token in move_tokens:
                move_type = move_types.get(move_token, "")
                if move_token == "MOVE_HIDDEN_POWER":
                    hidden_power_type = hidden_power_type_from_trainer_iv(resolve_int_token(mon.get("iv", "")))
                    if hidden_power_type:
                        move_type = hidden_power_type
                mon_obj["moves"].append({
                    "token": move_token,
                    "name": move_names.get(move_token, pretty_token(move_token, "MOVE_")),
                    "type": move_type,
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
        if should_skip_encounter_section(section_name, known_section_names):
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

    def get_item_name(item_token: str) -> str:
        item_name = item_names.get(item_token, pretty_token(item_token, "ITEM_"))
        if item_name and set(item_name) == {"?"}:
            return "-"
        taught_move_name = tmhm_move_name_by_item_token.get(item_token)
        if taught_move_name:
            return f"{item_name} ({taught_move_name})"
        return item_name

    def get_item_icon_path(item_token: str) -> str:
        icon_entry = item_icon_table.get(item_token, {})
        icon_symbol = str(icon_entry.get("iconSymbol", ""))
        return str(item_icon_paths.get("icons", {}).get(icon_symbol, "graphics/items/icons/poke_ball.png"))

    def get_item_palette_path(item_token: str) -> str:
        if item_token == "ITEM_VS_SEEKER":
            return ""
        palette_entry = item_icon_table.get(item_token, {})
        palette_symbol = str(palette_entry.get("paletteSymbol", ""))
        return str(item_icon_paths.get("palettes", {}).get(palette_symbol, ""))

    def aggregate_item_entries(raw_items: List[Dict[str, object]]) -> List[Dict[str, object]]:
        grouped: Dict[tuple[str, bool], Dict[str, object]] = {}
        manual_index = 0
        for raw_item in raw_items:
            item_token = str(raw_item.get("itemToken", "")).strip()
            explicit_name = str(raw_item.get("itemName", "")).strip()
            explicit_icon_path = str(raw_item.get("iconPath", "")).strip()
            explicit_palette_path = str(raw_item.get("palettePath", "")).strip()

            if not item_token and not explicit_name:
                continue
            is_hidden = bool(raw_item.get("isHidden"))

            # Manual entries without an item token get a synthetic key and remain
            # independent rows in the rendered list.
            if item_token:
                key = (item_token, is_hidden)
            else:
                manual_index += 1
                key = (f"__MANUAL_{manual_index}__", is_hidden)

            entry = grouped.get(key)
            if not entry:
                resolved_name = explicit_name
                resolved_icon = explicit_icon_path
                resolved_palette = explicit_palette_path

                if item_token:
                    resolved_name = resolved_name or get_item_name(item_token)
                    resolved_icon = resolved_icon or get_item_icon_path(item_token)
                    resolved_palette = resolved_palette or get_item_palette_path(item_token)

                entry = {
                    "itemToken": item_token,
                    "itemName": resolved_name or "-",
                    "iconPath": resolved_icon or ("graphics/items/icons/poke_ball.png" if item_token else ""),
                    "palettePath": resolved_palette,
                    "count": 0,
                    "isHidden": is_hidden,
                }
                grouped[key] = entry
            increment = raw_item.get("count")
            if increment is None:
                increment = raw_item.get("quantity", 1)
            entry["count"] = int(entry.get("count", 0)) + int(increment or 1)

        items = list(grouped.values())
        items.sort(key=lambda item: (bool(item.get("isHidden")), str(item.get("itemName", "")).lower(), str(item.get("itemToken", ""))))
        return items

    def aggregate_merged_item_entries(raw_items: List[Dict[str, object]]) -> List[Dict[str, object]]:
        grouped: Dict[tuple[str, bool], Dict[str, object]] = {}
        manual_index = 0
        for raw_item in raw_items:
            item_token = str(raw_item.get("itemToken", "")).strip()
            explicit_name = str(raw_item.get("itemName", "")).strip()
            explicit_icon_path = str(raw_item.get("iconPath", "")).strip()
            explicit_palette_path = str(raw_item.get("palettePath", "")).strip()

            if not item_token and not explicit_name:
                continue
            is_hidden = bool(raw_item.get("isHidden"))

            if item_token:
                key = (item_token, is_hidden)
            else:
                manual_index += 1
                key = (f"__MANUAL_{manual_index}__", is_hidden)

            entry = grouped.get(key)
            if not entry:
                resolved_name = explicit_name
                resolved_icon = explicit_icon_path
                resolved_palette = explicit_palette_path

                if item_token:
                    resolved_name = resolved_name or get_item_name(item_token)
                    resolved_icon = resolved_icon or get_item_icon_path(item_token)
                    resolved_palette = resolved_palette or get_item_palette_path(item_token)

                entry = {
                    "itemToken": item_token,
                    "itemName": resolved_name or "-",
                    "iconPath": resolved_icon or ("graphics/items/icons/poke_ball.png" if item_token else ""),
                    "palettePath": resolved_palette,
                    "count": 0,
                    "isHidden": is_hidden,
                }
                grouped[key] = entry

            increment = raw_item.get("count")
            if increment is None:
                increment = raw_item.get("quantity", 1)
            increment_int = int(increment or 1)
            if item_token:
                entry["count"] = max(int(entry.get("count", 0)), increment_int)
            else:
                entry["count"] = int(entry.get("count", 0)) + increment_int

        items = list(grouped.values())
        items.sort(key=lambda item: (bool(item.get("isHidden")), str(item.get("itemName", "")).lower(), str(item.get("itemToken", ""))))
        return items

    def collect_items_for_map_token(map_token: str) -> List[Dict[str, object]]:
        normalized_map_token = normalize_map_token(map_token)
        section_items: List[Dict[str, object]] = list(map_items_by_token.get(map_token, []))
        section_items.extend(npc_gift_items_by_section_token.get(normalized_map_token, []))
        return section_items

    def collect_section_items(section_name: str) -> List[Dict[str, object]]:
        map_record = resolve_section_map_record(section_name)
        section_items: List[Dict[str, object]] = []

        if map_record:
            map_token = str(map_record.get("mapToken", ""))
            if map_token:
                section_items.extend(collect_items_for_map_token(map_token))

        sect_cfg = section_overrides.get(section_name, {})
        if isinstance(sect_cfg, dict):
            extra_map_tokens = sect_cfg.get("itemMapTokens")
            if isinstance(extra_map_tokens, (list, tuple)):
                for extra_token in extra_map_tokens:
                    token = str(extra_token).strip()
                    if not token:
                        continue
                    section_items.extend(collect_items_for_map_token(token))

            manual_items = sect_cfg.get("manualItems")
            if isinstance(manual_items, (list, tuple)):
                for manual_item in manual_items:
                    if not isinstance(manual_item, dict):
                        continue
                    token = str(manual_item.get("itemToken", "")).strip()
                    name = str(manual_item.get("itemName", "")).strip()
                    icon_path = str(manual_item.get("iconPath", "")).strip()
                    palette_path = str(manual_item.get("palettePath", "")).strip()
                    quantity = manual_item.get("quantity", 1)
                    is_hidden = bool(manual_item.get("isHidden", False))
                    try:
                        quantity_int = int(quantity)
                    except (TypeError, ValueError):
                        quantity_int = 1
                    if quantity_int <= 0:
                        quantity_int = 1

                    if not token and not name:
                        continue

                    section_items.append(
                        {
                            "itemToken": token,
                            "itemName": name,
                            "iconPath": icon_path,
                            "palettePath": palette_path,
                            "quantity": quantity_int,
                            "isHidden": is_hidden,
                        }
                    )

        return aggregate_item_entries(section_items)

    def section_map_token(section_name: str) -> str:
        record = resolve_section_map_record(section_name)
        if not record:
            return ""
        token = str(record.get("mapToken", ""))
        return normalize_map_token(token) if token else ""

    def shop_section_token_for_map_token(map_token: str) -> str:
        token = normalize_map_token(map_token)
        if token.endswith("_MART"):
            return token[: -len("_MART")]
        if "_DEPARTMENT_STORE_" in token:
            return token.split("_DEPARTMENT_STORE_", 1)[0]
        if "_GAME_CORNER_" in token:
            return token.split("_GAME_CORNER_", 1)[0]
        if token.startswith("INDIGO_PLATEAU_"):
            return "INDIGO_PLATEAU"
        return token
    def collect_section_shops(section_name: str) -> List[Dict[str, object]]:
        def _shop_variant_sort_key(variant_label: str) -> tuple[int, str]:
            token = variant_label.strip().lower()
            if not token:
                return (0, "")
            if token == "initial":
                return (1, token)
            expanded_match = re.fullmatch(r"expanded\s+(\d+)", token)
            if expanded_match:
                return (2 + int(expanded_match.group(1)), token)
            return (100, token)

        token = section_map_token(section_name)
        rows: List[Dict[str, object]] = []
        if token:
            rows.extend(shops_by_section_token.get(shop_section_token_for_map_token(token), []))

        sect_cfg = section_overrides.get(section_name, {})
        if isinstance(sect_cfg, dict):
            manual_shops = sect_cfg.get("manualShops")
            if isinstance(manual_shops, (list, tuple)):
                for manual_shop in manual_shops:
                    if not isinstance(manual_shop, dict):
                        continue

                    location_label = str(manual_shop.get("locationLabel", "")).strip() or section_name
                    shop_label = str(manual_shop.get("shopLabel", "Shop")).strip() or "Shop"
                    variant_label = str(manual_shop.get("variantLabel", "")).strip()
                    currency = str(manual_shop.get("currency", "money")).strip() or "money"
                    theme = str(manual_shop.get("theme", "")).strip()

                    offers: List[Dict[str, object]] = []
                    raw_offers = manual_shop.get("offers")
                    if isinstance(raw_offers, (list, tuple)):
                        for offer in raw_offers:
                            if not isinstance(offer, dict):
                                continue
                            name = str(offer.get("name", "")).strip()
                            if not name:
                                continue
                            try:
                                cost = int(offer.get("cost", 0) or 0)
                            except (TypeError, ValueError):
                                cost = 0
                            offers.append(
                                {
                                    "offerType": str(offer.get("offerType", "service")).strip() or "service",
                                    "token": str(offer.get("token", "")).strip(),
                                    "name": name,
                                    "cost": max(0, cost),
                                    "currency": str(offer.get("currency", currency)).strip() or currency,
                                    "costLabel": str(offer.get("costLabel", "")).strip(),
                                }
                            )

                    if not offers:
                        continue

                    rows.append(
                        {
                            "locationLabel": location_label,
                            "shopLabel": shop_label,
                            "variantLabel": variant_label,
                            "currency": currency,
                            "theme": theme,
                            "offers": offers,
                        }
                    )

        rows.sort(
            key=lambda entry: (
                str(entry.get("locationLabel", "")).lower(),
                str(entry.get("shopLabel", "")).lower(),
                _shop_variant_sort_key(str(entry.get("variantLabel", ""))),
            )
        )
        return rows

    def collect_section_move_tutors(section_name: str) -> List[Dict[str, object]]:
        token = section_map_token(section_name)
        if not token:
            return []
        rows = list(tutors_by_section_token.get(token, []))

        prefix = f"{token}_"
        for source_token, source_rows in tutors_by_section_token.items():
            if not source_token.startswith(prefix):
                continue
            rows.extend(source_rows)

        normalized_rows: List[Dict[str, object]] = []
        seen: set[tuple[str, str, str, int]] = set()
        for row in rows:
            payment_token = str(row.get("paymentItemToken", "")).strip()
            payment_count = int(row.get("paymentCount", 1) or 1)
            dedupe = (
                str(row.get("locationLabel", "")).strip().lower(),
                str(row.get("moveName", "")).strip().lower(),
                payment_token,
                payment_count,
                str(row.get("npcGfxToken", "")).strip(),
            )
            if dedupe in seen:
                continue
            seen.add(dedupe)

            normalized = dict(row)
            if payment_token and payment_token != "ITEM_NONE":
                normalized["paymentIconPath"] = get_item_icon_path(payment_token)
                normalized["paymentPalettePath"] = get_item_palette_path(payment_token)

            payment_options = normalized.get("paymentOptions")
            if isinstance(payment_options, list):
                normalized_options: List[Dict[str, object]] = []
                for option in payment_options:
                    if not isinstance(option, dict):
                        continue
                    option_token = str(option.get("itemToken", "")).strip()
                    if not option_token:
                        continue
                    normalized_option = dict(option)
                    normalized_option["iconPath"] = get_item_icon_path(option_token)
                    normalized_option["palettePath"] = get_item_palette_path(option_token)
                    normalized_options.append(normalized_option)
                normalized["paymentOptions"] = normalized_options

            normalized_rows.append(normalized)

        rows = normalized_rows
        rows.sort(
            key=lambda entry: (
                str(entry.get("locationLabel", "")).lower(),
                str(entry.get("moveName", "")).lower(),
            )
        )
        return rows

    def collect_section_trade_gifts(section_name: str) -> List[Dict[str, object]]:
        token = section_map_token(section_name)
        if not token:
            return []

        rows = list(trade_gifts_by_section_token.get(token, []))

        sect_cfg = section_overrides.get(section_name, {})
        if isinstance(sect_cfg, dict):
            extra_map_tokens = sect_cfg.get("tradeGiftMapTokens")
            if isinstance(extra_map_tokens, (list, tuple)):
                for extra_token in extra_map_tokens:
                    normalized_extra = normalize_map_token(str(extra_token).strip())
                    if normalized_extra:
                        rows.extend(trade_gifts_by_section_token.get(normalized_extra, []))

        normalized_rows: List[Dict[str, object]] = []
        seen: set[tuple[str, str, str, int, str]] = set()
        for row in rows:
            received_species_token = str(row.get("receivedSpeciesToken", "")).strip()
            requested_species_token = str(row.get("requestedSpeciesToken", "")).strip()
            method = str(row.get("method", "")).strip().lower()
            cost = int(row.get("cost", 0) or 0)

            if not received_species_token:
                continue

            dedupe = (
                method,
                received_species_token,
                requested_species_token,
                cost,
                str(row.get("npcGfxToken", "")).strip(),
            )
            if dedupe in seen:
                continue
            seen.add(dedupe)

            normalized = dict(row)
            normalized["receivedSpeciesName"] = species_names.get(
                received_species_token,
                pretty_token(received_species_token, "SPECIES_"),
            )
            normalized["receivedSpritePath"] = species_front_path(received_species_token)

            if requested_species_token:
                normalized["requestedSpeciesName"] = species_names.get(
                    requested_species_token,
                    pretty_token(requested_species_token, "SPECIES_"),
                )
                normalized["requestedSpritePath"] = species_front_path(requested_species_token)
            else:
                normalized["requestedSpeciesName"] = ""
                normalized["requestedSpritePath"] = ""

            normalized_rows.append(normalized)

        starter_species_order = [
            "SPECIES_BULBASAUR",
            "SPECIES_CHARMANDER",
            "SPECIES_SQUIRTLE",
        ]
        starter_species_set = set(starter_species_order)
        starter_rows = [
            row
            for row in normalized_rows
            if str(row.get("method", "")).strip().lower() == "gift"
            and str(row.get("npcGfxToken", "")).strip() == "OBJ_EVENT_GFX_PROF_OAK"
            and not str(row.get("requestedSpeciesToken", "")).strip()
            and str(row.get("receivedSpeciesToken", "")).strip() in starter_species_set
        ]
        starter_token_set = {
            str(row.get("receivedSpeciesToken", "")).strip() for row in starter_rows
        }
        if starter_token_set == starter_species_set:
            starter_row_by_token = {
                str(row.get("receivedSpeciesToken", "")).strip(): row for row in starter_rows
            }
            combined_starter_row = dict(starter_rows[0])
            combined_starter_row["receivedOptions"] = [
                {
                    "speciesToken": token,
                    "speciesName": str(starter_row_by_token[token].get("receivedSpeciesName", "")).strip(),
                    "spritePath": str(starter_row_by_token[token].get("receivedSpritePath", "")).strip(),
                }
                for token in starter_species_order
                if token in starter_row_by_token
            ]
            combined_starter_row["receivedSpeciesName"] = " or ".join(
                option["speciesName"]
                for option in combined_starter_row["receivedOptions"]
                if str(option.get("speciesName", "")).strip()
            )
            normalized_rows = [row for row in normalized_rows if row not in starter_rows]
            normalized_rows.append(combined_starter_row)

        method_order = {"gift": 0, "sale": 1, "trade": 2}
        normalized_rows.sort(
            key=lambda entry: (
                method_order.get(str(entry.get("method", "")).lower(), 99),
                str(entry.get("receivedSpeciesName", "")).lower(),
            )
        )
        return normalized_rows

    def section_hidden_trade_gifts(section_name: str) -> tuple[bool, set[int]]:
        sect_cfg = section_overrides.get(section_name, {})
        if not isinstance(sect_cfg, dict):
            return False, set()
        raw = sect_cfg.get("hideTradeGifts")
        if raw is True:
            return True, set()
        if isinstance(raw, (list, tuple)):
            indices: set[int] = set()
            for item in raw:
                if isinstance(item, bool):
                    continue
                try:
                    index = int(item)
                except (TypeError, ValueError):
                    continue
                if index >= 0:
                    indices.add(index)
            return False, indices
        return False, set()

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

    def section_hidden_items(section_name: str) -> tuple[bool, set[int]]:
        sect_cfg = section_overrides.get(section_name, {})
        if not isinstance(sect_cfg, dict):
            return False, set()
        raw = sect_cfg.get("hideItems")
        if raw is True:
            return True, set()
        if isinstance(raw, (list, tuple)):
            indices: set[int] = set()
            for item in raw:
                if isinstance(item, bool):
                    continue
                try:
                    index = int(item)
                except (TypeError, ValueError):
                    continue
                if index >= 0:
                    indices.add(index)
            return False, indices
        return False, set()

    def section_hidden_move_tutors(section_name: str) -> tuple[bool, set[int]]:
        sect_cfg = section_overrides.get(section_name, {})
        if not isinstance(sect_cfg, dict):
            return False, set()
        raw = sect_cfg.get("hideMoveTutors")
        if raw is True:
            return True, set()
        if isinstance(raw, (list, tuple)):
            indices: set[int] = set()
            for item in raw:
                if isinstance(item, bool):
                    continue
                try:
                    index = int(item)
                except (TypeError, ValueError):
                    continue
                if index >= 0:
                    indices.add(index)
            return False, indices
        return False, set()

    def apply_hidden_items(items: List[Dict[str, object]], hide_all: bool, hidden_indices: set[int]) -> List[Dict[str, object]]:
        if hide_all:
            return []
        if not items or not hidden_indices:
            return items
        return [item for idx, item in enumerate(items) if idx not in hidden_indices]

    def apply_hidden_move_tutors(move_tutors: List[Dict[str, object]], hide_all: bool, hidden_indices: set[int]) -> List[Dict[str, object]]:
        if hide_all:
            return []
        if not move_tutors or not hidden_indices:
            return move_tutors
        return [tutor for idx, tutor in enumerate(move_tutors) if idx not in hidden_indices]

    def apply_hidden_trade_gifts(trade_gifts: List[Dict[str, object]], hide_all: bool, hidden_indices: set[int]) -> List[Dict[str, object]]:
        if hide_all:
            return []
        if not trade_gifts or not hidden_indices:
            return trade_gifts
        return [trade for idx, trade in enumerate(trade_gifts) if idx not in hidden_indices]

    section_items_by_name: Dict[str, List[Dict[str, object]]] = {}
    section_shops_by_name: Dict[str, List[Dict[str, object]]] = {}
    section_trade_gifts_by_name: Dict[str, List[Dict[str, object]]] = {}
    section_tutors_by_name: Dict[str, List[Dict[str, object]]] = {}
    for name in ordered_section_names:
        hide_all_items, hidden_item_indices = section_hidden_items(name)
        hide_all_trade_gifts, hidden_trade_gift_indices = section_hidden_trade_gifts(name)
        hide_all_tutors, hidden_tutor_indices = section_hidden_move_tutors(name)
        if name in merge_overrides:
            merge_cfg = merge_overrides.get(name, {})
            if isinstance(merge_cfg, dict):
                combined_items: List[Dict[str, object]] = []
                combined_shops: List[Dict[str, object]] = []
                combined_trade_gifts: List[Dict[str, object]] = []
                combined_tutors: List[Dict[str, object]] = []
                for source in [str(s) for s in merge_cfg.get("sources", [])]:
                    combined_items.extend(collect_section_items(source))
                    combined_shops.extend(collect_section_shops(source))
                    combined_trade_gifts.extend(collect_section_trade_gifts(source))
                    combined_tutors.extend(collect_section_move_tutors(source))
                manual_items = merge_cfg.get("manualItems")
                if isinstance(manual_items, (list, tuple)):
                    for manual_item in manual_items:
                        if isinstance(manual_item, dict):
                            combined_items.append(dict(manual_item))
                section_items_by_name[name] = apply_hidden_items(
                    aggregate_merged_item_entries(combined_items),
                    hide_all_items,
                    hidden_item_indices,
                )
                section_shops_by_name[name] = combined_shops
                section_trade_gifts_by_name[name] = apply_hidden_trade_gifts(
                    combined_trade_gifts,
                    hide_all_trade_gifts,
                    hidden_trade_gift_indices,
                )
                section_tutors_by_name[name] = apply_hidden_move_tutors(
                    combined_tutors,
                    hide_all_tutors,
                    hidden_tutor_indices,
                )
                continue
        section_items_by_name[name] = apply_hidden_items(
            collect_section_items(name),
            hide_all_items,
            hidden_item_indices,
        )
        section_shops_by_name[name] = collect_section_shops(name)
        section_trade_gifts_by_name[name] = apply_hidden_trade_gifts(
            collect_section_trade_gifts(name),
            hide_all_trade_gifts,
            hidden_trade_gift_indices,
        )
        section_tutors_by_name[name] = apply_hidden_move_tutors(
            collect_section_move_tutors(name),
            hide_all_tutors,
            hidden_tutor_indices,
        )

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
    
    def section_stretched_height(section_name: str) -> Optional[float]:
        sect_cfg = section_overrides.get(section_name, {})
        if not isinstance(sect_cfg, dict):
            return None
        raw = sect_cfg.get("stretchedHeight")
        if raw is None:
            return None
        if isinstance(raw, bool):
            return 2.0 if raw else None
        try:
            value = float(raw)
        except (TypeError, ValueError):
            return None
        if value <= 0:
            return None
        return value

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
                "stretchedHeight": section_stretched_height(name),
                "encounters": get_section_encounters(name, section_hidden_encounter_kinds(name)),
                "items": section_items_by_name.get(name, []),
                "shops": section_shops_by_name.get(name, []),
                "tradeGifts": section_trade_gifts_by_name.get(name, []),
                "moveTutors": section_tutors_by_name.get(name, []),
                "trainers": sections[name],
                "trainerGroups": trainer_groups.get(name, []),
            }
            for name in ordered_section_names
            if name in sections and (not section_filter or section_filter.lower() == name.lower())
        ],
        "typeIcons": type_icon_specs,
    }
