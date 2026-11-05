"""Require real instruction equality for the kt_gs_packet_221c30 slice."""

import pytest
import yaml

from kt_gs_packet_221c30_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_gs_packet_221c30,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def gs_packet_221c30_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_gs_packet_221c30(tmp_path_factory.mktemp("kt-gs-packet-221c30-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_gs_packet_221c30_matches_original(gs_packet_221c30_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(gs_packet_221c30_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_gs_packet_221c30_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_packet_221c30")
    assert (segment["start"], segment["vram"]) == (0x121E10, 0x221C30)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_texture_221d10")
    assert post_segment["start"] == 0x121EF0

    # Verify prologue instructions in original ELF
    # func_00221C30: addiu $a2, $zero, 1; mtsab $a1, 0
    assert original_bytes(0x221C30, 8) == b"\x01\x00\x06\x24\x28\x46\xa0\x70"
    # End of func_00221CF0 padding before 0x221D10: 12 bytes nop
    assert original_bytes(0x221D04, 12) == b"\x00" * 12
