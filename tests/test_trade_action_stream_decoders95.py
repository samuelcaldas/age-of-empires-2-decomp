"""Compile and compare the trade action stream decoders95."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders95_support")

from trade_action_stream_decoders95_support import (  # noqa: E402
    FF4D0_OFFSET, FF4D0_SIZE, FF660_OFFSET, FF660_SIZE,
    FF840_OFFSET, FF840_SIZE, FFA80_OFFSET, FFA80_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders95_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1852 compiler code bytes plus 20 linker/slice-alignment bytes = 1872B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_001774D0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001774D0 (396 bytes / 99 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF4D0_OFFSET:FF4D0_OFFSET + FF4D0_SIZE],
        read_original(original_image, FF4D0_OFFSET, FF4D0_SIZE),
        START_ADDRESS + FF4D0_OFFSET,
    )


def test_func_001774D0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001774D0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00177660_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00177660 (468 bytes / 117 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF660_OFFSET:FF660_OFFSET + FF660_SIZE],
        read_original(original_image, FF660_OFFSET, FF660_SIZE),
        START_ADDRESS + FF660_OFFSET,
    )


def test_func_00177660_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00177660."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00177840_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00177840 (576 bytes / 144 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF840_OFFSET:FF840_OFFSET + FF840_SIZE],
        read_original(original_image, FF840_OFFSET, FF840_SIZE),
        START_ADDRESS + FF840_OFFSET,
    )


def test_func_00177A80_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00177A80 (412 bytes / 103 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFA80_OFFSET:FFA80_OFFSET + FFA80_SIZE],
        read_original(original_image, FFA80_OFFSET, FFA80_SIZE),
        START_ADDRESS + FFA80_OFFSET,
    )


def test_func_00177A80_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00177A80."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
