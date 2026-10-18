"""Require real instruction equality for the RenderManager chat init slice."""

import re

import pytest
import yaml

from render_manager_chat_init_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_chat_init,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def chat_init_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_chat_init(tmp_path_factory.mktemp("render-manager-chat-init-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_chat_init_matches_original(chat_init_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(chat_init_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_chat_init_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_chat_init")
    assert (segment["start"], segment["vram"]) == (0x88FD0, 0x188DF0)
    # Check prologue at 0x188DF0: addiu $sp, $sp, -0x30
    assert original_bytes(0x188DF0, 4) == bytes.fromhex("d0ffbd27")
    # Check padding at 0x188E9C: 4 zero bytes
    assert original_bytes(0x188E9C, 4) == bytes(4)
    # Check next prologue at 0x188EA0: addiu $sp, $sp, -0xC50
    assert original_bytes(0x188EA0, 4) == bytes.fromhex("b0f3bd27")


def test_render_manager_chat_init_symbols():
    """Verify symbol declarations in config/SLES-50282/symbols.txt."""
    symbols_txt = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (address, size) in FUNCTIONS.items():
        pattern = rf"^{name}\s*=\s*0x{address:X};\s*//\s*type:func\s+size:0x{size:02X}\s+absolute:True"
        assert re.search(pattern, symbols_txt, re.MULTILINE), f"Missing or invalid symbol {name}"
