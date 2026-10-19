"""Measure isolated, relocation-resolved matching for trade_action_helper_21C710."""

from hashlib import sha1
from io import BytesIO
import os
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
WRAPPER = ROOT / "build/tools/wibo"
LINKER = ROOT / "build/mips_binutils/mips-linux-gnu-ld"


def resolve_original_elf():
    for p in [
        ROOT / "orig/SLES-50282/AOK.ELF",
        Path("/home/samuelcaldas/source/repos/aoe/orig/SLES-50282/AOK.ELF"),
        Path("/orig/SLES-50282/AOK.ELF"),
        Path("/workspace/orig/SLES-50282/AOK.ELF"),
    ]:
        if p.is_file():
            return p
    return ROOT / "orig/SLES-50282/AOK.ELF"


def resolve_compiler():
    for p in [
        ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe",
        Path("/home/samuelcaldas/source/repos/aoe/compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"),
        Path("/compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"),
        Path("/workspace/compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"),
    ]:
        if p.is_file():
            return p
    return ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"


ORIGINAL = resolve_original_elf()
COMPILER = resolve_compiler()

FUNCTIONS = [
    ("func_0021C710", 0x21C710, 128),  # 0x80 code bytes, 0 pad
    ("func_0021C790", 0x21C790, 128),  # 0x80 code bytes, 0 pad
    ("func_0021C810", 0x21C810, 188),  # 0xBC code bytes, 4 pad
    ("func_0021C8D0", 0x21C8D0, 188),  # 0xBC code bytes, 4 pad
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
    ("pad_c810", 0x21C8CC, 0x21C8D0, 4),
    ("pad_c8d0", 0x21C98C, 0x21C990, 4),
]

EXPECTED_RELOCATIONS = {
    "func_0021C710": [
        (0x1C, 4, "func_123908", 0),
        (0x34, 4, "func_104448", 0),
        (0x3C, 5, "D_00392B30", 0),
        (0x40, 6, "D_00392B30", 0),
        (0x48, 4, "func_1045E8", 0),
        (0x58, 4, "func_1046A8", 0),
        (0x60, 4, "func_104600", 0),
    ],
    "func_0021C790": [
        (0x1C, 4, "func_123908", 0),
        (0x34, 4, "func_104448", 0),
        (0x3C, 5, "D_00392B30", 0),
        (0x40, 6, "D_00392B30", 0),
        (0x48, 4, "func_1045E8", 0),
        (0x58, 4, "func_1046A8", 0),
        (0x60, 4, "func_104600", 0),
    ],
    "func_0021C810": [
        (0x2C, 4, "func_123908", 0),
        (0x44, 4, "func_104448", 0),
        (0x4C, 5, "D_00392B30", 0),
        (0x50, 6, "D_00392B30", 0),
        (0x58, 4, "func_1045E8", 0),
        (0x8C, 4, "func_1046A8", 0),
        (0x94, 4, "func_104600", 0),
    ],
    "func_0021C8D0": [
        (0x2C, 4, "func_123908", 0),
        (0x44, 4, "func_104448", 0),
        (0x4C, 5, "D_00392B30", 0),
        (0x50, 6, "D_00392B30", 0),
        (0x58, 4, "func_1045E8", 0),
        (0x8C, 4, "func_1046A8", 0),
        (0x94, 4, "func_104600", 0),
    ],
}


def verify_relocation_manifest(compiled, table, expected_indices, fn_by_shndx, expected_manifest):
    """Verify that every section's relocations match the manifest exactly."""
    reloc_sections = [s for s in compiled.iter_sections() if isinstance(s, RelocationSection) and s["sh_info"] in expected_indices]
    assert len(reloc_sections) == len(FUNCTIONS), f"expected {len(FUNCTIONS)} reloc sections, got {len(reloc_sections)}"
    total_relocs = 0
    for sec in reloc_sections:
        fn_name = fn_by_shndx[sec["sh_info"]]
        assert sec.num_relocations() == 7, f"expected 7 relocs in {sec.name}, got {sec.num_relocations()}"
        total_relocs += sec.num_relocations()
        actual_relocs = [
            (r["r_offset"], r["r_info_type"], table.get_symbol(r["r_info_sym"]).name, getattr(r, "r_addend", 0))
            for r in sorted(sec.iter_relocations(), key=lambda r: r["r_offset"])
        ]
        assert actual_relocs == expected_manifest[fn_name], f"relocation mismatch in {fn_name}"
    assert total_relocs == 28, f"expected 28 total relocations, got {total_relocs}"


def verify_padding_gaps(elf_data, padding_gaps):
    """Verify that every inter-function padding gap contains only zero bytes."""
    for pad_name, start, end, pad_len in padding_gaps:
        pad_bytes = elf_data[start - 0xFFE20:end - 0xFFE20]
        assert len(pad_bytes) == pad_len, f"{pad_name} length mismatch: got {len(pad_bytes)}, expected {pad_len}"
        assert pad_bytes == bytes(pad_len), f"{pad_name} not all zero"


def test_helper_21c710_relocation_resolved_comparison(tmp_path):
    """Compile C++, resolve call/data relocations, and compare original code bytes."""
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER, LINKER) if not path.is_file()]
    if missing:
        pytest.skip(f"requires private original ELF and PS2 tools: {missing}")
    data = ORIGINAL.read_bytes()
    assert sha1(data).hexdigest() == "f478e19f2059d52899b691483ef5c7522e30e17c"
    reference = ELFFile(BytesIO(data))

    candidate = tmp_path / "helper_21C710.o"
    subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         "src/trade_action_helper_21C710.cpp", "-o", str(candidate)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=60,
    )
    compiled = ELFFile(BytesIO(candidate.read_bytes()))
    table = compiled.get_section_by_name(".symtab")

    expected_indices = []
    fn_by_shndx = {}
    for name, _, size in FUNCTIONS:
        fn_sym = unique_symbol(table, name)
        assert fn_sym["st_size"] in (size, size + 12), f"{name} size mismatch: got {fn_sym['st_size']}, expected {size}"
        expected_indices.append(fn_sym["st_shndx"])
        fn_by_shndx[fn_sym["st_shndx"]] = name

    # Relocation manifest verification
    verify_relocation_manifest(compiled, table, expected_indices, fn_by_shndx, EXPECTED_RELOCATIONS)

    undefined = {s.name for s in table.iter_symbols()
                 if s.name and s["st_shndx"] == "SHN_UNDEF"}
    assert undefined <= set(EXTERNALS)

    renamed = tmp_path / "helper_21C710-renamed.o"
    indices = rename_text_sections(candidate, renamed)
    assert indices == expected_indices, "unexpected private executable sections"
    executable = [i for i, s in enumerate(compiled.iter_sections()) if s["sh_flags"] & 0x4]
    assert executable == expected_indices, "unexpected non-.text executable section"

    definitions = "".join(f"{name} = {address:#x};\n" for name, address in EXTERNALS.items())
    sections_script = "".join(
        f".text_{idx} {vram:#x} : {{ *(.text_{idx}) }}\n"
        for (_, vram, _), idx in zip(FUNCTIONS, indices)
    )
    script = tmp_path / "helper_21C710.ld"
    script.write_text(definitions + "_gp = 0x4EA7C0;\nSECTIONS {\n"
                      + sections_script + "/DISCARD/ : { *(*) }\n}\n")
    linked = tmp_path / "helper_21C710.elf"
    subprocess.run(
        [str(LINKER), "-EL", "-m", "elf32ltsmip", "--no-undefined",
         "-T", str(script), "-o", str(linked), str(renamed)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=30,
    )
    result = ELFFile(BytesIO(linked.read_bytes()))
    symbols = result.get_section_by_name(".symtab")
    assert not [s.name for s in symbols.iter_symbols() if s.name and s["st_shndx"] == "SHN_UNDEF"]

    # Verify exact 100.00% byte matches for all 4 functions
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
        assert actual_bytes == expected_bytes, f"{name} binary mismatch"

    # Verify all padding gaps are zero-filled
    verify_padding_gaps(data, PADDING_GAPS)


def test_helper_21c710_relocation_manifest_rejection(tmp_path):
    """Verify that corrupting expected relocation manifest causes rejection."""
    missing = [str(path) for path in (COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("compiler unavailable")
    candidate = tmp_path / "helper_mut.o"
    subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         "src/trade_action_helper_21C710.cpp", "-o", str(candidate)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=60,
    )
    compiled = ELFFile(BytesIO(candidate.read_bytes()))
    table = compiled.get_section_by_name(".symtab")
    expected_indices = []
    fn_by_shndx = {}
    for name, _, size in FUNCTIONS:
        fn_sym = unique_symbol(table, name)
        expected_indices.append(fn_sym["st_shndx"])
        fn_by_shndx[fn_sym["st_shndx"]] = name

    import copy
    mutated_offset = copy.deepcopy(EXPECTED_RELOCATIONS)
    mutated_offset["func_0021C710"][0] = (0x24, 4, "func_123908", 0)
    with pytest.raises(AssertionError) as exc_info:
        verify_relocation_manifest(compiled, table, expected_indices, fn_by_shndx, mutated_offset)
    assert "relocation mismatch in func_0021C710" in str(exc_info.value)


def test_helper_21c710_padding_rejection():
    """Verify that non-zero padding or length deviation is rejected."""
    data = ORIGINAL.read_bytes()
    corrupted = bytearray(data)

    offset = 0x21C8CC - 0xFFE20
    corrupted[offset] = 0xFF
    with pytest.raises(AssertionError) as exc_info:
        verify_padding_gaps(corrupted, PADDING_GAPS)
    assert "pad_c810 not all zero" in str(exc_info.value)
