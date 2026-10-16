"""Compile and compare the trade action stream decoders87."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders87_support")

from trade_action_stream_decoders87_support import (  # noqa: E402
    FF020_OFFSET, FF020_SIZE, FFD10_OFFSET, FFD10_SIZE,
    FFE00_OFFSET, FFE00_SIZE, FFF00_OFFSET, FFF00_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders87_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1056 compiler code bytes plus 32 linker/slice-alignment bytes = 1088B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00174D10_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174D10 (228 bytes / 57 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFD10_OFFSET:FFD10_OFFSET + FFD10_SIZE],
        read_original(original_image, FFD10_OFFSET, FFD10_SIZE),
        START_ADDRESS + FFD10_OFFSET,
    )


def test_func_00174D10_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00174D10."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00174E00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174E00 (252 bytes / 63 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFE00_OFFSET:FFE00_OFFSET + FFE00_SIZE],
        read_original(original_image, FFE00_OFFSET, FFE00_SIZE),
        START_ADDRESS + FFE00_OFFSET,
    )


def test_func_00174E00_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00174E00."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00174F00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174F00 (276 bytes / 69 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFF00_OFFSET:FFF00_OFFSET + FFF00_SIZE],
        read_original(original_image, FFF00_OFFSET, FFF00_SIZE),
        START_ADDRESS + FFF00_OFFSET,
    )


def test_func_00174F00_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00174F00."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00175020_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175020 (300 bytes / 75 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF020_OFFSET:FF020_OFFSET + FF020_SIZE],
        read_original(original_image, FF020_OFFSET, FF020_SIZE),
        START_ADDRESS + FF020_OFFSET,
    )


def test_func_00175020_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00175020."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
