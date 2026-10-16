"""Compile and compare the trade action stream decoders71."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders71_support")

from trade_action_stream_decoders71_support import (  # noqa: E402
    FF000_OFFSET, FF000_SIZE, FF080_OFFSET, FF080_SIZE,
    FF100_OFFSET, FF100_SIZE, FF1A0_OFFSET, FF1A0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders71_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 576 compiler code bytes plus 16 linker/slice-alignment bytes = 592B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00172000_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172000 (124 bytes / 31 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF000_OFFSET:FF000_OFFSET + FF000_SIZE],
        read_original(original_image, FF000_OFFSET, FF000_SIZE),
        START_ADDRESS + FF000_OFFSET,
    )


def test_func_00172000_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00172000."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00172080_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172080 (124 bytes / 31 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF080_OFFSET:FF080_OFFSET + FF080_SIZE],
        read_original(original_image, FF080_OFFSET, FF080_SIZE),
        START_ADDRESS + FF080_OFFSET,
    )


def test_func_00172080_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00172080."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00172100_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172100 (152 bytes / 38 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF100_OFFSET:FF100_OFFSET + FF100_SIZE],
        read_original(original_image, FF100_OFFSET, FF100_SIZE),
        START_ADDRESS + FF100_OFFSET,
    )


def test_func_00172100_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00172100."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_001721A0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001721A0 (176 bytes / 44 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF1A0_OFFSET:FF1A0_OFFSET + FF1A0_SIZE],
        read_original(original_image, FF1A0_OFFSET, FF1A0_SIZE),
        START_ADDRESS + FF1A0_OFFSET,
    )
