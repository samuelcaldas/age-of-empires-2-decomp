"""Require exact binary match for RenderManager query slice."""

from pathlib import Path
import pytest

from render_manager_query_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_query,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def query_object(tmp_path_factory):
    """Compile render_manager_query.cpp using authentic MWCC."""
    return compile_query(tmp_path_factory.mktemp("render-manager-query-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_query_matches_original(query_object, name):
    """Verify 100% byte-for-byte binary parity on each query method."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(query_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: expected {size} bytes, got {len(actual)}"
    assert actual == expected, f"Binary mismatch in {name}"
