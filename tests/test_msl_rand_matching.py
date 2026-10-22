"""Exact target comparisons for Metrowerks MSL srand and rand."""

from pathlib import Path
import pytest
import network_match_support as support

ROOT = Path(__file__).resolve().parents[1]
SRAND_SOURCE = ROOT / "src/msl/srand.c"
RAND_SOURCE = ROOT / "src/msl/rand.c"


def test_msl_srand_matches_original_bytes(tmp_path):
    missing = support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    original = support.verified_original_image()
    output = support.compile_object(SRAND_SOURCE, tmp_path, extra_flags=("-lang=c",))
    actual = support.relocated_function(output, "srand", 0x119858, 16, {}, 0)
    expected = support.original_bytes(original, 0x119858, 16)
    support.assert_exact(actual, expected, 0x119858)


def test_msl_rand_matches_original_bytes(tmp_path):
    missing = support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    original = support.verified_original_image()
    output = support.compile_object(RAND_SOURCE, tmp_path, extra_flags=("-lang=c",))
    actual = support.relocated_function(output, "rand", 0x119868, 48, {}, 0)
    expected = support.original_bytes(original, 0x119868, 48)
    support.assert_exact(actual, expected, 0x119868)
