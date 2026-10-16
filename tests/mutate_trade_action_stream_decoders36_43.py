"""Reject eight compiled production-source mutations across decoder36–43."""

import argparse
import hashlib
import importlib.util
from pathlib import Path

HASHES = {
    "src/trade_action_stream_decoders36.cpp": "a6e1dd5bd12488518ca0cdf9c3b5c8efcf61b23603e3e990f7e228c9d39a6078",
    "src/trade_action_stream_decoders37.cpp": "b10094b44086d1c4d247958ee483d6cccc64a65cb6224e76e8118558edbdd977",
    "src/trade_action_stream_decoders38.cpp": "26fcc5faf7fa981ac91ea9f5dee0b3ed26bb171fc4de1ec2375a46fbd346ff4e",
    "src/trade_action_stream_decoders39.cpp": "7a9fec2318b3733942b2972a48301b77c6b9d75c61fdafd7920b51be526d3250",
    "src/trade_action_stream_decoders40.cpp": "fbea95a10df01a5fd90bf5daebd96b451009cb93b05fbeac439a3bf41eb318ec",
    "src/trade_action_stream_decoders41.cpp": "42bb8e1ee3991570391d92c4588b3306c47b1141c0553f580f83fc2d2ec4dbea",
    "src/trade_action_stream_decoders42.cpp": "1c07b008ddb4949a7869bde1693ca52de7fbd3c1df69d762dec174745e82dbe9",
    "src/trade_action_stream_decoders43.cpp": "409c9c7c4e565f3910ab62244361c7dfc833aadf6b4cc644dfee8740274bca2e",
    "tests/test_trade_action_stream_decoders36.py": "dd59fcc68302f542717b20bc45459c646fd2a75cbc318071d29a2b2ad771f947",
    "tests/test_trade_action_stream_decoders37.py": "c32af999b78705a245f396873f71ed9ddb3f594aa9e0739b2fc396d2770ffd19",
    "tests/test_trade_action_stream_decoders38.py": "569e88087ef68d8705be80870f8db45b56cc5f545b0ead9dbe0af1fb6f4d4726",
    "tests/test_trade_action_stream_decoders39.py": "cd8c7496cdfd59c61987e8ea5cafa88191eb10d080d64b136a14b512fc8986bb",
    "tests/test_trade_action_stream_decoders40.py": "ad4766ace8be3d9fd68f802f46af5c45b598ba8fb7a4108c3d2a273d7d123bd6",
    "tests/test_trade_action_stream_decoders41.py": "58b30bb0f1a28c6810aa7520d3bf2228523472aa6b1b4e3952edc1a5164e4a9b",
    "tests/test_trade_action_stream_decoders42.py": "b658ef41ef1901a2b5d57754dc590b74e77d303887511856ed5be8cf27b19927",
    "tests/test_trade_action_stream_decoders43.py": "44f0f01654f3f6cfb4609bc452854c64c52cbd4c5748e3390e5536d627e07fa6",
    "tests/trade_action_stream_decoders36_support.py": "8e064453070cb5fd7b747322719b2b8de5eada6b395de43bc5ef89f8e1e6a7ca",
    "tests/trade_action_stream_decoders37_support.py": "94adda5087454d58ab4a381425418dd9edfaaea36078577356c5541816bf88e5",
    "tests/trade_action_stream_decoders38_support.py": "4fe1b86e36817cbd827b0db7d43b6f75ddda3307b47ba0ea8201a0ddc15ddf6f",
    "tests/trade_action_stream_decoders39_support.py": "9608c9da15863ce9a9ad46afd9d3b468b4cf524e377f43d8bc99bb91f308f42e",
    "tests/trade_action_stream_decoders40_support.py": "8d5fb6fb331c83cbb249686dd28176f149ed0ab43bec34f7076bb7c205fbfc81",
    "tests/trade_action_stream_decoders41_support.py": "d79f61bca657f16b08ea2c3c255dbec581a3367c9c4b10b8f50bd4fd40f71bd5",
    "tests/trade_action_stream_decoders42_support.py": "22011e651e84dfb1a689ab179930f65483bb00b03c725d4c7c88dd5c82f5ca7f",
    "tests/trade_action_stream_decoders43_support.py": "1df68e900e2357a85c68393995339f30f95e54e6b68802a7690d7ac0ac66201f",
}
MUTANTS = (
    (36, "func_001688C0", b"D_004E2DA8 -= 4", b"D_004E2DA8 -= 3"),
    (37, "func_00168C30", b"D_004E2DB0 += 4;", b"D_004E2DB0 += 3;"),
    (38, "func_00169260", b"D_004E2DA8 -= 4;", b"D_004E2DA8 -= 3;"),
    (39, "func_00169880", b"D_004E2DB0 += 3;", b"D_004E2DB0 += 2;"),
    (40, "func_001699F0", b"D_004E2DA0.word &= D_004E30A8;", b"D_004E2DA0.word |= D_004E30A8;"),
    (41, "func_00169BA0", b"D_004E2DA0.word |= D_004E30AC;", b"D_004E2DA0.word ^= D_004E30AC;"),
    (42, "func_00169FD0", b"D_004E2DB0 += 3;", b"D_004E2DB0 += 2;"),
    (43, "func_0016A2B0", b"D_004E2DA0.bytes[3];", b"D_004E2DA0.bytes[2];"),
)


def load_proof():
    path = Path(__file__).resolve().with_name("trade_action_stream_decoders36_43_proof.py")
    spec = importlib.util.spec_from_file_location("decoder36_43_proof", path)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def assert_import_hashes(root):
    for relative, expected in HASHES.items():
        actual = hashlib.sha256((root / relative).read_bytes()).hexdigest()
        assert actual == expected, (relative, actual, expected)


def mutate_and_reject(proof, number, function, original, replacement):
    root = proof.ROOT
    path = root / f"src/trade_action_stream_decoders{number}.cpp"
    original_file = path.read_bytes()
    start = original_file.index(f"void {function}()".encode())
    end = original_file.index(b"\n}\n", start) + 2
    body = original_file[start:end]
    assert body.count(original) >= 1, function
    mutated_body = body.replace(original, replacement, 1)
    changed = original_file[:start] + mutated_body + original_file[end:]
    path.write_bytes(changed)
    try:
        proof.run(["ninja", "-v", f"build/SLES-50282/src/trade_action_stream_decoders{number}.o"])
        try:
            proof.prove_unit(number)
        except AssertionError as error:
            assert function in str(error), (function, error)
            print(f"REJECTED {function}: {error}")
        else:
            raise AssertionError(f"{function} source mutant unexpectedly passed")
    finally:
        path.write_bytes(original_file)
        proof.run(["ninja", "-v", f"build/SLES-50282/src/trade_action_stream_decoders{number}.o"])
        assert_import_hashes(root)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, required=True)
    root = parser.parse_args().root
    proof = load_proof()
    proof.require_root(root)
    assert_import_hashes(root)
    proof.prepare_build()
    print("BASELINE BEFORE SOURCE MUTANTS")
    proof.prove_all()
    for mutant in MUTANTS:
        mutate_and_reject(proof, *mutant)
    assert_import_hashes(root)
    proof.prepare_build()
    print("BASELINE AFTER SOURCE RESTORATION")
    proof.prove_all()
    assert_import_hashes(root)
    print("RESTORED all 24 pinned source/test/support files by fixed SHA-256")


if __name__ == "__main__":
    main()
