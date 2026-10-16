"""Compile and compare the trade action stream decoders94."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders94_support")

from trade_action_stream_decoders94_support import (  # noqa: E402
    FF160_OFFSET, FF160_SIZE, FF370_OFFSET, FF370_SIZE,
    FFE60_OFFSET, FFE60_SIZE, FFFC0_OFFSET, FFFC0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders94_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1628 compiler code bytes plus 20 linker/slice-alignment bytes = 1648B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00176E60_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00176E60 (344 bytes / 86 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFE60_OFFSET:FFE60_OFFSET + FFE60_SIZE],
        read_original(original_image, FFE60_OFFSET, FFE60_SIZE),
        START_ADDRESS + FFE60_OFFSET,
    )


def test_func_00176E60_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00176E60."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00176FC0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00176FC0 (416 bytes / 104 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFFC0_OFFSET:FFFC0_OFFSET + FFFC0_SIZE],
        read_original(original_image, FFFC0_OFFSET, FFFC0_SIZE),
        START_ADDRESS + FFFC0_OFFSET,
    )


def test_func_00177160_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00177160 (524 bytes / 131 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF160_OFFSET:FF160_OFFSET + FF160_SIZE],
        read_original(original_image, FF160_OFFSET, FF160_SIZE),
        START_ADDRESS + FF160_OFFSET,
    )


def test_func_00177160_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00177160."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00177370_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00177370 (344 bytes / 86 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF370_OFFSET:FF370_OFFSET + FF370_SIZE],
        read_original(original_image, FF370_OFFSET, FF370_SIZE),
        START_ADDRESS + FF370_OFFSET,
    )


def test_func_00177370_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00177370."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
