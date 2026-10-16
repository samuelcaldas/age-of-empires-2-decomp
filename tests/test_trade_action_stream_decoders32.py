"""Compile and compare the trade action stream decoders32."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders32_support")

from trade_action_stream_decoders32_support import (  # noqa: E402
    F7D10_OFFSET, F7D10_SIZE, F7D40_OFFSET, F7D40_SIZE,
    F7DA0_OFFSET, F7DA0_SIZE, F7E20_OFFSET, F7E20_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders32_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 392 compiler code bytes plus 24 linker/slice-alignment bytes = 416B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00167D10_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00167D10 (44 bytes / 11 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F7D10_OFFSET:F7D10_OFFSET + F7D10_SIZE],
        read_original(original_image, F7D10_OFFSET, F7D10_SIZE),
        START_ADDRESS + F7D10_OFFSET,
    )


def test_func_00167D10_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00167D10."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00167D40_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00167D40 (92 bytes / 23 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F7D40_OFFSET:F7D40_OFFSET + F7D40_SIZE],
        read_original(original_image, F7D40_OFFSET, F7D40_SIZE),
        START_ADDRESS + F7D40_OFFSET,
    )


def test_func_00167D40_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00167D40."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00167DA0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00167DA0 (116 bytes / 29 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F7DA0_OFFSET:F7DA0_OFFSET + F7DA0_SIZE],
        read_original(original_image, F7DA0_OFFSET, F7DA0_SIZE),
        START_ADDRESS + F7DA0_OFFSET,
    )


def test_func_00167DA0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00167DA0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00167E20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00167E20 (140 bytes / 35 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F7E20_OFFSET:F7E20_OFFSET + F7E20_SIZE],
        read_original(original_image, F7E20_OFFSET, F7E20_SIZE),
        START_ADDRESS + F7E20_OFFSET,
    )


def test_func_00167E20_tail_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00167E20."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
