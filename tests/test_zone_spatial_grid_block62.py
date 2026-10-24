from pathlib import Path
import subprocess


def test_zone_spatial_grid_block62_no_asm():
    """Verify that decompiled source files are 100% pure C/C++
    without embedded assembly.
    """
    path = Path("src/zone/zone_spatial_grid_constructor.cpp")
    content = path.read_text()
    assert "__asm__" not in content, "Found embedded assembly"
    assert ".word" not in content, "Found raw opcodes"
    assert (
        "asm" not in content or "exceptions" in content
    ), "Found unexpected assembly directive"


def test_zone_spatial_grid_block62_native():
    """Verify behavioral correctness and side effects
    via native 32-bit test.
    """
    cmd = [
        "g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
        "tests/native/zone_spatial_grid_block62_test.cpp",
        "src/zone/zone_spatial_grid_constructor.cpp",
        "-o", "tests/native/zone_spatial_grid_block62_test"
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True)
    assert compile_res.returncode == 0, (
        f"Compilation failed: {compile_res.stderr}"
    )

    try:
        run_res = subprocess.run(
            ["./tests/native/zone_spatial_grid_block62_test"],
            capture_output=True, text=True,
        )
        assert run_res.returncode == 0, f"Native test failed: {run_res.stderr}"
    finally:
        bin_path = Path("tests/native/zone_spatial_grid_block62_test")
        if bin_path.exists():
            bin_path.unlink()
