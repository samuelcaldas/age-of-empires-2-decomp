"""Measure isolated, relocation-resolved matching for trade_action_helper_21C410."""

from hashlib import sha1
from io import BytesIO
from pathlib import Path
import runpy
import subprocess

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection
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
    ("func_0021C410", 0x21C410, 132),  # 0x84 code bytes, 12 pad
    ("func_0021C4A0", 0x21C4A0, 132),  # 0x84 code bytes, 12 pad
    ("func_0021C530", 0x21C530, 216),  # 0xD8 code bytes, 8 pad
    ("func_0021C610", 0x21C610, 128),  # 0x80 code bytes, 0 pad
    ("func_0021C690", 0x21C690, 128),  # 0x80 code bytes, 0 pad
]

EXTERNALS = {
    "func_123908": 0x123908,
    "func_104448": 0x104448,
    "func_1045E8": 0x1045E8,
    "func_1046A8": 0x1046A8,
    "func_104600": 0x104600,
    "D_00392B30": 0x392B30,
}

PADDING_GAPS = [
    ("pad_c410", 0x21C494, 0x21C4A0, 12),
    ("pad_c4a0", 0x21C524, 0x21C530, 12),
    ("pad_c530", 0x21C608, 0x21C610, 8),
]


def test_helper_21c410_relocation_resolved_comparison(tmp_path):
    """Compile C++, resolve call/data relocations, and compare original code bytes."""
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER, LINKER) if not path.is_file()]
    if missing:
        pytest.skip(f"requires private original ELF and PS2 tools: {missing}")
    data = ORIGINAL.read_bytes()
    assert sha1(data).hexdigest() == "f478e19f2059d52899b691483ef5c7522e30e17c"
    reference = ELFFile(BytesIO(data))

    candidate = tmp_path / "helper_21C410.o"
    subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         "src/trade_action_helper_21C410.cpp", "-o", str(candidate)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=60,
    )
    compiled = ELFFile(BytesIO(candidate.read_bytes()))
    table = compiled.get_section_by_name(".symtab")

    expected_indices = []
    for name, _, size in FUNCTIONS:
        fn_sym = unique_symbol(table, name)
        assert fn_sym["st_size"] in (size, size + 12), f"{name} size mismatch: got {fn_sym['st_size']}, expected {size}"
        expected_indices.append(fn_sym["st_shndx"])

    # Verify exact count and types of all 35 relocations across functions
    total_relocs = 0
    reloc_sections = [s for s in compiled.iter_sections() if isinstance(s, RelocationSection) and s["sh_info"] in expected_indices]
    assert len(reloc_sections) == len(FUNCTIONS), f"expected {len(FUNCTIONS)} reloc sections, got {len(reloc_sections)}"
    for sec in reloc_sections:
        assert sec.num_relocations() == 7, f"expected 7 relocs in {sec.name}, got {sec.num_relocations()}"
        total_relocs += sec.num_relocations()
        relocs = list(sec.iter_relocations())
        types = [r["r_info_type"] for r in relocs]
        assert types.count(4) == 5, f"expected 5 R_MIPS_26 in {sec.name}"
        assert types.count(5) == 1, f"expected 1 R_MIPS_HI16 in {sec.name}"
        assert types.count(6) == 1, f"expected 1 R_MIPS_LO16 in {sec.name}"
    assert total_relocs == 35, f"expected 35 total relocations, got {total_relocs}"

    undefined = {s.name for s in table.iter_symbols()
                 if s.name and s["st_shndx"] == "SHN_UNDEF"}
    assert undefined <= set(EXTERNALS)

    renamed = tmp_path / "helper_21C410-renamed.o"
    indices = rename_text_sections(candidate, renamed)
    assert indices == expected_indices, "unexpected private executable sections"
    executable = [i for i, s in enumerate(compiled.iter_sections()) if s["sh_flags"] & 0x4]
    assert executable == expected_indices, "unexpected non-.text executable section"

    definitions = "".join(f"{name} = {address:#x};\n" for name, address in EXTERNALS.items())
    sections_script = "".join(
        f".text_{idx} {vram:#x} : {{ *(.text_{idx}) }}\n"
        for (_, vram, _), idx in zip(FUNCTIONS, indices)
    )
    script = tmp_path / "helper_21C410.ld"
    script.write_text(definitions + "_gp = 0x4EA7C0;\nSECTIONS {\n"
                      + sections_script + "/DISCARD/ : { *(*) }\n}\n")
    linked = tmp_path / "helper_21C410.elf"
    subprocess.run(
        [str(LINKER), "-EL", "-m", "elf32ltsmip", "--no-undefined",
         "-T", str(script), "-o", str(linked), str(renamed)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=30,
    )
    result = ELFFile(BytesIO(linked.read_bytes()))
    symbols = result.get_section_by_name(".symtab")
    assert not [s.name for s in symbols.iter_symbols() if s.name and s["st_shndx"] == "SHN_UNDEF"]

    # Verify exact 100.00% byte matches for all 5 functions
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

    # Verify all 3 padding gaps are zero-filled
    for pad_name, start, end, pad_len in PADDING_GAPS:
        pad_bytes = data[start - 0xFFE20:end - 0xFFE20]
        assert len(pad_bytes) == pad_len, f"{pad_name} length mismatch"
        assert pad_bytes == bytes(pad_len), f"{pad_name} not all zero"
