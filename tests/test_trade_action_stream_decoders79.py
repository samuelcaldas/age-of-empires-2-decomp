"""Compile and compare the trade action stream decoders79."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders79_support")

from trade_action_stream_decoders79_support import (  # noqa: E402
    FF750_OFFSET, FF750_SIZE, FF7A0_OFFSET, FF7A0_SIZE,
    FF7F0_OFFSET, FF7F0_SIZE, FF840_OFFSET, FF840_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders79_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 304 compiler code bytes plus 16 linker/slice-alignment bytes = 320B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00173750_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173750 (76 bytes / 19 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF750_OFFSET:FF750_OFFSET + FF750_SIZE],
        read_original(original_image, FF750_OFFSET, FF750_SIZE),
        START_ADDRESS + FF750_OFFSET,
    )


def test_func_00173750_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00173750."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_001737A0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001737A0 (76 bytes / 19 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF7A0_OFFSET:FF7A0_OFFSET + FF7A0_SIZE],
        read_original(original_image, FF7A0_OFFSET, FF7A0_SIZE),
        START_ADDRESS + FF7A0_OFFSET,
    )


def test_func_001737A0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001737A0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_001737F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001737F0 (76 bytes / 19 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF7F0_OFFSET:FF7F0_OFFSET + FF7F0_SIZE],
        read_original(original_image, FF7F0_OFFSET, FF7F0_SIZE),
        START_ADDRESS + FF7F0_OFFSET,
    )


def test_func_001737F0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001737F0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00173840_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173840 (76 bytes / 19 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF840_OFFSET:FF840_OFFSET + FF840_SIZE],
        read_original(original_image, FF840_OFFSET, FF840_SIZE),
        START_ADDRESS + FF840_OFFSET,
    )


def test_func_00173840_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00173840."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
