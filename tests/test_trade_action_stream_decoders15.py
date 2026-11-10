"""Compile and compare the trade action stream decoders15."""

import struct

import pytest

# Preserve assertion diagnostics before pytest loads the support module as a plugin.
pytest.register_assert_rewrite("trade_action_stream_decoders15_support")

from trade_action_stream_decoders15_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F0050_OFFSET, F0050_SIZE, F01F0_OFFSET, F01F0_SIZE,
    FD70_OFFSET, FD70_SIZE, FF00_OFFSET, FF00_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping,
    read_original,
)

pytest_plugins = ("trade_action_stream_decoders15_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,656 compiler code bytes plus 24 linker/slice-alignment bytes = 1,680B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0015FD70_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0015FD70 (392 bytes, 100% exact)."""
    actual = decoder_code[FD70_OFFSET:FD70_OFFSET + FD70_SIZE]
    expected = read_original(original_image, FD70_OFFSET, FD70_SIZE)
    assert_same_code(actual, expected, START_ADDRESS + FD70_OFFSET)


def test_func_0015FD70_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0015FD70."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0015FF00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0015FF00 (336 bytes / 84 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF00_OFFSET:FF00_OFFSET + FF00_SIZE],
        read_original(original_image, FF00_OFFSET, FF00_SIZE),
        START_ADDRESS + FF00_OFFSET,
    )


def test_func_00160050_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00160050 (404 bytes / 101 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F0050_OFFSET:F0050_OFFSET + F0050_SIZE],
        read_original(original_image, F0050_OFFSET, F0050_SIZE),
        START_ADDRESS + F0050_OFFSET,
    )


def test_func_00160050_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00160050."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_001601F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001601F0 (524 bytes / 131 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F01F0_OFFSET:F01F0_OFFSET + F01F0_SIZE],
        read_original(original_image, F01F0_OFFSET, F01F0_SIZE),
        START_ADDRESS + F01F0_OFFSET,
    )


def test_func_001601F0_tail_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001601F0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
