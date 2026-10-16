"""Compile and compare the trade action stream decoders92."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders92_support")

from trade_action_stream_decoders92_support import (  # noqa: E402
    FF130_OFFSET, FF130_SIZE, FF300_OFFSET, FF300_SIZE,
    FF480_OFFSET, FF480_SIZE, FF5F0_OFFSET, FF5F0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders92_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1676 compiler code bytes plus 20 linker/slice-alignment bytes = 1696B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00176130_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00176130 (456 bytes / 114 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF130_OFFSET:FF130_OFFSET + FF130_SIZE],
        read_original(original_image, FF130_OFFSET, FF130_SIZE),
        START_ADDRESS + FF130_OFFSET,
    )


def test_func_00176130_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00176130."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00176300_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00176300 (384 bytes / 96 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF300_OFFSET:FF300_OFFSET + FF300_SIZE],
        read_original(original_image, FF300_OFFSET, FF300_SIZE),
        START_ADDRESS + FF300_OFFSET,
    )


def test_func_00176480_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00176480 (368 bytes / 92 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF480_OFFSET:FF480_OFFSET + FF480_SIZE],
        read_original(original_image, FF480_OFFSET, FF480_SIZE),
        START_ADDRESS + FF480_OFFSET,
    )


def test_func_001765F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001765F0 (468 bytes / 117 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF5F0_OFFSET:FF5F0_OFFSET + FF5F0_SIZE],
        read_original(original_image, FF5F0_OFFSET, FF5F0_SIZE),
        START_ADDRESS + FF5F0_OFFSET,
    )


def test_func_001765F0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001765F0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
