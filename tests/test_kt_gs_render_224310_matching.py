"""Require real instruction equality for the kt_gs_render_224310 slice."""

import pytest
import yaml

from kt_gs_render_224310_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_render_224310,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_render_224310_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_render_224310(tmp_path_factory.mktemp("kt-gs-render-224310-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_render_224310_matches_original(gs_render_224310_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_render_224310_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_render_224310_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_render_224310")
    assert (segment["start"], segment["vram"]) == (0x1244F0, 0x224310)

    # Verify prologue instructions in original ELF
    # func_00224310: lui at, 0xca; lw t0, 0x17e0(at)
    assert original_bytes(0x224310, 8) == b"\xca\x00\x01\x3c\xe0\x17\x28\x8c"
    # End of func_002244E0: 8 bytes nop padding before 0x224590
    assert original_bytes(0x224588, 8) == b"\x00" * 8
