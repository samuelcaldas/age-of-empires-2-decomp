"""Compile and compare the trade action stream decoders107."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders107_support")

from trade_action_stream_decoders107_support import (  # noqa: E402
    FF470_OFFSET, FF470_SIZE, FF640_OFFSET, FF640_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders107_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 984 compiler code bytes plus 8 linker/slice-alignment bytes = 992B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0017b470_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017b470 (456 bytes / 114 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF470_OFFSET:FF470_OFFSET + FF470_SIZE],
        read_original(original_image, FF470_OFFSET, FF470_SIZE),
        START_ADDRESS + FF470_OFFSET,
    )


def test_func_0017b470_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0017b470."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0017b640_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017b640 (528 bytes / 132 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF640_OFFSET:FF640_OFFSET + FF640_SIZE],
        read_original(original_image, FF640_OFFSET, FF640_SIZE),
        START_ADDRESS + FF640_OFFSET,
    )
