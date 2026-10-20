"""CLI entry point for func_001F2BD0 verification."""

import argparse
import json
from pathlib import Path
import sys

from scripts.verify_zone_spatial_grid_reset import verify


def main():
    parser = argparse.ArgumentParser(
        description="Verify func_001F2BD0 compiled instructions against authentic PS2 ELF"
    )
    parser.add_argument("--source", required=True, help="Path to compiled object")
    parser.add_argument("--original", required=True, help="Path to original AOK.ELF")
    args = parser.parse_args()

    result = verify(Path(args.source), Path(args.original))
    print(json.dumps(result, indent=2))
    sys.exit(0 if result["literal_match"] else 1)


if __name__ == "__main__":
    main()
