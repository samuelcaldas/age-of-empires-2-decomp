"""Verify Block 60 literal instructions without editing generated targets."""

import hashlib
from io import BytesIO
from itertools import chain
from pathlib import Path
import struct

from elftools.elf.elffile import ELFFile


FUNCTION_NAME = "func_001F2320"
FUNCTION_ADDRESS = 0x1F2320
CODE_SIZE = 0x178
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
CALL_ADDRESSES = {
    "func_1F21E0": 0x1F21E0,
    "func_001F21E0": 0x1F21E0,
}
EXPECTED_RELOCATIONS = (
    (0x28, 4, 0x1F21E0),
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
        raise ValueError("Expected a Block 60 symbol table")
    symbols = table.get_symbol_by_name(FUNCTION_NAME)
    if not symbols or len(symbols) != 1:
        raise ValueError("Expected exactly one Block 60 function symbol")
    symbol = symbols[0]
    if not isinstance(symbol["st_shndx"], int):
        raise ValueError("Block 60 function must own an ELF section")
    return symbol


def _external_address(symbol):
    if symbol.name not in CALL_ADDRESSES:
        raise ValueError(f"Unexpected external relocation: {symbol.name}")
    return CALL_ADDRESSES[symbol.name]


def _source_address(elf, symbol):
    if symbol["st_shndx"] == "SHN_UNDEF":
        return _external_address(symbol)
    raise ValueError(f"Unexpected local relocation in Block 60: {symbol.name}")


def _section_records(elf, section, function):
    symbols = elf.get_section(section["sh_link"])
    records = []
    for entry in section.iter_relocations():
        symbol = symbols.get_symbol(entry["r_info_sym"])
        records.append({
            "offset": entry["r_offset"] - function["st_value"],
            "type": entry["r_info_type"],
            "symbol": symbol.name,
            "address": _source_address(elf, symbol),
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


def _target_section_records(elf, section, function):
    symbols = elf.get_section(section["sh_link"])
    records = []
    for entry in section.iter_relocations():
        symbol = symbols.get_symbol(entry["r_info_sym"])
        records.append({
            "offset": entry["r_offset"] - function["st_value"],
            "type": entry["r_info_type"],
            "symbol": symbol.name,
        })
    return records


def _target_records(path):
    elf = ELFFile(BytesIO(Path(path).read_bytes()))
    function = _function(elf)
    sections = [
        section for section in elf.iter_sections()
        if section["sh_type"] == "SHT_REL"
        and section["sh_info"] == function["st_shndx"]
    ]
    return list(chain.from_iterable(
        _target_section_records(elf, section, function) for section in sections
    ))


def _identities(records):
    return [
        (entry["offset"], entry["type"], entry["symbol"])
        for entry in records
    ]


def _target_literal_match(path, expected, records_equal):
    if not records_equal:
        return False
    code, _ = _compiled_function(path)
    return code == expected


def _evidence(code, expected, records, target_records, target_match):
    equal = _identities(records) == _identities(target_records)
    return {
        "code_bytes": len(code),
        "literal_match": code == expected,
        "source_relocations": records,
        "target_relocations": target_records,
        "relocation_records_equal": equal,
        "target_literal_checked": equal,
        "target_literal_match": target_match,
        "strict_match": code == expected and equal and target_match,
        "resolved_sha256": hashlib.sha256(code).hexdigest(),
        "original_sha256": hashlib.sha256(expected).hexdigest(),
    }


def verify(source_path, target_path, original_path):
    """Verify three ELF paths; raise ValueError for unverified records."""
    original = _original_elf(original_path)
    expected = _read_address(original, FUNCTION_ADDRESS, CODE_SIZE)
    code, records = _compiled_function(source_path)
    target_records = _target_records(target_path)
    equal = _identities(records) == _identities(target_records)
    target_match = _target_literal_match(target_path, expected, equal)
    return _evidence(code, expected, records, target_records, target_match)
