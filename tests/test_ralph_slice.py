"""Behavioral tests for scripts/ralph_slice.py (automatic slicing and loop state)."""

from __future__ import annotations

import json
import struct
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "scripts"))

import ralph_slice  # noqa: E402

NOP = 0x00000000
JR_RA = 0x03E00008
PROLOGUE = 0x27BDFFE0  # addiu sp, sp, -0x20
ADDIU_V0 = 0x24020001
BEQ_FWD4 = 0x10000004  # beq zero, zero, +4 words (target = pc + 4 + 16)


def words(*values: int) -> bytes:
    return b"".join(struct.pack("<I", value) for value in values)


def test_function_ends_after_jr_ra_and_delay_slot():
    code = words(PROLOGUE, ADDIU_V0, JR_RA, NOP, PROLOGUE, JR_RA, NOP)
    assert ralph_slice.find_function_size(code, 0, max_size=0x800) == 0x10


def test_leaf_function_without_prologue_ends_at_jr_ra():
    code = words(ADDIU_V0, JR_RA, ADDIU_V0, ADDIU_V0, ADDIU_V0)
    assert ralph_slice.find_function_size(code, 0, max_size=0x800) == 0xC


def test_early_return_before_branch_target_does_not_end_function():
    # beq jumps over the first jr ra to the word after it; second jr ra is the real end.
    code = words(BEQ_FWD4, NOP, JR_RA, NOP, ADDIU_V0, JR_RA, NOP)
    assert ralph_slice.find_function_size(code, 0, max_size=0x800) == 0x1C


def test_size_cap_cuts_at_last_return_seen():
    # branch to a far target keeps the function open; cap cuts after the jr ra at 4.
    code = words(0x10000100, JR_RA, NOP, ADDIU_V0, ADDIU_V0, ADDIU_V0)
    assert ralph_slice.find_function_size(code, 0, max_size=0x10) == 0xC


def test_missing_return_within_buffer_is_an_error():
    with pytest.raises(ralph_slice.SliceBoundaryError):
        ralph_slice.find_function_size(words(ADDIU_V0, ADDIU_V0), 0, max_size=0x800)


def test_parse_covered_uses_only_sized_function_symbols():
    text = (
        "func_00100010 = 0x100010; // type:func size:0x10\n"
        "func_00100040 = 0x100040; // type:func absolute:True\n"
        "D_00400000 = 0x400000; // type:f32 size:4\n"
        "AspectRatio__9ScreenObjFv = 0x100050; // type:func size:0x8 ScreenObj.AspectRatio()\n"
    )
    assert ralph_slice.parse_covered(text) == [(0x100010, 0x100020), (0x100050, 0x100058)]


def test_next_slice_skips_covered_and_nop_padding_with_alignment():
    code = words(PROLOGUE, JR_RA, NOP, NOP, NOP, NOP, NOP, NOP, ADDIU_V0, JR_RA, NOP)
    # base 0x100000: first function covered [0x100000, 0x10000C); padding to 0x100020 is
    # NOPs, so the next function starts at 0x100020.
    slice_ = ralph_slice.next_slice(code, 0x100000, [(0x100000, 0x10000C)], max_size=0x800)
    assert slice_ == ralph_slice.Slice(func="func_00100020", vram=0x100020, size=0xC)


def test_next_slice_returns_none_when_everything_is_covered():
    code = words(PROLOGUE, JR_RA, NOP)
    assert ralph_slice.next_slice(code, 0x100000, [(0x100000, 0x10000C)], max_size=0x800) is None


def test_next_slice_on_empty_code_returns_none():
    assert ralph_slice.next_slice(b"", 0x100000, [], max_size=0x800) is None


def test_state_records_and_selects_work_in_priority_order(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "state.json")
    state.record("func_00100000", 0x100000, 0x10, pct=95.0, attempts=1, min_pct=90.0, max_attempts=5)
    state.record("func_00100020", 0x100020, 0x10, pct=10.0, attempts=5, min_pct=90.0, max_attempts=5)
    state.record("func_00100040", 0x100040, 0x10, pct=40.0, attempts=2, min_pct=90.0, max_attempts=5)
    assert state.status("func_00100000") == "partial"
    assert state.status("func_00100020") == "blocked"
    assert state.status("func_00100040") == "retry"
    # retry of the current slice comes first, then partial, then blocked
    order = [entry["func"] for entry in state.pending()]
    assert order == ["func_00100040", "func_00100000", "func_00100020"]


def test_state_marks_complete_at_100_and_persists_atomically(tmp_path):
    path = tmp_path / "state.json"
    state = ralph_slice.LoopState(path)
    state.record("func_00100000", 0x100000, 0x10, pct=100.0, attempts=1, min_pct=90.0, max_attempts=5)
    assert state.pending() == []
    assert json.loads(path.read_text())["slices"]["func_00100000"]["status"] == "done"
    assert not list(tmp_path.glob("*.tmp"))
    assert ralph_slice.LoopState(path).status("func_00100000") == "done"


def test_covered_includes_partial_blocked_and_done_slices(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "state.json")
    state.record("func_00100000", 0x100000, 0x10, pct=95.0, attempts=1, min_pct=90.0, max_attempts=5)
    assert state.covered() == [(0x100000, 0x100010)]


# ---------------------------------------------------------------- non-C hints
SYSCALL = 0x0000000C
MFC0_V0 = 0x40026000
CACHE = 0xBC000000
SYNC = 0x0000000F
SQ_RA = 0x7FBF0000  # opcode 0x1F (sq on R5900)
LQ_RA = 0x7BBF0000  # opcode 0x1E (lq on R5900)
PMFHL = 0x70000030  # MMI opcode 0x1C
BREAK_DIVZERO = 0x000001CD  # break 7: emitted by divbyzerocheck, plain C
BREAK_OTHER = 0x0000000D


def test_plain_code_has_no_hints():
    assert ralph_slice.classify_code([PROLOGUE, ADDIU_V0, JR_RA, NOP]) == []


@pytest.mark.parametrize(
    "word,hint",
    [(SYSCALL, "syscall"), (MFC0_V0, "cop0"), (CACHE, "cache"), (SYNC, "sync"),
     (SQ_RA, "lq_sq"), (LQ_RA, "lq_sq"), (PMFHL, "mmi"), (BREAK_OTHER, "break")],
)
def test_each_non_c_instruction_family_is_flagged(word, hint):
    assert hint in ralph_slice.classify_code([PROLOGUE, word, JR_RA, NOP])


def test_divide_by_zero_break_is_not_flagged():
    assert "break" not in ralph_slice.classify_code([BREAK_DIVZERO, JR_RA, NOP])


def test_only_syscall_and_cop0_are_strong_hints():
    assert ralph_slice.is_likely_asm(["syscall"])
    assert ralph_slice.is_likely_asm(["lq_sq", "cop0"])
    assert not ralph_slice.is_likely_asm(["lq_sq", "mmi", "sync", "cache", "break"])
    assert not ralph_slice.is_likely_asm([])


# ---------------------------------------------------------------- history / stall
def _record(state, pct, attempts=1, stall=0, func="func_00100000", seconds=1.0):
    state.record(func, 0x100000, 0x10, pct=pct, attempts=attempts, min_pct=90.0, max_attempts=5,
                 seconds=seconds, stall=stall)


def test_record_keeps_history_with_pct_seconds_and_timestamp(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "s.json")
    _record(state, 30.0, seconds=12.5)
    _record(state, 40.0, attempts=2, seconds=7.0)
    history = state.data["slices"]["func_00100000"]["history"]
    assert [(h["pct"], h["seconds"]) for h in history] == [(30.0, 12.5), (40.0, 7.0)]
    assert all("timestamp" in h for h in history)


def test_history_survives_reload(tmp_path):
    path = tmp_path / "s.json"
    _record(ralph_slice.LoopState(path), 30.0)
    assert len(ralph_slice.LoopState(path).data["slices"]["func_00100000"]["history"]) == 1


def test_stall_blocks_after_n_attempts_without_improvement(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "s.json")
    _record(state, 23.73, attempts=1, stall=2)
    assert state.status("func_00100000") == "retry"
    _record(state, 23.73, attempts=2, stall=2)
    assert state.status("func_00100000") == "retry"
    _record(state, 23.73, attempts=3, stall=2)
    assert state.status("func_00100000") == "blocked"
    assert state.is_stalled("func_00100000", window=2)


def test_improvement_resets_the_stall_window(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "s.json")
    for attempts, pct in enumerate([20.0, 20.0, 35.0, 35.0], start=1):
        _record(state, pct, attempts=attempts, stall=2)
    assert state.status("func_00100000") == "retry"
    assert not state.is_stalled("func_00100000", window=2)


def test_stall_disabled_by_default(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "s.json")
    for attempts in (1, 2, 3, 4):
        _record(state, 10.0, attempts=attempts)
    assert state.status("func_00100000") == "retry"


def test_stall_never_demotes_a_slice_that_reached_the_threshold(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "s.json")
    for attempts in (1, 2, 3):
        _record(state, 95.0, attempts=attempts, stall=2)
    assert state.status("func_00100000") == "partial"


# ---------------------------------------------------------------- starvation / asm
def _two_partials(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "s.json")
    for func, vram in (("func_00100000", 0x100000), ("func_00100020", 0x100020)):
        state.record(func, vram, 0x10, pct=95.0, attempts=1, min_pct=90.0, max_attempts=5)
    return state


def test_touch_rotates_revisits_between_equal_status_entries(tmp_path):
    state = _two_partials(tmp_path)
    first = state.pending()[0]["func"]
    state.touch(first)
    second = state.pending()[0]["func"]
    assert (first, second) == ("func_00100000", "func_00100020")
    state.touch(second)
    assert state.pending()[0]["func"] == first


def test_status_rank_still_beats_passes(tmp_path):
    state = _two_partials(tmp_path)
    state.touch("func_00100000")
    state.record("func_00100040", 0x100040, 0x10, pct=10.0, attempts=1, min_pct=90.0, max_attempts=5)
    assert state.pending()[0]["func"] == "func_00100040"


def test_max_passes_removes_entry_from_pending_and_lists_it_as_unresolved(tmp_path):
    state = _two_partials(tmp_path)
    for _ in range(3):
        state.touch("func_00100000")
    assert [e["func"] for e in state.pending(max_passes=3)] == ["func_00100020"]
    assert [e["func"] for e in state.unresolved(max_passes=3)] == ["func_00100000"]


def test_asm_status_is_not_pending_but_is_covered(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "s.json")
    state.mark("func_00100000", 0x100000, 0x10, status="asm", reason="syscall")
    assert state.status("func_00100000") == "asm"
    assert state.pending() == []
    assert state.covered() == [(0x100000, 0x100010)]
    assert state.data["slices"]["func_00100000"]["reason"] == "syscall"


def test_mark_keeps_existing_history(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "s.json")
    _record(state, 20.0)
    state.mark("func_00100000", 0x100000, 0x10, status="asm", reason="x")
    assert len(state.data["slices"]["func_00100000"]["history"]) == 1


def test_mark_rejects_unknown_status(tmp_path):
    with pytest.raises(ValueError):
        ralph_slice.LoopState(tmp_path / "s.json").mark("f", 0, 4, status="bogus", reason="")


def test_legacy_state_entries_without_history_still_load_and_sort(tmp_path):
    path = tmp_path / "s.json"
    path.write_text(json.dumps({"slices": {"func_00100000": {
        "func": "func_00100000", "vram": 0x100000, "size": 16, "pct": 50.0, "attempts": 1, "status": "retry"}}}))
    state = ralph_slice.LoopState(path)
    assert [e["func"] for e in state.pending()] == ["func_00100000"]
    state.touch("func_00100000")
    assert state.data["slices"]["func_00100000"]["passes"] == 1


# ---------------------------------------------------------------- covered index
def _linear_skip(code, base, covered):
    address, end = base, base + len(code)
    while address + 4 <= end:
        containing = [stop for begin, stop in covered if begin <= address < stop]
        if containing:
            address = max(containing)
        elif struct.unpack_from("<I", code, address - base)[0] == 0:
            address += 4
        else:
            return address
    return None


def test_indexed_skip_equals_linear_reference_on_random_intervals():
    import random

    rng = random.Random(1234)
    for _ in range(300):
        count = rng.randrange(1, 40)
        code = words(*[rng.choice([0, 0, 0, ADDIU_V0]) for _ in range(count)])
        base = 0x100000
        covered = []
        for _ in range(rng.randrange(0, 8)):
            begin = base + 4 * rng.randrange(0, count + 2)
            covered.append((begin, begin + 4 * rng.randrange(1, 10)))
        expected = _linear_skip(code, base, covered)
        assert ralph_slice._skip_covered_and_padding(code, base, sorted(covered)) == expected


def test_next_slice_cap_uses_next_covered_start():
    code = words(ADDIU_V0, ADDIU_V0, ADDIU_V0, JR_RA, NOP)
    with pytest.raises(ralph_slice.SliceBoundaryError):
        ralph_slice.next_slice(code, 0x100000, [(0x10000C, 0x100014)], max_size=0x800)


# ---------------------------------------------------------------- summary
def test_summary_counts_bytes_statuses_time_and_eta(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "s.json")
    state.record("func_00100000", 0x100000, 0x100, pct=100.0, attempts=1, min_pct=90.0, max_attempts=5, seconds=100.0)
    state.record("func_00100100", 0x100100, 0x100, pct=95.0, attempts=1, min_pct=90.0, max_attempts=5, seconds=50.0)
    state.mark("func_00100200", 0x100200, 0x40, status="asm", reason="syscall")
    symbols = "func_00100300 = 0x100300; // type:func size:0x100\n"
    result = ralph_slice.summarize(state, symbols, text_start=0x100000, text_end=0x100800)
    assert result["total_bytes"] == 0x800
    assert result["covered_bytes"] == 0x100 + 0x40 + 0x100  # done + asm + symbols.txt
    assert result["counts"] == {"done": 1, "partial": 1, "asm": 1}
    assert result["total_seconds"] == 150.0
    assert result["average_seconds_per_slice"] == 75.0  # only slices that were timed
    assert result["asm"] == [{"func": "func_00100200", "reason": "syscall"}]
    assert result["eta_seconds"] > 0


def test_summary_without_history_has_no_eta(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "s.json")
    result = ralph_slice.summarize(state, "", text_start=0, text_end=0x100)
    assert result["eta_seconds"] is None
    assert result["average_seconds_per_slice"] == 0.0


def test_summary_does_not_double_count_overlap_between_symbols_and_state(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "s.json")
    state.record("func_00100000", 0x100000, 0x100, pct=100.0, attempts=1, min_pct=90.0, max_attempts=5)
    symbols = "func_00100000 = 0x100000; // type:func size:0x100\n"
    result = ralph_slice.summarize(state, symbols, text_start=0x100000, text_end=0x100400)
    assert result["covered_bytes"] == 0x100


# ---------------------------------------------------------------- side by side
def test_side_by_side_shows_both_disassemblies_with_context_and_marker():
    orig = words(PROLOGUE, ADDIU_V0, 0x24030002, ADDIU_V0, JR_RA, NOP)
    compiled = words(PROLOGUE, ADDIU_V0, 0x24030009, ADDIU_V0, JR_RA, NOP)
    mismatches = [{"offset": 8, "orig": "02000324", "compiled": "09000324"}]
    lines = ralph_slice.side_by_side(orig, compiled, mismatches, vram=0x100000, context=1)
    assert len(lines) == 3  # one line before, the divergence, one after
    assert lines[0].startswith("  ") and lines[2].startswith("  ")
    assert lines[1].startswith("! ")
    assert "addiu $v1, $zero, 2" in lines[1] and "addiu $v1, $zero, 9" in lines[1]
    assert "00100008" in lines[1]


def test_side_by_side_merges_overlapping_windows_and_caps_lines():
    orig = words(*([ADDIU_V0] * 40))
    compiled = words(*([0x24030002] * 40))
    mismatches = [{"offset": 4 * i, "orig": "01000224", "compiled": "02000324"} for i in range(40)]
    lines = ralph_slice.side_by_side(orig, compiled, mismatches, vram=0, context=2, max_lines=12)
    assert len(lines) <= 13
    assert lines[-1].startswith("...")


def test_side_by_side_handles_compiled_shorter_than_original():
    orig = words(PROLOGUE, ADDIU_V0, JR_RA, NOP)
    compiled = words(PROLOGUE, ADDIU_V0)
    mismatches = []
    lines = ralph_slice.side_by_side(orig, compiled, mismatches, vram=0, context=1)
    assert any("<missing>" in line for line in lines)


# ---------------------------------------------------------------- guard
def _git(repo, *args):
    import subprocess

    subprocess.run(["git", "-C", str(repo), *args], check=True, capture_output=True)


@pytest.fixture
def repo(tmp_path):
    root = tmp_path / "repo"
    for sub in ("scripts", "src", "config", "tests", "staging", "build"):
        (root / sub).mkdir(parents=True)
    (root / "scripts/tool.py").write_text("print(1)\n")
    (root / "src/a.cpp").write_text("int a;\n")
    (root / "configure.py").write_text("x = 1\n")
    (root / ".gitignore").write_text("staging/\nbuild/\n")
    _git(root, "init", "-q")
    _git(root, "-c", "user.name=t", "-c", "user.email=t@t", "add", "-A")
    _git(root, "-c", "user.name=t", "-c", "user.email=t@t", "commit", "-q", "-m", "init")
    return root


def test_guard_reports_nothing_when_untouched(repo):
    snapshot = ralph_slice.guard_snapshot(repo)
    assert ralph_slice.guard_verify(repo, snapshot) == {"changed": [], "stray": [], "unrestorable": []}


def test_guard_detects_changed_deleted_and_stray_files(repo):
    snapshot = ralph_slice.guard_snapshot(repo)
    (repo / "scripts/tool.py").write_text("print(2)\n")
    (repo / "configure.py").unlink()
    (repo / "stray.txt").write_text("x")
    (repo / "src/new.cpp").write_text("int b;\n")
    result = ralph_slice.guard_verify(repo, snapshot)
    assert result["changed"] == ["configure.py", "scripts/tool.py"]
    assert result["stray"] == ["src/new.cpp", "stray.txt"]


def test_guard_ignores_staging_and_build(repo):
    snapshot = ralph_slice.guard_snapshot(repo)
    (repo / "staging/func.cpp").write_text("x")
    (repo / "build/out.o").write_text("x")
    assert ralph_slice.guard_verify(repo, snapshot)["stray"] == []


def test_guard_ignores_pycache(repo):
    snapshot = ralph_slice.guard_snapshot(repo)
    (repo / "scripts/__pycache__").mkdir()
    (repo / "scripts/__pycache__/tool.cpython-312.pyc").write_bytes(b"x")
    assert ralph_slice.guard_verify(repo, snapshot)["changed"] == []


def test_guard_restore_reverts_changes_and_removes_new_strays(repo):
    snapshot = ralph_slice.guard_snapshot(repo)
    (repo / "scripts/tool.py").write_text("print(2)\n")
    (repo / "configure.py").unlink()
    (repo / "stray.txt").write_text("x")
    ralph_slice.guard_verify(repo, snapshot, restore=True)
    assert (repo / "scripts/tool.py").read_text() == "print(1)\n"
    assert (repo / "configure.py").read_text() == "x = 1\n"
    assert not (repo / "stray.txt").exists()


def test_guard_keeps_strays_that_existed_at_snapshot(repo):
    (repo / "old_stray.txt").write_text("keep")
    snapshot = ralph_slice.guard_snapshot(repo)
    result = ralph_slice.guard_verify(repo, snapshot, restore=True)
    assert result["stray"] == [] and (repo / "old_stray.txt").exists()


def test_guard_does_not_clobber_edits_that_were_uncommitted_at_snapshot(repo):
    (repo / "scripts/tool.py").write_text("print('wip')\n")
    snapshot = ralph_slice.guard_snapshot(repo)
    (repo / "scripts/tool.py").write_text("print('agent')\n")
    result = ralph_slice.guard_verify(repo, snapshot, restore=True)
    assert result["changed"] == ["scripts/tool.py"]
    assert result["unrestorable"] == ["scripts/tool.py"]
    assert (repo / "scripts/tool.py").read_text() == "print('agent')\n"


def test_guard_snapshot_round_trips_through_json(repo, tmp_path):
    snapshot = ralph_slice.guard_snapshot(repo)
    restored = json.loads(json.dumps(snapshot))
    assert ralph_slice.guard_verify(repo, restored)["changed"] == []


# ---------------------------------------------------------------- CLI
def _cli(capsys, *argv):
    parser = ralph_slice.build_parser()
    args = parser.parse_args([str(item) for item in argv])
    assert args.handler(args) == 0
    return json.loads(capsys.readouterr().out)


def test_cli_record_prints_final_status_and_honours_stall(tmp_path, capsys):
    state = tmp_path / "s.json"
    common = ["record", "--state", state, "--func", "func_00100000", "--vram", "0x100000", "--size", "0x10",
              "--pct", "23.73", "--stall", "2", "--seconds", "3"]
    statuses = [_cli(capsys, *common, "--attempts", n)["status"] for n in (1, 2, 3)]
    assert statuses == ["retry", "retry", "blocked"]


def test_cli_mark_asm_then_summary_lists_it(tmp_path, capsys):
    state = tmp_path / "s.json"
    _cli(capsys, "mark", "--state", state, "--func", "func_00100000", "--vram", "0x100000", "--size", "0x10",
         "--status", "asm", "--reason", "syscall in body")
    assert _cli(capsys, "summary", "--state", state)["asm"] == [
        {"func": "func_00100000", "reason": "syscall in body"}]


def test_cli_guard_snapshot_then_verify_restore(repo, tmp_path, capsys):
    snapshot = tmp_path / "guard.json"
    _cli(capsys, "guard", "snapshot", "--root", repo, "--file", snapshot)
    (repo / "configure.py").write_text("tampered\n")
    result = _cli(capsys, "guard", "verify", "--root", repo, "--file", snapshot, "--restore")
    assert result["changed"] == ["configure.py"]
    assert (repo / "configure.py").read_text() == "x = 1\n"


def test_next_reply_adds_hints_and_flags_likely_asm():
    reply = ralph_slice.slice_reply(ralph_slice.Slice("func_00100000", 0x100000, 16),
                                    words(PROLOGUE, SYSCALL, JR_RA, NOP))
    assert reply["hints"] == ["syscall"] and reply["likely_asm"] is True
    clean = ralph_slice.slice_reply(ralph_slice.Slice("func_00100000", 0x100000, 16),
                                    words(PROLOGUE, ADDIU_V0, JR_RA, NOP))
    assert clean["hints"] == [] and clean["likely_asm"] is False
