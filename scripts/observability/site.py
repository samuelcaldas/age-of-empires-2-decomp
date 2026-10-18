"""Self-hosted static Pages and SVG badges from validated shared metrics."""

from html import escape
import os
from pathlib import Path
import re
import shutil
import tempfile

from .artifacts import checked_path, prepare_output, read_manifest, write_manifest
from .publication import read_bundle

TEMPLATES = ("index.html", "styles.css", "app.mjs", "view_model.mjs", "chart.mjs")
COMMIT = re.compile(r"^[0-9a-f]{40,64}$")
MAX_SAFE_INTEGER = 2**53 - 1
STATES = {"verified", "failed", "blocked", "pending", "running", "unavailable"}


def badge_svg(label, value):
    """Render an accessible neutral badge with escaped labels and values."""
    left = max(90, len(label) * 7 + 16)
    right = max(80, len(value) * 7 + 16)
    title = escape(label + ": " + value, quote=True)
    return (f'<svg xmlns="http://www.w3.org/2000/svg" width="{left + right}" height="24" '
            f'role="img" aria-label="{title}"><title>{title}</title>'
            f'<rect width="{left + right}" height="24" rx="4" fill="#ededeb"/>'
            '<g fill="#171716" font-family="Arial,sans-serif" font-size="12" text-anchor="middle">'
            f'<text x="{left / 2}" y="16">{escape(label)}</text>'
            f'<text x="{left + right / 2}" y="16">{escape(value)}</text></g></svg>\n')


def _badges(projection):
    count = projection["verified_cpp_bytes"]
    return {"badges/bytes.svg": badge_svg("verified C++", f"{count} B" if count is not None else "unavailable"),
            "badges/state.svg": badge_svg("local verification", projection["state"]),
            "badges/verified-at.svg": badge_svg("last verified UTC", projection["last_verified_at"] or "unavailable")}


def _readme_badge_values(projection):
    count = projection.get("last_verified_cpp_bytes")
    commit = projection.get("measured_commit")
    if count is not None and (type(count) is not int or not 0 <= count <= MAX_SAFE_INTEGER):
        raise ValueError("invalid historical byte count")
    if commit is not None and (not isinstance(commit, str) or not COMMIT.fullmatch(commit)):
        raise ValueError("invalid measured commit identity")
    if count is not None and commit is None:
        raise ValueError("historical bytes require a measured commit")
    state = projection.get("state")
    if state not in STATES:
        raise ValueError("invalid current verification state")
    value = "unavailable"
    if count is not None:
        value = f"{count} B @ {commit[:8]}"
    verified_at = projection.get("last_verified_at") or "unavailable"
    if not isinstance(verified_at, str) or len(verified_at) > 32:
        raise ValueError("invalid verification timestamp")
    return {"bytes.svg": badge_svg("last verified C++", value),
            "state.svg": badge_svg("current verification", state),
            "verified-at.svg": badge_svg("last verified UTC", verified_at)}


def _safe_badge_directory(output_dir):
    directory = Path(output_dir)
    if any(path.is_symlink() for path in (directory, *directory.parents)):
        raise ValueError("badge output path cannot traverse symlinks")
    directory.mkdir(parents=True, exist_ok=True)
    return directory


def _write_badge(directory, name, content):
    path = directory / name
    if path.is_symlink() or not path.resolve().is_relative_to(directory.resolve()):
        raise ValueError("badge output path is unsafe")
    descriptor, temporary = tempfile.mkstemp(prefix=".badge-", dir=directory)
    try:
        _replace_badge(descriptor, temporary, path, content)
    finally:
        Path(temporary).unlink(missing_ok=True)


def _replace_badge(descriptor, temporary, path, content):
    with os.fdopen(descriptor, "w", encoding="utf-8") as stream:
        stream.write(content)
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temporary, path)


def write_readme_badges(projection, output_dir):
    """Write deterministic tracked README badges for the last integrated success."""
    badges = _readme_badge_values(projection)
    directory = _safe_badge_directory(output_dir)
    for name, content in badges.items():
        _write_badge(directory, name, content)
    return tuple(badges)


def build_site(bundle_dir, output_dir):
    """Build only selected validated data and trusted assets; inspect existing output."""
    bundle = read_bundle(bundle_dir)
    data = read_manifest(bundle_dir)
    badges = _badges(bundle["projection"])
    names = set(data["files"]) | set(TEMPLATES) | set(badges)
    output = prepare_output(output_dir, names, static=True)
    _copy_data(bundle_dir, output, data["files"])
    _copy_templates(output)
    for name, text in badges.items():
        path = checked_path(output, name, static=True)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text, encoding="utf-8")
    return write_manifest(output, names, static=True)


def _copy_data(source, output, names):
    for name in names:
        target = checked_path(output, name)
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(checked_path(source, name), target)


def _copy_templates(output):
    directory = Path(__file__).parent / "web"
    for name in TEMPLATES:
        shutil.copyfile(directory / name, checked_path(output, name, static=True))
