"""Check each lifecycle function against the pinned original image."""

from pathlib import Path

import pytest
import network_match_support as match_support

ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("src/network_object_lifecycle_3380e0.cpp", "func_003380E0", 0x3380E0, 0x54, 8,
     {"D_010990A0": 0x108F90A0, "D_01087ED0": 0x1087ED0,
      "func_003381A0": 0x3381A0}),
    ("src/network_object_lifecycle_338140.cpp", "func_00338140", 0x338140, 0x3C, 4,
     {"D_00492C50": 0x492C50, "D_004D20F0": 0x4D20F0}),
    ("src/network_object_lifecycle_338180.cpp", "func_00338180", 0x338180, 0x8, 0, {}),
    ("src/network_object_lifecycle_3381a0.cpp", "func_003381A0", 0x3381A0, 0x90, 4,
     {"func_00117CAC": 0x117CAC, "func_00338180": 0x338180}),
    ("src/network_object_lifecycle_338230.cpp", "func_00338230", 0x338230, 0x2C, 1,
     {"func_003381A0": 0x3381A0}),
]


@pytest.mark.parametrize("source,name,address,size,relocations,externals", CASES)
def test_lifecycle_function_exact_match(tmp_path, source, name, address, size,
                                       relocations, externals):
    original = match_support.verified_original_image()
    object_path = match_support.compile_object(ROOT / source, tmp_path)
    actual = match_support.relocated_function(
        object_path, name, address, size, externals, relocations)
    expected = match_support.original_bytes(original, address, size)
    match_support.assert_exact(actual, expected, address)


def test_lifecycle_alignment_padding_is_zero():
    image = match_support.verified_original_image()
    assert match_support.original_bytes(image, 0x338134, 12) == bytes(12)
    assert match_support.original_bytes(image, 0x33817C, 4) == bytes(4)
    assert match_support.original_bytes(image, 0x338188, 8) == bytes(8)
    assert match_support.original_bytes(image, 0x33825C, 4) == bytes(4)
