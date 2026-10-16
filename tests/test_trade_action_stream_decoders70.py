"""Compile and compare the trade action stream decoders70."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders70_support")

from trade_action_stream_decoders70_support import (  # noqa: E402
    FFE10_OFFSET, FFE10_SIZE, FFE80_OFFSET, FFE80_SIZE,
    FFEF0_OFFSET, FFEF0_SIZE, FFF60_OFFSET, FFF60_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders70_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 452 compiler code bytes plus 44 linker/slice-alignment bytes = 496B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00171E10_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171E10 (100 bytes / 25 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFE10_OFFSET:FFE10_OFFSET + FFE10_SIZE],
        read_original(original_image, FFE10_OFFSET, FFE10_SIZE),
        START_ADDRESS + FFE10_OFFSET,
    )


def test_func_00171E10_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00171E10."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00171E80_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171E80 (100 bytes / 25 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFE80_OFFSET:FFE80_OFFSET + FFE80_SIZE],
        read_original(original_image, FFE80_OFFSET, FFE80_SIZE),
        START_ADDRESS + FFE80_OFFSET,
    )


def test_func_00171E80_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00171E80."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00171EF0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171EF0 (100 bytes / 25 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFEF0_OFFSET:FFEF0_OFFSET + FFEF0_SIZE],
        read_original(original_image, FFEF0_OFFSET, FFEF0_SIZE),
        START_ADDRESS + FFEF0_OFFSET,
    )


def test_func_00171EF0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00171EF0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00171F60_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171F60 (152 bytes / 38 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFF60_OFFSET:FFF60_OFFSET + FFF60_SIZE],
        read_original(original_image, FFF60_OFFSET, FFF60_SIZE),
        START_ADDRESS + FFF60_OFFSET,
    )


def test_func_00171F60_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00171F60."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
