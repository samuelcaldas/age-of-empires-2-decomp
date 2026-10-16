"""Compile and compare the trade action stream decoders84."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders84_support")

from trade_action_stream_decoders84_support import (  # noqa: E402
    FF290_OFFSET, FF290_SIZE, FF330_OFFSET, FF330_SIZE,
    FF3F0_OFFSET, FF3F0_SIZE, FF4C0_OFFSET, FF4C0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders84_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 772 compiler code bytes plus 28 linker/slice-alignment bytes = 800B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00174290_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174290 (148 bytes / 37 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF290_OFFSET:FF290_OFFSET + FF290_SIZE],
        read_original(original_image, FF290_OFFSET, FF290_SIZE),
        START_ADDRESS + FF290_OFFSET,
    )


def test_func_00174290_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00174290."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00174330_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00174330 (184 bytes / 46 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF330_OFFSET:FF330_OFFSET + FF330_SIZE],
        read_original(original_image, FF330_OFFSET, FF330_SIZE),
        START_ADDRESS + FF330_OFFSET,
    )


def test_func_00174330_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00174330."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_001743F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001743F0 (208 bytes / 52 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF3F0_OFFSET:FF3F0_OFFSET + FF3F0_SIZE],
        read_original(original_image, FF3F0_OFFSET, FF3F0_SIZE),
        START_ADDRESS + FF3F0_OFFSET,
    )


def test_func_001744C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001744C0 (232 bytes / 58 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF4C0_OFFSET:FF4C0_OFFSET + FF4C0_SIZE],
        read_original(original_image, FF4C0_OFFSET, FF4C0_SIZE),
        START_ADDRESS + FF4C0_OFFSET,
    )


def test_func_001744C0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_001744C0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
