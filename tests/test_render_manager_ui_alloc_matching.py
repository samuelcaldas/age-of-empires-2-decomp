"""Require real instruction equality for the RenderManager UI alloc slice."""

import re

import pytest
import yaml

from render_manager_ui_alloc_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_ui_alloc,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def ui_alloc_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_ui_alloc(tmp_path_factory.mktemp("render-manager-ui-alloc-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_ui_alloc_matches_original(ui_alloc_object, name):
    """Require every original instruction byte, including relocated call and data targets."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(ui_alloc_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_render_manager_ui_alloc_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_ui_alloc")
    assert (segment["start"], segment["vram"]) == (0x85840, 0x185660)
    # Check prologue at 0x185660: addiu $sp, $sp, -0x30 (0x27bdffd0)
    assert original_bytes(0x185660, 4) == bytes.fromhex("d0ffbd27")
    # Check paddings
    assert original_bytes(0x185758, 8) == bytes(8)
    assert original_bytes(0x1857AC, 4) == bytes(4)
    # Check next prologue at 0x1857B0: addiu $sp, $sp, -0x30 (0x27bdffd0)
    assert original_bytes(0x1857B0, 4) == bytes.fromhex("d0ffbd27")


def test_render_manager_ui_alloc_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
