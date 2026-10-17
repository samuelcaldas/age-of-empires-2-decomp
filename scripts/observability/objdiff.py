"""Observed objdiff inventory, explicitly not verified C++ coverage."""

import hashlib
import json
from pathlib import Path

from .ranges import MAX_INTEGER

MEASURES = ("total_code", "matched_code", "total_units", "total_functions")


def _integer(value):
    if isinstance(value, str) and value.isascii() and value.isdigit():
        value = int(value)
    if type(value) is not int or not 0 <= value <= MAX_INTEGER:
        raise ValueError("invalid objdiff inventory size")
    return value


def read_objdiff_report(path):
    """Read bounded diagnostic counts; no report certifies source eligibility."""
    target = Path(path)
    if not target.is_file():
        return None
    if target.stat().st_size > 64 * 1024 * 1024:
        raise ValueError("objdiff report exceeds size limit")
    raw = target.read_bytes()
    measures = json.loads(raw)["measures"]
    result = {key: _integer(measures.get(key, 0)) for key in MEASURES}
    return dict(result, report_digest=hashlib.sha256(raw).hexdigest(), verified=False)
