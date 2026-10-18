"""Require real instruction equality for the RenderManager chat methods slice."""

import re

import pytest
import yaml

from render_manager_chat_methods_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_chat_methods,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def chat_methods_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_chat_methods(tmp_path_factory.mktemp("render-manager-chat-methods-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_chat_methods_matches_original(chat_methods_object, name):
    """Require every original instruction byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(chat_methods_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Instruction mismatch in {name}"


def test_render_manager_chat_methods_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_chat_methods")
    assert (segment["start"], segment["vram"]) == (0x89280, 0x1890A0)
    # Check prologue at 0x1890A0: bltz $a1, +5
    assert original_bytes(0x1890A0, 4) == bytes.fromhex("0500a004")
    # Check prologue at 0x1890E0: addiu $sp, $sp, -0x40
    assert original_bytes(0x1890E0, 4) == bytes.fromhex("c0ffbd27")
    # Check prologue at 0x189150: jr $ra
    assert original_bytes(0x189150, 4) == bytes.fromhex("0800e003")
    # Check prologue at 0x189160: blez $a1, +7
    assert original_bytes(0x189160, 4) == bytes.fromhex("0700a018")
    # Check prologue at 0x189250: jr $ra
    assert original_bytes(0x189250, 4) == bytes.fromhex("0800e003")
    # Check next prologue at 0x189260: addiu $sp, $sp, -0x90
    assert original_bytes(0x189260, 4) == bytes.fromhex("70ffbd27")


def test_render_manager_chat_methods_symbols():
    """Verify symbol declarations in config/SLES-50282/symbols.txt."""
    symbols_txt = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (address, size) in FUNCTIONS.items():
        pattern = rf"^{name}\s*=\s*0x{address:X};\s*//\s*type:func\s+size:0x{size:02X}\s+absolute:True"
        assert re.search(pattern, symbols_txt, re.MULTILINE), f"Missing or invalid symbol {name}"
