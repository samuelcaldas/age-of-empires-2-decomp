"""Compile and compare the trade action stream decoders104."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders104_support")

from trade_action_stream_decoders104_support import (  # noqa: E402
    FF730_OFFSET, FF730_SIZE, FF930_OFFSET, FF930_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders104_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1156 compiler code bytes plus 12 linker/slice-alignment bytes = 1168B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0017a730_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017a730 (512 bytes / 128 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF730_OFFSET:FF730_OFFSET + FF730_SIZE],
        read_original(original_image, FF730_OFFSET, FF730_SIZE),
        START_ADDRESS + FF730_OFFSET,
    )


def test_func_0017a930_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017a930 (644 bytes / 161 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF930_OFFSET:FF930_OFFSET + FF930_SIZE],
        read_original(original_image, FF930_OFFSET, FF930_SIZE),
        START_ADDRESS + FF930_OFFSET,
    )


def test_func_0017a930_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0017a930."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)
