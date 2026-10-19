"""Verify func_001F2EB0 instructions against the original PS2 ELF."""

import hashlib
from io import BytesIO
from itertools import chain
from pathlib import Path
import struct

from elftools.elf.elffile import ELFFile


FUNCTION_NAME = "func_001F2EB0"
FUNCTION_ADDRESS = 0x1F2EB0
CODE_SIZE = 0xCC  # 204 bytes
PADDING_SIZE = 0x04  # 4 bytes trailing NOP padding to 0x1F2F80
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
GP_ADDRESS = 0x4E0000
SYMBOL_ADDRESSES = {
    "func_001F6CA0": 0x1F6CA0,
    "D_004D89C0": 0x4D89C0,
    "D_004D8940": 0x4D8940,
    "D_004D8E18": 0x4D8E18,
    "func_001F2BD0": 0x1F2BD0,
}
EXPECTED_RELOCATIONS = (
    (0x24, 4, 0x1F6CA0),
    (0x74, 7, 0x4D89C0),
    (0x84, 7, 0x4D8940),
    (0x88, 7, 0x4D8E18),
    (0xAC, 4, 0x1F2BD0),
)


def _original_elf(path):
    data = Path(path).read_bytes()
    if hashlib.sha1(data).hexdigest() != ORIGINAL_SHA1:
        raise ValueError("Original executable SHA-1 does not match SLES-50282")
    return ELFFile(BytesIO(data))


def _read_address(elf, address, size):
    if size == 0:
        return b""
    segments = [
        segment for segment in elf.iter_segments()
        if segment["p_type"] == "PT_LOAD"
        and segment["p_vaddr"] <= address
        and address + size <= segment["p_vaddr"] + segment["p_filesz"]
    ]
    if len(segments) != 1:
        raise ValueError(
            f"Original range is not uniquely loaded: {address:#x}"
        )
    segment = segments[0]
    offset = address - segment["p_vaddr"]
    return segment.data()[offset:offset + size]


def _function(elf):
    table = elf.get_section_by_name(".symtab")
    if table is None:
        raise ValueError("Expected a symbol table")
    symbols = table.get_symbol_by_name(FUNCTION_NAME)
    if not symbols or len(symbols) != 1:
        raise ValueError(f"Expected exactly one symbol for {FUNCTION_NAME}")
    symbol = symbols[0]
    if symbol["st_info"]["type"] != "STT_FUNC":
        raise ValueError(f"{FUNCTION_NAME} symbol must be a function")
    if not isinstance(symbol["st_shndx"], int) or symbol["st_shndx"] >= elf.num_sections():
        raise ValueError(f"{FUNCTION_NAME} function must own an ELF section")
    section = elf.get_section(symbol["st_shndx"])
    if section["sh_type"] != "SHT_PROGBITS" or not (section["sh_flags"] & 0x4):
        raise ValueError(f"{FUNCTION_NAME} section must be executable code")
    return symbol


def _source_address(symbol):
    if symbol.name not in SYMBOL_ADDRESSES:
        raise ValueError(f"Unexpected external relocation: {symbol.name}")
    if symbol["st_shndx"] != "SHN_UNDEF" or symbol["st_value"] != 0:
        raise ValueError(f"External relocation symbol must be undefined: {symbol.name}")
    return SYMBOL_ADDRESSES[symbol.name]


def _section_records(elf, section, function):
    symbols = elf.get_section(section["sh_link"])
    records = []
    for entry in section.iter_relocations():
        symbol = symbols.get_symbol(entry["r_info_sym"])
        records.append({
            "offset": entry["r_offset"] - function["st_value"],
            "type": entry["r_info_type"],
            "symbol": symbol.name,
            "address": _source_address(symbol),
        })
    return records


def _source_records(elf, function):
    sections = [
        section for section in elf.iter_sections()
        if section["sh_type"] == "SHT_REL"
        and section["sh_info"] == function["st_shndx"]
    ]
    return list(chain.from_iterable(
        _section_records(elf, section, function) for section in sections
    ))


def _immediate(kind, address):
    if kind == 4:
        return (address >> 2) & 0x3FFFFFF
    if kind == 7:
        return (address - GP_ADDRESS) & 0xFFFF
    raise ValueError(f"Unsupported relocation type: {kind}")


def _relocation_mask(kind):
    if kind == 4:
        return 0x3FFFFFF
    if kind == 7:
        return 0xFFFF
    raise ValueError(f"Unsupported relocation type: {kind}")


def _patch_word(code, record):
    offset = record["offset"]
    if offset < 0 or offset + 4 > len(code):
        raise ValueError(f"Relocation offset out of bounds: {offset:#x}")
    word = struct.unpack_from("<I", code, offset)[0]
    mask = _relocation_mask(record["type"])
    if word & mask:
        raise ValueError(f"Nonzero implicit relocation addend at {offset:#x}")
    value = _immediate(record["type"], record["address"])
    struct.pack_into("<I", code, offset, (word & ~mask) | value)


def _manifest_matches(records):
    actual = tuple(sorted((entry["offset"], entry["type"], entry["address"])
                          for entry in records))
    expected = tuple(sorted(EXPECTED_RELOCATIONS))
    return actual == expected


def _resolve(code, records):
    if not _manifest_matches(records):
        return bytes(code)
    result = bytearray(code)
    for entry in sorted(records, key=lambda r: r["offset"]):
        _patch_word(result, entry)
    return bytes(result)


def _validate_elf_header(elf):
    header = elf.header
    if header["e_ident"]["EI_CLASS"] != "ELFCLASS32":
        raise ValueError("Source ELF must be 32-bit (ELFCLASS32)")
    if header["e_ident"]["EI_DATA"] != "ELFDATA2LSB":
        raise ValueError("Source ELF must be little-endian (ELFDATA2LSB)")
    if header["e_type"] != "ET_REL":
        raise ValueError("Source ELF must be relocatable (ET_REL)")
    if header["e_machine"] != "EM_MIPS":
        raise ValueError("Source ELF machine must be EM_MIPS")


def _compiled_function(path):
    elf = ELFFile(BytesIO(Path(path).read_bytes()))
    _validate_elf_header(elf)
    function = _function(elf)
    section = elf.get_section(function["st_shndx"])
    start = function["st_value"]
    size = function["st_size"]
    sec_data = section.data()
    if start + size > len(sec_data):
        raise ValueError(f"{FUNCTION_NAME} symbol extent exceeds section size")
    code = sec_data[start:start + size]
    records = _source_records(elf, function)
    return _resolve(code, records), records


def verify(source_path, original_path):
    """Verify func_001F2EB0 compiled bytes against original binary."""
    original = _original_elf(original_path)
    expected = _read_address(original, FUNCTION_ADDRESS, CODE_SIZE)
    expected_pad = _read_address(original, FUNCTION_ADDRESS + CODE_SIZE, PADDING_SIZE)
    code, records = _compiled_function(source_path)
    matched = (len(code) == CODE_SIZE and code == expected
               and _manifest_matches(records))
    padding_matched = (len(expected_pad) == PADDING_SIZE and expected_pad == b"\x00" * PADDING_SIZE)
    return {
        "code_bytes": len(code),
        "expected_code_bytes": CODE_SIZE,
        "literal_match": matched,
        "padding_bytes": PADDING_SIZE,
        "original_padding_verified": padding_matched,
        "source_relocations": records,
        "relocation_count": len(records),
        "resolved_sha256": hashlib.sha256(code[:CODE_SIZE]).hexdigest(),
        "original_sha256": hashlib.sha256(expected).hexdigest(),
    }
