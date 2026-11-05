"""Require real instruction equality for the kt_draw_sync_221550 slice."""

import pytest
import yaml

from kt_draw_sync_221550_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_draw_sync_221550,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def draw_sync_221550_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_draw_sync_221550(tmp_path_factory.mktemp("kt-draw-sync-221550-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_draw_sync_221550_matches_original(draw_sync_221550_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(draw_sync_221550_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_draw_sync_221550_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_draw_sync_221550")
    assert (segment["start"], segment["vram"]) == (0x121730, 0x221550)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_gs_init_221610")
    assert post_segment["start"] == 0x1217F0

    # Verify prologue instructions in original ELF
    # func_00221550: addiu $sp, $sp, -0x30; sq $ra, 0x20($sp)
    assert original_bytes(0x221550, 8) == b"\xd0\xff\xbd\x27\x20\x00\xbf\x7f"
    # func_002215D0: lui $v0, 0x1D9; ori $v1, $v0, 0x8000
    assert original_bytes(0x2215D0, 8) == b"\xd9\x01\x02\x3c\x00\x80\x43\x34"
    # End of func_002215D0 padding before 0x221610: 8 bytes nop
    assert original_bytes(0x221608, 8) == b"\x00" * 8
