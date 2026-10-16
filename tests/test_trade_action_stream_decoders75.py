"""Compile and compare the trade action stream decoders75."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders75_support")

from trade_action_stream_decoders75_support import (  # noqa: E402
    FFB70_OFFSET, FFB70_SIZE, FFC40_OFFSET, FFC40_SIZE,
    FFD30_OFFSET, FFD30_SIZE, FFE30_OFFSET, FFE30_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders75_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 888 compiler code bytes plus 24 linker/slice-alignment bytes = 912B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00172B70_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172B70 (204 bytes / 51 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFB70_OFFSET:FFB70_OFFSET + FFB70_SIZE],
        read_original(original_image, FFB70_OFFSET, FFB70_SIZE),
        START_ADDRESS + FFB70_OFFSET,
    )


def test_func_00172B70_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00172B70."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00172C40_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172C40 (228 bytes / 57 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFC40_OFFSET:FFC40_OFFSET + FFC40_SIZE],
        read_original(original_image, FFC40_OFFSET, FFC40_SIZE),
        START_ADDRESS + FFC40_OFFSET,
    )


def test_func_00172C40_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00172C40."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00172D30_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172D30 (252 bytes / 63 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFD30_OFFSET:FFD30_OFFSET + FFD30_SIZE],
        read_original(original_image, FFD30_OFFSET, FFD30_SIZE),
        START_ADDRESS + FFD30_OFFSET,
    )


def test_func_00172D30_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00172D30."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00172E30_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172E30 (204 bytes / 51 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFE30_OFFSET:FFE30_OFFSET + FFE30_SIZE],
        read_original(original_image, FFE30_OFFSET, FFE30_SIZE),
        START_ADDRESS + FFE30_OFFSET,
    )


def test_func_00172E30_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00172E30."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
