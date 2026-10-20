"""Pinned original-executable facts for Block 59 verification."""

import hashlib
from io import BytesIO
from pathlib import Path

from elftools.elf.elffile import ELFFile


FUNCTION_NAME = "func_001F21E0"
FUNCTION_ADDRESS = 0x1F21E0
CODE_SIZE = 0x134
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
STRING_ADDRESSES = {
    b"%s(%d) Used_Zones == Max_Zones(%d)\n\0": 0x492790,
    b"obmanager.cpp\0": 0x492740,
}
CALL_ADDRESSES = {"func_118de0": 0x118DE0, "func_117CAC": 0x117CAC}
EXPECTED_RELOCATIONS = (
    (0x3C, 5, 0x492790), (0x40, 6, 0x492790),
    (0x44, 5, 0x492740), (0x48, 6, 0x492740),
    (0x4C, 4, 0x118DE0), (0x94, 4, 0x117CAC),
)


def _original_elf(path):
    data = Path(path).read_bytes()
    if hashlib.sha1(data).hexdigest() != ORIGINAL_SHA1:
        raise ValueError("Original executable SHA-1 does not match SLES-50282")
    elf = ELFFile(BytesIO(data))
    for text, address in STRING_ADDRESSES.items():
        _check_original_string(elf, text, address)
    return elf


def _read_address(elf, address, size):
    segments = [segment for segment in elf.iter_segments()
                if segment["p_type"] == "PT_LOAD"
                and segment["p_vaddr"] <= address
                and address + size <= segment["p_vaddr"] + segment["p_filesz"]]
    if len(segments) != 1:
        raise ValueError(
            f"Original range is not uniquely loaded: {address:#x}"
        )
    segment = segments[0]
    offset = address - segment["p_vaddr"]
    return segment.data()[offset:offset + size]


def _check_original_string(elf, text, address):
    payloads = [segment.data() for segment in elf.iter_segments()
                if segment["p_type"] == "PT_LOAD"]
    occurrences = sum(payload.count(text) for payload in payloads)
    if occurrences != 1 or _read_address(elf, address, len(text)) != text:
        raise ValueError(
            f"Original string is not uniquely verified: {address:#x}"
        )


def read_original_code(path):
    """Read pinned original bytes; raise ValueError for invalid inputs."""
    original = _original_elf(path)
    return _read_address(original, FUNCTION_ADDRESS, CODE_SIZE)
