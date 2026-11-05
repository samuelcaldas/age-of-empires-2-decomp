"""Require real instruction equality for the kt_worker_thread_2209b0 slice."""

import pytest
import yaml

from kt_worker_thread_2209b0_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_worker_thread_2209b0,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def worker_thread_2209b0_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_worker_thread_2209b0(tmp_path_factory.mktemp("kt-worker-thread-2209b0-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_worker_thread_2209b0_matches_original(worker_thread_2209b0_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(worker_thread_2209b0_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_worker_thread_2209b0_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_worker_thread_2209b0")
    assert (segment["start"], segment["vram"]) == (0x120B90, 0x2209B0)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_thread_spawn_220ba0")
    assert post_segment["start"] == 0x120D80

    # Verify prologue instructions in original ELF
    # func_002209B0: addiu $sp, $sp, -0x60; sq $ra, 0x50($sp)
    assert original_bytes(0x2209B0, 8) == b"\xa0\xff\xbd\x27\x50\x00\xbf\x7f"
