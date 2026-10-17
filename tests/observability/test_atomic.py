"""Interrupted derivative writes must not damage previous evidence."""

import json
import pytest

from scripts.observability import atomic


def test_json_artifact_is_materialized(tmp_path):
    path = tmp_path / "snapshot.json"
    atomic.write_atomic(path, {"value": 7})
    assert path.is_file()
    assert json.loads(path.read_text()) == {"value": 7}


def test_interrupted_replace_preserves_previous_artifact(tmp_path, monkeypatch):
    path = tmp_path / "snapshot.json"
    path.write_text('{"old":true}')

    def interrupted(*arguments):
        raise OSError("interrupted replace")

    monkeypatch.setattr(atomic.os, "replace", interrupted)
    with pytest.raises(OSError, match="interrupted"):
        atomic.write_atomic(path, {"new": True})
    assert json.loads(path.read_text()) == {"old": True}
    assert list(tmp_path.iterdir()) == [path]
