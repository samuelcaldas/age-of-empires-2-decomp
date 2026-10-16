"""Compile and compare the trade action stream decoders61."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders61_support")

from trade_action_stream_decoders61_support import (  # noqa: E402
    FF040_OFFSET, FF040_SIZE, FF150_OFFSET, FF150_SIZE,
    FF240_OFFSET, FF240_SIZE, FF370_OFFSET, FF370_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders61_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1056 compiler code bytes plus 32 linker/slice-alignment bytes = 1088B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016F040_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016F040 (260 bytes / 65 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF040_OFFSET:FF040_OFFSET + FF040_SIZE],
        read_original(original_image, FF040_OFFSET, FF040_SIZE),
        START_ADDRESS + FF040_OFFSET,
    )


def test_func_0016F040_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016F040."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016F150_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016F150 (228 bytes / 57 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF150_OFFSET:FF150_OFFSET + FF150_SIZE],
        read_original(original_image, FF150_OFFSET, FF150_SIZE),
        START_ADDRESS + FF150_OFFSET,
    )


def test_func_0016F150_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016F150."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016F240_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016F240 (300 bytes / 75 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF240_OFFSET:FF240_OFFSET + FF240_SIZE],
        read_original(original_image, FF240_OFFSET, FF240_SIZE),
        START_ADDRESS + FF240_OFFSET,
    )


def test_func_0016F240_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016F240."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016F370_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016F370 (268 bytes / 67 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF370_OFFSET:FF370_OFFSET + FF370_SIZE],
        read_original(original_image, FF370_OFFSET, FF370_SIZE),
        START_ADDRESS + FF370_OFFSET,
    )


def test_func_0016F370_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016F370."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
