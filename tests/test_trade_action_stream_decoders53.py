"""Compile and compare the trade action stream decoders53."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders53_support")

from trade_action_stream_decoders53_support import (  # noqa: E402
    FD000_OFFSET, FD000_SIZE, FD100_OFFSET, FD100_SIZE,
    FD210_OFFSET, FD210_SIZE, FD320_OFFSET, FD320_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders53_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,048 compiler code bytes plus 24 linker/slice-alignment bytes = 1,072B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016D000_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016D000 (244 bytes / 61 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FD000_OFFSET:FD000_OFFSET + FD000_SIZE],
        read_original(original_image, FD000_OFFSET, FD000_SIZE),
        START_ADDRESS + FD000_OFFSET,
    )


def test_func_0016D000_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016D000."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016D100_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016D100 (268 bytes / 67 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FD100_OFFSET:FD100_OFFSET + FD100_SIZE],
        read_original(original_image, FD100_OFFSET, FD100_SIZE),
        START_ADDRESS + FD100_OFFSET,
    )


def test_func_0016D100_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016D100."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016D210_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016D210 (268 bytes / 67 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FD210_OFFSET:FD210_OFFSET + FD210_SIZE],
        read_original(original_image, FD210_OFFSET, FD210_SIZE),
        START_ADDRESS + FD210_OFFSET,
    )


def test_func_0016D210_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016D210."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016D320_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016D320 (268 bytes / 67 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FD320_OFFSET:FD320_OFFSET + FD320_SIZE],
        read_original(original_image, FD320_OFFSET, FD320_SIZE),
        START_ADDRESS + FD320_OFFSET,
    )


def test_func_0016D320_tail_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016D320."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
