"""Require real instruction equality for the RenderManager command slice."""

import re

import pytest
import yaml

from render_manager_command_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_command,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def command_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_command(tmp_path_factory.mktemp("render-manager-command-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_command_matches_original(command_object, name):
    """Require every original instruction byte, including relocated call targets."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(command_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_render_manager_command_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_command")
    assert (segment["start"], segment["vram"]) == (0x86E00, 0x186C20)
    # Check prologue at 0x186C20: addiu $sp, $sp, -64
    assert original_bytes(0x186C20, 4) == bytes.fromhex("c0ffbd27")
    # Check padding at 0x186DA8: 8 zero bytes
    assert original_bytes(0x186DA8, 8) == bytes(8)
    # Check prologue at 0x186DB0: jr $ra
    assert original_bytes(0x186DB0, 4) == bytes.fromhex("0800e003")
    # Check padding at 0x186DB8: 8 zero bytes
    assert original_bytes(0x186DB8, 8) == bytes(8)
    # Check next prologue at 0x186DC0: addiu $sp, $sp, -16
    assert original_bytes(0x186DC0, 4) == bytes.fromhex("f0ffbd27")


def test_render_manager_command_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
