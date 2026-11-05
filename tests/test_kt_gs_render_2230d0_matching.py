"""Require real instruction equality for the kt_gs_render_2230d0 slice."""

import pytest
import yaml

from kt_gs_render_2230d0_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_render_2230d0,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_render_2230d0_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_render_2230d0(tmp_path_factory.mktemp("kt-gs-render-2230d0-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_render_2230d0_matches_original(gs_render_2230d0_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_render_2230d0_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_render_2230d0_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_render_2230d0")
    assert (segment["start"], segment["vram"]) == (0x1232B0, 0x2230D0)

    # Verify prologue instructions in original ELF
    # func_002230D0: addiu sp, sp, -0x20; sq ra, 0x10(sp)
    assert original_bytes(0x2230D0, 8) == b"\xe0\xff\xbd\x27\x10\x00\xbf\x7f"
    # End of func_00223130: 4 bytes nop padding before 0x223190
    assert original_bytes(0x22318C, 4) == b"\x00" * 4
