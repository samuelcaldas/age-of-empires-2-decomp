"""Compile and compare the trade action stream decoders37."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders37_support")

from trade_action_stream_decoders37_support import (  # noqa: E402
    F8C30_OFFSET, F8C30_SIZE, F8D00_OFFSET, F8D00_SIZE,
    F8E00_OFFSET, F8E00_SIZE, F8F20_OFFSET, F8F20_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders37_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,040 compiler code bytes plus 16 linker/slice-alignment bytes = 1,056B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00168C30_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168C30 (208 bytes / 52 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8C30_OFFSET:F8C30_OFFSET + F8C30_SIZE],
        read_original(original_image, F8C30_OFFSET, F8C30_SIZE),
        START_ADDRESS + F8C30_OFFSET,
    )


def test_func_00168D00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168D00 (248 bytes / 62 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8D00_OFFSET:F8D00_OFFSET + F8D00_SIZE],
        read_original(original_image, F8D00_OFFSET, F8D00_SIZE),
        START_ADDRESS + F8D00_OFFSET,
    )


def test_func_00168D00_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00168D00."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00168E00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168E00 (280 bytes / 70 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8E00_OFFSET:F8E00_OFFSET + F8E00_SIZE],
        read_original(original_image, F8E00_OFFSET, F8E00_SIZE),
        START_ADDRESS + F8E00_OFFSET,
    )


def test_func_00168E00_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00168E00."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00168F20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168F20 (304 bytes / 76 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8F20_OFFSET:F8F20_OFFSET + F8F20_SIZE],
        read_original(original_image, F8F20_OFFSET, F8F20_SIZE),
        START_ADDRESS + F8F20_OFFSET,
    )
