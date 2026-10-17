import json
from pathlib import Path

from .github import apply_publication, plan_publication
from .identity import git_output, resolve_repository
from .publication import make_public_bundle
from .state import load_projection, read_state


def publish_command(args):
    """Publish bundle; default is strictly dry-run without writing to remote."""
    repository = resolve_repository(args.repo)
    root = Path(repository["root"])
    try:
        remote_url = git_output(root, "config", "--get", "remote.origin.url")
    except ValueError:
        remote_url = ""
    repo_info = dict(repository, remote_url=remote_url)
    state = read_state(repository["common_dir"])
    projection = load_projection(args.repo, args.version)
    bundle = make_public_bundle(state["snapshots"], projection)
    plan = plan_publication(bundle, repo_info)
    if args.apply:
        plan["mode"] = "apply"
    receipt = apply_publication(plan, deploy=args.deploy)
    print(json.dumps(receipt, indent=2))
