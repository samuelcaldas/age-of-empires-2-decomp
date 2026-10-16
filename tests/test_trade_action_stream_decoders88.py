"""Compile and compare the trade action stream decoders88."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders88_support")

from trade_action_stream_decoders88_support import (  # noqa: E402
    FF150_OFFSET, FF150_SIZE, FF190_OFFSET, FF190_SIZE,
    FF210_OFFSET, FF210_SIZE, FF280_OFFSET, FF280_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders88_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 544 compiler code bytes plus 16 linker/slice-alignment bytes = 560B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00175150_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175150 (56 bytes / 14 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF150_OFFSET:FF150_OFFSET + FF150_SIZE],
        read_original(original_image, FF150_OFFSET, FF150_SIZE),
        START_ADDRESS + FF150_OFFSET,
    )


def test_func_00175150_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00175150."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00175190_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175190 (128 bytes / 32 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF190_OFFSET:FF190_OFFSET + FF190_SIZE],
        read_original(original_image, FF190_OFFSET, FF190_SIZE),
        START_ADDRESS + FF190_OFFSET,
    )


def test_func_00175210_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175210 (108 bytes / 27 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF210_OFFSET:FF210_OFFSET + FF210_SIZE],
        read_original(original_image, FF210_OFFSET, FF210_SIZE),
        START_ADDRESS + FF210_OFFSET,
    )


def test_func_00175210_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00175210."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00175280_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00175280 (252 bytes / 63 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF280_OFFSET:FF280_OFFSET + FF280_SIZE],
        read_original(original_image, FF280_OFFSET, FF280_SIZE),
        START_ADDRESS + FF280_OFFSET,
    )


def test_func_00175280_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00175280."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
