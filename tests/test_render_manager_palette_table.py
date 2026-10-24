"""Native behavioral fixtures for render_manager_palette_table."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "stream constructor with field_0 non-10 zeroes remainder and leaves table NULL",
    "stream constructor with field_0 equal to 10 allocates and populates table",
    "remap constructor with direct palette generates 256-entry lookup map",
    "remap constructor with SubObj6C unpacks palette and populates lookup map",
    "remap constructor with NULL color defaults to black and cleans up on delete",
]


@pytest.fixture(scope="module")
def render_manager_palette_table_test(tmp_path_factory):
    """Compile production source and native fixtures as 32-bit binary."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_manager_palette_table regressions require g++")
    fixture = tmp_path_factory.mktemp("render-manager-palette-table")
    probe_binary = fixture / "probe"
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(probe_binary)],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    probe_run = subprocess.run([str(probe_binary)], capture_output=True, text=True)
    if probe_run.returncode:
        pytest.skip(f"native 32-bit g++ probe failed: {probe_run.stderr.strip()}")
    binary = fixture / "render-manager-palette-table-test"
    compilation = subprocess.run(
        [
            compiler, "-m32", "-Iinclude",
            "src/render/render_manager_palette_table.cpp",
            "src/render/render_manager_palette_blend.cpp",
            "tests/native/render_manager_palette_table_test.cpp",
            "-o", str(binary),
        ],
        cwd=PROJECT_ROOT, capture_output=True, text=True,
    )
    assert compilation.returncode == 0, (
        "production palette_table compilation failed after 32-bit probe passed:\n"
        + compilation.stderr
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_render_manager_palette_table_behavior(render_manager_palette_table_test, case):
    """Run one numbered palette_table behavioral fixture."""
    result = subprocess.run(
        [str(render_manager_palette_table_test), str(case)],
        capture_output=True, text=True,
    )
    assert result.returncode == 0, f"case {case}: {result.stderr}"
