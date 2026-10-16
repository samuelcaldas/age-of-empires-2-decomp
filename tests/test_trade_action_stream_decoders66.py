"""Compile and compare the trade action stream decoders66."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders66_support")

from trade_action_stream_decoders66_support import (  # noqa: E402
    FFA60_OFFSET, FFA60_SIZE, FFC20_OFFSET, FFC20_SIZE,
    FFDF0_OFFSET, FFDF0_SIZE, FFF60_OFFSET, FFF60_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders66_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1716 compiler code bytes plus 12 linker/slice-alignment bytes = 1728B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00170A60_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00170A60 (448 bytes / 112 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFA60_OFFSET:FFA60_OFFSET + FFA60_SIZE],
        read_original(original_image, FFA60_OFFSET, FFA60_SIZE),
        START_ADDRESS + FFA60_OFFSET,
    )


def test_func_00170C20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00170C20 (456 bytes / 114 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFC20_OFFSET:FFC20_OFFSET + FFC20_SIZE],
        read_original(original_image, FFC20_OFFSET, FFC20_SIZE),
        START_ADDRESS + FFC20_OFFSET,
    )


def test_func_00170C20_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00170C20."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00170DF0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00170DF0 (368 bytes / 92 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFDF0_OFFSET:FFDF0_OFFSET + FFDF0_SIZE],
        read_original(original_image, FFDF0_OFFSET, FFDF0_SIZE),
        START_ADDRESS + FFDF0_OFFSET,
    )


def test_func_00170F60_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00170F60 (444 bytes / 111 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFF60_OFFSET:FFF60_OFFSET + FFF60_SIZE],
        read_original(original_image, FFF60_OFFSET, FFF60_SIZE),
        START_ADDRESS + FFF60_OFFSET,
    )


def test_func_00170F60_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00170F60."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
