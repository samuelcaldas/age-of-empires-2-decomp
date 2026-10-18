"""README badges are committed assets, not ignored build output."""

import xml.etree.ElementTree as ElementTree

from scripts.observability.site import write_readme_badges
from .test_export import bundle


def test_readme_badges_use_last_success_and_measurement_identity(tmp_path):
    projection = bundle()["projection"]
    paths = write_readme_badges(projection, tmp_path / "badges")
    assert set(paths) == {"bytes.svg", "state.svg", "verified-at.svg"}
    bytes_svg = (tmp_path / "badges/bytes.svg").read_text()
    assert "40 B" in bytes_svg
    assert "aaaaaaaa" in bytes_svg
    assert "last verified" in bytes_svg
    for name in paths:
        ElementTree.parse(tmp_path / "badges" / name)


def test_readme_badges_do_not_label_old_success_as_current(tmp_path):
    projection = bundle()["projection"]
    projection["state"] = "pending"
    projection["verified_cpp_bytes"] = None
    paths = write_readme_badges(projection, tmp_path / "badges")
    assert "bytes.svg" in paths
    bytes_svg = (tmp_path / "badges/bytes.svg").read_text()
    state_svg = (tmp_path / "badges/state.svg").read_text()
    assert "40 B" in bytes_svg
    assert "pending" in state_svg
    assert "last verified" in bytes_svg


def test_readme_badges_never_invent_missing_success(tmp_path):
    projection = bundle()["projection"]
    projection["last_verified_cpp_bytes"] = None
    projection["measured_commit"] = None
    projection["last_verified_at"] = None
    paths = write_readme_badges(projection, tmp_path / "badges")
    assert "bytes.svg" in paths
    assert "unavailable" in (tmp_path / "badges/bytes.svg").read_text()
    assert "unavailable" in (tmp_path / "badges/verified-at.svg").read_text()


def test_badge_output_rejects_symlinked_destination(tmp_path):
    target = tmp_path / "private"
    target.mkdir()
    destination = tmp_path / "badges"
    destination.symlink_to(target, target_is_directory=True)
    try:
        write_readme_badges(bundle()["projection"], destination)
    except ValueError:
        pass
    else:
        raise AssertionError("symlink destination was accepted")


def test_readme_uses_versioned_badge_paths_not_ignored_build_directory():
    from pathlib import Path

    readme = Path(__file__).resolve().parents[2] / "README.md"
    text = readme.read_text()
    assert "docs/badges/bytes.svg" in text
    assert "docs/badges/state.svg" in text
    assert "docs/badges/verified-at.svg" in text
    assert "build/observability/site/badges" not in text
