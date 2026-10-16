"""Compile and compare the trade action stream decoders112."""

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders112_support")

from trade_action_stream_decoders112_support import (  # noqa: E402
    FCBA0_OFFSET, FCBA0_SIZE, FCF00_OFFSET, FCF00_SIZE, FILE_OFFSET,
    PAD1_OFFSET, PAD1_SIZE,
    SLICE_SIZE, START_ADDRESS, assert_same_code, original_load_mapping, read_original,
)

pytest_plugins = ("trade_action_stream_decoders112_support",)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = original_load_mapping(original_image)
    assert file_offset + START_ADDRESS - virtual_address == FILE_OFFSET
    assert FILE_OFFSET + SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1524 compiler code bytes plus 12 linker/slice-alignment bytes = 1536B."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0017cba0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017cba0 (852 bytes / 213 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FCBA0_OFFSET:FCBA0_OFFSET + FCBA0_SIZE],
        read_original(original_image, FCBA0_OFFSET, FCBA0_SIZE),
        START_ADDRESS + FCBA0_OFFSET,
    )


def test_func_0017cba0_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0017cba0."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(original_image, PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0017cf00_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0017cf00 (672 bytes / 168 instrs, 100% exact)."""
    assert_same_code(
        decoder_code[FCF00_OFFSET:FCF00_OFFSET + FCF00_SIZE],
        read_original(original_image, FCF00_OFFSET, FCF00_SIZE),
        START_ADDRESS + FCF00_OFFSET,
    )
