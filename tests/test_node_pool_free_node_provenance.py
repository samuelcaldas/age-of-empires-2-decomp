"""Check literal bytes for Block 61 free_node."""

from io import BytesIO
import json
from pathlib import Path
import struct
import subprocess
import sys

from elftools.elf.elffile import ELFFile
import pytest

from scripts.verify_node_pool_free_node import verify


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "build/SLES-50282/src/zone/zone_spatial_grid_node_pool_free_node.o"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"


def _require_path(path):
    if not path.is_file():
        pytest.skip(f"Private verification prerequisite unavailable: {path}")


@pytest.fixture
def private_inputs():
    """Require the private original and freshly compiled objects."""
    for path in (SOURCE, ORIGINAL):
        _require_path(path)
    return SOURCE, ORIGINAL


def _corrupt_instruction(source, destination, offset=0):
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symbols = elf.get_section_by_name(".symtab")
    function = symbols.get_symbol_by_name("func_001F24A0")[0]
    section = elf.get_section(function["st_shndx"])
    position = section["sh_offset"] + function["st_value"] + offset
    data[position] ^= 1
    destination.write_bytes(data)
    return destination


def _homonymous_source(source, destination):
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symbols = elf.get_section_by_name(".symtab")
    function = symbols.get_symbol_by_name("func_001F24A0")[0]
    owner = elf.get_section(function["st_shndx"])
    position = elf["e_shoff"] + 5 * elf["e_shentsize"]
    struct.pack_into("<I", data, position, owner["sh_name"])
    destination.write_bytes(data)
    return destination


def test_source_reproduces_original_instruction_bytes(private_inputs):
    """Verify that all 60 instruction bytes match the original binary."""
    source, original = private_inputs
    result = verify(source, original)
    assert result["code_bytes"] == 60
    assert result["literal_match"] is True
    assert len(result["source_relocations"]) == 0


def test_source_instruction_difference_rejects_literal_match(
    private_inputs, tmp_path,
):
    """Expose a changed source instruction rather than masking it."""
    source, original = private_inputs
    corrupted = _corrupt_instruction(source, tmp_path / "source.o")
    result = verify(corrupted, original)
    assert result["literal_match"] is False


def test_unpinned_original_is_rejected(private_inputs, tmp_path):
    """Reject original executables that fail the pinned SHA-1 check."""
    source, _ = private_inputs
    original = tmp_path / "AOK.ELF"
    original.write_bytes(b"not the verified executable")
    with pytest.raises(ValueError, match="Original executable SHA-1"):
        verify(source, original)


def test_homonymous_text_section_does_not_replace_symbol_owner(
    private_inputs, tmp_path,
):
    """Select st_shndx when an earlier section is also named .text."""
    source, original = private_inputs
    renamed = _homonymous_source(source, tmp_path / "homonymous.o")
    assert verify(renamed, original)["literal_match"] is True


def test_cli_exits_zero_on_literal_match(private_inputs):
    """Emit auditable JSON and exit 0 when literal bytes match."""
    source, original = private_inputs
    completed = subprocess.run(
        [sys.executable, "-m", "scripts.verify_node_pool_free_node_cli",
         "--source", str(source), "--original", str(original)],
        capture_output=True, text=True, cwd=ROOT,
    )
    assert completed.returncode == 0, completed.stderr
    result = json.loads(completed.stdout)
    assert result["literal_match"] is True
    assert result["code_bytes"] == 60
