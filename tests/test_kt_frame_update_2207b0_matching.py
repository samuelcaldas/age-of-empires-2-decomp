"""Require real instruction equality for the kt_frame_update_2207b0 slice."""

import pytest
import yaml

from kt_frame_update_2207b0_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_frame_update_2207b0,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def frame_update_2207b0_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_frame_update_2207b0(tmp_path_factory.mktemp("kt-frame-update-2207b0-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_frame_update_2207b0_matches_original(frame_update_2207b0_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(frame_update_2207b0_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_frame_update_2207b0_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_frame_update_2207b0")
    assert (segment["start"], segment["vram"]) == (0x120990, 0x2207B0)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_thread_spawn_220940")
    assert post_segment["start"] == 0x120B20

    # Verify prologue instructions in original ELF
    # func_002207B0: addiu $sp, $sp, -0x20; sq $ra, 0x10($sp)
    assert original_bytes(0x2207B0, 8) == b"\xe0\xff\xbd\x27\x10\x00\xbf\x7f"
    # func_002208F0: lui $v0, 0xC9; addiu $a0, $v0, 0x2D10
    assert original_bytes(0x2208F0, 8) == b"\xc9\x00\x02\x3c\x10\x2d\x44\x24"
    # End of func_002207B0 padding before func_002208F0: 8 bytes nop
    assert original_bytes(0x2208E8, 8) == b"\x00" * 8
    # End of func_002208F0 padding before func_00220940: 4 bytes nop
    assert original_bytes(0x22093C, 4) == b"\x00" * 4
