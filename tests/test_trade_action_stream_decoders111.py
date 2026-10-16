"""Compile and compare the trade action stream decoders111."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders111_support")

from trade_action_stream_decoders111_support import (  # noqa: E402
    FF690_OFFSET, FF690_SIZE, FF8F0_OFFSET, FF8F0_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders111_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1288 compiler code bytes plus 8 linker/slice-alignment bytes = 1296B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0017c690_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017c690 (608 bytes / 152 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF690_OFFSET:FF690_OFFSET + FF690_SIZE],
        read_original(original_image, FF690_OFFSET, FF690_SIZE),
        START_ADDRESS + FF690_OFFSET,
    )


def test_func_0017c8f0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017c8f0 (680 bytes / 170 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF8F0_OFFSET:FF8F0_OFFSET + FF8F0_SIZE],
        read_original(original_image, FF8F0_OFFSET, FF8F0_SIZE),
        START_ADDRESS + FF8F0_OFFSET,
    )


def test_func_0017c8f0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0017c8f0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)
