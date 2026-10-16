"""Compile and compare the trade action stream decoders73."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders73_support")

from trade_action_stream_decoders73_support import (  # noqa: E402
    FF520_OFFSET, FF520_SIZE, FF5F0_OFFSET, FF5F0_SIZE,
    FF6C0_OFFSET, FF6C0_SIZE, FF790_OFFSET, FF790_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders73_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 748 compiler code bytes plus 36 linker/slice-alignment bytes = 784B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00172520_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172520 (200 bytes / 50 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF520_OFFSET:FF520_OFFSET + FF520_SIZE],
        read_original(original_image, FF520_OFFSET, FF520_SIZE),
        START_ADDRESS + FF520_OFFSET,
    )


def test_func_00172520_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00172520."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_001725F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001725F0 (200 bytes / 50 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF5F0_OFFSET:FF5F0_OFFSET + FF5F0_SIZE],
        read_original(original_image, FF5F0_OFFSET, FF5F0_SIZE),
        START_ADDRESS + FF5F0_OFFSET,
    )


def test_func_001725F0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_001725F0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_001726C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001726C0 (200 bytes / 50 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF6C0_OFFSET:FF6C0_OFFSET + FF6C0_SIZE],
        read_original(original_image, FF6C0_OFFSET, FF6C0_SIZE),
        START_ADDRESS + FF6C0_OFFSET,
    )


def test_func_001726C0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_001726C0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00172790_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172790 (148 bytes / 37 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF790_OFFSET:FF790_OFFSET + FF790_SIZE],
        read_original(original_image, FF790_OFFSET, FF790_SIZE),
        START_ADDRESS + FF790_OFFSET,
    )


def test_func_00172790_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00172790."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
