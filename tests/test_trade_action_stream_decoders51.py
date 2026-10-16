"""Compile and compare the trade action stream decoders51."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders51_support")

from trade_action_stream_decoders51_support import (  # noqa: E402
    FC920_OFFSET, FC920_SIZE, FC9C0_OFFSET, FC9C0_SIZE,
    FCA60_OFFSET, FCA60_SIZE, FCB40_OFFSET, FCB40_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders51_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 748 compiler code bytes plus 20 linker/slice-alignment bytes = 768B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016C920_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016C920 (156 bytes / 39 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FC920_OFFSET:FC920_OFFSET + FC920_SIZE],
        read_original(original_image, FC920_OFFSET, FC920_SIZE),
        START_ADDRESS + FC920_OFFSET,
    )


def test_func_0016C920_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016C920."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016C9C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016C9C0 (156 bytes / 39 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FC9C0_OFFSET:FC9C0_OFFSET + FC9C0_SIZE],
        read_original(original_image, FC9C0_OFFSET, FC9C0_SIZE),
        START_ADDRESS + FC9C0_OFFSET,
    )


def test_func_0016C9C0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016C9C0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016CA60_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016CA60 (216 bytes / 54 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FCA60_OFFSET:FCA60_OFFSET + FCA60_SIZE],
        read_original(original_image, FCA60_OFFSET, FCA60_SIZE),
        START_ADDRESS + FCA60_OFFSET,
    )


def test_func_0016CA60_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016CA60."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016CB40_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016CB40 (220 bytes / 55 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FCB40_OFFSET:FCB40_OFFSET + FCB40_SIZE],
        read_original(original_image, FCB40_OFFSET, FCB40_SIZE),
        START_ADDRESS + FCB40_OFFSET,
    )


def test_func_0016CB40_tail_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016CB40."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
