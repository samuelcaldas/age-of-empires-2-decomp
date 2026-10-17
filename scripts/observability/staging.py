"""Immutable source capture, never an active worktree build."""

from io import BytesIO
from pathlib import Path
import subprocess
import tarfile

from .identity import git_output


def prepare_checkout(root, commit, tree, destination):
    """Extract the exact Git tree into an empty private path; reject mismatch."""
    if git_output(root, "rev-parse", commit + "^{tree}") != tree:
        raise ValueError("requested commit/tree mismatch")
    target = Path(destination)
    target.mkdir(parents=True, exist_ok=True)
    if any(target.iterdir()):
        raise ValueError("capture destination must be empty")
    result = subprocess.run(["git", "-C", str(root), "archive", "--format=tar", commit],
                            capture_output=True, check=True, timeout=60)
    with tarfile.open(fileobj=BytesIO(result.stdout)) as archive:
        archive.extractall(target, filter="data")
    return target
