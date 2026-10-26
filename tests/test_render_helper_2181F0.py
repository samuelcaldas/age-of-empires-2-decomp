"""Native semantic regressions for render_helper_2181F0."""

from pathlib import Path
import re
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    (0, "self20 null returns after zeroing field38"),
    (1, "self88 zero returns before virtual dispatch"),
    (2, "zero handle calls only the begin lookup and finish slot"),
    (3, "single iteration forwards handle and second range result"),
    (4, "two iterations increment sequence and index"),
    (5, "zero iterations use the prechecked signed bound"),
    (6, "gate 8c alone routes through mode zero"),
    (7, "both priority gates route through mode one"),
    (8, "disabled gates skip the callback"),
    (9, "callback mutations refresh gates and loop bound"),
    (10, "begin slot mutation still passes fresh null to lookup"),
    (11, "callback pointer mutation is read fresh at cleanup"),
    (12, "callback bound mutation controls the next precheck"),
    (13, "sequence and index wrap as signed low sixteen bits"),
]


def test_helper_2181f0_symbol_registration():
    """Include the executed return delay slot in the unique original symbol."""
    symbols = (PROJECT_ROOT / "config/SLES-50282/symbols.txt").read_text()
    pattern = r"^func_002181F0 = (0x[0-9A-Fa-f]+); // type:func size:(0x[0-9A-Fa-f]+)\b"
    matches = re.findall(pattern, symbols, re.MULTILINE)
    assert [(int(address, 16), int(size, 16)) for address, size in matches] == [
        (0x2181F0, 0x15C)
    ]


@pytest.fixture(scope="module")
def helper_2181f0_test(tmp_path_factory):
    """Compile the production source and the native regression fixture."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("render_helper_2181F0 tests require g++")
    fixture = tmp_path_factory.mktemp("helper-2181f0")
    probe = subprocess.run(
        [compiler, "-m32", "-x", "c++", "-", "-o", str(fixture / "probe")],
        input="#include <cstddef>\nint main() { static_assert(sizeof(void *) == 4); }\n",
        capture_output=True, text=True,
    )
    if probe.returncode:
        pytest.skip(f"native 32-bit g++ unavailable: {probe.stderr.strip()}")
    sources = [
        "tests/native/render_helper_2181F0_main.cpp",
        "tests/native/render_helper_2181F0_mocks.cpp",
        "tests/native/render_helper_2181F0_basic.cpp",
        "tests/native/render_helper_2181F0_routing.cpp",
        "tests/native/render_helper_2181F0_mutations.cpp",
        "tests/native/render_helper_2181F0_wrap.cpp",
    ]
    binary = fixture / "helper-2181f0-test"
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", "src/render/render_helper_2181F0.cpp",
         *sources, "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[item[1] for item in CASES])
def test_helper_2181f0_behavior(helper_2181f0_test, case, description):
    """Run each original-derived behavior in an isolated native process."""
    result = subprocess.run(
        [str(helper_2181f0_test), str(case)], capture_output=True, text=True,
    )
    assert result.returncode == 0, f"stderr: {result.stderr}, stdout: {result.stdout}"
    assert "PASS" in result.stdout
