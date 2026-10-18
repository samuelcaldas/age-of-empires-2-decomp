"""Preserve the complete, relocation-resolved C++ dispatch match at 0x21DE90."""

from hashlib import sha1
from io import BytesIO
from pathlib import Path
import runpy
import subprocess

from elftools.elf.elffile import ELFFile
import pytest

ROOT = Path(__file__).resolve().parents[1]
ELF_PROOF = runpy.run_path(str(ROOT / "tests/verify_trade_action_helper_2184D0_elf.py"))
rename_text_sections = ELF_PROOF["rename_text_sections"]
unique_symbol = ELF_PROOF["unique_symbol"]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
LINKER = ROOT / "build/mips_binutils/mips-linux-gnu-ld"
START = 0x21DE90
SIZE = 0xC0
FUNCTION = "func_0021DE90"
EXTERNALS = {"func_0021DF50": 0x21DF50, "func_221B60": 0x221B60, "func_221AC0": 0x221AC0}


def test_dispatch_matches_complete_original_function(tmp_path):
    """Compile C++, resolve every call relocation, and compare all 192 original bytes."""
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER, LINKER) if not path.is_file()]
    if missing:
        pytest.skip(f"requires private original ELF and PS2 tools: {missing}")
    data = ORIGINAL.read_bytes()
    assert sha1(data).hexdigest() == "f478e19f2059d52899b691483ef5c7522e30e17c"
    reference = ELFFile(BytesIO(data))
    loads = [segment for segment in reference.iter_segments()
             if segment["p_type"] == "PT_LOAD" and segment["p_vaddr"] <= START
             and START + SIZE <= segment["p_vaddr"] + segment["p_filesz"]]
    assert len(loads) == 1
    offset = loads[0]["p_offset"] + START - loads[0]["p_vaddr"]
    assert offset == 0x11E070
    expected = data[offset:offset + SIZE]
    candidate = tmp_path / "dispatch.o"
    subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         "src/trade_action_helper_21DE90.cpp", "-o", str(candidate)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=60,
    )
    compiled = ELFFile(BytesIO(candidate.read_bytes()))
    table = compiled.get_section_by_name(".symtab")
    function = unique_symbol(table, FUNCTION)
    assert function["st_size"] == SIZE, "candidate function extent differs from the original"
    undefined = {symbol.name for symbol in table.iter_symbols()
                 if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"}
    assert undefined == set(EXTERNALS)
    renamed = tmp_path / "dispatch-renamed.o"
    indices = rename_text_sections(candidate, renamed)
    assert indices == [function["st_shndx"]], "unexpected private executable sections"
    definitions = "".join(f"{name} = {address:#x};\n" for name, address in EXTERNALS.items())
    script = tmp_path / "dispatch.ld"
    script.write_text(definitions + "_gp = 0x4EA7C0;\n"
                      + f"SECTIONS {{ .entry {START:#x} : {{ *(.text_{indices[0]}) }} "
                      + "/DISCARD/ : { *(*) } }\n")
    linked = tmp_path / "dispatch.elf"
    subprocess.run(
        [str(LINKER), "-EL", "-m", "elf32ltsmip", "--no-undefined",
         "-T", str(script), "-o", str(linked), str(renamed)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=30,
    )
    result = ELFFile(BytesIO(linked.read_bytes()))
    symbols = result.get_section_by_name(".symtab")
    assert not [symbol.name for symbol in symbols.iter_symbols()
                if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"]
    entry = unique_symbol(symbols, FUNCTION)
    assert entry["st_value"] == START
    assert entry["st_size"] == SIZE
    section = result.get_section(entry["st_shndx"])
    assert section["sh_addr"] == START
    assert section.data() == expected
