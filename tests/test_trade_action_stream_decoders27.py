"""Compile and compare the trade action stream decoders27."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders27_support")

from trade_action_stream_decoders27_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F4C50_OFFSET, F4C50_SIZE, F4EF0_OFFSET, F4EF0_SIZE,
    F5160_OFFSET, F5160_SIZE, F5390_OFFSET, F5390_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE, START_ADDRESS, assert_same_code,
    original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders27_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 2,380 compiler code bytes plus 36 linker/slice-alignment bytes = 2,416B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00164C50_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00164C50 (660 bytes / 165 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F4C50_OFFSET:F4C50_OFFSET + F4C50_SIZE],
        read_original(original_image, F4C50_OFFSET, F4C50_SIZE),
        START_ADDRESS + F4C50_OFFSET,
    )


def test_func_00164C50_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00164C50."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00164EF0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00164EF0 (616 bytes / 154 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F4EF0_OFFSET:F4EF0_OFFSET + F4EF0_SIZE],
        read_original(original_image, F4EF0_OFFSET, F4EF0_SIZE),
        START_ADDRESS + F4EF0_OFFSET,
    )


def test_func_00164EF0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00164EF0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00165160_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00165160 (552 bytes / 138 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F5160_OFFSET:F5160_OFFSET + F5160_SIZE],
        read_original(original_image, F5160_OFFSET, F5160_SIZE),
        START_ADDRESS + F5160_OFFSET,
    )


def test_func_00165160_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00165160."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00165390_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00165390 (552 bytes / 138 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F5390_OFFSET:F5390_OFFSET + F5390_SIZE],
        read_original(original_image, F5390_OFFSET, F5390_SIZE),
        START_ADDRESS + F5390_OFFSET,
    )


def test_func_00165390_tail_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00165390."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
