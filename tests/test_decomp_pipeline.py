"""Tests for the automated decompilation pipeline."""

from scripts.decomp_pipeline import (
    stage_function,
    compile_draft,
    diff_draft,
    PROJECT_ROOT,
)


def test_stage_function_idempotency(tmp_path):
    func_name = "func_test_stage_12345"
    vram = 0x220C60
    size = 0x70

    # Run 1
    staged_path = stage_function(func_name, vram, size)
    assert staged_path.exists()
    content1 = staged_path.read_text()
    assert func_name in content1

    # Modify content
    staged_path.write_text("// Custom modified content\n" + content1)

    # Run 2 (must not overwrite modified draft)
    staged_path2 = stage_function(func_name, vram, size)
    assert staged_path2 == staged_path
    assert staged_path2.read_text().startswith("// Custom modified content")

    # Clean up
    if staged_path.exists():
        staged_path.unlink()


def test_diff_against_known_matched_function(tmp_path):
    # Test diffing kt_thread_spawn_220c60 (func_00220C60) which is 100% matched
    src = PROJECT_ROOT / "src/kcet/kt_thread_spawn_220c60.cpp"
    assert src.exists()

    tmp_obj = tmp_path / "test_spawn.o"
    ok, msg, obj_path = compile_draft(src, tmp_obj)
    assert ok, f"Compilation failed: {msg}"
    assert obj_path.exists()

    known_symbols = {
        "func_220300": 0x220300,
        "func_220380": 0x220380,
        "func_104B40": 0x104B40,
        "func_220CD0": 0x220CD0,
        "D_00C824F0": 0xC824F0,
        "D_00C804B0": 0xC804B0,
        "D_00C804F0": 0xC804F0,
    }

    diff_result = diff_draft(
        func_name="func_00220C60",
        vram=0x220C60,
        size=0x64,
        obj_path=obj_path,
        known_symbols=known_symbols
    )

    assert diff_result["size_match"] is True
    assert diff_result["is_match"] is True
    assert diff_result["match_percentage"] == 100.0
    assert len(diff_result["mismatches"]) == 0
