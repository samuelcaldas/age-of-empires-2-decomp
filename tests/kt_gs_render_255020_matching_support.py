from __future__ import annotations

from pathlib import Path

TARGET_ELF_PATH = Path("orig/SLES-50282/AOK.ELF")
BUILT_OBJECT_PATH = Path("build/SLES-50282/src/kcet/kt_gs_render_255020.o")
VRAM_ADDRESS = 0x00255020
FUNCTION_SIZE = 0x80
SLICER_FILE_OFFSET = 0x155200


def extract_expected_bytes() -> bytes:
    data = TARGET_ELF_PATH.read_bytes()
    return data[SLICER_FILE_OFFSET : SLICER_FILE_OFFSET + FUNCTION_SIZE]


def extract_text_section(obj_path: Path) -> bytes:
    data = obj_path.read_bytes()
    e_shoff = int.from_bytes(data[0x20:0x24], "little")
    e_shentsize = int.from_bytes(data[0x2E:0x30], "little")
    e_shnum = int.from_bytes(data[0x30:0x32], "little")
    e_shstrndx = int.from_bytes(data[0x32:0x34], "little")

    shstr_hdr = e_shoff + e_shstrndx * e_shentsize
    shstr_offset = int.from_bytes(data[shstr_hdr + 0x10 : shstr_hdr + 0x14], "little")

    for i in range(e_shnum):
        hdr = e_shoff + i * e_shentsize
        sh_name = int.from_bytes(data[hdr : hdr + 4], "little")
        name_end = data.find(b"\0", shstr_offset + sh_name)
        name = data[shstr_offset + sh_name : name_end].decode("ascii", errors="replace")
        if name == ".text":
            offset = int.from_bytes(data[hdr + 0x10 : hdr + 0x14], "little")
            size = int.from_bytes(data[hdr + 0x14 : hdr + 0x18], "little")
            return data[offset : offset + size]

    raise ValueError("No .text section found")
