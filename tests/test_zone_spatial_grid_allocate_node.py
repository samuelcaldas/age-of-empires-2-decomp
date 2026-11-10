import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

def test_zone_spatial_grid_allocate_node():
    test_src = ROOT / "tests/native/zone_spatial_grid_allocate_node_test.cpp"
    impl_src = ROOT / "src/zone/zone_spatial_grid_allocate_node.cpp"
    bin_path = ROOT / "build/tests/zone_spatial_grid_allocate_node_test"
    bin_path.parent.mkdir(parents=True, exist_ok=True)

    cmd = [
        "g++", "-m32", "-O2",
        f"-I{ROOT}/include",
        str(test_src), str(impl_src),
        "-o", str(bin_path)
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    assert res.returncode == 0, f"Compilation failed:\n{res.stderr}"

    run_res = subprocess.run([str(bin_path)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"Test failed:\n{run_res.stderr}\n{run_res.stdout}"
