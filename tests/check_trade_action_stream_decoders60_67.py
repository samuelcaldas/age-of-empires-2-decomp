"""Run the independent decoder60–67 proof from an explicit snapshot root."""

import argparse
import importlib.util
from pathlib import Path


def load_proof():
    path = Path(__file__).resolve().with_name("trade_action_stream_decoders60_67_proof.py")
    spec = importlib.util.spec_from_file_location("decoder60_67_proof", path)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, required=True,
                        help="explicit disposable Docker snapshot root; must equal cwd")
    arguments = parser.parse_args()
    root = arguments.root.resolve()
    assert Path.cwd().resolve() == root, "snapshot root must equal cwd"
    assert not (root / ".git").exists(), "refusing a Git worktree"
    assert (root / ".decoder60_67_snapshot").is_file(), "runner must mark disposable snapshot"
    proof = load_proof()
    proof.require_root(root)
    proof.prepare_build()
    proof.prove_all()


if __name__ == "__main__":
    main()
