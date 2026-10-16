"""Compile and compare the trade action stream decoders76."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders76_support")

from trade_action_stream_decoders76_support import (  # noqa: E402
    FFF00_OFFSET, FFF00_SIZE, FFFF0_OFFSET, FFFF0_SIZE,
    F00F0_OFFSET, F00F0_SIZE, F0210_OFFSET, F0210_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders76_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 984 compiler code bytes plus 40 linker/slice-alignment bytes = 1024B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00172F00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172F00 (228 bytes / 57 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFF00_OFFSET:FFF00_OFFSET + FFF00_SIZE],
        read_original(original_image, FFF00_OFFSET, FFF00_SIZE),
        START_ADDRESS + FFF00_OFFSET,
    )


def test_func_00172F00_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00172F00."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00172FF0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00172FF0 (252 bytes / 63 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFFF0_OFFSET:FFFF0_OFFSET + FFFF0_SIZE],
        read_original(original_image, FFFF0_OFFSET, FFFF0_SIZE),
        START_ADDRESS + FFFF0_OFFSET,
    )


def test_func_00172FF0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00172FF0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_001730F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001730F0 (276 bytes / 69 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F00F0_OFFSET:F00F0_OFFSET + F00F0_SIZE],
        read_original(original_image, F00F0_OFFSET, F00F0_SIZE),
        START_ADDRESS + F00F0_OFFSET,
    )


def test_func_001730F0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001730F0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00173210_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173210 (228 bytes / 57 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F0210_OFFSET:F0210_OFFSET + F0210_SIZE],
        read_original(original_image, F0210_OFFSET, F0210_SIZE),
        START_ADDRESS + F0210_OFFSET,
    )


def test_func_00173210_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00173210."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
