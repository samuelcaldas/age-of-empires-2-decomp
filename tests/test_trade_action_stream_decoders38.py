"""Compile and compare the trade action stream decoders38."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders38_support")

from trade_action_stream_decoders38_support import (  # noqa: E402
    F9050_OFFSET, F9050_SIZE, F9140_OFFSET, F9140_SIZE,
    F9260_OFFSET, F9260_SIZE, F93A0_OFFSET, F93A0_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders38_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,168 compiler code bytes plus 16 linker/slice-alignment bytes = 1,184B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00169050_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169050 (240 bytes / 60 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9050_OFFSET:F9050_OFFSET + F9050_SIZE],
        read_original(original_image, F9050_OFFSET, F9050_SIZE),
        START_ADDRESS + F9050_OFFSET,
    )


def test_func_00169140_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169140 (280 bytes / 70 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9140_OFFSET:F9140_OFFSET + F9140_SIZE],
        read_original(original_image, F9140_OFFSET, F9140_SIZE),
        START_ADDRESS + F9140_OFFSET,
    )


def test_func_00169140_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00169140."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00169260_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169260 (312 bytes / 78 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9260_OFFSET:F9260_OFFSET + F9260_SIZE],
        read_original(original_image, F9260_OFFSET, F9260_SIZE),
        START_ADDRESS + F9260_OFFSET,
    )


def test_func_00169260_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00169260."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_001693A0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001693A0 (336 bytes / 84 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F93A0_OFFSET:F93A0_OFFSET + F93A0_SIZE],
        read_original(original_image, F93A0_OFFSET, F93A0_SIZE),
        START_ADDRESS + F93A0_OFFSET,
    )
