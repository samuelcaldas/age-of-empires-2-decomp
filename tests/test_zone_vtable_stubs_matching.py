"""Compare compiled zone vtable stubs with original PS2 instructions."""

import pytest

from zone_vtable_stubs_matching_support import (
    EXPECTED_FUNCTIONS,
    TAIL_PADDING_BYTES,
    compile_stubs,
    link_stubs,
    original_slice_bytes,
    require_toolchain,
    verify_object_symbols,
)


def test_zone_vtable_stubs_matches_original_after_resolving_externals(tmp_path):
    """Require all 248 emitted bytes to match the original without undefined symbols."""
    require_toolchain()
    expected_code, expected_tail, slice_data = original_slice_bytes()
    object_path = compile_stubs(tmp_path)
    verify_object_symbols(object_path)
    actual_code = link_stubs(tmp_path, object_path)

    for name, info in EXPECTED_FUNCTIONS.items():
        offset = info["offset"]
        size = info["size"]
        assert actual_code[offset:offset + size] == slice_data[offset:offset + size], (
            f"Byte mismatch in {name}"
        )

    assert actual_code[8:16] == b"\x00" * 8, "Internal alignment must be eight zero bytes"
    assert slice_data[8:16] == b"\x00" * 8, "Original internal alignment must be zero"
    assert actual_code == expected_code, "Emitted code must match original PT_LOAD bytes"
    assert expected_tail == b"\x00" * TAIL_PADDING_BYTES, "Tail padding must be eight zero bytes"
