"""Compile and reject one real source mutant for each decoder60–67 unit."""

import argparse
import hashlib
import importlib.util
from pathlib import Path

HASHES = {
    "src/trade/trade_action_stream_decoders60.cpp": "bc4b8381e6c2e8d176c345063d4cf46ae52677be6e1dfe435c63ac00c9f7c882",
    "tests/test_trade_action_stream_decoders60.py": "65297b1a1a73feb3df4a14ad2cc7a70b0945825ca733adaef9fda53fbd44ed57",
    "tests/trade_action_stream_decoders60_support.py": "6f7bb34def7c12de924be6d3a4494521085d57a4f362fb2d5b072bb87d2193dd",
    "src/trade/trade_action_stream_decoders61.cpp": "6639df8b600a6fe9c969bcf88cffabd056a5393d41f08c2445045706bed6b796",
    "tests/test_trade_action_stream_decoders61.py": "3250e56813d6f4e5d284270625f9e67826dd85ba9f87ce40b5cef7acf3489b8d",
    "tests/trade_action_stream_decoders61_support.py": "f227ba58f7419b89fc4a1473fbd379b58b06fa4376877ced3b3fa1d1c5ea04e6",
    "src/trade/trade_action_stream_decoders62.cpp": "ee145aabb334d87ce0e24bab1e8cc9c9a56c18404456ff45ab5f2a293990cff4",
    "tests/test_trade_action_stream_decoders62.py": "36388cb8884dfb3bdeab0fbb183d93ffa2de583915c85114b295400e58f1317a",
    "tests/trade_action_stream_decoders62_support.py": "167d0c35790ad0a3af23b1a700aaa31b2a4d36c9c9c3009fb218149f92fda7c2",
    "src/trade/trade_action_stream_decoders63.cpp": "a62f0950bbf5ec0e509e0b258dddebe7f8ab3252efa2eebaf561688914e87c44",
    "tests/test_trade_action_stream_decoders63.py": "4a7015560d4202882395521daa04b26fac452957036914aeb5d48b7f1f2277bb",
    "tests/trade_action_stream_decoders63_support.py": "035144c51b0607aade5c515939efe38e9af530486744ee4d9c64aa3e8c1d4ed9",
    "src/trade/trade_action_stream_decoders64.cpp": "800b1b7cba809de7c8a7d1e0b7f0ca3fa73122cafe80667fe5251d0d0c47b931",
    "tests/test_trade_action_stream_decoders64.py": "8a6f1b72e01c32238c5a0fbfa1a839c9348caeec1f77e816b8fcf735418f0ef3",
    "tests/trade_action_stream_decoders64_support.py": "cf08efff3052f9554634974749aff3c2454fcea04b205274897abd3c377be5a9",
    "src/trade/trade_action_stream_decoders65.cpp": "583dfcdf2f80a8c604b317f4edaeef30d7d12c68c5b5caf14359ea16659cb969",
    "tests/test_trade_action_stream_decoders65.py": "daa158434a7dc82b371287fc56b135445e74dcd75591d7a5c4de43ba8c4ff6db",
    "tests/trade_action_stream_decoders65_support.py": "73be25359c9f2f338b86c1130eda111ddfe56a28bec8f071993021393c633d41",
    "src/trade/trade_action_stream_decoders66.cpp": "eb685cc04ad9f707460796184295cf6abd9a6e294d87e4f0772c6319b0ba62c5",
    "tests/test_trade_action_stream_decoders66.py": "7636067a1c42fe027c5915d4302eaf8afe775555d2fa1f24aab53d1ac61fa88f",
    "tests/trade_action_stream_decoders66_support.py": "87c900ce82ab58635b9eee3bcefdbef1dc380138719bcd6c0239e23e68025c8d",
    "src/trade/trade_action_stream_decoders67.cpp": "16bbad62f66206919daf1101da4ae70985f95d17ae4469f5ae7ae20b6db7935c",
    "tests/test_trade_action_stream_decoders67.py": "041d912c43168acdd1c962b3362204f9e0db9efed0a971d8eae2f261e128bd2c",
    "tests/trade_action_stream_decoders67_support.py": "9452f6d8f75f8e6b259210b09e30a9878ba51f3e71e1dcf46a81436c19c62386",
}
MUTANTS = (
    (60, "func_0016ECC0", b"D_004E2DB0 += 2;", b"D_004E2DB0 += 3;"),
    (61, "func_0016F040", b"D_004E2DB0 += 2;", b"D_004E2DB0 += 3;"),
    (62, "func_0016F480", b"D_004E2DB0 += 2;", b"D_004E2DB0 += 3;"),
    (63, "func_0016F940", b"D_004E2DB0 += 2;", b"D_004E2DB0 += 3;"),
    (64, "func_0016FEE0", b"D_004E2DB0 += 2;", b"D_004E2DB0 += 3;"),
    (65, "func_00170470", b"D_004E2DB0 += 2;", b"D_004E2DB0 += 3;"),
    (66, "func_00170A60", b"D_004E2DB0 += 2;", b"D_004E2DB0 += 3;"),
    (67, "func_00171120", b"D_004E2DB0 += 2;", b"D_004E2DB0 += 3;"),
)


def load_proof():
    path = Path(__file__).with_name("trade_action_stream_decoders60_67_proof.py")
    spec = importlib.util.spec_from_file_location("decoder60_67_proof", path)
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
        for number in range(60, 68)
    }


def reject_mutant(proof, number, function, original, replacement):
    root = proof.ROOT
    path = root / f"src/trade_action_stream_decoders{number}.cpp"
    pristine = path.read_bytes()
    begin = pristine.index(f"void {function}()".encode())
    end = pristine.index(b"\n}\n", begin) + 2
    body = pristine[begin:end]
    assert body.count(original) >= 1, (function, original)
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
