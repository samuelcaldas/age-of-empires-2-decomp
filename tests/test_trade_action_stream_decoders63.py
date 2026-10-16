"""Compile and compare the trade action stream decoders63."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders63_support")

from trade_action_stream_decoders63_support import (  # noqa: E402
    FF940_OFFSET, FF940_SIZE, FFAA0_OFFSET, FFAA0_SIZE,
    FFC20_OFFSET, FFC20_SIZE, FFD80_OFFSET, FFD80_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders63_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1424 compiler code bytes plus 16 linker/slice-alignment bytes = 1440B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016F940_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016F940 (344 bytes / 86 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF940_OFFSET:FF940_OFFSET + FF940_SIZE],
        read_original(original_image, FF940_OFFSET, FF940_SIZE),
        START_ADDRESS + FF940_OFFSET,
    )


def test_func_0016F940_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016F940."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016FAA0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016FAA0 (376 bytes / 94 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFAA0_OFFSET:FFAA0_OFFSET + FFAA0_SIZE],
        read_original(original_image, FFAA0_OFFSET, FFAA0_SIZE),
        START_ADDRESS + FFAA0_OFFSET,
    )


def test_func_0016FAA0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016FAA0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016FC20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016FC20 (352 bytes / 88 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFC20_OFFSET:FFC20_OFFSET + FFC20_SIZE],
        read_original(original_image, FFC20_OFFSET, FFC20_SIZE),
        START_ADDRESS + FFC20_OFFSET,
    )


def test_func_0016FD80_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016FD80 (352 bytes / 88 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFD80_OFFSET:FFD80_OFFSET + FFD80_SIZE],
        read_original(original_image, FFD80_OFFSET, FFD80_SIZE),
        START_ADDRESS + FFD80_OFFSET,
    )
