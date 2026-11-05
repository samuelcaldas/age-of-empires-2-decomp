"""Require real instruction equality for the kt_gs_list_222a90 slice."""

import pytest
import yaml

from kt_gs_list_222a90_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_list_222a90,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_list_222a90_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_list_222a90(tmp_path_factory.mktemp("kt-gs-list-222a90-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_list_222a90_matches_original(gs_list_222a90_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_list_222a90_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_list_222a90_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_list_222a90")
    assert (segment["start"], segment["vram"]) == (0x122C70, 0x222A90)

    # Verify prologue instructions in original ELF
    # func_00222A90: addiu $sp, $sp, -0x20; sq $ra, 0x10($sp)
    assert original_bytes(0x222A90, 8) == b"\xe0\xff\xbd\x27\x10\x00\xbf\x7f"
    # End of func_00222C00: 8 bytes nop padding before 0x222C10
    assert original_bytes(0x222C08, 8) == b"\x00" * 8
