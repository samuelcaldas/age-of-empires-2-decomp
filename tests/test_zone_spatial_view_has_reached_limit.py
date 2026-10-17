import subprocess
from pathlib import Path


def test_zone_spatial_view_has_reached_limit_native():
    repo_root = Path(__file__).resolve().parent.parent
    src = repo_root / "src" / "zone_spatial_view_has_reached_limit.cpp"
    test_src = repo_root / "tests" / "native" / "zone_spatial_view_has_reached_limit_test.cpp"
    bin_path = repo_root / "build" / "zone_spatial_view_has_reached_limit_test"
    bin_path.parent.mkdir(parents=True, exist_ok=True)

    cmd = [
        "g++",
        "-m32",
        "-O2",
        "-Iinclude",
        "-Itests/native",
        str(src),
        str(test_src),
        "-o",
        str(bin_path),
    ]
    compile_res = subprocess.run(cmd, capture_output=True, text=True)
    assert compile_res.returncode == 0, f"Compilation failed: {compile_res.stderr}"

    run_res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"Execution failed: {run_res.stderr}"
