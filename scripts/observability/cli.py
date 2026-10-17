"""Local observability commands with explicit failures and no implicit network."""

import json
import sqlite3
import subprocess
import sys

from .arguments import build_parser
from .commands import enqueue_command, status_command, verify_command, watch_command, work_command
from .site_cli import export_command, site_command


def _dispatch(args):
    if args.command == "enqueue":
        _, queued, _ = enqueue_command(args)
        print(json.dumps(queued, indent=2))
        return 0
    if args.command == "verify":
        result = verify_command(args)
        print(json.dumps(result, indent=2))
        return 0 if result["state"] == "verified" else 2
    if args.command == "export":
        export_command(args)
        return 0
    if args.command == "site":
        site_command(args)
        return 0
    handlers = dict(status=status_command, watch=watch_command, work=work_command)
    handlers[args.command](args)
    return 0


def main(argv=None):
    """Return process status; report local errors without forging a successful gate."""
    args = build_parser().parse_args(argv)
    try:
        return _dispatch(args)
    except KeyboardInterrupt:
        return 0
    except (OSError, ValueError, sqlite3.Error, subprocess.SubprocessError) as error:
        print("observability: " + str(error), file=sys.stderr)
        return 1
