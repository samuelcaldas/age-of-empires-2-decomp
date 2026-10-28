"""Require real instruction equality for the kt_vsync_thread_220c10 slice."""

import pytest
import yaml

from kt_vsync_thread_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_vsync_thread,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def vsync_thread_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_vsync_thread(tmp_path_factory.mktemp("kt-vsync-thread-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_vsync_thread_matches_original(vsync_thread_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(vsync_thread_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_vsync_thread_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_vsync_thread_220c10")
    assert (segment["start"], segment["vram"]) == (0x120DF0, 0x220C10)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "post_220C60")
    assert post_segment["start"] == 0x120E40

    # Verify prologue instructions in original ELF
    # func_00220C10: addiu $sp, $sp, -0x10; sq $ra, 0x0($sp)
    assert original_bytes(0x220C10, 8) == b"\xf0\xff\xbd\x27\x00\x00\xbf\x7f"
    # End of func_00220C10: loop back instruction: b 0x220C18; sw $v0, -0x74a8($gp)
    assert original_bytes(0x220C54, 8) == b"\xf0\xff\x00\x10\x58\x8b\x82\xaf"
    # End padding before 0x220C60
    assert original_bytes(0x220C5C, 4) == b"\x00\x00\x00\x00"
