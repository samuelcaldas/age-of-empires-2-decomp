"""Require real instruction equality for the kt_gs_swap_221790 slice."""

import pytest
import yaml

from kt_gs_swap_221790_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_swap_221790,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_swap_221790_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_swap_221790(tmp_path_factory.mktemp("kt-gs-swap-221790-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_swap_221790_matches_original(gs_swap_221790_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_swap_221790_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_swap_221790_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_swap_221790")
    assert (segment["start"], segment["vram"]) == (0x121970, 0x221790)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "post_221920")
    assert post_segment["start"] == 0x121B00

    # Verify prologue instructions in original ELF
    # func_00221790: addiu $sp, $sp, -0x40; sq $ra, 0x30($sp)
    assert original_bytes(0x221790, 8) == b"\xc0\xff\xbd\x27\x30\x00\xbf\x7f"
    # func_00221880: addiu $sp, $sp, -0x10; sq $ra, 0x0($sp)
    assert original_bytes(0x221880, 8) == b"\xf0\xff\xbd\x27\x00\x00\xbf\x7f"
