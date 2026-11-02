"""Behavioral tests for zone_spatial_grid_free_node_buffer."""
import shutil
import subprocess
from pathlib import Path
import pytest

PROJECT_ROOT = Path(__file__).resolve().parents[1]

def test_free_node_buffer_behavior(tmp_path):
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path / "test_bin"
    subprocess.run(
        [
            compiler, "-fno-builtin", "-Iinclude",
            "src/zone/zone_spatial_grid_free_node_buffer.cpp",
            "tests/native/zone_spatial_grid_free_node_buffer_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True
    )
    res = subprocess.run([str(binary)], cwd=PROJECT_ROOT, check=True, capture_output=True, text=True)
    assert "All tests passed!" in res.stdout
