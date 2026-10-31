"""Compile and compare the trade action stream decoders19."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders19_support")

from trade_action_stream_decoders19_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F18C0_OFFSET, F18C0_SIZE, F1AB0_OFFSET, F1AB0_SIZE,
    F1D20_OFFSET, F1D20_SIZE, F1ED0_OFFSET, F1ED0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD4_OFFSET, PAD4_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping,
    read_original,
)

pytest_plugins = ("trade_action_stream_decoders19_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 2,024 compiler code bytes plus 24 linker/slice-alignment bytes = 2,048B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_001618C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001618C0 (488 bytes, 100% exact)."""
    actual = decoder_code[F18C0_OFFSET:F18C0_OFFSET + F18C0_SIZE]
    expected = read_original(original_image, F18C0_OFFSET, F18C0_SIZE)
    assert_same_code(actual, expected, START_ADDRESS + F18C0_OFFSET)


def test_func_001618C0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_001618C0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00161AB0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00161AB0 (620 bytes / 155 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F1AB0_OFFSET:F1AB0_OFFSET + F1AB0_SIZE],
        read_original(original_image, F1AB0_OFFSET, F1AB0_SIZE),
        START_ADDRESS + F1AB0_OFFSET,
    )


def test_func_00161AB0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00161AB0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00161D20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00161D20 (432 bytes / 108 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F1D20_OFFSET:F1D20_OFFSET + F1D20_SIZE],
        read_original(original_image, F1D20_OFFSET, F1D20_SIZE),
        START_ADDRESS + F1D20_OFFSET,
    )


def test_func_00161ED0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00161ED0 (484 bytes / 121 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F1ED0_OFFSET:F1ED0_OFFSET + F1ED0_SIZE],
        read_original(original_image, F1ED0_OFFSET, F1ED0_SIZE),
        START_ADDRESS + F1ED0_OFFSET,
    )


def test_func_00161ED0_tail_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00161ED0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
