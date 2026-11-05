"""Require real instruction equality for the kt_gs_texture_221d10 slice."""

import pytest
import yaml

from kt_gs_texture_221d10_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_texture_221d10,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_texture_221d10_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_texture_221d10(tmp_path_factory.mktemp("kt-gs-texture-221d10-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_texture_221d10_matches_original(gs_texture_221d10_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_texture_221d10_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_texture_221d10_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_texture_221d10")
    assert (segment["start"], segment["vram"]) == (0x121EF0, 0x221D10)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_draw_221e20")
    assert post_segment["start"] == 0x122000

    # Verify prologue instructions in original ELF
    # func_00221D10: addiu $sp, $sp, -0x20; sq $ra, 0x10($sp)
    assert original_bytes(0x221D10, 8) == b"\xe0\xff\xbd\x27\x10\x00\xbf\x7f"
    # End of func_00221DC0 padding before 0x221E20: 8 bytes nop
    assert original_bytes(0x221E18, 8) == b"\x00" * 8
