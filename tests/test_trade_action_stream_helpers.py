"""Compile and compare the trade action stream helpers."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_helpers_support")

from trade_action_stream_helpers_support import (  # noqa: E402
    FDBD0_OFFSET, FDBD0_SIZE, FDC40_OFFSET, FDC40_SIZE,
    FDCA0_OFFSET, FDCA0_SIZE, FDCF0_OFFSET, FDCF0_SIZE,
    FDD10_OFFSET, FDD10_SIZE, FDD90_OFFSET, FDD90_SIZE,
    FDDD0_OFFSET, FDDD0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, PAD5_OFFSET, PAD5_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_helpers_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(helper_code):
    """Verify 484 compiler code bytes plus 44 linker/slice-alignment bytes = 528B."""
    assert len(helper_code) == SLICE_SIZE


def test_functions_exact_bytes(helper_code, original_image):
    """Require exact instructions for all 7 helper functions (100% exact)."""
    for offset, size in (
        (FDBD0_OFFSET, FDBD0_SIZE),
        (FDC40_OFFSET, FDC40_SIZE),
        (FDCA0_OFFSET, FDCA0_SIZE),
        (FDCF0_OFFSET, FDCF0_SIZE),
        (FDD10_OFFSET, FDD10_SIZE),
        (FDD90_OFFSET, FDD90_SIZE),
        (FDDD0_OFFSET, FDDD0_SIZE),
    ):
        assert_same_code(
            helper_code[offset:offset + size],
            read_original(original_image, offset, size),
            START_ADDRESS + offset,
        )


def test_alignment_paddings(helper_code, original_image):
    """Require exact zero padding after helper functions."""
    for offset, size in (
        (PAD1_OFFSET, PAD1_SIZE),
        (PAD2_OFFSET, PAD2_SIZE),
        (PAD3_OFFSET, PAD3_SIZE),
        (PAD4_OFFSET, PAD4_SIZE),
        (PAD5_OFFSET, PAD5_SIZE),
    ):
        actual_pad = helper_code[offset:offset + size]
        expected_pad = read_original(original_image, offset, size)
        assert_same_code(actual_pad, expected_pad, START_ADDRESS + offset)
