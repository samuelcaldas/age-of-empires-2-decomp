"""Compile and compare the trade action stream decoders33."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders33_support")

from trade_action_stream_decoders33_support import (  # noqa: E402
    F7EB0_OFFSET, F7EB0_SIZE, F7F40_OFFSET, F7F40_SIZE,
    F8000_OFFSET, F8000_SIZE, F80C0_OFFSET, F80C0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders33_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 680 compiler code bytes plus 40 linker/slice-alignment bytes = 720B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00167EB0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00167EB0 (140 bytes / 35 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F7EB0_OFFSET:F7EB0_OFFSET + F7EB0_SIZE],
        read_original(original_image, F7EB0_OFFSET, F7EB0_SIZE),
        START_ADDRESS + F7EB0_OFFSET,
    )


def test_func_00167EB0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00167EB0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00167F40_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00167F40 (180 bytes / 45 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F7F40_OFFSET:F7F40_OFFSET + F7F40_SIZE],
        read_original(original_image, F7F40_OFFSET, F7F40_SIZE),
        START_ADDRESS + F7F40_OFFSET,
    )


def test_func_00167F40_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00167F40."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00168000_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168000 (180 bytes / 45 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8000_OFFSET:F8000_OFFSET + F8000_SIZE],
        read_original(original_image, F8000_OFFSET, F8000_SIZE),
        START_ADDRESS + F8000_OFFSET,
    )


def test_func_00168000_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00168000."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_001680C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001680C0 (180 bytes / 45 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F80C0_OFFSET:F80C0_OFFSET + F80C0_SIZE],
        read_original(original_image, F80C0_OFFSET, F80C0_SIZE),
        START_ADDRESS + F80C0_OFFSET,
    )


def test_func_001680C0_tail_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001680C0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
