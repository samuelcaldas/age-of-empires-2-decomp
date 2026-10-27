"""Require real instruction equality for the render_font_context slice."""

import pytest
import yaml

from render_font_context_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_font_context,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def font_context_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_font_context(tmp_path_factory.mktemp("render-font-context-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_font_context_matches_original(font_context_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(font_context_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_render_font_context_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_font_context")
    assert (segment["start"], segment["vram"]) == (0x1200A0, 0x21FEC0)

    post_segment = next(item for item in config["segments"] if item["name"] == "post_21FF40")
    assert post_segment["start"] == 0x120120

    # Verify prologue instructions in original ELF
    # func_0021FEC0: jr $ra; sw $a0, -0x74c4($gp)
    assert original_bytes(0x21FEC0, 8) == b"\x08\x00\xe0\x03\x3c\x8b\x84\xaf"
    # func_0021FED0: jr $ra; lw $v0, -0x74c4($gp)
    assert original_bytes(0x21FED0, 8) == b"\x08\x00\xe0\x03\x3c\x8b\x82\x8f"
    # func_0021FEE0: addiu $v0, $zero, -1
    assert original_bytes(0x21FEE0, 4) == b"\xff\xff\x02\x24"
    # End of func_0021FEE0 padding up to 0x21FF40
    assert original_bytes(0x21FF34, 12) == b"\x00" * 12
