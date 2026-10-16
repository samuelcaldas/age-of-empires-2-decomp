"""Compile and compare the trade action stream decoders60."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders60_support")

from trade_action_stream_decoders60_support import (  # noqa: E402
    FECC0_OFFSET, FECC0_SIZE, FEDA0_OFFSET, FEDA0_SIZE,
    FEE80_OFFSET, FEE80_SIZE, FEF60_OFFSET, FEF60_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders60_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 880 compiler code bytes plus 16 linker/slice-alignment bytes = 896B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016ECC0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016ECC0 (216 bytes / 54 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FECC0_OFFSET:FECC0_OFFSET + FECC0_SIZE],
        read_original(original_image, FECC0_OFFSET, FECC0_SIZE),
        START_ADDRESS + FECC0_OFFSET,
    )


def test_func_0016ECC0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016ECC0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016EDA0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016EDA0 (216 bytes / 54 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FEDA0_OFFSET:FEDA0_OFFSET + FEDA0_SIZE],
        read_original(original_image, FEDA0_OFFSET, FEDA0_SIZE),
        START_ADDRESS + FEDA0_OFFSET,
    )


def test_func_0016EDA0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016EDA0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016EE80_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016EE80 (224 bytes / 56 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FEE80_OFFSET:FEE80_OFFSET + FEE80_SIZE],
        read_original(original_image, FEE80_OFFSET, FEE80_SIZE),
        START_ADDRESS + FEE80_OFFSET,
    )


def test_func_0016EF60_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016EF60 (224 bytes / 56 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FEF60_OFFSET:FEF60_OFFSET + FEF60_SIZE],
        read_original(original_image, FEF60_OFFSET, FEF60_SIZE),
        START_ADDRESS + FEF60_OFFSET,
    )
