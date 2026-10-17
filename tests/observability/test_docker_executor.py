"""Missing private tools must block before any compilation or GitHub access."""

from pathlib import Path

from scripts.observability.docker_executor import DockerExecutor, _docker_command
from scripts.observability.store import MetricsStore
from .test_store import request


def test_missing_private_inputs_are_blocked(tmp_path):
    root = Path(__file__).resolve().parents[2]
    claim = MetricsStore(tmp_path / "git").enqueue(request())
    executor = DockerExecutor(root, tmp_path / "missing", tmp_path / "private")
    result = executor.execute(claim)
    assert result.get("error") == "MISSING_PREREQUISITE"
    assert not (tmp_path / "private").exists()


def test_ninja_metadata_is_writable_but_source_and_inputs_are_readonly(tmp_path):
    checkout = tmp_path / "capture"
    (checkout / "src").mkdir(parents=True)
    (checkout / "include").mkdir()
    options = dict(root=tmp_path / "observer", inputs=tmp_path / "private", image="fixture")
    command = _docker_command(options, tmp_path, checkout, dict(behavior=[], matching=[]))
    mounts = [command[index + 1] for index, item in enumerate(command) if item == "--mount"]
    root = next(item for item in mounts if ",target=/workspace," in item or item.endswith("target=/workspace"))
    assert not root.endswith(",readonly")
    assert any("target=/workspace/src,readonly" in item for item in mounts)
    assert any("target=/workspace/include,readonly" in item for item in mounts)
    assert any("target=/workspace/orig/SLES-50282/AOK.ELF,readonly" in item for item in mounts)
