"""Check literal bytes and provenance for ZoneSpatialGrid getters."""

from io import BytesIO
import json
from pathlib import Path
import subprocess
import sys

from elftools.elf.elffile import ELFFile
import pytest

from scripts.verify_zone_spatial_grid_getters import verify


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
    source = tmp_path_factory.mktemp("getters-target") / "getters.o"
    completed = subprocess.run(
        [str(LAUNCHER), str(COMPILER), "-O3", "-inline", "on", "-msext",
         "on", "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
         "-c", "src/zone/zone_spatial_grid_getters.cpp", "-o", str(source)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert completed.returncode == 0, completed.stdout + completed.stderr
    assert source.is_file(), "Compiler succeeded without creating the object"
    return source, ORIGINAL


def _corrupt_instruction(source, destination, func_name):
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symtab = elf.get_section_by_name(".symtab")
    function = symtab.get_symbol_by_name(func_name)[0]
    section = elf.get_section(function["st_shndx"])
    pos = section["sh_offset"] + function["st_value"]
    data[pos] ^= 1
    destination.write_bytes(data)
    return destination


def test_all_getters_reproduce_original_bytes(private_inputs):
    """Verify all four 8-byte code extents reproduce original ELF bytes exactly."""
    source, original = private_inputs
    result = verify(source, original)
    assert result["all_matched"] is True
    assert result["total_code_bytes"] == 32
    assert len(result["getters"]) == 4
    for g in result["getters"]:
        assert g["matched"] is True
        assert g["size"] == 8
        assert g["resolved_sha256"] == g["original_sha256"]


def test_corrupted_getter_rejects_match(private_inputs, tmp_path):
    """Expose a changed instruction in any getter rather than masking it."""
    source, original = private_inputs
    corrupted = _corrupt_instruction(
        source, tmp_path / "corrupted.o", "func_001F26D0",
    )
    result = verify(corrupted, original)
    assert result["all_matched"] is False
    d0 = [g for g in result["getters"] if g["name"] == "func_001F26D0"][0]
    assert d0["matched"] is False


def test_unpinned_original_is_rejected(private_inputs, tmp_path):
    """Reject original executable that fails pinned SHA-1 check."""
    source, _ = private_inputs
    fake = tmp_path / "AOK.ELF"
    fake.write_bytes(b"not the authentic PS2 ELF")
    with pytest.raises(ValueError, match="Original executable SHA-1"):
        verify(source, fake)


def test_cli_exits_zero_on_all_matched(private_inputs):
    """Emit auditable JSON and exit 0 when all getters match."""
    source, original = private_inputs
    completed = subprocess.run(
        [sys.executable, "-m",
         "scripts.verify_zone_spatial_grid_getters_cli",
         "--source", str(source), "--original", str(original)],
        capture_output=True, text=True, cwd=ROOT,
    )
    assert completed.returncode == 0, completed.stderr
    result = json.loads(completed.stdout)
    assert result["all_matched"] is True
    assert result["total_code_bytes"] == 32


def test_non_function_symbol_is_rejected(private_inputs, tmp_path):
    """Require each getter symbol in .symtab to be typed as STT_FUNC."""
    source, original = private_inputs
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symtab = elf.get_section_by_name(".symtab")
    sym_idx = [i for i, s in enumerate(symtab.iter_symbols())
               if s.name == "func_001F26C0"][0]
    info_pos = symtab["sh_offset"] + sym_idx * symtab["sh_entsize"] + 12
    data[info_pos] = 0x11  # STT_OBJECT
    corrupted = tmp_path / "corrupted_sym.o"
    corrupted.write_bytes(data)
    with pytest.raises(ValueError, match="must be a function"):
        verify(corrupted, original)
