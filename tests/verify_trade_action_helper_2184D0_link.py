"""Verify the registered 2184D0 object, its BREAK, and a no-undefined link."""

import argparse
from hashlib import sha1
from io import BytesIO
from pathlib import Path
import struct
import subprocess
import tempfile

from elftools.elf.elffile import ELFFile


START = 0x2184D0
FUNCTION_SIZE = 0x348
SLICE_SIZE = 0x350
FILE_OFFSET = 0x1186B0
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
FUNCTION = "func_002184D0"
EXTERNALS = {
    "func_001AC470": 0x1AC470,
    "func_001AB8F0": 0x1AB8F0,
    "func_0025E640": 0x25E640,
    "func_001AB9D0": 0x1AB9D0,
    "func_001AD650": 0x1AD650,
}
GP = 0x4EA7C0

defrequire(condition, message):
    """Raise a clear error when an ELF verification fails."""
    if not condition:
        raise RuntimeError(message)

defunique_symbol(table, name):
    """Find exactly one named ELF symbol."""
    matches = table.get_symbol_by_name(name)
    require(matches is not None and len(matches) == 1, f"expected one {name}")
    return matches[0]

deforiginal_slice(path):
    """Check the pinned ELF mapping and return the full original slice."""
    data = path.read_bytes()
    require(sha1(data).hexdigest() == ORIGINAL_SHA1, "original ELF SHA-1 mismatch")
    elf = ELFFile(BytesIO(data))
    loads = [segment for segment in elf.iter_segments()
             if segment["p_type"] == "PT_LOAD" and segment["p_vaddr"] <= START
             and START + SLICE_SIZE <= segment["p_vaddr"] + segment["p_filesz"]]
    require(len(loads) == 1, "slice is not fully backed by one PT_LOAD")
    segment = loads[0]
    offset = segment["p_offset"] + START - segment["p_vaddr"]
    require(offset == FILE_OFFSET, f"unexpected file offset {offset:#x}")
    result = data[offset:offset + SLICE_SIZE]
    require(len(result) == SLICE_SIZE, "truncated original slice")
    require(result[FUNCTION_SIZE:] == bytes(8), "expected eight zero tail-padding bytes")
    targets = {((START + offset + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
               for offset, (word,) in enumerate(struct.iter_unpack("<I", result[:FUNCTION_SIZE]))
               if word >> 26 in (2, 3)}
    require(set(EXTERNALS.values()) <= targets, "real external addresses are absent in original calls")
    return result

defrename_text_sections(source, destination):
    """Give homonymous .text sections unique names without changing their bytes."""
    data = bytearray(source.read_bytes())
    require(data[:6] == b"\x7fELF\x01\x01", "expected little-endian ELF32")
    section_offset = struct.unpack_from("<I", data, 32)[0]
    entry_size, section_count, string_index = struct.unpack_from("<HHH", data, 46)
    strings_header = section_offset + string_index * entry_size
    strings_offset, strings_size = struct.unpack_from("<II", data, strings_header + 16)
    strings = bytes(data[strings_offset:strings_offset + strings_size])
    sections = []
    for index in range(section_count):
        header = section_offset + index * entry_size
        name_offset = struct.unpack_from("<I", data, header)[0]
        end = strings.find(b"\0", name_offset)
        name = strings[name_offset:end].decode()
        if name == ".text":
            sections.append((index, header))
    require(sections, "no .text sections found")
    renamed = bytearray(strings)
    for index, header in sections:
        name_offset = len(renamed)
        renamed.extend(f".text_{index}".encode() + b"\0")
        struct.pack_into("<I", data, header, name_offset)
    new_strings_offset = len(data)
    data.extend(renamed)
    struct.pack_into("<II", data, strings_header + 16, new_strings_offset, len(renamed))
    destination.write_bytes(data)
    return [index for index, _ in sections]

definspect_object(path):
    """Check the entry symbol, private sections, BREAK sequence, and imports."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        require(elf.header["e_type"] == "ET_REL", "candidate is not ET_REL")
        table = elf.get_section_by_name(".symtab")
        function = unique_symbol(table, FUNCTION)
        require(function["st_info"]["type"] == "STT_FUNC", "entry is not a function")
        require(function["st_size"] == 360, "unexpected emitted entry size")
        text_indices = [index for index, section in enumerate(elf.iter_sections())
                        if section.name == ".text"]
        require(function["st_shndx"] in text_indices, "entry is not in a .text section")
        grid = unique_symbol(table, "grid_count")
        grid_section = elf.get_section(grid["st_shndx"])
        words = struct.unpack("<" + "I" * (len(grid_section.data()) // 4), grid_section.data())
        require(0x000001CD in words, "grid_count lacks MIPS BREAK 0,7")
        require(any((word & 0xFC000000) == 0x54000000 for word in words),
                "grid_count lacks the conditional divide guard")
        require(any((word & 0x3F) == 0x1A for word in words), "grid_count lacks DIV")
        undefined = {symbol.name for symbol in table.iter_symbols()
                     if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"}
        require(undefined == set(EXTERNALS), f"unexpected imports: {sorted(undefined)}")
        function_sections = {symbol["st_shndx"] for symbol in table.iter_symbols()
                             if symbol["st_info"]["type"] == "STT_FUNC"
                             and isinstance(symbol["st_shndx"], int)}
        require(set(text_indices) <= function_sections, "unaccounted .text section")
        private_bytes = sum(elf.get_section(index)["sh_size"] for index in text_indices
                           if index != function["st_shndx"])
        return function["st_shndx"], text_indices, private_bytes, len(undefined)

deflink_candidate(linker, candidate, directory, text_indices, main_index):
    """Link every real text section while placing the entry at its original VRAM."""
    script = directory / "candidate.ld"
    definitions = "".join(f"{name} = {address:#x};\n"
                          for name, address in EXTERNALS.items())
    definitions += f"_gp = {GP:#x};\n"
    private_sections = " ".join(f"*(.text_{index})" for index in text_indices
                                 if index != main_index)
    script.write_text(
        definitions + f"SECTIONS {{ .entry {START:#x} : {{ *(.text_{main_index}) }} "
        f".private 0x219000 : {{ {private_sections} }} "
        "/DISCARD/ : { *(*) } }\n"
    )
    output = directory / "candidate.elf"
    subprocess.run([str(linker), "-EL", "-m", "elf32ltsmip", "--no-undefined",
                    "-T", str(script), "-o", str(output), str(candidate)], check=True)
    return output

definspect_link(path, original, private_bytes):
    """Verify final symbols and report complete unmasked extent metrics."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        require(elf.header["e_type"] == "ET_EXEC", "output is not ET_EXEC")
        table = elf.get_section_by_name(".symtab")
        require(not [symbol.name for symbol in table.iter_symbols()
                     if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"],
                "linked output has unresolved symbols")
        function = unique_symbol(table, FUNCTION)
        require(function["st_value"] == START, "entry is not at original address")
        entry_section = elf.get_section(function["st_shndx"])
        generated = entry_section.data()[:function["st_size"]]
        private = elf.get_section_by_name(".private")
        require(private is not None and private["sh_size"] >= private_bytes,
                "private helper sections were cropped")
        linked_private_bytes = private["sh_size"]
    overlap = min(len(generated), len(original))
    equal = sum(left == right for left, right in zip(generated[:overlap], original[:overlap]))
    different = overlap - equal
    missing = len(original) - overlap
    extra = max(0, len(generated) - len(original))
    print(f"ET_EXEC: {FUNCTION}={START:#x}, size={len(generated)}, unresolved=0, _gp={GP:#x}")
    print(f"Raw unmasked 848-byte slice: equal={equal}, different={different}, "
          f"missing={missing}, extra={extra}; overlap={overlap}")
    print(f"Retained private .text bytes={private_bytes}, linked private extent="
          f"{linked_private_bytes} (alignment padding={linked_private_bytes - private_bytes}); "
          f"full linked code extent={linked_private_bytes + len(generated)}")

defmain():
    """Run source-object, original-slice, and GNU final-link checks."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--object", type=Path,
                        default=Path("build/SLES-50282/src/trade_action_helper_2184D0.o"))
    parser.add_argument("--original", type=Path, default=Path("orig/SLES-50282/AOK.ELF"))
    parser.add_argument("--linker", type=Path,
                        default=Path("build/mips_binutils/mips-linux-gnu-ld"))
    arguments = parser.parse_args()
    for path in (arguments.object, arguments.original, arguments.linker):
        require(path.is_file(), f"missing input {path}")
    original = original_slice(arguments.original)
    with tempfile.TemporaryDirectory(prefix="trade-action-helper-2184D0-") as temporary:
        directory = Path(temporary)
        candidate = directory / "candidate.o"
        indices = rename_text_sections(arguments.object, candidate)
        main_index, text_indices, private_bytes, external_count = inspect_object(arguments.object)
        require(indices == text_indices, "section-index mapping changed")
        linked = link_candidate(arguments.linker.resolve(), candidate, directory,
                                text_indices, main_index)
        inspect_link(linked, original, private_bytes)
    print(f"ET_REL .text sections={len(indices)}, private bytes={private_bytes}, "
          f"real external symbols={external_count}; BREAK7 verified through grid_count st_shndx")


if __name__ == "__main__":
    try:
        main()
    except (OSError, RuntimeError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"BLOCKER: {error}") from error
