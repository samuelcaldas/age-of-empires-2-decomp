"""Fail-fast command-line boundary, separate from command execution."""

import argparse
import math

from .model import EDITIONS


def positive_interval(text):
    """Parse a finite positive interval or raise an argparse error."""
    value = float(text)
    if not math.isfinite(value) or value <= 0:
        raise argparse.ArgumentTypeError("interval must be positive and finite")
    return value


def _revision_options(parser):
    parser.add_argument("--commit", default="HEAD")
    parser.add_argument("--profile", choices=["audited"], default="audited")
    parser.add_argument("--inputs")
    parser.add_argument("--retry", action="store_true")


def _loop_options(parser):
    parser.add_argument("--interval", type=positive_interval, default=5)
    parser.add_argument("--once", action="store_true")
    parser.add_argument("--no-color", action="store_true")


def build_parser():
    """Build the local CLI without executing Git, Docker or network operations."""
    parser = argparse.ArgumentParser(description="Offline-first decompilation evidence")
    parser.add_argument("--repo", default=".")
    commands = parser.add_subparsers(dest="command", required=True)
    for name in ("status", "enqueue", "verify", "work", "watch"):
        _add_command(commands, name)
    return parser


def _add_command(commands, name):
    parser = commands.add_parser(name)
    parser.add_argument("--version", choices=EDITIONS, default="SLES-50282")
    if name == "status":
        parser.add_argument("--json", action="store_true")
    if name in {"enqueue", "verify", "work"}:
        _revision_options(parser)
    if name in {"work", "watch"}:
        _loop_options(parser)
    if name in {"verify", "work"}:
        parser.add_argument("--image", default="aoe-observability:verification")
    if name == "work":
        parser.add_argument("--watch", action="store_true")
