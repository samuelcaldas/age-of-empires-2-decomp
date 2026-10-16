"""Compile and compare the trade action stream decoders89."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders89_support")

from trade_action_stream_decoders89_support import (  # noqa: E402
    FF380_OFFSET, FF380_SIZE, FF470_OFFSET, FF470_SIZE,
    FF530_OFFSET, FF530_SIZE, FF5F0_OFFSET, FF5F0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders89_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 852 compiler code bytes plus 44 linker/slice-alignment bytes = 896B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00175380_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175380 (228 bytes / 57 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF380_OFFSET:FF380_OFFSET + FF380_SIZE],
        read_original(original_image, FF380_OFFSET, FF380_SIZE),
        START_ADDRESS + FF380_OFFSET,
    )


def test_func_00175380_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00175380."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00175470_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175470 (180 bytes / 45 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF470_OFFSET:FF470_OFFSET + FF470_SIZE],
        read_original(original_image, FF470_OFFSET, FF470_SIZE),
        START_ADDRESS + FF470_OFFSET,
    )


def test_func_00175470_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00175470."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00175530_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175530 (180 bytes / 45 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF530_OFFSET:FF530_OFFSET + FF530_SIZE],
        read_original(original_image, FF530_OFFSET, FF530_SIZE),
        START_ADDRESS + FF530_OFFSET,
    )


def test_func_00175530_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00175530."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_001755F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001755F0 (264 bytes / 66 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF5F0_OFFSET:FF5F0_OFFSET + FF5F0_SIZE],
        read_original(original_image, FF5F0_OFFSET, FF5F0_SIZE),
        START_ADDRESS + FF5F0_OFFSET,
    )


def test_func_001755F0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_001755F0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
