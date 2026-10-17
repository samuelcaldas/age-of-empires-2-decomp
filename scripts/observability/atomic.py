"""Atomic derivative JSON artifacts, with unique same-filesystem temporaries."""

import os
from pathlib import Path
import tempfile

from .model import canonical_bytes


def write_atomic(path, data):
    """Atomically replace JSON; preserve old contents and clean temporary on failure."""
    target = Path(path)
    target.parent.mkdir(parents=True, exist_ok=True)
    descriptor, name = tempfile.mkstemp(prefix=".metrics-", dir=target.parent)
    try:
        _write_and_replace(descriptor, name, target, data)
    finally:
        Path(name).unlink(missing_ok=True)


def _write_and_replace(descriptor, temporary, target, data):
    with os.fdopen(descriptor, "wb") as handle:
        handle.write(canonical_bytes(data) + b"\n")
        handle.flush()
        os.fsync(handle.fileno())
    os.replace(temporary, target)
    directory = os.open(target.parent, os.O_RDONLY | os.O_DIRECTORY)
    try:
        os.fsync(directory)
    finally:
        os.close(directory)
