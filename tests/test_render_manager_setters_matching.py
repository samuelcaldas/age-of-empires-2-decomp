"""Require real instruction equality for the RenderManager setters slice."""

import re

import pytest
import yaml

from render_manager_setters_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_setters,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def setters_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_setters(tmp_path_factory.mktemp("render-manager-setters-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_setters_matches_original(setters_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(setters_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_setters_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_setters")
    assert (segment["start"], segment["vram"]) == (0x88440, 0x188260)
    # Check prologue at 0x188260: addiu $sp, $sp, -0x20
    assert original_bytes(0x188260, 4) == bytes.fromhex("e0ffbd27")
    # Check prologue at 0x188560: addiu $sp, $sp, -0x10
    assert original_bytes(0x188560, 4) == bytes.fromhex("f0ffbd27")
    # Check next prologue at 0x188590: addiu $sp, $sp, -0x70
    assert original_bytes(0x188590, 4) == bytes.fromhex("90ffbd27")


def test_render_manager_setters_symbols():
    """Verify symbol declarations in config/SLES-50282/symbols.txt."""
    symbols_txt = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (address, size) in FUNCTIONS.items():
        pattern = rf"^{name}\s*=\s*0x{address:X};\s*//\s*type:func\s+size:0x{size:02X}\s+absolute:True"
        assert re.search(pattern, symbols_txt, re.MULTILINE), f"Missing or invalid symbol {name}"
