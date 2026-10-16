"""ELF structure checks for the trade-action helper proof."""

from hashlib import sha1
from io import BytesIO
import struct

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


def require(condition, message):
    """Raise a clear error when an ELF verification fails."""
    if not condition:
        raise RuntimeError(message)


def unique_symbol(table, name):
    """Find exactly one named ELF symbol."""
    matches = table.get_symbol_by_name(name)
    require(matches is not None and len(matches) == 1, f"expected one {name}")
    return matches[0]


def original_slice(path):
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


def rename_text_sections(source, destination):
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


def inspect_object(path):
    """Check the entry symbol, private sections, BREAK sequence, and imports."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        require(elf.header["e_type"] == "ET_REL", "candidate is not ET_REL")
        table = elf.get_section_by_name(".symtab")
        function = unique_symbol(table, FUNCTION)
        require(function["st_info"]["type"] == "STT_FUNC", "entry is not a function")
        require(function["st_size"] == 364, "unexpected emitted entry size")
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
        function_sections = {
            symbol["st_shndx"]
            for symbol in table.iter_symbols()
            if symbol["st_info"]["type"] == "STT_FUNC"
            and isinstance(symbol["st_shndx"], int)
        }
        require(set(text_indices) <= function_sections, "unaccounted .text section")
        private_bytes = sum(
            elf.get_section(index)["sh_size"]
            for index in text_indices
            if index != function["st_shndx"]
        )
        return function["st_shndx"], text_indices, private_bytes, len(undefined)
