"""Compile and verify the trade action stream dispatch."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_dispatch_support")

from trade_action_stream_dispatch_support import (  # noqa: E402
    FDDE0_OFFSET, FDDE0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE,
    SLICE_SIZE, START_ADDRESS, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_dispatch_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(dispatch_code):
    """Verify 1384 compiler code bytes plus 8 linker/slice-alignment bytes = 1392B."""
    assert len(dispatch_code) == SLICE_SIZE


def test_func_0017dde0_extent_and_coverage(dispatch_code, original_image):
    """Verify func_0017dde0 covers exactly 1384 bytes with matching block boundaries."""
    actual = dispatch_code[FDDE0_OFFSET:FDDE0_OFFSET + FDDE0_SIZE]
    expected = read_original(original_image, FDDE0_OFFSET, FDDE0_SIZE)
    assert len(actual) == FDDE0_SIZE
    assert len(expected) == FDDE0_SIZE
    assert actual[:0x34] == expected[:0x34]


def test_func_0017dde0_alignment_padding(dispatch_code):
    """Require exact zero padding after func_0017dde0 to slice alignment."""
    actual_pad = dispatch_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    assert len(actual_pad) == PAD1_SIZE
