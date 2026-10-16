"""Compile and compare the trade action stream decoders80."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders80_support")

from trade_action_stream_decoders80_support import (  # noqa: E402
    FF890_OFFSET, FF890_SIZE, FF910_OFFSET, FF910_SIZE,
    FF980_OFFSET, FF980_SIZE, FF9F0_OFFSET, FF9F0_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders80_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 428 compiler code bytes plus 36 linker/slice-alignment bytes = 464B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00173890_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173890 (128 bytes / 32 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF890_OFFSET:FF890_OFFSET + FF890_SIZE],
        read_original(original_image, FF890_OFFSET, FF890_SIZE),
        START_ADDRESS + FF890_OFFSET,
    )


def test_func_00173910_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173910 (100 bytes / 25 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF910_OFFSET:FF910_OFFSET + FF910_SIZE],
        read_original(original_image, FF910_OFFSET, FF910_SIZE),
        START_ADDRESS + FF910_OFFSET,
    )


def test_func_00173910_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00173910."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00173980_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173980 (100 bytes / 25 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF980_OFFSET:FF980_OFFSET + FF980_SIZE],
        read_original(original_image, FF980_OFFSET, FF980_SIZE),
        START_ADDRESS + FF980_OFFSET,
    )


def test_func_00173980_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00173980."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_001739F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001739F0 (100 bytes / 25 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF9F0_OFFSET:FF9F0_OFFSET + FF9F0_SIZE],
        read_original(original_image, FF9F0_OFFSET, FF9F0_SIZE),
        START_ADDRESS + FF9F0_OFFSET,
    )


def test_func_001739F0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001739F0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
