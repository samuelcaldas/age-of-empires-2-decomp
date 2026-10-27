"""Require all palette-blend instruction bytes and complete production boundaries."""

import re

import pytest
import yaml

from render_manager_palette_blend_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_palette_blend,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def palette_blend_object(tmp_path_factory):
    """Compile current production source rather than trusting a cached object."""
    return compile_palette_blend(tmp_path_factory.mktemp("render-manager-palette-blend-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_palette_blend_matches_original(palette_blend_object, name):
    """Catch any missing instruction, changed register, or altered delay slot."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(palette_blend_object, name)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == original_bytes(address, size), f"Instruction mismatch in {name}"


def test_render_manager_palette_blend_split_boundaries():
    """Catch truncated return delay slots and overlap with the next function."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segments = config["segments"]
    index = next(index for index, segment in enumerate(segments)
                 if isinstance(segment, dict) and segment.get("name") == "render_manager_palette_blend")
    segment = segments[index]
    assert (segment["start"], segment["vram"]) == (0x89440, 0x189260)
    assert segment["type"] == "code"
    assert segment["subsegments"] == [[0x89440, "asm", "render/render_manager_palette_blend"]]
    assert segments[index + 1]["start"] == 0x89660
    assert segments[index + 1]["vram"] == 0x189480
    assert original_bytes(0x189260, 4) == bytes.fromhex("70ffbd27")
    assert original_bytes(0x189478, 8) == bytes.fromhex("0800e0039000bd27")


def test_render_manager_palette_blend_symbol_registered():
    """Catch an incorrect production address or function size."""
    symbols = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    pattern = r"^func_00189260\s*=\s*0x189260;\s*//\s*type:func\s+size:0x220\s+absolute:True\s*$"
    assert re.search(pattern, symbols, re.MULTILINE), "Missing or invalid palette symbol"
