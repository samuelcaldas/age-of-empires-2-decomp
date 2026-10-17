"""Public artifacts are strict, bounded metadata, never arbitrary local files."""

from datetime import datetime, timezone
import json

import pytest

from scripts.observability.projection import build_projection
from scripts.observability.publication import (make_public_bundle, read_bundle,
                                               validate_bundle, write_bundle)
from .fixtures import snapshot


def bundle():
    value = snapshot()
    projection = build_projection([value], dict(commits=["a" * 40], head="a" * 40),
                                  datetime(2026, 10, 17, 0, 2, tzinfo=timezone.utc))
    return make_public_bundle([value], projection)


def test_same_verified_bytes_are_exported_without_recalculation():
    value = bundle()
    assert value.get("schema_version") == 1
    assert value["projection"]["verified_cpp_bytes"] == 40
    assert value["projection"]["global_percent"] is None
    assert value["snapshots"][0]["ranges"][0]["end"] == 140


def test_raw_private_fields_are_rejected():
    value = bundle()
    value["private_log"] = "/home/private/secret"
    with pytest.raises(ValueError):
        validate_bundle(value)


def test_free_text_in_projection_is_not_a_public_channel():
    value = bundle()
    if "projection" not in value:
        value["projection"] = {}
    value["projection"]["reason"] = "password=secret"
    with pytest.raises(ValueError):
        validate_bundle(value)


def test_manifest_materializes_and_roundtrips(tmp_path):
    value = bundle()
    manifest = write_bundle(value, tmp_path / "public")
    assert manifest.get("schema_version") == 1
    assert (tmp_path / "public/data/latest.json").is_file()
    assert read_bundle(tmp_path / "public") == value


def test_manifest_path_escape_is_rejected_without_reading_target(tmp_path):
    data = dict(schema_version=1, files={"../secret.json": "a" * 64})
    (tmp_path / "manifest.json").write_text(json.dumps(data))
    with pytest.raises(ValueError):
        read_bundle(tmp_path)


def test_symlinked_public_file_is_rejected(tmp_path):
    public = tmp_path / "public"
    write_bundle(bundle(), public)
    target = public / "data/latest.json"
    if not target.is_file():
        assert target.is_file(), "public latest artifact is missing"
    original = tmp_path / "private.json"
    target.replace(original)
    target.symlink_to(original)
    with pytest.raises(ValueError):
        read_bundle(public)
