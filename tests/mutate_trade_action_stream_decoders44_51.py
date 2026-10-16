"""Reject eight compiled production-source mutations across decoder44–51."""

import argparse
import hashlib
import importlib.util
from pathlib import Path

HASHES = {
    "src/trade_action_stream_decoders44.cpp": "7bdca131e4402dbd53fe612710e04513b3f27444ecdf78589f67878a8e862386",
    "tests/test_trade_action_stream_decoders44.py": "436097f241e1a730b40584de205eee1234fc7e4375bbd7d6d39b07ff2e097bcc",
    "tests/trade_action_stream_decoders44_support.py": "021dedbb9fa6f9e67f90c932193fdaa3c3153bb71f5b2dd47e5a8c9786f7e0b3",
    "src/trade_action_stream_decoders45.cpp": "f380b0020b514629f1d7d0e964be91f2a8026820a0d9320eb5178366c31c0b48",
    "tests/test_trade_action_stream_decoders45.py": "3aadb7ae2f36e1bf6f7373e1f5594f435977d327b7a977e9134cd769140f6202",
    "tests/trade_action_stream_decoders45_support.py": "2dded0a5ffa429f4bd9219928682a33557f9f0ed2ce655874933f7c4067b1c57",
    "src/trade_action_stream_decoders46.cpp": "4e04ba53d8218d3052d4a30d59410a37cd329fe0e99b3394048971180d6a8a5a",
    "tests/test_trade_action_stream_decoders46.py": "8f763cf53789ea89eeaf45339ac8aba7eba72e6efde14c7965dc9ec3de3ac66b",
    "tests/trade_action_stream_decoders46_support.py": "c750193cb797b4a13168d01d34e08030002f1e301ee4de7183a7d25c9884099c",
    "src/trade_action_stream_decoders47.cpp": "80f8fc3b8c307abc58592de626d75eb14df94d4d7aa1cd1c033c6dd671dcadd8",
    "tests/test_trade_action_stream_decoders47.py": "a7751cdfa9c87c14b38a0ac02e64137a23da193f04dac9d2b6e8ee6212417d60",
    "tests/trade_action_stream_decoders47_support.py": "772aa7f3c7a74a3ff6dd0efc06c8dbb87cb46276479f405e5bc3167fda344f24",
    "src/trade_action_stream_decoders48.cpp": "da30b2d29c432104c1e8dc44f9bcea4c0b54ab940f336f7fd16dc22801242694",
    "tests/test_trade_action_stream_decoders48.py": "0e2969cb128fdcaca49793d496e2830256fdc8d8ce4d2113cd971491b175251a",
    "tests/trade_action_stream_decoders48_support.py": "237b8abeeeafc36660dbc662d597d05e327e2eed8f41d5568c5e1fe9ca833009",
    "src/trade_action_stream_decoders49.cpp": "bf65b7a0df1dfa88749832a2bb9b0b12010bf501dfe34e98afaebd8d39e4ab3b",
    "tests/test_trade_action_stream_decoders49.py": "3f8a0c01d02beb0580fa934fd6a9af95ba1e1ee075dc8fd9ac066fa1cb8ecdb4",
    "tests/trade_action_stream_decoders49_support.py": "c136cf9b2b4dcb6b56944bc360518b5ac208218fdb3c0646ba16fc7d765bba75",
    "src/trade_action_stream_decoders50.cpp": "4ed4c1981f7b7d83bb64302fac7ecf10bda1762c478945cec7b76ca1bf8cae0a",
    "tests/test_trade_action_stream_decoders50.py": "9168f0cc90a3b61adbbf3554c4349249ace0b42c7d2f8df7a9da1dd91c0b097b",
    "tests/trade_action_stream_decoders50_support.py": "59254f20256fc87309b702dc14a02080abd50583772a3d0a26b4832a687c6448",
    "src/trade_action_stream_decoders51.cpp": "9dc029f75267e55e0f45e7260a087db5f7d359eecdb151933c2d6dfc82521608",
    "tests/test_trade_action_stream_decoders51.py": "1994b95486fa7c685b4eb0962920c4942717112b8c4f6f22bd73e6a64335fc65",
    "tests/trade_action_stream_decoders51_support.py": "35267e9ad120e0eeef76c95a3987674b0572ebf9f768d179d06614097dccbaa3",
}
MUTANTS = (
    (44, "func_0016A5D0", b"D_004E2DB0++;", b"D_004E2DB0 += 2;"),
    (45, "func_0016AA50", b"D_004E2DA0.word &= D_004E30A8;", b"D_004E2DA0.word |= D_004E30A8;"),
    (46, "func_0016B0E0", b"D_004E2DB0 += 4;", b"D_004E2DB0 += 3;"),
    (47, "func_0016B400", b"D_004E2DA8 -= 3;", b"D_004E2DA8 -= 2;"),
    (48, "func_0016B960", b"D_004E2DA8 -= 4;", b"D_004E2DA8 -= 3;"),
    (49, "func_0016C150", b"D_004E2DA8 -= 3;", b"D_004E2DA8 -= 2;"),
    (50, "func_0016C610", b"D_004E2DA8 -= 6;", b"D_004E2DA8 -= 5;"),
    (51, "func_0016C920", b"D_004E2DA0.word |= D_004E2DA4;", b"D_004E2DA0.word ^= D_004E2DA4;"),
)


def load_proof():
    path = Path(__file__).resolve().with_name("trade_action_stream_decoders44_51_proof.py")
    spec = importlib.util.spec_from_file_location("decoder44_51_proof", path)
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
