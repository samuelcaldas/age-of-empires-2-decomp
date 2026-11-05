"""Require real instruction equality for the kt_thread_init_220380 slice."""

import pytest
import yaml

from kt_thread_init_220380_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_thread_init_220380,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def thread_init_220380_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_thread_init_220380(tmp_path_factory.mktemp("kt-thread-init-220380-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_thread_init_220380_matches_original(thread_init_220380_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(thread_init_220380_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_thread_init_220380_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_thread_init_220380")
    assert (segment["start"], segment["vram"]) == (0x120560, 0x220380)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_sema_poll_2204d0")
    assert post_segment["start"] == 0x1206B0

    # Verify prologue instructions in original ELF
    # func_00220380: addiu $sp, $sp, -0x70; sq $ra, 0x30($sp)
    assert original_bytes(0x220380, 8) == b"\x90\xff\xbd\x27\x30\x00\xbf\x7f"
    # func_00220420: addiu $sp, $sp, -0x60; sq $ra, 0x50($sp)
    assert original_bytes(0x220420, 8) == b"\xa0\xff\xbd\x27\x50\x00\xbf\x7f"
    # End of func_00220380 padding before func_00220420: 8 bytes nop
    assert original_bytes(0x220418, 8) == b"\x00" * 8
    # End of func_00220420 padding before func_002204D0: 12 bytes nop
    assert original_bytes(0x2204C4, 12) == b"\x00" * 12
