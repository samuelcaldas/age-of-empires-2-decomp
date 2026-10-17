"""Bounded, explicit artifact paths; never recursively upload an arbitrary folder."""

import hashlib
import json
from pathlib import Path
import re

from .atomic import write_atomic

DATA_PATH = re.compile(r"(?:data/latest\.json|data/history/[0-9]{6}\.json|snapshots/[0-9a-f]{64}\.json)")
STATIC_PATHS = {"index.html", "styles.css", "app.mjs", "view_model.mjs",
                "chart.mjs", "badges/bytes.svg", "badges/state.svg", "badges/verified-at.svg"}
MAX_FILE_BYTES = 8 * 1024 * 1024


def checked_path(root, name, *, static=False):
    """Reject traversal, links, unknown extensions and paths outside the root."""
    if not isinstance(name, str) or not (DATA_PATH.fullmatch(name) or static and name in STATIC_PATHS):
        raise ValueError("artifact path is not allowlisted")
    directory = Path(root)
    path = directory / name
    chain = (directory, path, *path.parents)
    if any(item.is_symlink() for item in chain):
        raise ValueError("artifact symlinks are forbidden")
    return path


def file_digest(path):
    """Hash an explicitly selected file after enforcing its size limit."""
    if path.stat().st_size > MAX_FILE_BYTES:
        raise ValueError("public artifact exceeds size limit")
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read_manifest(root, *, static=False):
    """Verify every declared file before exposing any payload to a consumer."""
    path = Path(root) / "manifest.json"
    if path.is_symlink() or path.stat().st_size > MAX_FILE_BYTES:
        raise ValueError("unsafe artifact manifest")
    manifest = json.loads(path.read_text())
    if set(manifest) != {"schema_version", "kind", "files"} or manifest["schema_version"] != 1:
        raise ValueError("invalid artifact manifest")
    expected = "observability-site-v1" if static else "observability-data-v1"
    if manifest["kind"] != expected or len(manifest["files"]) > 25000:
        raise ValueError("unexpected artifact manifest kind/size")
    _verify_files(root, manifest["files"], static)
    return manifest


def _verify_files(root, files, static):
    for name, digest in files.items():
        target = checked_path(root, name, static=static)
        if not isinstance(digest, str) or not re.fullmatch(r"[0-9a-f]{64}", digest):
            raise ValueError("invalid artifact digest")
        if file_digest(target) != digest:
            raise ValueError("public artifact digest mismatch")


def prepare_output(root, names, *, static=False):
    """Inspect existing output; never overwrite unrelated files or follow links."""
    directory = Path(root)
    if directory.is_symlink():
        raise ValueError("output root cannot be a symlink")
    if directory.exists() and any(directory.iterdir()):
        _check_existing(directory, set(names), static)
    directory.mkdir(parents=True, exist_ok=True)
    return directory


def _check_existing(root, names, static):
    old = read_manifest(root, static=static)
    existing = {str(path.relative_to(root)) for path in root.rglob("*") if path.is_file() or path.is_symlink()}
    if existing != set(old["files"]) | {"manifest.json"} or not set(old["files"]).issubset(names):
        raise ValueError("output contains unowned or obsolete files; choose a fresh directory")


def write_manifest(root, names, *, static=False):
    """Write an exact selected-file manifest after all payload files exist."""
    kind = "observability-site-v1" if static else "observability-data-v1"
    files = {name: file_digest(checked_path(root, name, static=static)) for name in sorted(names)}
    manifest = dict(schema_version=1, kind=kind, files=files)
    write_atomic(Path(root) / "manifest.json", manifest)
    return manifest
