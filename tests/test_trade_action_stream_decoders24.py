"""Compile and compare the trade action stream decoders24."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders24_support")

from trade_action_stream_decoders24_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F3700_OFFSET, F3700_SIZE, F3840_OFFSET, F3840_SIZE,
    F39E0_OFFSET, F39E0_SIZE, F3B20_OFFSET, F3B20_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE, START_ADDRESS, assert_same_code,
    original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders24_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,488 compiler code bytes plus 32 linker/slice-alignment bytes = 1,520B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00163700_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00163700 (316 bytes / 79 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F3700_OFFSET:F3700_OFFSET + F3700_SIZE],
        read_original(original_image, F3700_OFFSET, F3700_SIZE),
        START_ADDRESS + F3700_OFFSET,
    )


def test_func_00163700_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00163700."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00163840_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00163840 (408 bytes / 102 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F3840_OFFSET:F3840_OFFSET + F3840_SIZE],
        read_original(original_image, F3840_OFFSET, F3840_SIZE),
        START_ADDRESS + F3840_OFFSET,
    )


def test_func_00163840_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00163840."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_001639E0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001639E0 (312 bytes / 78 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F39E0_OFFSET:F39E0_OFFSET + F39E0_SIZE],
        read_original(original_image, F39E0_OFFSET, F39E0_SIZE),
        START_ADDRESS + F39E0_OFFSET,
    )


def test_func_001639E0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_001639E0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00163B20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00163B20 (452 bytes / 113 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F3B20_OFFSET:F3B20_OFFSET + F3B20_SIZE],
        read_original(original_image, F3B20_OFFSET, F3B20_SIZE),
        START_ADDRESS + F3B20_OFFSET,
    )


def test_func_00163B20_tail_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00163B20."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
