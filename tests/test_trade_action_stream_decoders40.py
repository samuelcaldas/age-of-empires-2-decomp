"""Compile and compare the trade action stream decoders40."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders40_support")

from trade_action_stream_decoders40_support import (  # noqa: E402
    F99F0_OFFSET, F99F0_SIZE, F9A40_OFFSET, F9A40_SIZE,
    F9A90_OFFSET, F9A90_SIZE, F9B10_OFFSET, F9B10_SIZE, FILE_OFFSET,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders40_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 424 compiler code bytes plus 8 linker/slice-alignment bytes = 432B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_001699F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001699F0 (80 bytes / 20 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F99F0_OFFSET:F99F0_OFFSET + F99F0_SIZE],
        read_original(original_image, F99F0_OFFSET, F99F0_SIZE),
        START_ADDRESS + F99F0_OFFSET,
    )


def test_func_00169A40_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169A40 (80 bytes / 20 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9A40_OFFSET:F9A40_OFFSET + F9A40_SIZE],
        read_original(original_image, F9A40_OFFSET, F9A40_SIZE),
        START_ADDRESS + F9A40_OFFSET,
    )


def test_func_00169A90_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169A90 (124 bytes / 31 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9A90_OFFSET:F9A90_OFFSET + F9A90_SIZE],
        read_original(original_image, F9A90_OFFSET, F9A90_SIZE),
        START_ADDRESS + F9A90_OFFSET,
    )


def test_func_00169A90_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00169A90."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00169B10_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169B10 (140 bytes / 35 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9B10_OFFSET:F9B10_OFFSET + F9B10_SIZE],
        read_original(original_image, F9B10_OFFSET, F9B10_SIZE),
        START_ADDRESS + F9B10_OFFSET,
    )


def test_func_00169B10_tail_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00169B10."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
