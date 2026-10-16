"""Compile and compare the trade action stream decoders85."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders85_support")

from trade_action_stream_decoders85_support import (  # noqa: E402
    FF5B0_OFFSET, FF5B0_SIZE, FF670_OFFSET, FF670_SIZE,
    FF740_OFFSET, FF740_SIZE, FF830_OFFSET, FF830_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders85_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 864 compiler code bytes plus 32 linker/slice-alignment bytes = 896B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_001745B0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001745B0 (180 bytes / 45 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF5B0_OFFSET:FF5B0_OFFSET + FF5B0_SIZE],
        read_original(original_image, FF5B0_OFFSET, FF5B0_SIZE),
        START_ADDRESS + FF5B0_OFFSET,
    )


def test_func_001745B0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001745B0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00174670_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174670 (204 bytes / 51 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF670_OFFSET:FF670_OFFSET + FF670_SIZE],
        read_original(original_image, FF670_OFFSET, FF670_SIZE),
        START_ADDRESS + FF670_OFFSET,
    )


def test_func_00174670_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00174670."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00174740_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174740 (228 bytes / 57 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF740_OFFSET:FF740_OFFSET + FF740_SIZE],
        read_original(original_image, FF740_OFFSET, FF740_SIZE),
        START_ADDRESS + FF740_OFFSET,
    )


def test_func_00174740_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00174740."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00174830_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174830 (252 bytes / 63 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF830_OFFSET:FF830_OFFSET + FF830_SIZE],
        read_original(original_image, FF830_OFFSET, FF830_SIZE),
        START_ADDRESS + FF830_OFFSET,
    )


def test_func_00174830_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00174830."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
