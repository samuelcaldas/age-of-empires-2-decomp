"""Compile and compare the trade action stream decoders106."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders106_support")

from trade_action_stream_decoders106_support import (  # noqa: E402
    FF0B0_OFFSET, FF0B0_SIZE, FF300_OFFSET, FF300_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders106_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 936 compiler code bytes plus 24 linker/slice-alignment bytes = 960B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0017b0b0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017b0b0 (580 bytes / 145 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF0B0_OFFSET:FF0B0_OFFSET + FF0B0_SIZE],
        read_original(original_image, FF0B0_OFFSET, FF0B0_SIZE),
        START_ADDRESS + FF0B0_OFFSET,
    )


def test_func_0017b0b0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0017b0b0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0017b300_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017b300 (360 bytes / 90 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF300_OFFSET:FF300_OFFSET + FF300_SIZE],
        read_original(original_image, FF300_OFFSET, FF300_SIZE),
        START_ADDRESS + FF300_OFFSET,
    )


def test_func_0017b300_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0017b300."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)
