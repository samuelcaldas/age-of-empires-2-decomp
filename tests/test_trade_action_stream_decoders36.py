"""Compile and compare the trade action stream decoders36."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders36_support")

from trade_action_stream_decoders36_support import (  # noqa: E402
    F88C0_OFFSET, F88C0_SIZE, F8960_OFFSET, F8960_SIZE,
    F8A30_OFFSET, F8A30_SIZE, F8B20_OFFSET, F8B20_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders36_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 868 compiler code bytes plus 12 linker/slice-alignment bytes = 880B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_001688C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001688C0 (156 bytes / 39 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F88C0_OFFSET:F88C0_OFFSET + F88C0_SIZE],
        read_original(original_image, F88C0_OFFSET, F88C0_SIZE),
        START_ADDRESS + F88C0_OFFSET,
    )


def test_func_001688C0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001688C0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00168960_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168960 (208 bytes / 52 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8960_OFFSET:F8960_OFFSET + F8960_SIZE],
        read_original(original_image, F8960_OFFSET, F8960_SIZE),
        START_ADDRESS + F8960_OFFSET,
    )


def test_func_00168A30_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168A30 (240 bytes / 60 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8A30_OFFSET:F8A30_OFFSET + F8A30_SIZE],
        read_original(original_image, F8A30_OFFSET, F8A30_SIZE),
        START_ADDRESS + F8A30_OFFSET,
    )


def test_func_00168B20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00168B20 (264 bytes / 66 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F8B20_OFFSET:F8B20_OFFSET + F8B20_SIZE],
        read_original(original_image, F8B20_OFFSET, F8B20_SIZE),
        START_ADDRESS + F8B20_OFFSET,
    )


def test_func_00168B20_tail_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00168B20."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
