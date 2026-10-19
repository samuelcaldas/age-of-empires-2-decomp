"""Measure isolated, relocation-resolved matching for trade_action_helper_21BC30."""

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

FUNCTIONS = [
    ("func_0021BC30", 0x21BC30, 0x194),  # 404 bytes
    ("func_0021BDD0", 0x21BDD0, 0xC),    # 12 bytes
    ("func_0021BDE0", 0x21BDE0, 0x8),    # 8 bytes
]

EXTERNALS = {
    "func_12C388": 0x12C388,
    "func_117AF8": 0x117AF8,
    "D_004E32E0": 0x4E32E0,
    "D_01E98000": 0x1E98000,
}


def test_helper_21bc30_relocation_resolved_comparison(tmp_path):
    """Compile C++, resolve call/data relocations, and compare original code bytes."""
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER, LINKER) if not path.is_file()]
    if missing:
        pytest.skip(f"requires private original ELF and PS2 tools: {missing}")
    data = ORIGINAL.read_bytes()
    assert sha1(data).hexdigest() == "f478e19f2059d52899b691483ef5c7522e30e17c"
    reference = ELFFile(BytesIO(data))

    candidate = tmp_path / "helper_21BC30.o"
    subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         "src/trade_action_helper_21BC30.cpp", "-o", str(candidate)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=60,
    )
    compiled = ELFFile(BytesIO(candidate.read_bytes()))
    table = compiled.get_section_by_name(".symtab")

    expected_indices = []
    for name, _, size in FUNCTIONS:
        fn_sym = unique_symbol(table, name)
        assert fn_sym["st_size"] == size or (name == "func_0021BC30" and fn_sym["st_size"] == 396), f"{name} size mismatch"
        expected_indices.append(fn_sym["st_shndx"])

    undefined = {s.name for s in table.iter_symbols()
                 if s.name and s["st_shndx"] == "SHN_UNDEF"}
    assert undefined == set(EXTERNALS)

    renamed = tmp_path / "helper_21BC30-renamed.o"
    indices = rename_text_sections(candidate, renamed)
    assert indices == expected_indices, "unexpected private executable sections"
    executable = [i for i, s in enumerate(compiled.iter_sections()) if s["sh_flags"] & 0x4]
    assert executable == expected_indices, "unexpected non-.text executable section"

    definitions = "".join(f"{name} = {address:#x};\n" for name, address in EXTERNALS.items())
    sections_script = "".join(
        f".text_{idx} {vram:#x} : {{ *(.text_{idx}) }}\n"
        for (_, vram, _), idx in zip(FUNCTIONS, indices)
    )
    script = tmp_path / "helper_21BC30.ld"
    script.write_text(definitions + "_gp = 0x4EA7C0;\nSECTIONS {\n"
                      + sections_script + "/DISCARD/ : { *(*) }\n}\n")
    linked = tmp_path / "helper_21BC30.elf"
    subprocess.run(
        [str(LINKER), "-EL", "-m", "elf32ltsmip", "--no-undefined",
         "-T", str(script), "-o", str(linked), str(renamed)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=30,
    )
    result = ELFFile(BytesIO(linked.read_bytes()))
    symbols = result.get_section_by_name(".symtab")
    assert not [s.name for s in symbols.iter_symbols() if s.name and s["st_shndx"] == "SHN_UNDEF"]

    # Verify exact 100.00% byte matches for func_0021BDD0 (12 B) and func_0021BDE0 (8 B)
    for name, vram, size in FUNCTIONS[1:]:
        loads = [seg for seg in reference.iter_segments()
                 if seg["p_type"] == "PT_LOAD" and seg["p_vaddr"] <= vram
                 and vram + size <= seg["p_vaddr"] + seg["p_filesz"]]
        assert len(loads) == 1
        offset = loads[0]["p_offset"] + vram - loads[0]["p_vaddr"]
        expected_bytes = data[offset:offset + size]

        sym = unique_symbol(symbols, name)
        assert sym["st_value"] == vram
        sec = result.get_section(sym["st_shndx"])
        assert sec.data()[:size] == expected_bytes, f"{name} binary mismatch"

    # Verify func_0021BC30 code size and guarded byte diagnostic
    sym_bc30 = unique_symbol(symbols, "func_0021BC30")
    assert sym_bc30["st_size"] == 396
    sec_bc30 = result.get_section(sym_bc30["st_shndx"]).data()
    offset_bc30 = 0x21BC30 - 0xFFE20
    target_bc30 = data[offset_bc30:offset_bc30 + 404]
    overlap_words = sum(
        sec_bc30[i:i + 4] == target_bc30[i:i + 4]
        for i in range(0, min(len(sec_bc30), len(target_bc30)), 4)
    )
    # Direct unaligned word overlap is 11 words; sequence alignment (objdiff) reports 78.11%
    assert overlap_words == 11, f"unexpected unaligned word overlap: {overlap_words}"

    # Verify original padding boundaries across slice
    pad_bc30 = data[0x21BDC4 - 0xFFE20:0x21BDD0 - 0xFFE20]
    assert pad_bc30 == bytes(12), "expected 12 zero padding bytes after func_0021BC30"
    pad_bdd0 = data[0x21BDDC - 0xFFE20:0x21BDE0 - 0xFFE20]
    assert pad_bdd0 == bytes(4), "expected 4 zero padding bytes after func_0021BDD0"
    pad_bde0 = data[0x21BDE8 - 0xFFE20:0x21BDF0 - 0xFFE20]
    assert pad_bde0 == bytes(8), "expected 8 zero padding bytes after func_0021BDE0"
