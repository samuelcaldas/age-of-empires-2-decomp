"""Compile and compare the trade action stream decoders72."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders72_support")

from trade_action_stream_decoders72_support import (  # noqa: E402
    FF250_OFFSET, FF250_SIZE, FF2F0_OFFSET, FF2F0_SIZE,
    FF3A0_OFFSET, FF3A0_SIZE, FF450_OFFSET, FF450_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders72_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 700 compiler code bytes plus 20 linker/slice-alignment bytes = 720B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00172250_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172250 (148 bytes / 37 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF250_OFFSET:FF250_OFFSET + FF250_SIZE],
        read_original(original_image, FF250_OFFSET, FF250_SIZE),
        START_ADDRESS + FF250_OFFSET,
    )


def test_func_00172250_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00172250."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_001722F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001722F0 (176 bytes / 44 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF2F0_OFFSET:FF2F0_OFFSET + FF2F0_SIZE],
        read_original(original_image, FF2F0_OFFSET, FF2F0_SIZE),
        START_ADDRESS + FF2F0_OFFSET,
    )


def test_func_001723A0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001723A0 (176 bytes / 44 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF3A0_OFFSET:FF3A0_OFFSET + FF3A0_SIZE],
        read_original(original_image, FF3A0_OFFSET, FF3A0_SIZE),
        START_ADDRESS + FF3A0_OFFSET,
    )


def test_func_00172450_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172450 (200 bytes / 50 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF450_OFFSET:FF450_OFFSET + FF450_SIZE],
        read_original(original_image, FF450_OFFSET, FF450_SIZE),
        START_ADDRESS + FF450_OFFSET,
    )


def test_func_00172450_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00172450."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
