"""Require real instruction equality for the RenderManager idle slice."""

import re

import pytest
import yaml

from render_manager_idle_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_idle,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def idle_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_idle(tmp_path_factory.mktemp("render-manager-idle-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_idle_matches_original(idle_object, name):
    """Require every original instruction byte, including relocated call targets."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(idle_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_render_manager_idle_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_idle")
    assert (segment["start"], segment["vram"]) == (0x86950, 0x186770)
    # Check prologue at 0x186770: addiu $sp, $sp, -48
    assert original_bytes(0x186770, 4) == bytes.fromhex("d0ffbd27")
    # Check padding at 0x186928: 8 zero bytes
    assert original_bytes(0x186928, 8) == bytes(8)
    # Check prologue at 0x186930: lw $a0, 48($a0)
    assert original_bytes(0x186930, 4) == bytes.fromhex("3000848c")
    # Check padding at 0x186944: 12 zero bytes
    assert original_bytes(0x186944, 12) == bytes(12)
    # Check next prologue at 0x186950: addiu $sp, $sp, -96
    assert original_bytes(0x186950, 4) == bytes.fromhex("a0ffbd27")


def test_render_manager_idle_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
