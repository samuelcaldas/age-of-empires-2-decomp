"""Require real instruction equality for the RenderManager input translate slice."""

import re

import pytest
import yaml

from render_manager_input_translate_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_input_translate,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def input_translate_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_input_translate(tmp_path_factory.mktemp("render-manager-input-translate-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_input_translate_matches_original(input_translate_object, name):
    """Require every original instruction byte, including relocated data targets."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(input_translate_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_render_manager_input_translate_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_input_translate")
    assert (segment["start"], segment["vram"]) == (0x85340, 0x185160)
    # Check prologue at 0x185160: lw $a3, 0x4($a0) (0x8c870004)
    assert original_bytes(0x185160, 4) == bytes.fromhex("0400878c")
    # Check next prologue at 0x185230: addiu $sp, $sp, -0x50 (0x27bdffb0)
    assert original_bytes(0x185230, 4) == bytes.fromhex("b0ffbd27")


def test_render_manager_input_translate_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
