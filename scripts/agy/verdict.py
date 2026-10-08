"""Turn one agy run and its observed changes into a final state.

Precedence matters. A scope violation is `rejected` even when the run also
timed out or produced valid output, because the changes cannot be trusted.
Only a clean, in-scope run with a schema-valid result is `done`.
"""

import json
from dataclasses import dataclass

from agy_client import AgyRun, parse_output
from guard import disallowed_paths
from profiles import Profile
from schema_check import SchemaViolation, validate

DONE = "done"
FAILED = "failed"
REJECTED = "rejected"
TERMINAL_STATES = (DONE, FAILED, REJECTED)


@dataclass(frozen=True)
class Verdict:
    """The final state of a run, with the reasons and the validated output."""

    state: str
    reasons: list[str]
    output: dict | None
    conversation_id: str | None
    usage: dict | None


def judge(profile: Profile, writes: tuple[str, ...], run: AgyRun, changes: list[str], main_changes: list[str]) -> Verdict:
    """Return the verdict for one run. `writes` is the profile's pattern list, rendered."""
    scope_reasons = _scope_reasons(writes, changes, main_changes)
    if scope_reasons:
        return Verdict(REJECTED, scope_reasons, None, None, None)
    envelope = parse_output(run.stdout)
    failure = _run_failure(run, envelope)
    if failure:
        return Verdict(FAILED, [failure], None, _field(envelope, "conversation_id"), _field(envelope, "usage"))
    return _check_output(profile, envelope)


def _scope_reasons(writes: tuple[str, ...], changes: list[str], main_changes: list[str]) -> list[str]:
    reasons = []
    outside = disallowed_paths(changes, writes)
    if outside:
        reasons.append(f"paths outside the profile's writes list: {outside}")
    if main_changes:
        reasons.append(f"main checkout changed during the run: {main_changes}")
    return reasons


def _run_failure(run: AgyRun, envelope: dict | None) -> str | None:
    if run.timed_out:
        return "timed out"
    if run.returncode != 0:
        return f"agy exited with code {run.returncode}"
    if envelope is None:
        return "agy stdout is not a JSON object"
    if envelope.get("status") != "SUCCESS":
        return f"agy reported status {envelope.get('status')!r}"
    return None


def _check_output(profile: Profile, envelope: dict) -> Verdict:
    output = envelope.get("structured_output")
    conversation_id = envelope.get("conversation_id")
    usage = envelope.get("usage")
    if not isinstance(output, dict):
        return Verdict(FAILED, ["agy returned no structured_output"], None, conversation_id, usage)
    try:
        validate(output, json.loads(profile.schema_path.read_text(encoding="utf-8")))
    except SchemaViolation as error:
        return Verdict(FAILED, [f"output does not match schema: {error}"], None, conversation_id, usage)
    return Verdict(DONE, [], output, conversation_id, usage)


def _field(envelope: dict | None, key: str):
    return envelope.get(key) if envelope else None
