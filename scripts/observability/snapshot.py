"""Create one schema-complete attempt without borrowing a previous success."""

from datetime import datetime, timezone

from .model import content_digest, validate_snapshot


def utc_now():
    """Return a bounded UTC timestamp used only for observation, not ordering."""
    return datetime.now(timezone.utc).isoformat(timespec="seconds").replace("+00:00", "Z")


def make_snapshot(claim, result, assessment, started):
    """Bind assessment, input identities and scope to the queued commit/tree."""
    request = claim["request"]
    identity = result.get("before", {})
    fingerprints = _fingerprints(request, result, identity)
    data = _base(claim, assessment, started)
    data.update(fingerprints=fingerprints, scope=_scope(result), observed=result.get("observed"))
    data["series_id"] = content_digest([request["edition"], "cpp-exact-v1", fingerprints,
                                        result.get("registry_digest"), "audited_lower_bound"])
    return validate_snapshot(data)


def _base(claim, assessment, started):
    request = claim["request"]
    return dict(schema_version=1, collector_version="1", policy_version="cpp-exact-v1",
                series_id="0" * 64, edition=request["edition"], commit=request["commit"],
                tree=request["tree"], producer=claim["producer"], sequence=claim["sequence"],
                attempt_id=claim["attempt_id"], profile=request["profile"], state=assessment["state"],
                times=dict(started=started, finished=utc_now(), collected=utc_now()),
                gates=dict(assessment["gates"], regression="not-run"), ranges=assessment["ranges"],
                denominator=dict(bytes=None, kind="unknown", confidence="unknown", source="unknown"),
                evidence=assessment.get("evidence", []), errors=assessment["errors"])


def _fingerprints(request, result, identity):
    return dict(config=identity.get("config", request["fingerprint"]),
                registry=result.get("registry_digest", request["fingerprint"]),
                inventory=None, original=identity.get("original"), compiler=identity.get("compiler"),
                verifier=identity.get("verifier", request["fingerprint"]))


def _scope(result):
    return dict(kind="audited_lower_bound", complete=False,
                enrolled_units=result.get("enrolled_units", 1 if result.get("entry") else 0),
                observed_units=None, integrated=result.get("integrated", False),
                linked_executable="not-run")
