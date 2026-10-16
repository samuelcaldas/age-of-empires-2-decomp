"""Exercise value, cursor, and +1 destination mutants, then rebuild the baseline."""

import hashlib

from trade_action_stream_decoders28_31_proof import (
    ROOT, prove_all, prove_unit, require_root, run,
)

HASHES = {
    "src/trade_action_stream_decoders28.cpp": "57e8cab1edf90e48a46fbbf19bd01f21438f03184be1a5aabca8463681f94064",
    "src/trade_action_stream_decoders29.cpp": "f2413d1195c49bb69fac24aa1563c49c649bbb437597aed2d5e4470ce4e45208",
    "src/trade_action_stream_decoders30.cpp": "d0f5493c26aa9ea8dcf210cdf8b61b790842d25d8cb8067df3d57faef009aef4",
    "src/trade_action_stream_decoders31.cpp": "8b788f6dd1c56fb9c8746de752a757fb6822c066f4a86110b26fa0da8f944923",
    "tests/test_trade_action_stream_decoders28.py": "3c62261d257af7bb6b2432e7dc716ab04681f5b4c46ef359c169046b94239085",
    "tests/test_trade_action_stream_decoders29.py": "1280e5e177991b03964581b0a15e95a4cabb80008ea44a18a771c188af5a3ee4",
    "tests/test_trade_action_stream_decoders30.py": "e1d7fe2a60023b633fbd3992db4ba9302f29ae6d97d846e5389a5e72eb6f4b1d",
    "tests/test_trade_action_stream_decoders31.py": "7d97f29a96be84edd2211dcc0f1fc8ddd257893ed7994a689c8e28fd5ef8d85a",
    "tests/trade_action_stream_decoders28_support.py": "d88a7367198826528c20faa9d88a510df1bf439a9e0ba0d2b69c9a04d989578b",
    "tests/trade_action_stream_decoders29_support.py": "507ae45b37883f4b455ee1da8c14b5667149841908b8fe0d6792bd879a5cd4ae",
    "tests/trade_action_stream_decoders30_support.py": "e8e06e1c8cfb1f93c20f157242f2631ea7f74ef2f08bce6fbbeb83ac8bbe6869",
    "tests/trade_action_stream_decoders31_support.py": "f992eec589c4361542d5475400d6e1e5394caf09343e1d9818c67095d4b28234",
}


def assert_import_hashes():
    for relative, expected in HASHES.items():
        actual = hashlib.sha256((ROOT / relative).read_bytes()).hexdigest()
        assert actual == expected, (relative, actual, expected)


def ninja_object(number):
    run(["ninja", "-v", f"build/SLES-50282/src/trade_action_stream_decoders{number}.o"])


def mutate_and_reject(number, function_name, original, replacement):
    path = ROOT / f"src/trade_action_stream_decoders{number}.cpp"
    original_file = path.read_bytes()
    prefix = f"void {function_name}()".encode()
    start = original_file.index(prefix)
    end = original_file.index(b"\n}\n", start) + 2
    body = original_file[start:end]
    assert original in body
    path.write_bytes(original_file[:start] + body.replace(original, replacement, 1) + original_file[end:])
    try:
        ninja_object(number)
        try:
            prove_unit(number)
        except AssertionError as error:
            print(f"REJECTED {function_name} mutant: {error}")
        else:
            raise AssertionError(f"{function_name} mutant unexpectedly passed")
    finally:
        path.write_bytes(original_file)
        ninja_object(number)
        assert_import_hashes()


def main():
    require_root()
    assert_import_hashes()
    mutate_and_reject(28, "func_001658C0", b"*dst = *ptr;", b"*dst = ptr[1];")
    mutate_and_reject(30, "func_00166A70", b"D_004E2DA8 -= 4;", b"D_004E2DA8 -= 3;")
    try:
        prove_unit(29, {"D_004E2DA0": 0x4E2DA1})
    except AssertionError as error:
        assert "original/effective/expected" in str(error)
        print(f"REJECTED destination+1 mutant before raw comparison: {error}")
    else:
        raise AssertionError("destination+1 mutant unexpectedly passed")
    for number in range(28, 32):
        ninja_object(number)
    assert_import_hashes()
    prove_all()
    assert_import_hashes()
    print("RESTORED all 12 pinned source/test/support files by fixed SHA-256")


if __name__ == "__main__":
    main()
