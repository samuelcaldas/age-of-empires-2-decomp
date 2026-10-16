"""Compile and compare the trade action stream decoders81."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders81_support")

from trade_action_stream_decoders81_support import (  # noqa: E402
    FFA60_OFFSET, FFA60_SIZE, FFB00_OFFSET, FFB00_SIZE,
    FFB80_OFFSET, FFB80_SIZE, FFC00_OFFSET, FFC00_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders81_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 552 compiler code bytes plus 24 linker/slice-alignment bytes = 576B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00173A60_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173A60 (152 bytes / 38 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFA60_OFFSET:FFA60_OFFSET + FFA60_SIZE],
        read_original(original_image, FFA60_OFFSET, FFA60_SIZE),
        START_ADDRESS + FFA60_OFFSET,
    )


def test_func_00173A60_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00173A60."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00173B00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173B00 (124 bytes / 31 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFB00_OFFSET:FFB00_OFFSET + FFB00_SIZE],
        read_original(original_image, FFB00_OFFSET, FFB00_SIZE),
        START_ADDRESS + FFB00_OFFSET,
    )


def test_func_00173B00_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00173B00."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00173B80_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173B80 (124 bytes / 31 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFB80_OFFSET:FFB80_OFFSET + FFB80_SIZE],
        read_original(original_image, FFB80_OFFSET, FFB80_SIZE),
        START_ADDRESS + FFB80_OFFSET,
    )


def test_func_00173B80_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00173B80."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00173C00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173C00 (152 bytes / 38 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFC00_OFFSET:FFC00_OFFSET + FFC00_SIZE],
        read_original(original_image, FFC00_OFFSET, FFC00_SIZE),
        START_ADDRESS + FFC00_OFFSET,
    )


def test_func_00173C00_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00173C00."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
