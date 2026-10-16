"""Compile and compare the trade action stream decoders20."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders20_support")

from trade_action_stream_decoders20_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F20C0_OFFSET, F20C0_SIZE, F22F0_OFFSET, F22F0_SIZE,
    F25A0_OFFSET, F25A0_SIZE, F27D0_OFFSET, F27D0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders20_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 2,416 compiler code bytes plus 16 linker/slice-alignment bytes = 2,432B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_001620C0_near_matching(decoder_code, original_image):
    """Verify func_001620C0 138/139 instructions (552/556B) with identical store target."""
    actual = decoder_code[F20C0_OFFSET:F20C0_OFFSET + F20C0_SIZE]
    expected = read_original(original_image, F20C0_OFFSET, F20C0_SIZE)
    assert len(actual) == len(expected) == F20C0_SIZE
    assert sum(a == b for a, b in zip(actual, expected)) == 552
    assert (struct.unpack_from("<I", expected, 0x14)[0],
            struct.unpack_from("<I", actual, 0x14)[0]) == (0xA0620000, 0xA38285E0)
    orig_target = (EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", expected, 0x0C)[0]
                   + struct.unpack_from("<h", expected, 0x14)[0])
    actual_target = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", actual, 0x14)[0]
    assert orig_target == actual_target == EXTERNAL_SYMBOLS["D_004E2DA0"]


def test_func_001620C0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001620C0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_001622F0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001622F0 (688 bytes / 172 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F22F0_OFFSET:F22F0_OFFSET + F22F0_SIZE],
        read_original(original_image, F22F0_OFFSET, F22F0_SIZE),
        START_ADDRESS + F22F0_OFFSET,
    )


def test_func_001625A0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001625A0 (560 bytes / 140 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F25A0_OFFSET:F25A0_OFFSET + F25A0_SIZE],
        read_original(original_image, F25A0_OFFSET, F25A0_SIZE),
        START_ADDRESS + F25A0_OFFSET,
    )


def test_func_001627D0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001627D0 (612 bytes / 153 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F27D0_OFFSET:F27D0_OFFSET + F27D0_SIZE],
        read_original(original_image, F27D0_OFFSET, F27D0_SIZE),
        START_ADDRESS + F27D0_OFFSET,
    )


def test_func_001627D0_tail_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001627D0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
