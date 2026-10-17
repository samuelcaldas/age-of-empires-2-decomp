"""Small transactional SQLite boundary for shared local state."""

from contextlib import contextmanager
from pathlib import Path
import sqlite3
import uuid

SCHEMA = (
    "CREATE TABLE IF NOT EXISTS metadata (key TEXT PRIMARY KEY, value TEXT NOT NULL)",
    "CREATE TABLE IF NOT EXISTS requests (sequence INTEGER PRIMARY KEY AUTOINCREMENT, "
    "key TEXT UNIQUE NOT NULL, payload TEXT NOT NULL, state TEXT NOT NULL, "
    "worker TEXT, lease REAL, token TEXT)",
    "CREATE TABLE IF NOT EXISTS snapshots (id TEXT PRIMARY KEY, attempt TEXT NOT NULL, "
    "state TEXT NOT NULL, sequence INTEGER NOT NULL, payload TEXT NOT NULL, UNIQUE(attempt,state))",
    "CREATE TABLE IF NOT EXISTS events (id INTEGER PRIMARY KEY AUTOINCREMENT, payload TEXT NOT NULL)",
)


@contextmanager
def transaction(directory, *, write=False):
    """Yield a transaction and always close the connection, including on error."""
    connection = sqlite3.connect(Path(directory) / "metrics.sqlite", timeout=10)
    connection.row_factory = sqlite3.Row
    try:
        connection.execute("BEGIN IMMEDIATE" if write else "BEGIN")
        yield connection
        connection.commit()
    except (sqlite3.Error, ValueError, OSError):
        connection.rollback()
        raise
    finally:
        connection.close()


def initialize(directory):
    """Create the private store and its single pseudonymous producer identity."""
    Path(directory).mkdir(parents=True, exist_ok=True, mode=0o700)
    with transaction(directory, write=True) as connection:
        _initialize_tables(connection)


def _initialize_tables(connection):
    for statement in SCHEMA:
        connection.execute(statement)
    connection.execute("INSERT OR IGNORE INTO metadata VALUES ('producer', ?)",
                       (uuid.uuid4().hex,))
