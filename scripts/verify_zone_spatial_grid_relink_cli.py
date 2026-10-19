"""CLI for verifying func_001F2980 instructions against original PS2 ELF."""

import argparse
import json
import sys

from scripts.verify_zone_spatial_grid_relink import verify


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", required=True, help="Path to compiled object")
    parser.add_argument("--original", required=True, help="Path to AOK.ELF")
    args = parser.parse_args()

    result = verify(args.source, args.original)
    print(json.dumps(result, indent=2))
    if not result["literal_match"]:
        sys.exit(1)


if __name__ == "__main__":
    main()
