"""Compile and compare the trade action stream decoders99."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders99_support")

from trade_action_stream_decoders99_support import (  # noqa: E402
    FF040_OFFSET, FF040_SIZE, FF190_OFFSET, FF190_SIZE,
    FF290_OFFSET, FF290_SIZE, FFEE0_OFFSET, FFEE0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders99_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1160 compiler code bytes plus 40 linker/slice-alignment bytes = 1200B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00178ee0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00178ee0 (348 bytes / 87 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFEE0_OFFSET:FFEE0_OFFSET + FFEE0_SIZE],
        read_original(original_image, FFEE0_OFFSET, FFEE0_SIZE),
        START_ADDRESS + FFEE0_OFFSET,
    )


def test_func_00178ee0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00178ee0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00179040_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00179040 (324 bytes / 81 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF040_OFFSET:FF040_OFFSET + FF040_SIZE],
        read_original(original_image, FF040_OFFSET, FF040_SIZE),
        START_ADDRESS + FF040_OFFSET,
    )


def test_func_00179040_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00179040."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00179190_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00179190 (244 bytes / 61 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF190_OFFSET:FF190_OFFSET + FF190_SIZE],
        read_original(original_image, FF190_OFFSET, FF190_SIZE),
        START_ADDRESS + FF190_OFFSET,
    )


def test_func_00179190_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00179190."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00179290_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00179290 (244 bytes / 61 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF290_OFFSET:FF290_OFFSET + FF290_SIZE],
        read_original(original_image, FF290_OFFSET, FF290_SIZE),
        START_ADDRESS + FF290_OFFSET,
    )


def test_func_00179290_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00179290."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
