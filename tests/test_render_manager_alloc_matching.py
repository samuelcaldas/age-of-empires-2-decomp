"""Require real instruction equality for the RenderManager alloc slice."""

import re

import pytest
import yaml

from render_manager_alloc_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_alloc,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def alloc_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_alloc(tmp_path_factory.mktemp("render-manager-alloc-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_alloc_matches_original(alloc_object, name):
    """Require every original instruction byte, including relocated call and data targets."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(alloc_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_render_manager_alloc_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_alloc")
    assert (segment["start"], segment["vram"]) == (0x85750, 0x185570)
    # Check prologue at 0x185570: addiu $sp, $sp, -0x30 (0x27bdffd0)
    assert original_bytes(0x185570, 4) == bytes.fromhex("d0ffbd27")
    # Check padding at 0x185608
    assert original_bytes(0x185608, 8) == bytes(8)
    # Check next prologue at 0x185660: addiu $sp, $sp, -0x30 (0x27bdffd0)
    assert original_bytes(0x185660, 4) == bytes.fromhex("d0ffbd27")


def test_render_manager_alloc_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
