"""Require real instruction equality for the kt_sema_poll_2204d0 slice."""

import pytest
import yaml

from kt_sema_poll_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_sema_poll,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def sema_poll_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_sema_poll(tmp_path_factory.mktemp("kt-sema-poll-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_sema_poll_matches_original(sema_poll_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(sema_poll_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_sema_poll_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "kt_sema_poll_2204d0")
    assert (segment["start"], segment["vram"]) == (0x1206B0, 0x2204D0)

    post_segment = next(item for item in config["segments"] if item["name"] == "post_220530")
    assert post_segment["start"] == 0x120710

    # Verify prologue instructions in original ELF
    # func_002204D0: j func_2204E0; nop
    assert original_bytes(0x2204D0, 8) == b"\x38\x81\x08\x08\x00\x00\x00\x00"
    # func_002204E0: addiu $sp, $sp, -0x30; sq $ra, 0x20($sp)
    assert original_bytes(0x2204E0, 8) == b"\xd0\xff\xbd\x27\x20\x00\xbf\x7f"
    # End of func_002204D0 padding before func_002204E0
    assert original_bytes(0x2204D8, 8) == b"\x00" * 8
    # End of func_002204E0 padding up to 0x220530
    assert original_bytes(0x220528, 8) == b"\x00" * 8
