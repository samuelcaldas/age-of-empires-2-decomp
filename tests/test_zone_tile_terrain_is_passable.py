import json
from pathlib import Path
import subprocess

import pytest


def test_zone_tile_terrain_is_passable_native():
    repo_root = Path(__file__).resolve().parent.parent
    src_file = repo_root / "src/zone" / "zone_tile_terrain_is_passable.cpp"
    test_file = repo_root / "tests" / "native" / "zone_tile_terrain_is_passable_test.cpp"
    bin_file = repo_root / "build" / "native_zone_tile_terrain_is_passable_test"

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


def test_zone_tile_terrain_is_passable_matching(tmp_path):
    repo_root = Path(__file__).resolve().parent.parent
    compiler = repo_root / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
    wrapper = repo_root / "build/tools/wibo"
    src_file = repo_root / "src/zone" / "zone_tile_terrain_is_passable.cpp"
    obj = tmp_path / "zone_tile_terrain_is_passable.o"

    if not compiler.is_file():
        pytest.skip("licensed compiler not available")

    subprocess.run(
        [
            str(wrapper),
            str(compiler),
            "-c",
            str(src_file),
            "-o",
            str(obj),
            "-O3",
            "-inline",
            "on",
            "-msext",
            "on",
            "-char",
            "signed",
            "-sym",
            "off",
            "-Iinclude",
        ],
        check=True,
        capture_output=True,
    )

    diff_cmd = [
        str(repo_root / "build/tools/objdiff-cli"),
        "diff",
        "-1",
        str(repo_root / "build/SLES-50282/obj/zone_tile_terrain_is_passable.o"),
        "-2",
        str(obj),
        "-o",
        "-",
    ]
    res = subprocess.run(diff_cmd, capture_output=True, text=True, check=True)
    d = json.loads(res.stdout)
    s = [x for x in d["right"]["symbols"] if "instructions" in x][0]
    pct = s.get("match_percent")
    assert pct == 100.0, f"Expected 100.0% match, got {pct}%"
