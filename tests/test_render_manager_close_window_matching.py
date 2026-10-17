"""Require real instruction equality for the RenderManager close window slice."""

import re

import pytest
import yaml

from render_manager_close_window_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_close_window,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def close_window_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_close_window(tmp_path_factory.mktemp("render-manager-close-window-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_close_window_matches_original(close_window_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(close_window_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_close_window_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_close_window")
    assert (segment["start"], segment["vram"]) == (0x87840, 0x187660)
    # Check prologue at 0x187660: addiu $sp, $sp, -32
    assert original_bytes(0x187660, 4) == bytes.fromhex("e0ffbd27")
    # Check padding at 0x1876A8: 8 zero bytes
    assert original_bytes(0x1876A8, 8) == bytes(8)
    # Check next prologue at 0x1876B0: addiu $sp, $sp, -288
    assert original_bytes(0x1876B0, 4) == bytes.fromhex("e0febd27")


def test_render_manager_close_window_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
