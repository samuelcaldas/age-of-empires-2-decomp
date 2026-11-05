"""Require real instruction equality for the kt_game_thread_spawn_2205e0 slice."""

import pytest
import yaml

from kt_game_thread_spawn_2205e0_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_game_thread_spawn_2205e0,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def game_thread_spawn_2205e0_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_game_thread_spawn_2205e0(tmp_path_factory.mktemp("kt-game-thread-spawn-2205e0-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_game_thread_spawn_2205e0_matches_original(game_thread_spawn_2205e0_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(game_thread_spawn_2205e0_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_game_thread_spawn_2205e0_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_game_thread_spawn_2205e0")
    assert (segment["start"], segment["vram"]) == (0x1207C0, 0x2205E0)

    post_segment = next(item for item in config["segments"] if isinstance(item, dict) and item.get("name") == "kt_game_loop_2206a0")
    assert post_segment["start"] == 0x120880

    # Verify prologue instructions in original ELF
    # func_002205E0: addiu $sp, $sp, -0x40; sq $ra, 0x20($sp)
    assert original_bytes(0x2205E0, 8) == b"\xc0\xff\xbd\x27\x20\x00\xbf\x7f"
    # End of func_002205E0 padding before func_002206A0: 12 bytes nop
    assert original_bytes(0x220694, 12) == b"\x00" * 12
