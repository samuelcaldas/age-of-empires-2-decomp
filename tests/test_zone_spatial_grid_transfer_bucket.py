from pathlib import Path
import subprocess

REPO_ROOT = Path(__file__).resolve().parent.parent


def test_zone_spatial_grid_transfer_bucket():
    src = (
        REPO_ROOT
        / "src"
        / "zone"
        / "zone_spatial_grid_transfer_bucket.cpp"
    )
    test_src = (
        REPO_ROOT
        / "tests"
        / "native"
        / "zone_spatial_grid_transfer_bucket_test.cpp"
    )
    out_bin = REPO_ROOT / "build" / "zone_spatial_grid_transfer_bucket_test"
    out_bin.parent.mkdir(parents=True, exist_ok=True)

    cmd = [
        "g++",
        "-m32",
        "-O2",
        "-I",
        str(REPO_ROOT / "include"),
        str(src),
        str(test_src),
        "-o",
        str(out_bin),
    ]
    subprocess.run(cmd, check=True)
    res = subprocess.run([str(out_bin)], capture_output=True, text=True)
    assert res.returncode == 0
