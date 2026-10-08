"""Load and validate task profiles from `scripts/agy/profiles/*.yml`.

A profile fixes everything the model is allowed to vary: model, effort,
execution mode, timeout, the paths it may write, its output schema, and the
prompt text. Callers choose only the profile name and its inputs.
"""

import re
from dataclasses import dataclass
from pathlib import Path

import yaml

from errors import ProfileError

AGY_DIR = Path(__file__).resolve().parent
PROFILES_DIR = AGY_DIR / "profiles"
SCHEMAS_DIR = AGY_DIR / "schemas"

PROFILE_NAME_PATTERN = re.compile(r"^[a-z][a-z0-9-]*$")
VALID_MODES = ("plan", "accept-edits")
VALID_EFFORTS = ("low", "medium", "high", "xhigh", "max")
VALID_INPUT_KINDS = ("text", "path")
REQUIRED_KEYS = ("description", "model", "effort", "mode", "timeout_seconds", "schema", "prompt")


@dataclass(frozen=True)
class InputSpec:
    """One named input a profile accepts, as text or as a repository path."""

    name: str
    kind: str
    required: bool


@dataclass(frozen=True)
class Profile:
    """A validated task profile. `writes` is empty for read-only profiles."""

    name: str
    description: str
    model: str
    effort: str
    mode: str
    timeout_seconds: int
    schema_path: Path
    prompt: str
    writes: tuple[str, ...]
    inputs: tuple[InputSpec, ...]

    @property
    def is_read_only(self) -> bool:
        """True when the profile declares no writable paths."""
        return not self.writes


def load_profile(name: str, profiles_dir: Path = PROFILES_DIR) -> Profile:
    """Return the profile called `name`, or raise ProfileError.

    Raises:
        ProfileError: the name is malformed, the file is missing, or a field is invalid.
    """
    if not PROFILE_NAME_PATTERN.match(name):
        raise ProfileError(f"invalid profile name: {name!r}")
    path = profiles_dir / f"{name}.yml"
    if not path.is_file():
        raise ProfileError(f"unknown profile: {name} (looked in {profiles_dir})")
    raw = _read_yaml(path)
    return _build_profile(name, raw, profiles_dir)


def _read_yaml(path: Path) -> dict:
    try:
        data = yaml.safe_load(path.read_text(encoding="utf-8"))
    except yaml.YAMLError as error:
        raise ProfileError(f"{path.name}: invalid YAML: {error}") from error
    if not isinstance(data, dict):
        raise ProfileError(f"{path.name}: top level must be a mapping")
    return data


def _build_profile(name: str, raw: dict, profiles_dir: Path) -> Profile:
    _require_keys(name, raw)
    _check_choice(name, "mode", raw["mode"], VALID_MODES)
    _check_choice(name, "effort", raw["effort"], VALID_EFFORTS)
    timeout = _check_timeout(name, raw["timeout_seconds"])
    return Profile(
        name=name,
        description=str(raw["description"]).strip(),
        model=str(raw["model"]),
        effort=raw["effort"],
        mode=raw["mode"],
        timeout_seconds=timeout,
        schema_path=_check_schema(name, raw["schema"]),
        prompt=str(raw["prompt"]).strip(),
        writes=_check_writes(name, raw.get("writes", [])),
        inputs=_build_inputs(name, raw.get("inputs", [])),
    )


def _require_keys(name: str, raw: dict) -> None:
    missing = [key for key in REQUIRED_KEYS if key not in raw]
    if missing:
        raise ProfileError(f"{name}: missing keys {missing}")


def _check_choice(name: str, field: str, value: str, choices: tuple) -> None:
    if value not in choices:
        raise ProfileError(f"{name}: {field} must be one of {choices}, got {value!r}")


def _check_timeout(name: str, value: object) -> int:
    if not isinstance(value, int) or isinstance(value, bool) or value <= 0:
        raise ProfileError(f"{name}: timeout_seconds must be a positive integer")
    return value


def _check_schema(name: str, file_name: str) -> Path:
    path = SCHEMAS_DIR / file_name
    if not path.is_file():
        raise ProfileError(f"{name}: schema file not found: {file_name}")
    return path


def _check_writes(name: str, writes: list) -> tuple[str, ...]:
    if not isinstance(writes, list):
        raise ProfileError(f"{name}: writes must be a list of patterns")
    for pattern in writes:
        _check_relative_pattern(name, pattern)
    return tuple(writes)


def _check_relative_pattern(name: str, pattern: str) -> None:
    if pattern.startswith("/") or ".." in Path(pattern).parts:
        raise ProfileError(f"{name}: write pattern must be relative and inside the repo: {pattern!r}")


def _build_inputs(name: str, raw_inputs: list) -> tuple[InputSpec, ...]:
    return tuple(_build_input(name, entry) for entry in raw_inputs)


def _build_input(name: str, entry: dict) -> InputSpec:
    if not isinstance(entry, dict) or "name" not in entry or "kind" not in entry:
        raise ProfileError(f"{name}: each input needs 'name' and 'kind'")
    _check_choice(name, "input kind", entry["kind"], VALID_INPUT_KINDS)
    return InputSpec(
        name=entry["name"],
        kind=entry["kind"],
        required=bool(entry.get("required", True)),
    )
