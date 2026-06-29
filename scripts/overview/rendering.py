from __future__ import annotations

import base64
import html
import importlib
import json
import mimetypes
import os
import re
from pathlib import Path
from typing import Dict, List, Set

from .parsing import (
    parse_initial_movement_facing_directions,
    parse_map_object_events,
    parse_object_event_gfx_to_info_symbol,
    parse_object_event_graphics_info_tables,
    parse_object_event_pic_symbol_to_png_path,
    parse_object_event_pic_tables,
)


# Animation-frame index (into a pic table) used to render each facing
# direction, plus whether the frame is horizontally flipped. Mirrors the
# standard object-event anim tables: south=0, north=1, west=2, east=2 flipped.
FACE_DIRECTION_FRAME = {
    "DIR_NONE": (0, False),
    "DIR_SOUTH": (0, False),
    "DIR_NORTH": (1, False),
    "DIR_WEST": (2, False),
    "DIR_EAST": (2, True),
}


ROOT = Path(__file__).resolve().parents[2]
OVERVIEW_SOURCE_DIR = Path(__file__).resolve().parent


class AssetResolver:
    def __init__(self, output_dir: Path, embed_assets: bool) -> None:
        self.output_dir = output_dir
        self.embed_assets = embed_assets
        self._cache: Dict[str, str] = {}
        self._embedded_paths: Set[str] = set()
        self._missing_assets: Set[str] = set()
        self._embedded_bytes = 0

    def resolve(self, rel_path: str) -> str:
        normalized = rel_path.replace("\\", "/").strip()
        if not normalized:
            return ""

        cached = self._cache.get(normalized)
        if cached is not None:
            return cached

        if self.embed_assets:
            resolved = self._data_url_for(normalized)
        else:
            resolved = os.path.relpath(ROOT / normalized, self.output_dir).replace("\\", "/")

        self._cache[normalized] = resolved
        return resolved

    def _data_url_for(self, rel_path: str) -> str:
        raw_path = ROOT / rel_path
        actual_path = raw_path
        if not raw_path.is_file():
            fallback_rel = self._fallback_for(rel_path)
            if not fallback_rel:
                raise FileNotFoundError(f"Missing asset: {rel_path}")
            fallback_path = ROOT / fallback_rel
            if not fallback_path.is_file():
                raise FileNotFoundError(
                    f"Missing asset and fallback: {rel_path} -> {fallback_rel}"
                )
            self._missing_assets.add(rel_path)
            actual_path = fallback_path

        raw = actual_path.read_bytes()
        mime_type, _ = mimetypes.guess_type(rel_path)
        if not mime_type:
            mime_type = "application/octet-stream"
        payload = base64.b64encode(raw).decode("ascii")
        self._embedded_paths.add(rel_path)
        self._embedded_bytes += len(raw)
        return f"data:{mime_type};base64,{payload}"

    def _fallback_for(self, rel_path: str) -> str:
        if rel_path.startswith("graphics/pokemon/"):
            return "graphics/pokemon/question_mark/circled/front.png"
        if rel_path.startswith("graphics/trainers/"):
            return "graphics/trainers/front_pics/youngster_front_pic.png"
        if rel_path.startswith("graphics/items/icons/"):
            return "graphics/items/icons/poke_ball.png"
        if rel_path.startswith("graphics/interface/"):
            return "graphics/interface/menu_info.png"
        return ""

    def stats(self) -> Dict[str, int]:
        return {
            "uniqueEmbeddedAssets": len(self._embedded_paths),
            "embeddedBytes": self._embedded_bytes,
            "missingAssets": len(self._missing_assets),
        }


def _find_external_asset_refs(html_text: str) -> List[str]:
    refs: Set[str] = set()

    attr_pattern = re.compile(r"(?:src|href)=['\"]([^'\"]+)['\"]")
    css_pattern = re.compile(r"url\((['\"]?)([^)'\"]+)\1\)")
    graphics_pattern = re.compile(r"(?:\.\./)?graphics/[A-Za-z0-9_./-]+")

    for match in attr_pattern.finditer(html_text):
        raw = match.group(1).strip()
        if not raw or raw.startswith(("data:", "http://", "https://", "#", "javascript:")):
            continue
        refs.add(raw)

    for match in css_pattern.finditer(html_text):
        raw = match.group(2).strip()
        if not raw or raw.startswith(("data:", "http://", "https://", "#")):
            continue
        refs.add(raw)

    for match in graphics_pattern.finditer(html_text):
        refs.add(match.group(0))

    return sorted(refs)


def read_overview_source(*parts: str) -> str:
    return OVERVIEW_SOURCE_DIR.joinpath(*parts).read_text(encoding="utf-8")


def render_template(content: str, replacements: Dict[str, str]) -> str:
    for key, value in replacements.items():
        content = content.replace(key, value)
    return content


def render_type_icon_css(type_icons: Dict[str, Dict[str, int]]) -> str:
    lines = []
    for type_token, spec in sorted(type_icons.items()):
        lines.append(
            f".type-{type_token} {{ width:{spec['w']}px; height:{spec['h']}px; background-position:-{spec['x']}px -{spec['y']}px; }}"
        )
    return "\n".join(lines)


def render_type_icons_html(type_tokens: List[str], type_icons: Dict[str, Dict[str, int]]) -> str:
    icons = []
    for type_token in type_tokens:
        if type_token in type_icons:
            icons.append(f"<span class='type-icon type-{type_token}' title='{html.escape(type_token)}'></span>")
    return "".join(icons)


def render_move_rows(moves: List[Dict[str, object]], type_icons: Dict[str, Dict[str, int]], templates: Dict[str, str]) -> str:
    if not moves:
        return "<div class='move-row'><span>-</span></div>"

    move_row_template = templates["move_row"]
    rows = []
    for move in moves:
        move_name = html.escape(str(move["name"]))
        move_type = str(move.get("type", ""))
        move_type_icon = ""
        if move_type in type_icons:
            move_type_icon = f"<span class='type-icon type-{move_type}' title='{html.escape(move_type)}'></span>"
        rows.append(render_template(move_row_template, {"__MOVE_NAME__": move_name, "__MOVE_TYPE_ICON__": move_type_icon}))
    return "".join(rows)


def render_mon_card(mon: Dict[str, object], type_icons: Dict[str, Dict[str, int]], asset_url, templates: Dict[str, str]) -> str:
    nature_effect = str(mon.get("natureEffect", ""))
    item_name = str(mon.get("itemName", "-"))
    item_icon_html = ""
    item_icon_path = str(mon.get("itemIconPath", ""))
    if item_name != "-" and item_icon_path:
        item_icon_html = (
            f"<img class='item-icon' src='{html.escape(asset_url(item_icon_path))}' "
            f"alt='{html.escape(item_name)}' title='{html.escape(item_name)}'>"
        )

    return render_template(
        templates["mon_card"],
        {
            "__MON_SPRITE__": html.escape(asset_url(str(mon["sprite"]))),
            "__MON_NAME__": html.escape(str(mon["speciesName"])),
            "__LEVEL__": html.escape(str(mon["level"])),
            "__TYPE_ICONS__": render_type_icons_html(mon["types"], type_icons),
            "__NATURE__": html.escape(str(mon["nature"])),
            "__NATURE_EFFECT__": html.escape(nature_effect),
            "__ABILITY__": html.escape(str(mon["ability"])),
            "__ITEM_NAME__": html.escape(item_name),
            "__ITEM_ICON_HTML__": item_icon_html,
            "__MOVES_HTML__": render_move_rows(mon["moves"], type_icons, templates),
        },
    )


def render_trainer_card(trainer: Dict[str, object], type_icons: Dict[str, Dict[str, int]], asset_url, templates: Dict[str, str]) -> str:
    mons_html = "".join(render_mon_card(mon, type_icons, asset_url, templates) for mon in trainer["mons"])
    trainer_card_class = "trainer-card--major" if trainer.get("isMajor") else "trainer-card--compact"
    trainer_theme = str(trainer.get("theme", "default")).strip().lower()
    if trainer_theme and trainer_theme != "default":
        trainer_card_class = f"{trainer_card_class} trainer-theme-{trainer_theme}"
    return render_template(
        templates["trainer_card"],
        {
            "__TRAINER_CARD_CLASS__": trainer_card_class,
            "__TRAINER_SPRITE__": html.escape(asset_url(str(trainer["sprite"]))),
            "__TRAINER_NAME__": html.escape(str(trainer["name"])),
            "__TRAINER_CLASS__": html.escape(str(trainer["class"])),
            "__MONS_HTML__": mons_html,
        },
    )


def render_encounter_panel(panel: Dict[str, object], asset_url, templates: Dict[str, str]) -> str:
    kind = str(panel.get("kind", ""))
    is_non_land = kind != "land_mons"
    panel_class = {
        "land_mons": "enc-panel--land",
        "rock_smash_mons": "enc-panel--rock-smash",
        "water_mons": "enc-panel--surf",
        "fishing_mons": "enc-panel--fishing",
    }.get(kind, "enc-panel--default")

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

    def render_slot_row(slot: Dict[str, object], slot_row_index: int) -> str:
        rarity = int(slot.get("rarity", 0))
        row_stripe_class = "enc-slot-even" if (slot_row_index + 1) % 2 == 0 else "enc-slot-odd"
        return render_template(
            templates["encounter_slot_row"],
            {
                "__ROW_STRIPE_CLASS__": row_stripe_class,
                "__RARITY_CLASS__": get_rarity_class(rarity),
                "__RARITY__": html.escape(f"{rarity}%"),
                "__SPRITE_URL__": html.escape(asset_url(str(slot["sprite"]))),
                "__SPECIES_NAME__": html.escape(str(slot["speciesName"])),
                "__LEVEL__": html.escape(str(slot["level"])),
            },
        )

    row_chunks = []
    slot_row_index = 0
    rod_groups = panel.get("rodGroups")
    if rod_groups:
        for group in rod_groups:
            row_chunks.append(render_template(templates["rod_header_row"], {"__ICON_URL__": html.escape(asset_url(str(group.get("icon", "")))), "__GROUP_LABEL__": html.escape(str(group.get("label", "")))}))
            for slot in group.get("slots", []):
                row_chunks.append(render_slot_row(slot, slot_row_index))
                slot_row_index += 1
    else:
        for slot in panel.get("slots", []):
            row_chunks.append(render_slot_row(slot, slot_row_index))
            slot_row_index += 1

    return render_template(
        templates["encounter_panel"],
        {
            "__PANEL_CLASS__": panel_class,
            "__PANEL_TITLE__": html.escape(str(panel.get("title", "Encounter"))),
            "__PANEL_ROWS__": "".join(row_chunks),
        },
    )


def render_encounters(encounters: Dict[str, object], asset_url, templates: Dict[str, str]) -> str:
    chunks = ["<aside class='encounters'>", "<div class='enc-family-head'>Wild Encounters</div>"]
    if encounters.get("mode") == "dual":
        chunks.append("<div class='enc-columns'><div class='enc-col'>")
        for panel in encounters.get("leftPanels", []):
            chunks.append(render_encounter_panel(panel, asset_url, templates))
        chunks.append("</div><div class='enc-col'>")
        for panel in encounters.get("rightPanels", []):
            chunks.append(render_encounter_panel(panel, asset_url, templates))
        chunks.append("</div></div>")
    else:
        for panel in encounters.get("singlePanels", []):
            chunks.append(render_encounter_panel(panel, asset_url, templates))
    chunks.append("</aside>")
    return "".join(chunks)


def render_trainer_cards(
    section: Dict[str, object],
    type_icons: Dict[str, Dict[str, int]],
    asset_url,
    templates: Dict[str, str],
) -> str:
    groups = section.get("trainerGroups")
    if groups:
        chunks: List[str] = []
        for group in groups:
            if not isinstance(group, dict):
                continue
            label = html.escape(str(group.get("label", "")))
            trainers = group.get("trainers", [])
            if not trainers:
                continue
            chunks.append(f"<div class='trainer-group-head'>{label}</div>")
            chunks.extend(render_trainer_card(trainer, type_icons, asset_url, templates) for trainer in trainers)
        if chunks:
            return "".join(chunks)

    return "".join(render_trainer_card(trainer, type_icons, asset_url, templates) for trainer in section["trainers"])


def render_section(section: Dict[str, object], type_icons: Dict[str, Dict[str, int]], asset_url, templates: Dict[str, str]) -> str:
    encounters = section.get("encounters")
    trainer_cards_html = render_trainer_cards(section, type_icons, asset_url, templates)
    trainer_section_html = ""
    if trainer_cards_html.strip():
        trainer_section_html = f"<div class='cards'>{trainer_cards_html}</div>"

    pane_mode = "map-only"
    if encounters and encounters.get("mode") == "dual":
        pane_mode = "dual"
    elif encounters and encounters.get("mode") == "single":
        pane_mode = "single"

    map_scale_max = section.get("mapSacleMax")
    map_scale_max_attr = ""
    if map_scale_max is not None:
        map_scale_max_attr = f" data-map-scale-max='{html.escape(str(map_scale_max))}'"

    full_height_attr = ""
    if section.get("fullHeight"):
        full_height_attr = " data-map-full-height='true'"

    return render_template(
        templates["section"],
        {
            "__SECTION_THEME__": html.escape(str(section.get("theme", "default"))),
            "__SECTION_NAME__": html.escape(str(section["name"])),
            "__TRAINER_COUNT__": str(len(section["trainers"])),
            "__PANE_MODE__": pane_mode,
            "__MAP_IMAGE__": "",
            "__MAP_KEY__": html.escape(str(section["slug"])),
            "__MAP_SCALE_MAX_ATTR__": map_scale_max_attr,
            "__MAP_FULL_HEIGHT_ATTR__": full_height_attr,
            "__ENCOUNTERS_HTML__": render_encounters(encounters, asset_url, templates) if encounters else "",
            "__TRAINER_SECTION_HTML__": trainer_section_html,
        },
    )


def render_sections_html(sections: List[Dict[str, object]], type_icons: Dict[str, Dict[str, int]], asset_url, templates: Dict[str, str]) -> str:
    return "\n".join(render_section(section, type_icons, asset_url, templates) for section in sections)


def _read_base64(rel_path: str) -> str:
    raw = (ROOT / rel_path).read_bytes()
    return base64.b64encode(raw).decode("ascii")


def _palettes_from_indexed_png(rel_path: str) -> List[str]:
    pil_image = importlib.import_module("PIL.Image")

    with pil_image.open(ROOT / rel_path) as img:
        indexed = img.convert("P")
        palette = indexed.getpalette()
    if not palette:
        raise ValueError(f"PNG has no palette: {rel_path}")

    def rgb_at(color_index: int) -> tuple[int, int, int]:
        idx = color_index * 3
        if idx + 2 < len(palette):
            return palette[idx], palette[idx + 1], palette[idx +2]
        return 0, 0, 0
    
    num_colors = len(palette) // 3
    single_bank = num_colors <= 16

    out: List[str] = []
    for bank in range(16):
        lines = ["JASC-PAL", "0100", "16"]
        for color_idx in range(16):
            if single_bank:
                r, g, b = rgb_at(color_idx)
            else:
                r, g, b = rgb_at(bank * 16 + color_idx)
            lines.append(f"{r} {g} {b}")
        out.append(base64.b64encode(("\r\n".join(lines) + "\r\n").encode("ascii")).decode("ascii"))
    return out


def _read_tileset_palettes_base64(tiles_png_path: str) -> List[str]:
    palettes_dir = (ROOT / tiles_png_path).parent / "palettes"
    if palettes_dir.is_dir() and (palettes_dir / "00.pal").is_file():
        out: List[str] = []
        for idx in range(16):
            pal_path = palettes_dir / f"{idx:02d}.pal"
            out.append(base64.b64encode(pal_path.read_bytes()).decode("ascii"))
        return out

    return _palettes_from_indexed_png(tiles_png_path)


def _read_indexed_png_pixels_base64(rel_path: str) -> Dict[str, object]:
    pil_image = importlib.import_module("PIL.Image")

    with pil_image.open(ROOT / rel_path) as img:
        indexed = img.convert("P")
        width, height = indexed.size
        pixel_bytes = indexed.tobytes()
    return {
        "width": width,
        "height": height,
        "pixelsB64": base64.b64encode(pixel_bytes).decode("ascii"),
    }


def _build_map_object_overlay(map_render: Dict[str, object], asset_url) -> List[Dict[str, object]]:
    map_json_path = str(map_render.get("mapJsonPath", ""))
    if not map_json_path:
        return []

    gfx_to_info = parse_object_event_gfx_to_info_symbol()
    info_tables = parse_object_event_graphics_info_tables()
    pic_tables = parse_object_event_pic_tables()
    pic_paths = parse_object_event_pic_symbol_to_png_path()
    movement_facing = parse_initial_movement_facing_directions()

    objects: List[Dict[str, object]] = []
    for event in parse_map_object_events(map_json_path):
        gfx_token = str(event.get("graphicsId", ""))
        info_symbol = gfx_to_info.get(gfx_token)
        if not info_symbol:
            continue

        info = info_tables.get(info_symbol, {})
        pic_table_symbol = str(info.get("picTable", ""))
        frame_meta = pic_tables.get(pic_table_symbol, {})
        pic_symbol = str(frame_meta.get("picSymbol", ""))
        png_path = pic_paths.get(pic_symbol)
        if not png_path:
            continue

        frame_tiles_w = int(frame_meta.get("tilesW", 2))
        frame_tiles_h = int(frame_meta.get("tilesH", 2))
        frame_w = max(8, frame_tiles_w * 8)
        frame_h = max(8, frame_tiles_h * 8)

        source_frames = frame_meta.get("sourceFrames") or [int(frame_meta.get("frame", 0))]

        # Orient the sprite the way porymap does: derive the facing direction
        # from the event's movement type, then pick the matching anim frame.
        direction = movement_facing.get(str(event.get("movementType", "")), "DIR_SOUTH")
        anim_index, flip = FACE_DIRECTION_FRAME.get(direction, (0, False))
        if bool(info.get("inanimate")) or anim_index >= len(source_frames):
            anim_index, flip = 0, False

        source_frame = max(0, int(source_frames[anim_index]))

        draw_w = max(8, int(info.get("width", frame_w)))
        draw_h = max(8, int(info.get("height", frame_h)))

        objects.append(
            {
                "x": int(event.get("x", 0)),
                "y": int(event.get("y", 0)),
                "spriteUrl": asset_url(png_path),
                "frameX": source_frame * frame_w,
                "frameY": 0,
                "frameW": frame_w,
                "frameH": frame_h,
                "drawW": draw_w,
                "drawH": draw_h,
                "flip": flip,
            }
        )

    objects.sort(key=lambda obj: (int(obj.get("y", 0)), int(obj.get("x", 0))))
    return objects


def build_map_render_data(sections: List[Dict[str, object]], asset_url) -> Dict[str, Dict[str, object]]:
    payload: Dict[str, Dict[str, object]] = {}
    for section in sections:
        section_key = str(section.get("slug", ""))
        map_render = section.get("mapRender")
        if not section_key or not isinstance(map_render, dict):
            continue

        try:
            width = int(map_render.get("width", 0))
            height = int(map_render.get("height", 0))
            if width <= 0 or height <= 0:
                continue

            blockdata_path = str(map_render["blockdataPath"])
            primary = map_render["primary"]
            secondary = map_render["secondary"]

            payload[section_key] = {
                "mapName": str(map_render.get("mapName", "")),
                "mapId": str(map_render.get("mapId", "")),
                "width": width,
                "height": height,
                "blockdataB64": _read_base64(blockdata_path),
                "primaryMetatilesB64": _read_base64(str(primary["metatilesPath"])),
                "secondaryMetatilesB64": _read_base64(str(secondary["metatilesPath"])),
                "primaryTilesUrl": asset_url(str(primary["tilesPngPath"])),
                "secondaryTilesUrl": asset_url(str(secondary["tilesPngPath"])),
                "primaryPalettesB64": _read_tileset_palettes_base64(str(primary["tilesPngPath"])),
                "secondaryPalettesB64": _read_tileset_palettes_base64(str(secondary["tilesPngPath"])),
                "primaryTilePixels": _read_indexed_png_pixels_base64(str(primary["tilesPngPath"])),
                "secondaryTilePixels": _read_indexed_png_pixels_base64(str(secondary["tilesPngPath"])),
                "objects": _build_map_object_overlay(map_render, asset_url),
            }
            crop = map_render.get("crop")
            if isinstance(crop, dict):
                payload[section_key]["crop"] = crop
            map_scale_max = section.get("mapScaleMax")
            if map_scale_max is not None:
                payload[section_key]["mapScaleMax"] = map_scale_max
            if section.get("fullHeight"):
                payload[section_key]["fullHeight"] = True
        except (FileNotFoundError, KeyError, OSError, ValueError, TypeError):
            continue

    return payload


def render_html(model: Dict[str, object], out_path: Path, embed_assets: bool = True) -> Dict[str, int]:
    output_dir = out_path.parent
    asset_resolver = AssetResolver(output_dir=output_dir, embed_assets=embed_assets)

    def asset_url(rel_path: str) -> str:
        return asset_resolver.resolve(rel_path)

    templates = {
        "main_template": read_overview_source("templates", "main_template.html"),
        "section": read_overview_source("templates", "section.html"),
        "trainer_card": read_overview_source("templates", "trainer_card.html"),
        "mon_card": read_overview_source("templates", "mon_card.html"),
        "move_row": read_overview_source("templates", "move_row.html"),
        "encounter_panel": read_overview_source("templates", "encounter_panel.html"),
        "encounter_slot_row": read_overview_source("templates", "encounter_slot_row.html"),
        "rod_header_row": read_overview_source("templates", "rod_header_row.html"),
    }

    css = read_overview_source("static", "overview.css")
    css = css.replace("__TYPE_ICON_URL__", asset_url("graphics/interface/menu_info.png"))
    css = "\n".join((css, render_type_icon_css(model["typeIcons"])))
    map_render_data = build_map_render_data(model["sections"], asset_url)
    map_render_data_json = json.dumps(map_render_data, separators=(",", ":")).replace("</", "<\\/")
    map_render_script = read_overview_source("static", "overview_map_renderer.js")
    page_html = templates["main_template"]
    page_html = page_html.replace("__STYLE_BLOCK__", f"<style>\n{css}\n</style>")
    page_html = page_html.replace("__SECTIONS_HTML__", render_sections_html(model["sections"], model["typeIcons"], asset_url, templates))
    page_html = page_html.replace("__MAP_RENDER_DATA_BLOCK__", f"<script id='overview-map-data' type='application/json'>{map_render_data_json}</script>")
    page_html = page_html.replace("__SCRIPT_BLOCK__", f"<script>\n{map_render_script}\n</script>")

    if embed_assets:
        external_refs = _find_external_asset_refs(page_html)
        if external_refs:
            preview = ", ".join(external_refs[:8])
            if len(external_refs) > 8:
                preview += ", ..."
            raise RuntimeError(
                "Generated overview still contains external asset references: "
                f"{preview}"
            )

    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(page_html, encoding="utf-8")

    stats = asset_resolver.stats()
    stats["htmlBytes"] = len(page_html.encode("utf-8"))
    return stats
