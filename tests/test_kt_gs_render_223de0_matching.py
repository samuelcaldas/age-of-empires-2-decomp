"""Require real instruction equality for the kt_gs_render_223de0 slice."""

import pytest
import yaml

from kt_gs_render_223de0_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_render_223de0,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_render_223de0_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_render_223de0(tmp_path_factory.mktemp("kt-gs-render-223de0-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_render_223de0_matches_original(gs_render_223de0_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_render_223de0_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_render_223de0_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_render_223de0")
    assert (segment["start"], segment["vram"]) == (0x123FC0, 0x223DE0)

    # Verify prologue instructions in original ELF
    # func_00223DE0: addiu sp, sp, -0x90; paddub v1, a1, zero
    assert original_bytes(0x223DE0, 8) == b"\x70\xff\xbd\x27\x28\x1e\xa0\x70"
    # End of func_00223FF0: 12 bytes nop padding before 0x2240B0
    assert original_bytes(0x2240A4, 12) == b"\x00" * 12
