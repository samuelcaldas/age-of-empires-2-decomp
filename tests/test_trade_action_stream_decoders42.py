"""Compile and compare the trade action stream decoders42."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders42_support")

from trade_action_stream_decoders42_support import (  # noqa: E402
    F9E40_OFFSET, F9E40_SIZE, F9F20_OFFSET, F9F20_SIZE,
    F9FD0_OFFSET, F9FD0_SIZE, FA0B0_OFFSET, FA0B0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders42_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 872 compiler code bytes plus 24 linker/slice-alignment bytes = 896B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00169E40_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169E40 (216 bytes / 54 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9E40_OFFSET:F9E40_OFFSET + F9E40_SIZE],
        read_original(original_image, F9E40_OFFSET, F9E40_SIZE),
        START_ADDRESS + F9E40_OFFSET,
    )


def test_func_00169E40_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00169E40."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00169F20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169F20 (172 bytes / 43 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9F20_OFFSET:F9F20_OFFSET + F9F20_SIZE],
        read_original(original_image, F9F20_OFFSET, F9F20_SIZE),
        START_ADDRESS + F9F20_OFFSET,
    )


def test_func_00169F20_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00169F20."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00169FD0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169FD0 (224 bytes / 56 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9FD0_OFFSET:F9FD0_OFFSET + F9FD0_SIZE],
        read_original(original_image, F9FD0_OFFSET, F9FD0_SIZE),
        START_ADDRESS + F9FD0_OFFSET,
    )


def test_func_0016A0B0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016A0B0 (260 bytes / 65 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FA0B0_OFFSET:FA0B0_OFFSET + FA0B0_SIZE],
        read_original(original_image, FA0B0_OFFSET, FA0B0_SIZE),
        START_ADDRESS + FA0B0_OFFSET,
    )


def test_func_0016A0B0_tail_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016A0B0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
