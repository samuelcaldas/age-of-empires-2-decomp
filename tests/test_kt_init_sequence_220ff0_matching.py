"""Require real instruction equality for the kt_init_sequence_220ff0 slice."""

import pytest
import yaml

from kt_init_sequence_220ff0_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_init_sequence_220ff0,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def init_sequence_220ff0_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_init_sequence_220ff0(tmp_path_factory.mktemp("kt-init-sequence-220ff0-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_init_sequence_220ff0_matches_original(init_sequence_220ff0_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(init_sequence_220ff0_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_init_sequence_220ff0_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_init_sequence_220ff0")
    assert (segment["start"], segment["vram"]) == (0x1211D0, 0x220FF0)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_init_sequence_221110")
    assert post_segment["start"] == 0x1212F0

    # Verify prologue instructions in original ELF
    # func_00220FF0: addiu $sp, $sp, -0x20; sq $ra, 0x10($sp)
    assert original_bytes(0x220FF0, 8) == b"\xe0\xff\xbd\x27\x10\x00\xbf\x7f"
    # End of func_00220FF0 padding before 0x221110: 12 bytes nop
    assert original_bytes(0x221104, 12) == b"\x00" * 12
