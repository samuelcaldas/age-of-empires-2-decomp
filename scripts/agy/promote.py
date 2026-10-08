"""Post-run step for `fetch-official`: verify a downloaded original, then copy it into `orig/`.

The model reports a source URL, a file path, and a SHA-1. None of these is
trusted. This module checks the URL against `allowed_sources.yml`, checks the
file's real SHA-1 against the expected value given by the caller, and only
then copies the file into the main checkout. An existing file with different
content is never overwritten.
"""

import hashlib
import shutil
from pathlib import Path, PurePosixPath

import yaml

from errors import AgyDelegationError
from profiles import AGY_DIR

ALLOWED_SOURCES_PATH = AGY_DIR / "allowed_sources.yml"
CHUNK_BYTES = 1 << 20


class PromotionError(AgyDelegationError):
    """A downloaded file failed a check, so it was not copied into `orig/`."""


def load_allowed_prefixes(path: Path = ALLOWED_SOURCES_PATH) -> tuple[str, ...]:
    """Return the URL prefixes listed under `sources` in the allowlist file."""
    data = yaml.safe_load(path.read_text(encoding="utf-8")) or {}
    return tuple(entry["prefix"] for entry in data.get("sources", []))


def promote_official_binary(
    repo_root: Path,
    worktree: Path,
    version: str,
    expected_sha1: str,
    output: dict,
    allowed_prefixes: tuple[str, ...],
) -> Path:
    """Copy the verified file from the worktree into `orig/<version>/`.

    Returns:
        The path of the file in the main checkout.

    Raises:
        PromotionError: the URL is not allowed, the path is outside
            `orig/<version>/`, the SHA-1 does not match, or the target exists
            with different content.
    """
    _check_source(output.get("source_url", ""), allowed_prefixes)
    relative = _check_location(output.get("file_path", ""), version)
    source = worktree / relative
    _check_digest(source, expected_sha1, output.get("sha1", ""))
    return _copy_into_checkout(repo_root, source, relative)


def _check_source(url: str, allowed_prefixes: tuple[str, ...]) -> None:
    if not any(url.startswith(prefix) for prefix in allowed_prefixes):
        raise PromotionError(f"source not in allowed_sources.yml: {url!r}")


def _check_location(file_path: str, version: str) -> str:
    parts = PurePosixPath(file_path).parts
    expected_head = ("orig", version)
    if parts[:2] != expected_head or ".." in parts or len(parts) < 3:
        raise PromotionError(f"file_path must sit under orig/{version}/: {file_path!r}")
    return file_path


def _check_digest(source: Path, expected_sha1: str, reported_sha1: str) -> None:
    if not source.is_file():
        raise PromotionError(f"downloaded file not found in worktree: {source}")
    actual = _sha1_of(source)
    expected = expected_sha1.lower()
    if actual != expected or reported_sha1.lower() != expected:
        raise PromotionError(f"SHA-1 mismatch for {source.name}: expected {expected}, file {actual}")


def _sha1_of(path: Path) -> str:
    digest = hashlib.sha1(usedforsecurity=False)
    with path.open("rb") as handle:
        for chunk in iter(lambda: handle.read(CHUNK_BYTES), b""):
            digest.update(chunk)
    return digest.hexdigest()


def _copy_into_checkout(repo_root: Path, source: Path, relative: str) -> Path:
    target = repo_root / relative
    if target.exists():
        return _accept_existing(target, source)
    target.parent.mkdir(parents=True, exist_ok=True)
    temporary = target.with_suffix(target.suffix + ".tmp")
    shutil.copyfile(source, temporary)
    temporary.replace(target)
    return target


def _accept_existing(target: Path, source: Path) -> Path:
    if _sha1_of(target) != _sha1_of(source):
        raise PromotionError(f"refusing to overwrite {target} with different content")
    return target
