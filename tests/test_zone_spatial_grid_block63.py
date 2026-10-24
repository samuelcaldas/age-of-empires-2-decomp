from pathlib import Path
import re
import subprocess


def test_zone_spatial_grid_block63_no_asm():
    """Verify that decompiled source files are 100% pure C/C++
    without embedded assembly.
    """
    path = Path("src/zone/zone_spatial_grid_destructor.cpp")
    content = path.read_text()
    assert "__asm__" not in content, "Found embedded assembly"
    assert ".word" not in content, "Found raw opcodes"
    assert re.search(r"\b(?:asm|__asm)\b", content) is None


def test_zone_spatial_grid_block63_native(tmp_path):
    """Verify behavioral correctness and side effects
    via native 32-bit test.
    """
    executable = tmp_path / "block63-native"
    cmd = [
        "g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_block63_test.cpp",
        "src/zone/zone_spatial_grid_destructor.cpp",
        "-o", str(executable)
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True)
    assert compile_res.returncode == 0, (
        f"Compilation failed: {compile_res.stderr}"
    )

    run_res = subprocess.run(
        [str(executable)], capture_output=True, text=True,
    )
    assert run_res.returncode == 0, f"Native test failed: {run_res.stderr}"
