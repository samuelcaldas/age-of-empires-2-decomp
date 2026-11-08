from pathlib import Path
from elftools.elf.elffile import ELFFile

def extract_target_bytes():
    repo = Path(__file__).resolve().parent.parent
    elf_path = repo / "orig" / "SLES-50282" / "AOK.ELF"
    with open(elf_path, "rb") as f:
        f.seek(0x152800)
        return f.read(0xD0)

def extract_compiled_bytes():
    repo = Path(__file__).resolve().parent.parent
    obj_path = repo / "build" / "SLES-50282" / "src" / "kcet" / "kt_gs_render_252620.o"
    if not obj_path.exists():
        return None
    with open(obj_path, "rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name('.symtab')
        sym = symtab.get_symbol_by_name("func_00252620")[0]
        sec = elf.get_section(sym['st_shndx'])
        return bytes(sec.data()[:sym['st_size']])
