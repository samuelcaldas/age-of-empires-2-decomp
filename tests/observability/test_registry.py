"""Registry selectors cannot inject commands or escape the checkout."""

import json
import pytest

from scripts.observability.registry import load_registry


def write_registry(path, selector="tests/check.py", sources=None):
    path.write_text(json.dumps(dict(schema_version=1, entries=[dict(
        edition="SLES-50282", name="unit", sources=sources or ["src/unit.cpp"],
        reviewed_digest="a" * 64, behavior=[selector], matching=[selector],
        ranges=[dict(start=100, end=140, owner="unit", function=True)])])))


def test_audited_registry_entry_is_loaded(tmp_path):
    path = tmp_path / "registry.json"
    write_registry(path)
    entries = load_registry(path)
    assert len(entries) == 1
    assert entries[0]["name"] == "unit"


@pytest.mark.parametrize("selector", ["--override-ini=x", "tests/x.py;curl secret", "../tests/x.py"])
def test_unsafe_selectors_are_rejected(tmp_path, selector):
    path = tmp_path / "registry.json"
    write_registry(path, selector)
    with pytest.raises(ValueError):
        load_registry(path)


def test_source_escape_is_rejected(tmp_path):
    path = tmp_path / "registry.json"
    write_registry(path, sources=["../outside.cpp"])
    with pytest.raises(ValueError):
        load_registry(path)
