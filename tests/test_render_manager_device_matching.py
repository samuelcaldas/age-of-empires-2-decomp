"""Require real instruction equality for the RenderManager device slice."""

import re

import pytest
import yaml

from render_manager_device_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_device,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def device_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_device(tmp_path_factory.mktemp("render-manager-device-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_device_matches_original(device_object, name):
    """Require every original instruction byte, including relocated call targets."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(device_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_render_manager_device_split_boundaries():
    """Check the slicer's loaded address and padding against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_device")
    assert (segment["start"], segment["vram"]) == (0x85210, 0x185030)
    assert original_bytes(0x185058, 8) == bytes(8)
    assert original_bytes(0x1850C8, 8) == bytes(8)
    assert original_bytes(0x185158, 8) == bytes(8)


def test_render_manager_device_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
