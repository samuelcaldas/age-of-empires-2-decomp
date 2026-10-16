"""Compile and compare the trade action stream decoders30."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders30_support")

from trade_action_stream_decoders30_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F6630_OFFSET, F6630_SIZE, F6820_OFFSET, F6820_SIZE,
    F6A70_OFFSET, F6A70_SIZE, F6D00_OFFSET, F6D00_SIZE, FILE_OFFSET,
    PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE, SLICE_SIZE,
    START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders30_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 2,528 compiler code bytes plus 16 linker/slice-alignment bytes = 2,544B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00166630_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00166630 (496 bytes / 124 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F6630_OFFSET:F6630_OFFSET + F6630_SIZE],
        read_original(original_image, F6630_OFFSET, F6630_SIZE),
        START_ADDRESS + F6630_OFFSET,
    )


def test_func_00166820_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00166820 (580 bytes / 145 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F6820_OFFSET:F6820_OFFSET + F6820_SIZE],
        read_original(original_image, F6820_OFFSET, F6820_SIZE),
        START_ADDRESS + F6820_OFFSET,
    )


def test_func_00166820_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00166820."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00166A70_near_matching(decoder_code, original_image):
    """Verify func_00166A70 162/163 instructions (648/652B) with identical store target."""
    actual = decoder_code[F6A70_OFFSET:F6A70_OFFSET + F6A70_SIZE]
    expected = read_original(original_image, F6A70_OFFSET, F6A70_SIZE)
    assert len(actual) == len(expected) == F6A70_SIZE
    assert sum(a == b for a, b in zip(actual, expected)) == 648
    exp_word = struct.unpack_from("<I", expected, 0x14)[0]
    act_word = struct.unpack_from("<I", actual, 0x14)[0]
    assert (exp_word, act_word) == (0xA0620000, 0xA38285E0)
    assert ((exp_word >> 21) & 0x1F, (act_word >> 21) & 0x1F) == (3, 28)
    orig_base = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", expected, 0x0C)[0]
    orig_target = orig_base + struct.unpack_from("<h", expected, 0x14)[0]
    actual_target = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", actual, 0x14)[0]
    assert orig_target == actual_target == EXTERNAL_SYMBOLS["D_004E2DA0"]


def test_func_00166A70_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00166A70."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00166D00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00166D00 (800 bytes / 200 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F6D00_OFFSET:F6D00_OFFSET + F6D00_SIZE],
        read_original(original_image, F6D00_OFFSET, F6D00_SIZE),
        START_ADDRESS + F6D00_OFFSET,
    )
