"""Verify ZoneSpatialGrid setter instructions against original PS2 ELF."""

import hashlib
from io import BytesIO
from pathlib import Path

from elftools.elf.elffile import ELFFile


ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
SETTERS = (
    ("func_001F2AB0", 0x1F2AB0, 8),
    ("func_001F2AC0", 0x1F2AC0, 8),
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


def _get_function_symbol(elf, name):
    table = elf.get_section_by_name(".symtab")
    if table is None:
        raise ValueError("Missing symbol table in compiled object")
    symbols = table.get_symbol_by_name(name)
    if not symbols or len(symbols) != 1:
        raise ValueError(f"Expected exactly one symbol for {name}")
    sym = symbols[0]
    if sym["st_info"]["type"] != "STT_FUNC":
        raise ValueError(f"Symbol {name} must be a function")
    if not isinstance(sym["st_shndx"], int) or sym["st_shndx"] >= elf.num_sections():
        raise ValueError(f"Function {name} must own an ELF section")
    return sym


def _compiled_function_bytes(elf, name, expected_size):
    sym = _get_function_symbol(elf, name)
    section = elf.get_section(sym["st_shndx"])
    start = sym["st_value"]
    code = section.data()[start:start + sym["st_size"]]
    if len(code) != expected_size:
        raise ValueError(
            f"Unexpected size for {name}: {len(code)} != {expected_size}"
        )
    rel_sections = [
        s for s in elf.iter_sections()
        if s["sh_type"] == "SHT_REL" and s["sh_info"] == sym["st_shndx"]
    ]
    rel_count = sum(s.num_relocations() for s in rel_sections)
    if rel_count != 0:
        raise ValueError(f"Expected 0 relocations for leaf setter {name}")
    return code


def verify(source_path, original_path):
    """Verify each setter against its exact 8-byte code extent in AOK.ELF."""
    original = _original_elf(original_path)
    source_elf = ELFFile(BytesIO(Path(source_path).read_bytes()))

    results = []
    all_matched = True
    total_bytes = 0

    for name, address, size in SETTERS:
        expected = _read_address(original, address, size)
        code = _compiled_function_bytes(source_elf, name, size)
        matched = (code == expected)
        if not matched:
            all_matched = False
        total_bytes += len(code)
        results.append({
            "name": name,
            "address": address,
            "size": len(code),
            "matched": matched,
            "resolved_sha256": hashlib.sha256(code).hexdigest(),
            "original_sha256": hashlib.sha256(expected).hexdigest(),
        })

    return {
        "all_matched": all_matched,
        "total_code_bytes": total_bytes,
        "setters": results,
    }
