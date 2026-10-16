"""Compile and compare the trade action stream decoders21."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders21_support")

from trade_action_stream_decoders21_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F2A40_OFFSET, F2A40_SIZE, F2CF0_OFFSET, F2CF0_SIZE,
    FILE_OFFSET, PAD1_OFFSET, PAD1_SIZE, SLICE_SIZE, START_ADDRESS,
    assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders21_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,500 compiler code bytes plus 4 linker/slice-alignment bytes = 1,504B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00162A40_near_matching(decoder_code, original_image):
    """Verify func_00162A40 170/171 instructions (680/684B) with identical store target."""
    actual = decoder_code[F2A40_OFFSET:F2A40_OFFSET + F2A40_SIZE]
    expected = read_original(original_image, F2A40_OFFSET, F2A40_SIZE)
    assert len(actual) == len(expected) == F2A40_SIZE
    assert sum(a == b for a, b in zip(actual, expected)) == 680
    assert (struct.unpack_from("<I", expected, 0x14)[0],
            struct.unpack_from("<I", actual, 0x14)[0]) == (0xA0620000, 0xA38285E0)
    orig_target = (EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", expected, 0x0C)[0]
                   + struct.unpack_from("<h", expected, 0x14)[0])
    actual_target = EXTERNAL_SYMBOLS["_gp"] + struct.unpack_from("<h", actual, 0x14)[0]
    assert orig_target == actual_target == EXTERNAL_SYMBOLS["D_004E2DA0"]


def test_func_00162A40_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_00162A40."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00162CF0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00162CF0 (816 bytes / 204 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F2CF0_OFFSET:F2CF0_OFFSET + F2CF0_SIZE],
        read_original(original_image, F2CF0_OFFSET, F2CF0_SIZE),
        START_ADDRESS + F2CF0_OFFSET,
    )
