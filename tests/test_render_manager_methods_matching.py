"""Require exact binary match for RenderManager methods slice."""

from pathlib import Path
import pytest

from render_manager_methods_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_methods,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def methods_object(tmp_path_factory):
    """Compile render_manager_methods.cpp using authentic MWCC."""
    return compile_methods(tmp_path_factory.mktemp("render-manager-methods-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_methods_matches_original(methods_object, name):
    """Verify 100% byte-for-byte binary parity on each method."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(methods_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: expected {size} bytes, got {len(actual)}"
    assert actual == expected, f"Binary mismatch in {name}"
