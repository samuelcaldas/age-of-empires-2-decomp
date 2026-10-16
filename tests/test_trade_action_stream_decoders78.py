"""Compile and compare the trade action stream decoders78."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders78_support")

from trade_action_stream_decoders78_support import (  # noqa: E402
    FF670_OFFSET, FF670_SIZE, FF690_OFFSET, FF690_SIZE,
    FF6D0_OFFSET, FF6D0_SIZE, FF710_OFFSET, FF710_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders78_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 184 compiler code bytes plus 40 linker/slice-alignment bytes = 224B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00173670_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173670 (28 bytes / 7 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF670_OFFSET:FF670_OFFSET + FF670_SIZE],
        read_original(original_image, FF670_OFFSET, FF670_SIZE),
        START_ADDRESS + FF670_OFFSET,
    )


def test_func_00173670_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00173670."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00173690_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173690 (52 bytes / 13 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF690_OFFSET:FF690_OFFSET + FF690_SIZE],
        read_original(original_image, FF690_OFFSET, FF690_SIZE),
        START_ADDRESS + FF690_OFFSET,
    )


def test_func_00173690_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00173690."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_001736D0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001736D0 (52 bytes / 13 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF6D0_OFFSET:FF6D0_OFFSET + FF6D0_SIZE],
        read_original(original_image, FF6D0_OFFSET, FF6D0_SIZE),
        START_ADDRESS + FF6D0_OFFSET,
    )


def test_func_001736D0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001736D0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00173710_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00173710 (52 bytes / 13 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FF710_OFFSET:FF710_OFFSET + FF710_SIZE],
        read_original(original_image, FF710_OFFSET, FF710_SIZE),
        START_ADDRESS + FF710_OFFSET,
    )


def test_func_00173710_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00173710."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
