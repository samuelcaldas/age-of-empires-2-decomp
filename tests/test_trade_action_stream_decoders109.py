"""Compile and compare the trade action stream decoders109."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders109_support")

from trade_action_stream_decoders109_support import (  # noqa: E402
    FFCE0_OFFSET, FFCE0_SIZE, FFF00_OFFSET, FFF00_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders109_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1152 compiler code bytes plus 16 linker/slice-alignment bytes = 1168B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0017bce0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017bce0 (540 bytes / 135 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFCE0_OFFSET:FFCE0_OFFSET + FFCE0_SIZE],
        read_original(original_image, FFCE0_OFFSET, FFCE0_SIZE),
        START_ADDRESS + FFCE0_OFFSET,
    )


def test_func_0017bce0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0017bce0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0017bf00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017bf00 (612 bytes / 153 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFF00_OFFSET:FFF00_OFFSET + FFF00_SIZE],
        read_original(original_image, FFF00_OFFSET, FFF00_SIZE),
        START_ADDRESS + FFF00_OFFSET,
    )


def test_func_0017bf00_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0017bf00."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)
