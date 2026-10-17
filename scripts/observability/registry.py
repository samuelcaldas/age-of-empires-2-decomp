"""Explicit audited verifier enrollment; registry flags are not matching proof."""

import json
from pathlib import Path
import re

from .model import EDITIONS, content_digest
from .ranges import validate_ownership

FIELDS = {"edition", "name", "sources", "reviewed_digest", "behavior", "matching", "ranges"}
SELECTOR = re.compile(r"tests/[A-Za-z0-9_/]+\.py(?:::[A-Za-z0-9_]+)?")


def _validate_entry(entry):
    if set(entry) != FIELDS or entry["edition"] not in EDITIONS:
        raise ValueError("invalid audited registry entry")
    if not re.fullmatch(r"[a-z][a-z0-9_]{0,79}", entry["name"]):
        raise ValueError("invalid registry identity")
    if not re.fullmatch(r"[0-9a-f]{64}", entry["reviewed_digest"]):
        raise ValueError("invalid source review digest")
    _validate_paths(entry)
    validate_ownership(entry["ranges"])


def _validate_paths(entry):
    if not entry["sources"] or any(Path(name).is_absolute() or ".." in Path(name).parts
                                   for name in entry["sources"]):
        raise ValueError("unsafe registry source path")
    selectors = entry["behavior"] + entry["matching"]
    if not entry["behavior"] or not entry["matching"]:
        raise ValueError("both verification gates must be declared")
    if any(not SELECTOR.fullmatch(selector) for selector in selectors):
        raise ValueError("unsafe pytest selector")


def load_registry(path):
    """Load validated explicit enrollment; reject unknown keys and duplicate IDs."""
    data = json.loads(Path(path).read_text())
    if set(data) != {"schema_version", "entries"} or data["schema_version"] != 1:
        raise ValueError("unsupported verifier registry")
    entries = data["entries"]
    for entry in entries:
        _validate_entry(entry)
    identities = [(entry["edition"], entry["name"]) for entry in entries]
    if len(set(identities)) != len(identities):
        raise ValueError("duplicate registry identity")
    return entries


def registry_identity(path):
    """Return the canonical identity of the validated registry."""
    return content_digest(load_registry(path))
