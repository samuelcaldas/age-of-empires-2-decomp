import os
import subprocess
import pytest
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent

def test_zone_spatial_grid_scan_occupants_behavior(tmp_path):
    compiler = "g++"
    binary = tmp_path / "test_bin"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "tests/native/zone_spatial_grid_scan_occupants_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True
    )
    result = subprocess.run([str(binary)], cwd=PROJECT_ROOT, check=True, capture_output=True, text=True)
    assert "zone_spatial_grid_scan_occupants_test passed" in result.stdout
