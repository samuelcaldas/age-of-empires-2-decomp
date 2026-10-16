"""Compile and compare the trade action stream decoders34."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders34_support")

from trade_action_stream_decoders34_support import (  # noqa: E402
    F8180_OFFSET, F8180_SIZE, F8260_OFFSET, F8260_SIZE,
    F8340_OFFSET, F8340_SIZE, F8420_OFFSET, F8420_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders34_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 848 compiler code bytes plus 48 linker/slice-alignment bytes = 896B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00168180_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168180 (212 bytes / 53 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8180_OFFSET:F8180_OFFSET + F8180_SIZE],
        read_original(original_image, F8180_OFFSET, F8180_SIZE),
        START_ADDRESS + F8180_OFFSET,
    )


def test_func_00168180_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00168180."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00168260_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168260 (212 bytes / 53 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8260_OFFSET:F8260_OFFSET + F8260_SIZE],
        read_original(original_image, F8260_OFFSET, F8260_SIZE),
        START_ADDRESS + F8260_OFFSET,
    )


def test_func_00168260_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00168260."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00168340_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168340 (212 bytes / 53 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8340_OFFSET:F8340_OFFSET + F8340_SIZE],
        read_original(original_image, F8340_OFFSET, F8340_SIZE),
        START_ADDRESS + F8340_OFFSET,
    )


def test_func_00168340_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00168340."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00168420_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168420 (212 bytes / 53 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8420_OFFSET:F8420_OFFSET + F8420_SIZE],
        read_original(original_image, F8420_OFFSET, F8420_SIZE),
        START_ADDRESS + F8420_OFFSET,
    )


def test_func_00168420_tail_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00168420."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
