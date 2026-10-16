"""Compile and reject one real source mutant for each decoder52–59 unit."""

import argparse
import hashlib
import importlib.util
from pathlib import Path

HASHES = {
    "src/trade_action_stream_decoders52.cpp": "3f4a96991ee89facbe77770e6896a46f9af5a1a7e58d89fbbb48cd4504539009",
    "tests/test_trade_action_stream_decoders52.py": "15d3f12bb76b2227fd8d088c4902863b6352c877bf67864568b3e450d4e2ce8f",
    "tests/trade_action_stream_decoders52_support.py": "88152c9bc82ea82b737b393efa165bb908fe7605ed32d4d5057898e177b075b6",
    "src/trade_action_stream_decoders53.cpp": "1e3f35aaa21fb5a4f2a470fdbbe746b43a243a4d4018d79bf60f099226d9c40c",
    "tests/test_trade_action_stream_decoders53.py": "5c8a19788113b0a5adb6f27612160f70981b80fc18a2587f8548fccc8dd5ba47",
    "tests/trade_action_stream_decoders53_support.py": "8d36ffc50b87552af7e4dbab446557256e2ee0ecf49f662e430a553750fb9bea",
    "src/trade_action_stream_decoders54.cpp": "17209f7c199722684d2f3143aa9c3772e3540bc1da2824090b89f4a13fae5af2",
    "tests/test_trade_action_stream_decoders54.py": "fc695178ed77d891698a059533d9acaf02c023142e93171edfdbd25ab322ea1c",
    "tests/trade_action_stream_decoders54_support.py": "27eaabae5a78238f7f318115d2090d98b1a953aedab5b70b3d0ac115c8b4486b",
    "src/trade_action_stream_decoders55.cpp": "454707a4ff6d804545b9328e0ff642fbc81e02163975be0ebf7897be2f5d5ac9",
    "tests/test_trade_action_stream_decoders55.py": "4616ef1dcb066d5a7691254471a452d3d093410214bdd1dbbf64a8b17d53630f",
    "tests/trade_action_stream_decoders55_support.py": "f6f8ab316994d4ca643ad44daaf5c0ee25dfefaf7df3ea62e5c19ba01adbf122",
    "src/trade_action_stream_decoders56.cpp": "d5fa1eac1c8b8b6ea9cd61797f48767e54afd49485140ae6595451b3bf0a2d39",
    "tests/test_trade_action_stream_decoders56.py": "8c5bcb97988003daad62c11d2f26665aaab2889befa5482936e7706b79a2e827",
    "tests/trade_action_stream_decoders56_support.py": "15506ab1e852bcdc47fba6c6757988746a29147745ddc0379af62d7e4d03576b",
    "src/trade_action_stream_decoders57.cpp": "65ef80e8dc57f6c38a6ff8504a8f7e30ca5bd37913961a94fb244fff251178cb",
    "tests/test_trade_action_stream_decoders57.py": "742678998a8b6d6bdab400d4ea3fad56f0256608133e41f6ef2521e2d6236b70",
    "tests/trade_action_stream_decoders57_support.py": "900c504f10e712e51d837ca3c4fca5410e8f444946e47098a0b781649bd5350d",
    "src/trade_action_stream_decoders58.cpp": "de6f144e5a2f948f05e4bf92ffdf201dfbfc4d8bcccd46fae8c8edfdc89fed5c",
    "tests/test_trade_action_stream_decoders58.py": "038da2156c422bcbc3c79116e4a5227bc71f42ffe371e6025e71164329e869a2",
    "tests/trade_action_stream_decoders58_support.py": "e08716299b202b10127942615a4c672abac4ce272518d134a0c9c0eff99ee5f0",
    "src/trade_action_stream_decoders59.cpp": "a49b9d75f96216b7959aab01d560fd7163176236cc0a28ee46da1352b03f9459",
    "tests/test_trade_action_stream_decoders59.py": "352866f4d20fd3244bf6e37f5484d59e649761792292dff88fbafe225d7c645b",
    "tests/trade_action_stream_decoders59_support.py": "bafb1d433982115fc0eae9fee1111350399c11536dd30b99f57fbfd4112402ce",
}
MUTANTS = (
    (52, "func_0016CC20", b"D_004E2DB0 += 4;", b"D_004E2DB0 += 3;"),
    (53, "func_0016D000", b"D_004E2DB0 += 4;", b"D_004E2DB0 += 3;"),
    (54, "func_0016D5F0", b"D_004E2DB0 += 4;", b"D_004E2DB0 += 3;"),
    (55, "func_0016D800", b"D_004E2DB0 += 3;", b"D_004E2DB0 += 2;"),
    (56, "func_0016DCB0", b"D_004E2DB0 += 3;", b"D_004E2DB0 += 2;"),
    (57, "func_0016E1F0", b"D_004E2DB0 += 3;", b"D_004E2DB0 += 2;"),
    (58, "func_0016E790", b"D_004E2DB0 += 4;", b"D_004E2DB0 += 3;"),
    (59, "func_0016EA50", b"D_004E30A8;", b"D_004E30B0;"),
)


def load_proof():
    path = Path(__file__).with_name("trade_action_stream_decoders52_59_proof.py")
    spec = importlib.util.spec_from_file_location("decoder52_59_proof", path)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def assert_hashes(root):
    for relative, expected in HASHES.items():
        actual = hashlib.sha256((root / relative).read_bytes()).hexdigest()
        assert actual == expected, (relative, actual, expected)


def object_hashes(root):
    return {
        number: hashlib.sha256((root / f"build/SLES-50282/src/trade_action_stream_decoders{number}.o").read_bytes()).hexdigest()
        for number in range(52, 60)
    }


def reject_mutant(proof, number, function, original, replacement):
    root = proof.ROOT
    path = root / f"src/trade_action_stream_decoders{number}.cpp"
    pristine = path.read_bytes()
    begin = pristine.index(f"void {function}()".encode())
    end = pristine.index(b"\n}\n", begin) + 2
    body = pristine[begin:end]
    assert body.count(original) == 1, (function, original)
    path.write_bytes(pristine[:begin] + body.replace(original, replacement, 1) + pristine[end:])
    try:
        proof.run(["ninja", "-v", f"build/SLES-50282/src/trade_action_stream_decoders{number}.o"])
        try:
            proof.prove_unit(number)
        except AssertionError as error:
            assert function in str(error), (function, error)
            print(f"REJECTED COMPILED MUTANT {number}: {function}")
        else:
            raise AssertionError(f"compiled mutant unexpectedly passed: {function}")
    finally:
        path.write_bytes(pristine)
        proof.run(["ninja", "-v", f"build/SLES-50282/src/trade_action_stream_decoders{number}.o"])
        assert_hashes(root)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, required=True)
    root = parser.parse_args().root.resolve()
    assert Path.cwd().resolve() == root, "explicit snapshot root must equal cwd"
    proof = load_proof()
    proof.require_root(root)
    assert_hashes(root)
    proof.prepare_build()
    proof.prove_all()
    baseline_objects = object_hashes(root)
    for mutant in MUTANTS:
        reject_mutant(proof, *mutant)
    assert_hashes(root)
    proof.prepare_build()
    proof.prove_all()
    assert object_hashes(root) == baseline_objects, "baseline object hashes changed after source restoration"
    assert_hashes(root)
    print("RESTORED all 24 pinned blobs and eight baseline object hashes")


if __name__ == "__main__":
    main()
