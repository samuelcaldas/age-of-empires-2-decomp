"""Check literal bytes and provenance for func_001F2C20 occupant advance."""

from io import BytesIO
import json
from pathlib import Path
import struct
import subprocess
import sys

from elftools.elf.elffile import ELFFile
import pytest

from scripts.verify_zone_spatial_grid_advance import verify


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
    source = tmp_path_factory.mktemp("advance-target") / "advance.o"
    completed = subprocess.run(
        [str(LAUNCHER), str(COMPILER), "-O3", "-inline", "on", "-msext",
         "on", "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
         "-c", "src/zone/zone_spatial_grid_advance.cpp", "-o", str(source)],
        cwd=ROOT, capture_output=True, text=True,
    )
    assert completed.returncode == 0, completed.stdout + completed.stderr
    assert source.is_file(), "Compiler succeeded without creating the object"
    return source, ORIGINAL


def _corrupt_instruction(source, destination, offset=0):
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symtab = elf.get_section_by_name(".symtab")
    function = symtab.get_symbol_by_name("func_001F2C20")[0]
    section = elf.get_section(function["st_shndx"])
    pos = section["sh_offset"] + function["st_value"] + offset
    data[pos] ^= 1
    destination.write_bytes(data)
    return destination


def test_source_reproduces_original_instruction_bytes(private_inputs):
    """Require all 140 original bytes, not merely equal function lengths."""
    source, original = private_inputs
    result = verify(source, original)
    assert result["code_bytes"] == 140
    assert result["expected_code_bytes"] == 140
    assert result["padding_bytes"] == 4
    assert result["original_padding_verified"] is True
    assert result["relocation_count"] == 3
    assert result["literal_match"] is True
    assert result["resolved_sha256"] == result["original_sha256"]
    assert result["resolved_sha256"] == (
        "7334e37f68281872d4a6a87b951d09b2869cc348d41ce3057e95f081835a213e"
    )


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
         "scripts.verify_zone_spatial_grid_advance_cli",
         "--source", str(source), "--original", str(original)],
        capture_output=True, text=True, cwd=ROOT,
    )
    assert completed.returncode == 0, completed.stderr
    result = json.loads(completed.stdout)
    assert result["code_bytes"] == 140
    assert result["expected_code_bytes"] == 140
    assert result["padding_bytes"] == 4
    assert result["original_padding_verified"] is True
    assert result["relocation_count"] == 3
    assert result["literal_match"] is True


ORIGINAL_JUMPS = ((0x28, 0x0C07DB2C), (0x5C, 0x0C07CAAC), (0x68, 0x0C07CAB0))


def _pre_resolved_candidate(source):
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    table = elf.get_section_by_name(".symtab")
    function = table.get_symbol_by_name("func_001F2C20")[0]
    section = elf.get_section(function["st_shndx"])
    start = section["sh_offset"] + function["st_value"]
    for offset, word in ORIGINAL_JUMPS:
        struct.pack_into("<I", data, start + offset, word)
    return data, elf, function


def _relocation_section(elf, function):
    sections = [
        (index, section) for index, section in enumerate(elf.iter_sections())
        if section["sh_type"] == "SHT_REL"
        and section["sh_info"] == function["st_shndx"]
    ]
    assert len(sections) == 1
    return sections[0]


def _change_manifest(data, elf, section_index, section, mutation):
    start = section["sh_offset"]
    size_field = elf["e_shoff"] + section_index * elf["e_shentsize"] + 20
    changes = {"wrong_offset": 0x14, "outside_function": 0x8C}
    if mutation in changes:
        struct.pack_into("<I", data, start, changes[mutation])
        return
    if mutation == "wrong_type":
        data[start + 4] = 2
        return
    if mutation == "wrong_target":
        data[start + 4:start + 8] = data[start + 12:start + 16]
        return
    if mutation == "duplicate_record":
        data[start + 8:start + 16] = data[start:start + 8]
        return
    if mutation == "missing_record":
        data[start:start + 16] = data[start + 8:start + 24]
        struct.pack_into("<I", data, size_field, 16)
        return
    assert mutation == "missing_manifest"
    struct.pack_into("<I", data, size_field, 0)


@pytest.mark.parametrize("mutation", (
    "missing_record", "missing_manifest", "wrong_offset", "outside_function",
    "wrong_type", "wrong_target", "duplicate_record",
))
def test_pre_resolved_code_requires_exact_relocation_manifest(
    private_inputs, tmp_path, mutation,
):
    """Reject original instructions when required relocation metadata is invalid."""
    source, original = private_inputs
    assert verify(source, original)["literal_match"] is True
    data, elf, function = _pre_resolved_candidate(source)
    index, section = _relocation_section(elf, function)
    _change_manifest(data, elf, index, section, mutation)
    candidate = tmp_path / f"{mutation}.o"
    candidate.write_bytes(data)
    result = verify(candidate, original)
    assert result["literal_match"] is False


def test_nonzero_implicit_jump_addend_is_rejected(private_inputs, tmp_path):
    """Reject pre-resolved jump immediates even with an authentic manifest."""
    source, original = private_inputs
    assert verify(source, original)["literal_match"] is True
    data, _, _ = _pre_resolved_candidate(source)
    candidate = tmp_path / "nonzero_addend.o"
    candidate.write_bytes(data)
    with pytest.raises(ValueError, match="Nonzero implicit relocation addend"):
        verify(candidate, original)


def test_non_function_symbol_is_rejected(private_inputs, tmp_path):
    """Require the function symbol in .symtab to be typed as STT_FUNC."""
    source, original = private_inputs
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symtab = elf.get_section_by_name(".symtab")
    sym_idx = [i for i, s in enumerate(symtab.iter_symbols())
               if s.name == "func_001F2C20"][0]
    info_pos = symtab["sh_offset"] + sym_idx * symtab["sh_entsize"] + 12
    data[info_pos] = 0x11  # STT_OBJECT
    corrupted = tmp_path / "corrupted_sym.o"
    corrupted.write_bytes(data)
    with pytest.raises(ValueError, match="symbol must be a function"):
        verify(corrupted, original)


def test_defined_relocation_symbol_is_rejected(private_inputs, tmp_path):
    """Require external relocation symbols to be SHN_UNDEF with value 0."""
    source, original = private_inputs
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symtab = elf.get_section_by_name(".symtab")
    sym_idx = [i for i, s in enumerate(symtab.iter_symbols())
               if s.name == "func_001F6CB0"][0]
    sym_pos = symtab["sh_offset"] + sym_idx * symtab["sh_entsize"]
    # Mutate st_value to 4 and st_shndx to 1 (defined in section 1)
    struct.pack_into("<I", data, sym_pos + 4, 4)
    struct.pack_into("<H", data, sym_pos + 14, 1)
    corrupted = tmp_path / "defined_sym.o"
    corrupted.write_bytes(data)
    with pytest.raises(ValueError, match="External relocation symbol must be undefined"):
        verify(corrupted, original)


def test_non_executable_section_is_rejected(private_inputs, tmp_path):
    """Require the function to reside in an executable code section."""
    source, original = private_inputs
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symtab = elf.get_section_by_name(".symtab")
    function = symtab.get_symbol_by_name("func_001F2C20")[0]
    sh_idx = function["st_shndx"]
    flags_pos = elf["e_shoff"] + sh_idx * elf["e_shentsize"] + 8
    flags = struct.unpack_from("<I", data, flags_pos)[0]
    struct.pack_into("<I", data, flags_pos, flags & ~4)
    corrupted = tmp_path / "non_exec.o"
    corrupted.write_bytes(data)
    with pytest.raises(ValueError, match="section must be executable code"):
        verify(corrupted, original)


def test_non_mips_machine_is_rejected(private_inputs, tmp_path):
    """Require source ELF e_machine to be EM_MIPS."""
    source, original = private_inputs
    data = bytearray(source.read_bytes())
    # e_machine offset in 32-bit ELF is 18 (0x12)
    struct.pack_into("<H", data, 0x12, 3)  # EM_386
    corrupted = tmp_path / "x86.o"
    corrupted.write_bytes(data)
    with pytest.raises(ValueError, match="Source ELF machine must be EM_MIPS"):
        verify(corrupted, original)


def test_symbol_extent_exceeding_section_is_rejected(private_inputs, tmp_path):
    """Require symbol size to fit completely within the owning section."""
    source, original = private_inputs
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    symtab = elf.get_section_by_name(".symtab")
    sym_idx = [i for i, s in enumerate(symtab.iter_symbols())
               if s.name == "func_001F2C20"][0]
    # st_size is at offset 8 in 32-bit Elf_Sym
    size_pos = symtab["sh_offset"] + sym_idx * symtab["sh_entsize"] + 8
    struct.pack_into("<I", data, size_pos, 0x90)  # 144 bytes > 140 section size
    corrupted = tmp_path / "oversize_sym.o"
    corrupted.write_bytes(data)
    with pytest.raises(ValueError, match="symbol extent exceeds section size"):
        verify(corrupted, original)


def test_permuted_relocation_order_is_accepted(private_inputs, tmp_path):
    """Normalize and accept valid relocation records regardless of table order."""
    source, original = private_inputs
    data = bytearray(source.read_bytes())
    elf = ELFFile(BytesIO(data))
    function = elf.get_section_by_name(".symtab").get_symbol_by_name("func_001F2C20")[0]
    _, section = _relocation_section(elf, function)
    start = section["sh_offset"]
    # Swap first two 8-byte relocation entries
    entry0 = data[start:start + 8]
    entry1 = data[start + 8:start + 16]
    data[start:start + 8] = entry1
    data[start + 8:start + 16] = entry0
    permuted = tmp_path / "permuted.o"
    permuted.write_bytes(data)
    result = verify(permuted, original)
    assert result["literal_match"] is True
