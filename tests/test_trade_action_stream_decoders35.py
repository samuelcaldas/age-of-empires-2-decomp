"""Compile and compare the trade action stream decoders35."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders35_support")

from trade_action_stream_decoders35_support import (  # noqa: E402
    F8500_OFFSET, F8500_SIZE, F85F0_OFFSET, F85F0_SIZE,
    F86E0_OFFSET, F86E0_SIZE, F87D0_OFFSET, F87D0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders35_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 944 compiler code bytes plus 16 linker/slice-alignment bytes = 960B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00168500_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168500 (236 bytes / 59 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8500_OFFSET:F8500_OFFSET + F8500_SIZE],
        read_original(original_image, F8500_OFFSET, F8500_SIZE),
        START_ADDRESS + F8500_OFFSET,
    )


def test_func_00168500_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00168500."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_001685F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001685F0 (236 bytes / 59 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F85F0_OFFSET:F85F0_OFFSET + F85F0_SIZE],
        read_original(original_image, F85F0_OFFSET, F85F0_SIZE),
        START_ADDRESS + F85F0_OFFSET,
    )


def test_func_001685F0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001685F0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_001686E0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001686E0 (236 bytes / 59 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F86E0_OFFSET:F86E0_OFFSET + F86E0_SIZE],
        read_original(original_image, F86E0_OFFSET, F86E0_SIZE),
        START_ADDRESS + F86E0_OFFSET,
    )


def test_func_001686E0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001686E0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_001687D0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001687D0 (236 bytes / 59 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F87D0_OFFSET:F87D0_OFFSET + F87D0_SIZE],
        read_original(original_image, F87D0_OFFSET, F87D0_SIZE),
        START_ADDRESS + F87D0_OFFSET,
    )


def test_func_001687D0_tail_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001687D0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
