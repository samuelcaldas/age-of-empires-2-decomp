"""Require real instruction equality for the RenderManager activate slice."""

import re

import pytest
import yaml

from render_manager_activate_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_activate,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def activate_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_activate(tmp_path_factory.mktemp("render-manager-activate-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_activate_matches_original(activate_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(activate_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_activate_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_activate")
    assert (segment["start"], segment["vram"]) == (0x87350, 0x187170)
    # Check prologue at 0x187170: addiu $sp, $sp, -32
    assert original_bytes(0x187170, 4) == bytes.fromhex("e0ffbd27")
    # Check padding at 0x1872FC: 4 zero bytes
    assert original_bytes(0x1872FC, 4) == bytes(4)
    # Check prologue at 0x187300: jr $ra
    assert original_bytes(0x187300, 4) == bytes.fromhex("0800e003")
    # Check padding at 0x187308: 8 zero bytes
    assert original_bytes(0x187308, 8) == bytes(8)
    # Check prologue at 0x187310: jr $ra
    assert original_bytes(0x187310, 4) == bytes.fromhex("0800e003")
    # Check padding at 0x187318: 8 zero bytes
    assert original_bytes(0x187318, 8) == bytes(8)
    # Check prologue at 0x187320: addiu $sp, $sp, -16
    assert original_bytes(0x187320, 4) == bytes.fromhex("f0ffbd27")
    # Check prologue at 0x187350: jr $ra
    assert original_bytes(0x187350, 4) == bytes.fromhex("0800e003")
    # Check padding at 0x187358: 8 zero bytes
    assert original_bytes(0x187358, 8) == bytes(8)
    # Check prologue at 0x187360: addiu $sp, $sp, -16
    assert original_bytes(0x187360, 4) == bytes.fromhex("f0ffbd27")
    # Check prologue at 0x187390: jr $ra
    assert original_bytes(0x187390, 4) == bytes.fromhex("0800e003")
    # Check padding at 0x187398: 8 zero bytes
    assert original_bytes(0x187398, 8) == bytes(8)
    # Check next prologue at 0x1873A0: addiu $sp, $sp, -48
    assert original_bytes(0x1873A0, 4) == bytes.fromhex("d0ffbd27")


def test_render_manager_activate_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
