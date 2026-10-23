"""Require a complete relocation-resolved match for the join-request routine."""

from pathlib import Path
import tempfile

import pytest

import network_match_support as match


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "src/network_join_request_338fa0.cpp"
FUNCTION_NAME = "func_00338FA0"
START_ADDRESS = 0x338FA0
FUNCTION_SIZE = 0x12C
RELOCATION_COUNT = 9
EXTERNAL_SYMBOLS = {
    "func_00338350": 0x338350,
    "func_003382D0": 0x3382D0,
    "func_11B170": 0x11B170,
    "func_00335A20": 0x335A20,
    "func_117AF8": 0x117AF8,
    "func_003383B0": 0x3383B0,
}


def test_join_request_matches_every_original_byte():
    missing = match.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    image = match.verified_original_image()
    with tempfile.TemporaryDirectory() as directory:
        object_path = match.compile_object(SOURCE, directory)
        actual = match.relocated_function(
            object_path, FUNCTION_NAME, START_ADDRESS, FUNCTION_SIZE,
            EXTERNAL_SYMBOLS, RELOCATION_COUNT,
        )
    expected = match.original_bytes(image, START_ADDRESS, FUNCTION_SIZE)
    match.assert_exact(actual, expected, START_ADDRESS)
    assert match.original_bytes(image, START_ADDRESS + FUNCTION_SIZE, 4) == b"\0" * 4
