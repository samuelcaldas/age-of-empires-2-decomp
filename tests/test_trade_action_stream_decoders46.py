"""Compile and compare the trade action stream decoders46."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders46_support")

from trade_action_stream_decoders46_support import (  # noqa: E402
    FAF70_OFFSET, FAF70_SIZE, FB0E0_OFFSET, FB0E0_SIZE,
    FB1A0_OFFSET, FB1A0_SIZE, FB2C0_OFFSET, FB2C0_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders46_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,152 compiler code bytes plus 16 linker/slice-alignment bytes = 1,168B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016AF70_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016AF70 (368 bytes / 92 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FAF70_OFFSET:FAF70_OFFSET + FAF70_SIZE],
        read_original(original_image, FAF70_OFFSET, FAF70_SIZE),
        START_ADDRESS + FAF70_OFFSET,
    )


def test_func_0016B0E0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016B0E0 (188 bytes / 47 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FB0E0_OFFSET:FB0E0_OFFSET + FB0E0_SIZE],
        read_original(original_image, FB0E0_OFFSET, FB0E0_SIZE),
        START_ADDRESS + FB0E0_OFFSET,
    )


def test_func_0016B0E0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016B0E0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016B1A0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016B1A0 (276 bytes / 69 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FB1A0_OFFSET:FB1A0_OFFSET + FB1A0_SIZE],
        read_original(original_image, FB1A0_OFFSET, FB1A0_SIZE),
        START_ADDRESS + FB1A0_OFFSET,
    )


def test_func_0016B1A0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016B1A0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016B2C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016B2C0 (320 bytes / 80 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FB2C0_OFFSET:FB2C0_OFFSET + FB2C0_SIZE],
        read_original(original_image, FB2C0_OFFSET, FB2C0_SIZE),
        START_ADDRESS + FB2C0_OFFSET,
    )
