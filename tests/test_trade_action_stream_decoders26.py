"""Compile and compare the trade action stream decoders26."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders26_support")

from trade_action_stream_decoders26_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F4400_OFFSET, F4400_SIZE, F45E0_OFFSET, F45E0_SIZE,
    F4880_OFFSET, F4880_SIZE, F4A60_OFFSET, F4A60_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE, START_ADDRESS, assert_same_code,
    original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders26_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 2,088 compiler code bytes plus 40 linker/slice-alignment bytes = 2,128B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00164400_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00164400 (468 bytes / 117 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F4400_OFFSET:F4400_OFFSET + F4400_SIZE],
        read_original(original_image, F4400_OFFSET, F4400_SIZE),
        START_ADDRESS + F4400_OFFSET,
    )


def test_func_00164400_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00164400."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_001645E0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001645E0 (668 bytes / 167 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F45E0_OFFSET:F45E0_OFFSET + F45E0_SIZE],
        read_original(original_image, F45E0_OFFSET, F45E0_SIZE),
        START_ADDRESS + F45E0_OFFSET,
    )


def test_func_001645E0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001645E0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00164880_near_matching(decoder_code, original_image):
    """Verify func_00164880 116/117 instructions (465/468B) with identical store target."""
    actual = decoder_code[F4880_OFFSET:F4880_OFFSET + F4880_SIZE]
    expected = read_original(original_image, F4880_OFFSET, F4880_SIZE)
    assert len(actual) == len(expected) == F4880_SIZE
    assert sum(a == b for a, b in zip(actual, expected)) == 465
    exp_word = struct.unpack_from("<I", expected, 0x14)[0]
    act_word = struct.unpack_from("<I", actual, 0x14)[0]
    assert (exp_word, act_word) == (0xA0820000, 0xA38285E0)
    assert ((exp_word >> 21) & 0x1F, (act_word >> 21) & 0x1F) == (4, 28)
    orig_base = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", expected, 0x0C)[0]
    orig_target = orig_base + struct.unpack_from("<h", expected, 0x14)[0]
    actual_target = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", actual, 0x14)[0]
    assert orig_target == actual_target == EXTERNAL_SYMBOLS["D_004E2DA0"]


def test_func_00164880_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00164880."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00164A60_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00164A60 (484 bytes / 121 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F4A60_OFFSET:F4A60_OFFSET + F4A60_SIZE],
        read_original(original_image, F4A60_OFFSET, F4A60_SIZE),
        START_ADDRESS + F4A60_OFFSET,
    )


def test_func_00164A60_tail_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00164A60."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
