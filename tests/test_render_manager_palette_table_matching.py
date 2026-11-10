"""Require palette table instruction bytes and slice boundaries."""

import re

import pytest
import yaml

from render_manager_palette_table_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_palette_table,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def palette_table_object(tmp_path_factory):
    """Compile current production source rather than trusting a cached object."""
    return compile_palette_table(tmp_path_factory.mktemp("render-manager-palette-table-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_palette_table_sizes(palette_table_object, name):
    """Verify function sizes match original extent exactly."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(palette_table_object, name)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"


def test_render_manager_palette_table_ctor1_exact(palette_table_object):
    """Verify stream constructor matches 100% byte for byte."""
    name = "__ct__18RenderPaletteTableFPv"
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(palette_table_object, name)
    assert actual == original_bytes(address, size)


def test_render_manager_palette_table_dtor_exact(palette_table_object):
    """Verify virtual destructor matches 100% byte for byte."""
    name = "__dt__18RenderPaletteTableFv"
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(palette_table_object, name)
    assert actual == original_bytes(address, size)


def test_render_manager_palette_table_ctor2_structure(palette_table_object):
    """Verify remap constructor matches 504 bytes and key control flow."""
    name = "__ct__18RenderPaletteTableFP8SubObj6CiPC18RenderPaletteColorPCUc"
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(palette_table_object, name)
    assert len(actual) == size
    # Check prologue and epilogue
    orig = original_bytes(address, size)
    assert actual[:0x10] == orig[:0x10]
    assert actual[-0x14:] == orig[-0x14:]


def test_render_manager_palette_table_split_boundaries():
    """Verify slice boundaries in config.yml."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segments = config["segments"]
    index = next(i for i, seg in enumerate(segments)
                 if isinstance(seg, dict) and seg.get("name") == "render_manager_palette_table")
    segment = segments[index]
    assert (segment["start"], segment["vram"]) == (0x89660, 0x189480)
    assert segment["type"] == "code"
    assert segment["subsegments"] == [[0x89660, "asm", "render/render_manager_palette_table"]]
    assert segments[index + 1]["start"] == 0x89A10
    assert segments[index + 1]["vram"] == 0x189830


def test_render_manager_palette_table_symbols_registered():
    """Verify production symbols in symbols.txt."""
    symbols = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, (addr, size) in FUNCTIONS.items():
        pattern = rf"{re.escape(name)}\s*=\s*0x{addr:X};\s*//\s*type:func\s+size:0x{size:X}\s+absolute:True"
        assert re.search(pattern, symbols, re.MULTILINE), f"Missing symbol {name}"
