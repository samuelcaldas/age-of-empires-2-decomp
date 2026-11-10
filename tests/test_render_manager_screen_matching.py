"""Require exact binary match for RenderManager screen slice."""

from pathlib import Path
import pytest

from render_manager_screen_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_screen,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def screen_object(tmp_path_factory):
    """Compile render_manager_screen.cpp using authentic MWCC."""
    return compile_screen(tmp_path_factory.mktemp("render-manager-screen-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_screen_matches_original(screen_object, name):
    """Verify 100% byte-for-byte binary parity on func_001847C0."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(screen_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: expected {size} bytes, got {len(actual)}"
    assert actual == expected, f"Binary mismatch in {name}"
