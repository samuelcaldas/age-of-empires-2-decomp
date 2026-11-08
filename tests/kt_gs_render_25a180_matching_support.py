from pathlib import Path
from elftools.elf.elffile import ELFFile

EXPECTED_ELF_PATH = Path("orig/SLES-50282/AOK.ELF")
OBJ_PATH = Path("build/SLES-50282/src/kcet/kt_gs_render_25a180.o")
FILE_OFFSET = 0x15A360
SLICE_SIZE = 0x80

def extract_expected_bytes() -> bytes:
    with open(EXPECTED_ELF_PATH, "rb") as f:
        f.seek(FILE_OFFSET)
        return f.read(SLICE_SIZE)

def extract_compiled_bytes() -> bytes:
    with open(OBJ_PATH, "rb") as f:
        elf = ELFFile(f)
        data = bytearray()
        for sym_name, sym_size in [("func_0025A180", 0x30), ("func_0025A1B0", 0x30), ("func_0025A1E0", 0x20)]:
            sec = None
            for s in elf.iter_sections():
                if s.name == f".text.{sym_name}" or (s.name == ".text" and sec is None):
                    sec = s
            # In MWCC, each asm void may generate a .text section or all in .text
            # Let's check sections or concatenate
        # If all in .text sections:
        text_sections = [s for s in elf.iter_sections() if s.name.startswith(".text")]
        if len(text_sections) == 1:
            return text_sections[0].data()[:SLICE_SIZE]
        for s in text_sections:
            data.extend(s.data())
        return bytes(data)[:SLICE_SIZE]

def matches_expected() -> bool:
    return extract_compiled_bytes() == extract_expected_bytes()
