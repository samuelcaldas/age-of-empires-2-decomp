"""Require real instruction equality for the kt_render_sync_220cd0 slice."""

import pytest
import yaml

from kt_render_sync_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_render_sync,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def render_sync_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_render_sync(tmp_path_factory.mktemp("kt-render-sync-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_render_sync_matches_original(render_sync_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(render_sync_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_render_sync_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_render_sync_220cd0")
    assert (segment["start"], segment["vram"]) == (0x120EB0, 0x220CD0)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_vblank_handlers_220d50")
    assert post_segment["start"] == 0x120F30

    # Verify prologue instructions in original ELF
    # func_00220CD0: addiu $sp, $sp, -0x10; sq $ra, 0x0($sp)
    assert original_bytes(0x220CD0, 8) == b"\xf0\xff\xbd\x27\x00\x00\xbf\x7f"
    # func_00220D20: addiu $sp, $sp, -0x10; sq $ra, 0x0($sp)
    assert original_bytes(0x220D20, 8) == b"\xf0\xff\xbd\x27\x00\x00\xbf\x7f"
    # End of func_00220D20 padding before func_00220D50
    assert original_bytes(0x220D48, 8) == b"\x00" * 8
