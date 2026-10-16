"""Compile and compare the trade action stream decoders86."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders86_support")

from trade_action_stream_decoders86_support import (  # noqa: E402
    FF930_OFFSET, FF930_SIZE, FFA00_OFFSET, FFA00_SIZE,
    FFAF0_OFFSET, FFAF0_SIZE, FFBF0_OFFSET, FFBF0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders86_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 960 compiler code bytes plus 32 linker/slice-alignment bytes = 992B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00174930_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174930 (204 bytes / 51 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF930_OFFSET:FF930_OFFSET + FF930_SIZE],
        read_original(original_image, FF930_OFFSET, FF930_SIZE),
        START_ADDRESS + FF930_OFFSET,
    )


def test_func_00174930_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00174930."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00174A00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174A00 (228 bytes / 57 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFA00_OFFSET:FFA00_OFFSET + FFA00_SIZE],
        read_original(original_image, FFA00_OFFSET, FFA00_SIZE),
        START_ADDRESS + FFA00_OFFSET,
    )


def test_func_00174A00_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00174A00."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00174AF0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174AF0 (252 bytes / 63 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFAF0_OFFSET:FFAF0_OFFSET + FFAF0_SIZE],
        read_original(original_image, FFAF0_OFFSET, FFAF0_SIZE),
        START_ADDRESS + FFAF0_OFFSET,
    )


def test_func_00174AF0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00174AF0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00174BF0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174BF0 (276 bytes / 69 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFBF0_OFFSET:FFBF0_OFFSET + FFBF0_SIZE],
        read_original(original_image, FFBF0_OFFSET, FFBF0_SIZE),
        START_ADDRESS + FFBF0_OFFSET,
    )


def test_func_00174BF0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00174BF0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
