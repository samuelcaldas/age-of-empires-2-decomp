"""Configure and run the independent decoder28-31 proof from an explicit root."""

import argparse
import importlib.util
from pathlib import Path


def load_proof():
    path = Path(__file__).resolve().with_name("trade_action_stream_decoders28_31_proof.py")
    spec = importlib.util.spec_from_file_location("decoder28_31_proof", path)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, help="explicit snapshot or worktree root; must equal cwd")
    arguments = parser.parse_args()
    proof = load_proof()
    proof.require_root(arguments.root)
    proof.prepare_build()
    proof.prove_all()


if __name__ == "__main__":
    main()
