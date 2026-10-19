"""Verify func_001F28A0 instructions against the original PS2 ELF."""

import hashlib
from io import BytesIO
from pathlib import Path

from elftools.elf.elffile import ELFFile


FUNCTION_NAME = "func_001F28A0"
FUNCTION_ADDRESS = 0x1F28A0
CODE_SIZE = 0x58  # 88 bytes (21 instructions + delay slot nop at 0x1F28F4)
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
        raise ValueError("Expected a symbol table")
    symbols = table.get_symbol_by_name(FUNCTION_NAME)
    if not symbols or len(symbols) != 1:
        raise ValueError(f"Expected exactly one symbol for {FUNCTION_NAME}")
    symbol = symbols[0]
    if symbol["st_info"]["type"] != "STT_FUNC":
        raise ValueError(f"{FUNCTION_NAME} symbol must be a function")
    if not isinstance(symbol["st_shndx"], int) or symbol["st_shndx"] >= elf.num_sections():
        raise ValueError(f"{FUNCTION_NAME} function must own an ELF section")
    return symbol


def _compiled_function(path):
    elf = ELFFile(BytesIO(Path(path).read_bytes()))
    function = _function(elf)
    section = elf.get_section(function["st_shndx"])
    start = function["st_value"]
    code = section.data()[start:start + function["st_size"]]
    if len(code) != CODE_SIZE:
        raise ValueError(f"Unexpected compiled function size: {len(code)}")
    # Verify zero relocations for leaf function
    rel_sections = [
        s for s in elf.iter_sections()
        if s["sh_type"] == "SHT_REL" and s["sh_info"] == function["st_shndx"]
    ]
    rel_count = sum(s.num_relocations() for s in rel_sections)
    if rel_count != 0:
        raise ValueError(f"Expected 0 relocations for {FUNCTION_NAME}")
    return code


def verify(source_path, original_path):
    """Verify func_001F28A0 compiled bytes against original binary."""
    original = _original_elf(original_path)
    expected = _read_address(original, FUNCTION_ADDRESS, CODE_SIZE)
    code = _compiled_function(source_path)
    return {
        "code_bytes": len(code),
        "literal_match": code == expected,
        "relocation_count": 0,
        "resolved_sha256": hashlib.sha256(code).hexdigest(),
        "original_sha256": hashlib.sha256(expected).hexdigest(),
    }
