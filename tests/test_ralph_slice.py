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
