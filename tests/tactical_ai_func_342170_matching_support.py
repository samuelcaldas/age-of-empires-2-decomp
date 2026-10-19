"""Link the tactical event handler and its complete jump table at original addresses."""

import hashlib
import subprocess

from elftools.elf.elffile import ELFFile

from test_tactical_ai_layout_341040_matching import (
    COMPILER_PATH, FUNC_342170_SOURCE_PATH, LINKER_PATH, ORIGINAL_PATH,
    ORIGINAL_SHA1, PROJECT_ROOT, WRAPPER_PATH, require_toolchain,
)

FUNCTION_NAME = "func_00342170"
TEXT_ADDRESS = 0x342170
TEXT_SIZE = 0x630
TABLE_ADDRESS = 0x4D55F0
TABLE_SIZE = 30 * 4
EXTERNAL_SYMBOLS = {
    "func_339900": 0x339900,
    "func_33A5D0": 0x33A5D0,
    "func_339960": 0x339960,
    "func_1F6750": 0x1F6750,
    "D_4D5508": 0x4D5508,
    "func_33A730": 0x33A730,
    "func_00340CF0": 0x340CF0,
    "func_1F6EA0": 0x1F6EA0,
    "func_00219BA0": 0x219BA0,
    "func_33F8B0": 0x33F8B0,
    "func_00341040": 0x341040,
    "func_00340C30": 0x340C30,
    "func_36ACC0": 0x36ACC0,
    "func_1FBD30": 0x1FBD30,
}


def compile_handler(output_directory):
    """Compile current C++ into a temporary object; propagate compiler failures."""
    require_toolchain()
    object_path = output_directory / "tactical_ai_func_342170.o"
    subprocess.run(
        [str(WRAPPER_PATH), str(COMPILER_PATH), "-c", "-O3", "-inline", "on",
         "-msext", "on", "-char", "signed", "-sym", "off", "-Iinclude",
         "-lang=c++", str(FUNC_342170_SOURCE_PATH), "-o", str(object_path)],
        cwd=PROJECT_ROOT, capture_output=True, text=True, check=True,
    )
    with object_path.open("rb") as stream:
        function_bytes(ELFFile(stream), linked=False)
    return object_path


def function_bytes(elf, linked):
    """Select the sized function through st_shndx, rejecting wrong sizes or placement."""
    symbol_table = elf.get_section_by_name(".symtab")
    symbols = symbol_table.get_symbol_by_name(FUNCTION_NAME)
    assert symbols is not None and len(symbols) == 1, FUNCTION_NAME
    symbol = symbols[0]
    assert symbol["st_info"]["type"] == "STT_FUNC"
    assert symbol["st_size"] == TEXT_SIZE, "candidate function size"
    section = elf.get_section(symbol["st_shndx"])
    start = symbol["st_value"] - section["sh_addr"]
    assert not linked or symbol["st_value"] == TEXT_ADDRESS, "candidate function address"
    assert 0 <= start <= section["sh_size"] - TEXT_SIZE
    return section.data()[start:start + TEXT_SIZE]


def load_range(elf, address, size):
    """Read one complete PT_LOAD range; reject missing or ambiguous file data."""
    segments = [
        segment for segment in elf.iter_segments()
        if segment["p_type"] == "PT_LOAD"
        and segment["p_vaddr"] <= address
        and address + size <= segment["p_vaddr"] + segment["p_filesz"]
    ]
    assert len(segments) == 1, f"invalid original range: {address:#x}+{size:#x}"
    segment = segments[0]
    start = address - segment["p_vaddr"]
    return segment.data()[start:start + size]


def original_ranges():
    """Return original text and table bytes only after the pinned hash matches."""
    require_toolchain()
    assert hashlib.sha1(ORIGINAL_PATH.read_bytes()).hexdigest() == ORIGINAL_SHA1
    with ORIGINAL_PATH.open("rb") as stream:
        elf = ELFFile(stream)
        return {
            "text": load_range(elf, TEXT_ADDRESS, TEXT_SIZE),
            "jump table": load_range(elf, TABLE_ADDRESS, TABLE_SIZE),
        }


def write_linker_script(output_directory, external_symbols):
    """Pin real external addresses and place generated code and table without rewriting them."""
    definitions = "".join(
        f"{name} = {address:#x};\n" for name, address in external_symbols.items()
    )
    script = output_directory / "tactical_ai_func_342170.ld"
    script.write_text(
        definitions + "SECTIONS {\n"
        f"  .text {TEXT_ADDRESS:#x} : {{ *(.text) }}\n"
        f"  .rodata {TABLE_ADDRESS:#x} : {{ *(.rodata) }}\n"
        "  /DISCARD/ : { *(*) }\n}\n", encoding="utf-8",
    )
    return script


def link_handler(object_path, output_directory, external_symbols=EXTERNAL_SYMBOLS):
    """Resolve MIPS relocations with GNU ld; propagate unresolved-symbol failures."""
    script = write_linker_script(output_directory, external_symbols)
    linked_path = output_directory / "tactical_ai_func_342170.elf"
    subprocess.run(
        [str(LINKER_PATH), "-EL", "-m", "elf32ltsmip", "--no-undefined",
         "-T", str(script), "-o", str(linked_path), str(object_path)],
        cwd=PROJECT_ROOT, capture_output=True, text=True, check=True,
    )
    return linked_path


def linked_ranges(linked_path):
    """Read linked function and all 30 table entries, rejecting unresolved symbols."""
    with linked_path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        unresolved = [symbol.name for symbol in symbols.iter_symbols()
                      if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"]
        assert not unresolved, f"unresolved symbols: {unresolved}"
        table = elf.get_section_by_name(".rodata")
        assert table["sh_addr"] == TABLE_ADDRESS, "jump table address"
        assert table["sh_size"] == TABLE_SIZE, "jump table size"
        return {"text": function_bytes(elf, linked=True), "jump table": table.data()}


def assert_matches_original(linked_path, expected):
    """Reject any instruction or jump-table byte difference from the verified original."""
    actual = linked_ranges(linked_path)
    assert actual["text"] == expected["text"], "resolved text bytes differ"
    assert actual["jump table"] == expected["jump table"], "resolved jump table bytes differ"
