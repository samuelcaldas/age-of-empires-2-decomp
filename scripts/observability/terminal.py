"""Tmux-friendly rendering of the shared projection, without duplicate arithmetic."""

import sqlite3
import time

from rich.console import Console
from rich.live import Live
from rich.table import Table
from rich.text import Text


def _number(value, suffix=""):
    if value is None:
        return "unavailable"
    return f"{value:g}{suffix}"


def _identities(value):
    return [("HEAD", value["head_commit"][:12]),
            ("Default branch", value["source_head_commit"][:12]),
            ("Last measured", (value["measured_commit"] or "unknown")[:12]),
            ("Last verified UTC", value["last_verified_at"] or "unknown"),
            ("Freshness", "stale / historical" if value["stale"] else "recent"),
            ("Agents", "not configured")]


def _metrics(value):
    return [("State", value["state"] + (" / " + value["reason"] if value["reason"] else "")),
            ("Verified C++ bytes", _number(value["verified_cpp_bytes"], " B")),
            ("Historical verified", _number(value["last_verified_cpp_bytes"], " B")),
            ("Global code total", "unknown" if value["denominator"]["bytes"] is None else str(value["denominator"]["bytes"])),
            ("Global coverage", _number(value["global_percent"], "%")),
            ("24h net speed", _number(value["rates"]["24h"]["bytes_per_hour"], " B/h")),
            ("7d net speed", _number(value["rates"]["7d"]["bytes_per_hour"], " B/h")),
            ("ETA central", _number(value["eta"]["central_days"], " days")),
            ("Scope", f"audited lower bound; {value['enrolled_units']} enrolled units")]


def render_terminal(projection, *, width=100, color=True):
    """Render explicit current/historical values for any terminal width."""
    table = Table.grid(expand=True, padding=(0, 1))
    table.add_column(max_width=min(24, max(12, width // 2)))
    table.add_column(ratio=1, overflow="fold")
    table.add_row(Text("AoE II / " + projection["edition"], style="bold"), "LOCAL EVIDENCE")
    for label, value in _metrics(projection) + _identities(projection):
        table.add_row(Text(label), Text(value))
    return table


def _frame(loader, console):
    try:
        return render_terminal(loader(), width=console.size.width)
    except (OSError, ValueError, sqlite3.Error):
        return Text("unavailable: refresh failed; previous evidence is not current")


def watch_terminal(loader, *, interval=5, once=False, no_color=False):
    """Watch offline state until Ctrl+C; no-color/non-TTY output remains readable."""
    console = Console(no_color=no_color)
    if once:
        console.print(_frame(loader, console))
        return
    with Live(_frame(loader, console), console=console, auto_refresh=False) as live:
        _watch_loop(live, loader, console, interval)


def _watch_loop(live, loader, console, interval):
    while True:
        time.sleep(interval)
        live.update(_frame(loader, console), refresh=True)
