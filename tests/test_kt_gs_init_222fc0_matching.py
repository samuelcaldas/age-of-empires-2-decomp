"""Require real instruction equality for the kt_gs_init_222fc0 slice."""

import pytest
import yaml

from kt_gs_init_222fc0_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_init_222fc0,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_init_222fc0_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_init_222fc0(tmp_path_factory.mktemp("kt-gs-init-222fc0-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_init_222fc0_matches_original(gs_init_222fc0_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_init_222fc0_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_init_222fc0_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_init_222fc0")
    assert (segment["start"], segment["vram"]) == (0x1231A0, 0x222FC0)

    # Verify prologue instructions in original ELF
    # func_00222FC0: lui at, 0xc9; lw a0, 0x2d44(at)
    assert original_bytes(0x222FC0, 8) == b"\xc9\x00\x01\x3c\x44\x2d\x24\x8c"
    # End of func_002230C0: 8 bytes nop padding before 0x2230D0
    assert original_bytes(0x2230C8, 8) == b"\x00" * 8
