"""Compile and compare the trade action stream decoders48."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders48_support")

from trade_action_stream_decoders48_support import (  # noqa: E402
    FB960_OFFSET, FB960_SIZE, FBB00_OFFSET, FBB00_SIZE,
    FBC40_OFFSET, FBC40_SIZE, FBDD0_OFFSET, FBDD0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders48_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,560 compiler code bytes plus 24 linker/slice-alignment bytes = 1,584B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016B960_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016B960 (404 bytes / 101 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FB960_OFFSET:FB960_OFFSET + FB960_SIZE],
        read_original(original_image, FB960_OFFSET, FB960_SIZE),
        START_ADDRESS + FB960_OFFSET,
    )


def test_func_0016B960_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016B960."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016BB00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016BB00 (320 bytes / 80 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FBB00_OFFSET:FBB00_OFFSET + FBB00_SIZE],
        read_original(original_image, FBB00_OFFSET, FBB00_SIZE),
        START_ADDRESS + FBB00_OFFSET,
    )


def test_func_0016BC40_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016BC40 (396 bytes / 99 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FBC40_OFFSET:FBC40_OFFSET + FBC40_SIZE],
        read_original(original_image, FBC40_OFFSET, FBC40_SIZE),
        START_ADDRESS + FBC40_OFFSET,
    )


def test_func_0016BC40_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016BC40."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016BDD0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016BDD0 (440 bytes / 110 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FBDD0_OFFSET:FBDD0_OFFSET + FBDD0_SIZE],
        read_original(original_image, FBDD0_OFFSET, FBDD0_SIZE),
        START_ADDRESS + FBDD0_OFFSET,
    )


def test_func_0016BDD0_tail_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016BDD0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
