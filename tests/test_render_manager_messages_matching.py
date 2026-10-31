"""Require exact binary match for RenderManager messages slice."""

from pathlib import Path
import pytest

from render_manager_messages_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_messages,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def messages_object(tmp_path_factory):
    """Compile render_manager_messages.cpp using authentic MWCC."""
    return compile_messages(tmp_path_factory.mktemp("render-manager-messages-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_manager_messages_matches_original(messages_object, name):
    """Verify 100% byte-for-byte binary parity on messages method."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(messages_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: expected {size} bytes, got {len(actual)}"
    assert actual == expected, f"Binary mismatch in {name}"
