"""Compile and compare the trade action stream decoders52."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders52_support")

from trade_action_stream_decoders52_support import (  # noqa: E402
    FCC20_OFFSET, FCC20_SIZE, FCD00_OFFSET, FCD00_SIZE,
    FCE00_OFFSET, FCE00_SIZE, FCF00_OFFSET, FCF00_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders52_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 948 compiler code bytes plus 44 linker/slice-alignment bytes = 992B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016CC20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016CC20 (216 bytes / 54 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FCC20_OFFSET:FCC20_OFFSET + FCC20_SIZE],
        read_original(original_image, FCC20_OFFSET, FCC20_SIZE),
        START_ADDRESS + FCC20_OFFSET,
    )


def test_func_0016CC20_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016CC20."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016CD00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016CD00 (244 bytes / 61 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FCD00_OFFSET:FCD00_OFFSET + FCD00_SIZE],
        read_original(original_image, FCD00_OFFSET, FCD00_SIZE),
        START_ADDRESS + FCD00_OFFSET,
    )


def test_func_0016CD00_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016CD00."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016CE00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016CE00 (244 bytes / 61 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FCE00_OFFSET:FCE00_OFFSET + FCE00_SIZE],
        read_original(original_image, FCE00_OFFSET, FCE00_SIZE),
        START_ADDRESS + FCE00_OFFSET,
    )


def test_func_0016CE00_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016CE00."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016CF00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016CF00 (244 bytes / 61 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FCF00_OFFSET:FCF00_OFFSET + FCF00_SIZE],
        read_original(original_image, FCF00_OFFSET, FCF00_SIZE),
        START_ADDRESS + FCF00_OFFSET,
    )


def test_func_0016CF00_tail_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016CF00."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
