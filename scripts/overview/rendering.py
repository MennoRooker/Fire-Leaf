from __future__ import annotations

import base64
import html
import importlib
import json
import os
from pathlib import Path
from typing import Dict, List


ROOT = Path(__file__).resolve().parents[2]
OVERVIEW_SOURCE_DIR = Path(__file__).resolve().parent


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
    return render_template(
        templates["mon_card"],
        {
            "__MON_SPRITE__": html.escape(asset_url(str(mon["sprite"]))),
            "__MON_NAME__": html.escape(str(mon["speciesName"])),
            "__LEVEL__": html.escape(str(mon["level"])),
            "__TYPE_ICONS__": render_type_icons_html(mon["types"], type_icons),
            "__NATURE__": html.escape(str(mon["nature"])),
            "__ABILITY__": html.escape(str(mon["ability"])),
            "__ITEM_NAME__": html.escape(str(mon["itemName"])),
            "__MOVES_HTML__": render_move_rows(mon["moves"], type_icons, templates),
        },
    )


def render_trainer_card(trainer: Dict[str, object], type_icons: Dict[str, Dict[str, int]], asset_url, templates: Dict[str, str]) -> str:
    mons_html = "".join(render_mon_card(mon, type_icons, asset_url, templates) for mon in trainer["mons"])
    return render_template(
        templates["trainer_card"],
        {
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

    def render_slot_row(slot: Dict[str, object]) -> str:
        rarity = int(slot.get("rarity", 0))
        return render_template(
            templates["encounter_slot_row"],
            {
                "__RARITY_CLASS__": get_rarity_class(rarity),
                "__RARITY__": html.escape(f"{rarity}%"),
                "__SPRITE_URL__": html.escape(asset_url(str(slot["sprite"]))),
                "__SPECIES_NAME__": html.escape(str(slot["speciesName"])),
                "__LEVEL__": html.escape(str(slot["level"])),
            },
        )

    row_chunks = []
    rod_groups = panel.get("rodGroups")
    if rod_groups:
        for group in rod_groups:
            row_chunks.append(render_template(templates["rod_header_row"], {"__ICON_URL__": html.escape(asset_url(str(group.get("icon", "")))), "__GROUP_LABEL__": html.escape(str(group.get("label", "")))}))
            for slot in group.get("slots", []):
                row_chunks.append(render_slot_row(slot))
    else:
        for slot in panel.get("slots", []):
            row_chunks.append(render_slot_row(slot))

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
    pane_mode = "map-only"
    if encounters and encounters.get("mode") == "dual":
        pane_mode = "dual"
    elif encounters and encounters.get("mode") == "single":
        pane_mode = "single"

    map_scale_max = section.get("mapSacleMax")
    map_scale_max_attr = ""
    if map_scale_max is not None:
        map_scale_max_attr = f" data-map-scale-max='{html.escape(str(map_scale_max))}'"

    return render_template(
        templates["section"],
        {
            "__SECTION_THEME__": html.escape(str(section.get("theme", "default"))),
            "__SECTION_NAME__": html.escape(str(section["name"])),
            "__TRAINER_COUNT__": str(len(section["trainers"])),
            "__PANE_MODE__": pane_mode,
            "__MAP_IMAGE__": html.escape(asset_url(str(section["mapImage"]))),
            "__MAP_KEY__": html.escape(str(section["slug"])),
            "__MAP_SCALE_MAX_ATTR__": map_scale_max_attr,
            "__ENCOUNTERS_HTML__": render_encounters(encounters, asset_url, templates) if encounters else "",
            "__TRAINER_CARDS_HTML__": render_trainer_cards(section, type_icons, asset_url, templates),
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


def _read_tileset_palettes_base64(metatiles_rel_path: str, tiles_png_path: str) -> List[str]:
    palettes_dir = (ROOT / metatiles_rel_path).parent / "palettes"
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
                "primaryPalettesB64": _read_tileset_palettes_base64(str(primary["metatilesPath"]), str(primary["tilesPngPath"])),
                "secondaryPalettesB64": _read_tileset_palettes_base64(str(secondary["metatilesPath"]), str(secondary["tilesPngPath"])),
                "primaryTilePixels": _read_indexed_png_pixels_base64(str(primary["tilesPngPath"])),
                "secondaryTilePixels": _read_indexed_png_pixels_base64(str(secondary["tilesPngPath"])),
            }
            crop = map_render.get("crop")
            if isinstance(crop, dict):
                payload[section_key]["crop"] = crop
        except (FileNotFoundError, KeyError, OSError, ValueError, TypeError):
            continue

    return payload


def render_html(model: Dict[str, object], out_path: Path) -> None:
    output_dir = out_path.parent

    def asset_url(rel_path: str) -> str:
        return os.path.relpath(ROOT / rel_path, output_dir).replace("\\", "/")

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

    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(page_html, encoding="utf-8")
