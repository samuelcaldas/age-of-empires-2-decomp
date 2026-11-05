"""Require real instruction equality for the kt_gs_step_222180 slice."""

import pytest
import yaml

from kt_gs_step_222180_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_step_222180,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_step_222180_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_step_222180(tmp_path_factory.mktemp("kt-gs-step-222180-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_step_222180_matches_original(gs_step_222180_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_step_222180_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_step_222180_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_step_222180")
    assert (segment["start"], segment["vram"]) == (0x122360, 0x222180)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_init_2222d0")
    assert post_segment["start"] == 0x1224B0

    # Verify prologue instructions in original ELF
    # func_00222180: sh $a0, -0x74B6($gp)
    assert original_bytes(0x222180, 4) == b"\x4a\x8b\x84\xa7"
    # End of func_002221A0 delay slot and padding before 0x2222D0: 12 bytes nop
    assert original_bytes(0x2222C4, 12) == b"\x00" * 12
