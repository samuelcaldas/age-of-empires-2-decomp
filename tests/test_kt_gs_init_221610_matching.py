"""Require real instruction equality for the kt_gs_init_221610 slice."""

import pytest
import yaml

from kt_gs_init_221610_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_init_221610,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_init_221610_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_init_221610(tmp_path_factory.mktemp("kt-gs-init-221610-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_init_221610_matches_original(gs_init_221610_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_init_221610_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_init_221610_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_init_221610")
    assert (segment["start"], segment["vram"]) == (0x1217F0, 0x221610)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "post_221790")
    assert post_segment["start"] == 0x121970

    # Verify prologue instructions in original ELF
    # func_00221610: lui $v0, 0xC8; addiu $a2, $v0, 0x2510
    assert original_bytes(0x221610, 8) == b"\xc8\x00\x02\x3c\x10\x25\x46\x24"
    # func_00221630: addiu $sp, $sp, -0x30; addiu $a1, $zero, 1
    assert original_bytes(0x221630, 8) == b"\xd0\xff\xbd\x27\x01\x00\x05\x24"
    # End of func_00221630 padding before 0x221790: 8 bytes nop
    assert original_bytes(0x221788, 8) == b"\x00" * 8
