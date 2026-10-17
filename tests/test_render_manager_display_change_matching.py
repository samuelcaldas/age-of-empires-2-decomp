"""Require real instruction equality for the RenderManager display change slice."""

import re

import pytest
import yaml

from render_manager_display_change_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_display_change,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def display_change_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_display_change(tmp_path_factory.mktemp("render-manager-display-change-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_display_change_matches_original(display_change_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(display_change_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_display_change_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_display_change")
    assert (segment["start"], segment["vram"]) == (0x87580, 0x1873A0)
    # Check prologue at 0x1873A0: addiu $sp, $sp, -48
    assert original_bytes(0x1873A0, 4) == bytes.fromhex("d0ffbd27")
    # Check padding at 0x18746C: 4 zero bytes
    assert original_bytes(0x18746C, 4) == bytes(4)
    # Check prologue at 0x187470: jr $ra
    assert original_bytes(0x187470, 4) == bytes.fromhex("0800e003")
    # Check padding at 0x187478: 8 zero bytes
    assert original_bytes(0x187478, 8) == bytes(8)
    # Check next prologue at 0x187480: addiu $sp, $sp, -96
    assert original_bytes(0x187480, 4) == bytes.fromhex("a0ffbd27")


def test_render_manager_display_change_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
