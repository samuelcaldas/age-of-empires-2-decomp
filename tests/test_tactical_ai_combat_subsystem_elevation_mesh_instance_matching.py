"""Compile func_003285D0 with MWCC PS2 and require exact 56-byte match."""

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
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_elevation_mesh_instance.cpp"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
RUNNER = ROOT / "build/tools/wibo"
ADDRESS = 0x3285D0
SIZE = 56
CALLEES = {"func_1A2C20": 0x1A2C20}
GLOBALS = {"D_4DEBF0": 0x4DEBF0}


def build_object(tmp_path):
    """Build a new object through Ninja with verified MWCC PS2 flags."""
    output = tmp_path / "instance.o"
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
    """Apply R_MIPS_26, R_MIPS_HI16, and R_MIPS_LO16 relocations."""
    rtype, offset = rel["r_info_type"], rel["r_offset"]
    name = symbols.get_symbol(rel["r_info_sym"]).name
    word = struct.unpack_from("<I", data, offset)[0]
    if rtype == 4:
        target = CALLEES[name] + ((word & 0x03FFFFFF) << 2)
        struct.pack_into("<I", data, offset, (word & 0xFC000000) | (target >> 2))
    elif rtype == 5:
        target = GLOBALS[name]
        hi = ((target >> 16) + (1 if (target & 0xFFFF) >= 0x8000 else 0)) & 0xFFFF
        struct.pack_into("<I", data, offset, (word & 0xFFFF0000) | hi)
    elif rtype == 6:
        struct.pack_into("<I", data, offset, (word & 0xFFFF0000) | (GLOBALS[name] & 0xFFFF))


def relocate_section(elf, section_index, data):
    """Resolve all relocations for target symbol section."""
    count = 0
    for section in elf.iter_sections():
        if section["sh_type"] == "SHT_REL" and section["sh_info"] == section_index:
            symbols = elf.get_section(section["sh_link"])
            for rel in section.iter_relocations():
                relocate_entry(data, rel, symbols)
                count += 1
    assert count == 3, f"Expected 3 relocations, found {count}"


def function_bytes(path):
    """Extract symbol code and verify exact size and relocation count."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        symbol = symbols.get_symbol_by_name("func_003285D0")[0]
        assert symbol["st_size"] == SIZE
        section_index = symbol["st_shndx"]
        data = bytearray(elf.get_section(section_index).data())
        relocate_section(elf, section_index, data)
        start = symbol["st_value"]
        return bytes(data[start:start + SIZE])


@pytest.mark.skipif(
    not all(path.is_file() for path in (ORIGINAL, COMPILER, RUNNER)),
    reason="requires licensed original ELF, MWCC PS2 compiler, and wibo",
)
def test_instance_matches_original_instructions(tmp_path):
    """Require all 56 instruction bytes to match the original ELF binary."""
    pinned_hash = (ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL.read_bytes()).hexdigest() == pinned_hash
    output = build_object(tmp_path)
    with ORIGINAL.open("rb") as stream:
        expected = original_function_bytes(ELFFile(stream), ADDRESS, SIZE)
    actual = function_bytes(output)
    assert actual == expected
