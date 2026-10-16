"""Compile and compare the trade action stream decoders41."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders41_support")

from trade_action_stream_decoders41_support import (  # noqa: E402
    F9BA0_OFFSET, F9BA0_SIZE, F9C20_OFFSET, F9C20_SIZE,
    F9CC0_OFFSET, F9CC0_SIZE, F9D60_OFFSET, F9D60_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders41_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 640 compiler code bytes plus 32 linker/slice-alignment bytes = 672B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00169BA0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169BA0 (124 bytes / 31 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9BA0_OFFSET:F9BA0_OFFSET + F9BA0_SIZE],
        read_original(original_image, F9BA0_OFFSET, F9BA0_SIZE),
        START_ADDRESS + F9BA0_OFFSET,
    )


def test_func_00169BA0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00169BA0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00169C20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169C20 (148 bytes / 37 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9C20_OFFSET:F9C20_OFFSET + F9C20_SIZE],
        read_original(original_image, F9C20_OFFSET, F9C20_SIZE),
        START_ADDRESS + F9C20_OFFSET,
    )


def test_func_00169C20_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00169C20."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00169CC0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169CC0 (152 bytes / 38 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9CC0_OFFSET:F9CC0_OFFSET + F9CC0_SIZE],
        read_original(original_image, F9CC0_OFFSET, F9CC0_SIZE),
        START_ADDRESS + F9CC0_OFFSET,
    )


def test_func_00169CC0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00169CC0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00169D60_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169D60 (216 bytes / 54 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9D60_OFFSET:F9D60_OFFSET + F9D60_SIZE],
        read_original(original_image, F9D60_OFFSET, F9D60_SIZE),
        START_ADDRESS + F9D60_OFFSET,
    )


def test_func_00169D60_tail_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00169D60."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
