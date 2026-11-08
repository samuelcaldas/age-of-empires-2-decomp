from pathlib import Path
from elftools.elf.elffile import ELFFile

REPO_ROOT = Path(__file__).resolve().parent.parent

def extract_target_bytes() -> bytes:
    elf_path = REPO_ROOT / "orig" / "SLES-50282" / "AOK.ELF"
    with open(elf_path, "rb") as f:
        f.seek(0x157C70)
        return f.read(0x340)

def extract_compiled_bytes() -> bytes:
    obj_path = REPO_ROOT / "build" / "SLES-50282" / "src" / "kcet" / "kt_gs_render_257a90.o"
    with open(obj_path, "rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        funcs = ["func_00257A90", "func_00257DC0"]
        out = bytearray()
        for func_name in funcs:
            matches = symtab.get_symbol_by_name(func_name)
            sym = matches[0]
            sec = elf.get_section(sym['st_shndx'])
            out.extend(sec.data()[:sym['st_size']])
        return bytes(out)
