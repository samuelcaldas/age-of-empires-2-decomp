"""Require real instruction equality for the RenderManager display mode slice."""

import re

import pytest
import yaml

from render_manager_display_mode_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_display_mode,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def display_mode_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_display_mode(tmp_path_factory.mktemp("render-manager-display-mode-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_display_mode_matches_original(display_mode_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(display_mode_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_display_mode_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_display_mode")
    assert (segment["start"], segment["vram"]) == (0x88920, 0x188740)
    # Check prologue at 0x188740: addiu $sp, $sp, -0x40
    assert original_bytes(0x188740, 4) == bytes.fromhex("c0ffbd27")
    # Check prologue at 0x188940: addiu $sp, $sp, -0x20
    assert original_bytes(0x188940, 4) == bytes.fromhex("e0ffbd27")
    # Check next prologue at 0x1889A0: addiu $sp, $sp, -0x20
    assert original_bytes(0x1889A0, 4) == bytes.fromhex("e0ffbd27")


def test_render_manager_display_mode_symbols():
    """Verify symbol declarations in config/SLES-50282/symbols.txt."""
    symbols_txt = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (address, size) in FUNCTIONS.items():
        pattern = rf"^{name}\s*=\s*0x{address:X};\s*//\s*type:func\s+size:0x{size:02X}\s+absolute:True"
        assert re.search(pattern, symbols_txt, re.MULTILINE), f"Missing or invalid symbol {name}"
