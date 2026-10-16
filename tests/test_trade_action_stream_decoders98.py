"""Compile and compare the trade action stream decoders98."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders98_support")

from trade_action_stream_decoders98_support import (  # noqa: E402
    FFC10_OFFSET, FFC10_SIZE, FFC70_OFFSET, FFC70_SIZE,
    FFCD0_OFFSET, FFCD0_SIZE, FFD90_OFFSET, FFD90_SIZE,
    FFE30_OFFSET, FFE30_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE, PAD5_OFFSET, PAD5_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders98_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 692 compiler code bytes plus 28 linker/slice-alignment bytes = 720B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00178c10_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00178c10 (88 bytes / 22 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFC10_OFFSET:FFC10_OFFSET + FFC10_SIZE],
        read_original(original_image, FFC10_OFFSET, FFC10_SIZE),
        START_ADDRESS + FFC10_OFFSET,
    )


def test_func_00178c10_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00178c10."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00178c70_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00178c70 (88 bytes / 22 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFC70_OFFSET:FFC70_OFFSET + FFC70_SIZE],
        read_original(original_image, FFC70_OFFSET, FFC70_SIZE),
        START_ADDRESS + FFC70_OFFSET,
    )


def test_func_00178c70_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00178c70."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00178cd0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00178cd0 (184 bytes / 46 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFCD0_OFFSET:FFCD0_OFFSET + FFCD0_SIZE],
        read_original(original_image, FFCD0_OFFSET, FFCD0_SIZE),
        START_ADDRESS + FFCD0_OFFSET,
    )


def test_func_00178cd0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00178cd0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00178d90_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00178d90 (160 bytes / 40 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFD90_OFFSET:FFD90_OFFSET + FFD90_SIZE],
        read_original(original_image, FFD90_OFFSET, FFD90_SIZE),
        START_ADDRESS + FFD90_OFFSET,
    )


def test_func_00178e30_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00178e30 (172 bytes / 43 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFE30_OFFSET:FFE30_OFFSET + FFE30_SIZE],
        read_original(original_image, FFE30_OFFSET, FFE30_SIZE),
        START_ADDRESS + FFE30_OFFSET,
    )


def test_func_00178e30_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00178e30."""
    actual_pad = decoder_code[PAD5_OFFSET:PAD5_OFFSET + PAD5_SIZE]
    expected_pad = read_original(original_image, PAD5_OFFSET, PAD5_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD5_OFFSET)
