"""Exact target comparisons for Metrowerks MSL strcpy, strcmp, and strcat."""

from pathlib import Path
import pytest
import network_match_support as support

ROOT = Path(__file__).resolve().parents[1]
STRCPY_SOURCE = ROOT / "src/msl/strcpy.c"
STRCMP_SOURCE = ROOT / "src/msl/strcmp.c"
STRCAT_SOURCE = ROOT / "src/msl/strcat.c"

EXTERNALS = {
    "strcpy": 0x11ABBC,
}


def test_msl_strcpy_matches_original_bytes(tmp_path):
    missing = support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    original = support.verified_original_image()
    output = support.compile_object(STRCPY_SOURCE, tmp_path, extra_flags=("-lang=c",))
    actual = support.relocated_function(output, "strcpy", 0x11ABBC, 276, {}, 0)
    expected = support.original_bytes(original, 0x11ABBC, 276)
    support.assert_exact(actual, expected, 0x11ABBC)


def test_msl_strcmp_matches_original_bytes(tmp_path):
    missing = support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    original = support.verified_original_image()
    output = support.compile_object(STRCMP_SOURCE, tmp_path, extra_flags=("-lang=c",))
    actual = support.relocated_function(output, "strcmp", 0x11AA78, 324, {}, 0)
    expected = support.original_bytes(original, 0x11AA78, 324)
    support.assert_exact(actual, expected, 0x11AA78)


def test_msl_strcat_matches_original_bytes(tmp_path):
    missing = support.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    original = support.verified_original_image()
    output = support.compile_object(STRCAT_SOURCE, tmp_path, extra_flags=("-lang=c",))
    actual = support.relocated_function(output, "strcat", 0x11A7BC, 300, EXTERNALS, 1)
    expected = support.original_bytes(original, 0x11A7BC, 300)
    support.assert_exact(actual, expected, 0x11A7BC)
