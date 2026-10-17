"""Require real instruction equality for the RenderManager blank screen slice."""

import re

import pytest
import yaml

from render_manager_blank_screen_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_blank_screen,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def blank_screen_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_blank_screen(tmp_path_factory.mktemp("render-manager-blank-screen-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_blank_screen_matches_original(blank_screen_object, name):
    """Require every original instruction byte, including relocated call and data targets."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(blank_screen_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_render_manager_blank_screen_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_blank_screen")
    assert (segment["start"], segment["vram"]) == (0x85B80, 0x1859A0)
    # Check prologue at 0x1859A0: addiu $sp, $sp, -0x30 (0x27bdffd0)
    assert original_bytes(0x1859A0, 4) == bytes.fromhex("d0ffbd27")
    # Check paddings
    assert original_bytes(0x185A44, 12) == bytes(12)
    assert original_bytes(0x185A74, 12) == bytes(12)
    # Check next prologue at 0x185A80: addiu $sp, $sp, -0x30 (0x27bdffd0)
    assert original_bytes(0x185A80, 4) == bytes.fromhex("d0ffbd27")


def test_render_manager_blank_screen_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
