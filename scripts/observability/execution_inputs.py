"""Private verifier input identities and audited profile composition."""

import hashlib
from pathlib import Path

from .identity import fingerprint_inputs
from .model import content_digest
from .registry import load_registry, registry_identity
from .source_policy import classify_source, source_digest

INPUT_PATHS = dict(original="orig/SLES-50282/AOK.ELF",
                   compiler="compilers/PS2/mwcc-2.3.1.01/mwccps2.exe", runner="build/tools/wibo")


def input_paths(inputs):
    """Return only explicitly supported private input locations."""
    return {name: Path(inputs) / relative for name, relative in INPUT_PATHS.items()}


def hash_file(path, algorithm="sha256"):
    """Hash a file with resource cleanup; missing files raise OSError."""
    with Path(path).open("rb") as handle:
        return hashlib.file_digest(handle, algorithm).hexdigest()


def verifier_digest(root):
    """Bind the collector code and schema, not a mutable executable pathname."""
    paths = tuple(sorted((Path(root) / "scripts/observability").glob("*.py")))
    return fingerprint_inputs(paths + (Path(root) / "schemas/observability/snapshot-v1.schema.json",))


def request_fingerprint(root, inputs):
    """Identify an enrollment/config/tool attempt, including private prerequisites."""
    registry = Path(root) / "config/observability/registry.json"
    paths = input_paths(inputs)
    private = {key: hash_file(path) if path.is_file() else None for key, path in paths.items()}
    return content_digest([registry_identity(registry), verifier_digest(root), private])


def combine_entries(entries, checkout):
    """Compose only individually reviewed closures; new content is never auto-approved."""
    if not entries or any(classify_source(entry, checkout) != "eligible" for entry in entries):
        raise ValueError("source enrollment is not reviewed")
    sources = sorted({name for entry in entries for name in entry["sources"]})
    return dict(sources=sources, reviewed_digest=source_digest(checkout, sources),
                ranges=[value for entry in entries for value in entry["ranges"]],
                behavior=sorted({node for entry in entries for node in entry["behavior"]}),
                matching=sorted({node for entry in entries for node in entry["matching"]}))


def entries_for(root, edition):
    """Select explicit edition enrollment without importing configure.py."""
    return [entry for entry in load_registry(Path(root) / "config/observability/registry.json")
            if entry["edition"] == edition]


def input_identity(root, inputs, request, checkout, entry):
    """Bind source/config/toolchain identities before and after a verification."""
    paths = input_paths(inputs)
    configuration = (Path(checkout) / "configure.py", Path(checkout) / "config/SLES-50282/build.sha1")
    return dict(commit=request["commit"], tree=request["tree"], original=hash_file(paths["original"], "sha1"),
                compiler=hash_file(paths["compiler"]), config=fingerprint_inputs(configuration),
                verifier=verifier_digest(root), source=source_digest(checkout, entry["sources"]),
                runner=hash_file(paths["runner"]))
