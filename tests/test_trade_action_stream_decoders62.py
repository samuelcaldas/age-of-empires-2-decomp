"""Compile and compare the trade action stream decoders62."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders62_support")

from trade_action_stream_decoders62_support import (  # noqa: E402
    FF480_OFFSET, FF480_SIZE, FF590_OFFSET, FF590_SIZE,
    FF6C0_OFFSET, FF6C0_SIZE, FF820_OFFSET, FF820_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders62_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1192 compiler code bytes plus 24 linker/slice-alignment bytes = 1216B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016F480_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016F480 (272 bytes / 68 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF480_OFFSET:FF480_OFFSET + FF480_SIZE],
        read_original(original_image, FF480_OFFSET, FF480_SIZE),
        START_ADDRESS + FF480_OFFSET,
    )


def test_func_0016F590_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016F590 (300 bytes / 75 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF590_OFFSET:FF590_OFFSET + FF590_SIZE],
        read_original(original_image, FF590_OFFSET, FF590_SIZE),
        START_ADDRESS + FF590_OFFSET,
    )


def test_func_0016F590_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016F590."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016F6C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016F6C0 (340 bytes / 85 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF6C0_OFFSET:FF6C0_OFFSET + FF6C0_SIZE],
        read_original(original_image, FF6C0_OFFSET, FF6C0_SIZE),
        START_ADDRESS + FF6C0_OFFSET,
    )


def test_func_0016F6C0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016F6C0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016F820_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016F820 (280 bytes / 70 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF820_OFFSET:FF820_OFFSET + FF820_SIZE],
        read_original(original_image, FF820_OFFSET, FF820_SIZE),
        START_ADDRESS + FF820_OFFSET,
    )


def test_func_0016F820_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016F820."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
