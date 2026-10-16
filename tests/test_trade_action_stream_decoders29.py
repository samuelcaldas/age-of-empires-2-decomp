"""Compile and compare the trade action stream decoders29."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders29_support")

from trade_action_stream_decoders29_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F5D50_OFFSET, F5D50_SIZE, F5F00_OFFSET, F5F00_SIZE,
    F6100_OFFSET, F6100_SIZE, F6350_OFFSET, F6350_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD3_OFFSET, PAD3_SIZE, PAD4_OFFSET, PAD4_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping,
    read_original,
)

pytest_plugins = ("trade_action_stream_decoders29_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 2,256 compiler code bytes plus 16 linker/slice-alignment bytes = 2,272B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00165D50_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00165D50 (428 bytes / 107 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F5D50_OFFSET:F5D50_OFFSET + F5D50_SIZE],
        read_original(original_image, F5D50_OFFSET, F5D50_SIZE),
        START_ADDRESS + F5D50_OFFSET,
    )


def test_func_00165D50_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00165D50."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00165F00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00165F00 (512 bytes / 128 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F5F00_OFFSET:F5F00_OFFSET + F5F00_SIZE],
        read_original(original_image, F5F00_OFFSET, F5F00_SIZE),
        START_ADDRESS + F5F00_OFFSET,
    )


def test_func_00166100_near_matching(decoder_code, original_image):
    """Verify func_00166100 145/146 instructions (580/584B) with identical store target."""
    actual = decoder_code[F6100_OFFSET:F6100_OFFSET + F6100_SIZE]
    expected = read_original(original_image, F6100_OFFSET, F6100_SIZE)
    assert len(actual) == len(expected) == F6100_SIZE
    assert sum(a == b for a, b in zip(actual, expected)) == 580
    exp_word = struct.unpack_from("<I", expected, 0x14)[0]
    act_word = struct.unpack_from("<I", actual, 0x14)[0]
    assert (exp_word, act_word) == (0xA0620000, 0xA38285E0)
    assert ((exp_word >> 21) & 0x1F, (act_word >> 21) & 0x1F) == (3, 28)
    orig_base = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", expected, 0x0C)[0]
    orig_target = orig_base + struct.unpack_from("<h", expected, 0x14)[0]
    actual_target = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", actual, 0x14)[0]
    assert orig_target == actual_target == EXTERNAL_SYMBOLS["D_004E2DA0"]


def test_func_00166100_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00166100."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00166350_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00166350 (732 bytes / 183 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F6350_OFFSET:F6350_OFFSET + F6350_SIZE],
        read_original(original_image, F6350_OFFSET, F6350_SIZE),
        START_ADDRESS + F6350_OFFSET,
    )


def test_func_00166350_tail_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00166350."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
