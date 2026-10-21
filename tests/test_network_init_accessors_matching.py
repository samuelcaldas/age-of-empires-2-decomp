"""Require exact matches for the init loop and the two state accessors."""

import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parent))
import network_match_support as support  # noqa: E402

ROOT = support.ROOT

UNITS = (
    # source, function, address, size, relocations, externals, bytes after the function
    ("src/network_init_3377d0.cpp", "func_003377D0", 0x3377D0, 0x50, 2,
     {"func_003379F0": 0x3379F0, "D_004E3568": 0x4E3568}, 0),
    ("src/network_state_set_337820.cpp", "func_00337820", 0x337820, 8, 1,
     {"D_004E3530": 0x4E3530}, 8),
    ("src/network_state_get_337830.cpp", "func_00337830", 0x337830, 8, 1,
     {"D_004E3530": 0x4E3530}, 8),
)


@pytest.fixture(scope="module")
def original_image():
    missing = support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    return support.verified_original_image()


@pytest.mark.parametrize("source,name,address,size,relocations,externals,padding", UNITS)
def test_function_bytes_match_original(tmp_path, original_image, source, name, address,
                                       size, relocations, externals, padding):
    """Compare every relocated byte; the relocation count is asserted."""
    object_path = support.compile_object(ROOT / source, tmp_path)
    actual = support.relocated_function(object_path, name, address, size, externals, relocations)
    expected = support.original_bytes(original_image, address, size)
    support.assert_exact(actual, expected, address)


@pytest.mark.parametrize("source,name,address,size,relocations,externals,padding", UNITS)
def test_alignment_padding_is_zero(original_image, source, name, address, size,
                                   relocations, externals, padding):
    """The bytes between this function and the next are zero alignment."""
    assert support.original_bytes(original_image, address + size, padding) == b"\0" * padding
