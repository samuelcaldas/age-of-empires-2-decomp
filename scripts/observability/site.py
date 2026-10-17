"""Self-hosted static Pages and SVG badges from validated shared metrics."""

from html import escape
from pathlib import Path
import shutil

from .artifacts import checked_path, prepare_output, read_manifest, write_manifest
from .publication import read_bundle

TEMPLATES = ("index.html", "styles.css", "app.mjs", "view_model.mjs", "chart.mjs")


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
