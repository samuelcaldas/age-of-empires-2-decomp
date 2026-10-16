"""Compile and compare the trade action stream decoders58."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders58_support")

from trade_action_stream_decoders58_support import (  # noqa: E402
    FE790_OFFSET, FE790_SIZE, FE930_OFFSET, FE930_SIZE,
    FE980_OFFSET, FE980_SIZE, FE9D0_OFFSET, FE9D0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders58_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 692 compiler code bytes plus 12 linker/slice-alignment bytes = 704B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016E790_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016E790 (408 bytes / 102 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FE790_OFFSET:FE790_OFFSET + FE790_SIZE],
        read_original(original_image, FE790_OFFSET, FE790_SIZE),
        START_ADDRESS + FE790_OFFSET,
    )


def test_func_0016E790_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016E790."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016E930_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016E930 (80 bytes / 20 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FE930_OFFSET:FE930_OFFSET + FE930_SIZE],
        read_original(original_image, FE930_OFFSET, FE930_SIZE),
        START_ADDRESS + FE930_OFFSET,
    )


def test_func_0016E980_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016E980 (80 bytes / 20 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FE980_OFFSET:FE980_OFFSET + FE980_SIZE],
        read_original(original_image, FE980_OFFSET, FE980_SIZE),
        START_ADDRESS + FE980_OFFSET,
    )


def test_func_0016E9D0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016E9D0 (124 bytes / 31 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FE9D0_OFFSET:FE9D0_OFFSET + FE9D0_SIZE],
        read_original(original_image, FE9D0_OFFSET, FE9D0_SIZE),
        START_ADDRESS + FE9D0_OFFSET,
    )


def test_func_0016E9D0_tail_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016E9D0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
