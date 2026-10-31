"""Native semantic regressions and binary matching for zone_spatial_grid_reset_query_state."""

import json
from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "SpatialGridState struct layout matches required offsets"),
    ("1", "func_001ED160 correctly mutates field_12B5B0 and field_12B574 around func_001ED1F0 call"),
]


@pytest.fixture(scope="module")
def reset_query_state_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("reset_query_state") / "zone-reset-query-state-test"
    subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            "-Iinclude",
            "src/zone/zone_spatial_grid_reset_query_state.cpp",
            "tests/native/zone_spatial_grid_reset_query_state_test.cpp",
            "-o",
            str(binary),
        ],
        cwd=PROJECT_ROOT,
        check=True,
        capture_output=True,
        text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_reset_query_state_behavior(reset_query_state_test_binary, case, description):
    """Check reset query state behavior in isolated native process."""
    result = subprocess.run([str(reset_query_state_test_binary), case], capture_output=True, text=True)
    assert result.returncode == 0, f"Case {case} failed with output: {result.stderr}"
    assert "PASS" in result.stdout


ORIGINAL = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = PROJECT_ROOT / "src/zone/zone_spatial_grid_reset_query_state.cpp"
COMPILER = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = PROJECT_ROOT / "build/tools/wibo"
BINUTILS = PROJECT_ROOT / "build/mips_binutils"

REQUIRED_FILES = (
    ORIGINAL,
    COMPILER,
    WRAPPER,
    BINUTILS / "mips-linux-gnu-ld",
    BINUTILS / "mips-linux-gnu-objcopy",
)


@pytest.mark.skipif(
    any(not path.is_file() for path in REQUIRED_FILES),
    reason="original binary, licensed compiler, or binutils not available",
)
def test_zone_spatial_grid_reset_query_state_matching(tmp_path):
    """Verify zone_spatial_grid_reset_query_state byte-for-byte binary match."""
    obj = tmp_path / "zone_spatial_grid_reset_query_state.o"
    subprocess.run(
        [
            str(WRAPPER),
            str(COMPILER),
            "-c",
            str(SOURCE),
            "-o",
            str(obj),
            "-O3",
            "-inline",
            "on",
            "-msext",
            "on",
            "-char",
            "signed",
            "-sym",
            "off",
            "-Iinclude",
        ],
        check=True,
        capture_output=True,
    )

    diff_cmd = [
        str(PROJECT_ROOT / "build/tools/objdiff-cli"),
        "diff",
        "-1",
        str(PROJECT_ROOT / "build/SLES-50282/obj/zone_spatial_grid_reset_query_state.o"),
        "-2",
        str(obj),
        "-o",
        "-",
    ]
    res = subprocess.run(diff_cmd, capture_output=True, text=True, check=True)
    d = json.loads(res.stdout)
    s = [x for x in d["right"]["symbols"] if "instructions" in x][0]
    pct = s.get("match_percent")
    assert pct == 100.0, f"Expected 100.0% match, got {pct}%"
