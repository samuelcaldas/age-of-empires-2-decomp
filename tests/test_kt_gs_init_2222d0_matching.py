"""Require real instruction equality for the kt_gs_init_2222d0 slice."""

import pytest
import yaml

from kt_gs_init_2222d0_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_init_2222d0,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_init_2222d0_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_init_2222d0(tmp_path_factory.mktemp("kt-gs-init-2222d0-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_init_2222d0_matches_original(gs_init_2222d0_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_init_2222d0_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_init_2222d0_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_init_2222d0")
    assert (segment["start"], segment["vram"]) == (0x1224B0, 0x2222D0)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "post_222370")
    assert post_segment["start"] == 0x122550

    # Verify prologue instructions in original ELF
    # func_002222D0: lui $v0, 0xC9
    assert original_bytes(0x2222D0, 4) == b"\xc9\x00\x02\x3c"
    # End of func_00222310 padding before 0x222370: 12 bytes nop
    assert original_bytes(0x222364, 12) == b"\x00" * 12
