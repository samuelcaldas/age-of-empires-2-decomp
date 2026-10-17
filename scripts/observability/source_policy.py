"""Conservative source review binding, never a substitute for exact matching."""

import hashlib
import json
from pathlib import Path
import re

ASSEMBLY = re.compile(r"\b(?:asm|__asm|__asm__|_asm)\b|\.(?:word|byte|insn)\b")
INCLUDES = re.compile(r'^\s*#\s*include\s*[<"]([^>"\n]+)[>"]', re.MULTILINE)
MACRO_INCLUDE = re.compile(r'^\s*#\s*include\s+(?![<"])', re.MULTILINE)
SUFFIXES = {".c", ".cc", ".cpp", ".cxx", ".h", ".hpp"}


def _safe_path(checkout, name):
    root = Path(checkout).resolve()
    path = root / name
    if Path(name).is_absolute() or ".." in Path(name).parts:
        raise ValueError("source path escapes checkout")
    if not path.resolve().is_relative_to(root) or path.is_symlink():
        raise ValueError("source path escapes checkout")
    return path


def source_digest(checkout, sources):
    """Bind reviewed relative paths and UTF-8 contents; reject unsafe paths."""
    records = [(name, hashlib.sha256(_safe_path(checkout, name).read_bytes()).hexdigest())
               for name in sorted(sources)]
    encoded = json.dumps(records, separators=(",", ":")).encode()
    return hashlib.sha256(encoded).hexdigest()


def _known_include(name, path, sources):
    candidates = {str(Path(path).parent / name), str(Path("include") / name), name}
    return bool(candidates.intersection(sources))


def _source_status(checkout, name, sources):
    path = _safe_path(checkout, name)
    if path.suffix.lower() not in SUFFIXES:
        return "excluded"
    text = path.read_text(encoding="utf-8")
    if ASSEMBLY.search(text):
        return "excluded"
    if MACRO_INCLUDE.search(text):
        return "unknown"
    if any(not _known_include(item, name, sources) for item in INCLUDES.findall(text)):
        return "unknown"
    return "eligible"


def _reviewed_status(entry, checkout):
    sources = entry.get("sources", [])
    if not sources or len(set(sources)) != len(sources):
        return "unknown"
    statuses = {_source_status(checkout, name, sources) for name in sources}
    if "excluded" in statuses:
        return "excluded"
    if statuses != {"eligible"}:
        return "unknown"
    if source_digest(checkout, sources) != entry.get("reviewed_digest"):
        return "unknown"
    return "eligible"


def classify_source(entry, checkout):
    """Classify a reviewed closure; unreadable, stale or ambiguous means unknown."""
    try:
        return _reviewed_status(entry, checkout)
    except (OSError, UnicodeError, ValueError):
        return "unknown"
