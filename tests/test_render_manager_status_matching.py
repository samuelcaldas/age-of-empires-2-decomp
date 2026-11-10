"""Require status helper instruction bytes and slice boundaries."""

import re

import pytest
import yaml

from render_manager_status_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_status,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def status_object(tmp_path_factory):
    """Compile current production source rather than trusting a cached object."""
    return compile_status(tmp_path_factory.mktemp("render-manager-status-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_status_matches_original(status_object, name):
    """Verify each function matches 100% byte for byte."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(status_object, name)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == original_bytes(address, size)


def test_render_manager_status_split_boundaries():
    """Verify slice boundaries in config.yml."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segments = config["segments"]
    index = next(i for i, seg in enumerate(segments)
                 if isinstance(seg, dict) and seg.get("name") == "render_manager_status")
    segment = segments[index]
    assert (segment["start"], segment["vram"]) == (0x89E60, 0x189C80)
    assert segment["type"] == "code"
    assert segment["subsegments"] == [[0x89E60, "asm", "render/render_manager_status"]]
    assert segments[index + 1]["start"] == 0x8A050
    assert segments[index + 1]["vram"] == 0x189E70


def test_render_manager_status_symbols_registered():
    """Verify production symbols in symbols.txt."""
    symbols = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (addr, size) in FUNCTIONS.items():
        pattern = rf"{re.escape(name)}\s*=\s*0x{addr:X};\s*//\s*type:func"
        assert re.search(pattern, symbols, re.MULTILINE), f"Missing symbol {name}"
