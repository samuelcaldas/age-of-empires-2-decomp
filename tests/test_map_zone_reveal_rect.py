"""Native regressions for map_zone_reveal_rect."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_001384C0 out-of-bounds rejection",
    "func_001384C0 tile reveal and ally notification",
]


@pytest.fixture(scope="module")
def map_zone_reveal_rect_test(tmp_path_factory):
    """Compile map_zone_reveal_rect source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("map_zone_reveal_rect regressions require g++")
    fixture = tmp_path_factory.mktemp("map-zone-reveal-rect")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "map-zone-reveal-rect-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/map_zone_reveal_rect.cpp",
            "tests/native/map_zone_reveal_rect_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_map_zone_reveal_rect_behavior(map_zone_reveal_rect_test, case):
    """Verify rectangular reveal logic and callbacks."""
    result = subprocess.run([str(map_zone_reveal_rect_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
