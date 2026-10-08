"""Tests for the agy delegation tools. They use a fake agy and a temporary git repo; no network."""

import hashlib
import json
from pathlib import Path

import pytest
from conftest import BINARY_BYTES, invocation_count, invocation_prompts

import delegate
from agy_client import AGY_ENV_VAR, resolve_agy
from errors import AgyDelegationError, AgyUnavailableError, InputError, ProfileError
from guard import disallowed_paths
from orchestrate import BatchError, load_batch, run_batch
from profiles import load_profile
from promote import PromotionError, load_allowed_prefixes, promote_official_binary
from schema_check import SchemaViolation, validate
from verdict import DONE, FAILED, REJECTED

RESEARCH_OUTPUT = {"summary": "s", "findings": [], "sources_consulted": [], "limitations": "none"}
DOC_OUTPUT = {"doc_path": "docs/new.md", "summary": "s", "open_questions": []}
BINARY = "orig/AGE2/age2.icd"


def run_profile(repo: Path, agy: str, profile: str, inputs: dict[str, str], **kwargs) -> dict:
    return delegate.run_task(repo, profile, inputs, agy, **kwargs)


def set_output(monkeypatch: pytest.MonkeyPatch, output: dict | str) -> None:
    monkeypatch.setenv("AGY_STUB_OUTPUT", output if isinstance(output, str) else json.dumps(output))


def research(repo: Path, agy: str, question: str = "q") -> dict:
    return run_profile(repo, agy, "research", {"question": question})


# --- profiles -------------------------------------------------------------------

def test_loads_every_shipped_profile() -> None:
    for name in ("research", "fetch-official", "binary-analysis", "splat-split", "doc-draft"):
        assert load_profile(name).name == name


def test_read_only_profiles_declare_no_writes() -> None:
    assert load_profile("research").is_read_only
    assert load_profile("binary-analysis").is_read_only
    assert not load_profile("doc-draft").is_read_only


def test_unknown_profile_is_rejected() -> None:
    with pytest.raises(ProfileError, match="unknown profile"):
        load_profile("does-not-exist")


@pytest.mark.parametrize("name", ["../research", "Research", "a/b", ""])
def test_malformed_profile_name_is_rejected(name: str) -> None:
    with pytest.raises(ProfileError, match="invalid profile name"):
        load_profile(name)


def _write_profile(directory: Path, body: str) -> None:
    (directory / "bad.yml").write_text(body, encoding="utf-8")


BASE_PROFILE = """\
description: test
model: m
effort: low
mode: plan
timeout_seconds: 10
schema: research.json
prompt: hi
"""


@pytest.mark.parametrize(
    "replacement,message",
    [
        (("mode: plan", "mode: yolo"), "mode must be one of"),
        (("effort: low", "effort: extreme"), "effort must be one of"),
        (("timeout_seconds: 10", "timeout_seconds: 0"), "positive integer"),
        (("schema: research.json", "schema: missing.json"), "schema file not found"),
        (("model: m", "model: gemini-3.1-pro-high"), "fixes effort to high"),
    ],
)
def test_invalid_profile_fields_are_rejected(tmp_path: Path, replacement: tuple[str, str], message: str) -> None:
    old, new = replacement
    _write_profile(tmp_path, BASE_PROFILE.replace(old, new))
    with pytest.raises(ProfileError, match=message):
        load_profile("bad", tmp_path)


def test_write_pattern_escaping_the_repo_is_rejected(tmp_path: Path) -> None:
    _write_profile(tmp_path, BASE_PROFILE + "writes:\n  - '../outside/*'\n")
    with pytest.raises(ProfileError, match="relative and inside the repo"):
        load_profile("bad", tmp_path)


# --- schema subset --------------------------------------------------------------

SCHEMA = {
    "type": "object",
    "additionalProperties": False,
    "required": ["name", "count"],
    "properties": {
        "name": {"type": "string"},
        "count": {"type": "integer"},
        "kind": {"type": "string", "enum": ["a", "b"]},
        "tags": {"type": "array", "items": {"type": "string"}},
    },
}


def test_schema_accepts_a_matching_value() -> None:
    validate({"name": "x", "count": 2, "kind": "a", "tags": ["t"]}, SCHEMA)


@pytest.mark.parametrize(
    "value,message",
    [
        ({"count": 2}, "missing required property 'name'"),
        ({"name": "x", "count": "2"}, "expected integer"),
        ({"name": "x", "count": True}, "expected integer"),
        ({"name": "x", "count": 2, "extra": 1}, "unexpected properties"),
        ({"name": "x", "count": 2, "kind": "c"}, "not one of"),
        ({"name": "x", "count": 2, "tags": [1]}, r"\$\.tags\[0\]"),
    ],
)
def test_schema_rejects_mismatches(value: dict, message: str) -> None:
    with pytest.raises(SchemaViolation, match=message):
        validate(value, SCHEMA)


# --- scope ----------------------------------------------------------------------

def test_disallowed_paths_treats_empty_writes_as_read_only() -> None:
    assert disallowed_paths(["docs/a.md"], ()) == ["docs/a.md"]


def test_disallowed_paths_allows_matching_patterns_only() -> None:
    paths = ["docs/a.md", "docs/sub/b.md", "configure.py"]
    assert disallowed_paths(paths, ("docs/*",)) == ["configure.py"]


# --- inputs ---------------------------------------------------------------------

def test_missing_required_input_is_rejected_before_any_work(repo: Path, fake_agy: str) -> None:
    with pytest.raises(InputError, match="missing required inputs"):
        run_profile(repo, fake_agy, "binary-analysis", {})
    assert not (repo / ".worktrees").exists()


def test_unknown_input_is_rejected(repo: Path, fake_agy: str) -> None:
    with pytest.raises(InputError, match="unknown inputs"):
        run_profile(repo, fake_agy, "research", {"question": "q", "extra": "x"})


def test_path_input_outside_the_repo_is_rejected(repo: Path, fake_agy: str, tmp_path: Path) -> None:
    outside = tmp_path / "outside.bin"
    outside.write_bytes(b"x")
    with pytest.raises(InputError, match="outside the repository"):
        run_profile(repo, fake_agy, "binary-analysis", {"binary": str(outside)})


def test_empty_input_is_rejected(repo: Path, fake_agy: str) -> None:
    with pytest.raises(InputError, match="is empty"):
        research(repo, fake_agy, question="   ")


def test_missing_agy_is_reported(repo: Path, tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> None:
    monkeypatch.setenv(AGY_ENV_VAR, str(tmp_path / "no-such-agy"))
    with pytest.raises(AgyUnavailableError):
        resolve_agy(None)


# --- read-only runs -------------------------------------------------------------

def test_read_only_run_completes_and_records_output(repo: Path, fake_agy: str, monkeypatch) -> None:
    set_output(monkeypatch, RESEARCH_OUTPUT)
    result = research(repo, fake_agy)
    assert result["state"] == DONE
    assert result["output"] == RESEARCH_OUTPUT
    assert result["changed_files"] == []
    assert (Path(result["run_dir"]) / "result.json").is_file()
    assert (Path(result["run_dir"]) / "meta.json").is_file()


def test_read_only_run_that_writes_in_worktree_is_rejected(repo: Path, fake_agy: str, monkeypatch) -> None:
    set_output(monkeypatch, RESEARCH_OUTPUT)
    monkeypatch.setenv("AGY_STUB_ACTION", "write")
    monkeypatch.setenv("AGY_STUB_PATH", "docs/x.md")
    result = research(repo, fake_agy)
    assert result["state"] == REJECTED
    assert result["changed_files"] == ["docs/x.md"]
    assert "outside the profile's writes list" in result["reasons"][0]


def test_read_only_run_that_writes_to_main_checkout_is_rejected(repo: Path, fake_agy: str, monkeypatch) -> None:
    set_output(monkeypatch, RESEARCH_OUTPUT)
    monkeypatch.setenv("AGY_STUB_ACTION", "write_abs")
    monkeypatch.setenv("AGY_STUB_PATH", str(repo / "notes.txt"))
    result = research(repo, fake_agy)
    assert result["state"] == REJECTED
    assert any("main checkout changed" in reason for reason in result["reasons"])


def test_read_only_run_with_a_commit_is_still_rejected(repo: Path, fake_agy: str, monkeypatch) -> None:
    set_output(monkeypatch, RESEARCH_OUTPUT)
    monkeypatch.setenv("AGY_STUB_ACTION", "commit")
    monkeypatch.setenv("AGY_STUB_PATH", "docs/committed.md")
    result = research(repo, fake_agy)
    assert result["state"] == REJECTED
    assert "docs/committed.md" in result["changed_files"]


# --- write runs -----------------------------------------------------------------

def test_write_run_within_scope_is_done(repo: Path, fake_agy: str, monkeypatch) -> None:
    set_output(monkeypatch, DOC_OUTPUT)
    monkeypatch.setenv("AGY_STUB_ACTION", "write")
    monkeypatch.setenv("AGY_STUB_PATH", "docs/new.md")
    result = run_profile(repo, fake_agy, "doc-draft", {"topic": "t", "target": "docs/new.md", "findings": "f"})
    assert result["state"] == DONE
    assert result["changed_files"] == ["docs/new.md"]
    assert not (repo / "docs" / "new.md").exists()


def test_write_run_touching_configure_py_is_rejected_and_main_is_untouched(repo: Path, fake_agy: str, monkeypatch) -> None:
    set_output(monkeypatch, DOC_OUTPUT)
    monkeypatch.setenv("AGY_STUB_ACTION", "write")
    monkeypatch.setenv("AGY_STUB_PATH", "configure.py")
    monkeypatch.setenv("AGY_STUB_CONTENT", "# hacked\n")
    result = run_profile(repo, fake_agy, "doc-draft", {"topic": "t", "target": "docs/x.md", "findings": "f"})
    assert result["state"] == REJECTED
    assert result["changed_files"] == ["configure.py"]
    assert (repo / "configure.py").read_text(encoding="utf-8") == "# original\n"


def test_schema_violation_is_failed(repo: Path, fake_agy: str, monkeypatch) -> None:
    set_output(monkeypatch, {"summary": "s"})
    result = research(repo, fake_agy)
    assert result["state"] == FAILED
    assert "does not match schema" in result["reasons"][0]


def test_missing_structured_output_is_failed(repo: Path, fake_agy: str, monkeypatch) -> None:
    set_output(monkeypatch, "none")
    result = research(repo, fake_agy)
    assert result["state"] == FAILED
    assert "no structured_output" in result["reasons"][0]


def test_non_success_status_is_failed(repo: Path, fake_agy: str, monkeypatch) -> None:
    set_output(monkeypatch, RESEARCH_OUTPUT)
    monkeypatch.setenv("AGY_STUB_STATUS", "FAILURE")
    result = research(repo, fake_agy)
    assert result["state"] == FAILED
    assert "status" in result["reasons"][0]


def test_nonzero_exit_is_failed(repo: Path, fake_agy: str, monkeypatch) -> None:
    monkeypatch.setenv("AGY_STUB_ACTION", "exit3")
    result = research(repo, fake_agy)
    assert result["state"] == FAILED
    assert "exited with code 3" in result["reasons"][0]


def test_timeout_is_failed_and_killed(repo: Path, fake_agy: str, monkeypatch) -> None:
    monkeypatch.setenv("AGY_STUB_ACTION", "sleep")
    result = run_profile(repo, fake_agy, "research", {"question": "q"}, timeout_seconds=1, grace_seconds=1)
    assert result["state"] == FAILED
    assert result["reasons"] == ["timed out"]


# --- idempotency ----------------------------------------------------------------

def test_completed_run_is_reused_without_calling_agy(repo: Path, fake_agy: str, monkeypatch, tmp_path: Path) -> None:
    set_output(monkeypatch, RESEARCH_OUTPUT)
    first = research(repo, fake_agy)
    second = research(repo, fake_agy)
    assert first["reused"] is False
    assert second["reused"] is True
    assert second["output"] == RESEARCH_OUTPUT
    assert invocation_count(tmp_path) == 1


def test_failed_run_is_retried(repo: Path, fake_agy: str, monkeypatch, tmp_path: Path) -> None:
    monkeypatch.setenv("AGY_STUB_ACTION", "exit3")
    research(repo, fake_agy)
    monkeypatch.setenv("AGY_STUB_ACTION", "none")
    set_output(monkeypatch, RESEARCH_OUTPUT)
    result = research(repo, fake_agy)
    assert result["state"] == DONE
    assert invocation_count(tmp_path) == 2


def test_changed_input_is_a_different_run(repo: Path, fake_agy: str, monkeypatch, tmp_path: Path) -> None:
    set_output(monkeypatch, RESEARCH_OUTPUT)
    first = research(repo, fake_agy, question="one")
    second = research(repo, fake_agy, question="two")
    assert first["key"] != second["key"]
    assert invocation_count(tmp_path) == 2


def test_binary_input_is_hashed_into_the_run(repo: Path, fake_agy: str, monkeypatch) -> None:
    set_output(monkeypatch, {"file_name": "age2.icd", "size_bytes": 1, "sha1": "x", "format": "PE",
                             "linker_version": "6.0", "whole_file_entropy": 7.9, "sections": [], "notes": ""})
    result = run_profile(repo, fake_agy, "binary-analysis", {"binary": BINARY})
    meta = json.loads((Path(result["run_dir"]) / "meta.json").read_text(encoding="utf-8"))
    binary_input = next(item for item in meta["inputs"] if item["name"] == "binary")
    assert binary_input["sha256"] == hashlib.sha256(BINARY_BYTES).hexdigest()


def test_prompt_contains_the_rendered_input(repo: Path, fake_agy: str, monkeypatch, tmp_path: Path) -> None:
    set_output(monkeypatch, RESEARCH_OUTPUT)
    research(repo, fake_agy, question="distinctive-marker")
    assert "distinctive-marker" in invocation_prompts(tmp_path)[0]


# --- fetch-official promotion ---------------------------------------------------

FETCH_CONTENT = b"fetched original bytes"
FETCH_SHA1 = hashlib.sha1(FETCH_CONTENT).hexdigest()


def _fetch(repo: Path, agy: str, monkeypatch, *, url: str, sha1: str, expected: str | None = None) -> dict:
    set_output(monkeypatch, {"source_url": url, "file_path": "orig/AGE2/age2.exe", "sha1": sha1})
    monkeypatch.setenv("AGY_STUB_ACTION", "write")
    monkeypatch.setenv("AGY_STUB_PATH", "orig/AGE2/age2.exe")
    monkeypatch.setenv("AGY_STUB_CONTENT", FETCH_CONTENT.decode())
    inputs = {"version": "AGE2", "file_name": "age2.exe", "expected_sha1": expected or FETCH_SHA1}
    return run_profile(repo, agy, "fetch-official", inputs)


def test_fetch_official_promotes_a_verified_file(repo: Path, fake_agy: str, monkeypatch) -> None:
    result = _fetch(repo, fake_agy, monkeypatch, url="https://support.microsoft.com/x", sha1=FETCH_SHA1)
    assert result["state"] == DONE
    assert result["promoted_to"] == str(repo / "orig" / "AGE2" / "age2.exe")
    assert (repo / "orig" / "AGE2" / "age2.exe").read_bytes() == FETCH_CONTENT


def test_fetch_official_rejects_a_source_outside_the_allowlist(repo: Path, fake_agy: str, monkeypatch) -> None:
    result = _fetch(repo, fake_agy, monkeypatch, url="https://example.invalid/age2.exe", sha1=FETCH_SHA1)
    assert result["state"] == FAILED
    assert "not in allowed_sources.yml" in result["reasons"][0]
    assert not (repo / "orig" / "AGE2" / "age2.exe").exists()


def test_fetch_official_rejects_a_sha1_mismatch(repo: Path, fake_agy: str, monkeypatch) -> None:
    result = _fetch(repo, fake_agy, monkeypatch, url="https://support.microsoft.com/x", sha1="0" * 40)
    assert result["state"] == FAILED
    assert "SHA-1 mismatch" in result["reasons"][0]
    assert not (repo / "orig" / "AGE2" / "age2.exe").exists()


def test_promotion_refuses_to_overwrite_different_content(repo: Path, tmp_path: Path) -> None:
    worktree = tmp_path / "wt"
    (worktree / "orig" / "AGE2").mkdir(parents=True)
    (worktree / "orig" / "AGE2" / "age2.exe").write_bytes(FETCH_CONTENT)
    (repo / "orig" / "AGE2" / "age2.exe").write_bytes(b"different")
    output = {"source_url": "https://support.microsoft.com/x", "file_path": "orig/AGE2/age2.exe", "sha1": FETCH_SHA1}
    with pytest.raises(PromotionError, match="refusing to overwrite"):
        promote_official_binary(repo, worktree, "AGE2", FETCH_SHA1, output, load_allowed_prefixes())


def test_promotion_rejects_paths_outside_the_version_folder(repo: Path, tmp_path: Path) -> None:
    output = {"source_url": "https://support.microsoft.com/x", "file_path": "orig/OTHER/age2.exe", "sha1": FETCH_SHA1}
    with pytest.raises(PromotionError, match="must sit under"):
        promote_official_binary(repo, tmp_path, "AGE2", FETCH_SHA1, output, load_allowed_prefixes())


# --- batches --------------------------------------------------------------------

def _batch_file(directory: Path, body: str) -> Path:
    path = directory / "batch.yml"
    path.write_text(body, encoding="utf-8")
    return path


BATCH = """\
name: first
max_parallel: 3
tasks:
  - id: alpha
    profile: research
    inputs: {question: alpha-question}
  - id: beta
    profile: research
    inputs: {question: beta-question}
    depends_on: [alpha]
  - id: gamma
    profile: research
    inputs: {question: gamma-question}
"""


def test_batch_runs_dependencies_in_order(repo: Path, fake_agy: str, monkeypatch, tmp_path: Path) -> None:
    set_output(monkeypatch, RESEARCH_OUTPUT)
    batch = load_batch(_batch_file(tmp_path, BATCH))
    summary = run_batch(repo, batch, fake_agy)
    assert {task["state"] for task in summary["tasks"].values()} == {DONE}
    prompts = invocation_prompts(tmp_path)
    alpha_index = next(i for i, text in enumerate(prompts) if "alpha-question" in text)
    beta_index = next(i for i, text in enumerate(prompts) if "beta-question" in text)
    assert beta_index > alpha_index


def test_rerunning_a_batch_repeats_no_work(repo: Path, fake_agy: str, monkeypatch, tmp_path: Path) -> None:
    set_output(monkeypatch, RESEARCH_OUTPUT)
    batch = load_batch(_batch_file(tmp_path, BATCH))
    run_batch(repo, batch, fake_agy)
    first_count = invocation_count(tmp_path)
    summary = run_batch(repo, batch, fake_agy)
    assert invocation_count(tmp_path) == first_count
    assert all(task["reused"] for task in summary["tasks"].values())


def test_failed_dependency_blocks_its_dependents(repo: Path, fake_agy: str, monkeypatch, tmp_path: Path) -> None:
    monkeypatch.setenv("AGY_STUB_ACTION", "exit3")
    batch = load_batch(_batch_file(tmp_path, BATCH))
    summary = run_batch(repo, batch, fake_agy)
    assert summary["tasks"]["alpha"]["state"] == FAILED
    assert summary["tasks"]["beta"]["state"] == FAILED
    assert summary["tasks"]["beta"]["reasons"] == ["dependency alpha is failed"]


def test_dependency_cycle_is_reported_not_hung(repo: Path, fake_agy: str, tmp_path: Path) -> None:
    cyclic = _batch_file(
        tmp_path,
        "tasks:\n"
        "  - id: a\n    profile: research\n    inputs: {question: q}\n    depends_on: [b]\n"
        "  - id: b\n    profile: research\n    inputs: {question: q}\n    depends_on: [a]\n",
    )
    summary = run_batch(repo, load_batch(cyclic), fake_agy)
    assert {task["state"] for task in summary["tasks"].values()} == {FAILED}


@pytest.mark.parametrize(
    "body,message",
    [
        ("tasks:\n  - id: a\n    profile: research\n  - id: a\n    profile: research\n", "duplicate task ids"),
        ("tasks:\n  - id: a\n    profile: research\n    depends_on: [zz]\n", "unknown tasks"),
        ("max_parallel: 0\ntasks:\n  - id: a\n    profile: research\n", "max_parallel"),
        ("tasks: []\n", "no tasks"),
        ("tasks:\n  - id: Bad_ID\n    profile: research\n", "invalid task id"),
    ],
)
def test_invalid_batch_is_rejected(tmp_path: Path, body: str, message: str) -> None:
    with pytest.raises(BatchError, match=message):
        load_batch(_batch_file(tmp_path, body))


def test_error_type_is_shared_across_modules() -> None:
    assert issubclass(BatchError, AgyDelegationError)
    assert issubclass(PromotionError, AgyDelegationError)
