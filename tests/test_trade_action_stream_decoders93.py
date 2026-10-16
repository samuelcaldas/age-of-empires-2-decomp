"""Compile and compare the trade action stream decoders93."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders93_support")

from trade_action_stream_decoders93_support import (  # noqa: E402
    FF7D0_OFFSET, FF7D0_SIZE, FF9C0_OFFSET, FF9C0_SIZE,
    FFB80_OFFSET, FFB80_SIZE, FFD40_OFFSET, FFD40_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders93_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1644 compiler code bytes plus 36 linker/slice-alignment bytes = 1680B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_001767D0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001767D0 (492 bytes / 123 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF7D0_OFFSET:FF7D0_OFFSET + FF7D0_SIZE],
        read_original(original_image, FF7D0_OFFSET, FF7D0_SIZE),
        START_ADDRESS + FF7D0_OFFSET,
    )


def test_func_001767D0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001767D0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_001769C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001769C0 (436 bytes / 109 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF9C0_OFFSET:FF9C0_OFFSET + FF9C0_SIZE],
        read_original(original_image, FF9C0_OFFSET, FF9C0_SIZE),
        START_ADDRESS + FF9C0_OFFSET,
    )


def test_func_001769C0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001769C0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00176B80_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00176B80 (436 bytes / 109 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFB80_OFFSET:FFB80_OFFSET + FFB80_SIZE],
        read_original(original_image, FFB80_OFFSET, FFB80_SIZE),
        START_ADDRESS + FFB80_OFFSET,
    )


def test_func_00176B80_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00176B80."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00176D40_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00176D40 (280 bytes / 70 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFD40_OFFSET:FFD40_OFFSET + FFD40_SIZE],
        read_original(original_image, FFD40_OFFSET, FFD40_SIZE),
        START_ADDRESS + FFD40_OFFSET,
    )


def test_func_00176D40_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00176D40."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
