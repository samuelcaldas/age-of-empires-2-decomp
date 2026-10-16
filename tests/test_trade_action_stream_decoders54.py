"""Compile and compare the trade action stream decoders54."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders54_support")

from trade_action_stream_decoders54_support import (  # noqa: E402
    FD430_OFFSET, FD430_SIZE, FD540_OFFSET, FD540_SIZE,
    FD5F0_OFFSET, FD5F0_SIZE, FD6F0_OFFSET, FD6F0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders54_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 956 compiler code bytes plus 20 linker/slice-alignment bytes = 976B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016D430_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016D430 (268 bytes / 67 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FD430_OFFSET:FD430_OFFSET + FD430_SIZE],
        read_original(original_image, FD430_OFFSET, FD430_SIZE),
        START_ADDRESS + FD430_OFFSET,
    )


def test_func_0016D430_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016D430."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016D540_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016D540 (172 bytes / 43 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FD540_OFFSET:FD540_OFFSET + FD540_SIZE],
        read_original(original_image, FD540_OFFSET, FD540_SIZE),
        START_ADDRESS + FD540_OFFSET,
    )


def test_func_0016D540_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016D540."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016D5F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016D5F0 (244 bytes / 61 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FD5F0_OFFSET:FD5F0_OFFSET + FD5F0_SIZE],
        read_original(original_image, FD5F0_OFFSET, FD5F0_SIZE),
        START_ADDRESS + FD5F0_OFFSET,
    )


def test_func_0016D5F0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016D5F0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016D6F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016D6F0 (272 bytes / 68 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FD6F0_OFFSET:FD6F0_OFFSET + FD6F0_SIZE],
        read_original(original_image, FD6F0_OFFSET, FD6F0_SIZE),
        START_ADDRESS + FD6F0_OFFSET,
    )
