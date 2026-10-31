"""Compile and compare the trade action stream decoders16."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders16_support")

from trade_action_stream_decoders16_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F0400_OFFSET, F0400_SIZE, F05A0_OFFSET, F05A0_SIZE,
    F0730_OFFSET, F0730_SIZE, F0950_OFFSET, F0950_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE, START_ADDRESS, assert_same_code,
    original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders16_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,860 compiler code bytes plus 44 linker/slice-alignment bytes = 1,904B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00160400_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00160400 (404 bytes, 100% exact)."""
    actual = decoder_code[F0400_OFFSET:F0400_OFFSET + F0400_SIZE]
    expected = read_original(original_image, F0400_OFFSET, F0400_SIZE)
    assert_same_code(actual, expected, START_ADDRESS + F0400_OFFSET)


def test_func_00160400_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00160400."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_001605A0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001605A0 (388 bytes / 97 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F05A0_OFFSET:F05A0_OFFSET + F05A0_SIZE],
        read_original(original_image, F05A0_OFFSET, F05A0_SIZE),
        START_ADDRESS + F05A0_OFFSET,
    )


def test_func_001605A0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001605A0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00160730_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00160730 (532 bytes / 133 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F0730_OFFSET:F0730_OFFSET + F0730_SIZE],
        read_original(original_image, F0730_OFFSET, F0730_SIZE),
        START_ADDRESS + F0730_OFFSET,
    )


def test_func_00160730_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00160730."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00160950_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00160950 (536 bytes / 134 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F0950_OFFSET:F0950_OFFSET + F0950_SIZE],
        read_original(original_image, F0950_OFFSET, F0950_SIZE),
        START_ADDRESS + F0950_OFFSET,
    )


def test_func_00160950_tail_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00160950."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
