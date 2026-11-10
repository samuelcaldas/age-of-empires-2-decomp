"""Compare compiled stream decoders14 with relocated original PS2 code."""

import struct

import pytest

pytest.register_assert_rewrite("trade_action_stream_decoders14_support")

import trade_action_stream_decoders14_support as support  # noqa: E402


@pytest.fixture(scope="module")
def original_image():
    return support.original_image.__wrapped__()


@pytest.fixture(scope="module")
def decoder_code(tmp_path_factory, original_image):
    return support.decoder_code.__wrapped__(tmp_path_factory, original_image)


def test_vram_mapping_matches_pt_load(original_image):
    file_offset, virtual_address, file_size = support.original_load_mapping(original_image)
    assert file_offset + support.START_ADDRESS - virtual_address == support.FILE_OFFSET
    assert support.FILE_OFFSET + support.SLICE_SIZE <= file_offset + file_size


def test_slice_total_extent(decoder_code):
    """Verify 1,304 compiler code bytes plus 24 linker/slice-alignment bytes = 1,328B."""
    assert len(decoder_code) == support.SLICE_SIZE


def test_func_0015F840_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0015F840 (248 bytes, 100% exact)."""
    actual = decoder_code[support.F840_OFFSET:support.F840_OFFSET + support.F840_SIZE]
    expected = support.read_original(original_image, support.F840_OFFSET, support.F840_SIZE)
    support.assert_same_code(actual, expected, support.START_ADDRESS + support.F840_OFFSET)


def test_func_0015F840_alignment_padding(decoder_code, original_image):
    """Require exact 8-byte zero padding after func_0015F840."""
    actual_pad = decoder_code[support.PAD1_OFFSET:support.PAD1_OFFSET + support.PAD1_SIZE]
    expected_pad = support.read_original(original_image, support.PAD1_OFFSET, support.PAD1_SIZE)
    support.assert_same_code(actual_pad, expected_pad, support.START_ADDRESS + support.PAD1_OFFSET)


def test_func_0015F940_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0015F940 (324 bytes / 81 instrs, 100% exact)."""
    support.assert_same_code(
        decoder_code[support.F940_OFFSET:support.F940_OFFSET + support.F940_SIZE],
        support.read_original(original_image, support.F940_OFFSET, support.F940_SIZE),
        support.START_ADDRESS + support.F940_OFFSET,
    )


def test_func_0015F940_alignment_padding(decoder_code, original_image):
    """Require exact 12-byte zero padding after func_0015F940."""
    actual_pad = decoder_code[support.PAD2_OFFSET:support.PAD2_OFFSET + support.PAD2_SIZE]
    expected_pad = support.read_original(original_image, support.PAD2_OFFSET, support.PAD2_SIZE)
    support.assert_same_code(actual_pad, expected_pad, support.START_ADDRESS + support.PAD2_OFFSET)


def test_func_0015FA90_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0015FA90 (336 bytes / 84 instrs, 100% exact)."""
    support.assert_same_code(
        decoder_code[support.FA90_OFFSET:support.FA90_OFFSET + support.FA90_SIZE],
        support.read_original(original_image, support.FA90_OFFSET, support.FA90_SIZE),
        support.START_ADDRESS + support.FA90_OFFSET,
    )


def test_func_0015FBE0_exact_bytes(decoder_code, original_image):
    """Require exact instructions for func_0015FBE0 (396 bytes / 99 instrs, 100% exact)."""
    support.assert_same_code(
        decoder_code[support.FBE0_OFFSET:support.FBE0_OFFSET + support.FBE0_SIZE],
        support.read_original(original_image, support.FBE0_OFFSET, support.FBE0_SIZE),
        support.START_ADDRESS + support.FBE0_OFFSET,
    )


def test_func_0015FBE0_tail_alignment_padding(decoder_code, original_image):
    """Require exact 4-byte zero padding after func_0015FBE0."""
    actual_pad = decoder_code[support.PAD4_OFFSET:support.PAD4_OFFSET + support.PAD4_SIZE]
    expected_pad = support.read_original(original_image, support.PAD4_OFFSET, support.PAD4_SIZE)
    support.assert_same_code(actual_pad, expected_pad, support.START_ADDRESS + support.PAD4_OFFSET)
