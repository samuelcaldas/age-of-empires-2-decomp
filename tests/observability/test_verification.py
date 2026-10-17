"""A green process is insufficient to certify original instruction ranges."""

import pytest

from scripts.observability.source_policy import source_digest
from scripts.observability.verification import assess_evidence, collect_gate_results

NODE = "tests/check.py::test_exact"


def report(outcome="passed", exit_code=0):
    return dict(collected=[NODE], exit_code=exit_code, outcomes=[
        dict(nodeid=NODE, when=phase, outcome=outcome if phase == "call" else "passed",
             xfail=False) for phase in ("setup", "call", "teardown")])


def entry(root):
    (root / "candidate.cpp").write_text("int value() { return 7; }")
    return dict(sources=["candidate.cpp"], reviewed_digest=source_digest(root, ["candidate.cpp"]),
                ranges=[dict(start=100, end=140, owner="unit", function=True)],
                behavior=[NODE], matching=[NODE])


def test_all_declared_phases_must_pass():
    assert collect_gate_results(report(), [NODE]) == "passed"


@pytest.mark.parametrize("outcome,want", [("failed", "failed"), ("skipped", "skipped")])
def test_nonpasses_are_preserved(outcome, want):
    assert collect_gate_results(report(outcome), [NODE]) == want


def test_missing_declared_nodes_are_unavailable():
    assert collect_gate_results(report(), [NODE, "tests/other.py::test_missing"]) == "unavailable"


def test_failure_in_other_gate_preserves_independent_success():
    value = report()
    other = dict(nodeid="tests/other.py::test_failure", when="call", outcome="failed", xfail=False)
    value["outcomes"].append(other)
    value["collected"].append(other["nodeid"])
    value["exit_code"] = 1
    assert collect_gate_results(value, [NODE]) == "passed"


def test_no_collected_tests_cannot_pass():
    assert collect_gate_results(dict(collected=[], outcomes=[], exit_code=0), [NODE]) != "passed"


def test_xfail_or_partial_phases_cannot_pass():
    value = report()
    value["outcomes"][1]["xfail"] = True
    assert collect_gate_results(value, [NODE]) != "passed"
    value = report()
    value["outcomes"].pop()
    assert collect_gate_results(value, [NODE]) != "passed"


def test_fresh_reviewed_exact_and_native_evidence_certifies_ranges(tmp_path):
    item = entry(tmp_path)
    identity = dict(commit="a" * 40, tree="b" * 40, original="c" * 40,
                    compiler="d" * 64, config="e" * 64, verifier="f" * 64)
    result = assess_evidence(item, tmp_path, identity, identity,
                             dict(behavior=report(), matching=report()))
    assert result["state"] == "verified"
    assert result["ranges"] == [dict(start=100, end=140, owner="unit", function=True)]


@pytest.mark.parametrize("identity", ["tree", "original", "compiler", "config", "verifier"])
def test_changed_verification_inputs_invalidate_results(tmp_path, identity):
    result = assess_evidence(entry(tmp_path), tmp_path, {identity: "before"},
                             {identity: "after"}, dict(behavior=report(), matching=report()))
    assert result["state"] == "blocked"
    assert result["errors"] == ["INPUT_CHANGED"]
    assert result["ranges"] == []


def test_native_success_does_not_replace_matching(tmp_path):
    result = assess_evidence(entry(tmp_path), tmp_path, {}, {},
                             dict(behavior=report(), matching=report("skipped")))
    assert result["state"] == "blocked"
    assert result["ranges"] == []


def test_actual_assertion_failure_is_failed(tmp_path):
    result = assess_evidence(entry(tmp_path), tmp_path, {}, {},
                             dict(behavior=report("failed", 1), matching=report()))
    assert result["state"] == "failed"
    assert result["ranges"] == []


def test_changed_source_is_not_certified(tmp_path):
    item = entry(tmp_path)
    (tmp_path / "candidate.cpp").write_text("int value() { return 8; }")
    result = assess_evidence(item, tmp_path, {}, {}, dict(behavior=report(), matching=report()))
    assert result["state"] == "blocked"
    assert result["errors"] == ["SOURCE_NOT_REVIEWED"]
