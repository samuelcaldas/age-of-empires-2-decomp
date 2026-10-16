"""Compile and compare the trade action stream decoders64."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders64_support")

from trade_action_stream_decoders64_support import (  # noqa: E402
    FFEE0_OFFSET, FFEE0_SIZE, FF090_OFFSET, FF090_SIZE,
    FF230_OFFSET, FF230_SIZE, FF320_OFFSET, FF320_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders64_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1404 compiler code bytes plus 20 linker/slice-alignment bytes = 1424B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016FEE0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016FEE0 (420 bytes / 105 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFEE0_OFFSET:FFEE0_OFFSET + FFEE0_SIZE],
        read_original(original_image, FFEE0_OFFSET, FFEE0_SIZE),
        START_ADDRESS + FFEE0_OFFSET,
    )


def test_func_0016FEE0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016FEE0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00170090_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00170090 (416 bytes / 104 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF090_OFFSET:FF090_OFFSET + FF090_SIZE],
        read_original(original_image, FF090_OFFSET, FF090_SIZE),
        START_ADDRESS + FF090_OFFSET,
    )


def test_func_00170230_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00170230 (240 bytes / 60 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF230_OFFSET:FF230_OFFSET + FF230_SIZE],
        read_original(original_image, FF230_OFFSET, FF230_SIZE),
        START_ADDRESS + FF230_OFFSET,
    )


def test_func_00170320_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00170320 (328 bytes / 82 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF320_OFFSET:FF320_OFFSET + FF320_SIZE],
        read_original(original_image, FF320_OFFSET, FF320_SIZE),
        START_ADDRESS + FF320_OFFSET,
    )


def test_func_00170320_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00170320."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
