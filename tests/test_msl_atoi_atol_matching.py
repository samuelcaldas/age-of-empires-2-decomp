"""Exact target comparisons for Metrowerks MSL atoi and atol."""

from pathlib import Path
import pytest
import network_match_support as support

ROOT = Path(__file__).resolve().parents[1]
ATOI_SOURCE = ROOT / "src/msl/atoi.c"
ATOL_SOURCE = ROOT / "src/msl/atol.c"

EXTERNALS = {
    "func_11C5F8": 0x11C5F8,
}


def test_msl_atoi_matches_original_bytes(tmp_path):
    missing = support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    original = support.verified_original_image()
    output = support.compile_object(ATOI_SOURCE, tmp_path, extra_flags=("-lang=c",))
    actual = support.relocated_function(output, "atoi", 0x114378, 40, EXTERNALS, 1)
    expected = support.original_bytes(original, 0x114378, 40)
    support.assert_exact(actual, expected, 0x114378)


def test_msl_atol_matches_original_bytes(tmp_path):
    missing = support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    original = support.verified_original_image()
    output = support.compile_object(ATOL_SOURCE, tmp_path, extra_flags=("-lang=c",))
    actual = support.relocated_function(output, "atol", 0x1143A0, 32, EXTERNALS, 1)
    expected = support.original_bytes(original, 0x1143A0, 32)
    support.assert_exact(actual, expected, 0x1143A0)
