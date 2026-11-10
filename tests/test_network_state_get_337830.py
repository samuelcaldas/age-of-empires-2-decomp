from pathlib import Path
import subprocess

REPO_ROOT = Path(__file__).resolve().parent.parent


def test_network_state_get_337830():
    src = REPO_ROOT / "src" / "network" / "network_state_get_337830.cpp"
    test_src = (
        REPO_ROOT
        / "tests"
        / "native"
        / "network_state_get_337830_test.cpp"
    )
    out_bin = REPO_ROOT / "build" / "network_state_get_337830_test"
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
