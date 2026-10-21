from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]


def test_network_object_lifecycle_native(tmp_path):
    executable = tmp_path / "network-object-lifecycle-native"
    command = [
        "g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
        "tests/native/network_object_lifecycle_3380e0_test.cpp",
        "src/network_object_lifecycle_3380e0.cpp",
        "src/network_object_lifecycle_338140.cpp",
        "src/network_object_lifecycle_338180.cpp",
        "src/network_object_lifecycle_3381a0.cpp",
        "src/network_object_lifecycle_338230.cpp", "-o", str(executable),
    ]
    result = subprocess.run(command, cwd=ROOT, capture_output=True, text=True)
    assert result.returncode == 0, result.stderr
    result = subprocess.run([str(executable)], cwd=ROOT, capture_output=True, text=True)
    assert result.returncode == 0, result.stderr
