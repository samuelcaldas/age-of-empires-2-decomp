import subprocess
from pathlib import Path

def test_zone_spatial_pyramid_search_step_native():
    repo_root = Path(__file__).resolve().parent.parent
    src_file = repo_root / "src" / "zone_spatial_pyramid_search_step.cpp"
    test_file = repo_root / "tests" / "native" / "zone_spatial_pyramid_search_step_test.cpp"
    bin_file = repo_root / "build" / "native_zone_spatial_pyramid_search_step_test"

    bin_file.parent.mkdir(parents=True, exist_ok=True)

    cmd_compile = [
        "g++",
        "-m32",
        "-O2",
        "-I", str(repo_root / "include"),
        str(src_file),
        str(test_file),
        "-o", str(bin_file),
    ]
    res_compile = subprocess.run(cmd_compile, capture_output=True, text=True)
    assert res_compile.returncode == 0, f"Compilation failed:\n{res_compile.stderr}"

    res_run = subprocess.run([str(bin_file)], capture_output=True, text=True)
    assert res_run.returncode == 0, f"Test failed:\n{res_run.stderr}"
