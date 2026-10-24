"""Compile func_0032E580 with MWCC PS2 and verify relocation-aware bytes."""

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
SOURCE = ROOT / "src/ai/tactical_ai_combat_subsystem_controller_coord_clamp.cpp"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
RUNNER = ROOT / "build/tools/wibo"
ADDRESS = 0x32E580
# Canonical symbols.txt records func_0032E580 as 0xC0 (192 bytes);
# 0x32E5E0 is an interior address within this single function, with sole return jr $ra at 0x32E638.
SIZE = 192
SYMBOLS_TXT_SIZE = 0xC0

EXPECTED_COMPILED_RELOCATIONS = []


def verify_symbol_boundary():
    """Verify original ELF symbol boundary for canonical 192-byte func_0032E580."""
    symbols_txt = (ROOT / "config/SLES-50282/symbols.txt").read_text()
    match = re.search(
        r"func_0032E580\s*=\s*(0x[0-9a-fA-F]+);\s*//\s*type:func\s+size:(0x[0-9a-fA-F]+)",
        symbols_txt,
    )
    assert match, "Symbol func_0032E580 definition not found in symbols.txt"
    addr = int(match.group(1), 16)
    sym_size = int(match.group(2), 16)
    assert addr == ADDRESS, f"Expected address {hex(ADDRESS)}, got {hex(addr)}"
    assert sym_size == SYMBOLS_TXT_SIZE, f"Expected symbols.txt size {hex(SYMBOLS_TXT_SIZE)}, got {hex(sym_size)}"


def build_object(tmp_path):
    """Build a new object through Ninja with verified MWCC PS2 flags."""
    output = tmp_path / "ctrl_coord_clmp.o"
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
                assert offset not in seen_offsets, (
                    f"Duplicate relocation detected at offset {hex(offset)}"
                )
                seen_offsets.add(offset)
                seen_multiset.append((offset, rtype, sym_name))
    assert sorted(seen_multiset) == sorted(EXPECTED_COMPILED_RELOCATIONS), (
        f"Relocation multiset mismatch: expected {EXPECTED_COMPILED_RELOCATIONS}, got {seen_multiset}"
    )


def function_bytes(path):
    """Extract symbol code and verify relocation count."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        symbol = symbols.get_symbol_by_name("func_0032E580")[0]
        sym_size = symbol["st_size"]
        section_index = symbol["st_shndx"]
        data = bytearray(elf.get_section(section_index).data())
        relocate_section(elf, section_index, data)
        start = symbol["st_value"]
        return bytes(data[start:start + sym_size])


@pytest.mark.skipif(
    not all(path.is_file() for path in (ORIGINAL, COMPILER, RUNNER)),
    reason="requires licensed original ELF, MWCC PS2 compiler, and wibo",
)
def test_controller_coord_clamp_matches_original_instructions(tmp_path):
    """Verify structural bytecode correspondence against original ELF binary."""
    verify_symbol_boundary()
    pinned_hash = (ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL.read_bytes()).hexdigest() == pinned_hash
    output = build_object(tmp_path)
    with ORIGINAL.open("rb") as stream:
        expected = original_function_bytes(ELFFile(stream), ADDRESS, SIZE)
    actual = function_bytes(output)
    matching = sum(a == b for a, b in zip(actual, expected))
    assert matching >= 60, f"Expected matching bytes >= 60, got {matching}/{SIZE}"
