"""Regression coverage for strict relocation pairing."""
import struct

import pytest

import network_match_support as support


class Symbol(dict):
    name = "peer"


class Relocations(dict):
    def __init__(self, kinds):
        super().__init__(sh_type="SHT_REL", sh_info=1)
        self.kinds = kinds

    def iter_relocations(self):
        return iter(dict(r_offset=i * 4, r_info_type=kind, r_info_sym=0)
                    for i, kind in enumerate(self.kinds))


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


def test_overlapping_hi16_registers_resolve_independently():
    assert relocate([5, 5, 6, 6], [0x3C010000, 0x3C020000, 0x24450000, 0xAC260004]) == (
        0x3C010109, 0x3C020109, 0x244590C0, 0xAC2690C4)
