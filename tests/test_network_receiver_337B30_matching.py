"""Exact byte comparison for the receiver thread."""
import subprocess
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import network_match_support

ROOT = Path(__file__).resolve().parents[1]
EXTERNALS = {
    "func_118de0": 0x118DE0, "func_003378D0": 0x3378D0,
    "func_388E60": 0x388E60, "func_388F90": 0x388F90,
    "func_388CC0": 0x388CC0, "D_004E356C": 0x4E356C,
    "D_004E3578": 0x4E3578, "D_004E357C": 0x4E357C,
    "D_004E3580": 0x4E3580, "D_004E3584": 0x4E3584,
    "D_004E3590": 0x4E3590, "D_004E3594": 0x4E3594,
    "D_004E3598": 0x4E3598, "D_004E359C": 0x4E359C,
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
