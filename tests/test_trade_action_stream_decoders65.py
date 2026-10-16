"""Compile and compare the trade action stream decoders65."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders65_support")

from trade_action_stream_decoders65_support import (  # noqa: E402
    FF470_OFFSET, FF470_SIZE, FF5F0_OFFSET, FF5F0_SIZE,
    FF770_OFFSET, FF770_SIZE, FF8C0_OFFSET, FF8C0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders65_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1484 compiler code bytes plus 36 linker/slice-alignment bytes = 1520B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00170470_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00170470 (372 bytes / 93 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF470_OFFSET:FF470_OFFSET + FF470_SIZE],
        read_original(original_image, FF470_OFFSET, FF470_SIZE),
        START_ADDRESS + FF470_OFFSET,
    )


def test_func_00170470_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00170470."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_001705F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001705F0 (380 bytes / 95 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF5F0_OFFSET:FF5F0_OFFSET + FF5F0_SIZE],
        read_original(original_image, FF5F0_OFFSET, FF5F0_SIZE),
        START_ADDRESS + FF5F0_OFFSET,
    )


def test_func_001705F0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001705F0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00170770_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00170770 (328 bytes / 82 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF770_OFFSET:FF770_OFFSET + FF770_SIZE],
        read_original(original_image, FF770_OFFSET, FF770_SIZE),
        START_ADDRESS + FF770_OFFSET,
    )


def test_func_00170770_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00170770."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_001708C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001708C0 (404 bytes / 101 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF8C0_OFFSET:FF8C0_OFFSET + FF8C0_SIZE],
        read_original(original_image, FF8C0_OFFSET, FF8C0_SIZE),
        START_ADDRESS + FF8C0_OFFSET,
    )


def test_func_001708C0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001708C0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
