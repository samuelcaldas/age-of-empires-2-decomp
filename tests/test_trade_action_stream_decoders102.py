"""Compile and compare the trade action stream decoders102."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders102_support")

from trade_action_stream_decoders102_support import (  # noqa: E402
    FF0C0_OFFSET, FF0C0_SIZE, FFD30_OFFSET, FFD30_SIZE,
    FFF10_OFFSET, FFF10_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders102_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1400 compiler code bytes plus 8 linker/slice-alignment bytes = 1408B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00179d30_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00179d30 (476 bytes / 119 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFD30_OFFSET:FFD30_OFFSET + FFD30_SIZE],
        read_original(original_image, FFD30_OFFSET, FFD30_SIZE),
        START_ADDRESS + FFD30_OFFSET,
    )


def test_func_00179d30_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00179d30."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00179f10_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00179f10 (428 bytes / 107 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFF10_OFFSET:FFF10_OFFSET + FFF10_SIZE],
        read_original(original_image, FFF10_OFFSET, FFF10_SIZE),
        START_ADDRESS + FFF10_OFFSET,
    )


def test_func_00179f10_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00179f10."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0017a0c0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017a0c0 (496 bytes / 124 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF0C0_OFFSET:FF0C0_OFFSET + FF0C0_SIZE],
        read_original(original_image, FF0C0_OFFSET, FF0C0_SIZE),
        START_ADDRESS + FF0C0_OFFSET,
    )
