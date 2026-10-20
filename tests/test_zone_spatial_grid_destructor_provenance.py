"""Check literal bytes for Block 63 spatial grid destructor."""

from io import BytesIO
import json
from pathlib import Path
import struct
import subprocess
import sys

from elftools.elf.elffile import ELFFile
import pytest

from scripts.verify_zone_spatial_grid_destructor import verify


ROOT = Path(__file__).resolve().parents[1]
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
LAUNCHER = ROOT / "build/tools/wibo"
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"


def _require_path(path):
    if not path.is_file():
        pytest.skip(f"Private verification prerequisite unavailable: {path}")


@pytest.fixture(scope="module")
def private_inputs(tmp_path_factory):
    """Compile a fresh object; compiler failure must never reuse old bytes."""
    for path in (COMPILER, LAUNCHER, ORIGINAL):
        _require_path(path)
    source = tmp_path_factory.mktemp("block63-target") / "destructor.o"
    completed = subprocess.run(
        [str(LAUNCHER), str(COMPILER), "-O3", "-inline", "on", "-msext",
         "on", "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
         "-c", "src/zone_spatial_grid_destructor.cpp", "-o", str(source)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert completed.returncode == 0, completed.stdout + completed.stderr
    assert source.is_file(), "Compiler succeeded without creating the object"
    return source, ORIGINAL


def _corrupt_instruction(source, destination, offset=0):
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symbols = elf.get_section_by_name(".symtab")
    function = symbols.get_symbol_by_name("func_001F2590")[0]
    section = elf.get_section(function["st_shndx"])
    position = section["sh_offset"] + function["st_value"] + offset
    data[position] ^= 1
    destination.write_bytes(data)
    return destination


def _homonymous_source(source, destination):
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symbols = elf.get_section_by_name(".symtab")
    function = symbols.get_symbol_by_name("func_001F2590")[0]
    owner = elf.get_section(function["st_shndx"])
    position = elf["e_shoff"] + 5 * elf["e_shentsize"]
    struct.pack_into("<I", data, position, owner["sh_name"])
    destination.write_bytes(data)
    return destination


def test_source_reproduces_original_instruction_bytes(private_inputs):
    """Require all 292 original bytes, not merely equal function lengths."""
    source, original = private_inputs
    result = verify(source, original)
    assert result["code_bytes"] == 292
    assert result["relocation_count"] == 8
    assert result["literal_match"] is True
    assert result["resolved_sha256"] == (
        "f4a44b5c924308fcb9f9a0fd3ba2b96625e8fd4c7da75aea01a5e38020f624db"
    )


def test_source_instruction_difference_rejects_literal_match(
    private_inputs, tmp_path,
):
    """Expose a changed source instruction rather than masking it."""
    source, original = private_inputs
    corrupted = _corrupt_instruction(source, tmp_path / "source.o", 0x14)
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
    result = verify(renamed, original)
    assert result["code_bytes"] == 292
    assert result["relocation_count"] == 8


def test_cli_exits_zero_on_literal_match(private_inputs):
    """Emit auditable JSON and exit 0 when literal match succeeds."""
    source, original = private_inputs
    completed = subprocess.run(
        [sys.executable, "-m",
         "scripts.verify_zone_spatial_grid_destructor_cli",
         "--source", str(source), "--original", str(original)],
        capture_output=True, text=True, cwd=ROOT,
    )
    assert completed.returncode == 0, completed.stderr
    result = json.loads(completed.stdout)
    assert result["code_bytes"] == 292
    assert result["relocation_count"] == 8
    assert result["literal_match"] is True


def test_unexpected_relocation_manifest_is_rejected(
    private_inputs, tmp_path,
):
    """Reject objects with wrong relocation sites, such as the old 0x74 site."""
    source, original = private_inputs
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    rel_sec = [s for s in elf.iter_sections() if s["sh_type"] == "SHT_REL"][0]
    pos = rel_sec["sh_offset"] + 3 * rel_sec["sh_entsize"]
    struct.pack_into("<I", data, pos, 0x74)
    corrupted = tmp_path / "corrupted_reloc.o"
    corrupted.write_bytes(data)
    with pytest.raises(ValueError, match="Unexpected source relocation records"):
        verify(corrupted, original)


def test_non_function_symbol_is_rejected(private_inputs, tmp_path):
    """Require the function symbol in .symtab to be typed as STT_FUNC."""
    source, original = private_inputs
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symtab = elf.get_section_by_name(".symtab")
    sym_idx = [i for i, s in enumerate(symtab.iter_symbols())
               if s.name == "func_001F2590"][0]
    info_pos = symtab["sh_offset"] + sym_idx * symtab["sh_entsize"] + 12
    data[info_pos] = 0x11  # STT_OBJECT
    corrupted = tmp_path / "corrupted_sym.o"
    corrupted.write_bytes(data)
    with pytest.raises(ValueError, match="Block 63 symbol must be a function"):
        verify(corrupted, original)
