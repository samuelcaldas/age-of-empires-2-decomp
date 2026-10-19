"""Verify Block 62 constructor instructions against the original PS2 ELF."""

import hashlib
from io import BytesIO
from itertools import chain
from pathlib import Path
import struct

from elftools.elf.elffile import ELFFile


FUNCTION_NAME = "func_001F24E0"
FUNCTION_ADDRESS = 0x1F24E0
CODE_SIZE = 0xAC
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
SYMBOL_ADDRESSES = {
    "D_004D9AD0": 0x4D9AD0,
    "func_001F2DA0": 0x1F2DA0,
}
EXPECTED_RELOCATIONS = (
    (0x04, 5, 0x4D9AD0),
    (0x10, 6, 0x4D9AD0),
    (0x90, 4, 0x1F2DA0),
)


def _original_elf(path):
    data = Path(path).read_bytes()
    if hashlib.sha1(data).hexdigest() != ORIGINAL_SHA1:
        raise ValueError("Original executable SHA-1 does not match SLES-50282")
    return ELFFile(BytesIO(data))


def _read_address(elf, address, size):
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
        raise ValueError("Expected a Block 62 symbol table")
    symbols = table.get_symbol_by_name(FUNCTION_NAME)
    if not symbols or len(symbols) != 1:
        raise ValueError("Expected exactly one Block 62 function symbol")
    symbol = symbols[0]
    if not isinstance(symbol["st_shndx"], int):
        raise ValueError("Block 62 function must own an ELF section")
    return symbol


def _source_address(symbol):
    if symbol.name not in SYMBOL_ADDRESSES:
        raise ValueError(f"Unexpected external relocation: {symbol.name}")
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
    if kind == 5:
        return ((address + 0x8000) >> 16) & 0xFFFF
    return address & 0xFFFF


def _relocation_mask(kind):
    if kind == 4:
        return 0x3FFFFFF
    return 0xFFFF


def _patch_word(code, record):
    offset = record["offset"]
    word = struct.unpack_from("<I", code, offset)[0]
    mask = _relocation_mask(record["type"])
    if word & mask:
        raise ValueError(f"Nonzero implicit relocation addend at {offset:#x}")
    value = _immediate(record["type"], record["address"])
    struct.pack_into("<I", code, offset, (word & ~mask) | value)


def _resolve(code, records):
    actual = tuple((entry["offset"], entry["type"], entry["address"])
                   for entry in records)
    if actual != EXPECTED_RELOCATIONS:
        raise ValueError("Unexpected source relocation records")
    result = bytearray(code)
    for entry in records:
        _patch_word(result, entry)
    return bytes(result)


def _compiled_function(path):
    elf = ELFFile(BytesIO(Path(path).read_bytes()))
    function = _function(elf)
    section = elf.get_section(function["st_shndx"])
    start = function["st_value"]
    code = section.data()[start:start + function["st_size"]]
    records = _source_records(elf, function)
    if len(code) != CODE_SIZE:
        raise ValueError(f"Unexpected compiled function size: {len(code)}")
    return _resolve(code, records), records


def verify(source_path, original_path):
    """Verify Block 62 compiled bytes against the original binary."""
    original = _original_elf(original_path)
    expected = _read_address(original, FUNCTION_ADDRESS, CODE_SIZE)
    code, records = _compiled_function(source_path)
    return {
        "code_bytes": len(code),
        "literal_match": code == expected,
        "source_relocations": records,
        "resolved_sha256": hashlib.sha256(code).hexdigest(),
        "original_sha256": hashlib.sha256(expected).hexdigest(),
    }
