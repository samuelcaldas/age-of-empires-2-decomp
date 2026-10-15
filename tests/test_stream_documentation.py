"""Keep recovered stream subsystem coverage present in the binary analysis."""

import re
from pathlib import Path

import pytest


ROOT = Path(__file__).resolve().parents[1]
ANALYSIS = ROOT / "docs/ps2_binary_analysis.md"
SUBSYSTEMS = (
    ("Trade Action Stream Aggregators", "trade_action_stream_aggregators.cpp"),
    ("Trade Action Stream Emitters", "trade_action_stream_emitters.cpp"),
)


def subsystem_section(title):
    """Return the uniquely titled subsystem section, independent of numbering."""
    document = ANALYSIS.read_text(encoding="utf-8")
    heading = rf"^#### [^\n]*`{re.escape(title)}`[^\n]*$"
    matches = list(re.finditer(heading, document, re.MULTILINE))
    assert len(matches) == 1, f"Expected one documentation section for {title}"
    start = matches[0].end()
    next_heading = document.find("\n#### ", start)
    if next_heading == -1:
        return document[start:]
    return document[start:next_heading]


@pytest.mark.parametrize("title,source_name", SUBSYSTEMS)
def test_stream_subsystem_retains_function_coverage(title, source_name):
    """Require each restored subsystem to document every implemented function."""
    section = subsystem_section(title)
    source = (ROOT / "src" / source_name).read_text(encoding="utf-8")
    functions = re.findall(r"void\s+(func_[0-9A-Fa-f]+)\s*\(\s*\)\s*\{", source)
    assert functions, f"No stream functions found in {source_name}"
    assert all(f"`{function}`" in section for function in functions)
