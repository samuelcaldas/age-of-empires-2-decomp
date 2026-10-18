"""Require real instruction equality for the RenderManager surface slice."""

import re

import pytest
import yaml

from render_manager_surface_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_surface,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def surface_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_surface(tmp_path_factory.mktemp("render-manager-surface-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_surface_matches_original(surface_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(surface_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_surface_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_surface")
    assert (segment["start"], segment["vram"]) == (0x88B80, 0x1889A0)
    # Check prologue at 0x1889A0: addiu $sp, $sp, -0x20
    assert original_bytes(0x1889A0, 4) == bytes.fromhex("e0ffbd27")
    # Check prologue at 0x188A40: addiu $v0, $zero, 0x1
    assert original_bytes(0x188A40, 4) == bytes.fromhex("01000224")
    # Check prologue at 0x188A90: dsll32 $v1, $a0, 24
    assert original_bytes(0x188A90, 4) == bytes.fromhex("3c1e0400")
    # Check prologue at 0x188BA0: jr $ra
    assert original_bytes(0x188BA0, 4) == bytes.fromhex("0800e003")
    # Check next prologue at 0x188C00: jr $ra
    assert original_bytes(0x188C00, 4) == bytes.fromhex("0800e003")


def test_render_manager_surface_symbols():
    """Verify symbol declarations in config/SLES-50282/symbols.txt."""
    symbols_txt = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (address, size) in FUNCTIONS.items():
        pattern = rf"^{name}\s*=\s*0x{address:X};\s*//\s*type:func\s+size:0x{size:02X}\s+absolute:True"
        assert re.search(pattern, symbols_txt, re.MULTILINE), f"Missing or invalid symbol {name}"
