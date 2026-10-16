"""Compile and compare the trade action stream decoders17."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders17_support")

from trade_action_stream_decoders17_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F0B70_OFFSET, F0B70_SIZE, F0D40_OFFSET, F0D40_SIZE,
    F0F10_OFFSET, F0F10_SIZE, F1040_OFFSET, F1040_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE, START_ADDRESS, assert_same_code,
    original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders17_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,576 compiler code bytes plus 24 linker/slice-alignment bytes = 1,600B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00160B70_near_matching(decoder_code, original_image):
    """Verify func_00160B70 113/114 instructions (453/456B) with identical store target."""
    actual = decoder_code[F0B70_OFFSET:F0B70_OFFSET + F0B70_SIZE]
    expected = read_original(original_image, F0B70_OFFSET, F0B70_SIZE)
    assert len(actual) == len(expected) == F0B70_SIZE
    original_base = struct.unpack_from("<I", expected, 0x0C)[0]
    actual_base = struct.unpack_from("<I", actual, 0x0C)[0]
    original_target = (
        EXTERNAL_SYMBOLS["_gp"]
        + struct.unpack_from("<h", expected, 0x0C)[0]
        + struct.unpack_from("<h", expected, 0x14)[0]
    )
    actual_target = (
        EXTERNAL_SYMBOLS["_gp"]
        + struct.unpack_from("<h", actual, 0x0C)[0]
        + struct.unpack_from("<h", actual, 0x14)[0]
    )
    assert original_base == actual_base == 0x278485E0
    assert original_target == actual_target == EXTERNAL_SYMBOLS["D_004E2DA0"]
    assert sum(a == b for a, b in zip(actual, expected)) == 453
    assert (struct.unpack_from("<I", expected, 0x14)[0],
            struct.unpack_from("<I", actual, 0x14)[0]) == (0xA0820000, 0xA38285E0)


def test_func_00160B70_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00160B70."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00160D40_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00160D40 (456 bytes / 114 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F0D40_OFFSET:F0D40_OFFSET + F0D40_SIZE],
        read_original(original_image, F0D40_OFFSET, F0D40_SIZE),
        START_ADDRESS + F0D40_OFFSET,
    )


def test_func_00160D40_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00160D40."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00160F10_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00160F10 (300 bytes / 75 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F0F10_OFFSET:F0F10_OFFSET + F0F10_SIZE],
        read_original(original_image, F0F10_OFFSET, F0F10_SIZE),
        START_ADDRESS + F0F10_OFFSET,
    )


def test_func_00160F10_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00160F10."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00161040_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00161040 (364 bytes / 91 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F1040_OFFSET:F1040_OFFSET + F1040_SIZE],
        read_original(original_image, F1040_OFFSET, F1040_SIZE),
        START_ADDRESS + F1040_OFFSET,
    )


def test_func_00161040_tail_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00161040."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
