"""Compile and compare the trade action stream decoders31."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders31_support")

from trade_action_stream_decoders31_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F7020_OFFSET, F7020_SIZE, F72D0_OFFSET, F72D0_SIZE,
    F75E0_OFFSET, F75E0_SIZE, F7930_OFFSET, F7930_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders31_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 3,296 compiler code bytes plus 16 linker/slice-alignment bytes = 3,312B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00167020_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00167020 (688 bytes / 172 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F7020_OFFSET:F7020_OFFSET + F7020_SIZE],
        read_original(original_image, F7020_OFFSET, F7020_SIZE),
        START_ADDRESS + F7020_OFFSET,
    )


def test_func_001672D0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001672D0 (772 bytes / 193 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F72D0_OFFSET:F72D0_OFFSET + F72D0_SIZE],
        read_original(original_image, F72D0_OFFSET, F72D0_SIZE),
        START_ADDRESS + F72D0_OFFSET,
    )


def test_func_001672D0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001672D0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_001675E0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001675E0 (844 bytes / 211 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F75E0_OFFSET:F75E0_OFFSET + F75E0_SIZE],
        read_original(original_image, F75E0_OFFSET, F75E0_SIZE),
        START_ADDRESS + F75E0_OFFSET,
    )


def test_func_001675E0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001675E0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00167930_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00167930 (992 bytes / 248 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F7930_OFFSET:F7930_OFFSET + F7930_SIZE],
        read_original(original_image, F7930_OFFSET, F7930_SIZE),
        START_ADDRESS + F7930_OFFSET,
    )
