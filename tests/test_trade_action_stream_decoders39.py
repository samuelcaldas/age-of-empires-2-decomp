"""Compile and compare the trade action stream decoders39."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders39_support")

from trade_action_stream_decoders39_support import (  # noqa: E402
    F94F0_OFFSET, F94F0_SIZE, F9600_OFFSET, F9600_SIZE,
    F9730_OFFSET, F9730_SIZE, F9880_OFFSET, F9880_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders39_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,264 compiler code bytes plus 16 linker/slice-alignment bytes = 1,280B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_001694F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001694F0 (264 bytes / 66 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F94F0_OFFSET:F94F0_OFFSET + F94F0_SIZE],
        read_original(original_image, F94F0_OFFSET, F94F0_SIZE),
        START_ADDRESS + F94F0_OFFSET,
    )


def test_func_001694F0_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_001694F0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00169600_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169600 (304 bytes / 76 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9600_OFFSET:F9600_OFFSET + F9600_SIZE],
        read_original(original_image, F9600_OFFSET, F9600_SIZE),
        START_ADDRESS + F9600_OFFSET,
    )


def test_func_00169730_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169730 (336 bytes / 84 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9730_OFFSET:F9730_OFFSET + F9730_SIZE],
        read_original(original_image, F9730_OFFSET, F9730_SIZE),
        START_ADDRESS + F9730_OFFSET,
    )


def test_func_00169880_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00169880 (360 bytes / 90 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F9880_OFFSET:F9880_OFFSET + F9880_SIZE],
        read_original(original_image, F9880_OFFSET, F9880_SIZE),
        START_ADDRESS + F9880_OFFSET,
    )


def test_func_00169880_tail_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00169880."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
