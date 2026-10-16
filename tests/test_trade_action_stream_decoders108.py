"""Compile and compare the trade action stream decoders108."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders108_support")

from trade_action_stream_decoders108_support import (  # noqa: E402
    FF850_OFFSET, FF850_SIZE, FFB10_OFFSET, FFB10_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders108_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1156 compiler code bytes plus 12 linker/slice-alignment bytes = 1168B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0017b850_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017b850 (700 bytes / 175 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF850_OFFSET:FF850_OFFSET + FF850_SIZE],
        read_original(original_image, FF850_OFFSET, FF850_SIZE),
        START_ADDRESS + FF850_OFFSET,
    )


def test_func_0017b850_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0017b850."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0017bb10_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017bb10 (456 bytes / 114 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFB10_OFFSET:FFB10_OFFSET + FFB10_SIZE],
        read_original(original_image, FFB10_OFFSET, FFB10_SIZE),
        START_ADDRESS + FFB10_OFFSET,
    )


def test_func_0017bb10_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0017bb10."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)
