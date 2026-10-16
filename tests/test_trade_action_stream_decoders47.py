"""Compile and compare the trade action stream decoders47."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders47_support")

from trade_action_stream_decoders47_support import (  # noqa: E402
    FB400_OFFSET, FB400_SIZE, FB550_OFFSET, FB550_SIZE,
    FB670_OFFSET, FB670_SIZE, FB7D0_OFFSET, FB7D0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders47_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,352 compiler code bytes plus 24 linker/slice-alignment bytes = 1,376B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016B400_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016B400 (328 bytes / 82 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FB400_OFFSET:FB400_OFFSET + FB400_SIZE],
        read_original(original_image, FB400_OFFSET, FB400_SIZE),
        START_ADDRESS + FB400_OFFSET,
    )


def test_func_0016B400_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016B400."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016B550_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016B550 (276 bytes / 69 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FB550_OFFSET:FB550_OFFSET + FB550_SIZE],
        read_original(original_image, FB550_OFFSET, FB550_SIZE),
        START_ADDRESS + FB550_OFFSET,
    )


def test_func_0016B550_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016B550."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016B670_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016B670 (352 bytes / 88 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FB670_OFFSET:FB670_OFFSET + FB670_SIZE],
        read_original(original_image, FB670_OFFSET, FB670_SIZE),
        START_ADDRESS + FB670_OFFSET,
    )


def test_func_0016B7D0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016B7D0 (396 bytes / 99 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FB7D0_OFFSET:FB7D0_OFFSET + FB7D0_SIZE],
        read_original(original_image, FB7D0_OFFSET, FB7D0_SIZE),
        START_ADDRESS + FB7D0_OFFSET,
    )


def test_func_0016B7D0_tail_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016B7D0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
