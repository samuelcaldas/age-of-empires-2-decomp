"""Require real instruction equality for the render_font_lookup slice."""

import pytest
import yaml

from render_font_lookup_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_font_lookup,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def font_lookup_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_font_lookup(tmp_path_factory.mktemp("render-font-lookup-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_render_font_lookup_matches_original(font_lookup_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(font_lookup_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_render_font_lookup_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "render_font_lookup")
    assert (segment["start"], segment["vram"]) == (0x120120, 0x21FF40)

    post_segment = next(item for item in config["segments"] if item["name"] == "post_21FF60")
    assert post_segment["start"] == 0x120140

    # Verify prologue instructions in original ELF
    # func_0021FF40: lui $v0, 0x48; addiu $v0, $v0, -0x4218
    assert original_bytes(0x21FF40, 8) == b"\x48\x00\x02\x3c\xe8\xbd\x42\x24"
    # End of func_0021FF40 padding up to 0x21FF60
    assert original_bytes(0x21FF58, 8) == b"\x00" * 8
