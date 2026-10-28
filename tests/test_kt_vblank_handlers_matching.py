"""Require real instruction equality for the kt_vblank_handlers_220d50 slice."""

import pytest
import yaml

from kt_vblank_handlers_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_vblank_handlers,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def vblank_handlers_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_vblank_handlers(tmp_path_factory.mktemp("kt-vblank-handlers-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_vblank_handlers_matches_original(vblank_handlers_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(vblank_handlers_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_vblank_handlers_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_vblank_handlers_220d50")
    assert (segment["start"], segment["vram"]) == (0x120F30, 0x220D50)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "post_220DD0")
    assert post_segment["start"] == 0x120FB0

    # Verify prologue instructions in original ELF
    # func_00220D50: addiu $sp, $sp, -0x10; sq $ra, 0x0($sp)
    assert original_bytes(0x220D50, 8) == b"\xf0\xff\xbd\x27\x00\x00\xbf\x7f"
    # func_00220DA0: addiu $sp, $sp, -0x10; sq $ra, 0x0($sp)
    assert original_bytes(0x220DA0, 8) == b"\xf0\xff\xbd\x27\x00\x00\xbf\x7f"
    # End of func_00220D50 padding before func_00220DA0
    assert original_bytes(0x220D98, 8) == b"\x00" * 8
    # End of func_00220DA0 epilogue at 0x220DC8: jr $ra; addiu $sp, $sp, 0x10
    assert original_bytes(0x220DC8, 8) == b"\x08\x00\xe0\x03\x10\x00\xbd\x27"
