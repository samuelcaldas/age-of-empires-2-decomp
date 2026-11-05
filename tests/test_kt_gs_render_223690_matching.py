"""Require real instruction equality for the kt_gs_render_223690 slice."""

import pytest
import yaml

from kt_gs_render_223690_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_render_223690,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_render_223690_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_render_223690(tmp_path_factory.mktemp("kt-gs-render-223690-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_render_223690_matches_original(gs_render_223690_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_render_223690_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_render_223690_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_render_223690")
    assert (segment["start"], segment["vram"]) == (0x123870, 0x223690)

    # Verify prologue instructions in original ELF
    # func_00223690: addiu sp, sp, -0x170; sq ra, 0x90(sp)
    assert original_bytes(0x223690, 8) == b"\x90\xfe\xbd\x27\x90\x00\xbf\x7f"
    # End of func_00223D80: 16 bytes nop padding before 0x223DE0
    assert original_bytes(0x223DD0, 16) == b"\x00" * 16
