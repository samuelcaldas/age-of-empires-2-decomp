"""Require real instruction equality for the kt_gs_render_222370 slice."""

import pytest
import yaml

from kt_gs_render_222370_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_render_222370,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_render_222370_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_render_222370(tmp_path_factory.mktemp("kt-gs-render-222370-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_render_222370_matches_original(gs_render_222370_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_render_222370_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_render_222370_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_render_222370")
    assert (segment["start"], segment["vram"]) == (0x122550, 0x222370)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "post_222500")
    assert post_segment["start"] == 0x1226E0

    # Verify prologue instructions in original ELF
    # func_00222370: addiu $sp, $sp, -0x40; sq $ra, 0x30($sp)
    assert original_bytes(0x222370, 8) == b"\xc0\xff\xbd\x27\x30\x00\xbf\x7f"
    # End of func_002223B0 padding before 0x222500: 8 bytes nop
    assert original_bytes(0x2224F8, 8) == b"\x00" * 8
