"""Exact target comparisons for Metrowerks MSL memset."""

from pathlib import Path
import pytest
import network_match_support as support

ROOT = Path(__file__).resolve().parents[1]
MEMSET_SOURCE = ROOT / "src/msl/memset.c"


def test_msl_memset_matches_original_bytes(tmp_path):
    missing = support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    original = support.verified_original_image()
    output = support.compile_object(MEMSET_SOURCE, tmp_path, extra_flags=("-lang=c",))
    actual = support.relocated_function(output, "memset", 0x117CAC, 0xC0, {}, 0)
    expected = support.original_bytes(original, 0x117CAC, 0xC0)
    support.assert_exact(actual, expected, 0x117CAC)
