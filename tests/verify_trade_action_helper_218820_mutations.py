"""Privately verify that native 218820 contract tests reject source mutants."""

import hashlib
import resource
import shutil
import subprocess
import tempfile
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parents[1]
SOURCE_PATH = PROJECT_ROOT / "src/trade_action_helper_218820.cpp"
SOURCE_SHA256 = "97ba0194fba95fdff59333f365ecb7a67480d19f5ab574ec9c08baa243fc1369"
CASE_COUNT = 19


def replace_once(source, old, new):
    if source.count(old) != 1:
        raise AssertionError(f"expected one mutation anchor: {old!r}")
    return source.replace(old, new, 1)


def source_mutation(source, replacements):
    for old, new in replacements:
        source = replace_once(source, old, new)
    return source


def compile_test(compiler, source_path, binary_path):
    subprocess.run(
        [compiler, "-m32", "-fno-builtin", "-Iinclude", str(source_path),
         "tests/native/trade_action_helper_218820_support.cpp",
         "tests/native/trade_action_helper_218820_test.cpp", "-o", str(binary_path)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )


def disable_core_dump():
    resource.setrlimit(resource.RLIMIT_CORE, (0, 0))


def run_case(binary_path, case_number):
    return subprocess.run(
        [str(binary_path), str(case_number)], capture_output=True, text=True,
        preexec_fn=disable_core_dump,
    )


def verify_baseline(compiler, original_bytes):
    with tempfile.TemporaryDirectory(prefix="218820-baseline-") as directory:
        binary = Path(directory) / "native-test"
        compile_test(compiler, SOURCE_PATH, binary)
        for case_number in range(CASE_COUNT):
            result = run_case(binary, case_number)
            if result.returncode or "PASS" not in result.stdout:
                raise AssertionError(f"baseline case {case_number} failed: {result.stderr}")
    if SOURCE_PATH.read_bytes() != original_bytes:
        raise AssertionError("production source changed during baseline verification")


def verify_mutant(compiler, original_bytes, name, replacements, case_number, assertion):
    mutated = source_mutation(original_bytes.decode(), replacements)
    with tempfile.TemporaryDirectory(prefix=f"218820-{name}-") as directory:
        folder = Path(directory)
        mutant_path = folder / "mutant.cpp"
        mutant_path.write_text(mutated)
        binary = folder / "native-test"
        compile_test(compiler, mutant_path, binary)
        result = run_case(binary, case_number)
    if result.returncode == 0 or f"Assertion `{assertion}' failed" not in result.stderr:
        raise AssertionError(f"mutant {name} missed expected native assertion: {result.stderr}")
    if SOURCE_PATH.read_bytes() != original_bytes:
        raise AssertionError(f"production source changed while testing mutant {name}")
    print(f"rejected {name}: {assertion}")


def mutants():
    return [
        ("stale-state", [("    state1AC = *(int *)(s0 + 0x1AC);\n    if ((unsigned int)state1AC >= 8)", "    state1AC = state1AC;\n    if ((unsigned int)state1AC >= 8)")], 13, "handler_kinds[0] == expected_kind"),
        ("stale-dispatch-manager", [("    arg20 = *(void **)(s0 + 0x20);\n\n    void *f0c =", "    arg20 = arg20;\n\n    void *f0c =")], 16, "handler_calls[0].arguments[0] == pointer_value(manager_b)"),
        ("stale-cleanup-manager", [("    arg20 = *(void **)(s0 + 0x20);\n    func_001AB9D0(arg20);\n}\n", "    arg20 = arg20;\n    func_001AB9D0(arg20);\n}\n")], 16, "cleanup_calls[0].arguments[0] == pointer_value(manager_c)"),
        ("wrong-coordinate", [("(unsigned long)f14 - 1);", "(unsigned long)f14 - 2);")], 10, "record.arguments[3] == 13"),
        ("wrong-byte", [("case 2:\n            func_001AD940(arg20, f0c, f10, computed_arg3, computed_arg4, b1B5, b1B0);", "case 2:\n            func_001AD940(arg20, f0c, f10, computed_arg3, computed_arg4, b1B0, b1B5);")], 2, "record.arguments[5 + index] == expected[state - 1][index]"),
        ("state-eight-map", [("(unsigned int)state1AC >= 8", "(unsigned int)state1AC > 8"), ("        default:\n            break;", "        case 8:\n            func_001ACDF0(arg20, f0c, f10, computed_arg3, computed_arg4, b194);\n            break;\n        default:\n            break;")], 8, "handler_call_count == 0"),
        ("omitted-cleanup", [("    arg20 = *(void **)(s0 + 0x20);\n    func_001AB9D0(arg20);\n}\n", "    arg20 = *(void **)(s0 + 0x20);\n    (void)arg20;\n}\n")], 1, "cleanup_call_count == 1"),
        ("initial-zero-cleanup", [("    if (state1AC == 0) {\n        return;\n    }", "    if (state1AC == 0) {\n        func_001AB9D0(*(void **)(s0 + 0x20));\n        return;\n    }")], 0, "cleanup_call_count == 0"),
    ]


def main():
    compiler = shutil.which("g++")
    if compiler is None:
        raise SystemExit("g++ is required; mutations are not skipped")
    original_bytes = SOURCE_PATH.read_bytes()
    if hashlib.sha256(original_bytes).hexdigest() != SOURCE_SHA256:
        raise SystemExit("production source does not match the pinned input")
    verify_baseline(compiler, original_bytes)
    for mutation in mutants():
        verify_mutant(compiler, original_bytes, *mutation)
    if hashlib.sha256(SOURCE_PATH.read_bytes()).hexdigest() != SOURCE_SHA256:
        raise AssertionError("production source was not restored byte-for-byte")
    verify_baseline(compiler, original_bytes)
    print("all 19 baseline cases pass after mutation verification")


if __name__ == "__main__":
    main()
