"""Compile and compare the trade action stream decoders90."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders90_support")

from trade_action_stream_decoders90_support import (  # noqa: E402
    FF700_OFFSET, FF700_SIZE, FF830_OFFSET, FF830_SIZE,
    FF930_OFFSET, FF930_SIZE, FFA50_OFFSET, FFA50_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders90_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1148 compiler code bytes plus 20 linker/slice-alignment bytes = 1168B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00175700_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175700 (304 bytes / 76 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF700_OFFSET:FF700_OFFSET + FF700_SIZE],
        read_original(original_image, FF700_OFFSET, FF700_SIZE),
        START_ADDRESS + FF700_OFFSET,
    )


def test_func_00175830_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175830 (248 bytes / 62 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF830_OFFSET:FF830_OFFSET + FF830_SIZE],
        read_original(original_image, FF830_OFFSET, FF830_SIZE),
        START_ADDRESS + FF830_OFFSET,
    )


def test_func_00175830_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00175830."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00175930_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175930 (280 bytes / 70 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF930_OFFSET:FF930_OFFSET + FF930_SIZE],
        read_original(original_image, FF930_OFFSET, FF930_SIZE),
        START_ADDRESS + FF930_OFFSET,
    )


def test_func_00175930_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00175930."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00175A50_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175A50 (316 bytes / 79 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFA50_OFFSET:FFA50_OFFSET + FFA50_SIZE],
        read_original(original_image, FFA50_OFFSET, FFA50_SIZE),
        START_ADDRESS + FFA50_OFFSET,
    )


def test_func_00175A50_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00175A50."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
