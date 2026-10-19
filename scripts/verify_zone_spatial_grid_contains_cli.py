"""Command-line interface for func_001F2D50 verification."""

import argparse
import json
import sys

from scripts.verify_zone_spatial_grid_contains import verify


def main():
    parser = argparse.ArgumentParser(description="Verify func_001F2D50 contains")
    parser.add_argument("--source", required=True, help="Path to compiled .o")
    parser.add_argument("--original", required=True, help="Path to original ELF")
    args = parser.parse_args()

    result = verify(args.source, args.original)
    print(json.dumps(result, indent=2))
    if not result["literal_match"]:
        sys.exit(1)


if __name__ == "__main__":
    main()
