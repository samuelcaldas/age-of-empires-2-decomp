"""Require relocation-resolved MWCC matching for network_func_3379f0."""

import pytest
import network_match_support as support

EXTERNAL_SYMBOLS = {
    "D_004E3568": 0x4E3568,
    "D_004E356C": 0x4E356C,
    "D_004E352C": 0x4E352C,
    "D_004E3530": 0x4E3530,
    "D_004E3560": 0x4E3560,
    "D_004E3538": 0x4E3538,
    "D_004E3534": 0x4E3534,
    "D_004D1EE8": 0x4D1EE8,
    "D_004D1EF0": 0x4D1EF0,
    "D_004D1F00": 0x4D1F00,
    "func_11ABBC": 0x11ABBC,
    "func_104D60": 0x104D60,
    "func_104D40": 0x104D40,
    "func_388D60": 0x388D60,
}


def test_network_func_3379f0_matches_original_bytes(tmp_path):
    missing = support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    original = support.verified_original_image()
    output = support.compile_object(support.ROOT / "src/network/network_func_3379f0.cpp", tmp_path)
    actual = support.relocated_function(output, "func_003379F0", 0x3379F0, 316, EXTERNAL_SYMBOLS, 32)
    expected = support.original_bytes(original, 0x3379F0, 316)
    support.assert_exact(actual, expected, 0x3379F0)
    padding = support.original_bytes(original, 0x337B2C, 4)
    assert padding == bytes(4), f"trailing alignment is not zero: {padding.hex()}"
