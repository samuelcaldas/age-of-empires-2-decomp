"""Exact target comparisons for address formatting, parsing, and byte swaps."""

from pathlib import Path
import subprocess
import sys

import network_match_support as match

ROOT = Path(__file__).resolve().parents[1]
CASES = (
    ("network_address_format_337600.cpp", "func_00337600", 0x337600, 0x5C, 5,
     ("func_11A498=0x11A498", "D_004D1E88=0x4D1E88", "D_01087EB0=0x1087EB0")),
    ("network_address_parse_337660.cpp", "func_00337660", 0x337660, 0x168, 6,
     ("func_11A510=0x11A510", "D_004D1EA0=0x4D1EA0", "D_0049E101=0x49E101")),
    ("network_byte_swap_337520.cpp", "func_00337520", 0x337520, 0x3C, 0, ()),
    ("network_byte_swap_337560.cpp", "func_00337560", 0x337560, 0x1C, 0, ()),
    ("network_byte_swap_337590.cpp", "func_00337590", 0x337590, 0x3C, 0, ()),
    ("network_byte_swap_3375d0.cpp", "func_003375D0", 0x3375D0, 0x1C, 0, ()),
)


def test_address_helper_matches_and_has_zero_alignment_padding():
    for source, symbol, address, size, relocations, externals in CASES:
        result = subprocess.run(
            [sys.executable, str(ROOT / "tests/network_match_support.py"),
             str(ROOT / "src" / source), symbol, hex(address), hex(size),
             "--expect-relocations", str(relocations),
             *(argument for external in externals for argument in ("--extern", external))],
            cwd=ROOT, capture_output=True, text=True,
        )
        assert result.returncode == 0, result.stdout + result.stderr
        padding = 8 if address == 0x337660 else 4
        image = match.verified_original_image()
        assert match.original_bytes(image, address + size, padding) == bytes(padding)
