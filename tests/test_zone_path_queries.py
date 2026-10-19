"""Native and original-ELF regressions for zone_path_queries (func_001C8780)."""

from io import BytesIO
from pathlib import Path
import hashlib
import re
import shutil
import subprocess

from elftools.elf.elffile import ELFFile
import pytest
import yaml


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