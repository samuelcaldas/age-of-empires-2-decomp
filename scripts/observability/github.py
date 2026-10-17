"""Pure publication planning and dry-run execution."""

from .public_model import REPOSITORY, validate_public_bundle


def plan_publication(bundle, repository):
    """Validate public bundle and produce offline publication plan."""
    validate_public_bundle(bundle)
    url = repository.get("remote_url", "")
    if REPOSITORY not in url:
        raise ValueError(f"remote repository must be {REPOSITORY}")
    return {
        "mode": "dry-run",
        "target_branch": "decomp-metrics",
        "repository": REPOSITORY,
        "snapshots_count": len(bundle["snapshots"]),
        "latest_measured_commit": bundle["projection"]["measured_commit"],
        "bytes": bundle["projection"]["verified_cpp_bytes"]
    }


def apply_publication(plan, transport=None, *, deploy=False):
    """Execute publication; default dry-run does not write to network."""
    if transport is None:
        return {"status": "dry-run", "plan": plan}
    # If custom transport passed, call it if not dry-run
    if plan.get("mode") == "apply":
        transport("push", plan["target_branch"])
        if deploy:
            transport("dispatch_pages", plan["repository"])
        return {"status": "applied", "deploy": deploy}
    return {"status": "dry-run", "plan": plan}
