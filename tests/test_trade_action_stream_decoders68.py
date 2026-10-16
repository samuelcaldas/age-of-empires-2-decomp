"""Compile and compare the trade action stream decoders68."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders68_support")

from trade_action_stream_decoders68_support import (  # noqa: E402
    FF850_OFFSET, FF850_SIZE, FFA50_OFFSET, FFA50_SIZE,
    FFC50_OFFSET, FFC50_SIZE, FFC70_OFFSET, FFC70_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders68_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1088 compiler code bytes plus 32 linker/slice-alignment bytes = 1120B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00171850_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171850 (500 bytes / 125 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF850_OFFSET:FF850_OFFSET + FF850_SIZE],
        read_original(original_image, FF850_OFFSET, FF850_SIZE),
        START_ADDRESS + FF850_OFFSET,
    )


def test_func_00171850_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00171850."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00171A50_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171A50 (508 bytes / 127 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFA50_OFFSET:FFA50_OFFSET + FFA50_SIZE],
        read_original(original_image, FFA50_OFFSET, FFA50_SIZE),
        START_ADDRESS + FFA50_OFFSET,
    )


def test_func_00171A50_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00171A50."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00171C50_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171C50 (28 bytes / 7 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFC50_OFFSET:FFC50_OFFSET + FFC50_SIZE],
        read_original(original_image, FFC50_OFFSET, FFC50_SIZE),
        START_ADDRESS + FFC50_OFFSET,
    )


def test_func_00171C50_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00171C50."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00171C70_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171C70 (52 bytes / 13 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFC70_OFFSET:FFC70_OFFSET + FFC70_SIZE],
        read_original(original_image, FFC70_OFFSET, FFC70_SIZE),
        START_ADDRESS + FFC70_OFFSET,
    )


def test_func_00171C70_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00171C70."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
