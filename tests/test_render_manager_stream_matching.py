"""Require real instruction equality for the corrected RenderManager stream slice."""

import re

import pytest
import yaml

from render_manager_stream_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_stream,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def stream_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_stream(tmp_path_factory.mktemp("render-manager-stream-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_stream_matches_original(stream_object, name):
    """Require every original instruction byte, including relocated call targets."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(stream_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_render_manager_stream_split_preserves_adjacent_prologue():
    """Check the slicer's loaded address against the actual ELF function boundary."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_stream")
    assert (segment["start"], segment["vram"]) == (0x850B0, 0x184ED0)
    assert original_bytes(segment["vram"], 4) == bytes.fromhex("b0ffbd27")
    assert original_bytes(0x184EC8, 8) == bytes(8)
    assert original_bytes(0x184FAC, 4) == bytes(4)
    assert original_bytes(0x184FFC, 4) == bytes(4)


def test_render_manager_stream_symbols_exclude_padding():
    """Ensure emitted slice symbols use bounded original entries and instruction sizes."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    functions = {"func_00184ce0": (0x184CE0, 0x1E8), **FUNCTIONS}
    for name, expected in functions.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
