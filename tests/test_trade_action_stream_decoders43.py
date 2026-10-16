"""Compile and compare the trade action stream decoders43."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders43_support")

from trade_action_stream_decoders43_support import (  # noqa: E402
    FA1C0_OFFSET, FA1C0_SIZE, FA2B0_OFFSET, FA2B0_SIZE,
    FA3B0_OFFSET, FA3B0_SIZE, FA4C0_OFFSET, FA4C0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE,
    PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders43_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,016 compiler code bytes plus 24 linker/slice-alignment bytes = 1,040B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0016A1C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016A1C0 (228 bytes / 57 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FA1C0_OFFSET:FA1C0_OFFSET + FA1C0_SIZE],
        read_original(original_image, FA1C0_OFFSET, FA1C0_SIZE),
        START_ADDRESS + FA1C0_OFFSET,
    )


def test_func_0016A1C0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0016A1C0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0016A2B0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016A2B0 (248 bytes / 62 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FA2B0_OFFSET:FA2B0_OFFSET + FA2B0_SIZE],
        read_original(original_image, FA2B0_OFFSET, FA2B0_SIZE),
        START_ADDRESS + FA2B0_OFFSET,
    )


def test_func_0016A2B0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0016A2B0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0016A3B0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016A3B0 (268 bytes / 67 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FA3B0_OFFSET:FA3B0_OFFSET + FA3B0_SIZE],
        read_original(original_image, FA3B0_OFFSET, FA3B0_SIZE),
        START_ADDRESS + FA3B0_OFFSET,
    )


def test_func_0016A3B0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0016A3B0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0016A4C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0016A4C0 (272 bytes / 68 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FA4C0_OFFSET:FA4C0_OFFSET + FA4C0_SIZE],
        read_original(original_image, FA4C0_OFFSET, FA4C0_SIZE),
        START_ADDRESS + FA4C0_OFFSET,
    )
