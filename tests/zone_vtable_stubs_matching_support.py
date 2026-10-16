"""Compare compiled zone vtable stubs with original PS2 instructions."""

import hashlib
import subprocess
from pathlib import Path

import pytest
from elftools.elf.elffile import ELFFile


PROJECT_ROOT = Path(__file__).resolve().parents[1]
SOURCE_PATH = PROJECT_ROOT / "src/zone_vtable_stubs.cpp"
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"
LINKER_PATH = PROJECT_ROOT / "build/mips_binutils/mips-linux-gnu-ld"

VRAM_START = 0x1C97A0
FILE_OFFSET_START = 0xC9980
TOTAL_CODE_BYTES = 248
TOTAL_SLICE_BYTES = 256
TAIL_PADDING_BYTES = 8
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"

EXPECTED_FUNCTIONS = {
    "func_001C97A0": {"vram": 0x1C97A0, "size": 8, "offset": 0x0},
    "func_001C97B0": {"vram": 0x1C97B0, "size": 16, "offset": 0x10},
    "func_001C97C0": {"vram": 0x1C97C0, "size": 16, "offset": 0x20},
    "func_001C97D0": {"vram": 0x1C97D0, "size": 200, "offset": 0x30},
}

EXTERNAL_SYMBOLS = {
    "func_1C98A0": 0x1C98A0,
    "func_32F090": 0x32F090,
    "func_1CF9B0": 0x1CF9B0,
    "func_32FBD0": 0x32FBD0,
    "_gp": 0x4EA7C0,
}


def require_toolchain():
    """Skip only when private binaries or PS2 toolchain files are absent."""
    required_paths = (ORIGINAL_PATH, COMPILER_PATH, WRAPPER_PATH, LINKER_PATH)
    missing_paths = [str(path) for path in required_paths if not path.is_file()]
    if missing_paths:
        pytest.skip("requires original ELF and PS2 toolchain; missing: " + ", ".join(missing_paths))


def compile_stubs(output_directory):
    """Compile the source with verified PS2 MWCC settings."""
    output_obj = output_directory / "zone_vtable_stubs.o"
    subprocess.run(
        [
            str(WRAPPER_PATH), str(COMPILER_PATH), "-O3", "-inline", "on",
            "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
            "-lang=c++", "-c", str(SOURCE_PATH), "-o", str(output_obj),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    return output_obj


def verify_object_symbols(object_path):
    """Confirm compiler emitted unique functions in distinct homonymous .text sections."""
    with object_path.open("rb") as stream:
        obj_elf = ELFFile(stream)
        assert obj_elf.header["e_type"] == "ET_REL", "Object must be ET_REL"
        symtab = obj_elf.get_section_by_name(".symtab")
        assert symtab is not None, "Missing .symtab in compiled object"

        shndx_seen = {}
        for name, info in EXPECTED_FUNCTIONS.items():
            symbols = [s for s in symtab.iter_symbols() if s.name == name]
            assert len(symbols) == 1, f"Expected unique symbol {name} in object, got {len(symbols)}"
            sym = symbols[0]
            assert sym["st_info"]["type"] == "STT_FUNC", f"{name} is not STT_FUNC"
            assert sym["st_size"] == info["size"], f"{name}: expected size {info['size']}, got {sym['st_size']}"
            assert sym["st_value"] == 0, f"{name}: relocatable offset must be 0"
            sec = obj_elf.get_section(sym["st_shndx"])
            assert sec.name == ".text", f"{name}: expected .text section, got {sec.name}"
            shndx_seen[name] = sym["st_shndx"]

        distinct_sections = set(shndx_seen.values())
        assert len(distinct_sections) == len(EXPECTED_FUNCTIONS), (
            f"Expected {len(EXPECTED_FUNCTIONS)} distinct .text sections for homonymous emission, "
            f"got {len(distinct_sections)}: {shndx_seen}"
        )


def link_stubs(output_directory, object_path):
    """Resolve all external addresses and link at original VRAM address with --no-undefined."""
    linker_script = output_directory / "zone_vtable_stubs.ld"
    definitions = "".join(
        f"{name} = {address:#x};\n" for name, address in EXTERNAL_SYMBOLS.items()
    )
    linker_script.write_text(
        definitions + "SECTIONS {\n"
        f"  . = {VRAM_START:#x};\n"
        "  .text : { *(.text) }\n"
        "  /DISCARD/ : { *(*) }\n"
        "}\n",
        encoding="utf-8",
    )
    linked_path = output_directory / "zone_vtable_stubs.elf"
    subprocess.run(
        [
            str(LINKER_PATH), "-EL", "-m", "elf32ltsmip", "--no-undefined",
            "-T", str(linker_script), "-o", str(linked_path), str(object_path),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    with linked_path.open("rb") as stream:
        linked_elf = ELFFile(stream)
        assert linked_elf.header["e_type"] == "ET_EXEC", "Linked binary must be ET_EXEC"
        symtab = linked_elf.get_section_by_name(".symtab")
        assert symtab is not None, "Missing .symtab in linked ELF"

        unresolved = [
            sym.name for sym in symtab.iter_symbols()
            if sym.name and sym["st_shndx"] == "SHN_UNDEF"
        ]
        assert not unresolved, f"Unresolved symbols remain: {unresolved}"

        # Verify _gp symbol resolution
        gp_symbols = [s for s in symtab.iter_symbols() if s.name == "_gp"]
        assert len(gp_symbols) == 1, f"Expected unique _gp symbol, got {len(gp_symbols)}"
        assert gp_symbols[0]["st_value"] == 0x4EA7C0, f"Expected _gp at 0x4EA7C0, got {hex(gp_symbols[0]['st_value'])}"

        # Verify external callees resolution
        for ext_name, ext_addr in EXTERNAL_SYMBOLS.items():
            esyms = [s for s in symtab.iter_symbols() if s.name == ext_name]
            assert len(esyms) == 1, f"Expected unique external symbol {ext_name}, got {len(esyms)}"
            assert esyms[0]["st_value"] == ext_addr, f"{ext_name}: expected {hex(ext_addr)}, got {hex(esyms[0]['st_value'])}"

        text_section = linked_elf.get_section_by_name(".text")
        assert text_section is not None, "Missing .text in linked ELF"
        assert text_section["sh_addr"] == VRAM_START, f"Expected .text at {hex(VRAM_START)}, got {hex(text_section['sh_addr'])}"
        code = text_section.data()
        assert len(code) == TOTAL_CODE_BYTES, f"Expected {TOTAL_CODE_BYTES} bytes, got {len(code)}"

        # Verify individual function symbols in linked ELF
        for name, info in EXPECTED_FUNCTIONS.items():
            symbols = [s for s in symtab.iter_symbols() if s.name == name]
            assert len(symbols) == 1, f"Expected unique symbol {name} in ET_EXEC, got {len(symbols)}"
            sym = symbols[0]
            assert sym["st_info"]["type"] == "STT_FUNC", f"{name} in linked ELF is not STT_FUNC"
            assert sym["st_value"] == info["vram"], f"{name}: expected VRAM {hex(info['vram'])}, got {hex(sym['st_value'])}"
            assert sym["st_size"] == info["size"], f"{name}: expected size {info['size']}, got {sym['st_size']}"
            offset = sym["st_value"] - text_section["sh_addr"]
            assert offset == info["offset"], f"{name}: expected section offset {hex(info['offset'])}, got {hex(offset)}"

        return code


def original_slice_bytes():
    """Read original code and padding bytes directly from ELF PT_LOAD mapping."""
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == ORIGINAL_SHA1
    with ORIGINAL_PATH.open("rb") as stream:
        original_elf = ELFFile(stream)
        matching_segments = [
            seg for seg in original_elf.iter_segments()
            if seg["p_type"] == "PT_LOAD"
            and seg["p_vaddr"] <= VRAM_START
            and VRAM_START + TOTAL_SLICE_BYTES <= seg["p_vaddr"] + seg["p_filesz"]
        ]
        assert len(matching_segments) == 1, len(matching_segments)
        segment = matching_segments[0]
        offset = VRAM_START - segment["p_vaddr"]
        assert segment["p_offset"] + offset == FILE_OFFSET_START
        slice_data = segment.data()[offset:offset + TOTAL_SLICE_BYTES]
        assert len(slice_data) == TOTAL_SLICE_BYTES
        code = slice_data[:TOTAL_CODE_BYTES]
        tail = slice_data[TOTAL_CODE_BYTES:]
        assert tail == b"\x00" * TAIL_PADDING_BYTES, f"Unexpected tail padding: {tail}"
        return code, tail, slice_data
