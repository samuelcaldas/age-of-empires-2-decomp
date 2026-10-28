"""Require real instruction equality for the kt_game_loop_2206a0 slice."""

import pytest
import yaml

from kt_game_loop_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_game_loop,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def game_loop_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_game_loop(tmp_path_factory.mktemp("kt-game-loop-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_game_loop_matches_original(game_loop_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(game_loop_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_game_loop_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "kt_game_loop_2206a0")
    assert (segment["start"], segment["vram"]) == (0x120880, 0x2206A0)

    post_segment = next(item for item in config["segments"] if item["name"] == "post_2207B0")
    assert post_segment["start"] == 0x120990

    # Verify prologue instructions in original ELF
    # func_002206A0: addiu $sp, $sp, -0x10; sq $ra, 0x0($sp)
    assert original_bytes(0x2206A0, 8) == b"\xf0\xff\xbd\x27\x00\x00\xbf\x7f"
    # End of func_002206A0: loop back instruction: b 0x2206F0; nop
    assert original_bytes(0x2207A8, 8) == b"\xd1\xff\x00\x10\x00\x00\x00\x00"
