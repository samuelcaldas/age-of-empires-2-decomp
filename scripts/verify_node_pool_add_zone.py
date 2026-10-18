"""Verify Block 59 literal instructions without editing generated targets."""

import hashlib
from io import BytesIO
from itertools import chain
from pathlib import Path
import struct

from elftools.elf.elffile import ELFFile

from scripts.node_pool_original import (
    CALL_ADDRESSES, CODE_SIZE, EXPECTED_RELOCATIONS, FUNCTION_NAME,
    STRING_ADDRESSES, read_original_code,
)


def _function(elf):
    table = elf.get_section_by_name(".symtab")
    if table is None:
        raise ValueError("Expected a Block 59 symbol table")
    symbols = table.get_symbol_by_name(FUNCTION_NAME)
    if not symbols or len(symbols) != 1:
        raise ValueError("Expected exactly one Block 59 function symbol")
    symbol = symbols[0]
    if not isinstance(symbol["st_shndx"], int):
        raise ValueError("Block 59 function must own an ELF section")
    return symbol


def _external_address(symbol):
    if symbol.name not in CALL_ADDRESSES:
        raise ValueError(f"Unexpected external relocation: {symbol.name}")
    return CALL_ADDRESSES[symbol.name]


def _source_address(elf, symbol):
    if symbol["st_shndx"] == "SHN_UNDEF":
        return _external_address(symbol)
    if not isinstance(symbol["st_shndx"], int):
        raise ValueError(f"Unexpected relocation section: {symbol.name}")
    section = elf.get_section(symbol["st_shndx"])
    payload = section.data()[symbol["st_value"]:]
    text = payload.split(b"\0", 1)[0] + b"\0"
    if text not in STRING_ADDRESSES:
        raise ValueError(f"Unverified local relocation string: {symbol.name}")
    return STRING_ADDRESSES[text]


def _section_records(elf, section, function):
    symbols = elf.get_section(section["sh_link"])
    records = []
    for entry in section.iter_relocations():
        symbol = symbols.get_symbol(entry["r_info_sym"])
        records.append({
            "offset": entry["r_offset"] - function["st_value"],
            "type": entry["r_info_type"], "symbol": symbol.name,
            "address": _source_address(elf, symbol),
        })
    return records


def _source_records(elf, function):
    sections = [section for section in elf.iter_sections()
                if section["sh_type"] == "SHT_REL"
                and section["sh_info"] == function["st_shndx"]]
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
        records.append({"offset": entry["r_offset"] - function["st_value"],
                        "type": entry["r_info_type"], "symbol": symbol.name})
    return records


def _target_records(path):
    elf = ELFFile(BytesIO(Path(path).read_bytes()))
    function = _function(elf)
    sections = [section for section in elf.iter_sections()
                if section["sh_type"] == "SHT_REL"
                and section["sh_info"] == function["st_shndx"]]
    return list(chain.from_iterable(
        _target_section_records(elf, section, function) for section in sections
    ))


def _identities(records):
    return [(entry["offset"], entry["type"], entry["symbol"])
            for entry in records]


def _target_literal_match(path, expected, records_equal):
    if not records_equal:
        return False
    code, _ = _compiled_function(path)
    return code == expected


def _evidence(code, expected, records, target_records, target_match):
    equal = _identities(records) == _identities(target_records)
    return {
        "code_bytes": len(code), "literal_match": code == expected,
        "source_relocations": records, "target_relocations": target_records,
        "relocation_records_equal": equal,
        "target_literal_checked": equal, "target_literal_match": target_match,
        "strict_match": code == expected and equal and target_match,
        "resolved_sha256": hashlib.sha256(code).hexdigest(),
        "original_sha256": hashlib.sha256(expected).hexdigest(),
    }


def verify(source_path, target_path, original_path):
    """Verify three ELF paths; raise ValueError for unverified records."""
    expected = read_original_code(original_path)
    code, records = _compiled_function(source_path)
    target_records = _target_records(target_path)
    equal = _identities(records) == _identities(target_records)
    target_match = _target_literal_match(target_path, expected, equal)
    return _evidence(code, expected, records, target_records, target_match)
