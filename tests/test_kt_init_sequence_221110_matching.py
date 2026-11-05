"""Require real instruction equality for the kt_init_sequence_221110 slice."""

import pytest
import yaml

from kt_init_sequence_221110_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_init_sequence_221110,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def init_sequence_221110_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_init_sequence_221110(tmp_path_factory.mktemp("kt-init-sequence-221110-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_init_sequence_221110_matches_original(init_sequence_221110_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(init_sequence_221110_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_init_sequence_221110_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_init_sequence_221110")
    assert (segment["start"], segment["vram"]) == (0x1212F0, 0x221110)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_dma_flip_221410")
    assert post_segment["start"] == 0x1215F0

    # Verify prologue instructions in original ELF
    # func_00221110: addiu $sp, $sp, -0x50; sq $ra, 0x30($sp)
    assert original_bytes(0x221110, 8) == b"\xb0\xff\xbd\x27\x30\x00\xbf\x7f"
    # End of func_00221110 padding before 0x221410: 12 bytes nop
    assert original_bytes(0x221404, 12) == b"\x00" * 12
