"""Compile and compare the trade action stream decoders67."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders67_support")

from trade_action_stream_decoders67_support import (  # noqa: E402
    FF120_OFFSET, FF120_SIZE, FF310_OFFSET, FF310_SIZE,
    FF500_OFFSET, FF500_SIZE, FF680_OFFSET, FF680_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders67_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1820 compiler code bytes plus 20 linker/slice-alignment bytes = 1840B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00171120_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171120 (488 bytes / 122 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF120_OFFSET:FF120_OFFSET + FF120_SIZE],
        read_original(original_image, FF120_OFFSET, FF120_SIZE),
        START_ADDRESS + FF120_OFFSET,
    )


def test_func_00171120_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00171120."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00171310_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171310 (496 bytes / 124 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF310_OFFSET:FF310_OFFSET + FF310_SIZE],
        read_original(original_image, FF310_OFFSET, FF310_SIZE),
        START_ADDRESS + FF310_OFFSET,
    )


def test_func_00171500_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171500 (380 bytes / 95 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF500_OFFSET:FF500_OFFSET + FF500_SIZE],
        read_original(original_image, FF500_OFFSET, FF500_SIZE),
        START_ADDRESS + FF500_OFFSET,
    )


def test_func_00171500_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00171500."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00171680_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171680 (456 bytes / 114 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF680_OFFSET:FF680_OFFSET + FF680_SIZE],
        read_original(original_image, FF680_OFFSET, FF680_SIZE),
        START_ADDRESS + FF680_OFFSET,
    )


def test_func_00171680_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00171680."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
