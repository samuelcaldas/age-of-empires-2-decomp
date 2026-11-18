"""Behavioral tests for scripts/ralph_metrics.py (event log, backfill, CSV export, HTML report)."""

from __future__ import annotations

import csv
import json
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "scripts"))

import ralph_metrics  # noqa: E402
import ralph_slice  # noqa: E402


def _events(path):
    return [json.loads(line) for line in path.read_text().splitlines() if line.strip()]


def _state_with_history(tmp_path):
    state = ralph_slice.LoopState(tmp_path / "state.json")
    state.record("func_00100000", 0x100000, 0x100, pct=40.0, attempts=1, min_pct=90.0, max_attempts=5,
                 seconds=30.0, stall=0)
    state.record("func_00100000", 0x100000, 0x100, pct=100.0, attempts=2, min_pct=90.0, max_attempts=5,
                 seconds=60.0, stall=0)
    state.record("func_00100100", 0x100100, 0x10, pct=95.0, attempts=1, min_pct=90.0, max_attempts=5,
                 seconds=20.0, stall=0)
    state.mark("func_00100200", 0x100200, 0x40, status="asm", reason="syscall")
    return state


# ---------------------------------------------------------------- event log
def test_append_event_writes_one_json_line_with_type_and_time(tmp_path):
    events = tmp_path / "metrics" / "events.jsonl"
    ralph_metrics.append_event(events, "wave", {"size": 2, "wall_seconds": 90.5}, now=1000.0)
    ralph_metrics.append_event(events, "wave", {"size": 1, "wall_seconds": 10.0}, now=1001.0)
    rows = _events(events)
    assert rows == [
        {"ts": 1000.0, "type": "wave", "size": 2, "wall_seconds": 90.5},
        {"ts": 1001.0, "type": "wave", "size": 1, "wall_seconds": 10.0},
    ]


def test_append_event_rejects_unknown_types(tmp_path):
    with pytest.raises(ValueError):
        ralph_metrics.append_event(tmp_path / "e.jsonl", "bogus", {})


def test_cli_record_coerces_numbers_hex_and_text(tmp_path):
    events = tmp_path / "events.jsonl"
    code = ralph_metrics.main(["record", "--events", str(events), "--type", "attempt",
                               "func=func_00100000", "vram=0x100000", "pct=23.5", "attempt=2",
                               "outcome=no function end"])
    assert code == 0
    row = _events(events)[0]
    assert row["type"] == "attempt"
    assert row["vram"] == 0x100000 and row["attempt"] == 2 and row["pct"] == 23.5
    assert row["func"] == "func_00100000" and row["outcome"] == "no function end"


def test_read_events_of_missing_file_is_empty(tmp_path):
    assert ralph_metrics.read_events(tmp_path / "missing.jsonl") == []


# ---------------------------------------------------------------- snapshot
def test_snapshot_fields_split_bytes_by_status(tmp_path):
    state = _state_with_history(tmp_path)
    fields = ralph_metrics.snapshot_fields(state, "", 0x100000, 0x100800)
    assert fields["cpp_bytes"] == 0x100
    assert fields["asm_bytes"] == 0x40
    assert fields["partial_bytes"] == 0x10
    assert fields["total_bytes"] == 0x800
    assert fields["count_done"] == 1 and fields["count_asm"] == 1


def test_cli_snapshot_appends_a_snapshot_event(tmp_path):
    state_path = tmp_path / "state.json"
    _state_with_history(tmp_path)
    events = tmp_path / "events.jsonl"
    assert ralph_metrics.main(["snapshot", "--state", str(state_path), "--events", str(events)]) == 0
    (row,) = _events(events)
    assert row["type"] == "snapshot" and row["cpp_bytes"] == 0x100


# ---------------------------------------------------------------- backfill
def test_backfill_turns_state_history_into_attempts_finals_and_snapshots(tmp_path):
    state_path = tmp_path / "state.json"
    _state_with_history(tmp_path)
    events = tmp_path / "events.jsonl"
    written = ralph_metrics.backfill(state_path, events)
    rows = _events(events)
    kinds = [row["type"] for row in rows]
    assert written == len(rows) - 1  # the marker event is not counted
    assert kinds.count("attempt") == 3  # two history items for func_00100000, one for func_00100100
    attempt = next(row for row in rows if row["type"] == "attempt" and row["pct"] == 40.0)
    assert attempt["outcome"] == "backfill" and attempt["seconds"] == 30.0
    finals = {row["func"]: row for row in rows if row["type"] == "slice_final"}
    assert finals["func_00100000"]["status"] == "done" and finals["func_00100000"]["seconds"] == 90.0
    assert finals["func_00100200"]["status"] == "asm"
    assert kinds.count("snapshot") >= 1
    assert rows[-1]["type"] == "backfill"


def test_backfill_is_idempotent(tmp_path):
    state_path = tmp_path / "state.json"
    _state_with_history(tmp_path)
    events = tmp_path / "events.jsonl"
    ralph_metrics.backfill(state_path, events)
    before = events.read_text()
    assert ralph_metrics.backfill(state_path, events) == 0
    assert events.read_text() == before


def test_backfill_snapshots_are_cumulative_over_time(tmp_path):
    state_path = tmp_path / "state.json"
    _state_with_history(tmp_path)
    events = tmp_path / "events.jsonl"
    ralph_metrics.backfill(state_path, events)
    snapshots = [row for row in _events(events) if row["type"] == "snapshot"]
    cpp = [row["cpp_bytes"] for row in snapshots]
    assert cpp == sorted(cpp) and cpp[-1] == 0x100


# ---------------------------------------------------------------- export
def _sample_events(path):
    ralph_metrics.append_event(path, "snapshot", {"covered_bytes": 10, "cpp_bytes": 4, "total_bytes": 100}, now=1.0)
    ralph_metrics.append_event(path, "snapshot", {"covered_bytes": 30, "cpp_bytes": 20, "total_bytes": 100,
                                                  "asm_bytes": 5}, now=2.0)
    ralph_metrics.append_event(path, "attempt", {"func": "f", "pct": 50.0, "agent": "agy", "model": "m",
                                                 "attempt": 1, "seconds": 9.0, "outcome": "retry"}, now=1.5)
    ralph_metrics.append_event(path, "wave", {"index": 1, "size": 2, "wall_seconds": 100.0}, now=2.5)


def test_export_writes_progress_attempts_waves_and_summary(tmp_path):
    events = tmp_path / "events.jsonl"
    _sample_events(events)
    out = tmp_path / "docs-metrics"
    written = ralph_metrics.export(events, out)
    assert sorted(path.name for path in out.iterdir()) == [
        "attempts.csv", "progress.csv", "summary.json", "waves.csv"]
    with (out / "progress.csv").open() as handle:
        rows = list(csv.DictReader(handle))
    assert [row["cpp_bytes"] for row in rows] == ["4", "20"]
    assert "time" in rows[0] and rows[0]["asm_bytes"] == ""  # absent in the first snapshot
    summary = json.loads((out / "summary.json").read_text())
    assert summary["latest_snapshot"]["covered_bytes"] == 30
    assert summary["attempts"] == 1
    assert set(written) == {"progress.csv", "attempts.csv", "waves.csv", "summary.json"}


# ---------------------------------------------------------------- report
def test_report_contains_every_chart_and_escapes_labels(tmp_path):
    events = tmp_path / "events.jsonl"
    _sample_events(events)
    ralph_metrics.append_event(events, "attempt", {"func": "f", "pct": 100.0, "agent": "agy",
                                                   "model": "<evil>", "attempt": 1, "seconds": 5.0,
                                                   "outcome": "done"}, now=3.0)
    ralph_metrics.append_event(events, "agent_failure", {"func": "f", "class": "quota", "attempt": 1}, now=4.0)
    ralph_metrics.append_event(events, "slice_final", {"func": "f", "status": "done", "size": 0x40}, now=3.0)
    out = tmp_path / "report.html"
    ralph_metrics.write_report(events, out)
    html = out.read_text()
    assert html.startswith("<!doctype html>")
    assert html.count("<svg") == 6
    for heading in ("Progresso", "Bytes por hora", "Tempo por tentativa", "Sucesso na 1", "Distribuição", "Falhas"):
        assert heading in html
    assert "&lt;evil&gt;" in html and "<evil>" not in html
    assert "quota" in html


def test_report_without_events_still_renders_a_page(tmp_path):
    out = tmp_path / "report.html"
    ralph_metrics.write_report(tmp_path / "none.jsonl", out)
    html = out.read_text()
    assert "<!doctype html>" in html and "sem dados" in html
