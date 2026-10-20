"""Verify Block 61 literal instructions against the original PS2 ELF."""

import hashlib
from io import BytesIO
from pathlib import Path

from elftools.elf.elffile import ELFFile


FUNCTION_NAME = "func_001F24A0"
FUNCTION_ADDRESS = 0x1F24A0
CODE_SIZE = 0x3C
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"


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
        raise ValueError("Expected a Block 61 symbol table")
    symbols = table.get_symbol_by_name(FUNCTION_NAME)
    if not symbols or len(symbols) != 1:
        raise ValueError("Expected exactly one Block 61 function symbol")
    symbol = symbols[0]
    if not isinstance(symbol["st_shndx"], int):
        raise ValueError("Block 61 function must own an ELF section")
    return symbol


def _source_records(elf, function):
    records = []
    shndx = function["st_shndx"]
    symbols = elf.get_section_by_name(".symtab")
    for section in elf.iter_sections():
        if section["sh_type"] == "SHT_REL" and section["sh_info"] == shndx:
            for entry in section.iter_relocations():
                dep = symbols.get_symbol(entry["r_info_sym"])
                records.append({
                    "offset": entry["r_offset"] - function["st_value"],
                    "type": entry["r_info_type"],
                    "symbol": dep.name,
                })
    return records


def _compiled_function(path):
    elf = ELFFile(BytesIO(Path(path).read_bytes()))
    function = _function(elf)
    section = elf.get_section(function["st_shndx"])
    start = function["st_value"]
    code = section.data()[start:start + function["st_size"]]
    records = _source_records(elf, function)
    if len(code) != CODE_SIZE:
        raise ValueError(f"Unexpected compiled function size: {len(code)}")
    return code, records


def verify(source_path, original_path):
    """Verify Block 61 compiled bytes against the original binary."""
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
