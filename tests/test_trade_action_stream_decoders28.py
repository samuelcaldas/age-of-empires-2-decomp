"""Compile and compare the trade action stream decoders28."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders28_support")

from trade_action_stream_decoders28_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F55C0_OFFSET, F55C0_SIZE, F5710_OFFSET, F5710_SIZE,
    F58C0_OFFSET, F58C0_SIZE, F5AC0_OFFSET, F5AC0_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE, START_ADDRESS, assert_same_code,
    original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders28_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,908 compiler code bytes plus 28 linker/slice-alignment bytes = 1,936B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_001655C0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001655C0 (332 bytes / 83 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F55C0_OFFSET:F55C0_OFFSET + F55C0_SIZE],
        read_original(original_image, F55C0_OFFSET, F55C0_SIZE),
        START_ADDRESS + F55C0_OFFSET,
    )


def test_func_001655C0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001655C0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00165710_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00165710 (428 bytes / 107 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F5710_OFFSET:F5710_OFFSET + F5710_SIZE],
        read_original(original_image, F5710_OFFSET, F5710_SIZE),
        START_ADDRESS + F5710_OFFSET,
    )


def test_func_00165710_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00165710."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_001658C0_near_matching(decoder_code, original_image):
    """Verify func_001658C0 124/125 instructions (496/500B) with identical store target."""
    actual = decoder_code[F58C0_OFFSET:F58C0_OFFSET + F58C0_SIZE]
    expected = read_original(original_image, F58C0_OFFSET, F58C0_SIZE)
    assert len(actual) == len(expected) == F58C0_SIZE
    assert sum(a == b for a, b in zip(actual, expected)) == 496
    exp_word = struct.unpack_from("<I", expected, 0x14)[0]
    act_word = struct.unpack_from("<I", actual, 0x14)[0]
    assert (exp_word, act_word) == (0xA0620000, 0xA38285E0)
    assert ((exp_word >> 21) & 0x1F, (act_word >> 21) & 0x1F) == (3, 28)
    orig_base = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", expected, 0x0C)[0]
    orig_target = orig_base + struct.unpack_from("<h", expected, 0x14)[0]
    actual_target = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", actual, 0x14)[0]
    assert orig_target == actual_target == EXTERNAL_SYMBOLS["D_004E2DA0"]


def test_func_001658C0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001658C0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00165AC0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00165AC0 (648 bytes / 162 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F5AC0_OFFSET:F5AC0_OFFSET + F5AC0_SIZE],
        read_original(original_image, F5AC0_OFFSET, F5AC0_SIZE),
        START_ADDRESS + F5AC0_OFFSET,
    )


def test_func_00165AC0_tail_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00165AC0."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
