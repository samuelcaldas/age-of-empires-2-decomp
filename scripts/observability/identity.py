"""Read-only Git and input identities without configure.py side effects."""

import hashlib
from pathlib import Path
import subprocess


def git_output(path, *arguments):
    """Run a read-only Git query or raise a context-rich ValueError."""
    result = subprocess.run(["git", "-C", str(path), *arguments], capture_output=True,
                            text=True, timeout=30)
    if result.returncode:
        raise ValueError("Git query failed: " + arguments[0])
    return result.stdout.strip()


def _default_branch(root):
    result = subprocess.run(["git", "-C", str(root), "symbolic-ref", "refs/remotes/origin/HEAD"],
                            capture_output=True, text=True, timeout=30)
    if result.returncode == 0:
        return result.stdout.strip().removeprefix("refs/remotes/origin/")
    branches = git_output(root, "for-each-ref", "--format=%(refname:short)", "refs/heads").splitlines()
    return next((branch for branch in ("main", "master") if branch in branches), "main")


def resolve_repository(path):
    """Resolve shared Git state, HEAD/tree and default branch without mutation."""
    root = Path(git_output(path, "rev-parse", "--show-toplevel")).resolve()
    return dict(root=str(root), common_dir=git_output(root, "rev-parse", "--path-format=absolute", "--git-common-dir"),
                commit=git_output(root, "rev-parse", "HEAD"), tree=git_output(root, "rev-parse", "HEAD^{tree}"),
                default_branch=_default_branch(root), dirty=bool(git_output(root, "status", "--porcelain")))


def fingerprint_inputs(paths):
    """Hash input names/content without embedding private absolute paths."""
    material = (path.name.encode() + b"\0" + hashlib.sha256(path.read_bytes()).digest()
                for path in sorted(map(Path, paths)))
    return hashlib.sha256(b"".join(material)).hexdigest()


def first_parent_history(root, branch):
    """Return first-parent commits oldest first; missing branch is an error."""
    return git_output(root, "rev-list", "--first-parent", "--reverse", branch).splitlines()
