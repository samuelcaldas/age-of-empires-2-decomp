"""Structured metrics for scripts/ralph_decomp.sh: event log, backfill, CSV export and an HTML report.

Events are JSON lines in build/ralph/metrics/events.jsonl. Only the sequential part of the loop writes them.
Stdlib only: the report draws SVG directly, so no plotting package is needed.
"""

from __future__ import annotations

import argparse
import csv
import html
import json
import time
from pathlib import Path
from typing import Dict, List, Optional, Sequence, Tuple

import ralph_slice

EVENT_TYPES = ("attempt", "slice_final", "wave", "snapshot", "agent_failure", "backfill")
SNAPSHOT_KEYS = ("total_bytes", "covered_bytes", "cpp_bytes", "asm_bytes", "partial_bytes", "blocked_bytes",
                 "total_seconds")
FINISHED_STATUSES = ("done", "asm", "partial", "blocked")
PALETTE = ("#1b6ca8", "#c2410c", "#7c3aed", "#15803d", "#be123c")
CHART_WIDTH, CHART_HEIGHT, CHART_PAD = 760, 260, 40
NO_DATA = "sem dados"


def coerce(raw: str):
    """CLI values: ints (decimal or 0x hex), floats, otherwise text."""
    try:
        return int(raw, 0)
    except ValueError:
        pass
    try:
        return float(raw)
    except ValueError:
        return raw


def fields_from_pairs(pairs: Sequence[str]) -> dict:
    """Turn ``key=value`` arguments into a dict with coerced values."""
    fields = {}
    for pair in pairs:
        key, separator, value = pair.partition("=")
        if not separator or not key:
            raise ValueError(f"expected key=value, got {pair!r}")
        fields[key] = coerce(value)
    return fields


def append_event(events: Path, kind: str, fields: dict, now: Optional[float] = None) -> dict:
    """Append one event as a JSON line and return it."""
    if kind not in EVENT_TYPES:
        raise ValueError(f"unknown event type {kind!r}; expected one of {EVENT_TYPES}")
    event = {"ts": time.time() if now is None else now, "type": kind, **fields}
    path = Path(events)
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a") as handle:
        handle.write(json.dumps(event, sort_keys=True) + "\n")
    return event


def read_events(events: Path) -> List[dict]:
    path = Path(events)
    if not path.is_file():
        return []
    return [json.loads(line) for line in path.read_text().splitlines() if line.strip()]


def snapshot_fields(state: ralph_slice.LoopState, symbols_text: str, text_start: int, text_end: int) -> dict:
    """Progress numbers at this moment: bytes per status plus slice counts."""
    summary = ralph_slice.summarize(state, symbols_text, text_start, text_end)
    fields = {key: summary[key] for key in SNAPSHOT_KEYS}
    for status, count in summary["counts"].items():
        fields[f"count_{status}"] = count
    return fields


def _symbols_text() -> str:
    return ralph_slice.SYMBOLS_TXT.read_text() if ralph_slice.SYMBOLS_TXT.is_file() else ""


def backfill(state_path: Path, events: Path, text_start: int = ralph_slice.TEXT_START,
             text_end: int = ralph_slice.TEXT_END) -> int:
    """Create events from ``state.json`` history. Runs once per events file; returns the events written."""
    if any(row.get("type") == "backfill" for row in read_events(events)):
        return 0
    slices = ralph_slice.LoopState(state_path).data["slices"]
    generated = backfill_events(slices, text_start, text_end)
    for ts, kind, fields in generated:
        append_event(events, kind, fields, now=ts)
    append_event(events, "backfill", {"events": len(generated), "source": str(state_path)})
    return len(generated)


def backfill_events(slices: dict, text_start: int, text_end: int) -> List[Tuple[float, str, dict]]:
    """(timestamp, type, fields) tuples for attempts, final slice states and cumulative snapshots."""
    stamps = [item["timestamp"] for entry in slices.values() for item in entry.get("history", [])]
    fallback = min(stamps) if stamps else 0.0
    generated: List[Tuple[float, str, dict]] = []
    finals: List[Tuple[float, str, dict]] = []
    for entry in slices.values():
        history = entry.get("history", [])
        for number, item in enumerate(history, start=1):
            generated.append((item["timestamp"], "attempt", {
                "func": entry["func"], "vram": entry["vram"], "size": entry["size"], "attempt": number,
                "agent": "unknown", "model": "unknown", "pct": item["pct"], "seconds": item["seconds"],
                "outcome": "backfill"}))
        if entry["status"] in FINISHED_STATUSES:
            ts = history[-1]["timestamp"] if history else fallback
            finals.append((ts, "slice_final", {
                "func": entry["func"], "vram": entry["vram"], "size": entry["size"], "status": entry["status"],
                "attempts": entry.get("attempts", len(history)), "pct": entry.get("pct", 0.0),
                "seconds": sum(item["seconds"] for item in history)}))
    generated.extend(finals)
    generated.extend(_cumulative_snapshots(finals, text_start, text_end))
    return sorted(generated, key=lambda item: item[0])


def _cumulative_snapshots(finals: List[Tuple[float, str, dict]], text_start: int, text_end: int):
    totals = {status: 0 for status in FINISHED_STATUSES}
    snapshots = []
    for ts, _kind, fields in sorted(finals, key=lambda item: item[0]):
        totals[fields["status"]] += fields["size"]
        snapshots.append((ts, "snapshot", {
            "source": "backfill", "total_bytes": text_end - text_start,
            "cpp_bytes": totals["done"], "asm_bytes": totals["asm"],
            "partial_bytes": totals["partial"], "blocked_bytes": totals["blocked"],
            "covered_bytes": totals["done"] + totals["asm"]}))
    return snapshots


def export(events: Path, out_dir: Path) -> List[str]:
    """Write progress/attempts/waves CSV and a summary JSON. Returns the file names written."""
    rows = read_events(events)
    out = Path(out_dir)
    out.mkdir(parents=True, exist_ok=True)
    snapshots = [_flat(row) for row in rows if row["type"] == "snapshot"]
    attempts = [_flat(row) for row in rows if row["type"] == "attempt"]
    waves = [_flat(row) for row in rows if row["type"] == "wave"]
    _write_csv(out / "progress.csv", snapshots)
    _write_csv(out / "attempts.csv", attempts)
    _write_csv(out / "waves.csv", waves)
    summary = {"generated_at": _iso(time.time()), "events": len(rows), "attempts": len(attempts),
               "waves": len(waves), "latest_snapshot": snapshots[-1] if snapshots else None}
    (out / "summary.json").write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n")
    return ["progress.csv", "attempts.csv", "waves.csv", "summary.json"]


def _flat(row: dict) -> dict:
    flat = {key: value for key, value in row.items() if key != "type"}
    return {"time": _iso(row["ts"]), **flat}


def _iso(ts: float) -> str:
    return time.strftime("%Y-%m-%dT%H:%M:%S", time.localtime(ts))


def _write_csv(path: Path, rows: List[dict]) -> None:
    fields: List[str] = []
    for row in rows:
        fields.extend(key for key in row if key not in fields)
    with path.open("w", newline="") as handle:
        if not fields:
            return
        writer = csv.DictWriter(handle, fieldnames=fields)
        writer.writeheader()
        writer.writerows(rows)


# ---------------------------------------------------------------- HTML report
def write_report(events: Path, out: Path) -> None:
    Path(out).parent.mkdir(parents=True, exist_ok=True)
    Path(out).write_text(build_report(read_events(events)))


def build_report(rows: List[dict]) -> str:
    snapshots = [row for row in rows if row["type"] == "snapshot"]
    attempts = [row for row in rows if row["type"] == "attempt"]
    finals = [row for row in rows if row["type"] == "slice_final"]
    failures = [row for row in rows if row["type"] == "agent_failure"]
    charts = [
        _progress_chart(snapshots),
        _bar_chart("Bytes por hora (C/C++ finalizado)", _bytes_per_hour(finals), "bytes"),
        _bar_chart("Tempo por tentativa (s, média por modelo)", _mean_seconds_by_model(attempts), "s"),
        _bar_chart("Sucesso na 1ª tentativa por modelo (%)", _first_attempt_rate(attempts), "%"),
        _bar_chart("Distribuição da similaridade (faixas de 10%)", _pct_histogram(attempts), ""),
        _bar_chart("Falhas de agente por classe", _count_by(failures, "class"), ""),
    ]
    body = "\n".join(charts)
    return _page(_summary_line(snapshots, attempts), body)


def _summary_line(snapshots: List[dict], attempts: List[dict]) -> str:
    if not snapshots:
        return f"<p>{NO_DATA}</p>"
    last = snapshots[-1]
    total = last.get("total_bytes") or 1
    return (f"<p>Último instante ({html.escape(_iso(last['ts']))}): C/C++ real "
            f"{100 * last.get('cpp_bytes', 0) / total:.2f}% · asm {100 * last.get('asm_bytes', 0) / total:.2f}% · "
            f"parcial {100 * last.get('partial_bytes', 0) / total:.2f}% · tentativas registradas: {len(attempts)}</p>")


def _progress_chart(snapshots: List[dict]) -> str:
    snaps = sorted(snapshots, key=lambda row: row["ts"])
    series = []
    for key, label in (("cpp_bytes", "C/C++ real"), ("asm_bytes", "asm"), ("partial_bytes", "parcial"),
                       ("covered_bytes", "coberto (total)")):
        points = [(row["ts"], 100 * row.get(key, 0) / (row.get("total_bytes") or 1)) for row in snaps
                  if row.get("total_bytes")]
        series.append((label, points))
    return _line_chart("Progresso do .text (%)", series)


def _bytes_per_hour(finals: List[dict]) -> List[Tuple[str, float]]:
    buckets: Dict[int, float] = {}
    for row in finals:
        if row["status"] == "done":
            hour = int(row["ts"] // 3600)
            buckets[hour] = buckets.get(hour, 0) + row["size"]
    return [(time.strftime("%d/%m %Hh", time.localtime(hour * 3600)), buckets[hour]) for hour in sorted(buckets)]


def _mean_seconds_by_model(attempts: List[dict]) -> List[Tuple[str, float]]:
    groups: Dict[str, List[float]] = {}
    for row in attempts:
        if row.get("outcome") != "backfill" and row.get("seconds", 0) > 0:
            groups.setdefault(str(row.get("model", "?")), []).append(row["seconds"])
    return [(model, sum(values) / len(values)) for model, values in sorted(groups.items())]


def _first_attempt_rate(attempts: List[dict]) -> List[Tuple[str, float]]:
    groups: Dict[str, List[bool]] = {}
    for row in attempts:
        if row.get("attempt") == 1 and row.get("outcome") != "backfill":
            groups.setdefault(str(row.get("model", "?")), []).append(row.get("pct", 0) >= 100)
    return [(model, 100 * sum(flags) / len(flags)) for model, flags in sorted(groups.items())]


def _pct_histogram(attempts: List[dict]) -> List[Tuple[str, float]]:
    labels = [f"{low}–{low + 9}" for low in range(0, 100, 10)] + ["100"]
    counts = [0.0] * len(labels)
    for row in attempts:
        if "pct" in row:
            counts[10 if row["pct"] >= 100 else int(row["pct"] // 10)] += 1
    return list(zip(labels, counts))


def _count_by(rows: List[dict], key: str) -> List[Tuple[str, float]]:
    counts: Dict[str, float] = {}
    for row in rows:
        label = str(row.get(key, "?"))
        counts[label] = counts.get(label, 0) + 1
    return sorted(counts.items())


def _page(summary: str, body: str) -> str:
    return f"""<!doctype html>
<html lang="pt-BR">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Ralph decomp: métricas</title>
<style>
:root {{ color-scheme: light dark; --fg: #1f2933; --bg: #ffffff; --muted: #6b7280; }}
@media (prefers-color-scheme: dark) {{ :root:not([data-theme="light"]) {{ --fg: #e5e7eb; --bg: #111827; --muted: #9ca3af; }} }}
:root[data-theme="dark"] {{ --fg: #e5e7eb; --bg: #111827; --muted: #9ca3af; }}
body {{ background: var(--bg); color: var(--fg); font-family: system-ui, sans-serif; margin: 16px; }}
figure {{ margin: 24px 0; }}
figcaption {{ font-weight: 600; margin-bottom: 8px; }}
svg {{ max-width: 100%; height: auto; }}
text {{ fill: var(--fg); font-size: 11px; }}
</style>
</head>
<body>
<h1>Ralph decomp: métricas</h1>
{summary}
{body}
</body>
</html>
"""


def _empty_chart(title: str) -> str:
    return _figure(title, f'<text x="{CHART_WIDTH / 2}" y="{CHART_HEIGHT / 2}" text-anchor="middle">{NO_DATA}</text>')


def _figure(title: str, inner: str) -> str:
    return (f'<figure><figcaption>{html.escape(title)}</figcaption>'
            f'<svg viewBox="0 0 {CHART_WIDTH} {CHART_HEIGHT}" role="img" aria-label="{html.escape(title)}">'
            f"{inner}</svg></figure>")


def _line_chart(title: str, series: List[Tuple[str, List[Tuple[float, float]]]]) -> str:
    points = [point for _, values in series for point in values]
    if not points:
        return _empty_chart(title)
    x_lo, x_hi = min(x for x, _ in points), max(x for x, _ in points)
    body, legend = [], []
    for index, (label, values) in enumerate(series):
        if not values:
            continue
        color = PALETTE[index % len(PALETTE)]
        coords = " ".join(f"{_scale(x, x_lo, x_hi, CHART_PAD, CHART_WIDTH - CHART_PAD):.1f},"
                          f"{_scale(y, 0, 100, CHART_HEIGHT - CHART_PAD, CHART_PAD):.1f}" for x, y in values)
        body.append(f'<polyline fill="none" stroke="{color}" stroke-width="2" points="{coords}"/>')
        legend.append(f'<text x="{CHART_PAD + 130 * len(legend)}" y="{CHART_PAD / 2}" fill="{color}">'
                      f"{html.escape(label)}</text>")
    axis = (f'<line x1="{CHART_PAD}" y1="{CHART_HEIGHT - CHART_PAD}" x2="{CHART_WIDTH - CHART_PAD}" '
            f'y2="{CHART_HEIGHT - CHART_PAD}" stroke="#9ca3af"/>')
    return _figure(title, axis + "".join(legend) + "".join(body))


def _bar_chart(title: str, bars: List[Tuple[str, float]], unit: str) -> str:
    if not bars:
        return _empty_chart(title)
    top = max(value for _, value in bars) or 1
    slot = (CHART_WIDTH - 2 * CHART_PAD) / len(bars)
    inner, usable = [], CHART_HEIGHT - 2 * CHART_PAD
    for index, (label, value) in enumerate(bars):
        height = value / top * usable
        x = CHART_PAD + index * slot + slot * 0.15
        y = CHART_HEIGHT - CHART_PAD - height
        inner.append(f'<rect x="{x:.1f}" y="{y:.1f}" width="{slot * 0.7:.1f}" height="{height:.1f}" '
                     f'fill="{PALETTE[0]}"/>')
        suffix = "%" if unit == "%" else ""
        inner.append(f'<text x="{x + slot * 0.35:.1f}" y="{y - 4:.1f}" text-anchor="middle">'
                     f"{_format_value(value)}{suffix}</text>")
        inner.append(f'<text x="{x + slot * 0.35:.1f}" y="{CHART_HEIGHT - CHART_PAD + 14}" '
                     f'text-anchor="middle">{html.escape(label[:14])}</text>')
    return _figure(title, "".join(inner))


def _format_value(value: float) -> str:
    return f"{value:.0f}" if value >= 100 or float(value).is_integer() else f"{value:.1f}"


def _scale(value: float, lo: float, hi: float, out_lo: float, out_hi: float) -> float:
    if hi == lo:
        return (out_lo + out_hi) / 2
    return out_lo + (value - lo) * (out_hi - out_lo) / (hi - lo)


# ---------------------------------------------------------------- CLI
def _command_record(args: argparse.Namespace) -> int:
    append_event(args.events, args.type, fields_from_pairs(args.fields))
    return 0


def _command_snapshot(args: argparse.Namespace) -> int:
    state = ralph_slice.LoopState(args.state)
    append_event(args.events, "snapshot", snapshot_fields(state, _symbols_text(),
                                                          ralph_slice.TEXT_START, ralph_slice.TEXT_END))
    return 0


def _command_backfill(args: argparse.Namespace) -> int:
    print(json.dumps({"written": backfill(args.state, args.events)}))
    return 0


def _command_export(args: argparse.Namespace) -> int:
    print(json.dumps({"written": export(args.events, args.out)}))
    return 0


def _command_report(args: argparse.Namespace) -> int:
    write_report(args.events, args.out)
    print(json.dumps({"report": str(args.out)}))
    return 0


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    record = sub.add_parser("record", help="Append one event: record --type attempt key=value ...")
    record.add_argument("--events", type=Path, required=True)
    record.add_argument("--type", required=True, choices=EVENT_TYPES)
    record.add_argument("fields", nargs="*")
    record.set_defaults(handler=_command_record)
    snapshot = sub.add_parser("snapshot", help="Append a progress snapshot of state.json")
    snapshot.add_argument("--state", type=Path, required=True)
    snapshot.add_argument("--events", type=Path, required=True)
    snapshot.set_defaults(handler=_command_snapshot)
    backfill_cmd = sub.add_parser("backfill", help="Create events from state.json history (once per file)")
    backfill_cmd.add_argument("--state", type=Path, required=True)
    backfill_cmd.add_argument("--events", type=Path, required=True)
    backfill_cmd.set_defaults(handler=_command_backfill)
    export_cmd = sub.add_parser("export", help="Write CSV and JSON files for docs/metrics/")
    export_cmd.add_argument("--events", type=Path, required=True)
    export_cmd.add_argument("--out", type=Path, required=True)
    export_cmd.set_defaults(handler=_command_export)
    report = sub.add_parser("report", help="Write a static HTML report with inline SVG charts")
    report.add_argument("--events", type=Path, required=True)
    report.add_argument("--out", type=Path, required=True)
    report.set_defaults(handler=_command_report)
    return parser


def main(argv: Optional[Sequence[str]] = None) -> int:
    args = build_parser().parse_args(argv)
    return args.handler(args)


if __name__ == "__main__":
    raise SystemExit(main())
