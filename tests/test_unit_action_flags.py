"""Native regressions for unit_action_flags bitfield manipulation, guards, and getters."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    "func_0026AD80 returns 0.0f (100% exact match)",
    "func_26AD20/30/60 bitfield flag testing, setting, and clearing",
    "func_0026AC40 guard and func_0026AD10 forwarder",
]


@pytest.fixture(scope="module")
def flags_test(tmp_path_factory):
    """Compile the actual flags source with 32-bit native test doubles."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("flags regressions require g++")
    fixture = tmp_path_factory.mktemp("action-flags")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input=("#include <cassert>\n#include <climits>\n#include <cstddef>\n"
               "#include <cstdio>\nint main() { static_assert(sizeof(void *) == 4); }\n"),
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    binary = fixture / "flags-test"
    subprocess.run(
        [
            compiler, "-m32", "-Wno-invalid-offsetof",
            "-Iinclude",
            "src/unit/unit_action_flags.cpp",
            "tests/native/unit_action_flags_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case", range(len(CASES)), ids=CASES)
def test_flags_behavior(flags_test, case):
    """Verify bitfield flag testing, setting, clearing, and state guards."""
    result = subprocess.run([str(flags_test), str(case)], capture_output=True, text=True)
    assert result.returncode == 0, f"case {case}: {result.stderr}"
