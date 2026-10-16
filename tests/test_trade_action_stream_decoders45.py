"""Compile and compare the trade action stream decoders45."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders45_support")

from trade_action_stream_decoders45_support import (  # noqa: E402
    FAA50_OFFSET, FAA50_SIZE, FBA0_OFFSET, FBA0_SIZE,
    FCD0_OFFSET, FCD0_SIZE, FE00_OFFSET, FE00_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders45_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,296 compiler code bytes plus 16 linker/slice-alignment bytes = 1,312B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016AA50_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016AA50 (324 bytes / 81 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FAA50_OFFSET:FAA50_OFFSET + FAA50_SIZE],
        read_original(original_image, FAA50_OFFSET, FAA50_SIZE),
        START_ADDRESS + FAA50_OFFSET,
    )


def test_func_0016AA50_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016AA50."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016ABA0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016ABA0 (304 bytes / 76 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FBA0_OFFSET:FBA0_OFFSET + FBA0_SIZE],
        read_original(original_image, FBA0_OFFSET, FBA0_SIZE),
        START_ADDRESS + FBA0_OFFSET,
    )


def test_func_0016ACD0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016ACD0 (300 bytes / 75 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FCD0_OFFSET:FCD0_OFFSET + FCD0_SIZE],
        read_original(original_image, FCD0_OFFSET, FCD0_SIZE),
        START_ADDRESS + FCD0_OFFSET,
    )


def test_func_0016ACD0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016ACD0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016AE00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016AE00 (368 bytes / 92 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FE00_OFFSET:FE00_OFFSET + FE00_SIZE],
        read_original(original_image, FE00_OFFSET, FE00_SIZE),
        START_ADDRESS + FE00_OFFSET,
    )
