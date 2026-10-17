"""Strict public-safe evidence boundary and canonical identities."""

import copy
import hashlib
import json
from pathlib import Path

from jsonschema import Draft202012Validator, FormatChecker, ValidationError

from .ranges import union_code_bytes, validate_ownership

SCHEMA_PATH = Path(__file__).resolve().parents[2] / "schemas/observability/snapshot-v1.schema.json"
EDITIONS = ("SLES-50282", "SLPM-62076", "AGE2_X1_1_0C_EN", "EMPIRES2_2_0A_EN")


def canonical_bytes(data):
    """Serialize a finite JSON value deterministically or raise ValueError."""
    return json.dumps(data, sort_keys=True, separators=(",", ":"), allow_nan=False).encode()


def content_digest(data):
    """Return a SHA-256 identity of canonical JSON, not an authenticity claim."""
    return hashlib.sha256(canonical_bytes(data)).hexdigest()


def _validate_claims(data):
    validate_ownership(data["ranges"])
    if data["state"] != "verified" and data["ranges"]:
        raise ValueError("unverified attempts cannot claim ranges")
    if data["state"] == "verified":
        _validate_verified(data)
    denominator = data["denominator"]
    if denominator["confidence"] == "verified" and denominator["kind"] != "audited_code":
        raise ValueError("denominator is not verified game code")
    if denominator["kind"] == "unknown" and denominator["bytes"] is not None:
        raise ValueError("unknown denominator cannot contain a byte total")


def _validate_verified(data):
    if any(data["gates"][gate] != "passed" for gate in ("matching", "behavior")):
        raise ValueError("verified evidence requires independent gates")
    if not data["evidence"] or not data["fingerprints"]["original"]:
        raise ValueError("verified evidence requires original and evidence identities")
    total = data["denominator"]["bytes"]
    if total is not None and union_code_bytes(data["ranges"]) > total:
        raise ValueError("ranges exceed denominator")


def validate_snapshot(data, *, public=True):
    """Return an isolated valid public-safe snapshot, or raise ValueError."""
    schema = json.loads(SCHEMA_PATH.read_text())
    try:
        Draft202012Validator(schema, format_checker=FormatChecker()).validate(data)
    except ValidationError as error:
        raise ValueError("invalid snapshot at " + ".".join(map(str, error.absolute_path))) from error
    _validate_claims(data)
    return copy.deepcopy(data)
