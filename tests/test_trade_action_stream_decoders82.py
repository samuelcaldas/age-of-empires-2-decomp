"""Compile and compare the trade action stream decoders82."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders82_support")

from trade_action_stream_decoders82_support import (  # noqa: E402
    FFCA0_OFFSET, FFCA0_SIZE, FFD50_OFFSET, FFD50_SIZE,
    FFDF0_OFFSET, FFDF0_SIZE, FFEA0_OFFSET, FFEA0_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders82_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 676 compiler code bytes plus 12 linker/slice-alignment bytes = 688B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00173CA0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173CA0 (176 bytes / 44 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFCA0_OFFSET:FFCA0_OFFSET + FFCA0_SIZE],
        read_original(original_image, FFCA0_OFFSET, FFCA0_SIZE),
        START_ADDRESS + FFCA0_OFFSET,
    )


def test_func_00173D50_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173D50 (148 bytes / 37 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFD50_OFFSET:FFD50_OFFSET + FFD50_SIZE],
        read_original(original_image, FFD50_OFFSET, FFD50_SIZE),
        START_ADDRESS + FFD50_OFFSET,
    )


def test_func_00173D50_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00173D50."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00173DF0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173DF0 (176 bytes / 44 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFDF0_OFFSET:FFDF0_OFFSET + FFDF0_SIZE],
        read_original(original_image, FFDF0_OFFSET, FFDF0_SIZE),
        START_ADDRESS + FFDF0_OFFSET,
    )


def test_func_00173EA0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173EA0 (176 bytes / 44 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFEA0_OFFSET:FFEA0_OFFSET + FFEA0_SIZE],
        read_original(original_image, FFEA0_OFFSET, FFEA0_SIZE),
        START_ADDRESS + FFEA0_OFFSET,
    )
