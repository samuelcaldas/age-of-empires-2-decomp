import json
from pathlib import Path

from .identity import resolve_repository
from .publication import make_public_bundle, write_bundle
from .site import build_site
from .state import load_projection, read_state


def export_command(args):
    """Export allowlisted public bundle."""
    repository = resolve_repository(args.repo)
    state = read_state(repository["common_dir"])
    projection = load_projection(args.repo, args.version)
    bundle = make_public_bundle(state["snapshots"], projection)
    output = Path(args.output)
    manifest = write_bundle(bundle, output)
    print(json.dumps(dict(status="exported", files=len(manifest["files"]), output=str(output)), indent=2))


def site_command(args):
    """Build static site from exported public bundle."""
    manifest = build_site(args.input, args.output)
    print(json.dumps(dict(status="built", files=len(manifest["files"]), output=str(args.output)), indent=2))
