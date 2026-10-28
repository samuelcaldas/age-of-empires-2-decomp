"""Require real instruction equality for the kt_thread_spawn_220ba0 slice."""

import pytest
import yaml

from kt_thread_spawn_220ba0_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_thread_spawn_220ba0,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def thread_spawn_220ba0_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_thread_spawn_220ba0(tmp_path_factory.mktemp("kt-thread-spawn-220ba0-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_thread_spawn_220ba0_matches_original(thread_spawn_220ba0_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(thread_spawn_220ba0_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_thread_spawn_220ba0_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_thread_spawn_220ba0")
    assert (segment["start"], segment["vram"]) == (0x120D80, 0x220BA0)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_vsync_thread_220c10")
    assert post_segment["start"] == 0x120DF0

    # Verify prologue instructions in original ELF
    # func_00220BA0: addiu $sp, $sp, -0x10; lui $v0, 0xC8
    assert original_bytes(0x220BA0, 8) == b"\xf0\xff\xbd\x27\xc8\x00\x02\x3c"
    # End of func_00220BA0 padding before func_00220C10: 12 bytes nop
    assert original_bytes(0x220C04, 12) == b"\x00" * 12
