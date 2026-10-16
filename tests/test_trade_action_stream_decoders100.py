"""Compile and compare the trade action stream decoders100."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders100_support")

from trade_action_stream_decoders100_support import (  # noqa: E402
    FF390_OFFSET, FF390_SIZE, FF4F0_OFFSET, FF4F0_SIZE,
    FF6A0_OFFSET, FF6A0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD3_OFFSET, PAD3_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders100_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1088 compiler code bytes plus 16 linker/slice-alignment bytes = 1104B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00179390_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00179390 (344 bytes / 86 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF390_OFFSET:FF390_OFFSET + FF390_SIZE],
        read_original(original_image, FF390_OFFSET, FF390_SIZE),
        START_ADDRESS + FF390_OFFSET,
    )


def test_func_00179390_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00179390."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_001794f0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001794f0 (432 bytes / 108 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF4F0_OFFSET:FF4F0_OFFSET + FF4F0_SIZE],
        read_original(original_image, FF4F0_OFFSET, FF4F0_SIZE),
        START_ADDRESS + FF4F0_OFFSET,
    )


def test_func_001796a0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001796a0 (312 bytes / 78 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF6A0_OFFSET:FF6A0_OFFSET + FF6A0_SIZE],
        read_original(original_image, FF6A0_OFFSET, FF6A0_SIZE),
        START_ADDRESS + FF6A0_OFFSET,
    )


def test_func_001796a0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_001796a0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)
