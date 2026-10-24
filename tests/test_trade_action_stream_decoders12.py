"""Compare the compiled C++ decoders12 with relocated original PS2 code."""

import hashlib
from io import BytesIO
import subprocess
from pathlib import Path

import pytest
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/trade/trade_action_stream_decoders12.cpp"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
LINKER = ROOT / "build/mips_binutils/mips-linux-gnu-ld"
FILE_OFFSET, START_ADDRESS, SLICE_SIZE = 0x5F400, 0x15F220, 0x230
F220_SIZE, F330_OFFSET, F330_SIZE = 0x110, 0x110, 0x114
TAIL_PAD_OFFSET, TAIL_PAD_SIZE = 0x224, 0xC
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
FUNCTIONS = (
    ("func_0015F220", START_ADDRESS, F220_SIZE),
    ("func_0015F330", START_ADDRESS + F330_OFFSET, F330_SIZE),
)
EXTERNAL_SYMBOLS = {
    "_gp": 0x4EA7C0,
    "D_004E2DA0": 0x4E2DA0,
    "D_004E2DA4": 0x4E2DA4,
    "D_004E2DAC": 0x4E2DAC,
    "D_004E2DB4": 0x4E2DB4,
    "func_001522C0": 0x1522C0,
}


def require_private_inputs():
    required = (ORIGINAL, COMPILER, WRAPPER, LINKER)
    missing = [str(path) for path in required if not path.is_file()]
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))


def original_load_mapping(original_bytes):
    with BytesIO(original_bytes) as stream:
        elf = ELFFile(stream)
        segments = [
            segment for segment in elf.iter_segments()
            if segment["p_type"] == "PT_LOAD"
            and segment["p_vaddr"] <= START_ADDRESS
            and START_ADDRESS + SLICE_SIZE <= segment["p_vaddr"] + segment["p_filesz"]
        ]
        assert len(segments) == 1, f"expected one file-backed PT_LOAD, got {len(segments)}"
        segment = segments[0]
        file_offset = segment["p_offset"] + START_ADDRESS - segment["p_vaddr"]
        mapping = segment["p_offset"], segment["p_vaddr"], segment["p_filesz"]
    assert file_offset == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= mapping[0] + mapping[2]
    return mapping


@pytest.fixture(scope="module")
def original_image():
    require_private_inputs()
    original_bytes = ORIGINAL.read_bytes()
    assert hashlib.sha1(original_bytes).hexdigest() == ORIGINAL_SHA1, "AOK.ELF SHA1 mismatch"
    original_load_mapping(original_bytes)
    return original_bytes


def assert_function_symbols(elf_file, linked=False):
    symbol_table = elf_file.get_section_by_name(".symtab")
    assert symbol_table is not None
    section_indices = []
    for name, address, size in FUNCTIONS:
        matches = symbol_table.get_symbol_by_name(name)
        assert matches is not None and len(matches) == 1, name
        symbol = matches[0]
        assert symbol["st_info"]["type"] == "STT_FUNC" and symbol["st_size"] == size
        section_index = symbol["st_shndx"]
        assert isinstance(section_index, int) and section_index > 0
        section = elf_file.get_section(section_index)
        assert section.name == ".text"
        if not linked:
            assert section["sh_size"] == size
        if linked:
            assert symbol["st_value"] == address
            start = address - section["sh_addr"]
        else:
            start = symbol["st_value"]
            section_indices.append(section_index)
        assert len(section.data()[start:start + size]) == size
    if not linked:
        assert section_indices[0] != section_indices[1], "expected homonymous MWCC .text sections"


def compile_decoders(directory):
    subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         str(SOURCE), "-o", str(directory)],
        cwd=ROOT, capture_output=True, text=True, check=True,
    )
    return directory / "trade_action_stream_decoders12.o"


def link_decoders(directory, object_file):
    linker_script = directory / "decoders12.ld"
    definitions = "".join(f"{name} = {address:#x};\n" for name, address in EXTERNAL_SYMBOLS.items())
    linker_script.write_text(
        definitions + "SECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n", encoding="utf-8",
    )
    linked_path = directory / "decoders12.elf"
    subprocess.run(
        [str(LINKER), "-EL", "-m", "elf32ltsmip", "--no-undefined", "-T",
         str(linker_script), "-o", str(linked_path), str(object_file)],
        cwd=ROOT, capture_output=True, text=True, check=True,
    )
    with linked_path.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf.header["e_type"] == "ET_EXEC"
        symbols = elf.get_section_by_name(".symtab")
        unresolved = [symbol.name for symbol in symbols.iter_symbols()
                      if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"]
        assert not unresolved, f"unresolved symbols: {unresolved}"
        for name, address in EXTERNAL_SYMBOLS.items():
            matches = symbols.get_symbol_by_name(name)
            assert matches is not None and len(matches) == 1, name
            assert matches[0]["st_value"] == address, name
        assert_function_symbols(elf, linked=True)
        section = elf.get_section_by_name(".text")
        assert section["sh_addr"] == START_ADDRESS
        code = section.data()
        assert len(code) == SLICE_SIZE
        return code


@pytest.fixture(scope="module")
def decoder_code(tmp_path_factory, original_image):
    directory = tmp_path_factory.mktemp("decoders12")
    object_file = compile_decoders(directory)
    with object_file.open("rb") as stream:
        object_elf = ELFFile(stream)
        assert_function_symbols(object_elf)
        undefined = {symbol.name for symbol in object_elf.get_section_by_name(".symtab").iter_symbols()
                     if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"}
    assert undefined == set(EXTERNAL_SYMBOLS) - {"_gp"}
    return link_decoders(directory, object_file)


def assert_same_code(actual, expected, address):
    assert len(actual) == len(expected), f"Code length differs at {address:#x}: {len(actual)} vs {len(expected)}"
    difference = next((i for i, pair in enumerate(zip(actual, expected)) if pair[0] != pair[1]), None)
    assert difference is None, f"Instruction bytes differ at {address + difference:#x}"


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 548 compiler code bytes plus 12 linker-alignment bytes."""
    assert len(decoder_code) == SLICE_SIZE


@pytest.mark.parametrize("name,address,size", FUNCTIONS)
def test_decoder_function_bytes(decoder_code, original_image, name, address, size):
    offset = address - START_ADDRESS
    expected = original_image[FILE_OFFSET + offset:FILE_OFFSET + offset + size]
    assert_same_code(decoder_code[offset:offset + size], expected, address)


def test_tail_alignment_padding(decoder_code, original_image):
    actual = decoder_code[TAIL_PAD_OFFSET:TAIL_PAD_OFFSET + TAIL_PAD_SIZE]
    expected = original_image[FILE_OFFSET + TAIL_PAD_OFFSET:FILE_OFFSET + SLICE_SIZE]
    assert actual == b"\0" * TAIL_PAD_SIZE
    assert_same_code(actual, expected, START_ADDRESS + TAIL_PAD_OFFSET)


def test_complete_slice_exact_bytes(decoder_code, original_image):
    expected = original_image[FILE_OFFSET:FILE_OFFSET + SLICE_SIZE]
    assert len(decoder_code) == SLICE_SIZE
    assert_same_code(decoder_code, expected, START_ADDRESS)
