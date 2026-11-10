"""Require error helper instruction bytes and slice boundaries."""

import re

import pytest
import yaml

from render_manager_error_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_error,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def error_object(tmp_path_factory):
    """Compile current production source rather than trusting a cached object."""
    return compile_error(tmp_path_factory.mktemp("render-manager-error-matching"))


def test_render_manager_error_ctor_exact(error_object):
    """Verify constructor matches 100% byte for byte."""
    name = "__ct__18RenderManagerErrorFPv"
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(error_object, name)
    assert actual == original_bytes(address, size)


def test_render_manager_error_format_exact(error_object):
    """Verify format_error tail call matches 100% byte for byte."""
    name = "format_error__18RenderManagerErrorFii"
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(error_object, name)
    assert actual == original_bytes(address, size)


def test_render_manager_error_dtor_exact(error_object):
    """Verify deleting destructor matches 100% byte for byte."""
    name = "__dt__18RenderManagerErrorFv"
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(error_object, name)
    assert actual == original_bytes(address, size)


def test_render_manager_error_translate_exact(error_object):
    """Verify translate_error matches 100% byte for byte."""
    name = "translate_error__18RenderManagerErrorFi"
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(error_object, name)
    assert actual == original_bytes(address, size)


def test_render_manager_error_split_boundaries():
    """Verify slice boundaries in config.yml."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segments = config["segments"]
    index = next(i for i, seg in enumerate(segments)
                 if isinstance(seg, dict) and seg.get("name") == "render_manager_error")
    segment = segments[index]
    assert (segment["start"], segment["vram"]) == (0x89A10, 0x189830)
    assert segment["type"] == "code"
    assert segment["subsegments"] == [[0x89A10, "asm", "render/render_manager_error"]]
    assert segments[index + 1]["start"] == 0x89D20
    assert segments[index + 1]["vram"] == 0x189B40


def test_render_manager_error_symbols_registered():
    """Verify production symbols in symbols.txt."""
    symbols = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (addr, size) in FUNCTIONS.items():
        pattern = rf"{re.escape(name)}\s*=\s*0x{addr:X};\s*//\s*type:func"
        assert re.search(pattern, symbols, re.MULTILINE), f"Missing symbol {name}"
