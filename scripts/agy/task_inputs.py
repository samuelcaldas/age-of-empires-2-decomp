"""Validate task inputs and render the prompt and write patterns from them.

Path inputs must exist and resolve inside the repository. Their SHA-256 is
kept so the run key changes when the file changes. Placeholders use the form
`{{name}}` and are replaced literally, so braces in the prompt stay intact.
"""

from dataclasses import dataclass
from pathlib import Path

from errors import InputError
from profiles import Profile
from run_store import hash_file


@dataclass(frozen=True)
class ResolvedInput:
    """An input after validation. `sha256` is set only for path inputs."""

    name: str
    value: str
    sha256: str | None


def resolve_inputs(profile: Profile, raw: dict[str, str], repo_root: Path) -> list[ResolvedInput]:
    """Check `raw` against the profile's declared inputs and return them in order.

    Raises:
        InputError: an input is unknown, missing, empty, or not a file inside the repo.
    """
    _reject_unknown(profile, raw)
    _reject_missing(profile, raw)
    return [_resolve_one(spec, raw[spec.name], repo_root) for spec in profile.inputs if spec.name in raw]


def _reject_unknown(profile: Profile, raw: dict[str, str]) -> None:
    known = {spec.name for spec in profile.inputs}
    unknown = sorted(set(raw) - known)
    if unknown:
        raise InputError(f"{profile.name}: unknown inputs {unknown}")


def _reject_missing(profile: Profile, raw: dict[str, str]) -> None:
    missing = [spec.name for spec in profile.inputs if spec.required and spec.name not in raw]
    if missing:
        raise InputError(f"{profile.name}: missing required inputs {missing}")


def _resolve_one(spec, value: str, repo_root: Path) -> ResolvedInput:
    if not value.strip():
        raise InputError(f"input '{spec.name}' is empty")
    if spec.kind == "text":
        return ResolvedInput(spec.name, value, None)
    path = _inside_repo(spec.name, value, repo_root)
    return ResolvedInput(spec.name, str(path), hash_file(path))


def _inside_repo(name: str, value: str, repo_root: Path) -> Path:
    candidate = (repo_root / value).resolve()
    if not candidate.is_relative_to(repo_root.resolve()):
        raise InputError(f"input '{name}' resolves outside the repository: {value}")
    if not candidate.is_file():
        raise InputError(f"input '{name}' is not an existing file: {value}")
    return candidate


def render_text(template: str, inputs: list[ResolvedInput]) -> str:
    """Replace every `{{name}}` in `template` with the matching input value."""
    rendered = template
    for item in inputs:
        rendered = rendered.replace("{{" + item.name + "}}", item.value)
    return rendered


def input_directories(inputs: list[ResolvedInput]) -> list[Path]:
    """Return the parent directory of each path input, for agy's `--add-dir`."""
    return [Path(item.value).parent for item in inputs if item.sha256 is not None]


def input_fingerprint(inputs: list[ResolvedInput]) -> list[dict]:
    """Return the inputs as plain dicts, for `meta.json` and the run key."""
    return [{"name": item.name, "value": item.value, "sha256": item.sha256} for item in inputs]
