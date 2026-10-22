"""Exact byte comparison for the receiver thread."""
import subprocess
from collections import Counter
from pathlib import Path
import sys

from elftools.elf.elffile import ELFFile
import pytest

sys.path.insert(0, str(Path(__file__).resolve().parent))
import network_match_support  # noqa: E402

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


def require_private_inputs():
    missing = network_match_support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))


def test_receiver_extent_and_next_function_entry():
    """The receiver ends at 0x337D3C; the next prologue starts at 0x337D40."""
    require_private_inputs()
    image = network_match_support.verified_original_image()
    assert network_match_support.original_bytes(image, 0x337D3C, 4) == b"\0" * 4
    assert network_match_support.original_bytes(image, 0x337D40, 12) == bytes.fromhex(
        "a0ffbd273000bf7f2000b27f")


def test_receiver_relocation_manifest(tmp_path):
    """Assert every emitted relocation's count and type for this function."""
    require_private_inputs()
    obj = network_match_support.compile_object(ROOT / "src/network_receiver_337B30.cpp", tmp_path)
    with obj.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        function = symbols.get_symbol_by_name("func_00337B30")[0]
        section_index = function["st_shndx"]
        relocations = [relocation for section in elf.iter_sections()
                       if section["sh_type"] == "SHT_REL" and section["sh_info"] == section_index
                       for relocation in section.iter_relocations()]
    assert function["st_size"] == 524
    assert len(relocations) == 54
    assert Counter(relocation["r_info_type"] for relocation in relocations) == {
        4: 7, 5: 11, 6: 11, 7: 25,
    }


def test_receiver_matches_original():
    """Resolve all 54 compiler relocations, then compare every executable byte."""
    require_private_inputs()
    command = [sys.executable, "tests/network_match_support.py",
               "src/network_receiver_337B30.cpp", "func_00337B30", "0x337B30", "0x20c",
               "--expect-relocations", "54"]
    for name, address in EXTERNALS.items():
        command.extend(("--extern", f"{name}={address:#x}"))
    result = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
    assert result.returncode == 0, result.stdout + result.stderr
    assert "EXACT 524 bytes" in result.stdout


def test_receiver_global_addresses_follow_original_gp_loads():
    """Reconcile each source global with its direct gp-relative load."""
    require_private_inputs()
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
