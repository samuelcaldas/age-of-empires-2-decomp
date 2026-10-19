"""Measure isolated, relocation-resolved matching for trade_action_helper_21BDF0."""

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
    ("func_0021BDF0", 0x21BDF0, 0x1C0),  # 448 bytes code extent
    ("func_0021BFB0", 0x21BFB0, 0x14),   # 20 bytes code extent (12 B zero padding excluded)
]

EXTERNALS = {
    "strcpy": 0x11ABBC,
    "func_100850": 0x100850,
    "func_2F61F0": 0x2F61F0,
    "func_00219F60": 0x219F60,
    "D_00C5E300": 0xC5E300,
    "D_492C70": 0x492C70,
    "D_492C78": 0x492C78,
    "D_004E32E4": 0x4E32E4,
}


def test_helper_21bdf0_relocation_resolved_comparison(tmp_path):
    """Compile C++, resolve call/data relocations, and compare original code bytes."""
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER, LINKER) if not path.is_file()]
    if missing:
        pytest.skip(f"requires private original ELF and PS2 tools: {missing}")
    data = ORIGINAL.read_bytes()
    assert sha1(data).hexdigest() == "f478e19f2059d52899b691483ef5c7522e30e17c"
    reference = ELFFile(BytesIO(data))

    candidate = tmp_path / "helper_21BDF0.o"
    subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         "src/trade_action_helper_21BDF0.cpp", "-o", str(candidate)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=60,
    )
    compiled = ELFFile(BytesIO(candidate.read_bytes()))
    table = compiled.get_section_by_name(".symtab")

    expected_indices = []
    for name, _, size in FUNCTIONS:
        fn_sym = unique_symbol(table, name)
        assert fn_sym["st_size"] in (size, size + 12), f"{name} size mismatch"
        expected_indices.append(fn_sym["st_shndx"])

    undefined = {s.name for s in table.iter_symbols()
                 if s.name and s["st_shndx"] == "SHN_UNDEF"}
    assert undefined <= set(EXTERNALS)

    renamed = tmp_path / "helper_21BDF0-renamed.o"
    indices = rename_text_sections(candidate, renamed)
    assert indices == expected_indices, "unexpected private executable sections"
    executable = [i for i, s in enumerate(compiled.iter_sections()) if s["sh_flags"] & 0x4]
    assert executable == expected_indices, "unexpected non-.text executable section"

    definitions = "".join(f"{name} = {address:#x};\n" for name, address in EXTERNALS.items())
    sections_script = "".join(
        f".text_{idx} {vram:#x} : {{ *(.text_{idx}) }}\n"
        for (_, vram, _), idx in zip(FUNCTIONS, indices)
    )
    script = tmp_path / "helper_21BDF0.ld"
    script.write_text(definitions + "_gp = 0x4EA7C0;\nSECTIONS {\n"
                      + sections_script + ".lit4 0x4E2804 : { *(.lit4) }\n/DISCARD/ : { *(*) }\n}\n")
    linked = tmp_path / "helper_21BDF0.elf"
    subprocess.run(
        [str(LINKER), "-EL", "-m", "elf32ltsmip", "--no-undefined",
         "-T", str(script), "-o", str(linked), str(renamed)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=30,
    )
    result = ELFFile(BytesIO(linked.read_bytes()))
    symbols = result.get_section_by_name(".symtab")
    assert not [s.name for s in symbols.iter_symbols() if s.name and s["st_shndx"] == "SHN_UNDEF"]

    # Verify exact 100.00% byte matches for all functions
    for name, vram, size in FUNCTIONS:
        loads = [seg for seg in reference.iter_segments()
                 if seg["p_type"] == "PT_LOAD" and seg["p_vaddr"] <= vram
                 and vram + size <= seg["p_vaddr"] + seg["p_filesz"]]
        assert len(loads) == 1
        offset = loads[0]["p_offset"] + vram - loads[0]["p_vaddr"]
        expected_bytes = data[offset:offset + size]

        sym = unique_symbol(symbols, name)
        assert sym["st_value"] == vram
        sec = result.get_section(sym["st_shndx"])
        actual_bytes = sec.data()[:size]
        if actual_bytes != expected_bytes:
            diffs = [
                f"+{i:#x}: got {actual_bytes[i]:02x} expected {expected_bytes[i]:02x}"
                for i in range(min(len(actual_bytes), len(expected_bytes)))
                if actual_bytes[i] != expected_bytes[i]
            ]
            assert actual_bytes == expected_bytes, f"{name} binary mismatch ({len(diffs)} byte diffs):\n" + "\n".join(diffs[:20])

    # Verify original 12 zero padding bytes after func_0021BFB0
    pad_bfb0 = data[0x21BFC4 - 0xFFE20:0x21BFD0 - 0xFFE20]
    assert pad_bfb0 == bytes(12), "expected 12 zero padding bytes after func_0021BFB0"
