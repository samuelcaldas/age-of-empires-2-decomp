"""Native regressions for unit_action_properties."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_00267750 case 0 recalculates m_field30",
    "func_00267750 case 1 dispatches Method62 and Method61 when active",
    "func_00267750 case 21 dispatches Method7C on world sub1b30",
    "func_002678A0 case 0 updates m_field30 with offset",
    "func_002678A0 case 1 dispatches Method62 and Method61 with sum",
    "func_002679A0 case 0 updates m_field30 with product",
    "func_002679A0 case 1 dispatches Method62 and Method61 with product",
]


@pytest.fixture(scope="module")
def properties_test(tmp_path_factory):
    """Compile the actual unit_action_properties source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("unit_action_properties regressions require g++")
    fixture = tmp_path_factory.mktemp("action-properties")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "action-properties-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_properties.cpp",
            "tests/native/unit_action_properties_test.cpp",
            "-o", str(binary)
        ],
        cwd=Path.cwd(), check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_properties_behavior(properties_test, case):
    """Verify property dispatch and arithmetic operations."""
    result = subprocess.run([str(properties_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
