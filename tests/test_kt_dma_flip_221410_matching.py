"""Require real instruction equality for the kt_dma_flip_221410 slice."""

import pytest
import yaml

from kt_dma_flip_221410_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_dma_flip_221410,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def dma_flip_221410_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_dma_flip_221410(tmp_path_factory.mktemp("kt-dma-flip-221410-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_dma_flip_221410_matches_original(dma_flip_221410_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(dma_flip_221410_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_dma_flip_221410_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_dma_flip_221410")
    assert (segment["start"], segment["vram"]) == (0x1215F0, 0x221410)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "post_221550")
    assert post_segment["start"] == 0x121730

    # Verify prologue instructions in original ELF
    # func_00221410: addiu $sp, $sp, -0x10; sq $ra, 0x0($sp)
    assert original_bytes(0x221410, 8) == b"\xf0\xff\xbd\x27\x00\x00\xbf\x7f"
    # func_00221440: addiu $sp, $sp, -0x20; sq $ra, 0x10($sp)
    assert original_bytes(0x221440, 8) == b"\xe0\xff\xbd\x27\x10\x00\xbf\x7f"
    # End of func_00221440 padding before 0x221550: 12 bytes nop
    assert original_bytes(0x221544, 12) == b"\x00" * 12
