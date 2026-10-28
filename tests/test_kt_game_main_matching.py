"""Require real instruction equality for the kt_game_main_220530 slice."""

import pytest
import yaml

from kt_game_main_matching_support import (
    FUNCTIONS,
    PROJECT_ROOT,
    compile_game_main,
    compiled_bytes,
    original_bytes,
    require_original,
)


@pytest.fixture(scope="module")
def game_main_object(tmp_path_factory):
    """Compile source afresh so a stale build cannot satisfy matching checks."""
    return compile_game_main(tmp_path_factory.mktemp("kt-game-main-matching"))


@pytest.mark.parametrize("name", FUNCTIONS)
def test_kt_game_main_matches_original(game_main_object, name):
    """Require every original instruction byte, including relocated operands."""
    address, size = FUNCTIONS[name]
    actual = compiled_bytes(game_main_object, name)
    expected = original_bytes(address, size)
    assert len(actual) == size, f"{name}: original {size}, compiled {len(actual)} bytes"
    assert actual == expected, f"Relocated instruction mismatch in {name}"


def test_kt_game_main_split_boundaries():
    """Check the slicer's loaded address and boundary against actual ELF bytes."""
    require_original()
    config = yaml.safe_load((PROJECT_ROOT / "config/SLES-50282/config.yml").read_text())
    segment = next(item for item in config["segments"] if item["name"] == "kt_game_main_220530")
    assert (segment["start"], segment["vram"]) == (0x120710, 0x220530)

    post_segment = next(item for item in config["segments"] if item["name"] == "post_2205E0")
    assert post_segment["start"] == 0x1207C0

    # Verify prologue instructions in original ELF
    # func_00220530: addiu $sp, $sp, -0x10; sq $ra, 0x0($sp)
    assert original_bytes(0x220530, 8) == b"\xf0\xff\xbd\x27\x00\x00\xbf\x7f"
    # End of func_00220530 padding before func_002205E0 (16 bytes padding)
    assert original_bytes(0x2205D0, 16) == b"\x00" * 16
