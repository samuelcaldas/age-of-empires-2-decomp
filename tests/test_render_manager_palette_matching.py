"""Require real instruction equality for the RenderManager palette slice."""

import re

import pytest
import yaml

from render_manager_palette_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_palette,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def palette_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_palette(tmp_path_factory.mktemp("render-manager-palette-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_palette_matches_original(palette_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(palette_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_palette_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_palette")
    assert (segment["start"], segment["vram"]) == (0x87660, 0x187480)
    # Check prologue at 0x187480: addiu $sp, $sp, -96
    assert original_bytes(0x187480, 4) == bytes.fromhex("a0ffbd27")
    # Check padding at 0x187558: 8 zero bytes
    assert original_bytes(0x187558, 8) == bytes(8)
    # Check prologue at 0x187560: addiu $sp, $sp, -16
    assert original_bytes(0x187560, 4) == bytes.fromhex("f0ffbd27")
    # Check padding at 0x1875C8: 8 zero bytes
    assert original_bytes(0x1875C8, 8) == bytes(8)
    # Check prologue at 0x1875D0: addiu $sp, $sp, -32
    assert original_bytes(0x1875D0, 4) == bytes.fromhex("e0ffbd27")
    # Check padding at 0x187644: 12 zero bytes
    assert original_bytes(0x187644, 12) == bytes(12)
    # Check prologue at 0x187650: jr $ra
    assert original_bytes(0x187650, 4) == bytes.fromhex("0800e003")
    # Check padding at 0x187658: 8 zero bytes
    assert original_bytes(0x187658, 8) == bytes(8)
    # Check next prologue at 0x187660: addiu $sp, $sp, -32
    assert original_bytes(0x187660, 4) == bytes.fromhex("e0ffbd27")


def test_render_manager_palette_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
