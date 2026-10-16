"""Compile and compare the trade action stream decoders16."""

import struct
import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders16_support")

from trade_action_stream_decoders16_support import (  # noqa: E402
    EXTERNAL_SYMBOLS, F0400_OFFSET, F0400_SIZE, F05A0_OFFSET, F05A0_SIZE,
    F0730_OFFSET, F0730_SIZE, F0950_OFFSET, F0950_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE, PAD2_OFFSET, PAD2_SIZE, PAD3_OFFSET, PAD3_SIZE,
    PAD4_OFFSET, PAD4_SIZE, SLICE_SIZE, START_ADDRESS, assert_same_code,
    original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders16_support",)


def effective_store_target(code):
    """Resolve the destination used by the store's actual base register."""
    instruction = struct.unpack_from("<I", code, 0x14)[0]
    base_register = (instruction >> 21) & 0x1F
    store_offset = struct.unpack_from("<h", code, 0x14)[0]
    gp_address = EXTERNAL_SYMBOLS["_gp"]
    if base_register == 28:
        return gp_address + store_offset
    base_instruction = struct.unpack_from("<I", code, 0x0C)[0]
    opcode = base_instruction >> 26
    source_register = (base_instruction >> 21) & 0x1F
    destination_register = (base_instruction >> 16) & 0x1F
    assert opcode == 9 and source_register == 28
    assert destination_register == base_register
    base_offset = struct.unpack_from("<h", code, 0x0C)[0]
    return gp_address + base_offset + store_offset


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,860 compiler code bytes plus 44 linker/slice-alignment bytes = 1,904B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_00160400_near_matching(decoder_code, original_image):
    """Verify func_00160400 100/101 instructions (401/404B) with identical store target."""
    actual = decoder_code[F0400_OFFSET:F0400_OFFSET + F0400_SIZE]
    expected = read_original(original_image, F0400_OFFSET, F0400_SIZE)
    assert len(actual) == len(expected) == F0400_SIZE
    original_base = struct.unpack_from("<I", expected, 0x0C)[0]
    actual_base = struct.unpack_from("<I", actual, 0x0C)[0]
    original_target = effective_store_target(expected)
    actual_target = effective_store_target(actual)
    assert original_target == actual_target == EXTERNAL_SYMBOLS["D_004E2DA0"]
    assert original_base == actual_base == 0x278485E0
    assert sum(a == b for a, b in zip(actual, expected)) == 401
    assert (struct.unpack_from("<I", expected, 0x14)[0],
            struct.unpack_from("<I", actual, 0x14)[0]) == (0xA0820000, 0xA38285E0)


def test_func_00160400_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00160400."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_001605A0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_001605A0 (388 bytes / 97 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F05A0_OFFSET:F05A0_OFFSET + F05A0_SIZE],
        read_original(original_image, F05A0_OFFSET, F05A0_SIZE),
        START_ADDRESS + F05A0_OFFSET,
    )


def test_func_001605A0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_001605A0."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(original_image, PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)


def test_func_00160730_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00160730 (532 bytes / 133 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F0730_OFFSET:F0730_OFFSET + F0730_SIZE],
        read_original(original_image, F0730_OFFSET, F0730_SIZE),
        START_ADDRESS + F0730_OFFSET,
    )


def test_func_00160730_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_00160730."""
    actual_pad = decoder_code[PAD3_OFFSET:PAD3_OFFSET + PAD3_SIZE]
    expected_pad = read_original(original_image, PAD3_OFFSET, PAD3_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD3_OFFSET)


def test_func_00160950_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_00160950 (536 bytes / 134 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[F0950_OFFSET:F0950_OFFSET + F0950_SIZE],
        read_original(original_image, F0950_OFFSET, F0950_SIZE),
        START_ADDRESS + F0950_OFFSET,
    )


def test_func_00160950_tail_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_00160950."""
    actual_pad = decoder_code[PAD4_OFFSET:PAD4_OFFSET + PAD4_SIZE]
    expected_pad = read_original(original_image, PAD4_OFFSET, PAD4_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD4_OFFSET)
