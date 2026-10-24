"""Check literal bytes independently from objdiff completion flags."""

from io import BytesIO
import json
from pathlib import Path
import struct
import subprocess
import sys

from elftools.elf.elffile import ELFFile
import pytest

from scripts.verify_node_pool_add_zone import verify


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "build/SLES-50282/src/zone/zone_spatial_grid_node_pool_add_zone.o"
TARGET = ROOT / "build/SLES-50282/obj/zone_spatial_grid_node_pool_add_zone.o"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"


def _require_path(path):
    if not path.is_file():
        pytest.skip(f"Private verification prerequisite unavailable: {path}")


@pytest.fixture
def private_inputs():
    """Require the private original and freshly compiled objects."""
    for path in (SOURCE, TARGET, ORIGINAL):
        _require_path(path)
    return SOURCE, TARGET, ORIGINAL


def _corrupt_instruction(source, destination, offset=0):
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symbols = elf.get_section_by_name(".symtab")
    function = symbols.get_symbol_by_name("func_001F21E0")[0]
    section = elf.get_section(function["st_shndx"])
    position = section["sh_offset"] + function["st_value"] + offset
    data[position] ^= 1
    destination.write_bytes(data)
    return destination


def _homonymous_source(source, destination):
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symbols = elf.get_section_by_name(".symtab")
    function = symbols.get_symbol_by_name("func_001F21E0")[0]
    owner = elf.get_section(function["st_shndx"])
    position = elf["e_shoff"] + 5 * elf["e_shentsize"]
    struct.pack_into("<I", data, position, owner["sh_name"])
    destination.write_bytes(data)
    return destination


def test_source_reproduces_original_instruction_bytes(private_inputs):
    """Resolve all six relocations and compare every original byte."""
    result = verify(*private_inputs)
    assert result["code_bytes"] == 308
    assert result["literal_match"] is True
    assert len(result["source_relocations"]) == 6


def test_reference_relocation_difference_blocks_approval(private_inputs):
    """Keep reference relocation mismatches separate from literal equality."""
    result = verify(*private_inputs)
    assert len(result.get("target_relocations", [])) == 32
    assert result["relocation_records_equal"] is False
    assert result["strict_match"] is False


def test_target_instruction_difference_blocks_approval(
    private_inputs, tmp_path,
):
    """Require target bytes to match, not just relocation identities."""
    source, _, original = private_inputs
    target = _corrupt_instruction(source, tmp_path / "target.o")
    result = verify(source, target, original)
    assert result["relocation_records_equal"] is True
    assert result["strict_match"] is False


def test_source_instruction_difference_rejects_literal_match(
    private_inputs, tmp_path,
):
    """Expose a changed source instruction rather than masking it."""
    source, target, original = private_inputs
    corrupted = _corrupt_instruction(source, tmp_path / "source.o")
    result = verify(corrupted, target, original)
    assert result["literal_match"] is False
    assert result["strict_match"] is False


def test_source_relocation_addend_is_not_discarded(private_inputs, tmp_path):
    """Reject an unexpected implicit addend instead of overwriting it."""
    source, target, original = private_inputs
    corrupted = _corrupt_instruction(source, tmp_path / "source.o", 0x3C)
    with pytest.raises(ValueError, match="Nonzero implicit relocation addend"):
        verify(corrupted, target, original)


def test_unverified_local_string_is_rejected(private_inputs, tmp_path):
    """Reject strings absent from verified original data."""
    source, target, original = private_inputs
    data = source.read_bytes()
    assert data.count(b"obmanager.cpp\0") == 1
    corrupted = tmp_path / "source.o"
    corrupted.write_bytes(data.replace(b"obmanager.cpp\0", b"obmanager.cpq\0"))
    with pytest.raises(ValueError, match="Unverified local relocation string"):
        verify(corrupted, target, original)


def test_unverified_external_symbol_is_rejected(private_inputs, tmp_path):
    """Reject unknown call targets even when relocation locations agree."""
    source, target, original = private_inputs
    data = source.read_bytes()
    assert data.count(b"func_117CAC\0") == 1
    corrupted = tmp_path / "source.o"
    corrupted.write_bytes(data.replace(b"func_117CAC\0", b"func_117CAD\0"))
    with pytest.raises(ValueError, match="Unexpected external relocation"):
        verify(corrupted, target, original)


def test_unpinned_original_is_rejected(private_inputs, tmp_path):
    """Reject original executables that fail the pinned SHA-1 check."""
    source, target, _ = private_inputs
    original = tmp_path / "AOK.ELF"
    original.write_bytes(b"not the verified executable")
    with pytest.raises(ValueError, match="Original executable SHA-1"):
        verify(source, target, original)


def test_exact_records_and_bytes_can_pass_the_strict_gate(private_inputs):
    """Avoid making strict failure an unconditional result."""
    source, _, original = private_inputs
    result = verify(source, source, original)
    assert result["literal_match"] is True
    assert result["relocation_records_equal"] is True
    assert result["target_literal_match"] is True
    assert result["strict_match"] is True


def test_homonymous_text_section_does_not_replace_symbol_owner(
    private_inputs, tmp_path,
):
    """Select st_shndx when an earlier section is also named .text."""
    source, target, original = private_inputs
    renamed = _homonymous_source(source, tmp_path / "homonymous.o")
    assert verify(renamed, target, original)["literal_match"] is True


def test_cli_exits_nonzero_when_strict_gate_is_blocked(private_inputs):
    """Emit auditable JSON without treating blocked verification as success."""
    source, target, original = private_inputs
    completed = subprocess.run(
        [sys.executable, "-m", "scripts.verify_node_pool_add_zone_cli",
         "--source", str(source), "--target", str(target),
         "--original", str(original)],
        capture_output=True, text=True, cwd=ROOT,
    )
    assert completed.returncode == 1, completed.stderr
    result = json.loads(completed.stdout)
    assert result["literal_match"] is True
    assert result["strict_match"] is False
