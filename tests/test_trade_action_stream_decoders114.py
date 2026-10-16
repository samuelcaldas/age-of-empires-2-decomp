"""Compile and compare the trade action stream decoders114."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders114_support")

from trade_action_stream_decoders114_support import (  # noqa: E402
    FD7E0_OFFSET, FD7E0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders114_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1000 compiler code bytes plus 8 linker/slice-alignment bytes = 1008B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0017d7e0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017d7e0 (1000 bytes / 250 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FD7E0_OFFSET:FD7E0_OFFSET + FD7E0_SIZE],
        read_original(original_image, FD7E0_OFFSET, FD7E0_SIZE),
        START_ADDRESS + FD7E0_OFFSET,
    )


def test_func_0017d7e0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0017d7e0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)
