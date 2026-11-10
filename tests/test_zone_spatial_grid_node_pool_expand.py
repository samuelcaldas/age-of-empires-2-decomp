import os
import subprocess
from pathlib import Path
import pytest

REPO_ROOT = Path(__file__).resolve().parent.parent

def test_zone_spatial_grid_node_pool_expand_native():
    cpp_src = REPO_ROOT / "tests" / "native" / "zone_spatial_grid_node_pool_expand_test.cpp"
    bin_path = REPO_ROOT / "tests" / "native" / "zone_spatial_grid_node_pool_expand_test"

    cmd_compile = [
        "g++", "-m32", "-O2",
        "-I", str(REPO_ROOT / "include"),
        str(cpp_src),
        "-o", str(bin_path)
    ]
    res_compile = subprocess.run(cmd_compile, capture_output=True, text=True)
    assert res_compile.returncode == 0, f"Compilation failed: {res_compile.stderr}"

    try:
        res_run = subprocess.run([str(bin_path)], capture_output=True, text=True)
        assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
        assert "zone_spatial_grid_node_pool_expand_test passed" in res_run.stdout
    finally:
        if bin_path.exists():
            bin_path.unlink()
