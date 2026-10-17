"""Self-hosted badges and static output preserve the public metric identity."""

import json

from scripts.observability.publication import write_bundle
from scripts.observability.site import badge_svg, build_site
from .test_export import bundle


def test_svg_is_real_and_escapes_untrusted_labels():
    svg = badge_svg('<script>alert("x")</script>', "40 B")
    assert "<svg" in svg
    assert "<script>" not in svg
    assert "&lt;script&gt;" in svg
    assert "40 B" in svg


def test_site_uses_identical_projection_and_relative_assets(tmp_path):
    public = tmp_path / "public"
    write_bundle(bundle(), public)
    destination = tmp_path / "site"
    manifest = build_site(public, destination)
    assert (destination / "index.html").is_file()
    assert (destination / "badges/bytes.svg").is_file()
    assert "40 B" in (destination / "badges/bytes.svg").read_text()
    latest = json.loads((destination / "data/latest.json").read_text())
    assert latest["projection"]["verified_cpp_bytes"] == 40
    assert latest["projection"]["global_percent"] is None
    assert "index.html" in manifest["files"]
