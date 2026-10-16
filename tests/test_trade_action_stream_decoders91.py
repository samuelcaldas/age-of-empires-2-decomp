"""Compile and compare the trade action stream decoders91."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders91_support")

from trade_action_stream_decoders91_support import (  # noqa: E402
    FFB90_OFFSET, FFB90_SIZE, FFD10_OFFSET, FFD10_SIZE,
    FFE70_OFFSET, FFE70_SIZE, FFFB0_OFFSET, FFFB0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders91_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1420 compiler code bytes plus 20 linker/slice-alignment bytes = 1440B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00175B90_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175B90 (372 bytes / 93 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFB90_OFFSET:FFB90_OFFSET + FFB90_SIZE],
        read_original(original_image, FFB90_OFFSET, FFB90_SIZE),
        START_ADDRESS + FFB90_OFFSET,
    )


def test_func_00175B90_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00175B90."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00175D10_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175D10 (348 bytes / 87 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFD10_OFFSET:FFD10_OFFSET + FFD10_SIZE],
        read_original(original_image, FFD10_OFFSET, FFD10_SIZE),
        START_ADDRESS + FFD10_OFFSET,
    )


def test_func_00175D10_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00175D10."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00175E70_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175E70 (316 bytes / 79 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFE70_OFFSET:FFE70_OFFSET + FFE70_SIZE],
        read_original(original_image, FFE70_OFFSET, FFE70_SIZE),
        START_ADDRESS + FFE70_OFFSET,
    )


def test_func_00175E70_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00175E70."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00175FB0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175FB0 (384 bytes / 96 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFFB0_OFFSET:FFFB0_OFFSET + FFFB0_SIZE],
        read_original(original_image, FFFB0_OFFSET, FFFB0_SIZE),
        START_ADDRESS + FFFB0_OFFSET,
    )
