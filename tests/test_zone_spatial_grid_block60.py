import json
import os
from pathlib import Path
import subprocess
import sys

import pytest


@pytest.mark.parametrize("unit_name", [
    "zone_spatial_grid_node_pool_alloc_node",
])
def test_unverified_node_pool_units_are_incomplete(unit_name):
    """Exclude unresolved exact-matching gates from completion totals."""
    subprocess.run(
        [sys.executable, "configure.py", "--version", "SLES-50282"],
        capture_output=True, text=True, check=True,
    )
    configuration = json.loads(Path("objdiff.json").read_text())
    units = {unit["name"]: unit for unit in configuration["units"]}
    assert units[f"main/{unit_name}"]["metadata"]["complete"] is False


def test_zone_spatial_grid_block60_build():
    """Verify that Block 60 objects configure and build cleanly."""
    for f in [".ninja_log", ".ninja_deps"]:
        if os.path.exists(f):
            os.remove(f)
    cfg_res = subprocess.run(
        [sys.executable, "configure.py", "--version", "SLES-50282"],
        capture_output=True, text=True,
    )
    assert cfg_res.returncode == 0, f"configure failed: {cfg_res.stderr}"
    res = subprocess.run(["ninja"], capture_output=True, text=True)
    assert res.returncode == 0, f"ninja build failed: {res.stderr}"


def test_zone_spatial_grid_block60_no_asm():
    """Verify that decompiled source files are 100% pure C/C++
    without embedded assembly.
    """
    with open("src/zone_spatial_grid_node_pool_alloc_node.cpp", "r") as f:
        content = f.read()
    assert "__asm__" not in content, "Found embedded assembly"
    assert ".word" not in content, "Found raw opcodes"
    assert (
        "asm" not in content or "exceptions" in content
    ), "Found unexpected assembly directive"


def test_zone_spatial_grid_block60_native():
    """Verify behavioral correctness and side effects
    via native 32-bit test.
    """
    cmd = [
        "g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_block60_test.cpp",
        "src/zone_spatial_grid_node_pool_alloc_node.cpp",
        "-o", "tests/native/zone_spatial_grid_block60_test"
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True)
    assert compile_res.returncode == 0, (
        f"Compilation failed: {compile_res.stderr}"
    )

    try:
        run_res = subprocess.run(
            ["./tests/native/zone_spatial_grid_block60_test"],
            capture_output=True, text=True,
        )
        assert run_res.returncode == 0, f"Native test failed: {run_res.stderr}"
    finally:
        if os.path.exists("tests/native/zone_spatial_grid_block60_test"):
            os.remove("tests/native/zone_spatial_grid_block60_test")
