"""Native and original-ELF regressions for zone_path_eval (0x1C7860)."""

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
def zone_path_eval_test(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("zone_path_eval regressions require g++")
    fixture_directory = tmp_path_factory.mktemp("zone-path-eval")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_directory / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture_directory / "zone-path-eval-test"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "src/zone/zone_path_eval.cpp",
            "tests/native/zone_path_eval_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_zone_path_eval_behavior(zone_path_eval_test):
    result = subprocess.run([str(zone_path_eval_test)], capture_output=True, text=True)
    assert result.returncode == 0, result.stderr


@pytest.fixture(scope="module")
def zone_path_eval_original():
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


def test_zone_path_eval_split_matches_original_mapping(zone_path_eval_original):
    """Require the configured entry to match the original file-backed ELF mapping."""
    path = PROJECT_ROOT / "config/SLES-50282/config.yml"
    text = path.read_text()
    configuration = yaml.safe_load(text)
    split = next(segment for segment in configuration["segments"]
                 if isinstance(segment, dict) and segment.get("name") == "zone_path_eval")
    mappings = [segment["p_vaddr"] + split["start"] - segment["p_offset"]
                for segment in zone_path_eval_original.iter_segments()
                if segment["p_type"] == "PT_LOAD"
                and segment["p_offset"] <= split["start"]
                and split["start"] + 0xC30 <= segment["p_offset"] + segment["p_filesz"]]
    assert mappings == [split["vram"]], "zone_path_eval split disagrees with original PT_LOAD"
    assert split["start"] == 0xC7A40
    assert split["vram"] == 0x1C7860


def test_zone_path_eval_symbol_matches_original_extent(zone_path_eval_original):
    """Exclude the preceding return and trailing alignment from the function symbol."""
    symbols = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    record = re.search(r"^(func_001C78[56]0) = (0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)",
                       symbols, re.MULTILINE)
    assert record is not None, "zone_path_eval symbol record is missing"
    name, address, size = record.groups()
    assert (name, int(address, 16), int(size, 16)) == ("func_001C7860", 0x1C7860, 0xC2C)
    stream = zone_path_eval_original.stream
    stream.seek(0xC7A40)
    original = stream.read(0xC30)
    assert original[:4] == bytes.fromhex("50 fe bd 27")
    assert original[0xC24:0xC2C] == bytes.fromhex("08 00 e0 03 b0 01 bd 27")
    assert original[0xC2C:] == bytes(4)
