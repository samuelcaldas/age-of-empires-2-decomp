"""Compile and compare the trade action stream decoders18."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders18_support")

from trade_action_stream_decoders18_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F11B0_OFFSET, F11B0_SIZE, F1370_OFFSET, F1370_SIZE,
    F15B0_OFFSET, F15B0_SIZE, F1720_OFFSET, F1720_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping,
    read_original,
)

pytest_plugins = ("trade_action_stream_decoders18_support",)


def effective_store_target(code):
    """Resolve an sb destination using its actual base and target registers."""
    store_word = struct.unpack_from("<I", code, 0x14)[0]
    assert store_word >> 26 == 0x28
    target_register = (store_word >> 16) & 0x1F
    assert target_register == 2
    base_register = (store_word >> 21) & 0x1F
    store_offset = struct.unpack_from("<h", code, 0x14)[0]
    gp_address = EXTERNAL_SYMBOLS["_gp"]
    if base_register == 28:
        return gp_address + store_offset
    base_writes = []
    for offset in range(0, 0x14, 4):
        word = struct.unpack_from("<I", code, offset)[0]
        opcode = word >> 26
        source_register = (word >> 21) & 0x1F
        destination_register = (word >> 16) & 0x1F
        if opcode == 9 and source_register == 28 and destination_register == base_register:
            base_writes.append(struct.unpack_from("<h", code, offset)[0])
    assert len(base_writes) == 1
    return gp_address + base_writes[0] + store_offset


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,784 compiler code bytes plus 24 linker/slice-alignment bytes = 1,808B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_001611B0_near_matching(decoder_code, original_image):
    """Verify func_001611B0 108/109 instructions (432/436B) with identical store target."""
    actual = decoder_code[F11B0_OFFSET:F11B0_OFFSET + F11B0_SIZE]
    expected = read_original(original_image, F11B0_OFFSET, F11B0_SIZE)
    assert len(actual) == len(expected) == F11B0_SIZE
    assert effective_store_target(expected) == EXTERNAL_SYMBOLS["D_004E2DA0"]
    assert effective_store_target(actual) == EXTERNAL_SYMBOLS["D_004E2DA0"]
    assert struct.unpack_from("<I", expected, 0x0C)[0] == 0x278385E0
    assert struct.unpack_from("<I", actual, 0x14)[0] == 0xA38285E0
    assert sum(a == b for a, b in zip(actual, expected)) == 432
    assert sum(
        actual[offset:offset + 4] == expected[offset:offset + 4]
        for offset in range(0, F11B0_SIZE, 4)
    ) == 108


def test_func_001611B0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001611B0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_00161370_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00161370 (568 bytes / 142 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F1370_OFFSET:F1370_OFFSET + F1370_SIZE],
        read_original(original_image, F1370_OFFSET, F1370_SIZE),
        START_ADDRESS + F1370_OFFSET,
    )


def test_func_00161370_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00161370."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_001615B0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001615B0 (364 bytes / 91 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F15B0_OFFSET:F15B0_OFFSET + F15B0_SIZE],
        read_original(original_image, F15B0_OFFSET, F15B0_SIZE),
        START_ADDRESS + F15B0_OFFSET,
    )


def test_func_001615B0_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_001615B0."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00161720_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00161720 (416 bytes / 104 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F1720_OFFSET:F1720_OFFSET + F1720_SIZE],
        read_original(original_image, F1720_OFFSET, F1720_SIZE),
        START_ADDRESS + F1720_OFFSET,
    )
