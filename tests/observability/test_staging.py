"""Only committed source is verified, regardless of active-tree edits."""

import pytest

from scripts.observability.staging import prepare_checkout
from .test_identity import git, make_repository


def test_capture_ignores_uncommitted_source(tmp_path):
    root = make_repository(tmp_path / "repo")
    commit = git(root, "rev-parse", "HEAD")
    tree = git(root, "rev-parse", "HEAD^{tree}")
    (root / "source.txt").write_text("other agent is editing")
    staged = prepare_checkout(root, commit, tree, tmp_path / "isolated")
    assert (staged / "source.txt").is_file()
    assert (staged / "source.txt").read_text() == "original"
    assert (root / "source.txt").read_text() == "other agent is editing"


def test_wrong_tree_is_rejected_before_capture(tmp_path):
    root = make_repository(tmp_path / "repo")
    with pytest.raises(ValueError, match="tree"):
        prepare_checkout(root, git(root, "rev-parse", "HEAD"), "0" * 40, tmp_path / "isolated")
