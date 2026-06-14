#!/usr/bin/env python3
"""
Generate an overview page from existing project data.

Output:
  docs/OVERVIEW.html

Optional:
  python3 scripts/generate_overview.py --section "Route 2"
"""

from __future__ import annotations

import argparse
import html
import json
import os
import re
from pathlib import Path
from typing import Dict, List, Optional, Tuple


ROOT = Path(__file__).resolve().parents[1]


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
    entry_re = re.compile(r"\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*\{(.*?)\n\s*\},", re.S)
    for species, body in entry_re.findall(text):
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


def parse_parties() -> Dict[str, Dict[str, object]]:
    text = read_text("src/data/trainer_parties.h")
    lines = text.splitlines()

    started = False
    current_section = "Unsorted"
    out: Dict[str, Dict[str, object]] = {}

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

    return out


def slugify(name: str) -> str:
    s = re.sub(r"[^A-Za-z0-9]+", "_", name).strip("_")
    return s.lower() or "section"


def build_model(section_filter: Optional[str]) -> Dict[str, object]:
    trainers = parse_trainers()
    parties = parse_parties()

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
            mon_obj["itemName"] = item_names.get(item_token, pretty_token(item_token, "ITEM_"))

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

    ordered_sections = [
        {
            "name": name,
            "slug": slugify(name),
            "mapImage": f"docs/maps/{slugify(name)}.png",
            "trainers": trs,
        }
        for name, trs in sections.items()
    ]

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
  border: 3px solid var(--line);
  background: #efe9e0;
  margin: 16px 0 30px;
}
.section-head {
  border-bottom: 3px solid var(--line);
  padding: 10px 12px;
  background: #ddd2c4;
  display: flex;
  justify-content: space-between;
  align-items: center;
}
.map-pane {
    min-height: 120px;
  background: #d8d0c4;
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 10px;
    border-bottom: 3px solid var(--line);
}
.map-pane img { max-width: 100%; max-height: 100%; image-rendering: pixelated; }
.cards {
  display: grid;
  gap: 10px;
  padding: 10px;
  grid-template-columns: repeat(auto-fill, minmax(900px, 1fr));
}
.trainer-card {
  border: 3px solid var(--line);
  background: var(--panel);
}
.trainer-main {
  display: grid;
  grid-template-columns: 180px 1fr;
}
.trainer-left {
  border-right: 3px solid var(--line);
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
  background: #f8f5ef;
}
.mons .mon:last-child {
    border-right: 3px solid var(--line);
}
.mon-head {
  border-bottom: 3px solid var(--line);
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
  padding: 4px 6px;
  font-size: 30px;
  line-height: 1.15;
}
.move-row { display: flex; align-items: center; justify-content: center; gap: 6px; }

@media (max-width: 1200px) {
    .map-pane { min-height: 90px; }
}
"""
    css = css.replace("__TYPE_ICON_URL__", asset_url("graphics/interface/menu_info.png"))

    html_chunks: List[str] = []
    html_chunks.append("<!doctype html><html><head><meta charset='utf-8'>")
    html_chunks.append("<meta name='viewport' content='width=device-width, initial-scale=1'>")
    html_chunks.append("<title>Trainer Overview</title>")
    html_chunks.append("<style>")
    html_chunks.append(css)

    for t, spec in sorted(type_icons.items()):
        html_chunks.append(
            f".type-{t} {{ width:{spec['w']}px; height:{spec['h']}px; background-position:-{spec['x']}px -{spec['y']}px; }}"
        )

    html_chunks.append("</style></head><body><div class='wrap'>")
    html_chunks.append("<h1>Trainer Overview</h1>")
    html_chunks.append(
        "<p class='hint'>Map images are optional. Place route screenshots in docs/maps using section slug names.</p>"
    )

    for sec in sections:
        section_name = html.escape(str(sec["name"]))
        map_img = html.escape(asset_url(str(sec["mapImage"])))
        html_chunks.append("<section class='section'>")
        html_chunks.append(f"<div class='section-head'><strong>{section_name}</strong><span>{len(sec['trainers'])} trainers</span></div>")
        html_chunks.append("<div class='map-pane'>")
        html_chunks.append(
            f"<img src='{map_img}' alt='Map for {section_name}' onerror=\"this.style.display='none';this.parentElement.innerHTML='<em>No map image yet</em>'\">"
        )
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
    parser = argparse.ArgumentParser(description="Generate trainer overview HTML")
    parser.add_argument("--section", help="Only render one section title (case-insensitive)")
    args = parser.parse_args()

    model = build_model(args.section)
    out_path = ROOT / "docs" / "OVERVIEW.html"
    render_html(model, out_path)

    print(f"Wrote: {out_path}")
    print(f"Sections rendered: {len(model['sections'])}")


if __name__ == "__main__":
    main()
