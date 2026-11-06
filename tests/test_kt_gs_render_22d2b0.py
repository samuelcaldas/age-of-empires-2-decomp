from pathlib import Path
import subprocess

PROJECT_ROOT = Path(__file__).resolve().parents[1]

def test_native_kt_gs_render_22d2b0():
    test_bin = PROJECT_ROOT / "tests/native/kt_gs_render_22d2b0_test"
    test_src = PROJECT_ROOT / "tests/native/kt_gs_render_22d2b0_test.cpp"
    impl_src = PROJECT_ROOT / "tests/native/kt_gs_render_22d2b0_impl.cpp"
    include_dir = PROJECT_ROOT / "include"

    compile_cmd = [
        "g++",
        "-O2",
        f"-I{include_dir}",
        str(test_src),
        str(impl_src),
        "-o",
        str(test_bin),
    ]
    res_compile = subprocess.run(compile_cmd, capture_output=True, text=True)
    assert res_compile.returncode == 0, f"Compilation failed: {res_compile.stderr}"

    try:
        res_run = subprocess.run([str(test_bin)], capture_output=True, text=True)
        assert res_run.returncode == 0, f"Execution failed: {res_run.stderr}"
        assert "native kt_gs_render_22d2b0 tests passed" in res_run.stdout
    finally:
        if test_bin.exists():
            test_bin.unlink()
