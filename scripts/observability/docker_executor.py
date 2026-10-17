"""Private, network-disabled Docker verification of immutable Git source trees."""

import json
import os
from pathlib import Path
import subprocess
import tempfile

from .execution_inputs import (INPUT_PATHS, combine_entries, entries_for, input_identity,
                               input_paths, request_fingerprint)
from .identity import first_parent_history, resolve_repository
from .objdiff import read_objdiff_report
from .registry import registry_identity
from .staging import prepare_checkout


class DockerExecutor:
    """Build only audited source captures; never mount private inputs into an image."""

    def __init__(self, root, inputs, directory, image="aoe-observability:verification"):
        self.options = dict(root=Path(root), inputs=Path(inputs), image=image)
        self.directory = Path(directory)

    def execute(self, claim):
        """Return identity-bound evidence or an explicit safe prerequisite code."""
        paths = input_paths(self.options["inputs"])
        if any(not path.is_file() for path in paths.values()):
            return dict(error="MISSING_PREREQUISITE")
        return _execute(self.options, self.directory, claim)


def _execute(options, directory, claim):
    request = claim["request"]
    if request["edition"] != "SLES-50282":
        return dict(error="UNSUPPORTED_EDITION")
    if request_fingerprint(options["root"], options["inputs"]) != request["fingerprint"]:
        return dict(error="INPUT_CHANGED")
    directory.mkdir(parents=True, exist_ok=True, mode=0o700)
    workspace = Path(tempfile.mkdtemp(prefix="attempt-", dir=directory))
    checkout = prepare_checkout(options["root"], request["commit"], request["tree"], workspace / "source")
    return _run_capture(options, request, workspace, checkout)


def _run_capture(options, request, workspace, checkout):
    entries = entries_for(options["root"], request["edition"])
    if not entries:
        return dict(error="UNSUPPORTED_EDITION")
    try:
        entry = combine_entries(entries, checkout)
    except ValueError:
        return dict(error="SOURCE_NOT_REVIEWED", enrolled_units=len(entries))
    before = input_identity(options["root"], options["inputs"], request, checkout, entry)
    expected = (checkout / "config/SLES-50282/build.sha1").read_text().split()[0]
    if before["original"] != expected:
        return dict(error="ORIGINAL_HASH_MISMATCH", before=before)
    result = _invoke_tests(options, workspace, checkout, entry)
    result.update(entry=entry, checkout=checkout, before=before, enrolled_units=len(entries))
    return _finish_identity(options, request, checkout, entry, result)


def _finish_identity(options, request, checkout, entry, result):
    result["after"] = input_identity(options["root"], options["inputs"], request, checkout, entry)
    repository = resolve_repository(options["root"])
    history = first_parent_history(options["root"], repository["default_branch"])
    result["integrated"] = request["commit"] in history
    result["registry_digest"] = registry_identity(options["root"] / "config/observability/registry.json")
    result["observed"] = read_objdiff_report(options["inputs"] / "build/SLES-50282/report.json")
    return result


def _mount(source, target, *, readonly=True):
    suffix = ",readonly" if readonly else ""
    if "," in str(source):
        raise ValueError("Docker bind source cannot contain commas")
    return ["--mount", f"type=bind,source={source},target={target}{suffix}"]


def _prepare_destinations(checkout):
    for relative in INPUT_PATHS.values():
        destination = checkout / relative
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.touch(exist_ok=True)


def _source_mounts(checkout):
    mounts = _mount(checkout, "/workspace", readonly=False)
    for path in sorted(checkout.iterdir()):
        if path.name not in {"build", "orig", "compilers"}:
            mounts += _mount(path, "/workspace/" + path.name)
    return mounts


def _docker_command(options, workspace, checkout, entry):
    _prepare_destinations(checkout)
    command = ["docker", "--context", "docker-dev", "run", "--rm", "--network", "none",
               "--user", f"{os.getuid()}:{os.getgid()}", "-e", "TZ=America/Sao_Paulo",
               "-e", "PYTHONPATH=/observer", "-w", "/workspace"]
    command += _source_mounts(checkout) + _mount(options["root"], "/observer")
    (workspace / "output").mkdir(exist_ok=True)
    command += _mount(workspace / "output", "/evidence", readonly=False)
    for key, source in input_paths(options["inputs"]).items():
        command += _mount(source.resolve(), "/workspace/" + INPUT_PATHS[key])
    return command + [options["image"], "python", "-m", "pytest", "-q", "-p",
                      "scripts.observability.pytest_plugin", "--observability-report",
                      "/evidence/gates.json", *entry["behavior"], *entry["matching"]]


def _invoke_tests(options, workspace, checkout, entry):
    command = _docker_command(options, workspace, checkout, entry)
    try:
        return _run_docker(command, workspace / "output")
    except subprocess.TimeoutExpired:
        return dict(error="VERIFICATION_TIMEOUT")
    except OSError:
        return dict(error="MISSING_PREREQUISITE")


def _run_docker(command, workspace):
    with (workspace / "pytest.log").open("wb") as output:
        result = subprocess.run(command, stdout=output, stderr=subprocess.STDOUT, timeout=600)
    report_path = workspace / "gates.json"
    if not report_path.is_file():
        return dict(error="REMOTE_MOUNT_UNAVAILABLE" if result.returncode == 125 else "GATE_INCOMPLETE")
    report = json.loads(report_path.read_text())
    return dict(reports=dict(behavior=report, matching=report))
