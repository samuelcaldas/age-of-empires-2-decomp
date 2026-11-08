from pathlib import Path
import subprocess

PROJECT_ROOT = Path(__file__).resolve().parents[1]

def test_native_kt_gs_render_23f6c0():
    include_dir = PROJECT_ROOT / "include"
    test_src = PROJECT_ROOT / "tests/native/kt_gs_render_23f6c0_test.cpp"
    impl_src = PROJECT_ROOT / "tests/native/kt_gs_render_23f6c0_impl.cpp"
    bin_out = PROJECT_ROOT / "build/tests/kt_gs_render_23f6c0_test"

    bin_out.parent.mkdir(parents=True, exist_ok=True)
    res = subprocess.run(
        [
            "g++",
            "-std=c++17",
            f"-I{include_dir}",
            str(test_src),
            str(impl_src),
            "-o",
            str(bin_out),
        ],
        capture_output=True,
        text=True,
    )
    assert res.returncode == 0, f"Compilation failed: {res.stderr}"

    run_res = subprocess.run([str(bin_out)], capture_output=True, text=True)
    assert run_res.returncode == 0, f"Execution failed: {run_res.stderr}"
    assert "kt_gs_render_23f6c0 native tests passed." in run_res.stdout
