"""Compile and compare the trade action stream decoders74."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders74_support")

from trade_action_stream_decoders74_support import (  # noqa: E402
    FF830_OFFSET, FF830_SIZE, FF8F0_OFFSET, FF8F0_SIZE,
    FF9C0_OFFSET, FF9C0_SIZE, FFAB0_OFFSET, FFAB0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders74_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 804 compiler code bytes plus 28 linker/slice-alignment bytes = 832B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00172830_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172830 (184 bytes / 46 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF830_OFFSET:FF830_OFFSET + FF830_SIZE],
        read_original(original_image, FF830_OFFSET, FF830_SIZE),
        START_ADDRESS + FF830_OFFSET,
    )


def test_func_00172830_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00172830."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_001728F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001728F0 (208 bytes / 52 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF8F0_OFFSET:FF8F0_OFFSET + FF8F0_SIZE],
        read_original(original_image, FF8F0_OFFSET, FF8F0_SIZE),
        START_ADDRESS + FF8F0_OFFSET,
    )


def test_func_001729C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001729C0 (232 bytes / 58 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF9C0_OFFSET:FF9C0_OFFSET + FF9C0_SIZE],
        read_original(original_image, FF9C0_OFFSET, FF9C0_SIZE),
        START_ADDRESS + FF9C0_OFFSET,
    )


def test_func_001729C0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_001729C0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00172AB0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172AB0 (180 bytes / 45 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFAB0_OFFSET:FFAB0_OFFSET + FFAB0_SIZE],
        read_original(original_image, FFAB0_OFFSET, FFAB0_SIZE),
        START_ADDRESS + FFAB0_OFFSET,
    )


def test_func_00172AB0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00172AB0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
