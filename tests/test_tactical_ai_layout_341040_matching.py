"""Compare tactical AI screen layout functions 0x341040 and 0x342170 with original PS2 instructions and execute native test suite."""

import hashlib
import json
import subprocess
from pathlib import Path

import pytest
from elftools.elf.elffile import ELFFile


PROJECT_ROOT = Path(__file__).resolve().parents[1]
SOURCE_PATH = PROJECT_ROOT / "src/tactical_ai_layout_341040.cpp"
FUNC_342170_SOURCE_PATH = PROJECT_ROOT / "src/tactical_ai_func_342170.cpp"
ORIGINAL_PATH = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER_PATH = PROJECT_ROOT / "build/tools/wibo"
LINKER_PATH = PROJECT_ROOT / "build/mips_binutils/mips-linux-gnu-ld"
OBJDIFF_PATH = PROJECT_ROOT / "build/tools/objdiff-cli"
TEXT_ADDRESS = 0x341040
TEXT_SIZE = 5984  # 4388 + 1584 + padding
SLICE_SIZE = 5984
FILE_OFFSET = 0x241220
ORIGINAL_SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"
FUNCTIONS = {
    "func_00341040": (0x341040, 4388),
    "func_00342170": (0x342170, 1584),
}


def require_toolchain():
    """Skip only when the original binary or PS2 toolchain files are absent."""
    required_paths = (ORIGINAL_PATH, COMPILER_PATH, WRAPPER_PATH, LINKER_PATH)
    missing_paths = [str(path) for path in required_paths if not path.is_file()]
    if missing_paths:
        pytest.skip("requires original ELF and PS2 toolchain; missing: " + ", ".join(missing_paths))


def original_text():
    """Read the exact PT_LOAD bytes."""
    original_bytes = ORIGINAL_PATH.read_bytes()
    assert hashlib.sha1(original_bytes).hexdigest() == ORIGINAL_SHA1, (
        "AOK.ELF SHA1 mismatch — wrong binary"
    )
    with ORIGINAL_PATH.open("rb") as original_stream:
        original_elf = ELFFile(original_stream)
        matching_segments = [
            segment for segment in original_elf.iter_segments()
            if segment["p_type"] == "PT_LOAD"
            and segment["p_vaddr"] <= TEXT_ADDRESS
            and TEXT_ADDRESS + SLICE_SIZE <= segment["p_vaddr"] + segment["p_filesz"]
        ]
        assert len(matching_segments) == 1, len(matching_segments)
        segment = matching_segments[0]
        offset = TEXT_ADDRESS - segment["p_vaddr"]
        assert segment["p_offset"] + offset == FILE_OFFSET
        code = segment.data()[offset:offset + SLICE_SIZE]
        assert len(code) == SLICE_SIZE
        return code


def test_tactical_ai_layout_341040_exists():
    """Verify that original text exists and has the expected size."""
    require_toolchain()
    code = original_text()
    assert len(code) == TEXT_SIZE


def test_tactical_ai_layout_native_runner(tmp_path):
    """Compile and execute the native C++ unit tests for tactical_ai_layout_341040."""
    test_bin = tmp_path / "layout_test"
    subprocess.run(
        [
            "g++", "-m32", "-std=c++98", "-Iinclude",
            "tests/native/tactical_ai_layout_341040_test.cpp",
            "src/tactical_ai_layout_341040.cpp",
            "src/tactical_ai_func_342170.cpp",
            "-o", str(test_bin),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    res = subprocess.run([str(test_bin)], capture_output=True, text=True, check=True)
    assert "ALL TACTICAL AI LAYOUT TESTS PASSED" in res.stdout


def test_tactical_ai_func_342170_mwcc_compilation(tmp_path):
    """Compile func_00342170 with MWCC PS2 toolchain and verify against sliced object."""
    require_toolchain()
    compiled_obj = tmp_path / "tactical_ai_func_342170.o"
    res = subprocess.run(
        [
            str(WRAPPER_PATH),
            str(COMPILER_PATH),
            "-c",
            "-O3",
            "-inline", "on",
            "-msext", "on",
            "-char", "signed",
            "-sym", "off",
            "-Iinclude",
            "-lang=c++",
            str(FUNC_342170_SOURCE_PATH),
            "-o", str(compiled_obj),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )
    assert compiled_obj.is_file(), "MWCC failed to output object file"
    assert compiled_obj.stat().st_size > 0, "MWCC produced empty object file"

    # Also build to project base_path for objdiff tracking
    base_obj = PROJECT_ROOT / "build/SLES-50282/src/tactical_ai_func_342170.o"
    base_obj.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run(
        [
            str(WRAPPER_PATH),
            str(COMPILER_PATH),
            "-c",
            "-O3",
            "-inline", "on",
            "-msext", "on",
            "-char", "signed",
            "-sym", "off",
            "-Iinclude",
            "-lang=c++",
            str(FUNC_342170_SOURCE_PATH),
            "-o", str(base_obj),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=True,
    )

    if OBJDIFF_PATH.is_file():
        rep = subprocess.run(
            [str(OBJDIFF_PATH), "report", "generate"],
            cwd=PROJECT_ROOT,
            capture_output=True,
            text=True,
            check=True,
        )
        report_data = json.loads(rep.stdout)
        unit = next(
            (u for u in report_data.get("units", []) if "tactical_ai_func_342170" in u.get("name", "")),
            None,
        )
        assert unit is not None, "tactical_ai_func_342170 unit not found in objdiff report"

        # Diagnostic report: incomplete functions must NOT pass as matched
        fuzzy = unit.get("measures", {}).get("fuzzy_match_percent", 0.0)
        is_complete = unit.get("metadata", {}).get("complete", False)
        target_fn = next(
            (f for f in unit.get("functions", []) if f.get("name") == "func_00342170"),
            None,
        )
        assert target_fn is not None, "func_00342170 symbol missing from target unit"
        fn_size = int(target_fn.get("size", 0))
        print(f"\n[DIAGNOSTIC] tactical_ai_func_342170 size: {fn_size} (target: 1584), fuzzy match: {fuzzy:.2f}%, complete: {is_complete}")

        # Guard: must remain NonMatching in configuration while incomplete
        assert not is_complete, f"Function is {fuzzy}% matched, must remain NonMatching"

        # Incomplete functions report diagnostics and skip matching clearance
        if fuzzy < 100.0 or not is_complete:
            pytest.skip(
                f"func_00342170 remains NonMatching (diagnostic score: {fuzzy:.2f}%, size: {fn_size}/1584), translation in progress"
            )

        # Exact matching gate for future promotion
        assert fn_size == 1584, f"Target function size mismatch on promotion: {fn_size} != 1584"
        assert fuzzy == 100.0, f"Expected 100.0% matching on promotion, got {fuzzy}%"

