"""Rebuild every registered network function with the strict relocation resolver."""

from collections import Counter

import pytest
from elftools.elf.elffile import ELFFile

import network_match_support as support
from test_network_send_checked_337840_matching import EXTERNAL_SYMBOLS as SEND_EXTERNALS
from test_network_session_dispatch_3378d0_matching import EXTERNAL_SYMBOLS as SESSION_EXTERNALS
from test_network_func_3379f0_matching import EXTERNAL_SYMBOLS as FUNC_3379F0_EXTERNALS
from test_network_buffer_enqueue_338470_matching import EXTERNAL_SYMBOLS as QUEUE_EXTERNALS
from test_network_transport_init_337d40_matching import (
    EXTERNALS as INIT_EXTERNALS,
    RELOCATIONS as INIT_RELOCATIONS,
)
from test_network_receiver_337B30_matching import (
    EXTERNALS as RECEIVER_EXTERNALS,
)


FUNCTIONS = (
    ("src/network/network_byte_swap_337520.cpp", "func_00337520", 0x337520, 60, 0, {}),
    ("src/network/network_byte_swap_337560.cpp", "func_00337560", 0x337560, 36, 0, {}),
    ("src/network/network_byte_swap_337590.cpp", "func_00337590", 0x337590, 60, 0, {}),
    ("src/network/network_byte_swap_3375d0.cpp", "func_003375D0", 0x3375D0, 36, 0, {}),
    ("src/network/network_address_format_337600.cpp", "func_00337600", 0x337600, 92, 7,
     {"func_11A498": 0x11A498, "D_004D1E88": 0x4D1E88, "D_01087EB0": 0x1087EB0}),
    ("src/network/network_address_parse_337660.cpp", "func_00337660", 0x337660, 360, 5,
     {"func_11A510": 0x11A510, "D_004D1EA0": 0x4D1EA0, "D_0048E101": 0x48E101}),
    ("src/network/network_init_3377d0.cpp", "func_003377D0", 0x3377D0, 80, 2,
     {"func_003379F0": 0x3379F0, "D_004E3568": 0x4E3568}),
    ("src/network/network_state_set_337820.cpp", "func_00337820", 0x337820, 8, 1,
     {"D_004E3530": 0x4E3530}),
    ("src/network/network_state_get_337830.cpp", "func_00337830", 0x337830, 8, 1,
     {"D_004E3530": 0x4E3530}),
    ("src/network/network_send_checked_337840.cpp", "func_00337840", 0x337840, 136, 12,
     SEND_EXTERNALS),
    ("src/network/network_session_dispatch_3378d0.cpp", "func_003378D0", 0x3378D0, 276, 25,
     SESSION_EXTERNALS),
    ("src/network/network_func_3379f0.cpp", "func_003379F0", 0x3379F0, 316, 32,
     FUNC_3379F0_EXTERNALS),
    ("src/network/network_buffer_enqueue_338470.cpp", "func_00338470", 0x338470, 328, 16,
     QUEUE_EXTERNALS),
    ("src/network/network_transport_init_337d40.cpp", "func_00337D40", 0x337D40, 920,
     INIT_RELOCATIONS, INIT_EXTERNALS),
    ("src/network/network_receiver_337B30.cpp", "func_00337B30", 0x337B30, 524, 54,
     RECEIVER_EXTERNALS),
    ("src/network/network_dplay_create_3380e0.cpp", "func_003380E0", 0x3380E0, 84, 11,
     {"D_01087ED0": 0x1087ED0, "D_010890A0": 0x10890A0, "func_003381A0": 0x3381A0}),
    ("src/network/network_dplay_enum_338140.cpp", "func_00338140", 0x338140, 60, 4,
     {"D_00492C50": 0x492C50, "D_004D20F0": 0x4D20F0}),
    ("src/network/network_dplay_stub_338180.cpp", "func_00338180", 0x338180, 8, 0, {}),
    ("src/network/network_dplay_stub_338190.cpp", "func_00338190", 0x338190, 8, 0, {}),
    ("src/network/network_dplay_reset_3381a0.cpp", "func_003381A0", 0x3381A0, 144, 4,
     {"func_117CAC": 0x117CAC, "func_00338180": 0x338180}),
    ("src/network/network_dplay_ctor_338230.cpp", "func_00338230", 0x338230, 44, 1,
     {"func_003381A0": 0x3381A0}),
    ("src/network/network_dplay_dtor_338260.cpp", "func_00338260", 0x338260, 100, 4,
     {"func_339270": 0x339270, "func_00338180": 0x338180, "func_003381A0": 0x3381A0, "func_100670": 0x100670}),
    ("src/network/network_dplay_find_free_slot_3382d0.cpp", "func_003382D0", 0x3382D0, 64, 0, {}),
    ("src/network/network_dplay_find_slot_by_id_338310.cpp", "func_00338310", 0x338310, 64, 0, {}),
    ("src/network/network_dplay_generate_id_338350.cpp", "func_00338350", 0x338350, 96, 1,
     {"func_1AAB30": 0x1AAB30}),
    ("src/network/network_dplay_send_packet_3383b0.cpp", "func_003383B0", 0x3383B0, 188, 5,
     {"func_117AF8": 0x117AF8, "func_00337840": 0x337840, "func_118de0": 0x118DE0, "D_004D2110": 0x4D2110}),
    ("src/network/network_message_handler_3385c0.cpp", "func_003385C0", 0x3385C0, 940, 32,
     {"D_004D1F10": 0x4D1F10, "D_004D1F18": 0x4D1F18, "func_00337840": 0x337840,
      "func_00338190": 0x338190, "func_003382D0": 0x3382D0, "func_00338310": 0x338310,
      "func_00338470": 0x338470, "func_117A64": 0x117A64, "func_117AF8": 0x117AF8,
      "func_117CAC": 0x117CAC, "func_11ABBC": 0x11ABBC, "func_11B170": 0x11B170}),
    ("src/network/network_dplay_get_player_name_338970.cpp", "func_00338970", 0x338970, 148, 1,
     {"func_00338310": 0x338310}),
    ("src/network/network_dplay_get_queue_count_338a10.cpp", "func_00338A10", 0x338A10, 16, 0, {}),
    ("src/network/network_dplay_receive_338a20.cpp", "func_00338A20", 0x338A20, 368, 11,
     {"D_004E3560": 0x4E3560, "func_104D60": 0x104D60, "func_104D40": 0x104D40, "func_117AF8": 0x117AF8}),
    ("src/network/network_dplay_send_338b90.cpp", "func_00338B90", 0x338B90, 196, 2,
     {"func_003383B0": 0x3383B0}),
    ("src/network/network_dplay_release_338c60.cpp", "func_00338C60", 0x338C60, 80, 2,
     {"func_00338180": 0x338180, "func_003381A0": 0x3381A0}),
    ("src/network/network_dplay_init_338cb0.cpp", "func_00338CB0", 0x338CB0, 8, 0, {}),
    ("src/network/network_dplay_query_interface_338cc0.cpp", "func_00338CC0", 0x338CC0, 32, 2,
     {"D_01087ED0": 0x1087ED0}),
    ("src/network/network_session_request_338ce0.cpp", "func_00338CE0", 0x338CE0, 700, 40,
     {"func_117af8": 0x117AF8, "func_117cac": 0x117CAC, "func_11abbc": 0x11ABBC,
      "func_11acd0": 0x11ACD0, "func_11b170": 0x11B170, "func_337840": 0x337840,
      "func_103358": 0x103358, "func_2261C0": 0x2261C0, "D_004E352C": 0x4E352C,
      "D_0108AFA0": 0x108AFA0, "D_00492C60": 0x492C60, "D_004D1F18": 0x4D1F18,
      "D_004D1F10": 0x4D1F10}),
    ("src/network/network_join_request_338fa0.cpp", "func_00338FA0", 0x338FA0, 300, 9,
     {"func_00338350": 0x338350, "func_003382D0": 0x3382D0, "func_11B170": 0x11B170,
      "func_00335A20": 0x335A20, "func_117AF8": 0x117AF8, "func_003383B0": 0x3383B0}),
    ("src/network/network_dplay_get_player_caps_3390d0.cpp", "func_003390D0", 0x3390D0, 100, 2,
     {"func_00338310": 0x338310, "func_117AF8": 0x117AF8}),
    ("src/network/network_dplay_get_session_desc_339140.cpp", "func_00339140", 0x339140, 148, 1,
     {"func_117AF8": 0x117AF8}),
    ("src/network/network_dplay_get_caps_3391e0.cpp", "func_003391E0", 0x3391E0, 60, 0, {}),
    ("src/network/network_dplay_reset_queue_339220.cpp", "func_00339220", 0x339220, 68, 1,
     {"func_117CAC": 0x117CAC}),
    ("src/network/network_dplay_close_339270.cpp", "func_00339270", 0x339270, 56, 2,
     {"func_003392B0": 0x3392B0, "func_00338180": 0x338180}),
    ("src/network/network_dplay_send_destroy_3392b0.cpp", "func_003392B0", 0x3392B0, 80, 1,
     {"func_003383B0": 0x3383B0}),
    ("src/network/network_utf16_length_3394b0.cpp", "func_003394B0", 0x3394B0, 40, 0, {}),
)


@pytest.mark.parametrize("source,name,address,size,relocations,externals", FUNCTIONS)
def test_registered_network_function_exact(tmp_path, source, name, address, size,
                                           relocations, externals):
    """Reject a changed instruction, missing relocation, or wrong linked target."""
    missing = support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    original = support.verified_original_image()
    output = support.compile_object(support.ROOT / source, tmp_path)
    actual = support.relocated_function(output, name, address, size, externals, relocations)
    expected = support.original_bytes(original, address, size)
    support.assert_exact(actual, expected, address)
    if name == "func_00337D40":
        assert_initializer_manifest(output)
        padding = support.original_bytes(original, 0x3380D8, 8)
        assert padding == bytes(8), f"initializer padding is not zero: {padding.hex()}"
    if name == "func_00337B30":
        assert_receiver_manifest(output)
        padding = support.original_bytes(original, 0x337D3C, 4)
        assert padding == bytes(4), f"receiver alignment is not zero: {padding.hex()}"
        next_entry = support.original_bytes(original, 0x337D40, 12)
        assert next_entry == bytes.fromhex("a0ffbd273000bf7f2000b27f")


def assert_receiver_manifest(object_path):
    """Require all receiver relocation forms resolved by the exact test."""
    with object_path.open("rb") as stream:
        elf = ELFFile(stream)
        symbol = elf.get_section_by_name(".symtab").get_symbol_by_name("func_00337B30")[0]
        section_index = symbol["st_shndx"]
        types = Counter(
            relocation["r_info_type"]
            for section in elf.iter_sections()
            if section["sh_type"] == "SHT_REL" and section["sh_info"] == section_index
            for relocation in section.iter_relocations()
        )
    assert types == {4: 7, 5: 11, 6: 11, 7: 25}


def assert_initializer_manifest(object_path):
    """Require the verified relocation type counts for the PAL initializer."""
    with object_path.open("rb") as stream:
        elf = ELFFile(stream)
        symbol = elf.get_section_by_name(".symtab").get_symbol_by_name("func_00337D40")[0]
        section_index = symbol["st_shndx"]
        types = Counter(
            relocation["r_info_type"]
            for section in elf.iter_sections()
            if section["sh_type"] == "SHT_REL" and section["sh_info"] == section_index
            for relocation in section.iter_relocations()
        )
    assert types == {4: 20, 5: 34, 6: 34, 7: 19}
