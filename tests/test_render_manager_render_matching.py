"""Require real instruction equality for the RenderManager render slice."""

import re

import pytest
import yaml

from render_manager_render_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_render,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def render_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_render(tmp_path_factory.mktemp("render-manager-render-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_render_matches_original(render_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(render_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_render_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_render")
    assert (segment["start"], segment["vram"]) == (0x87030, 0x186E50)
    # Check prologue at 0x186E50: addiu $sp, $sp, -80
    assert original_bytes(0x186E50, 4) == bytes.fromhex("b0ffbd27")
    # Check padding at 0x18716C: 4 zero bytes
    assert original_bytes(0x18716C, 4) == bytes(4)
    # Check next prologue at 0x187170: addiu $sp, $sp, -32
    assert original_bytes(0x187170, 4) == bytes.fromhex("e0ffbd27")


def test_render_manager_render_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
