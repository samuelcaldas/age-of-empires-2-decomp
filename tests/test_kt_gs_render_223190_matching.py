"""Require real instruction equality for the kt_gs_render_223190 slice."""

import pytest
import yaml

from kt_gs_render_223190_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_render_223190,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_render_223190_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_render_223190(tmp_path_factory.mktemp("kt-gs-render-223190-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_render_223190_matches_original(gs_render_223190_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_render_223190_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_render_223190_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_render_223190")
    assert (segment["start"], segment["vram"]) == (0x123370, 0x223190)

    # Verify prologue instructions in original ELF
    # func_00223190: addiu sp, sp, -0x180; sq ra, 0xB0(sp)
    assert original_bytes(0x223190, 8) == b"\x80\xfe\xbd\x27\xb0\x00\xbf\x7f"
    # End of func_00223680: 8 bytes nop padding before 0x223690
    assert original_bytes(0x223688, 8) == b"\x00" * 8
