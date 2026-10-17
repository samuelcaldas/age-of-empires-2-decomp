"""Allowlisted public metadata; transport and credentials live elsewhere."""

import copy
import json
from pathlib import Path

from .artifacts import checked_path, prepare_output, read_manifest, write_manifest
from .atomic import write_atomic
from .model import content_digest, validate_snapshot
from .public_model import REPOSITORY, validate_public_bundle

HISTORY_CHUNK = 500


def validate_bundle(bundle):
    """Reject unknown fields, unsafe values and unsupported public claims."""
    return validate_public_bundle(bundle)


def make_public_bundle(snapshots, projection):
    """Package validated evidence, including explicit pending/historical references."""
    records = {content_digest(value): validate_snapshot(value) for value in snapshots}
    references = (projection["latest_attempt"], projection["last_successful"])
    for value in references:
        if value is not None:
            records[content_digest(value)] = validate_snapshot(value)
    return validate_bundle(dict(schema_version=1, repository=REPOSITORY,
                                snapshots=list(records.values()), projection=projection))


def _bundle_files(bundle):
    projection = copy.deepcopy(bundle["projection"])
    history = projection["history"]
    chunks = {f"data/history/{index // HISTORY_CHUNK:06}.json": history[index:index + HISTORY_CHUNK]
              for index in range(0, len(history), HISTORY_CHUNK)}
    projection["history"] = history[-HISTORY_CHUNK:]
    snapshots = {content_digest(value): value for value in bundle["snapshots"]}
    latest = dict(schema_version=1, repository=REPOSITORY, projection=projection,
                  snapshot_ids=list(snapshots), history_files=list(chunks))
    files = {f"snapshots/{identity}.json": value for identity, value in snapshots.items()}
    return dict(files, **chunks, **{"data/latest.json": latest})


def write_bundle(bundle, output):
    """Write only sanitized JSON paths and an exact file digest manifest."""
    files = _bundle_files(validate_bundle(bundle))
    directory = prepare_output(output, files)
    for name, data in files.items():
        write_atomic(checked_path(directory, name), data)
    return write_manifest(directory, files)


def _read_json(directory, name):
    return json.loads(checked_path(directory, name).read_text())


def read_bundle(directory):
    """Read an entirely checked manifest without links or unlisted payloads."""
    root = Path(directory)
    manifest = read_manifest(root)
    latest = _read_json(root, "data/latest.json")
    if set(latest) != {"schema_version", "repository", "projection", "snapshot_ids", "history_files"}:
        raise ValueError("unexpected latest metadata fields")
    return _reassemble(root, manifest, latest)


def _reassemble(root, manifest, latest):
    names = {f"snapshots/{identity}.json" for identity in latest["snapshot_ids"]}
    expected = names | set(latest["history_files"]) | {"data/latest.json"}
    if expected != set(manifest["files"]):
        raise ValueError("unreferenced or missing public payload")
    snapshots = [_read_json(root, f"snapshots/{identity}.json") for identity in latest["snapshot_ids"]]
    history = [point for name in latest["history_files"] for point in _read_json(root, name)]
    projection = dict(latest["projection"], history=history)
    return validate_bundle(dict(schema_version=latest["schema_version"], repository=latest["repository"],
                                snapshots=snapshots, projection=projection))
