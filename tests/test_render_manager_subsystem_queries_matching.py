"""Require real instruction equality for the RenderManager subsystem queries slice."""

import re

import pytest
import yaml

from render_manager_subsystem_queries_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_queries,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def queries_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_queries(tmp_path_factory.mktemp("render-manager-subsystem-queries-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_subsystem_queries_matches_original(queries_object, name):
    """Require every original instruction byte, including relocated call targets."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(queries_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_render_manager_subsystem_queries_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_manager_subsystem_queries")
    assert (segment["start"], segment["vram"]) == (0x861E0, 0x186000)
    # Check prologue at 0x186000: j func_225560
    assert original_bytes(0x186000, 4) == bytes.fromhex("58950808")
    # Check paddings
    assert original_bytes(0x186008, 8) == bytes(8)
    assert original_bytes(0x186078, 8) == bytes(8)
    assert original_bytes(0x1860C8, 8) == bytes(8)
    assert original_bytes(0x186108, 8) == bytes(8)
    assert original_bytes(0x186144, 12) == bytes(12)
    assert original_bytes(0x186198, 8) == bytes(8)
    assert original_bytes(0x1861B4, 12) == bytes(12)
    assert original_bytes(0x1861C8, 8) == bytes(8)
    # Check next prologue at 0x1861D0: addiu $sp, $sp, -0x70
    assert original_bytes(0x1861D0, 4) == bytes.fromhex("90ffbd27")


def test_render_manager_subsystem_queries_symbols():
    """Ensure emitted slice symbols match original function boundaries."""
    text = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    for name, expected in FUNCTIONS.items():
        pattern = rf"^{name} = (0x[0-9a-fA-F]+); // type:func size:(0x[0-9a-fA-F]+)\b"
        matches = re.findall(pattern, text, re.MULTILINE)
        assert [(int(address, 16), int(size, 16)) for address, size in matches] == [expected]
