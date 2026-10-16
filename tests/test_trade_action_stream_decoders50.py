"""Compile and compare the trade action stream decoders50."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders50_support")

from trade_action_stream_decoders50_support import (  # noqa: E402
    FC610_OFFSET, FC610_SIZE, FC7E0_OFFSET, FC7E0_SIZE,
    FC820_OFFSET, FC820_SIZE, FC890_OFFSET, FC890_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders50_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 764 compiler code bytes plus 20 linker/slice-alignment bytes = 784B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016C610_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016C610 (460 bytes / 115 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FC610_OFFSET:FC610_OFFSET + FC610_SIZE],
        read_original(original_image, FC610_OFFSET, FC610_SIZE),
        START_ADDRESS + FC610_OFFSET,
    )


def test_func_0016C610_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016C610."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016C7E0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016C7E0 (64 bytes / 16 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FC7E0_OFFSET:FC7E0_OFFSET + FC7E0_SIZE],
        read_original(original_image, FC7E0_OFFSET, FC7E0_SIZE),
        START_ADDRESS + FC7E0_OFFSET,
    )


def test_func_0016C820_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016C820 (108 bytes / 27 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FC820_OFFSET:FC820_OFFSET + FC820_SIZE],
        read_original(original_image, FC820_OFFSET, FC820_SIZE),
        START_ADDRESS + FC820_OFFSET,
    )


def test_func_0016C820_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016C820."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016C890_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016C890 (132 bytes / 33 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FC890_OFFSET:FC890_OFFSET + FC890_SIZE],
        read_original(original_image, FC890_OFFSET, FC890_SIZE),
        START_ADDRESS + FC890_OFFSET,
    )


def test_func_0016C890_tail_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016C890."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
