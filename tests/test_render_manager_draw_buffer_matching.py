"""Require real instruction equality for the RenderManager draw buffer slice."""

import re

import pytest
import yaml

from render_manager_draw_buffer_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_draw_buffer,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def draw_buffer_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_draw_buffer(tmp_path_factory.mktemp("render-manager-draw-buffer-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_draw_buffer_matches_original(draw_buffer_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(draw_buffer_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_draw_buffer_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_draw_buffer")
    assert (segment["start"], segment["vram"]) == (0x88DE0, 0x188C00)
    # Check prologue at 0x188C00: jr $ra
    assert original_bytes(0x188C00, 4) == bytes.fromhex("0800e003")
    # Check prologue at 0x188C10: sw $zero, 0x14($a0)
    assert original_bytes(0x188C10, 4) == bytes.fromhex("140080ac")
    # Check prologue at 0x188C20: addiu $sp, $sp, -0x40
    assert original_bytes(0x188C20, 4) == bytes.fromhex("c0ffbd27")
    # Check prologue at 0x188CF0: addiu $sp, $sp, -0x30
    assert original_bytes(0x188CF0, 4) == bytes.fromhex("d0ffbd27")
    # Check prologue at 0x188DB0: jr $ra
    assert original_bytes(0x188DB0, 4) == bytes.fromhex("0800e003")
    # Check next prologue at 0x188DF0: addiu $sp, $sp, -0x30
    assert original_bytes(0x188DF0, 4) == bytes.fromhex("d0ffbd27")


def test_render_manager_draw_buffer_symbols():
    """Verify symbol declarations in config/SLES-50282/symbols.txt."""
    symbols_txt = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (address, size) in FUNCTIONS.items():
        pattern = rf"^{name}\s*=\s*0x{address:X};\s*//\s*type:func\s+size:0x{size:02X}\s+absolute:True"
        assert re.search(pattern, symbols_txt, re.MULTILINE), f"Missing or invalid symbol {name}"
