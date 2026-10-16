"""Compile and compare the trade action stream decoders110."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders110_support")

from trade_action_stream_decoders110_support import (  # noqa: E402
    FF170_OFFSET, FF170_SIZE, FF480_OFFSET, FF480_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders110_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1308 compiler code bytes plus 4 linker/slice-alignment bytes = 1312B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0017c170_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017c170 (784 bytes / 196 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF170_OFFSET:FF170_OFFSET + FF170_SIZE],
        read_original(original_image, FF170_OFFSET, FF170_SIZE),
        START_ADDRESS + FF170_OFFSET,
    )


def test_func_0017c480_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017c480 (524 bytes / 131 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF480_OFFSET:FF480_OFFSET + FF480_SIZE],
        read_original(original_image, FF480_OFFSET, FF480_SIZE),
        START_ADDRESS + FF480_OFFSET,
    )


def test_func_0017c480_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0017c480."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)
