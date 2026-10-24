"""Link the configured 218820 object at its original address and report raw bytes."""

import argparse
from io import BytesIO
from pathlib import Path
import struct
import subprocess
import tempfile

from elftools.elf.elffile import ELFFile


START = 0x218820
SIZE = 0x240
FILE_OFFSET = 0x118A00
FUNCTION = "func_00218820"
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
EXTERNAL_NAMES = (
    "func_001AB8F0", "func_001AB9D0", "func_001ACDF0",
    "func_001AD940", "func_001ADA70", "func_001ADC00",
)


def require(condition, message):
    """Stop with a clear diagnostic when a verification condition fails."""
    if not condition:
        raise RuntimeError(message)


def unique_symbol(table, name):
    """Return one symbol by name, rejecting missing or ambiguous definitions."""
    matches = table.get_symbol_by_name(name)
    require(matches is not None and len(matches) == 1, f"expected one {name}")
    return matches[0]


def original_bytes(path):
    """Validate ELF layout and return the original slice and verified GP."""
    import hashlib

    data = path.read_bytes()
    require(hashlib.sha1(data).hexdigest() == ORIGINAL_SHA1, "original ELF SHA-1 mismatch")
    elf = ELFFile(BytesIO(data))
    loads = [segment for segment in elf.iter_segments()
             if segment["p_type"] == "PT_LOAD" and segment["p_vaddr"] <= START
             and START + SIZE <= segment["p_vaddr"] + segment["p_filesz"]]
    require(len(loads) == 1, "function range is not in one file-backed PT_LOAD")
    segment = loads[0]
    offset = segment["p_offset"] + START - segment["p_vaddr"]
    require((segment["p_offset"], segment["p_vaddr"], offset) ==
            (0x1E0, 0x100000, FILE_OFFSET), "unexpected original PT_LOAD mapping")
    code = data[offset:offset + SIZE]
    require(len(code) == SIZE, "original function bytes are truncated")
    require(code[-8:] == bytes.fromhex("0800e0034000bd27"),
            "expected jr ra and stack-adjustment delay slot at 0x218A58–0x218A60")
    require(data[offset + SIZE:offset + SIZE + 4] == bytes.fromhex("d0febd27"),
            "expected next function prologue immediately at 0x218A60")
    reginfo = elf.get_section_by_name(".reginfo")
    require(reginfo is not None and len(reginfo.data()) >= 24, "original .reginfo is missing")
    gp = struct.unpack_from("<I", reginfo.data(), 20)[0]
    require(gp == 0x4EA7C0, f"unexpected original _gp value {gp:#x}")
    return code, gp


def original_jump_targets(code):
    """Decode direct MIPS J/JAL targets from the original function instructions."""
    targets = set()
    for offset in range(0, len(code), 4):
        instruction = int.from_bytes(code[offset:offset + 4], "little")
        if instruction >> 26 in (2, 3):
            pc = START + offset
            targets.add(((pc + 4) & 0xF0000000) | ((instruction & 0x03FFFFFF) << 2))
    return targets


def inspect_object(path):
    """Verify the real MWCC ET_REL function and its external call set."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        require(elf.header["e_type"] == "ET_REL", "configured object is not ET_REL")
        table = elf.get_section_by_name(".symtab")
        function = unique_symbol(table, FUNCTION)
        require(function["st_info"]["type"] == "STT_FUNC", "function symbol is not STT_FUNC")
        section_index = function["st_shndx"]
        require(isinstance(section_index, int), "function symbol has no section index")
        require(elf.get_section(section_index).name == ".text", "function is not in .text")
        undefined = {symbol.name for symbol in table.iter_symbols()
                     if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"}
        require(undefined == set(EXTERNAL_NAMES), f"unexpected undefined symbols: {sorted(undefined)}")
        return function["st_size"], section_index


def link_object(linker, object_path, temporary, gp):
    """Create a no-undefined GNU ET_EXEC with original external addresses."""
    targets = {name: int(name.removeprefix("func_"), 16) for name in EXTERNAL_NAMES}
    targets["_gp"] = gp
    definitions = "".join(f"{name} = {address:#x};\n" for name, address in targets.items())
    script = temporary / "helper.ld"
    script.write_text(definitions + f"SECTIONS {{ .text {START:#x} : {{ *(.text) }} "
                      ".rodata 0x219100 : { *(.rodata) } /DISCARD/ : { *(*) } }\n")
    output = temporary / "helper.elf"
    subprocess.run([str(linker), "-EL", "-m", "elf32ltsmip", "--no-undefined",
                    "-T", str(script), "-o", str(output), str(object_path)], check=True)
    return output, targets


def inspect_link(path, targets, expected_size, original):
    """Verify resolved symbols and report equal, different, missing, and extra bytes."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        require(elf.header["e_type"] == "ET_EXEC", "GNU output is not ET_EXEC")
        table = elf.get_section_by_name(".symtab")
        unresolved = [symbol.name for symbol in table.iter_symbols()
                      if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"]
        require(not unresolved, f"unresolved output symbols: {unresolved}")
        for name, address in targets.items():
            require(unique_symbol(table, name)["st_value"] == address,
                    f"wrong linked address for {name}")
        function = unique_symbol(table, FUNCTION)
        require(function["st_value"] == START and function["st_size"] == expected_size,
                "linked function address or size changed")
        section = elf.get_section(function["st_shndx"])
        start = function["st_value"] - section["sh_addr"]
        generated = section.data()[start:start + function["st_size"]]
    require(len(generated) == expected_size, "linked function bytes are truncated")
    overlap = min(len(generated), len(original))
    equal = sum(left == right for left, right in zip(generated[:overlap], original[:overlap]))
    different = overlap - equal
    missing = max(0, len(original) - len(generated))
    extra = max(0, len(generated) - len(original))
    print(f"ET_EXEC: {FUNCTION}={START:#x}, size={expected_size:#x}, "
          f"_gp={targets['_gp']:#x}, unresolved=0")
    print(f"Raw unmasked comparison: equal={equal}/{len(original)} original bytes; "
          f"overlap={overlap}, different={different}, missing={missing}, extra={extra}")
    print("NonMatching; missing bytes are not counted as differing emitted bytes.")


def main():
    """Run the object, original ELF, and resolved GNU link checks."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--object", type=Path,
                        default=Path("build/SLES-50282/src/trade/trade_action_helper_218820.o"))
    parser.add_argument("--original", type=Path, default=Path("orig/SLES-50282/AOK.ELF"))
    parser.add_argument("--linker", type=Path,
                        default=Path("build/mips_binutils/mips-linux-gnu-ld"))
    arguments = parser.parse_args()
    for path in (arguments.object, arguments.original, arguments.linker):
        require(path.is_file(), f"required input is missing: {path}")
    original, gp = original_bytes(arguments.original)
    direct_targets = original_jump_targets(original)
    expected_targets = {int(name.removeprefix("func_"), 16) for name in EXTERNAL_NAMES}
    require(expected_targets <= direct_targets,
            f"external addresses not found in original J/JAL targets: {expected_targets - direct_targets}")
    size, section_index = inspect_object(arguments.object)
    print(f"ET_REL: {FUNCTION} STT_FUNC shndx={section_index} (.text), size={size:#x}")
    print(f"Original: SHA-1={ORIGINAL_SHA1}, VRAM={START:#x}..{START + SIZE:#x} "
          f"(end-exclusive), file={FILE_OFFSET:#x}..{FILE_OFFSET + SIZE:#x}; "
          "return delay slot at 0x218A5C, next prologue at 0x218A60, no tail padding")
    print(f"Verified original direct call targets: {', '.join(f'{value:#x}' for value in sorted(expected_targets))}")
    with tempfile.TemporaryDirectory(prefix="trade-action-helper-218820-") as directory:
        output, targets = link_object(arguments.linker.resolve(), arguments.object.resolve(),
                                      Path(directory), gp)
        inspect_link(output, targets, size, original)


if __name__ == "__main__":
    try:
        main()
    except (OSError, RuntimeError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"BLOCKER: {error}") from error
