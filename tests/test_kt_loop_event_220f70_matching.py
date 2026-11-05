"""Require real instruction equality for the kt_loop_event_220f70 slice."""

import pytest
import yaml

from kt_loop_event_220f70_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_loop_event_220f70,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def loop_event_220f70_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_loop_event_220f70(tmp_path_factory.mktemp("kt-loop-event-220f70-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_loop_event_220f70_matches_original(loop_event_220f70_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(loop_event_220f70_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_loop_event_220f70_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_loop_event_220f70")
    assert (segment["start"], segment["vram"]) == (0x121150, 0x220F70)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "post_220FF0")
    assert post_segment["start"] == 0x1211D0

    # Verify prologue instructions in original ELF
    # func_00220F70: addiu $sp, $sp, -0x10; sq $ra, 0x0($sp)
    assert original_bytes(0x220F70, 8) == b"\xf0\xff\xbd\x27\x00\x00\xbf\x7f"
    # End of func_00220F70 padding before 0x220FF0: 12 bytes nop
    assert original_bytes(0x220FE4, 12) == b"\x00" * 12
