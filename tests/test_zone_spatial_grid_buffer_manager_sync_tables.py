"""Native semantic regressions and binary matching for zone_spatial_grid_buffer_manager_sync_tables."""

import json
from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "SpatialGridBufferManager struct layout matches required offsets"),
    ("1", "func_001ECE20 returns immediately when count <= 0"),
    ("2", "func_001ECE20 does not notify or remove when cached val matches pointer val"),
    ("3", "func_001ECE20 removes element when element lookup fails or element is null"),
    ("4", "func_001ECE20 dispatches virtual func_74 and Method118 for changed bitmask teams"),
]


@pytest.fixture(scope="module")
def buffer_manager_sync_tables_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("buffer_manager_sync_tables") / "zone-buffer-manager-sync-tables-test"
    subprocess.run(
        [
            compiler,
            "-m32",
            "-fno-builtin",
            "-Iinclude",
            "src/zone/zone_spatial_grid_buffer_manager_sync_tables.cpp",
            "tests/native/zone_spatial_grid_buffer_manager_sync_tables_test.cpp",
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
def test_buffer_manager_sync_tables_behavior(buffer_manager_sync_tables_test_binary, case, description):
    """Check buffer manager sync tables behavior in isolated native process."""
    result = subprocess.run([str(buffer_manager_sync_tables_test_binary), case], capture_output=True, text=True)
    assert result.returncode == 0, f"Case {case} failed with output: {result.stderr}"
    assert "PASS" in result.stdout


ORIGINAL = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = PROJECT_ROOT / "src/zone/zone_spatial_grid_buffer_manager_sync_tables.cpp"
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
def test_zone_spatial_grid_buffer_manager_sync_tables_matching(tmp_path):
    """Verify zone_spatial_grid_buffer_manager_sync_tables byte-for-byte binary match."""
    obj = tmp_path / "zone_spatial_grid_buffer_manager_sync_tables.o"
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
        str(PROJECT_ROOT / "build/SLES-50282/obj/zone_spatial_grid_buffer_manager_sync_tables.o"),
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
