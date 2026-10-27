"""Require display reset instruction bytes and slice boundaries."""

import re

import pytest
import yaml

from render_manager_display_reset_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_display_reset,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def display_reset_object(tmp_path_factory):
    """Compile current production source rather than trusting a cached object."""
    return compile_display_reset(tmp_path_factory.mktemp("render-manager-display-reset-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_display_reset_matches_original(display_reset_object, name):
    """Verify each function matches 100% byte for byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(display_reset_object, name)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == original_bytes(address, size)


def test_render_manager_display_reset_split_boundaries():
    """Verify slice boundaries in config.yml."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segments = config["segments"]
    index = next(i for i, seg in enumerate(segments)
                 if isinstance(seg, dict) and seg.get("name") == "render_manager_display_reset")
    segment = segments[index]
    assert (segment["start"], segment["vram"]) == (0x89D20, 0x189B40)
    assert segment["type"] == "code"
    assert segment["subsegments"] == [[0x89D20, "asm", "render/render_manager_display_reset"]]
    assert segments[index + 1]["start"] == 0x89E60
    assert segments[index + 1]["vram"] == 0x189C80


def test_render_manager_display_reset_symbols_registered():
    """Verify production symbols in symbols.txt."""
    symbols = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (addr, size) in FUNCTIONS.items():
        pattern = rf"{re.escape(name)}\s*=\s*0x{addr:X};\s*//\s*type:func"
        assert re.search(pattern, symbols, re.MULTILINE), f"Missing symbol {name}"
