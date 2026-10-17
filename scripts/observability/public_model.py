"""Strict public bundle schema, with local-only schema resolution."""

import copy
import json

from jsonschema import Draft202012Validator, FormatChecker, ValidationError
from referencing import Registry, Resource

from .model import SCHEMA_PATH, canonical_bytes, content_digest, validate_snapshot
from .ranges import function_count, union_code_bytes

REPOSITORY = "samuelcaldas/age-of-empires-2-decomp"


def validate_public_bundle(bundle):
    """Return a safe isolated bundle or reject unknown fields/inconsistent claims."""
    snapshot_schema = json.loads(SCHEMA_PATH.read_text())
    schema = json.loads(SCHEMA_PATH.with_name("bundle-v1.schema.json").read_text())
    registry = Registry().with_resource("urn:aoe:snapshot:v1", Resource.from_contents(snapshot_schema))
    try:
        Draft202012Validator(schema, registry=registry, format_checker=FormatChecker()).validate(bundle)
    except ValidationError as error:
        raise ValueError("invalid public bundle at " + ".".join(map(str, error.absolute_path))) from error
    canonical_bytes(bundle)
    _check_claims(bundle)
    return copy.deepcopy(bundle)


def _check_claims(bundle):
    snapshots = [validate_snapshot(value) for value in bundle["snapshots"]]
    projection = bundle["projection"]
    digests = {content_digest(value) for value in snapshots}
    for name in ("latest_attempt", "last_successful"):
        _check_reference(projection[name], digests)
    success = projection["last_successful"]
    expected = union_code_bytes(success["ranges"]) if success else None
    if projection["last_verified_cpp_bytes"] != expected:
        raise ValueError("historical byte claim does not match its evidence")
    _check_current(projection)


def _check_reference(snapshot, digests):
    if snapshot is not None:
        validate_snapshot(snapshot)
        if content_digest(snapshot) not in digests:
            raise ValueError("projection references absent evidence")


def _check_current(projection):
    if projection["state"] != "verified":
        if projection["verified_cpp_bytes"] is not None:
            raise ValueError("unverified current status cannot claim verified bytes")
        return
    current = projection["latest_attempt"]
    if not current or current["state"] != "verified":
        raise ValueError("current verified status lacks verified evidence")
    if projection["verified_cpp_bytes"] != union_code_bytes(current["ranges"]):
        raise ValueError("current byte claim does not match evidence")
    if projection["functions"] != function_count(current["ranges"]):
        raise ValueError("function count does not match evidence")
