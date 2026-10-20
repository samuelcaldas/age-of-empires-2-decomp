"""Verify resolved tactical-handler bytes and prove the gate rejects corrupted output."""

import struct
import subprocess

import pytest
from elftools.elf.elffile import ELFFile

from tactical_ai_func_342170_matching_support import (
    EXTERNAL_SYMBOLS, assert_matches_original, compile_handler, link_handler,
    original_ranges,
)


@pytest.fixture(scope="module")
def handler_object(tmp_path_factory):
    """Compile actual current C++ once, independently of canonical build outputs."""
    return compile_handler(tmp_path_factory.mktemp("tactical_handler_object"))


@pytest.fixture(scope="module")
def resolved_handler(handler_object, tmp_path_factory):
    """Resolve generated text and table using verified original symbol addresses."""
    return link_handler(handler_object, tmp_path_factory.mktemp("tactical_handler_link"))


@pytest.fixture(scope="module")
def expected_handler():
    """Read both original ranges from the SHA-1-verified ELF."""
    return original_ranges()


def test_func_342170_resolved_text_and_all_jump_table_bytes(resolved_handler, expected_handler):
    """Require equality for 1,584 text bytes and all 120 generated jump-table bytes."""
    assert_matches_original(resolved_handler, expected_handler)


def corrupt_table_entry(linked_path, output_path, entry):
    """Change one linked destination by four bytes without altering any text bytes."""
    with linked_path.open("rb") as stream:
        elf = ELFFile(stream)
        table = elf.get_section_by_name(".rodata")
        offset = table["sh_offset"] + entry * 4
    data = bytearray(linked_path.read_bytes())
    destination = struct.unpack_from("<I", data, offset)[0]
    struct.pack_into("<I", data, offset, destination + 4)
    output_path.write_bytes(data)


@pytest.mark.parametrize("entry", range(30))
def test_resolved_gate_rejects_each_corrupted_table_destination(
    resolved_handler, expected_handler, tmp_path, entry,
):
    """Require every individual jump-table destination to affect the exact gate."""
    corrupted_path = tmp_path / "corrupted_table.elf"
    corrupt_table_entry(resolved_handler, corrupted_path, entry)
    with pytest.raises(AssertionError, match="resolved jump table bytes differ"):
        assert_matches_original(corrupted_path, expected_handler)


def test_resolved_gate_rejects_wrong_fallback_address(handler_object, expected_handler, tmp_path):
    """A successfully linked call to the wrong callee must fail exact comparison."""
    addresses = dict(EXTERNAL_SYMBOLS)
    addresses["func_1FBD30"] += 4
    wrong_handler = link_handler(handler_object, tmp_path, addresses)
    with pytest.raises(AssertionError, match="resolved text bytes differ"):
        assert_matches_original(wrong_handler, expected_handler)


def test_resolved_gate_rejects_unresolved_fallback(handler_object, tmp_path):
    """Missing external definitions must fail linking, not count as matching."""
    addresses = dict(EXTERNAL_SYMBOLS)
    del addresses["func_1FBD30"]
    with pytest.raises(subprocess.CalledProcessError) as failure:
        link_handler(handler_object, tmp_path, addresses)
    assert "undefined reference to `func_1FBD30'" in failure.value.stderr
