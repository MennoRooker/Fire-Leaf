#!/usr/bin/env python3
"""
Moves .baseSpeed and .evYield_Speed entries to appear after .baseSpDefense and 
.evYield_SpDefense respectively in species_info.h for consistency with in-game ordering.
The order HP, Atk, Def, Spd, SpAtk, SpDef becomes HP, Atk, Def, SpAtk, SpDef, Spd.
"""

import os
import re
import sys

FILE = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "../src/data/pokemon/species_info.h"))

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

# Do the same for .evYield_Speed with .evYield_SpAttack / .evYield_SpDefense.
# Apply to new_content so both passes are chained.
ev_pattern = re.compile(
    r"([ \t]*\.evYield_Speed[ \t]*=[ \t]*\d+,[ \t]*\n)"   # group 1: evYield_Speed line
    r"([ \t]*\.evYield_SpAttack[ \t]*=[ \t]*\d+,[ \t]*\n)" # group 2: evYield_SpAttack line
    r"([ \t]*\.evYield_SpDefense[ \t]*=[ \t]*\d+,[ \t]*\n)" # group 3: evYield_SpDefense line
)

final_content, count2 = ev_pattern.subn(r"\2\3\1", new_content)

if count == 0 and count2 == 0:
    print("No matches found — file may already be reordered or the pattern doesn't match.")
    sys.exit(1)

with open(FILE, "w", encoding="utf-8") as f:
    f.write(final_content)

print(f"Reordered .baseSpeed in {count} entries and .evYield_Speed in {count2} entries.")
