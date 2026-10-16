"""Compile and compare the trade action stream decoders83."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders83_support")

from trade_action_stream_decoders83_support import (  # noqa: E402
    FF020_OFFSET, FF020_SIZE, FF0F0_OFFSET, FF0F0_SIZE,
    FF1C0_OFFSET, FF1C0_SIZE, FFF50_OFFSET, FFF50_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders83_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 800 compiler code bytes plus 32 linker/slice-alignment bytes = 832B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00173F50_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173F50 (200 bytes / 50 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFF50_OFFSET:FFF50_OFFSET + FFF50_SIZE],
        read_original(original_image, FFF50_OFFSET, FFF50_SIZE),
        START_ADDRESS + FFF50_OFFSET,
    )


def test_func_00173F50_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00173F50."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00174020_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174020 (200 bytes / 50 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF020_OFFSET:FF020_OFFSET + FF020_SIZE],
        read_original(original_image, FF020_OFFSET, FF020_SIZE),
        START_ADDRESS + FF020_OFFSET,
    )


def test_func_00174020_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00174020."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_001740F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001740F0 (200 bytes / 50 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF0F0_OFFSET:FF0F0_OFFSET + FF0F0_SIZE],
        read_original(original_image, FF0F0_OFFSET, FF0F0_SIZE),
        START_ADDRESS + FF0F0_OFFSET,
    )


def test_func_001740F0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_001740F0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_001741C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001741C0 (200 bytes / 50 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF1C0_OFFSET:FF1C0_OFFSET + FF1C0_SIZE],
        read_original(original_image, FF1C0_OFFSET, FF1C0_SIZE),
        START_ADDRESS + FF1C0_OFFSET,
    )


def test_func_001741C0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_001741C0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
