"""Compile and compare the trade action stream decoders49."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders49_support")

from trade_action_stream_decoders49_support import (  # noqa: E402
    FBF90_OFFSET, FBF90_SIZE, FC150_OFFSET, FC150_SIZE,
    FC2A0_OFFSET, FC2A0_SIZE, FC440_OFFSET, FC440_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders49_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,640 compiler code bytes plus 24 linker/slice-alignment bytes = 1,664B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016BF90_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016BF90 (448 bytes / 112 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FBF90_OFFSET:FBF90_OFFSET + FBF90_SIZE],
        read_original(original_image, FBF90_OFFSET, FBF90_SIZE),
        START_ADDRESS + FBF90_OFFSET,
    )


def test_func_0016C150_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016C150 (332 bytes / 83 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FC150_OFFSET:FC150_OFFSET + FC150_SIZE],
        read_original(original_image, FC150_OFFSET, FC150_SIZE),
        START_ADDRESS + FC150_OFFSET,
    )


def test_func_0016C150_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016C150."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016C2A0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016C2A0 (408 bytes / 102 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FC2A0_OFFSET:FC2A0_OFFSET + FC2A0_SIZE],
        read_original(original_image, FC2A0_OFFSET, FC2A0_SIZE),
        START_ADDRESS + FC2A0_OFFSET,
    )


def test_func_0016C2A0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016C2A0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016C440_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016C440 (452 bytes / 113 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FC440_OFFSET:FC440_OFFSET + FC440_SIZE],
        read_original(original_image, FC440_OFFSET, FC440_SIZE),
        START_ADDRESS + FC440_OFFSET,
    )


def test_func_0016C440_tail_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016C440."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
