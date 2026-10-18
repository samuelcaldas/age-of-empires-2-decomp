"""Require real instruction equality for the RenderManager props slice."""

import re

import pytest
import yaml

from render_manager_props_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_props,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def props_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_props(tmp_path_factory.mktemp("render-manager-props-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_props_matches_original(props_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(props_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_props_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_props")
    assert (segment["start"], segment["vram"]) == (0x88200, 0x188020)
    # Check prologue at 0x188020: jr $ra
    assert original_bytes(0x188020, 4) == bytes.fromhex("0800e003")
    # Check prologue at 0x188250: jr $ra
    assert original_bytes(0x188250, 4) == bytes.fromhex("0800e003")
    # Check padding at 0x188258: 8 zero bytes
    assert original_bytes(0x188258, 8) == bytes(8)
    # Check next prologue at 0x188260: addiu $sp, $sp, -0x20
    assert original_bytes(0x188260, 4) == bytes.fromhex("e0ffbd27")


def test_render_manager_props_symbols():
    """Verify symbol declarations in config/SLES-50282/symbols.txt."""
    symbols_txt = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (address, size) in FUNCTIONS.items():
        pattern = rf"^{name}\s*=\s*0x{address:X};\s*//\s*type:func\s+size:0x{size:02X}\s+absolute:True"
        assert re.search(pattern, symbols_txt, re.MULTILINE), f"Missing or invalid symbol {name}"
