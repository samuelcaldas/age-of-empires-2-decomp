"""Require real instruction equality for the kt_gs_exec_221920 slice."""

import pytest
import yaml

from kt_gs_exec_221920_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_exec_221920,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_exec_221920_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_exec_221920(tmp_path_factory.mktemp("kt-gs-exec-221920-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_exec_221920_matches_original(gs_exec_221920_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_exec_221920_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_exec_221920_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_exec_221920")
    assert (segment["start"], segment["vram"]) == (0x121B00, 0x221920)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "post_221A40")
    assert post_segment["start"] == 0x121C20

    # Verify prologue instructions in original ELF
    # func_00221920: addiu $sp, $sp, -0x20; sq $ra, 0x10($sp)
    assert original_bytes(0x221920, 8) == b"\xe0\xff\xbd\x27\x10\x00\xbf\x7f"
    # End of func_00221920 padding before 0x221A40: 4 bytes nop
    assert original_bytes(0x221A3C, 4) == b"\x00" * 4
