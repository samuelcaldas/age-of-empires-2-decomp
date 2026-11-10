"""Compile and compare the trade action stream decoders22."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders22_support")

from trade_action_stream_decoders22_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F3020_OFFSET, F3020_SIZE, F3080_OFFSET, F3080_SIZE,
    F30E0_OFFSET, F30E0_SIZE, F3180_OFFSET, F3180_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD4_OFFSET, PAD4_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping,
    read_original,
)

pytest_plugins = ("trade_action_stream_decoders22_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 520 compiler code bytes plus 24 linker/slice-alignment bytes = 544B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00163020_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00163020 (88 bytes / 22 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F3020_OFFSET:F3020_OFFSET + F3020_SIZE],
        read_original(original_image, F3020_OFFSET, F3020_SIZE),
        START_ADDRESS + F3020_OFFSET,
    )


def test_func_00163020_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00163020."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00163080_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00163080 (88 bytes / 22 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F3080_OFFSET:F3080_OFFSET + F3080_SIZE],
        read_original(original_image, F3080_OFFSET, F3080_SIZE),
        START_ADDRESS + F3080_OFFSET,
    )


def test_func_00163080_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00163080."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_001630E0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001630E0 (160 bytes, 100% exact)."""
    assert_same_code(
        decoder_code[F30E0_OFFSET:F30E0_OFFSET + F30E0_SIZE],
        read_original(original_image, F30E0_OFFSET, F30E0_SIZE),
        START_ADDRESS + F30E0_OFFSET,
    )


def test_func_00163180_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00163180 (184 bytes, 100% exact)."""
    assert_same_code(
        decoder_code[F3180_OFFSET:F3180_OFFSET + F3180_SIZE],
        read_original(original_image, F3180_OFFSET, F3180_SIZE),
        START_ADDRESS + F3180_OFFSET,
    )


def test_func_00163180_tail_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00163180."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
