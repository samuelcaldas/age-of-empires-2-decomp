from pathlib import Path
import re
import subprocess


ROOT = Path(__file__).resolve().parents[1]


def test_zone_spatial_grid_setters_no_asm():
    """Ensure zero inline assembly or raw opcodes in implementation."""
    path = ROOT / "src/zone/zone_spatial_grid_setters.cpp"
    assert path.is_file(), f"Missing implementation file: {path}"
    content = path.read_text()
    assert "__asm__" not in content, "Found embedded assembly"
    assert ".word" not in content, "Found raw opcodes"
    assert re.search(r"\b(?:asm|__asm)\b", content) is None


def test_zone_spatial_grid_setters_native(tmp_path):
    """Verify behavioral correctness via native 32-bit compilation and execution."""
    executable = tmp_path / "setters-native"
    cmd = [
        "g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_setters_test.cpp",
        "src/zone/zone_spatial_grid_setters.cpp",
        "-o", str(executable)
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT)
    assert compile_res.returncode == 0, (
        f"Compilation failed: {compile_res.stderr}"
    )

    run_res = subprocess.run(
        [str(executable)], capture_output=True, text=True, cwd=ROOT,
    )
    assert run_res.returncode == 0, f"Native test failed: {run_res.stderr}"
