import os
import subprocess
import pytest
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent

def test_unit_action_spatial_behavior(tmp_path):
    compiler = "g++"
    binary = tmp_path / "test_bin"
    subprocess.run(
        [
            compiler, "-m32", "-fno-builtin", "-Iinclude",
            "tests/native/unit_action_spatial_test.cpp",
            "-o", str(binary)
        ],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True
    )
    result = subprocess.run([str(binary)], cwd=PROJECT_ROOT, check=True, capture_output=True, text=True)
    assert "unit_action_spatial_test passed" in result.stdout
