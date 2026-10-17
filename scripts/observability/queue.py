"""Transactional, content-bound queue with expiring worker leases."""

import json
import math
import re
import time
import uuid

from .model import EDITIONS, canonical_bytes, content_digest

REQUEST_FIELDS = {"commit", "tree", "edition", "profile", "fingerprint"}


def validate_request(request):
    """Reject arbitrary queue payloads before storing a verification request."""
    if set(request) != REQUEST_FIELDS or request["edition"] not in EDITIONS:
        raise ValueError("invalid queue request")
    if request["profile"] != "audited":
        raise ValueError("unsupported verification profile")
    identities = (request["commit"], request["tree"], request["fingerprint"])
    if any(not isinstance(item, str) or not re.fullmatch(r"[0-9a-f]{40}|[0-9a-f]{64}", item)
           for item in identities):
        raise ValueError("invalid request fingerprint")


def record_event(connection, event):
    """Append a local event; these private records are never published directly."""
    payload = canonical_bytes(event).decode()
    if len(payload) > 65536:
        raise ValueError("event exceeds size limit")
    connection.execute("INSERT INTO events(payload) VALUES (?)", (payload,))


def _record(connection, row):
    producer = connection.execute("SELECT value FROM metadata WHERE key='producer'").fetchone()[0]
    return dict(request=json.loads(row["payload"]), sequence=row["sequence"],
                key=row["key"], producer=producer,
                attempt_id=content_digest([producer, row["sequence"], row["key"]]))


def enqueue(connection, request):
    """Enqueue once per content identity and return its shared attempt record."""
    validate_request(request)
    key = content_digest(request)
    row = connection.execute("SELECT * FROM requests WHERE key=?", (key,)).fetchone()
    if row is not None:
        return _record(connection, row)
    connection.execute("INSERT INTO requests(key,payload,state) VALUES (?,?,'pending')",
                       (key, canonical_bytes(request).decode()))
    row = connection.execute("SELECT * FROM requests WHERE key=?", (key,)).fetchone()
    result = _record(connection, row)
    record_event(connection, dict(state="pending", attempt_id=result["attempt_id"],
                                  sequence=result["sequence"], request=request))
    return result


def _recover_expired(connection, now):
    rows = connection.execute("SELECT * FROM requests WHERE state='running' AND lease<=?",
                              (now,)).fetchall()
    for row in rows:
        record_event(connection, dict(state="blocked", code="WORKER_LOST", key=row["key"]))
    connection.execute("UPDATE requests SET state='pending',token=NULL WHERE state='running' AND lease<=?", (now,))


def claim(connection, worker_id, lease_seconds, now=None):
    """Claim with a fencing token; expired claims are explicitly recovered."""
    if not math.isfinite(lease_seconds) or lease_seconds <= 0:
        raise ValueError("lease must be positive and finite")
    if not re.fullmatch(r"[a-zA-Z0-9_-]{1,80}", worker_id):
        raise ValueError("invalid worker identity")
    moment = time.time() if now is None else now
    _recover_expired(connection, moment)
    row = connection.execute("SELECT * FROM requests WHERE state='pending' ORDER BY sequence LIMIT 1").fetchone()
    if row is None:
        return None
    return _claim_row(connection, row, worker_id, moment + lease_seconds)


def _claim_row(connection, row, worker, deadline):
    token = uuid.uuid4().hex
    connection.execute("UPDATE requests SET state='running',worker=?,lease=?,token=? WHERE key=?",
                       (worker, deadline, token, row["key"]))
    result = dict(_record(connection, row), token=token)
    record_event(connection, dict(state="running", attempt_id=result["attempt_id"]))
    return result
