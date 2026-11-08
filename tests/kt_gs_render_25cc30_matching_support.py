from pathlib import Path
from elftools.elf.elffile import ELFFile

EXPECTED_VRAM = 0x0025CC30
EXPECTED_SIZE = 0x140
ELF_OFFSET = EXPECTED_VRAM - 0x000FFE20

def get_expected_bytes():
    elf_path = Path("orig/SLES-50282/AOK.ELF")
    with open(elf_path, "rb") as f:
        f.seek(ELF_OFFSET)
        return f.read(EXPECTED_SIZE)

def extract_compiled_bytes(obj_path):
    with open(obj_path, "rb") as f:
        elf = ELFFile(f)
        text_bytes = bytearray()
        for sec in elf.iter_sections():
            if sec.name == ".text" or sec.name.startswith(".text."):
                text_bytes.extend(sec.data())
        return bytes(text_bytes)
