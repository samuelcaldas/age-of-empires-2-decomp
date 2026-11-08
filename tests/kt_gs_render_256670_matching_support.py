from pathlib import Path
from elftools.elf.elffile import ELFFile

REPO_ROOT = Path(__file__).resolve().parent.parent

def extract_target_bytes() -> bytes:
    elf_path = REPO_ROOT / "orig" / "SLES-50282" / "AOK.ELF"
    with open(elf_path, "rb") as f:
        f.seek(0x156850)
        return f.read(0x190)

def extract_compiled_bytes() -> bytes:
    obj_path = REPO_ROOT / "build" / "SLES-50282" / "src" / "kcet" / "kt_gs_render_256670.o"
    with open(obj_path, "rb") as f:
        elf = ELFFile(f)
        sec = elf.get_section_by_name(".text")
        return sec.data()
