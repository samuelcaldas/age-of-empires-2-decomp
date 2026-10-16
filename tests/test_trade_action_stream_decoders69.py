"""Compile and compare the trade action stream decoders69."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders69_support")

from trade_action_stream_decoders69_support import (  # noqa: E402
    FFCB0_OFFSET, FFCB0_SIZE, FFCF0_OFFSET, FFCF0_SIZE,
    FFD40_OFFSET, FFD40_SIZE, FFD90_OFFSET, FFD90_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders69_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 332 compiler code bytes plus 20 linker/slice-alignment bytes = 352B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00171CB0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171CB0 (52 bytes / 13 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFCB0_OFFSET:FFCB0_OFFSET + FFCB0_SIZE],
        read_original(original_image, FFCB0_OFFSET, FFCB0_SIZE),
        START_ADDRESS + FFCB0_OFFSET,
    )


def test_func_00171CB0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00171CB0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00171CF0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171CF0 (76 bytes / 19 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFCF0_OFFSET:FFCF0_OFFSET + FFCF0_SIZE],
        read_original(original_image, FFCF0_OFFSET, FFCF0_SIZE),
        START_ADDRESS + FFCF0_OFFSET,
    )


def test_func_00171CF0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00171CF0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00171D40_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171D40 (76 bytes / 19 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFD40_OFFSET:FFD40_OFFSET + FFD40_SIZE],
        read_original(original_image, FFD40_OFFSET, FFD40_SIZE),
        START_ADDRESS + FFD40_OFFSET,
    )


def test_func_00171D40_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00171D40."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00171D90_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00171D90 (128 bytes / 32 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFD90_OFFSET:FFD90_OFFSET + FFD90_SIZE],
        read_original(original_image, FFD90_OFFSET, FFD90_SIZE),
        START_ADDRESS + FFD90_OFFSET,
    )
