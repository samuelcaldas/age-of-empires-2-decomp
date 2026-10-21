"""Rebuild every registered network function with the strict relocation resolver."""

from collections import Counter

import pytest
from elftools.elf.elffile import ELFFile

import network_match_support as support
from test_network_send_checked_337840_matching import EXTERNAL_SYMBOLS as SEND_EXTERNALS
from test_network_session_dispatch_3378d0_matching import EXTERNAL_SYMBOLS as SESSION_EXTERNALS
from test_network_buffer_enqueue_338470_matching import EXTERNAL_SYMBOLS as QUEUE_EXTERNALS
from test_network_transport_init_337d40_matching import (
    EXTERNALS as INIT_EXTERNALS,
    RELOCATIONS as INIT_RELOCATIONS,
)


FUNCTIONS = (
    ("src/network_init_3377d0.cpp", "func_003377D0", 0x3377D0, 80, 2,
     {"func_003379F0": 0x3379F0, "D_004E3568": 0x4E3568}),
    ("src/network_state_set_337820.cpp", "func_00337820", 0x337820, 8, 1,
     {"D_004E3530": 0x4E3530}),
    ("src/network_state_get_337830.cpp", "func_00337830", 0x337830, 8, 1,
     {"D_004E3530": 0x4E3530}),
    ("src/network_send_checked_337840.cpp", "func_00337840", 0x337840, 136, 12,
     SEND_EXTERNALS),
    ("src/network_session_dispatch_3378d0.cpp", "func_003378D0", 0x3378D0, 276, 25,
     SESSION_EXTERNALS),
    ("src/network_buffer_enqueue_338470.cpp", "func_00338470", 0x338470, 328, 16,
     QUEUE_EXTERNALS),
    ("src/network_transport_init_337d40.cpp", "func_00337D40", 0x337D40, 920,
     INIT_RELOCATIONS, INIT_EXTERNALS),
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
