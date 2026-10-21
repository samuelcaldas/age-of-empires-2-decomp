"""Shared exact-match helpers for network-layer functions.

Compile a source file with MWCC, resolve every .text relocation against
explicit external addresses, and compare all function bytes with the original
PS2 image. There are no instruction masks. Any relocation form or symbol that
is not declared fails loudly.

Command line (prints EXACT or the first difference plus a disassembly diff):

    .venv/bin/python tests/network_match_support.py SOURCE FUNCTION ADDRESS SIZE \
        --expect-relocations N --extern func_118de0=0x118DE0 ...
"""

import argparse
import difflib
import hashlib
from io import BytesIO
from pathlib import Path
import struct
import subprocess
import sys
import tempfile

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
OBJDUMP = ROOT / "build/mips_binutils/mips-linux-gnu-objdump"
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
GLOBAL_POINTER = 0x4EA7C0
R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16 = 4, 5, 6, 7


def private_inputs_missing():
    """Return the private inputs that are absent; tests skip when non-empty."""
    required = (ORIGINAL, COMPILER, WRAPPER)
    return [str(path) for path in required if not path.is_file()]


def verified_original_image():
    """Read the original image and assert it is the pinned binary."""
    image = ORIGINAL.read_bytes()
    assert hashlib.sha1(image).hexdigest() == ORIGINAL_SHA1, "AOK.ELF SHA1 mismatch"
    return image


def original_bytes(image, address, size):
    """Read bytes through the unique file-backed PT_LOAD covering the range."""
    with BytesIO(image) as stream:
        segments = [
            segment for segment in ELFFile(stream).iter_segments()
            if segment["p_type"] == "PT_LOAD"
            and segment["p_vaddr"] <= address
            and address + size <= segment["p_vaddr"] + segment["p_filesz"]
        ]
    assert len(segments) == 1, f"expected one file-backed PT_LOAD at {address:#x}"
    offset = segments[0]["p_offset"] + address - segments[0]["p_vaddr"]
    return image[offset:offset + size]


def compile_object(source, directory, extra_flags=()):
    """Compile with the project flags; fail with the compiler output."""
    output = Path(directory) / (Path(source).stem + ".o")
    command = [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
               "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
               *extra_flags, "-c", str(source), "-o", str(output)]
    result = subprocess.run(command, cwd=ROOT, capture_output=True, text=True,
                            env={"MWCIncludes": "", "PATH": "/usr/bin:/bin"})
    assert result.returncode == 0, result.stdout + result.stderr
    return output


def resolve_target(symbol, externals):
    """Resolve a relocation target by name; locals and unknown names are errors."""
    assert symbol["st_shndx"] == "SHN_UNDEF", f"local symbol {symbol.name!r}: declare it extern"
    assert symbol.name in externals, f"undeclared external {symbol.name!r}"
    return externals[symbol.name]


def signed16(word):
    return struct.unpack("<h", struct.pack("<H", word & 0xFFFF))[0]


def apply_relocations(elf, section_index, code, base_address, externals, expected_count):
    """Apply every relocation of one .text section to `code` in place."""
    symbols = elf.get_section_by_name(".symtab")
    relocations = sorted(
        (relocation for section in elf.iter_sections()
         if section["sh_type"] == "SHT_REL" and section["sh_info"] == section_index
         for relocation in section.iter_relocations()),
        key=lambda relocation: relocation["r_offset"],
    )
    assert len(relocations) == expected_count, (
        f"relocation count {len(relocations)} != expected {expected_count}")
    high = {}
    for relocation in relocations:
        offset, kind = relocation["r_offset"], relocation["r_info_type"]
        symbol = symbols.get_symbol(relocation["r_info_sym"])
        target = resolve_target(symbol, externals)
        word = struct.unpack_from("<I", code, offset)[0]
        if kind == R_MIPS_26:
            value = target + ((word & 0x3FFFFFF) << 2)
            assert (value & 0xF0000000) == ((base_address + offset) & 0xF0000000)
            word = (word & 0xFC000000) | ((value >> 2) & 0x3FFFFFF)
        elif kind == R_MIPS_HI16:
            key = (symbol.name, (word >> 16) & 31)
            assert key not in high, f"overlapping HI16 for {symbol.name}"
            high[key] = offset
            continue
        elif kind == R_MIPS_LO16:
            key = (symbol.name, (word >> 21) & 31)
            assert key in high, f"LO16 without HI16 for {symbol.name}"
            high_offset = high.pop(key)
            high_word = struct.unpack_from("<I", code, high_offset)[0]
            value = target + ((high_word & 0xFFFF) << 16) + signed16(word)
            carried = (high_word & 0xFFFF0000) | (((value + 0x8000) >> 16) & 0xFFFF)
            struct.pack_into("<I", code, high_offset, carried)
            word = (word & 0xFFFF0000) | (value & 0xFFFF)
        elif kind == R_MIPS_GPREL16:
            value = target + signed16(word) - GLOBAL_POINTER
            assert -0x8000 <= value < 0x8000, f"GPREL16 out of range for {symbol.name}"
            word = (word & 0xFFFF0000) | (value & 0xFFFF)
        else:
            raise AssertionError(f"unhandled relocation type {kind} at {offset:#x}")
        struct.pack_into("<I", code, offset, word)
    assert not high, f"unpaired HI16 relocations: {sorted(high)}"


def relocated_function(object_path, name, address, size, externals, expected_relocations):
    """Return the function bytes with all relocations resolved at `address`."""
    with Path(object_path).open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".symtab")
        matches = symbols.get_symbol_by_name(name)
        assert matches is not None and len(matches) == 1, f"symbol {name}"
        function = matches[0]
        assert function["st_info"]["type"] == "STT_FUNC"
        assert function["st_size"] == size, f"emitted size {function['st_size']} != {size}"
        section_index = function["st_shndx"]
        section = elf.get_section(section_index)
        assert section.name == ".text", f"{name} not in .text"
        undefined = {symbol.name for symbol in symbols.iter_symbols()
                     if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"}
        assert undefined <= set(externals), f"undeclared externals: {sorted(undefined - set(externals))}"
        start = function["st_value"]
        code = bytearray(section.data())
        apply_relocations(elf, section_index, code, address - start, externals, expected_relocations)
        return bytes(code[start:start + size])


def disassemble(code, address):
    """Disassemble raw R5900 bytes for reading a mismatch."""
    with tempfile.NamedTemporaryFile(suffix=".bin") as handle:
        handle.write(code)
        handle.flush()
        result = subprocess.run(
            [str(OBJDUMP), "-D", "-b", "binary", "-m", "mips:5900", "-z",
             f"--adjust-vma={address:#x}", handle.name],
            capture_output=True, text=True)
    lines = [line.split("\t", 2) for line in result.stdout.splitlines() if "\t" in line]
    return [f"{line[0].strip()} {line[2] if len(line) > 2 else ''}" for line in lines]


def first_difference(actual, expected):
    """Index of the first differing byte, or None when equal."""
    return next((index for index, pair in enumerate(zip(actual, expected))
                 if pair[0] != pair[1]), None)


def assert_exact(actual, expected, address):
    """Assert full equality of every byte; no masks."""
    assert len(actual) == len(expected), f"length {len(actual)} != {len(expected)}"
    difference = first_difference(actual, expected)
    assert difference is None, f"bytes differ at {address + difference:#x}"


def parse_arguments(argv):
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("source")
    parser.add_argument("function")
    parser.add_argument("address", type=lambda text: int(text, 0))
    parser.add_argument("size", type=lambda text: int(text, 0))
    parser.add_argument("--expect-relocations", type=int, required=True)
    parser.add_argument("--extern", action="append", default=[], metavar="NAME=ADDRESS")
    return parser.parse_args(argv)


def main(argv):
    arguments = parse_arguments(argv)
    missing = private_inputs_missing()
    if missing:
        print("missing private inputs:", ", ".join(missing))
        return 2
    externals = {name: int(value, 0)
                 for name, value in (item.split("=", 1) for item in arguments.extern)}
    expected = original_bytes(verified_original_image(), arguments.address, arguments.size)
    with tempfile.TemporaryDirectory() as directory:
        path = compile_object(arguments.source, directory)
        try:
            actual = relocated_function(path, arguments.function, arguments.address,
                                        arguments.size, externals, arguments.expect_relocations)
        except AssertionError as error:
            print("NOT RESOLVED:", error)
            return 1
    difference = first_difference(actual, expected)
    if difference is None and len(actual) == len(expected):
        print(f"EXACT {len(actual)} bytes")
        return 0
    equal = sum(1 for pair in zip(actual, expected) if pair[0] == pair[1])
    print(f"DIFFERENT: {equal}/{len(expected)} bytes equal, first difference at "
          f"{arguments.address + (difference or 0):#x}")
    for line in difflib.unified_diff(disassemble(expected, arguments.address),
                                     disassemble(actual, arguments.address),
                                     "original", "candidate", lineterm="", n=2):
        print(line)
    return 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
