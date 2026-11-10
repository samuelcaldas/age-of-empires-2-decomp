from pathlib import Path
import subprocess

REPO_ROOT = Path(__file__).resolve().parents[1]

def test_zone_spatial_entity_query_status(tmp_path: Path) -> None:
    native_src = REPO_ROOT / "tests/native/zone_spatial_entity_query_status_test.cpp"
    impl_src = REPO_ROOT / "src/zone/zone_spatial_entity_query_status.cpp"
    bin_path = tmp_path / "zone_spatial_entity_query_status_test"

    compile_cmd = [
        "g++",
        "-m32",
        "-std=c++03",
        "-O2",
        f"-I{REPO_ROOT / 'include'}",
        str(native_src),
        str(impl_src),
        "-o",
        str(bin_path),
    ]
    res = subprocess.run(compile_cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed:\nSTDOUT: {res.stdout}\nSTDERR: {res.stderr}"

    run_res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"Execution failed:\nSTDOUT: {run_res.stdout}\nSTDERR: {run_res.stderr}"
    assert "zone_spatial_entity_query_status_test passed" in run_res.stdout
