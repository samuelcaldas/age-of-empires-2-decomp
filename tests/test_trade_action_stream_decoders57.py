"""Compile and compare the trade action stream decoders57."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders57_support")

from trade_action_stream_decoders57_support import (  # noqa: E402
    FE1F0_OFFSET, FE1F0_SIZE, FE370_OFFSET, FE370_SIZE,
    FE4A0_OFFSET, FE4A0_SIZE, FE610_OFFSET, FE610_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders57_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,420 compiler code bytes plus 20 linker/slice-alignment bytes = 1,440B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016E1F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016E1F0 (384 bytes / 96 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FE1F0_OFFSET:FE1F0_OFFSET + FE1F0_SIZE],
        read_original(original_image, FE1F0_OFFSET, FE1F0_SIZE),
        START_ADDRESS + FE1F0_OFFSET,
    )


def test_func_0016E370_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016E370 (296 bytes / 74 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FE370_OFFSET:FE370_OFFSET + FE370_SIZE],
        read_original(original_image, FE370_OFFSET, FE370_SIZE),
        START_ADDRESS + FE370_OFFSET,
    )


def test_func_0016E370_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016E370."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016E4A0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016E4A0 (356 bytes / 89 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FE4A0_OFFSET:FE4A0_OFFSET + FE4A0_SIZE],
        read_original(original_image, FE4A0_OFFSET, FE4A0_SIZE),
        START_ADDRESS + FE4A0_OFFSET,
    )


def test_func_0016E4A0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016E4A0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016E610_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016E610 (384 bytes / 96 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FE610_OFFSET:FE610_OFFSET + FE610_SIZE],
        read_original(original_image, FE610_OFFSET, FE610_SIZE),
        START_ADDRESS + FE610_OFFSET,
    )
