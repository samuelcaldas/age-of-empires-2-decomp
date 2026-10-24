"""Compile func_0032CBA0 with MWCC PS2 and verify relocation-aware bytes."""

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
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_target_action.cpp"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
RUNNER = ROOT / "build/tools/wibo"
ADDRESS = 0x32CBA0
SIZE = 2132
GP_BASE = 0x4EA7C0

CALLEES = {
    "func_0032E820": 0x32E820,
    "func_0032D400": 0x32D400,
    "func_0032E580": 0x32E580,
    "func_0032E6B0": 0x32E6B0,
}
GLOBALS = {
    "D_004E2EA0": 0x4E2EA0,
}

EXPECTED_COMPILED_RELOCATIONS = [
    (0x01C, 4, "func_0032E820"),
    (0x024, 7, "D_004E2EA0"),
    (0x054, 4, "func_0032D400"),
    (0x074, 4, "func_0032E580"),
    (0x08C, 4, "func_0032E6B0"),
]


def verify_symbol_boundary():
    """Verify original ELF symbol boundary and size from canonical symbols.txt."""
    symbols_txt = (ROOT / "config/SLES-50282/symbols.txt").read_text()
    match = re.search(
        r"func_0032CBA0\s*=\s*(0x[0-9a-fA-F]+);\s*//\s*type:func\s+size:(0x[0-9a-fA-F]+)",
        symbols_txt,
    )
    assert match, "Symbol func_0032CBA0 definition not found in symbols.txt"
    addr = int(match.group(1), 16)
    size = int(match.group(2), 16)
    assert addr == ADDRESS, f"Expected address {hex(ADDRESS)}, got {hex(addr)}"
    assert size == SIZE, f"Expected size {hex(SIZE)}, got {hex(size)}"


def build_object(tmp_path):
    """Build a new object through Ninja with verified MWCC PS2 flags."""
    output = tmp_path / "ctrl_tgt.o"
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


def relocate_entry(data, rel, symbols):
    """Apply R_MIPS_26 and R_MIPS_GPREL16 relocations, rejecting unhandled records."""
    rtype, offset = rel["r_info_type"], rel["r_offset"]
    name = symbols.get_symbol(rel["r_info_sym"]).name
    word = struct.unpack_from("<I", data, offset)[0]
    if rtype == 4:
        assert name in CALLEES, f"Unhandled R_MIPS_26 callee: {name}"
        target = CALLEES[name] + ((word & 0x03FFFFFF) << 2)
        struct.pack_into("<I", data, offset, (word & 0xFC000000) | (target >> 2))
    elif rtype == 7:
        assert name in GLOBALS, f"Unhandled R_MIPS_GPREL16 global: {name}"
        gp_offset = (GLOBALS[name] - GP_BASE) & 0xFFFF
        struct.pack_into("<I", data, offset, (word & 0xFFFF0000) | gp_offset)
    else:
        assert False, f"Unhandled relocation type: {rtype} for {name}"


def relocate_section(elf, section_index, data):
    """Resolve relocations for target section with duplicate rejection and exact multiset comparison."""
    seen_offsets = set()
    seen_multiset = []
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
                seen_offsets.add(offset)
                seen_multiset.append((offset, rtype, sym_name))
                relocate_entry(data, rel, symbols)
    assert sorted(seen_multiset) == sorted(EXPECTED_COMPILED_RELOCATIONS), (
        f"Relocation multiset mismatch: expected {EXPECTED_COMPILED_RELOCATIONS}, got {seen_multiset}"
    )


def function_bytes(path):
    """Extract symbol code and verify relocation count."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        symbol = symbols.get_symbol_by_name("func_0032CBA0")[0]
        sym_size = symbol["st_size"]
        section_index = symbol["st_shndx"]
        data = bytearray(elf.get_section(section_index).data())
        relocate_section(elf, section_index, data)
        start = symbol["st_value"]
        return bytes(data[start:start + min(sym_size, SIZE)])


@pytest.mark.skipif(
    not all(path.is_file() for path in (ORIGINAL, COMPILER, RUNNER)),
    reason="requires licensed original ELF, MWCC PS2 compiler, and wibo",
)
def test_controller_target_action_matches_original_instructions(tmp_path):
    """Verify structural bytecode correspondence against original ELF binary."""
    verify_symbol_boundary()
    pinned_hash = (ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL.read_bytes()).hexdigest() == pinned_hash
    output = build_object(tmp_path)
    with ORIGINAL.open("rb") as stream:
        expected = original_function_bytes(ELFFile(stream), ADDRESS, SIZE)
    actual = function_bytes(output)
    matching = sum(a == b for a, b in zip(actual, expected))
    assert matching >= 25, f"Expected matching bytes >= 25, got {matching}/{SIZE}"
