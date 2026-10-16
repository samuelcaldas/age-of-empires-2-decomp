"""Compile and compare the trade action stream decoders77."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders77_support")

from trade_action_stream_decoders77_support import (  # noqa: E402
    FF300_OFFSET, FF300_SIZE, FF400_OFFSET, FF400_SIZE,
    FF520_OFFSET, FF520_SIZE, FF650_OFFSET, FF650_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders77_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 856 compiler code bytes plus 24 linker/slice-alignment bytes = 880B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00173300_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173300 (252 bytes / 63 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF300_OFFSET:FF300_OFFSET + FF300_SIZE],
        read_original(original_image, FF300_OFFSET, FF300_SIZE),
        START_ADDRESS + FF300_OFFSET,
    )


def test_func_00173300_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00173300."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00173400_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173400 (276 bytes / 69 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF400_OFFSET:FF400_OFFSET + FF400_SIZE],
        read_original(original_image, FF400_OFFSET, FF400_SIZE),
        START_ADDRESS + FF400_OFFSET,
    )


def test_func_00173400_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00173400."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00173520_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173520 (300 bytes / 75 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF520_OFFSET:FF520_OFFSET + FF520_SIZE],
        read_original(original_image, FF520_OFFSET, FF520_SIZE),
        START_ADDRESS + FF520_OFFSET,
    )


def test_func_00173520_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00173520."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00173650_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173650 (28 bytes / 7 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF650_OFFSET:FF650_OFFSET + FF650_SIZE],
        read_original(original_image, FF650_OFFSET, FF650_SIZE),
        START_ADDRESS + FF650_OFFSET,
    )


def test_func_00173650_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00173650."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
