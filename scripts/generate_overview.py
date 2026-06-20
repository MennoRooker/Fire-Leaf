#!/usr/bin/env python3
"""
Generates an overview page from existing project data.
The overview acts as a mastersheet of maps with wild
encounters, trainers, items and shops.

Output:
  docs/OVERVIEW.html

Optional:
  python3 scripts/generate_overview.py --section "Route 2"

Run with --section to specify 1 map section to generate.

Map display overrides (split routes, floor maps, merged sections):
  scripts/overview/section_overrides.json
"""

from __future__ import annotations

import argparse
import importlib
import sys
from pathlib import Path


SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent
if str(REPO_ROOT) not in sys.path:
  sys.path.insert(0, str(REPO_ROOT))

overview_model = importlib.import_module("scripts.overview.model")
overview_parsing = importlib.import_module("scripts.overview.parsing")
overview_rendering = importlib.import_module("scripts.overview.rendering")

ROOT = overview_parsing.ROOT
build_model = overview_model.build_model
render_html = overview_rendering.render_html


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
