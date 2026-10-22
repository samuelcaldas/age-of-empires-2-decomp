"""Native and original-ELF regressions for zone_path_queries."""

from io import BytesIO
from pathlib import Path
import hashlib
import re
import shutil
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROBE_SOURCE = """
#include <cassert>
#include <cstddef>
int main() {
    static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
    static_assert(sizeof(int) == 4, "requires 32-bit integers");
}
"""


@pytest.fixture(scope="module")
def zone_path_queries_test(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("zone_path_queries regressions require g++")
    fixture_directory = tmp_path_factory.mktemp("zone-path-queries")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_directory / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture_directory / "zone-path-queries-test"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "src/zone_path_queries.cpp",
            "tests/native/zone_path_queries_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_zone_path_queries_behavior(zone_path_queries_test):
    result = subprocess.run([str(zone_path_queries_test)], capture_output=True, text=True)
    assert result.returncode == 0, result.stderr


@pytest.fixture(scope="module")
def zone_path_queries_original():
    """Load the licensed original ELF after checking its pinned SHA-1."""
    original_path = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
    if not original_path.is_file():
        pytest.skip("requires licensed SLES-50282 original ELF")
    original = original_path.read_bytes()
    checksum_path = PROJECT_ROOT / "config/SLES-50282/build.sha1"
    checksum_text = checksum_path.read_text()
    expected = checksum_text.split()[0]
    digest = hashlib.sha1(original)
    assert digest.hexdigest() == expected
    return ELFFile(BytesIO(original))


def test_func_001C84B0_symbol_matches_original_extent(zone_path_queries_original):
    """Verify func_001C84B0 extent: 708 bytes code + 12 padding at 0x1C84B0..0x1C8780."""
    symbols = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    record = re.search(r"^(func_001C84B0) = (0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)",
                       symbols, re.MULTILINE)
    assert record is not None, "func_001C84B0 symbol record is missing"
    name, address, size = record.groups()
    assert (name, int(address, 16), int(size, 16)) == ("func_001C84B0", 0x1C84B0, 0x2D0)
    stream = zone_path_queries_original.stream
    stream.seek(0xC8690)
    original = stream.read(0x2D0)
    assert original[:4] == bytes.fromhex("b0 ff bd 27") # addiu sp,sp,-80
    assert original[0x2BC:0x2C4] == bytes.fromhex("08 00 e0 03 50 00 bd 27") # jr ra; addiu sp,sp,80
    assert original[0x2C4:0x2D0] == bytes(12) # 12 zero alignment bytes


def test_func_001C84B0_matches_original_instructions(tmp_path_factory):
    """Verify func_001C84B0 matches original instruction bytes 100% bit-for-bit."""
    compiler = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
    wrapper = PROJECT_ROOT / "build/tools/wibo"
    original_path = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
    if not compiler.is_file() or not wrapper.is_file() or not original_path.is_file():
        pytest.skip("requires licensed PS2 MWCC, wibo, and original ELF")

    output_dir = tmp_path_factory.mktemp("queries-matching")
    output_obj = output_dir / "zone_path_queries.o"

    subprocess.run(
        [
            str(wrapper), str(compiler), "-O3", "-inline", "on",
            "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
            "-lang=c++", "-c", "src/zone_path_queries.cpp", "-o", str(output_obj)
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )

    with output_obj.open("rb") as f:
        elf = ELFFile(f)
        sym = elf.get_section_by_name(".symtab").get_symbol_by_name("func_001C84B0")[0]
        sec_idx = sym["st_shndx"]
        sec = elf.get_section(sec_idx)
        compiled = bytearray(sec.data())

        for rel_sec in elf.iter_sections():
            if rel_sec["sh_type"] == "SHT_REL" and rel_sec["sh_info"] == sec_idx:
                symtab = elf.get_section(rel_sec["sh_link"])
                for rel in rel_sec.iter_relocations():
                    s_name = symtab.get_symbol(rel["r_info_sym"]).name
                    r_type = rel["r_info_type"]
                    off = rel["r_offset"]
                    if r_type == 4: # R_MIPS_26
                        target = 0x123350 if s_name == "func_123350" else 0
                        w = struct.unpack_from("<I", compiled, off)[0]
                        relocated = (w & 0xFC000000) | ((target >> 2) & 0x03FFFFFF)
                        struct.pack_into("<I", compiled, off, relocated)
                    elif r_type in (7, 8): # R_MIPS_GPREL16 / R_MIPS_LITERAL
                        struct.pack_into("<h", compiled, off, 0x4E280C - 0x4EA7C0)

    original_bytes = original_path.read_bytes()
    orig_offset = 0x1C84B0 - 0x100000 + 0x1E0
    orig_code = original_bytes[orig_offset:orig_offset + 708]

    assert bytes(compiled[sym["st_value"]:sym["st_value"] + 708]) == orig_code


def test_func_001C8780_symbol_matches_original_extent(zone_path_queries_original):
    """Verify func_001C8780 extent: 720 bytes at 0x1C8780, ending at 0x1C8A50."""
    symbols = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    record = re.search(r"^(func_001C8780) = (0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)",
                       symbols, re.MULTILINE)
    assert record is not None, "func_001C8780 symbol record is missing"
    name, address, size = record.groups()
    assert (name, int(address, 16), int(size, 16)) == ("func_001C8780", 0x1C8780, 0x2D0)
    stream = zone_path_queries_original.stream
    stream.seek(0xC8960)
    original = stream.read(0x2D0)
    assert original[:4] == bytes.fromhex("40 ff bd 27") # addiu sp,sp,-192
    assert original[0x2C4:0x2CC] == bytes.fromhex("01 00 02 24 08 00 e0 03") # addiu v0,zero,1; jr ra
    assert original[0x2CC:0x2D0] == bytes.fromhex("c0 00 bd 27") # addiu sp,sp,192


def test_func_001C8A50_symbol_matches_original_extent(zone_path_queries_original):
    """Verify func_001C8A50 extent: 428 bytes code + 4 padding at 0x1C8A50..0x1C8C00."""
    symbols = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    record = re.search(r"^(func_001C8A50) = (0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)",
                       symbols, re.MULTILINE)
    assert record is not None, "func_001C8A50 symbol record is missing"
    name, address, size = record.groups()
    assert (name, int(address, 16), int(size, 16)) == ("func_001C8A50", 0x1C8A50, 0x1B0)
    stream = zone_path_queries_original.stream
    stream.seek(0xC8C30)
    original = stream.read(0x1B0)
    assert original[:4] == bytes.fromhex("50 ff bd 27") # addiu sp,sp,-176
    assert original[0x1A4:0x1AC] == bytes.fromhex("08 00 e0 03 b0 00 bd 27") # jr ra; addiu sp,sp,176
    assert original[0x1AC:0x1B0] == bytes(4) # 4 zero alignment bytes


def test_func_001C8A50_matches_original_extent_and_size(tmp_path_factory):
    """Verify compiled func_001C8A50 matches exact 428-byte code size and 176-byte frame."""
    compiler = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
    wrapper = PROJECT_ROOT / "build/tools/wibo"
    if not compiler.is_file() or not wrapper.is_file():
        pytest.skip("requires licensed PS2 MWCC and wibo")

    output_dir = tmp_path_factory.mktemp("queries-8a50")
    output_obj = output_dir / "zone_path_queries.o"

    subprocess.run(
        [
            str(wrapper), str(compiler), "-O3", "-inline", "on",
            "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
            "-lang=c++", "-c", "src/zone_path_queries.cpp", "-o", str(output_obj)
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )

    with output_obj.open("rb") as f:
        elf = ELFFile(f)
        sym = elf.get_section_by_name(".symtab").get_symbol_by_name("func_001C8A50")[0]
        assert sym["st_size"] == 428, f"func_001C8A50 size {sym['st_size']} != expected 428 bytes"
