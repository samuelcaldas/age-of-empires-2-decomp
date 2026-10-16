"""Compile and compare the trade action stream decoders96."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders96_support")

from trade_action_stream_decoders96_support import (  # noqa: E402
    FF010_OFFSET, FF010_SIZE, FF2A0_OFFSET, FF2A0_SIZE,
    FFC20_OFFSET, FFC20_SIZE, FFDF0_OFFSET, FFDF0_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders96_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 2140 compiler code bytes plus 20 linker/slice-alignment bytes = 2160B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00177C20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00177C20 (464 bytes / 116 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFC20_OFFSET:FFC20_OFFSET + FFC20_SIZE],
        read_original(original_image, FFC20_OFFSET, FFC20_SIZE),
        START_ADDRESS + FFC20_OFFSET,
    )


def test_func_00177DF0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00177DF0 (536 bytes / 134 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FFDF0_OFFSET:FFDF0_OFFSET + FFDF0_SIZE],
        read_original(original_image, FFDF0_OFFSET, FFDF0_SIZE),
        START_ADDRESS + FFDF0_OFFSET,
    )


def test_func_00177DF0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00177DF0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00178010_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00178010 (644 bytes / 161 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF010_OFFSET:FF010_OFFSET + FF010_SIZE],
        read_original(original_image, FF010_OFFSET, FF010_SIZE),
        START_ADDRESS + FF010_OFFSET,
    )


def test_func_00178010_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00178010."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_001782A0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001782A0 (496 bytes / 124 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF2A0_OFFSET:FF2A0_OFFSET + FF2A0_SIZE],
        read_original(original_image, FF2A0_OFFSET, FF2A0_SIZE),
        START_ADDRESS + FF2A0_OFFSET,
    )
