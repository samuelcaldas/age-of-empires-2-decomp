"""Behavioral tests for zone_spatial_grid_vector_purge_inactive_elements."""
import shutil
import subprocess
from pathlib import Path
import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]

def test_vector_purge_inactive_elements_behavior(tmp_path):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path / "test_bin"
    subprocess.run(
        [
            compiler, "-fno-builtin", "-Iinclude",
            "src/zone/zone_spatial_grid_vector_purge_inactive_elements.cpp",
            "tests/native/zone_spatial_grid_vector_purge_inactive_elements_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True
    )
    res = subprocess.run([str(binary)], cwd=PROJECT_ROOT, check=True, capture_output=True, text=True)
    assert "All tests passed!" in res.stdout
