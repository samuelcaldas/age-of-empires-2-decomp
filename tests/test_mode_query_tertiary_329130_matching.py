"""Compile func_00329130 with MWCC PS2 and require exact relocated bytes."""

import hashlib
import os
from pathlib import Path
import shlex
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest

from test_ps2_route_finish_matching import original_function_bytes

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/mode_query_tertiary_329130.cpp"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
RUNNER = ROOT / "build/tools/wibo"
ADDRESS = 0x329130
SIZE = 0xB4  # 180 bytes

GP_VALUE = 0x4EA7C0
SYMBOLS_MAP = {
    "D_004E2EA0": 0x4E2EA0,
    "func_1A5010": 0x1A5010,
    "D_004E3180": 0x4E3180,
}


def build_object(tmp_path):
    """Build a new object through Ninja with verified MWCC PS2 flags."""
    output = tmp_path / "mode_query.o"
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


def relocate_entry(data, relocation, symbols):
    """Resolve R_MIPS_26 call or R_MIPS_GPREL16 relocations."""
    name = symbols.get_symbol(relocation["r_info_sym"]).name
    assert name in SYMBOLS_MAP, f"Unexpected relocation symbol: {name}"
    target = SYMBOLS_MAP[name]
    offset = relocation["r_offset"]
    rel_type = relocation["r_info_type"]

    if rel_type == 4:  # R_MIPS_26
        word = struct.unpack_from("<I", data, offset)[0]
        struct.pack_into("<I", data, offset, (word & 0xFC000000) | (target >> 2))
    elif rel_type == 7:  # R_MIPS_GPREL16
        gp_offset = (target - GP_VALUE) & 0xFFFF
        struct.pack_into("<H", data, offset, gp_offset)
    else:
        raise ValueError(f"Unsupported relocation type: {rel_type}")


def relocate_table(elf, section, data):
    """Resolve all entries in one code relocation table."""
    symbols = elf.get_section(section["sh_link"])
    relocations = list(section.iter_relocations())
    for relocation in relocations:
        relocate_entry(data, relocation, symbols)
    return len(relocations)


def relocate_function(elf, section_index, data):
    """Select relocations by section index, handling MWCC .text sections."""
    count = 0
    for section in elf.iter_sections():
        if section["sh_type"] == "SHT_REL" and section["sh_info"] == section_index:
            count += relocate_table(elf, section, data)
    assert count == 3, f"Expected exactly 3 relocations, found {count}"


def function_bytes(path):
    """Extract symbol code and verify exact size and relocation resolution."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        symbol = symbols.get_symbol_by_name("func_00329130")[0]
        assert symbol["st_size"] == SIZE
        section_index = symbol["st_shndx"]
        data = bytearray(elf.get_section(section_index).data())
        relocate_function(elf, section_index, data)
        start = symbol["st_value"]
        return bytes(data[start:start + SIZE])


@pytest.mark.skipif(
    not all(path.is_file() for path in (ORIGINAL, COMPILER, RUNNER)),
    reason="requires licensed original ELF, MWCC PS2 compiler, and wibo",
)
def test_mode_query_matches_original_instructions(tmp_path):
    """Require all 180 instruction bytes to match the original ELF binary."""
    pinned_hash = (ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL.read_bytes()).hexdigest() == pinned_hash
    output = build_object(tmp_path)
    with ORIGINAL.open("rb") as stream:
        expected = original_function_bytes(ELFFile(stream), ADDRESS, SIZE)
    assert function_bytes(output) == expected
