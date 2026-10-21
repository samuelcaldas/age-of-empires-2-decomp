"""Require relocation-resolved MWCC matching for the session dispatcher."""

import hashlib
from io import BytesIO
from pathlib import Path
import struct
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/network_session_dispatch_3378d0.cpp"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
FUNCTION_NAME, START_ADDRESS, FUNCTION_SIZE = "func_003378D0", 0x3378D0, 0x114
GP = 0x4EA7C0
EXTERNAL_SYMBOLS = {
    "func_117a64": 0x117A64,
    "func_117AF8": 0x117AF8,
    "func_003385C0": 0x3385C0,
    "D_004E3530": 0x4E3530,
    "D_004E352C": 0x4E352C,
    "D_0108AFA0": 0x108AFA0,
    "D_01087ED0": 0x1087ED0,
    "D_004D1EE8": 0x4D1EE8,
    "D_004D1EF0": 0x4D1EF0,
    "D_004D1F00": 0x4D1F00,
    "D_004D1F10": 0x4D1F10,
    "D_004D1F18": 0x4D1F18,
}
STRINGS = {
    0x4D1EE8: b"ilhost\0",
    0x4D1EF0: b"ilconnect\0",
    0x4D1F00: b"ilbroadcast\0",
    0x4D1F10: b"JOINED\0",
    0x4D1F18: b"SESSION\0",
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


def compile_object(directory):
    output = directory / "network_session_dispatch_3378d0.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         str(SOURCE), "-o", str(output)], cwd=ROOT, capture_output=True, text=True,
        env={**__import__("os").environ, "MWCIncludes": ""},
    )
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def symbol_address(symbol):
    assert symbol["st_shndx"] == "SHN_UNDEF", f"unexpected local symbol {symbol.name}"
    assert symbol.name in EXTERNAL_SYMBOLS, f"unexpected external {symbol.name}"
    return EXTERNAL_SYMBOLS[symbol.name]


def apply_relocations(elf, section_index, code):
    symbols = elf.get_section_by_name(".symtab")
    relocations = sorted(
        (rel for section in elf.iter_sections()
         if section["sh_type"] == "SHT_REL" and section["sh_info"] == section_index
         for rel in section.iter_relocations()), key=lambda rel: rel["r_offset"])
    assert len(relocations) == 25
    pending_high = {}
    for relocation in relocations:
        offset, kind = relocation["r_offset"], relocation["r_info_type"]
        symbol = symbols.get_symbol(relocation["r_info_sym"])
        target = symbol_address(symbol)
        word = struct.unpack_from("<I", code, offset)[0]
        if kind == R_MIPS_26:
            value = target + ((word & 0x3FFFFFF) << 2)
            assert (value & 0xF0000000) == ((START_ADDRESS + offset) & 0xF0000000)
            word = (word & 0xFC000000) | ((value >> 2) & 0x3FFFFFF)
        elif kind == R_MIPS_HI16:
            assert symbol.name not in pending_high
            pending_high[symbol.name] = (offset, word)
            continue
        elif kind == R_MIPS_LO16:
            high_offset, high_word = pending_high.pop(symbol.name)
            low = struct.unpack("<h", struct.pack("<H", word & 0xFFFF))[0]
            value = target + ((high_word & 0xFFFF) << 16) + low
            high_word = (high_word & 0xFFFF0000) | (((value + 0x8000) >> 16) & 0xFFFF)
            struct.pack_into("<I", code, high_offset, high_word)
            word = (word & 0xFFFF0000) | (value & 0xFFFF)
        elif kind == R_MIPS_GPREL16:
            addend = struct.unpack("<h", struct.pack("<H", word & 0xFFFF))[0]
            value = target + addend - GP
            assert -0x8000 <= value < 0x8000
            word = (word & 0xFFFF0000) | (value & 0xFFFF)
        else:
            raise AssertionError(f"unhandled relocation type {kind} at {offset:#x}")
        struct.pack_into("<I", code, offset, word)
    assert not pending_high


@pytest.fixture(scope="module")
def original_image():
    require_private_inputs()
    image = ORIGINAL.read_bytes()
    assert hashlib.sha1(image).hexdigest() == ORIGINAL_SHA1, "AOK.ELF SHA1 mismatch"
    return image


@pytest.fixture(scope="module")
def relocated_code(tmp_path_factory):
    path = compile_object(tmp_path_factory.mktemp("session_dispatch"))
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        symtab = elf.get_section_by_name(".symtab")
        functions = symtab.get_symbol_by_name(FUNCTION_NAME)
        assert functions is not None and len(functions) == 1
        function = functions[0]
        assert function["st_info"]["type"] == "STT_FUNC"
        assert function["st_size"] == FUNCTION_SIZE
        undefined = {symbol.name for symbol in symtab.iter_symbols()
                     if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"}
        assert undefined == set(EXTERNAL_SYMBOLS)
        section_index = function["st_shndx"]
        offset = function["st_value"]
        code = bytearray(elf.get_section(section_index).data()[offset:offset + FUNCTION_SIZE])
        apply_relocations(elf, section_index, code)
    return bytes(code)


def test_session_dispatch_matches_original(relocated_code, original_image):
    expected = virtual_bytes(original_image, START_ADDRESS, FUNCTION_SIZE)
    difference = next((i for i, pair in enumerate(zip(relocated_code, expected))
                       if pair[0] != pair[1]), None)
    assert difference is None, f"instruction bytes differ at {START_ADDRESS + difference:#x}"


@pytest.mark.parametrize("address,content", sorted(STRINGS.items()))
def test_session_command_strings(address, content, original_image):
    assert virtual_bytes(original_image, address, len(content)) == content


def test_session_dispatch_has_zero_alignment_padding(original_image):
    assert virtual_bytes(original_image, START_ADDRESS + FUNCTION_SIZE, 12) == b"\0" * 12
