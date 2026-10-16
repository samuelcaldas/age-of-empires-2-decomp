"""Compile and compare the trade action stream decoders59."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders59_support")

from trade_action_stream_decoders59_support import (  # noqa: E402
    FEA50_OFFSET, FEA50_SIZE, FEAE0_OFFSET, FEAE0_SIZE,
    FEB80_OFFSET, FEB80_SIZE, FEC20_OFFSET, FEC20_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders59_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 596 compiler code bytes plus 28 linker/slice-alignment bytes = 624B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016EA50_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016EA50 (140 bytes / 35 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FEA50_OFFSET:FEA50_OFFSET + FEA50_SIZE],
        read_original(original_image, FEA50_OFFSET, FEA50_SIZE),
        START_ADDRESS + FEA50_OFFSET,
    )


def test_func_0016EA50_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016EA50."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016EAE0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016EAE0 (156 bytes / 39 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FEAE0_OFFSET:FEAE0_OFFSET + FEAE0_SIZE],
        read_original(original_image, FEAE0_OFFSET, FEAE0_SIZE),
        START_ADDRESS + FEAE0_OFFSET,
    )


def test_func_0016EAE0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016EAE0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016EB80_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016EB80 (148 bytes / 37 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FEB80_OFFSET:FEB80_OFFSET + FEB80_SIZE],
        read_original(original_image, FEB80_OFFSET, FEB80_SIZE),
        START_ADDRESS + FEB80_OFFSET,
    )


def test_func_0016EB80_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016EB80."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016EC20_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016EC20 (152 bytes / 38 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FEC20_OFFSET:FEC20_OFFSET + FEC20_SIZE],
        read_original(original_image, FEC20_OFFSET, FEC20_SIZE),
        START_ADDRESS + FEC20_OFFSET,
    )


def test_func_0016EC20_tail_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016EC20."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
