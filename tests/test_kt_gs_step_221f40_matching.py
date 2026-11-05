"""Require real instruction equality for the kt_gs_step_221f40 slice."""

import pytest
import yaml

from kt_gs_step_221f40_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_step_221f40,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_step_221f40_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_step_221f40(tmp_path_factory.mktemp("kt-gs-step-221f40-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_step_221f40_matches_original(gs_step_221f40_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_step_221f40_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_step_221f40_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_step_221f40")
    assert (segment["start"], segment["vram"]) == (0x122120, 0x221F40)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_step_222180")
    assert post_segment["start"] == 0x122360

    # Verify prologue instructions in original ELF
    # func_00221F40: addiu $sp, $sp, -0x180; sq $ra, 0x30($sp)
    assert original_bytes(0x221F40, 8) == b"\x80\xfe\xbd\x27\x30\x00\xbf\x7f"
    # End of func_00221F40 padding before 0x222180: 4 bytes nop
    assert original_bytes(0x22217C, 4) == b"\x00" * 4
