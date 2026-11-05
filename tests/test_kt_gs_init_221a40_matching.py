"""Require real instruction equality for the kt_gs_init_221a40 slice."""

import pytest
import yaml

from kt_gs_init_221a40_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_init_221a40,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_init_221a40_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_init_221a40(tmp_path_factory.mktemp("kt-gs-init-221a40-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_init_221a40_matches_original(gs_init_221a40_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_init_221a40_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_init_221a40_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_init_221a40")
    assert (segment["start"], segment["vram"]) == (0x121C20, 0x221A40)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "post_221B60")
    assert post_segment["start"] == 0x121D40

    # Verify prologue instructions in original ELF
    # func_00221A40: addiu $sp, $sp, -0x10; sq $ra, 0($sp)
    assert original_bytes(0x221A40, 8) == b"\xf0\xff\xbd\x27\x00\x00\xbf\x7f"
    # End of func_00221AC0 padding before 0x221B60: 12 bytes nop
    assert original_bytes(0x221B54, 12) == b"\x00" * 12
