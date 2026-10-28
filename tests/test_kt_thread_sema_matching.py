"""Require real instruction equality for the kt_thread_sema_220280 slice."""

import pytest
import yaml

from kt_thread_sema_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_thread_sema,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def thread_sema_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_thread_sema(tmp_path_factory.mktemp("kt-thread-sema-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_thread_sema_matches_original(thread_sema_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(thread_sema_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_thread_sema_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "kt_thread_sema_220280")
    assert (segment["start"], segment["vram"]) == (0x120460, 0x220280)

    post_segment = next(item for item in config["segments"] if item["name"] == "post_220380")
    assert post_segment["start"] == 0x120560

    # Verify prologue instructions in original ELF
    # func_00220280: addiu $sp, $sp, -0x20; sq $ra, 0x10($sp)
    assert original_bytes(0x220280, 8) == b"\xe0\xff\xbd\x27\x10\x00\xbf\x7f"
    # func_00220300: addiu $sp, $sp, -0x50; sq $ra, 0x20($sp)
    assert original_bytes(0x220300, 8) == b"\xb0\xff\xbd\x27\x20\x00\xbf\x7f"
    # End of func_00220280 padding before func_00220300
    assert original_bytes(0x2202FC, 4) == b"\x00\x00\x00\x00"
    # End of func_00220300 padding before func_00220380
    assert original_bytes(0x220378, 8) == b"\x00" * 8
