"""Compile and compare the trade action stream decoders55."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders55_support")

from trade_action_stream_decoders55_support import (  # noqa: E402
    FD800_OFFSET, FD800_SIZE, FD930_OFFSET, FD930_SIZE,
    FDA30_OFFSET, FDA30_SIZE, FDB60_OFFSET, FDB60_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders55_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,176 compiler code bytes plus 24 linker/slice-alignment bytes = 1,200B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016D800_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016D800 (296 bytes / 74 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FD800_OFFSET:FD800_OFFSET + FD800_SIZE],
        read_original(original_image, FD800_OFFSET, FD800_SIZE),
        START_ADDRESS + FD800_OFFSET,
    )


def test_func_0016D800_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016D800."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016D930_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016D930 (244 bytes / 61 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FD930_OFFSET:FD930_OFFSET + FD930_SIZE],
        read_original(original_image, FD930_OFFSET, FD930_SIZE),
        START_ADDRESS + FD930_OFFSET,
    )


def test_func_0016D930_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016D930."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016DA30_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016DA30 (304 bytes / 76 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FDA30_OFFSET:FDA30_OFFSET + FDA30_SIZE],
        read_original(original_image, FDA30_OFFSET, FDA30_SIZE),
        START_ADDRESS + FDA30_OFFSET,
    )


def test_func_0016DB60_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016DB60 (332 bytes / 83 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FDB60_OFFSET:FDB60_OFFSET + FDB60_SIZE],
        read_original(original_image, FDB60_OFFSET, FDB60_SIZE),
        START_ADDRESS + FDB60_OFFSET,
    )


def test_func_0016DB60_tail_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016DB60."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
