"""Freshly compile func_00328020 and require exact relocated PS2 instructions."""

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
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_elevation_mesh_serializer.cpp"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
RUNNER = ROOT / "build/tools/wibo"
ADDRESS = 0x328020
SIZE = 224


def build_object(tmp_path):
    """Build a new object through Ninja with the verified MWCC PS2 flags."""
    output = tmp_path / "serializer.o"
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


def relocate_call(data, relocation, symbols):
    """Resolve only the reference writer's R_MIPS_26 call relocations."""
    assert relocation["r_info_type"] == 4
    symbol = symbols.get_symbol(relocation["r_info_sym"])
    assert symbol.name == "func_00226F70"
    offset = relocation["r_offset"]
    word = struct.unpack_from("<I", data, offset)[0]
    assert word >> 26 == 3
    target = 0x226F70 + ((word & 0x03FFFFFF) << 2)
    assert target == 0x226F70
    struct.pack_into("<I", data, offset, (word & 0xFC000000) | (target >> 2))


def relocate_table(elf, section, data):
    """Resolve all entries in one code relocation table and return their count."""
    symbols = elf.get_section(section["sh_link"])
    relocations = list(section.iter_relocations())
    for relocation in relocations:
        relocate_call(data, relocation, symbols)
    return len(relocations)


def relocate_function(elf, section_index, data):
    """Select relocations by section index, including homonymous .text sections."""
    count = 0
    for section in elf.iter_sections():
        if section["sh_type"] != "SHT_REL":
            continue
        if section["sh_info"] != section_index:
            continue
        count += relocate_table(elf, section, data)
    assert count == 4


def function_bytes(path):
    """Extract exactly the symbol's code and reject unexpected size or relocations."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        functions = symbols.get_symbol_by_name("func_00328020")
        assert len(functions) == 1
        symbol = functions[0]
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
def test_serializer_matches_original_instructions(tmp_path):
    """Require all 224 instruction bytes to equal the PT_LOAD-mapped original."""
    pinned_hash = (ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL.read_bytes()).hexdigest() == pinned_hash
    output = build_object(tmp_path)
    with ORIGINAL.open("rb") as stream:
        expected = original_function_bytes(ELFFile(stream), ADDRESS, SIZE)
    assert function_bytes(output) == expected
