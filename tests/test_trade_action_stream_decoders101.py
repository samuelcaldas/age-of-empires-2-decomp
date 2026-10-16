"""Compile and compare the trade action stream decoders101."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders101_support")

from trade_action_stream_decoders101_support import (  # noqa: E402
    FF7E0_OFFSET, FF7E0_SIZE, FF980_OFFSET, FF980_SIZE,
    FFB30_OFFSET, FFB30_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders101_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1332 compiler code bytes plus 28 linker/slice-alignment bytes = 1360B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_001797e0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001797e0 (408 bytes / 102 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF7E0_OFFSET:FF7E0_OFFSET + FF7E0_SIZE],
        read_original(original_image, FF7E0_OFFSET, FF7E0_SIZE),
        START_ADDRESS + FF7E0_OFFSET,
    )


def test_func_001797e0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_001797e0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00179980_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00179980 (428 bytes / 107 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF980_OFFSET:FF980_OFFSET + FF980_SIZE],
        read_original(original_image, FF980_OFFSET, FF980_SIZE),
        START_ADDRESS + FF980_OFFSET,
    )


def test_func_00179980_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00179980."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00179b30_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00179b30 (500 bytes / 125 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFB30_OFFSET:FFB30_OFFSET + FFB30_SIZE],
        read_original(original_image, FFB30_OFFSET, FFB30_SIZE),
        START_ADDRESS + FFB30_OFFSET,
    )


def test_func_00179b30_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00179b30."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)
