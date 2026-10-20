"""Run the strict Block 59 verification gate."""

import argparse
import json
from pathlib import Path

from scripts.verify_node_pool_add_zone import verify


def _arguments():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--target", type=Path, required=True)
    parser.add_argument("--original", type=Path, required=True)
    return parser.parse_args()


def main():
    """Emit evidence and return 1 when the strict matching gate is blocked."""
    arguments = _arguments()
    evidence = verify(arguments.source, arguments.target, arguments.original)
    print(json.dumps(evidence, indent=2, sort_keys=True))
    if not evidence["strict_match"]:
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
