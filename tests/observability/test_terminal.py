"""Readable terminal values come from the same projection as JSON and web."""

from datetime import datetime, timezone
from io import StringIO

from rich.console import Console

from scripts.observability.projection import build_projection
from scripts.observability.terminal import _frame, render_terminal
from .fixtures import snapshot


def render(width):
    projection = build_projection([snapshot()], dict(commits=["a" * 40], head="a" * 40),
                                  datetime(2026, 10, 17, tzinfo=timezone.utc))
    buffer = StringIO()
    Console(file=buffer, width=width, color_system=None).print(
        render_terminal(projection, width=width, color=False))
    return buffer.getvalue()


def test_terminal_shows_actual_bytes_and_unknown_total():
    value = render(100)
    assert "40" in value
    assert "unknown" in value
    assert "aaaaaaaa" in value


def test_terminal_resizes_without_ansi_or_inferred_agents():
    value = render(40)
    assert value.strip()
    assert "\x1b[" not in value
    assert "not configured" in value


def test_refresh_failure_is_visible_instead_of_stale_green():
    def unavailable():
        raise OSError("private diagnostic must not be rendered")

    frame = _frame(unavailable, Console(width=80))
    assert "refresh failed" in frame.plain
    assert "private diagnostic" not in frame.plain
