"""Compile and compare the trade action stream decoders13."""

import struct

import pytest

# Preserve assertion diagnostics before pytest loads the support module as a plugin.
pytest.register_assert_rewrite("trade_action_stream_decoders13_support")

from trade_action_stream_decoders13_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F450_OFFSET, F450_SIZE, F510_OFFSET, F510_SIZE,
    F5D0_OFFSET, F5D0_SIZE, F6F0_OFFSET, F6F0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE, START_ADDRESS, assert_same_code,
    original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders13_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 972 compiler code bytes plus 36 linker/slice-alignment bytes = 1,008B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0015F450_near_matching(decoder_code, original_image):
    """Verify func_0015F450 44/45 instructions (177/180B) with identical store target."""
    actual = decoder_code[F450_OFFSET:F450_OFFSET + F450_SIZE]
    expected = read_original(original_image, F450_OFFSET, F450_SIZE)
    assert len(actual) == len(expected) == F450_SIZE
    assert sum(a == b for a, b in zip(actual, expected)) == 177
    expected_store = struct.unpack_from("<I", expected, 0x0C)[0]
    actual_store = struct.unpack_from("<I", actual, 0x0C)[0]
    assert (expected_store, actual_store) == (0xA0830000, 0xA38385E0)
    actual_target = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", actual, 0x0C)[0]
    assert actual_target == EXTERNAL_SYMBOLS["D_004E2DA0"]


def test_func_0015F450_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0015F450."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0015F510_near_matching(decoder_code, original_image):
    """Verify func_0015F510 44/45 instructions (176/180B) with identical store target."""
    actual = decoder_code[F510_OFFSET:F510_OFFSET + F510_SIZE]
    expected = read_original(original_image, F510_OFFSET, F510_SIZE)
    assert len(actual) == len(expected) == F510_SIZE
    assert sum(a == b for a, b in zip(actual, expected)) == 176
    expected_store = struct.unpack_from("<I", expected, 0x40)[0]
    actual_store = struct.unpack_from("<I", actual, 0x40)[0]
    assert (expected_store, actual_store) == (0xA0A30000, 0xA38385E0)
    actual_target = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", actual, 0x40)[0]
    assert actual_target == EXTERNAL_SYMBOLS["D_004E2DA0"]


def test_func_0015F510_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0015F510."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_0015F5D0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0015F5D0 (284 bytes / 71 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F5D0_OFFSET:F5D0_OFFSET + F5D0_SIZE],
        read_original(original_image, F5D0_OFFSET, F5D0_SIZE),
        START_ADDRESS + F5D0_OFFSET,
    )


def test_func_0015F5D0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0015F5D0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_0015F6F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0015F6F0 (328 bytes / 82 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F6F0_OFFSET:F6F0_OFFSET + F6F0_SIZE],
        read_original(original_image, F6F0_OFFSET, F6F0_SIZE),
        START_ADDRESS + F6F0_OFFSET,
    )


def test_func_0015F6F0_tail_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0015F6F0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
