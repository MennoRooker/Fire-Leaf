#!/usr/bin/env python3
"""
Moves .baseSpeed entries to appear after .baseSpDefense in species_info.h.
The order HP, Atk, Def, Spd, SpAtk, SpDef becomes HP, Atk, Def, SpAtk, SpDef, Spd.
"""

import re
import sys

FILE = "src/data/pokemon/species_info.h"

with open(FILE, "r", encoding="utf-8") as f:
    content = f.read()

# Match the block where .baseSpeed precedes .baseSpAttack / .baseSpDefense.
# Captures indentation and trailing whitespace so the swap is lossless.
pattern = re.compile(
    r"([ \t]*\.baseSpeed[ \t]*=[ \t]*\d+,[ \t]*\n)"   # group 1: baseSpeed line
    r"([ \t]*\.baseSpAttack[ \t]*=[ \t]*\d+,[ \t]*\n)" # group 2: baseSpAttack line
    r"([ \t]*\.baseSpDefense[ \t]*=[ \t]*\d+,[ \t]*\n)" # group 3: baseSpDefense line
)

new_content, count = pattern.subn(r"\2\3\1", content)

if count == 0:
    print("No matches found — file may already be reordered or the pattern doesn't match.")
    sys.exit(1)

with open(FILE, "w", encoding="utf-8") as f:
    f.write(new_content)

print(f"Reordered .baseSpeed in {count} entries.")
