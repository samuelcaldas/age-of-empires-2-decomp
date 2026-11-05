"""Require real instruction equality for the kt_gs_draw_221e20 slice."""

import pytest
import yaml

from kt_gs_draw_221e20_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_draw_221e20,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_draw_221e20_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_draw_221e20(tmp_path_factory.mktemp("kt-gs-draw-221e20-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_draw_221e20_matches_original(gs_draw_221e20_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_draw_221e20_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_draw_221e20_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_draw_221e20")
    assert (segment["start"], segment["vram"]) == (0x122000, 0x221E20)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_step_221f40")
    assert post_segment["start"] == 0x122120

    # Verify prologue instructions in original ELF
    # func_00221E20: addiu $sp, $sp, -0xC0; sq $ra, 0xA0($sp)
    assert original_bytes(0x221E20, 8) == b"\x40\xff\xbd\x27\xa0\x00\xbf\x7f"
    # End of func_00221E20 delay slot at 0x221F3C: addiu $sp, $sp, 0xC0
    assert original_bytes(0x221F3C, 4) == b"\xc0\x00\xbd\x27"
