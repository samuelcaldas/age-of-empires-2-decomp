"""Native regressions for unit_action_stream serialization, deserialization, and logging."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026AEC0 string length",
    "func_0026AE00 save and func_0026AF90 load stream dispatch",
    "func_0026B0A0 logging dispatch",
]


@pytest.fixture(scope="module")
def stream_test(tmp_path_factory):
    """Compile the actual stream source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("stream regressions require g++")
    fixture = tmp_path_factory.mktemp("action-stream")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "stream-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit_action_stream.cpp",
            "tests/native/unit_action_stream_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_stream_behavior(stream_test, case):
    """Verify serialization, string length calculations, and logging dispatch."""
    result = subprocess.run([str(stream_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
