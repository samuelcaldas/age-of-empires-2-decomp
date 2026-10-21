"""Exact byte comparison for the receiver thread."""
import subprocess
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import network_match_support

ROOT = Path(__file__).resolve().parents[1]
EXTERNALS = {
    "D_010890C0": 0x10890C0, "D_010890E0": 0x10890E0,
    "func_118de0": 0x118DE0, "func_003378D0": 0x3378D0,
    "func_388E60": 0x388E60, "func_388F90": 0x388F90,
    "func_388CC0": 0x388CC0, "D_004E352C": 0x004E352C,
    "D_004E3538": 0x004E3538, "D_004E353C": 0x004E353C,
    "D_004E3540": 0x004E3540, "D_004E3544": 0x004E3544,
    "D_004E3550": 0x004E3550, "D_004E3554": 0x004E3554,
    "D_004E3558": 0x004E3558, "D_004E355C": 0x004E355C,
    "D_004D1F20": 0x4D1F20, "D_004D1F38": 0x4D1F38,
    "D_004D1F40": 0x4D1F40,
}


def test_receiver_extent_includes_return_or_trailing_nop():
    missing = network_match_support.private_inputs_missing()
    if missing:
        import pytest
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    image = network_match_support.verified_original_image()
    assert network_match_support.original_bytes(image, 0x337D3C, 4) == b"\0" * 4


def test_receiver_matches_original():
    command = [str(ROOT / ".venv/bin/python"), "tests/network_match_support.py",
               "src/network_receiver_337B30.cpp", "func_00337B30", "0x337B30", "0x210",
               "--expect-relocations", "46"]
    for name, address in EXTERNALS.items():
        command.extend(("--extern", f"{name}={address:#x}"))
    result = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
    assert result.returncode == 0, result.stdout + result.stderr
    assert "EXACT 528 bytes" in result.stdout


def test_receiver_global_addresses_follow_original_gp_loads():
    missing = network_match_support.private_inputs_missing()
    if missing:
        import pytest
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    import struct
    image = network_match_support.verified_original_image()
    loads = {
        "D_004E352C": 0x337B48, "D_004E353C": 0x337B5C,
        "D_004E3558": 0x337B54, "D_004E355C": 0x337BC0,
        "D_004E3540": 0x337C30, "D_004E3544": 0x337C44,
        "D_004E3538": 0x337C70, "D_004E3550": 0x337D08,
        "D_004E3554": 0x337D14,
    }
    for name, address in loads.items():
        word, = struct.unpack("<I", network_match_support.original_bytes(image, address, 4))
        assert word >> 26 == 35 and (word >> 21) & 31 == 28
        expected = network_match_support.GLOBAL_POINTER + network_match_support.signed16(word)
        assert EXTERNALS[name] == expected, name
