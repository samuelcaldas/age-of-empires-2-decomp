"""Require real instruction equality for the RenderManager stats overlay slice."""

import re

import pytest
import yaml

from render_manager_stats_overlay_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_stats_overlay,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def stats_overlay_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_stats_overlay(tmp_path_factory.mktemp("render-manager-stats-overlay-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_stats_overlay_matches_original(stats_overlay_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(stats_overlay_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_stats_overlay_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_stats_overlay")
    assert (segment["start"], segment["vram"]) == (0x87D20, 0x187B40)
    # Check prologue at 0x187B40: addiu $sp, $sp, -0x30
    assert original_bytes(0x187B40, 4) == bytes.fromhex("d0ffbd27")
    # Check padding at 0x187C3C: 4 zero bytes
    assert original_bytes(0x187C3C, 4) == bytes(4)
    # Check prologue at 0x187C40: jr $ra
    assert original_bytes(0x187C40, 4) == bytes.fromhex("0800e003")
    # Check padding at 0x187C48: 8 zero bytes
    assert original_bytes(0x187C48, 8) == bytes(8)
    # Check prologue at 0x187C50: jr $ra
    assert original_bytes(0x187C50, 4) == bytes.fromhex("0800e003")
    # Check padding at 0x187C58: 8 zero bytes
    assert original_bytes(0x187C58, 8) == bytes(8)
    # Check prologue at 0x187C60: jr $ra
    assert original_bytes(0x187C60, 4) == bytes.fromhex("0800e003")
    # Check padding at 0x187C68: 8 zero bytes
    assert original_bytes(0x187C68, 8) == bytes(8)
    # Check prologue at 0x187C70: addiu $sp, $sp, -0x10
    assert original_bytes(0x187C70, 4) == bytes.fromhex("f0ffbd27")
    # Check next prologue at 0x187CA0: addiu $sp, $sp, -0x30
    assert original_bytes(0x187CA0, 4) == bytes.fromhex("d0ffbd27")


def test_render_manager_stats_overlay_symbols():
    """Verify symbol declarations in config/SLES-50282/symbols.txt."""
    symbols_txt = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (address, size) in FUNCTIONS.items():
        pattern = rf"^{name}\s*=\s*0x{address:X};\s*//\s*type:func\s+size:0x{size:02X}\s+absolute:True"
        assert re.search(pattern, symbols_txt, re.MULTILINE), f"Missing or invalid symbol {name}"
