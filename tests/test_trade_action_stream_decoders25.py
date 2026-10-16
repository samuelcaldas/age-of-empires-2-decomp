"""Compile and compare the trade action stream decoders25."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders25_support")

from trade_action_stream_decoders25_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F3CF0_OFFSET, F3CF0_SIZE, F3E80_OFFSET, F3E80_SIZE,
    F4060_OFFSET, F4060_SIZE, F4270_OFFSET, F4270_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE, START_ADDRESS,
    assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders25_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,796 compiler code bytes plus 12 linker/slice-alignment bytes = 1,808B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00163CF0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00163CF0 (400 bytes / 100 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F3CF0_OFFSET:F3CF0_OFFSET + F3CF0_SIZE],
        read_original(original_image, F3CF0_OFFSET, F3CF0_SIZE),
        START_ADDRESS + F3CF0_OFFSET,
    )


def test_func_00163E80_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00163E80 (476 bytes / 119 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F3E80_OFFSET:F3E80_OFFSET + F3E80_SIZE],
        read_original(original_image, F3E80_OFFSET, F3E80_SIZE),
        START_ADDRESS + F3E80_OFFSET,
    )


def test_func_00163E80_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00163E80."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00164060_near_matching(decoder_code, original_image):
    """Verify func_00164060 129/130 instructions (517/520B) with identical store target."""
    actual = decoder_code[F4060_OFFSET:F4060_OFFSET + F4060_SIZE]
    expected = read_original(original_image, F4060_OFFSET, F4060_SIZE)
    assert len(actual) == len(expected) == F4060_SIZE
    assert sum(a == b for a, b in zip(actual, expected)) == 517
    exp_word = struct.unpack_from("<I", expected, 0x14)[0]
    act_word = struct.unpack_from("<I", actual, 0x14)[0]
    assert (exp_word, act_word) == (0xA0820000, 0xA38285E0)
    assert ((exp_word >> 21) & 0x1F, (act_word >> 21) & 0x1F) == (4, 28)
    orig_base = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", expected, 0x0C)[0]
    orig_target = orig_base + struct.unpack_from("<h", expected, 0x14)[0]
    actual_target = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", actual, 0x14)[0]
    assert orig_target == actual_target == EXTERNAL_SYMBOLS["D_004E2DA0"]


def test_func_00164060_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00164060."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00164270_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00164270 (400 bytes / 100 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F4270_OFFSET:F4270_OFFSET + F4270_SIZE],
        read_original(original_image, F4270_OFFSET, F4270_SIZE),
        START_ADDRESS + F4270_OFFSET,
    )
