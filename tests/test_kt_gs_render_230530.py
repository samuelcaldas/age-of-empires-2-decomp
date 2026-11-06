from pathlib import Path
import subprocess

PROJECT_ROOT = Path(__file__).resolve().parent.parent

def test_native_kt_gs_render_230530():
    test_bin = PROJECT_ROOT / "tests/native/kt_gs_render_230530_test"
    test_src = PROJECT_ROOT / "tests/native/kt_gs_render_230530_test.cpp"
    impl_src = PROJECT_ROOT / "tests/native/kt_gs_render_230530_impl.cpp"
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
    finally:
        if test_bin.exists():
            test_bin.unlink()
