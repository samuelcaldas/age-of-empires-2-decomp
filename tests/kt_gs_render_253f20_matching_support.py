from pathlib import Path
from elftools.elf.elffile import ELFFile

TARGET_ELF_PATH = Path("orig/SLES-50282/AOK.ELF")
BUILT_OBJECT_PATH = Path("build/SLES-50282/src/kcet/kt_gs_render_253f20.o")
VRAM_ADDRESS = 0x00253F20
SLICE_SIZE = 0xB0
SLICER_FILE_OFFSET = 0x154100


def extract_expected_bytes() -> bytes:
    data = TARGET_ELF_PATH.read_bytes()
    return data[SLICER_FILE_OFFSET : SLICER_FILE_OFFSET + SLICE_SIZE]


def extract_compiled_bytes() -> bytes:
    if not BUILT_OBJECT_PATH.exists():
        return b""
    with open(BUILT_OBJECT_PATH, "rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name('.symtab')
        data = bytearray()
        for func_name in ["func_00253F20", "func_00253F90"]:
            sym = symtab.get_symbol_by_name(func_name)[0]
            sec = elf.get_section(sym['st_shndx'])
            data.extend(sec.data()[:sym['st_size']])
        return bytes(data)
