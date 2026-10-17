"""Require real instruction equality for the RenderManager loop slice."""

import re

import pytest
import yaml

from render_manager_loop_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_loop,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def loop_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_loop(tmp_path_factory.mktemp("render-manager-loop-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_loop_matches_original(loop_object, name):
    """Require every original instruction byte, including relocated call and data targets."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(loop_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_render_manager_loop_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_loop")
    assert (segment["start"], segment["vram"]) == (0x85410, 0x185230)
    # Check prologue at 0x185230: addiu $sp, $sp, -0x50 (0x27bdffb0)
    assert original_bytes(0x185230, 4) == bytes.fromhex("b0ffbd27")
    # Check 4-byte padding at 0x1853DC
    assert original_bytes(0x1853DC, 4) == bytes(4)
    # Check next prologue at 0x1853E0: jr $ra (0x03e00008)
    assert original_bytes(0x1853E0, 4) == bytes.fromhex("0800e003")


def test_render_manager_loop_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
