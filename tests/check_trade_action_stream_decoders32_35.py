"""Run the independent decoder32–35 proof from an explicit snapshot root."""

import argparse
import importlib.util
from pathlib import Path


def load_proof():
    path = Path(__file__).resolve().with_name("trade_action_stream_decoders32_35_proof.py")
    spec = importlib.util.spec_from_file_location("decoder32_35_proof", path)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, required=True,
                        help="explicit disposable Docker snapshot root; must equal cwd")
    arguments = parser.parse_args()
    proof = load_proof()
    proof.require_root(arguments.root)
    proof.prepare_build()
    proof.prove_all()


if __name__ == "__main__":
    main()
