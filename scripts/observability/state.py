"""Read-only state loading; display commands never initialize or mutate a store."""

from contextlib import closing
from datetime import datetime, timezone
import json
from pathlib import Path
import sqlite3

from .identity import first_parent_history, resolve_repository
from .projection import build_projection
from .queue import _record
from .snapshot import make_snapshot


def read_state(common_dir):
    """Read a consistent SQLite view without creating files or changing schema."""
    database = Path(common_dir) / "observability/metrics.sqlite"
    if not database.is_file():
        return dict(snapshots=[], pending=[], events=[])
    with closing(sqlite3.connect(database.as_uri() + "?mode=ro", uri=True)) as connection:
        connection.row_factory = sqlite3.Row
        connection.execute("BEGIN")
        return _read_records(connection)


def _read_records(connection):
    snapshots = connection.execute("SELECT payload FROM snapshots ORDER BY sequence,rowid").fetchall()
    events = connection.execute("SELECT payload FROM events ORDER BY id").fetchall()
    rows = connection.execute("SELECT * FROM requests WHERE state!='done' ORDER BY sequence").fetchall()
    return dict(snapshots=[json.loads(row[0]) for row in snapshots],
                events=[json.loads(row[0]) for row in events],
                pending=[dict(_record(connection, row), state=row["state"]) for row in rows])


def _pending_snapshot(claim, events):
    relevant = [event for event in events if event.get("attempt_id") == claim["attempt_id"]]
    timestamp = relevant[0].get("at", "1970-01-01T00:00:00Z") if relevant else "1970-01-01T00:00:00Z"
    assessment = dict(state=claim["state"], ranges=[], errors=[],
                      gates=dict(behavior="not-run", matching="not-run"))
    result = make_snapshot(claim, {}, assessment, timestamp)
    result["times"].update(finished=None, collected=timestamp)
    return result


def load_projection(root, edition="SLES-50282"):
    """Project local evidence and outstanding queue state for one edition."""
    repository = resolve_repository(root)
    commits = first_parent_history(root, repository["default_branch"])
    state = read_state(repository["common_dir"])
    snapshots = state["snapshots"] + [_pending_snapshot(claim, state["events"]) for claim in state["pending"]]
    selected = [snapshot for snapshot in snapshots if snapshot["edition"] == edition]
    graph = dict(commits=commits, anchor=commits[0], head=repository["commit"],
                 source_head=commits[-1], edition=edition)
    return build_projection(selected, graph, datetime.now(timezone.utc))
