from pathlib import Path
from elftools.elf.elffile import ELFFile

EXPECTED_ELF_PATH = Path("orig/SLES-50282/AOK.ELF")
OBJ_PATH = Path("build/SLES-50282/src/kcet/kt_gs_render_25a410.o")
FILE_OFFSET = 0x15A5F0
SLICE_SIZE = 0x1D0

def extract_expected_bytes() -> bytes:
    with open(EXPECTED_ELF_PATH, "rb") as f:
        f.seek(FILE_OFFSET)
        return f.read(SLICE_SIZE)

def extract_compiled_bytes() -> bytes:
    with open(OBJ_PATH, "rb") as f:
        elf = ELFFile(f)
        section = elf.get_section_by_name(".text")
        return section.data()[:SLICE_SIZE]

def matches_expected() -> bool:
    return extract_compiled_bytes() == extract_expected_bytes()
