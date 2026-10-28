"""Require real instruction equality for the kt_iop_init_220dd0 slice."""

import pytest
import yaml

from kt_iop_init_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_iop_init,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def iop_init_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_iop_init(tmp_path_factory.mktemp("kt-iop-init-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_iop_init_matches_original(iop_init_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(iop_init_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_iop_init_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_iop_init_220dd0")
    assert (segment["start"], segment["vram"]) == (0x120FB0, 0x220DD0)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "post_220F70")
    assert post_segment["start"] == 0x121150

    # Verify prologue instructions in original ELF
    # func_00220DD0: lui $v0, 0x49; addiu $a0, $v0, 0x2EE0
    assert original_bytes(0x220DD0, 8) == b"\x49\x00\x02\x3c\xe0\x2e\x44\x24"
    # func_00220E90: lui $v0, 0x39; addiu $a0, $v0, 0x2C50
    assert original_bytes(0x220E90, 8) == b"\x39\x00\x02\x3c\x50\x2c\x44\x24"
    # Padding between func_00220DD0 and func_00220E90: 8 bytes nop
    assert original_bytes(0x220E88, 8) == b"\x00" * 8
    # Padding at end of func_00220E90 up to 0x220F70: 12 bytes nop
    assert original_bytes(0x220F64, 12) == b"\x00" * 12
