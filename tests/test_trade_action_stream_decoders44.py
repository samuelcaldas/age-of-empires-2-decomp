"""Compile and compare the trade action stream decoders44."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders44_support")

from trade_action_stream_decoders44_support import (  # noqa: E402
    FA5D0_OFFSET, FA5D0_SIZE, FA6D0_OFFSET, FA6D0_SIZE,
    FA800_OFFSET, FA800_SIZE, FA920_OFFSET, FA920_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders44_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,112 compiler code bytes plus 40 linker/slice-alignment bytes = 1,152B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016A5D0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016A5D0 (248 bytes / 62 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FA5D0_OFFSET:FA5D0_OFFSET + FA5D0_SIZE],
        read_original(original_image, FA5D0_OFFSET, FA5D0_SIZE),
        START_ADDRESS + FA5D0_OFFSET,
    )


def test_func_0016A5D0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016A5D0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016A6D0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016A6D0 (292 bytes / 73 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FA6D0_OFFSET:FA6D0_OFFSET + FA6D0_SIZE],
        read_original(original_image, FA6D0_OFFSET, FA6D0_SIZE),
        START_ADDRESS + FA6D0_OFFSET,
    )


def test_func_0016A6D0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016A6D0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016A800_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016A800 (280 bytes / 70 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FA800_OFFSET:FA800_OFFSET + FA800_SIZE],
        read_original(original_image, FA800_OFFSET, FA800_SIZE),
        START_ADDRESS + FA800_OFFSET,
    )


def test_func_0016A800_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016A800."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016A920_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016A920 (292 bytes / 73 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FA920_OFFSET:FA920_OFFSET + FA920_SIZE],
        read_original(original_image, FA920_OFFSET, FA920_SIZE),
        START_ADDRESS + FA920_OFFSET,
    )


def test_func_0016A920_tail_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016A920."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
