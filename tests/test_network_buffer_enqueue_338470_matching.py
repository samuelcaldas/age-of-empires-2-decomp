"""Resolve every MWCC relocation and compare the complete enqueue routine."""

import hashlib
from io import BytesIO
from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/network_buffer_enqueue_338470.cpp"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
FUNCTION_NAME, START_ADDRESS, FUNCTION_SIZE = "func_00338470", 0x338470, 0x148
GP = 0x4EA7C0
RELOCATION_COUNT = 16
EXTERNAL_SYMBOLS = {
    "func_104D40": 0x104D40,
    "func_104D60": 0x104D60,
    "func_117AF8": 0x117AF8,
    "func_118de0": 0x118DE0,
    "D_004D2128": 0x4D2128,
    "D_004D2130": 0x4D2130,
    "D_004D2150": 0x4D2150,
    "D_004E3560": 0x4E3560,
}
STRINGS = {
    0x4D2128: b"dplay:\n\0",
    0x4D2130: b"receive buffer full/size:%d\n\0",
    0x4D2150: b"cur:%d,sav:%d,prev:%d\n\0",
}
R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16 = 4, 5, 6, 7


def require_private_inputs():
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))


def virtual_bytes(image, address, size):
    with BytesIO(image) as stream:
        segments = [segment for segment in ELFFile(stream).iter_segments()
                    if segment["p_type"] == "PT_LOAD" and segment["p_vaddr"] <= address
                    and address + size <= segment["p_vaddr"] + segment["p_filesz"]]
    assert len(segments) == 1, f"expected one file-backed PT_LOAD at {address:#x}"
    offset = segments[0]["p_offset"] + address - segments[0]["p_vaddr"]
    return image[offset:offset + size]


@pytest.fixture(scope="module")
def original_image():
    require_private_inputs()
    image = ORIGINAL.read_bytes()
    assert hashlib.sha1(image).hexdigest() == ORIGINAL_SHA1, "AOK.ELF SHA1 mismatch"
    return image


def compile_object(directory):
    output = directory / "network_buffer_enqueue_338470.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         str(SOURCE), "-o", str(output)],
        cwd=ROOT, env={**__import__("os").environ, "MWCIncludes": ""},
        capture_output=True, text=True,
    )
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def apply_relocations(elf, section_index, code):
    symbols = elf.get_section_by_name(".symtab")
    relocations = sorted(
        (relocation for section in elf.iter_sections()
         if section["sh_type"] == "SHT_REL" and section["sh_info"] == section_index
         for relocation in section.iter_relocations()),
        key=lambda relocation: relocation["r_offset"],
    )
    assert len(relocations) == RELOCATION_COUNT
    pending_high = {}
    for relocation in relocations:
        offset, kind = relocation["r_offset"], relocation["r_info_type"]
        symbol = symbols.get_symbol(relocation["r_info_sym"])
        assert symbol["st_shndx"] == "SHN_UNDEF", f"unexpected local symbol {symbol.name}"
        assert symbol.name in EXTERNAL_SYMBOLS, f"unexpected external {symbol.name}"
        target = EXTERNAL_SYMBOLS[symbol.name]
        word = struct.unpack_from("<I", code, offset)[0]
        if kind == R_MIPS_26:
            value = target + ((word & 0x3FFFFFF) << 2)
            assert (value & 0xF0000000) == ((START_ADDRESS + offset) & 0xF0000000)
            word = (word & 0xFC000000) | ((value >> 2) & 0x3FFFFFF)
        elif kind == R_MIPS_HI16:
            pending_high[symbol.name] = (offset, word)
            continue
        elif kind == R_MIPS_LO16:
            high_offset, high_word = pending_high.pop(symbol.name)
            low = struct.unpack("<h", struct.pack("<H", word & 0xFFFF))[0]
            value = target + ((high_word & 0xFFFF) << 16) + low
            struct.pack_into("<I", code, high_offset,
                             (high_word & 0xFFFF0000) | (((value + 0x8000) >> 16) & 0xFFFF))
            word = (word & 0xFFFF0000) | (value & 0xFFFF)
        elif kind == R_MIPS_GPREL16:
            addend = struct.unpack("<h", struct.pack("<H", word & 0xFFFF))[0]
            value = target + addend - GP
            assert -0x8000 <= value < 0x8000
            word = (word & 0xFFFF0000) | (value & 0xFFFF)
        else:
            raise AssertionError(f"unhandled relocation type {kind} at {offset:#x}")
        struct.pack_into("<I", code, offset, word)
    assert not pending_high, f"unpaired HI16 relocations: {sorted(pending_high)}"


@pytest.fixture(scope="module")
def relocated_code(tmp_path_factory, original_image):
    path = compile_object(tmp_path_factory.mktemp("buffer_enqueue"))
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        matches = symbols.get_symbol_by_name(FUNCTION_NAME)
        assert matches is not None and len(matches) == 1
        function = matches[0]
        assert function["st_info"]["type"] == "STT_FUNC"
        assert function["st_size"] == FUNCTION_SIZE
        undefined = {symbol.name for symbol in symbols.iter_symbols()
                     if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"}
        assert undefined == set(EXTERNAL_SYMBOLS)
        section_index = function["st_shndx"]
        start = function["st_value"]
        code = bytearray(elf.get_section(section_index).data()[start:start + FUNCTION_SIZE])
        apply_relocations(elf, section_index, code)
    return bytes(code)


def test_enqueue_matches_original_bytes(relocated_code, original_image):
    expected = virtual_bytes(original_image, START_ADDRESS, FUNCTION_SIZE)
    difference = next((index for index, pair in enumerate(zip(relocated_code, expected))
                       if pair[0] != pair[1]), None)
    assert difference is None, f"instruction bytes differ at {START_ADDRESS + difference:#x}"


@pytest.mark.parametrize("address,content", sorted(STRINGS.items()))
def test_log_strings_exist_in_original(original_image, address, content):
    assert virtual_bytes(original_image, address, len(content)) == content


def test_enqueue_extent_and_alignment_padding(original_image):
    assert virtual_bytes(original_image, START_ADDRESS + FUNCTION_SIZE, 8) == b"\0" * 8
    assert virtual_bytes(original_image, START_ADDRESS + FUNCTION_SIZE + 8, 4)[:4] != b"\0" * 4
