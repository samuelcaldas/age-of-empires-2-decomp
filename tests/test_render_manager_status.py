"""Native and original-ELF regressions for render_manager_status (0x189C80)."""

from io import BytesIO
from pathlib import Path
import hashlib
import re
import shutil
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
def render_manager_status_test(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_status regressions require g++")
    fixture_directory = tmp_path_factory.mktemp("render-manager-status")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_directory / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture_directory / "render-manager-status-test"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "src/render_manager_status.cpp",
            "tests/native/render_manager_status_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


def test_render_manager_status_behavior(render_manager_status_test):
    result = subprocess.run([str(render_manager_status_test)], capture_output=True, text=True)
    assert result.returncode == 0, result.stderr


@pytest.fixture(scope="module")
def render_manager_status_original():
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


def test_func_00189c80_symbol_matches_original_extent(render_manager_status_original):
    """Verify func_00189c80 extent: 376 bytes at 0x189C80..0x189DF8 + 8 pad at 0x189DF8..0x189E00."""
    symbols = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    record = re.search(r"^(func_00189c80) = (0x[0-9A-Fa-f]+);.*size:(0x[0-9A-Fa-f]+)",
                       symbols, re.MULTILINE)
    assert record is not None, "func_00189c80 symbol record is missing"
    name, address, size = record.groups()
    assert (name, int(address, 16), int(size, 16)) == ("func_00189c80", 0x189C80, 0x178)
    stream = render_manager_status_original.stream
    stream.seek(0x89E60)
    original = stream.read(0x180)
    # Prologue: addiu sp,sp,-48; sq ra,32(sp); sq s1,16(sp); sq s0,0(sp)
    assert original[:16] == bytes.fromhex("d0 ff bd 27 20 00 bf 7f 10 00 b1 7f 00 00 b0 7f")
    # Epilogue: lq ra,32(sp); lq s1,16(sp); lq s0,0(sp); jr ra; addiu sp,sp,48
    assert original[0x164:0x178] == bytes.fromhex("20 00 bf 7b 10 00 b1 7b 00 00 b0 7b 08 00 e0 03 30 00 bd 27")
    # Trailing alignment padding: 8 zero bytes
    assert original[0x178:0x180] == bytes(8)
