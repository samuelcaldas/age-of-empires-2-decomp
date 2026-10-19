"""Measure isolated, relocation-resolved matching for trade_action_helper_21B880."""

from hashlib import sha1
from io import BytesIO
from pathlib import Path
import runpy
import struct
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

START = 0x21B880
SIZE = 0x254  # 596 bytes executable code extent
FUNCTION = "func_0021B880"
EXTERNALS = {
    "func_0021B830": 0x21B830,
}


def test_helper_21b880_relocation_resolved_comparison(tmp_path):
    """Compile C++, resolve call relocations, and measure against 596 original code bytes."""
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER, LINKER) if not path.is_file()]
    if missing:
        pytest.skip(f"requires private original ELF and PS2 tools: {missing}")
    data = ORIGINAL.read_bytes()
    assert sha1(data).hexdigest() == "f478e19f2059d52899b691483ef5c7522e30e17c"
    reference = ELFFile(BytesIO(data))

    candidate = tmp_path / "helper_21B880.o"
    subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         "src/trade_action_helper_21B880.cpp", "-o", str(candidate)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=60,
    )
    compiled = ELFFile(BytesIO(candidate.read_bytes()))
    table = compiled.get_section_by_name(".symtab")
    function = unique_symbol(table, FUNCTION)

    undefined = {s.name for s in table.iter_symbols()
                 if s.name and s["st_shndx"] == "SHN_UNDEF"}
    assert undefined == set(EXTERNALS)

    renamed = tmp_path / "helper_21B880-renamed.o"
    indices = rename_text_sections(candidate, renamed)
    assert indices == [function["st_shndx"]], "unexpected private executable sections"
    executable = [i for i, s in enumerate(compiled.iter_sections()) if s["sh_flags"] & 0x4]
    assert executable == [function["st_shndx"]], "unexpected non-.text executable section"

    definitions = "".join(f"{name} = {address:#x};\n" for name, address in EXTERNALS.items())
    script = tmp_path / "helper_21B880.ld"
    script.write_text(definitions + f"_gp = 0x4EA7C0;\nSECTIONS {{\n"
                      f".text_b880 {START:#x} : {{ *(.text_{indices[0]}) }}\n"
                      "/DISCARD/ : { *(*) }\n}\n")
    linked = tmp_path / "helper_21B880.elf"
    subprocess.run(
        [str(LINKER), "-EL", "-m", "elf32ltsmip", "--no-undefined",
         "-T", str(script), "-o", str(linked), str(renamed)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=30,
    )
    result = ELFFile(BytesIO(linked.read_bytes()))
    symbols = result.get_section_by_name(".symtab")
    assert not [s.name for s in symbols.iter_symbols() if s.name and s["st_shndx"] == "SHN_UNDEF"]

    loads = [seg for seg in reference.iter_segments()
             if seg["p_type"] == "PT_LOAD" and seg["p_vaddr"] <= START
             and START + SIZE <= seg["p_vaddr"] + seg["p_filesz"]]
    assert len(loads) == 1
    offset = loads[0]["p_offset"] + START - loads[0]["p_vaddr"]
    target = data[offset:offset + SIZE]

    entry = unique_symbol(symbols, FUNCTION)
    assert entry["st_value"] == START
    sec = result.get_section(entry["st_shndx"])
    code = sec.data()

    # Verify code length (588 bytes generated vs 596 original, 8 bytes shorter)
    assert len(code) == 588
    assert len(target) == 596

    # Verify identical suffix from 0x1E4 (cand) / 0x1EC (target) through end of function
    assert code[0x1E4:] == target[0x1EC:]

    # Verify instructions before format branch (0x000 to 0x1B8) match, modulo relative branch offsets
    branch_offsets = {0x4C, 0x144, 0x194, 0x1A0, 0x1AC}
    for i in range(0, 0x1B8, 4):
        if i in branch_offsets:
            continue
        wo = struct.unpack("<I", target[i:i + 4])[0]
        wc = struct.unpack("<I", code[i:i + 4])[0]
        assert wo == wc, f"instruction mismatch at offset {hex(i)}"
