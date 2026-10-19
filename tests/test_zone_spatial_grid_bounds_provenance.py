"""Check literal bytes and provenance for func_001F2AD0 bounding volume update."""

from io import BytesIO
import json
from pathlib import Path
import struct
import subprocess
import sys

from elftools.elf.elffile import ELFFile
import pytest

from scripts.verify_zone_spatial_grid_bounds import verify


ROOT = Path(__file__).resolve().parents[1]
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
LAUNCHER = ROOT / "build/tools/wibo"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"


def _require_path(path):
    if not path.is_file():
        pytest.skip(f"Prerequisite unavailable: {path}")


@pytest.fixture(scope="module")
def private_inputs(tmp_path_factory):
    """Compile fresh object with MWCC under wibo."""
    for path in (COMPILER, LAUNCHER, ORIGINAL):
        _require_path(path)
    source = tmp_path_factory.mktemp("bounds-target") / "bounds.o"
    completed = subprocess.run(
        [str(LAUNCHER), str(COMPILER), "-O3", "-inline", "on", "-msext",
         "on", "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
         "-c", "src/zone_spatial_grid_bounds.cpp", "-o", str(source)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert completed.returncode == 0, completed.stdout + completed.stderr
    assert source.is_file(), "Compiler succeeded without creating the object"
    return source, ORIGINAL


def _corrupt_instruction(source, destination, offset=0):
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symtab = elf.get_section_by_name(".symtab")
    function = symtab.get_symbol_by_name("func_001F2AD0")[0]
    section = elf.get_section(function["st_shndx"])
    pos = section["sh_offset"] + function["st_value"] + offset
    data[pos] ^= 1
    destination.write_bytes(data)
    return destination


def test_source_reproduces_original_instruction_bytes(private_inputs):
    """Require all 244 original bytes, not merely equal function lengths."""
    source, original = private_inputs
    result = verify(source, original)
    assert result["code_bytes"] == 244
    assert result["expected_code_bytes"] == 244
    assert result["padding_bytes"] == 12
    assert result["padding_verified"] is True
    assert result["relocation_count"] == 4
    assert result["literal_match"] is True
    assert result["resolved_sha256"] == result["original_sha256"]


def test_source_instruction_difference_rejects_literal_match(
    private_inputs, tmp_path,
):
    """Expose a changed source instruction rather than masking it."""
    source, original = private_inputs
    baseline = verify(source, original)
    assert baseline["literal_match"] is True, "Baseline must match before testing mutation"
    corrupted = _corrupt_instruction(source, tmp_path / "source.o", 0x14)
    result = verify(corrupted, original)
    assert result["literal_match"] is False


def test_unpinned_original_is_rejected(private_inputs, tmp_path):
    """Reject original executable that fails pinned SHA-1 check."""
    source, _ = private_inputs
    fake = tmp_path / "AOK.ELF"
    fake.write_bytes(b"not the authentic PS2 ELF")
    with pytest.raises(ValueError, match="Original executable SHA-1"):
        verify(source, fake)


def test_cli_exits_on_verify(private_inputs):
    """Emit auditable JSON via CLI and exit 0 on literal match."""
    source, original = private_inputs
    completed = subprocess.run(
        [sys.executable, "-m",
         "scripts.verify_zone_spatial_grid_bounds_cli",
         "--source", str(source), "--original", str(original)],
        capture_output=True, text=True, cwd=ROOT,
    )
    assert completed.returncode == 0, completed.stderr
    result = json.loads(completed.stdout)
    assert result["code_bytes"] == 244
    assert result["expected_code_bytes"] == 244
    assert result["padding_bytes"] == 12
    assert result["padding_verified"] is True
    assert result["relocation_count"] == 4
    assert result["literal_match"] is True


def test_unexpected_relocation_manifest_is_handled(
    private_inputs, tmp_path,
):
    """Handle objects with altered relocation records."""
    source, original = private_inputs
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    rel_sec = [s for s in elf.iter_sections() if s["sh_type"] == "SHT_REL"][0]
    pos = rel_sec["sh_offset"]
    struct.pack_into("<I", data, pos, 0x14)
    corrupted = tmp_path / "corrupted_reloc.o"
    corrupted.write_bytes(data)
    result = verify(corrupted, original)
    assert result["literal_match"] is False


def test_non_function_symbol_is_rejected(private_inputs, tmp_path):
    """Require the function symbol in .symtab to be typed as STT_FUNC."""
    source, original = private_inputs
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symtab = elf.get_section_by_name(".symtab")
    sym_idx = [i for i, s in enumerate(symtab.iter_symbols())
               if s.name == "func_001F2AD0"][0]
    info_pos = symtab["sh_offset"] + sym_idx * symtab["sh_entsize"] + 12
    data[info_pos] = 0x11  # STT_OBJECT
    corrupted = tmp_path / "corrupted_sym.o"
    corrupted.write_bytes(data)
    with pytest.raises(ValueError, match="symbol must be a function"):
        verify(corrupted, original)
