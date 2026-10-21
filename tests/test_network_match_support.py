"""Regression coverage for exact MIPS relocation pairing."""

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


class Symbol(dict):
    name = "peer"


class Relocations(dict):
    def __init__(self, kinds):
        super().__init__(sh_type="SHT_REL", sh_info=1)
        self.kinds = kinds

    def iter_relocations(self):
        return iter(dict(r_offset=index * 4, r_info_type=kind, r_info_sym=0)
                    for index, kind in enumerate(self.kinds))


class Elf:
    def __init__(self, kinds):
        self.relocations = Relocations(kinds)

    def get_section_by_name(self, name):
        assert name == ".symtab"
        return self

    def get_symbol(self, index):
        assert index == 0
        return Symbol(st_shndx="SHN_UNDEF")

    def iter_sections(self):
        return iter([self.relocations])


def relocate(kinds, words):
    code = bytearray(struct.pack("<" + "I" * len(words), *words))
    support.apply_relocations(Elf(kinds), 1, code, 0x337B30,
                              {"peer": 0x10890C0}, len(kinds))
    return struct.unpack("<" + "I" * len(words), code)


def test_hi16_lo16_signed_carry():
    assert relocate([5, 6], [0x3C020000, 0x24420004]) == (0x3C020109, 0x244290C4)


def test_hi16_cannot_be_reused():
    with pytest.raises(AssertionError, match="LO16 without HI16"):
        relocate([5, 6, 6], [0x3C020000, 0x24420004, 0x24420008])


def test_hi16_must_be_consumed():
    with pytest.raises(AssertionError, match="unpaired HI16"):
        relocate([5], [0x3C020000])


def test_hi16_cannot_be_overwritten():
    with pytest.raises(AssertionError, match="overlapping HI16"):
        relocate([5, 5, 6], [0x3C020000, 0x3C020000, 0x24420004])


def test_interleaved_register_pairs_resolve_by_operands():
    actual = relocate([5, 5, 6, 6],
                      [0x3C010000, 0x3C020000, 0x24450000, 0xAC260004])
    assert actual == (0x3C010109, 0x3C020109, 0x244590C0, 0xAC2690C4)


def test_unpaired_high_relocation_fails_even_with_expected_count(tmp_path):
    """A mutated real object cannot pass with a count-only relocation check."""
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
            if section["sh_type"] == "SHT_REL"
            and elf.get_section(section["sh_info"]).name == ".text"
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
    with pytest.raises(AssertionError, match="HI16"):
        support.relocated_function(
            mutant, "func_00337840", 0x337840, 0x88, EXTERNALS, 12)
