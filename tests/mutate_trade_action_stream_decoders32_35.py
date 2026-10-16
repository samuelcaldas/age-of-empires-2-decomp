"""Reject one production-source byte/cursor mutation per decoder unit."""

import argparse
import hashlib
import importlib.util
from pathlib import Path

HASHES = {
    "src/trade_action_stream_decoders32.cpp": "98c91c3750b10bb13cb16b417f3d0ddb35bbc590629c0a7e363f81179e9a0611",
    "src/trade_action_stream_decoders33.cpp": "8bb58652c60ce34a45931fd3afe6063ef7cff0fbe38f18d65f36e3818b40a3c6",
    "src/trade_action_stream_decoders34.cpp": "04be99f729c47444fd29df85ec6463f20bdbc05c67f9541ccedae404ed55eaeb",
    "src/trade_action_stream_decoders35.cpp": "b798aaf3cbe181012c5d217ccec130c368a0da6601f36f629287629ecdefefd2",
    "tests/test_trade_action_stream_decoders32.py": "7fcb70def2dd8c1998cd415cf520c5369f3ab7168135f1dc138f315e46f28b0c",
    "tests/test_trade_action_stream_decoders33.py": "9645ca25266d1bf203725d0a91b448d60a257e6d71367d6188073ae6a8f3007e",
    "tests/test_trade_action_stream_decoders34.py": "247997612e8f363b29241cd0bf95ebdacbc509c5af00a92d9300573f4fc5617e",
    "tests/test_trade_action_stream_decoders35.py": "11a9b711f32a5b4a38cb157f8a4973837f29532f5f7518e77ae13d0eed7ebc16",
    "tests/trade_action_stream_decoders32_support.py": "30412afaa9f1df1949a94570bea83cf8d3dd40880682868af11c00bfc85ed2f5",
    "tests/trade_action_stream_decoders33_support.py": "6e60e048232e5af4f0a5c133dad4437601a48f75138199ac8f290855ff4699fb",
    "tests/trade_action_stream_decoders34_support.py": "bd8f6a79ac05ed7a8f905f7471f2566e5588fa1a75ced4257685fca8fdb58def",
    "tests/trade_action_stream_decoders35_support.py": "32f306d616088516426cfd16892583110f5fb9a29721e7c3187a25929ad05880",
}
MUTANTS = (
    (32, "func_00167D10", b"*D_004E2DB4 = *D_004E2DB0;", b"*D_004E2DB4 = D_004E2DB0[1];"),
    (33, "func_00167F40", b"*D_004E2DB4 = *D_004E2DB0;", b"*D_004E2DB4 = D_004E2DB0[1];"),
    (34, "func_00168180", b"D_004E2DB0 += 2;", b"D_004E2DB0 += 1;"),
    (35, "func_00168500", b"D_004E2DB0 += 3;", b"D_004E2DB0 += 2;"),
)


def load_proof():
    path = Path(__file__).resolve().with_name("trade_action_stream_decoders32_35_proof.py")
    spec = importlib.util.spec_from_file_location("decoder32_35_proof", path)
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
    assert body.count(original) == 1, function
    path.write_bytes(original_file[:start] + body.replace(original, replacement, 1) + original_file[end:])
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
    parser.add_argument("--root", type=Path, required=True,
                        help="explicit disposable Docker snapshot root; must equal cwd")
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
    print("RESTORED all 12 pinned source/test/support files by fixed SHA-256")


if __name__ == "__main__":
    main()
