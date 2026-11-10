from pathlib import Path
import subprocess

REPO_ROOT = Path(__file__).resolve().parent.parent


def test_network_state_set_337820():
    src = REPO_ROOT / "src" / "network" / "network_state_set_337820.cpp"
    test_src = (
        REPO_ROOT
        / "tests"
        / "native"
        / "network_state_set_337820_test.cpp"
    )
    out_bin = REPO_ROOT / "build" / "network_state_set_337820_test"
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
