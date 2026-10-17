"""Transactional worktree-shared evidence storage."""

import json
from pathlib import Path

from .database import initialize, transaction
from .model import canonical_bytes, content_digest, validate_snapshot
from . import queue


def _save_snapshot(connection, snapshot):
    payload = canonical_bytes(validate_snapshot(snapshot)).decode()
    row = connection.execute("SELECT payload FROM snapshots WHERE attempt=? AND state=?",
                             (snapshot["attempt_id"], snapshot["state"])).fetchone()
    if row is not None:
        if row[0] != payload:
            raise ValueError("immutable snapshot conflict")
        return
    connection.execute("INSERT INTO snapshots VALUES (?,?,?,?,?)",
                       (content_digest(snapshot), snapshot["attempt_id"], snapshot["state"],
                        snapshot["sequence"], payload))


def _complete_claim(connection, claim, snapshot):
    row = connection.execute("SELECT state,token FROM requests WHERE key=?", (claim["key"],)).fetchone()
    if row is None or row["state"] != "running" or row["token"] != claim["token"]:
        raise ValueError("stale verification lease")
    if snapshot["attempt_id"] != claim["attempt_id"]:
        raise ValueError("snapshot does not match lease identity")
    _save_snapshot(connection, snapshot)
    connection.execute("UPDATE requests SET state='done',token=NULL WHERE key=?", (claim["key"],))
    queue.record_event(connection, dict(state=snapshot["state"], attempt_id=claim["attempt_id"]))


class MetricsStore:
    """Persist validated records below the common Git directory, not a worktree."""

    def __init__(self, common_dir):
        self.directory = Path(common_dir) / "observability"
        initialize(self.directory)

    def enqueue(self, request, *, force=False):
        """Enqueue a validated content-bound request idempotently."""
        with transaction(self.directory, write=True) as connection:
            return queue.enqueue(connection, request, force=force)

    def claim(self, worker_id, lease_seconds=300, now=None, key=None):
        """Claim the oldest pending request exclusively or return None."""
        with transaction(self.directory, write=True) as connection:
            return queue.claim(connection, worker_id, lease_seconds, now, key)

    def append_event(self, event):
        """Append a bounded private event; never export it without sanitization."""
        with transaction(self.directory, write=True) as connection:
            queue.record_event(connection, event)

    def record_snapshot(self, snapshot):
        """Store an immutable valid snapshot; conflicting contents raise ValueError."""
        with transaction(self.directory, write=True) as connection:
            _save_snapshot(connection, snapshot)

    def complete(self, claim, snapshot):
        """Complete a valid current lease atomically or reject a stale worker."""
        with transaction(self.directory, write=True) as connection:
            _complete_claim(connection, claim, snapshot)

    def read_snapshots(self):
        """Return immutable records ordered by producer sequence."""
        with transaction(self.directory) as connection:
            rows = connection.execute("SELECT payload FROM snapshots ORDER BY sequence,rowid").fetchall()
        return [json.loads(row[0]) for row in rows]

    def read_events(self):
        """Return private queue/diagnostic events in append order."""
        with transaction(self.directory) as connection:
            rows = connection.execute("SELECT payload FROM events ORDER BY id").fetchall()
        return [json.loads(row[0]) for row in rows]
