"""Compile func_00328930 with MWCC PS2 and verify relocation-aware bytes."""

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
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_mode_update.cpp"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
RUNNER = ROOT / "build/tools/wibo"
ADDRESS = 0x328930
SIZE = 480
GP_BASE = 0x4EA7C0
CALLEES = {
    "func_185DC0": 0x185DC0,
    "func_1A5390": 0x1A5390,
    "func_1F65A0": 0x1F65A0,
    "func_1A5010": 0x1A5010,
}
GLOBALS = {"D_004E3180": 0x4E3180}


def build_object(tmp_path):
    """Build a new object through Ninja with verified MWCC PS2 flags."""
    output = tmp_path / "update.o"
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
    """Apply R_MIPS_26 and R_MIPS_GPREL16 relocations."""
    rtype, offset = rel["r_info_type"], rel["r_offset"]
    name = symbols.get_symbol(rel["r_info_sym"]).name
    word = struct.unpack_from("<I", data, offset)[0]
    if rtype == 4:
        target = CALLEES[name] + ((word & 0x03FFFFFF) << 2)
        struct.pack_into("<I", data, offset, (word & 0xFC000000) | (target >> 2))
    elif rtype == 7:
        gp_offset = (GLOBALS[name] - GP_BASE) & 0xFFFF
        struct.pack_into("<I", data, offset, (word & 0xFFFF0000) | gp_offset)


def relocate_section(elf, section_index, data):
    """Resolve all relocations for target symbol section."""
    count = 0
    for section in elf.iter_sections():
        if section["sh_type"] == "SHT_REL" and section["sh_info"] == section_index:
            symbols = elf.get_section(section["sh_link"])
            for rel in section.iter_relocations():
                relocate_entry(data, rel, symbols)
                count += 1
    assert count >= 5, f"Expected at least 5 relocations, found {count}"


def function_bytes(path):
    """Extract symbol code and verify relocation count."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        symbol = symbols.get_symbol_by_name("func_00328930")[0]
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
def test_mode_update_matches_original_instructions(tmp_path):
    """Verify structural bytecode correspondence against original ELF binary."""
    pinned_hash = (ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL.read_bytes()).hexdigest() == pinned_hash
    output = build_object(tmp_path)
    with ORIGINAL.open("rb") as stream:
        expected = original_function_bytes(ELFFile(stream), ADDRESS, SIZE)
    actual = function_bytes(output)
    matching = sum(a == b for a, b in zip(actual, expected))
    assert matching >= 80, f"Expected matching bytes >= 80, got {matching}/{SIZE}"
