"""Compile func_00329450 with MWCC PS2 and verify relocation-aware bytes."""

import hashlib
import os
from pathlib import Path
import re
import shlex
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest

from test_ps2_route_finish_matching import original_function_bytes

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_controller_lock.cpp"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
RUNNER = ROOT / "build/tools/wibo"
ADDRESS = 0x329450
SIZE = 256
GP_BASE = 0x4EA7C0
CALLEES = {
    "func_1880D0": 0x1880D0,
    "func_184C10": 0x184C10,
    "func_184BD0": 0x184BD0,
    "func_185DC0": 0x185DC0,
    "func_185F00": 0x185F00,
}
GLOBALS = {"D_004E3180": 0x4E3180}

EXPECTED_RELOCATIONS = [
    (0x2C, 4, "func_1880D0", 0x0C000000),    # jal 0 with zero target addend
    (0x30, 7, "D_004E3180", 0x8F840000),     # lw $a0, 0($gp) with zero addend
    (0x48, 4, "func_184C10", 0x0C000000),    # jal 0 with zero target addend
    (0x4C, 7, "D_004E3180", 0x8F840000),     # lw $a0, 0($gp) with zero addend
    (0x60, 7, "D_004E3180", 0x8F840000),     # lw $a0, 0($gp) with zero addend
    (0x64, 4, "func_184BD0", 0x0C000000),    # jal 0 with zero target addend
    (0x90, 4, "func_185DC0", 0x0C000000),    # jal 0 with zero target addend
    (0x94, 7, "D_004E3180", 0x8F840000),     # lw $a0, 0($gp) with zero addend
    (0xA0, 7, "D_004E3180", 0x8F840000),     # lw $a0, 0($gp) with zero addend
    (0xA8, 4, "func_185F00", 0x0C000000),    # jal 0 with zero target addend
    (0xD8, 7, "D_004E3180", 0x8F840000),     # lw $a0, 0($gp) with zero addend
    (0xE0, 4, "func_185F00", 0x0C000000),    # jal 0 with zero target addend
]


def verify_symbol_boundary():
    """Verify original ELF symbol boundary and size from canonical symbols.txt."""
    symbols_txt = (ROOT / "config/SLES-50282/symbols.txt").read_text()
    match = re.search(
        r"func_00329450\s*=\s*(0x[0-9a-fA-F]+);\s*//\s*type:func\s+size:(0x[0-9a-fA-F]+)",
        symbols_txt,
    )
    assert match, "Symbol func_00329450 definition not found in symbols.txt"
    addr = int(match.group(1), 16)
    size = int(match.group(2), 16)
    assert addr == ADDRESS, f"Expected address {hex(ADDRESS)}, got {hex(addr)}"
    assert size == SIZE, f"Expected size {hex(SIZE)}, got {hex(size)}"


def build_object(tmp_path):
    """Build a new object through Ninja with verified MWCC PS2 flags."""
    output = tmp_path / "ctrl_lock.o"
    command = [str(RUNNER), str(COMPILER), "-O3", "-inline", "on",
               "-msext", "on", "-char", "signed", "-sym", "off",
               "-Iinclude", "-lang=c++", "-c", str(SOURCE), "-o", str(output)]
    build_file = tmp_path / "build.ninja"
    build_file.write_text("rule compile\n  command = " + shlex.join(command)
                          + f"\nbuild {output}: compile {SOURCE}\n")
    environment = dict(os.environ, MWCIncludes="")
    result = subprocess.run(["ninja", "-f", str(build_file)], cwd=ROOT,
                            env=environment, capture_output=True, text=True,
                            timeout=60)
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def relocate_entry(data, rel, symbols, expected_unpatched):
    """Apply R_MIPS_26 and R_MIPS_GPREL16 relocations after asserting unpatched instruction."""
    rtype, offset = rel["r_info_type"], rel["r_offset"]
    name = symbols.get_symbol(rel["r_info_sym"]).name
    word = struct.unpack_from("<I", data, offset)[0]
    assert word == expected_unpatched, (
        f"Unpatched instruction mismatch at {hex(offset)}: "
        f"expected {hex(expected_unpatched)}, got {hex(word)}"
    )

    if rtype == 4:
        target = CALLEES[name] + ((word & 0x03FFFFFF) << 2)
        struct.pack_into("<I", data, offset, (word & 0xFC000000) | (target >> 2))
    elif rtype == 7:
        gp_offset = (GLOBALS[name] - GP_BASE) & 0xFFFF
        struct.pack_into("<H", data, offset, gp_offset)
    else:
        raise ValueError(f"Unsupported relocation type: {rtype}")


def relocate_section(elf, section_index, data):
    """Resolve relocations for target section with duplicate rejection, addend verification, and multiset comparison."""
    seen_offsets = set()
    seen_multiset = []
    expected_map = {off: (t, s, w) for off, t, s, w in EXPECTED_RELOCATIONS}
    for section in elf.iter_sections():
        if section["sh_type"] == "SHT_REL" and section["sh_info"] == section_index:
            symbols = elf.get_section(section["sh_link"])
            for rel in section.iter_relocations():
                offset = rel["r_offset"]
                rtype = rel["r_info_type"]
                sym_name = symbols.get_symbol(rel["r_info_sym"]).name
                assert 0 <= offset < SIZE, (
                    f"Relocation offset {hex(offset)} out of range [0, {hex(SIZE)})"
                )
                assert offset not in seen_offsets, (
                    f"Duplicate relocation detected at offset {hex(offset)}"
                )
                assert offset in expected_map, (
                    f"Unexpected relocation at offset {hex(offset)}"
                )
                exp_type, exp_sym, exp_word = expected_map[offset]
                assert rtype == exp_type, (
                    f"Relocation type mismatch at {hex(offset)}: expected {exp_type}, got {rtype}"
                )
                assert sym_name == exp_sym, (
                    f"Relocation symbol mismatch at {hex(offset)}: expected {exp_sym}, got {sym_name}"
                )
                seen_offsets.add(offset)
                unpatched = struct.unpack_from("<I", data, offset)[0]
                seen_multiset.append((offset, rtype, sym_name, unpatched))
                relocate_entry(data, rel, symbols, exp_word)
    assert sorted(seen_multiset) == sorted(EXPECTED_RELOCATIONS), (
        f"Relocation multiset mismatch: expected {EXPECTED_RELOCATIONS}, got {seen_multiset}"
    )


def function_bytes(path):
    """Extract symbol code and verify relocation count and boundary."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        symbol = symbols.get_symbol_by_name("func_00329450")[0]
        sym_size = symbol["st_size"]
        assert sym_size == SIZE, f"Expected size {SIZE}, got {sym_size}"
        section_index = symbol["st_shndx"]
        data = bytearray(elf.get_section(section_index).data())
        relocate_section(elf, section_index, data)
        start = symbol["st_value"]
        return bytes(data[start:start + sym_size])


@pytest.mark.skipif(
    not all(path.is_file() for path in (ORIGINAL, COMPILER, RUNNER)),
    reason="requires licensed original ELF, MWCC PS2 compiler, and wibo",
)
def test_controller_lock_matches_original_instructions(tmp_path):
    """Verify structural bytecode correspondence against original ELF binary."""
    verify_symbol_boundary()
    pinned_hash = (ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL.read_bytes()).hexdigest() == pinned_hash
    output = build_object(tmp_path)
    with ORIGINAL.open("rb") as stream:
        expected = original_function_bytes(ELFFile(stream), ADDRESS, SIZE)
    actual = function_bytes(output)
    assert actual == expected, "Mismatch in instruction bytes for func_00329450"
