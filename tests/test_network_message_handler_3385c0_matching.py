"""Require an exact 940-byte match for the received-message handler."""

from pathlib import Path
import sys

import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tests"))
import network_match_support as match

SOURCE = ROOT / "src/network_message_handler_3385c0.cpp"
FUNCTION = "func_003385C0"
ADDRESS = 0x3385C0
SIZE = 940
RELOCATIONS = 32
EXTERNALS = {
    "D_004D1F10": 0x4D1F10,
    "D_004D1F18": 0x4D1F18,
    "func_00337840": 0x337840,
    "func_00338190": 0x338190,
    "func_003382D0": 0x3382D0,
    "func_00338310": 0x338310,
    "func_00338470": 0x338470,
    "func_117A64": 0x117A64,
    "func_117AF8": 0x117AF8,
    "func_117CAC": 0x117CAC,
    "func_11ABBC": 0x11ABBC,
    "func_11B170": 0x11B170,
}


def test_message_handler_matches_original_bytes(tmp_path):
    missing = match.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    image = match.verified_original_image()
    object_path = match.compile_object(SOURCE, tmp_path)
    with object_path.open("rb") as stream:
        elf = match.ELFFile(stream)
        function = elf.get_section_by_name(".symtab").get_symbol_by_name(FUNCTION)[0]
        assert function["st_size"] == SIZE
        actual = match.relocated_function(object_path, FUNCTION, ADDRESS, SIZE,
                                          EXTERNALS, RELOCATIONS)
    expected = match.original_bytes(image, ADDRESS, SIZE)
    match.assert_exact(actual, expected, ADDRESS)
    assert match.original_bytes(image, 0x4D1F18, 8) == b"SESSION\0"
    assert match.original_bytes(image, 0x4D1F10, 7) == b"JOINED\0"
    assert match.original_bytes(image, ADDRESS + SIZE, 4) == b"\0" * 4
