"""Compile and compare the trade action stream decoders56."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders56_support")

from trade_action_stream_decoders56_support import (  # noqa: E402
    FDCB0_OFFSET, FDCB0_SIZE, FDE20_OFFSET, FDE20_SIZE,
    FDF30_OFFSET, FDF30_SIZE, FE080_OFFSET, FE080_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders56_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,320 compiler code bytes plus 24 linker/slice-alignment bytes = 1,344B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016DCB0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016DCB0 (356 bytes / 89 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FDCB0_OFFSET:FDCB0_OFFSET + FDCB0_SIZE],
        read_original(original_image, FDCB0_OFFSET, FDCB0_SIZE),
        START_ADDRESS + FDCB0_OFFSET,
    )


def test_func_0016DCB0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016DCB0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016DE20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016DE20 (272 bytes / 68 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FDE20_OFFSET:FDE20_OFFSET + FDE20_SIZE],
        read_original(original_image, FDE20_OFFSET, FDE20_SIZE),
        START_ADDRESS + FDE20_OFFSET,
    )


def test_func_0016DF30_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016DF30 (332 bytes / 83 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FDF30_OFFSET:FDF30_OFFSET + FDF30_SIZE],
        read_original(original_image, FDF30_OFFSET, FDF30_SIZE),
        START_ADDRESS + FDF30_OFFSET,
    )


def test_func_0016DF30_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016DF30."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016E080_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016E080 (360 bytes / 90 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FE080_OFFSET:FE080_OFFSET + FE080_SIZE],
        read_original(original_image, FE080_OFFSET, FE080_SIZE),
        START_ADDRESS + FE080_OFFSET,
    )


def test_func_0016E080_tail_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016E080."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
