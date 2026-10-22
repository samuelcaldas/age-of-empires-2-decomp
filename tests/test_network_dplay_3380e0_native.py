from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parents[1]

SOURCES = [
    "src/network_dplay_create_3380e0.cpp",
    "src/network_dplay_enum_338140.cpp",
    "src/network_dplay_stub_338180.cpp",
    "src/network_dplay_stub_338190.cpp",
    "src/network_dplay_reset_3381a0.cpp",
    "src/network_dplay_ctor_338230.cpp",
    "src/network_dplay_dtor_338260.cpp",
    "src/network_dplay_find_free_slot_3382d0.cpp",
    "src/network_dplay_find_slot_by_id_338310.cpp",
    "src/network_dplay_generate_id_338350.cpp",
    "src/network_dplay_send_packet_3383b0.cpp",
]


def test_network_dplay_3380e0_native(tmp_path):
    executable = tmp_path / "network-dplay-3380e0-native"
    compile_result = subprocess.run(
        ["g++", "-m32", "-std=c++98", "-O2", "-Iinclude",
         "tests/native/network_dplay_3380e0_test.cpp",
         *SOURCES, "-o", str(executable)],
        capture_output=True, text=True, cwd=ROOT,
    )
    assert compile_result.returncode == 0, compile_result.stderr
    run_result = subprocess.run([str(executable)], capture_output=True, text=True, cwd=ROOT)
    assert run_result.returncode == 0, run_result.stderr
