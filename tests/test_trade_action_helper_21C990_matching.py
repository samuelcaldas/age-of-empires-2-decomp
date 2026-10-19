"""Measure isolated, relocation-resolved matching for trade_action_helper_21C990."""

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


def resolve_original_elf():
    for p in [
        ROOT / "orig/SLES-50282/AOK.ELF",
        Path("/workspace/orig/SLES-50282/AOK.ELF"),
        Path("/home/samuelcaldas/source/repos/aoe/orig/SLES-50282/AOK.ELF"),
        Path("/home/samuelcaldas/source/repos/aoe/.worktrees/trade-action-217930/orig/SLES-50282/AOK.ELF"),
        Path("/orig/SLES-50282/AOK.ELF"),
    ]:
        if p.is_file():
            return p
    return ROOT / "orig/SLES-50282/AOK.ELF"


def resolve_compiler():
    for p in [
        ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe",
        Path("/workspace/compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"),
        Path("/home/samuelcaldas/source/repos/aoe/compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"),
        Path("/home/samuelcaldas/source/repos/aoe/.worktrees/trade-action-217930/compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"),
        Path("/compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"),
    ]:
        if p.is_file():
            return p
    return ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"


def resolve_wrapper():
    for p in [
        ROOT / "build/tools/wibo",
        Path("/workspace/build/tools/wibo"),
        Path("/home/samuelcaldas/source/repos/aoe/.worktrees/trade-action-217930/build/tools/wibo"),
        Path("/home/samuelcaldas/source/repos/aoe/build/tools/wibo"),
    ]:
        if p.is_file():
            return p
    return ROOT / "build/tools/wibo"


def resolve_linker():
    for p in [
        ROOT / "build/mips_binutils/mips-linux-gnu-ld",
        Path("/workspace/build/mips_binutils/mips-linux-gnu-ld"),
        Path("/home/samuelcaldas/source/repos/aoe/.worktrees/trade-action-217930/build/mips_binutils/mips-linux-gnu-ld"),
        Path("/home/samuelcaldas/source/repos/aoe/build/mips_binutils/mips-linux-gnu-ld"),
    ]:
        if p.is_file():
            return p
    return ROOT / "build/mips_binutils/mips-linux-gnu-ld"


ORIGINAL = resolve_original_elf()
COMPILER = resolve_compiler()
WRAPPER = resolve_wrapper()
LINKER = resolve_linker()

FUNCTIONS = [
    ("func_0021C990", 0x21C990, 760),  # 0x2F8 code bytes, 8 pad
    ("func_0021CC90", 0x21CC90, 132),  # 0x84 code bytes, 12 pad
]

EXTERNALS = {
    "func_123908": 0x123908,
    "func_104448": 0x104448,
    "func_1045E8": 0x1045E8,
    "func_1046A8": 0x1046A8,
    "func_104600": 0x104600,
    "D_00392B40": 0x392B40,
    "D_00CA158C": 0xCA158C,
    "D_00CA158E": 0xCA158E,
}

PADDING_GAPS = [
    ("pad_c990", 0x21CC88, 0x21CC90, 8),
    ("pad_cc90", 0x21CD14, 0x21CD20, 12),
]

EXPECTED_CODE_RELOCATIONS = {
    "func_0021C990": [
        (0x054, 5, "D_00392B40", 0),
        (0x058, 6, "D_00392B40", 0),
        (0x0A0, 4, "func_123908", 0),
        (0x0B0, 5, "D_00CA158C", 0),
        (0x0B4, 6, "D_00CA158C", 0),
        (0x0CC, 5, "D_00CA158E", 0),
        (0x0D0, 6, "D_00CA158E", 0),
        (0x164, 4, "func_104448", 0),
        (0x174, 4, "func_1045E8", 0),
        (0x18C, 4, "func_1046A8", 0),
        (0x1A4, 4, "func_1046A8", 0),
        (0x1B8, 4, "func_1046A8", 0),
        (0x1DC, 4, "func_1046A8", 0),
        (0x204, 4, "func_1046A8", 0),
        (0x224, 4, "func_1046A8", 0),
        (0x244, 4, "func_1046A8", 0),
        (0x264, 4, "func_1046A8", 0),
        (0x284, 4, "func_1046A8", 0),
        (0x294, 4, "func_1046A8", 0),
        (0x2B4, 4, "func_1046A8", 0),
        (0x2BC, 4, "func_104600", 0),
    ],
    "func_0021CC90": [
        (0x070, 4, "func_0021C990", 0),
    ],
}

EXPECTED_METADATA_RELOCATIONS = {
    "func_0021C990": [(0x4, 2, "func_0021C990", 0)],
    "func_0021CC90": [(0x4, 2, "func_0021CC90", 0)],
}


def verify_relocation_manifest(compiled, table, expected_indices, fn_by_shndx, expected_code_manifest, expected_meta_manifest=None):
    """Verify that every section's relocations match the manifest exactly."""
    all_reloc_sections = [s for s in compiled.iter_sections() if isinstance(s, RelocationSection)]
    code_relocs = [s for s in all_reloc_sections if s["sh_info"] in expected_indices]
    assert len(code_relocs) == len(FUNCTIONS), f"expected {len(FUNCTIONS)} code reloc sections, got {len(code_relocs)}"

    total_code_relocs = 0
    for sec in code_relocs:
        fn_name = fn_by_shndx[sec["sh_info"]]
        exp_count = len(expected_code_manifest[fn_name])
        assert sec.num_relocations() == exp_count, f"expected {exp_count} relocs in {sec.name}, got {sec.num_relocations()}"
        total_code_relocs += sec.num_relocations()
        actual_relocs = [
            (r["r_offset"], r["r_info_type"], table.get_symbol(r["r_info_sym"]).name, getattr(r, "r_addend", 0))
            for r in sorted(sec.iter_relocations(), key=lambda r: r["r_offset"])
        ]
        assert actual_relocs == expected_code_manifest[fn_name], f"code relocation mismatch in {fn_name}"
    assert total_code_relocs == 22, f"expected 22 total code relocations, got {total_code_relocs}"

    if expected_meta_manifest is not None:
        meta_relocs = [s for s in all_reloc_sections if s.name == ".rel.mwcats"]
        assert len(meta_relocs) == len(FUNCTIONS), f"expected {len(FUNCTIONS)} meta reloc sections, got {len(meta_relocs)}"
        total_meta_relocs = 0
        fn_names = [name for name, _, _ in FUNCTIONS]
        for idx, sec in enumerate(meta_relocs):
            fn_name = fn_names[idx]
            assert sec.num_relocations() == 1, f"expected 1 meta reloc in {sec.name}, got {sec.num_relocations()}"
            total_meta_relocs += sec.num_relocations()
            actual_meta = [
                (r["r_offset"], r["r_info_type"], table.get_symbol(r["r_info_sym"]).name, getattr(r, "r_addend", 0))
                for r in sec.iter_relocations()
            ]
            assert actual_meta == expected_meta_manifest[fn_name], f"metadata relocation mismatch in {fn_name}"
        assert total_meta_relocs == 2, f"expected 2 total metadata relocations, got {total_meta_relocs}"


def verify_padding_gaps(elf_data, padding_gaps):
    """Verify that every inter-function padding gap contains only zero bytes."""
    for pad_name, start, end, pad_len in padding_gaps:
        pad_bytes = elf_data[start - 0xFFE20:end - 0xFFE20]
        assert len(pad_bytes) == pad_len, f"{pad_name} length mismatch: got {len(pad_bytes)}, expected {pad_len}"
        assert pad_bytes == bytes(pad_len), f"{pad_name} not all zero"


def test_helper_21c990_relocation_resolved_comparison(tmp_path):
    """Compile C++, resolve call/data relocations, and compare original code bytes."""
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER, LINKER) if not path.is_file()]
    if missing:
        pytest.skip(f"requires private original ELF and PS2 tools: {missing}")
    data = ORIGINAL.read_bytes()
    assert sha1(data).hexdigest() == "f478e19f2059d52899b691483ef5c7522e30e17c"
    reference = ELFFile(BytesIO(data))

    candidate = tmp_path / "helper_21C990.o"
    subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         "src/trade_action_helper_21C990.cpp", "-o", str(candidate)],
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
    verify_relocation_manifest(compiled, table, expected_indices, fn_by_shndx, EXPECTED_CODE_RELOCATIONS, EXPECTED_METADATA_RELOCATIONS)

    undefined = {s.name for s in table.iter_symbols()
                 if s.name and s["st_shndx"] == "SHN_UNDEF"}
    allowed = set(EXTERNALS) | {name for name, _, _ in FUNCTIONS}
    assert undefined <= allowed

    renamed = tmp_path / "helper_21C990-renamed.o"
    indices = rename_text_sections(candidate, renamed)
    assert indices == expected_indices, "unexpected private executable sections"
    executable = [i for i, s in enumerate(compiled.iter_sections()) if s["sh_flags"] & 0x4]
    assert executable == expected_indices, "unexpected non-.text executable section"

    definitions = "".join(f"{name} = {address:#x};\n" for name, address in EXTERNALS.items())
    sections_script = "".join(
        f".text_{idx} {vram:#x} : {{ *(.text_{idx}) }}\n"
        for (_, vram, _), idx in zip(FUNCTIONS, indices)
    )
    script = tmp_path / "helper_21C990.ld"
    script.write_text(definitions + "_gp = 0x4EA7C0;\nSECTIONS {\n"
                      + sections_script + "/DISCARD/ : { *(*) }\n}\n")
    linked = tmp_path / "helper_21C990.elf"
    subprocess.run(
        [str(LINKER), "-EL", "-m", "elf32ltsmip", "--no-undefined",
         "-T", str(script), "-o", str(linked), str(renamed)],
        cwd=ROOT, capture_output=True, text=True, check=True, timeout=30,
    )
    result = ELFFile(BytesIO(linked.read_bytes()))
    symbols = result.get_section_by_name(".symtab")
    assert not [s.name for s in symbols.iter_symbols() if s.name and s["st_shndx"] == "SHN_UNDEF"]

    # Verify exact 100.00% byte matches for both functions
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


def test_helper_21c990_relocation_manifest_rejection(tmp_path):
    """Verify that corrupting expected code or metadata relocation manifest causes rejection."""
    missing = [str(path) for path in (COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("compiler unavailable")
    candidate = tmp_path / "helper_mut.o"
    subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         "src/trade_action_helper_21C990.cpp", "-o", str(candidate)],
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

    # Code relocation offset mutation
    mutated_code = copy.deepcopy(EXPECTED_CODE_RELOCATIONS)
    mutated_code["func_0021C990"][0] = (0x060, 5, "D_00392B40", 0)
    with pytest.raises(AssertionError) as exc_info:
        verify_relocation_manifest(compiled, table, expected_indices, fn_by_shndx, mutated_code, EXPECTED_METADATA_RELOCATIONS)
    assert "code relocation mismatch in func_0021C990" in str(exc_info.value)

    # Metadata relocation symbol mutation
    mutated_meta = copy.deepcopy(EXPECTED_METADATA_RELOCATIONS)
    mutated_meta["func_0021CC90"] = [(0x4, 2, "D_WRONG_SYM", 0)]
    with pytest.raises(AssertionError) as exc_info:
        verify_relocation_manifest(compiled, table, expected_indices, fn_by_shndx, EXPECTED_CODE_RELOCATIONS, mutated_meta)
    assert "metadata relocation mismatch in func_0021CC90" in str(exc_info.value)


def test_helper_21c990_padding_rejection():
    """Verify that non-zero padding or length deviation is rejected."""
    data = ORIGINAL.read_bytes()
    corrupted = bytearray(data)

    offset = 0x21CC88 - 0xFFE20
    corrupted[offset] = 0xFF
    with pytest.raises(AssertionError) as exc_info:
        verify_padding_gaps(corrupted, PADDING_GAPS)
    assert "pad_c990 not all zero" in str(exc_info.value)
