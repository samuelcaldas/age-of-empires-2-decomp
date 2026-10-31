"""Compile and compare the trade action stream decoders23."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders23_support")

from trade_action_stream_decoders23_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F3240_OFFSET, F3240_SIZE, F33B0_OFFSET, F33B0_SIZE,
    F3500_OFFSET, F3500_SIZE, F3600_OFFSET, F3600_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping,
    read_original,
)

pytest_plugins = ("trade_action_stream_decoders23_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,180 compiler code bytes plus 36 linker/slice-alignment bytes = 1,216B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00163240_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00163240 (368 bytes / 92 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F3240_OFFSET:F3240_OFFSET + F3240_SIZE],
        read_original(original_image, F3240_OFFSET, F3240_SIZE),
        START_ADDRESS + F3240_OFFSET,
    )


def test_func_001633B0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001633B0 (324 bytes / 81 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F33B0_OFFSET:F33B0_OFFSET + F33B0_SIZE],
        read_original(original_image, F33B0_OFFSET, F33B0_SIZE),
        START_ADDRESS + F33B0_OFFSET,
    )


def test_func_001633B0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001633B0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00163500_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00163500 (244 bytes / 61 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F3500_OFFSET:F3500_OFFSET + F3500_SIZE],
        read_original(original_image, F3500_OFFSET, F3500_SIZE),
        START_ADDRESS + F3500_OFFSET,
    )


def test_func_00163500_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00163500."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00163600_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00163600 (244 bytes / 61 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F3600_OFFSET:F3600_OFFSET + F3600_SIZE],
        read_original(original_image, F3600_OFFSET, F3600_SIZE),
        START_ADDRESS + F3600_OFFSET,
    )


def test_func_00163600_tail_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00163600."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
