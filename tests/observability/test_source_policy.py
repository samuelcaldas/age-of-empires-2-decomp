"""Source eligibility requires a reviewed and complete dependency closure."""

import pytest

from scripts.observability.source_policy import classify_source, source_digest


def entry_for(root, text, suffix="cpp", dependencies=None):
    path = "candidate." + suffix
    (root / path).write_text(text)
    sources = [path] + (dependencies or [])
    return {"sources": sources, "reviewed_digest": source_digest(root, sources)}


def test_reviewed_plain_cpp_is_eligible(tmp_path):
    entry = entry_for(tmp_path, "int value() { return 7; }\n")
    assert classify_source(entry, tmp_path) == "eligible"


@pytest.mark.parametrize("text,suffix", [
    ('asm { nop }', "cpp"), ('__asm__("nop");', "cpp"),
    ('__asm { nop }', "cpp"), ('.word 0x1234', "s"),
    ('#define INSTRUCTION asm\nINSTRUCTION { nop }', "cpp"),
    ('asm(".byte 1,2");', "cpp"),
])
def test_assembly_is_excluded(tmp_path, text, suffix):
    entry = entry_for(tmp_path, text, suffix)
    assert classify_source(entry, tmp_path) == "excluded"


def test_review_is_invalidated_by_source_change(tmp_path):
    entry = entry_for(tmp_path, "int value() { return 1; }")
    (tmp_path / "candidate.cpp").write_text("int value() { return 2; }")
    assert classify_source(entry, tmp_path) == "unknown"


def test_unreviewed_include_is_unknown(tmp_path):
    entry = entry_for(tmp_path, '#include "unknown.h"\nint value();')
    assert classify_source(entry, tmp_path) == "unknown"


def test_assembly_in_reviewed_dependency_is_excluded(tmp_path):
    (tmp_path / "helper.h").write_text('asm("nop");')
    entry = entry_for(tmp_path, '#include "helper.h"', dependencies=["helper.h"])
    assert classify_source(entry, tmp_path) == "excluded"


def test_outside_source_path_is_unknown(tmp_path):
    assert classify_source({"sources": ["../secret"],
                            "reviewed_digest": "0" * 64}, tmp_path) == "unknown"
