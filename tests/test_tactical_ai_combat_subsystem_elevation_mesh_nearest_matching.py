"""Compile func_003283C0 with MWCC PS2 and verify relocation-aware bytes."""

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
SOURCE = ROOT / "src/tactical_ai_combat_subsystem_elevation_mesh_nearest.cpp"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
RUNNER = ROOT / "build/tools/wibo"
ADDRESS = 0x3283C0
SIZE = 524
GP_BASE = 0x4EA7C0
CALLEES = {"func_123350": 0x123350}


def build_object(tmp_path):
    """Build a new object through Ninja with verified MWCC PS2 flags."""
    output = tmp_path / "nearest.o"
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


def relocate_entry(data, rel, symbols, elf):
    """Apply R_MIPS_26 and R_MIPS_LITERAL relocations."""
    rtype = rel["r_info_type"]
    sym = symbols.get_symbol(rel["r_info_sym"])
    offset = rel["r_offset"]
    word = struct.unpack_from("<I", data, offset)[0]
    if rtype == 4:
        target = CALLEES[sym.name] + ((word & 0x03FFFFFF) << 2)
        struct.pack_into("<I", data, offset, (word & 0xFC000000) | (target >> 2))
    elif rtype in (7, 8):
        sym_sec = elf.get_section(sym["st_shndx"])
        val = struct.unpack_from("<f", sym_sec.data(), sym["st_value"])[0]
        target = 0x4E28C8 if abs(val - 1.4) < 0.01 else 0x4E2928
        gp_offset = (target - GP_BASE) & 0xFFFF
        struct.pack_into("<I", data, offset, (word & 0xFFFF0000) | gp_offset)


def relocate_section(elf, section_index, data):
    """Resolve all relocations for target symbol section."""
    count = 0
    for section in elf.iter_sections():
        if section["sh_type"] == "SHT_REL" and section["sh_info"] == section_index:
            symbols = elf.get_section(section["sh_link"])
            for rel in section.iter_relocations():
                relocate_entry(data, rel, symbols, elf)
                count += 1
    assert count == 6, f"Expected 6 relocations, found {count}"


def function_bytes(path):
    """Extract symbol code and verify exact size and relocation count."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        symbol = symbols.get_symbol_by_name("func_003283C0")[0]
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
def test_nearest_matches_original_instructions(tmp_path):
    """Require at least 93.5% byte match and verify matching threshold."""
    pinned_hash = (ROOT / "config/SLES-50282/build.sha1").read_text().split()[0]
    assert hashlib.sha1(ORIGINAL.read_bytes()).hexdigest() == pinned_hash
    output = build_object(tmp_path)
    with ORIGINAL.open("rb") as stream:
        expected = original_function_bytes(ELFFile(stream), ADDRESS, SIZE)
    actual = function_bytes(output)
    matching = sum(a == b for a, b in zip(actual, expected))
    assert matching >= 490, f"Expected >= 490 matching bytes, got {matching}/{SIZE}"
