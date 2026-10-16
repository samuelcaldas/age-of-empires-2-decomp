"""Compare compiled zone vtable stubs with original PS2 instructions."""

import re

import pytest

pytest.register_assert_rewrite("zone_vtable_stubs_matching_support")
from zone_vtable_stubs_matching_support import (  # noqa: E402
    EXPECTED_FUNCTIONS,
    PROJECT_ROOT,
    TAIL_PADDING_BYTES,
    compile_stubs,
    link_stubs,
    original_slice_bytes,
    require_toolchain,
    verify_object_symbols,
)


def test_zone_vtable_stubs_symbol_registration():
    """Require unique original function addresses and sizes in slicer metadata."""
    symbols = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, info in EXPECTED_FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9A-Fa-f]+); // type:func size:(0x[0-9A-Fa-f]+)\b"
        matches = re.findall(pattern, symbols, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [
            (info["vram"], info["size"])
        ]


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
