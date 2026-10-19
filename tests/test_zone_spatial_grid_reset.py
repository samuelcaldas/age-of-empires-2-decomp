"""Native regression tests for func_001F2BD0 spatial grid occupant reset."""

from pathlib import Path
import subprocess

import pytest


ROOT = Path(__file__).resolve().parents[1]


def test_zone_spatial_grid_reset_no_asm():
    """Verify that zone_spatial_grid_reset.cpp contains zero assembly code."""
    source_path = ROOT / "src/zone_spatial_grid_reset.cpp"
    assert source_path.is_file(), "Source file does not exist"
    content = source_path.read_text()
    assert "__asm__" not in content, "Inline assembly detected in source"
    assert "asm(" not in content, "Inline assembly detected in source"
    assert ".word" not in content, "Raw opcode word detected in source"


def test_zone_spatial_grid_reset_native(tmp_path):
    """Verify behavioral correctness via native 32-bit compilation and execution."""
    executable = tmp_path / "reset-native"
    cmd = [
        "g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_reset_test.cpp",
        "src/zone_spatial_grid_reset.cpp",
        "-o", str(executable)
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT)
    assert compile_res.returncode == 0, (
        f"Compilation failed: {compile_res.stderr}"
    )

    run_res = subprocess.run([str(executable)], capture_output=True, text=True)
    assert run_res.returncode == 0, (
        f"Execution failed with code {run_res.returncode}: {run_res.stderr}"
    )
