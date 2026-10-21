"""Reject an object whose relocation count is right but one HI16 is unpaired."""

import struct

from elftools.elf.elffile import ELFFile
import pytest

import network_match_support as support


EXTERNALS = {
    "func_104D40": 0x104D40,
    "func_104D60": 0x104D60,
    "func_118de0": 0x118DE0,
    "func_388D60": 0x388D60,
    "D_004E3538": 0x4E3538,
    "D_004E3560": 0x4E3560,
    "D_004D1EB0": 0x4D1EB0,
    "D_004D1ED0": 0x4D1ED0,
}


def test_unpaired_high_relocation_fails_even_with_expected_count(tmp_path):
    """An unpaired HI16 cannot pass by merely preserving the relocation count."""
    missing = support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    original = support.compile_object(
        support.ROOT / "src/network_send_checked_337840.cpp", tmp_path)
    with original.open("rb") as stream:
        elf = ELFFile(stream)
        lo_entries = [
            section.header.sh_offset + index * section.header.sh_entsize
            for section in elf.iter_sections()
            if section["sh_type"] == "SHT_REL" and elf.get_section(section["sh_info"]).name == ".text"
            for index, relocation in enumerate(section.iter_relocations())
            if relocation["r_info_type"] == support.R_MIPS_LO16
        ]
    assert len(lo_entries) == 2
    image = bytearray(original.read_bytes())
    offset = lo_entries[0] + 4
    info = struct.unpack_from("<I", image, offset)[0]
    struct.pack_into("<I", image, offset, (info & ~0xFF) | support.R_MIPS_HI16)
    mutant = tmp_path / "unpaired.o"
    mutant.write_bytes(image)
    with pytest.raises(AssertionError, match="unpaired HI16"):
        support.relocated_function(
            mutant, "func_00337840", 0x337840, 0x88, EXTERNALS, 12)
