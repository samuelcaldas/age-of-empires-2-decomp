#!/usr/bin/env python3
"""Transform Windows-style dependency files into Unix-style paths for Ninja."""

import os
import re
import sys


def main() -> None:
    if len(sys.argv) < 3:
        sys.exit(0)

    in_path = sys.argv[1]
    out_path = sys.argv[2]

    if not os.path.exists(in_path):
        sys.exit(0)

    try:
        with open(in_path, "r", encoding="utf-8", errors="replace") as f:
            content = f.read()

        # Convert backslashes to forward slashes
        content = content.replace("\\", "/")

        # Strip drive letters (e.g. Z:/path -> /path)
        content = re.sub(r"(?i)[a-z]:/", "/", content)

        with open(out_path, "w", encoding="utf-8") as f:
            f.write(content)
    except Exception:
        pass


if __name__ == "__main__":
    main()
