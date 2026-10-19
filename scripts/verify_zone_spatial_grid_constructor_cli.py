"""Run the Block 62 verification gate."""

import argparse
import json
from pathlib import Path

from scripts.verify_zone_spatial_grid_constructor import verify


def _arguments():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--original", type=Path, required=True)
    return parser.parse_args()


def main():
    """Emit verification evidence and return 0 on literal match."""
    arguments = _arguments()
    evidence = verify(arguments.source, arguments.original)
    print(json.dumps(evidence, indent=2, sort_keys=True))
    if not evidence["literal_match"]:
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
