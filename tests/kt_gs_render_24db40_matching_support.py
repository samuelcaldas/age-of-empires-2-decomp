from pathlib import Path
import subprocess
from elftools.elf.elffile import ELFFile

REPO_ROOT = Path(__file__).resolve().parent.parent
ORIG_ELF = REPO_ROOT / "orig" / "SLES-50282" / "AOK.ELF"
MWCC = REPO_ROOT / "compilers" / "PS2" / "mwcc-2.3.1.01" / "mwccps2.exe"
WIBO = REPO_ROOT / "build" / "tools" / "wibo"

FUNCTIONS = {
    "func_0024DB40": (0x0024DB40, 0xD0),
}

def require_original():
    assert ORIG_ELF.exists(), f"Original binary not found at {ORIG_ELF}"

def require_compiler():
    assert MWCC.exists(), f"MWCC compiler not found at {MWCC}"
    assert WIBO.exists(), f"wibo not found at {WIBO}"

def compile_source(obj_path: Path):
    src = REPO_ROOT / "src" / "kcet" / "kt_gs_render_24db40.cpp"
    cmd = [
        str(WIBO),
        str(MWCC),
        "-O3",
        "-inline", "on",
        "-msext", "on",
        "-char", "signed",
        "-sym", "off",
        "-Iinclude",
        "-lang=c++",
        "-c",
        str(src),
        "-o",
        str(obj_path),
    ]
    subprocess.run(cmd, check=True, cwd=REPO_ROOT, capture_output=True, text=True)

def read_original_bytes(vram: int, size: int) -> bytes:
    offset = vram - 0x000FFE20
    with open(ORIG_ELF, "rb") as f:
        f.seek(offset)
        return f.read(size)

def extract_function_bytes(obj_path: Path, name: str) -> bytes:
    with open(obj_path, "rb") as f:
        elf = ELFFile(f)
        text = elf.get_section_by_name(".text")
        return text.data()[:0xD0]
