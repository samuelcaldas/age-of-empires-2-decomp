"""Run directories under `build/agy/<key>/` and the JSON records kept in them.

The run key is a hash of everything that decides the outcome: profile file,
schema, rendered prompt, model, effort, and input hashes. The same key means
the same work, so a completed run can be reused instead of repeated.
"""

import hashlib
import json
from pathlib import Path
from typing import Any

from profiles import Profile

RUNS_SUBDIR = Path("build") / "agy"
KEY_LENGTH = 16
CHUNK_BYTES = 1 << 20


def hash_file(path: Path) -> str:
    """Return the SHA-256 hex digest of `path`, read in chunks."""
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for chunk in iter(lambda: handle.read(CHUNK_BYTES), b""):
            digest.update(chunk)
    return digest.hexdigest()


def make_run_key(profile: Profile, prompt: str, fingerprint: list[dict], timeout: int) -> str:
    """Return a stable key for one unit of work.

    The timeout is part of the key: a run that timed out with a short limit
    must not block a later run with a longer one.
    """
    material = {
        "profile": profile.name,
        "schema": profile.schema_path.read_text(encoding="utf-8"),
        "prompt": prompt,
        "model": profile.model,
        "effort": profile.effort,
        "mode": profile.mode,
        "timeout": timeout,
        "inputs": fingerprint,
    }
    encoded = json.dumps(material, sort_keys=True).encode("utf-8")
    return hashlib.sha256(encoded).hexdigest()[:KEY_LENGTH]


def run_directory(repo_root: Path, key: str) -> Path:
    """Return `build/agy/<key>` under the repository, creating it if needed."""
    path = repo_root / RUNS_SUBDIR / key
    path.mkdir(parents=True, exist_ok=True)
    return path


def read_json(path: Path) -> dict | None:
    """Return the parsed JSON at `path`, or None when the file does not exist."""
    if not path.is_file():
        return None
    return json.loads(path.read_text(encoding="utf-8"))


def write_json(path: Path, data: Any) -> None:
    """Write `data` as indented JSON, replacing the file atomically."""
    temporary = path.with_suffix(path.suffix + ".tmp")
    temporary.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    temporary.replace(path)
