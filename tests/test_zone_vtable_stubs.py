"""Native regressions for zone_vtable_stubs."""

from pathlib import Path
import shutil
import subprocess

import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("stubs", "Verifies no-op and setter stubs on zone layout"),
    ("dispatch", "Verifies sequence calls in func_001C97D0"),
]

@pytest.fixture(scope="module")
def zone_vtable_stubs_test_binary(tmp_path_factory):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    fixture_dir = tmp_path_factory.mktemp("zone-stubs-test")
    binary = fixture_dir / "zone-stubs-test"
    subprocess.run(
        [
            compiler, "-m32", "-std=c++98", "-Iinclude",
            "src/zone/zone_vtable_stubs.cpp",
            "tests/native/zone_vtable_stubs_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary

@pytest.mark.parametrize("case_id,desc", CASES, ids=[c[0] for c in CASES])
def test_zone_vtable_stubs(zone_vtable_stubs_test_binary, case_id, desc):
    res = subprocess.run([str(zone_vtable_stubs_test_binary), case_id], capture_output=True, text=True)
    assert res.returncode == 0
    assert f"PASS {case_id}" in res.stdout
