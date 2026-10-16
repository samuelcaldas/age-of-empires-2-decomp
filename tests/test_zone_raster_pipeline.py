"""Native semantic regressions for zone raster and extent pipeline."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
PROBE_SOURCE = """
#include <cassert>
#include <cstddef>
#include <cstring>
int main() {
    static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
    static_assert(sizeof(int) == 4, "requires 32-bit integers");
}
"""

TEST_CASES = [
    ("perimeter_null_zero", "Perimeter point rejects null buffer and zero dx/dy"),
    ("perimeter_dedup_cap", "Perimeter point enforces deduplication and capacity limit"),
    ("perimeter_many", "Perimeter point accumulates many points preserving order"),
    ("serialize_zero", "Serialize writes only 8-byte header when extent count is zero"),
    ("serialize_many", "Serialize writes extent array and perimeter point buffers"),
    ("deserialize_roundtrip", "Deserialize roundtrips serialized stream and frees old buffers"),
    ("rect_update", "Rect update computes coordinates and subtracts edge masks"),
    ("raster_untag", "Raster untag clears tags inside rect preserving outside cells"),
    ("raster_trace", "Raster trace backtracks delta vectors to find origin cell"),
    ("raster_extent", "Raster extent unpacks signed delta offsets to expand bounding rect"),
]


@pytest.fixture(scope="module")
def zone_raster_test_binary(tmp_path_factory):
    """Compile production zone raster sources with the native test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-raster-test")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture_dir / "probe")],
        input=PROBE_SOURCE,
        capture_output=True,
        text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")

    binary = fixture_dir / "zone-raster-pipeline-test"
    sources = [
        "src/zone_perimeter_point.cpp",
        "src/zone_raster_serialize.cpp",
        "src/zone_raster_deserialize.cpp",
        "src/zone_rect_update.cpp",
        "src/zone_raster_untag.cpp",
        "src/zone_raster_trace.cpp",
        "src/zone_raster_extent.cpp",
        "tests/native/zone_perimeter_point_test.cpp",
        "tests/native/zone_raster_stream_test.cpp",
        "tests/native/zone_raster_spatial_test.cpp",
        "tests/native/zone_raster_test_main.cpp",
    ]
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", "-Itests/native"] + sources + ["-o", str(binary)],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", TEST_CASES, ids=[c[0] for c in TEST_CASES])
def test_zone_raster_pipeline_cases(zone_raster_test_binary, case, description):
    """Run dedicated behavioral test case on production zone raster routines."""
    result = subprocess.run(
        [str(zone_raster_test_binary), case],
        capture_output=True,
        text=True,
    )
    assert result.returncode == 0, f"{description} failed: {result.stderr}"
