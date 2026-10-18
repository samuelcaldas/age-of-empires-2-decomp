"""Require real instruction equality for the RenderManager screen mode slice."""

import re

import pytest
import yaml

from render_manager_screen_mode_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_screen_mode,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def screen_mode_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_screen_mode(tmp_path_factory.mktemp("render-manager-screen-mode-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_screen_mode_matches_original(screen_mode_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(screen_mode_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_screen_mode_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_screen_mode")
    assert (segment["start"], segment["vram"]) == (0x88770, 0x188590)
    # Check prologue at 0x188590: addiu $sp, $sp, -0x70
    assert original_bytes(0x188590, 4) == bytes.fromhex("90ffbd27")
    # Check prologue at 0x188680: addiu $sp, $sp, -0x20
    assert original_bytes(0x188680, 4) == bytes.fromhex("e0ffbd27")
    # Check prologue at 0x1886B0: addiu $sp, $sp, -0x20
    assert original_bytes(0x1886B0, 4) == bytes.fromhex("e0ffbd27")
    # Check prologue at 0x1886F0: addiu $v0, $zero, 0x1
    assert original_bytes(0x1886F0, 4) == bytes.fromhex("01000224")
    # Check prologue at 0x188720: sw $zero, 0x60($a0)
    assert original_bytes(0x188720, 4) == bytes.fromhex("600080ac")
    # Check next prologue at 0x188740: addiu $sp, $sp, -0x40
    assert original_bytes(0x188740, 4) == bytes.fromhex("c0ffbd27")


def test_render_manager_screen_mode_symbols():
    """Verify symbol declarations in config/SLES-50282/symbols.txt."""
    symbols_txt = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (address, size) in FUNCTIONS.items():
        pattern = rf"^{name}\s*=\s*0x{address:X};\s*//\s*type:func\s+size:0x{size:02X}\s+absolute:True"
        assert re.search(pattern, symbols_txt, re.MULTILINE), f"Missing or invalid symbol {name}"
