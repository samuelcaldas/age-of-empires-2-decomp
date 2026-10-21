"""Rebuild every registered network function with the strict relocation resolver."""

import pytest

import network_match_support as support
from test_network_send_checked_337840_matching import EXTERNAL_SYMBOLS as SEND_EXTERNALS
from test_network_session_dispatch_3378d0_matching import EXTERNAL_SYMBOLS as SESSION_EXTERNALS
from test_network_buffer_enqueue_338470_matching import EXTERNAL_SYMBOLS as QUEUE_EXTERNALS


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
