"""Native semantic regressions and binary matching for trade_action_stream_evaluators."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0015BD30 3-byte lead + 4-byte stream loop + 2-byte trail"),
    ("1", "func_0015BEC0 4-byte stream loop + 3-byte trail"),
    ("2", "func_0015BFF0 1-byte lead + 4-byte stream loop + 3-byte trail"),
    ("3", "func_0015C160 2-byte lead + 4-byte stream loop + 3-byte trail"),
]


@pytest.fixture(scope="module")
def evaluators_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("evaluators") / "trade-action-stream-evaluators-test"
    subprocess.run(
        [compiler, "-fno-builtin", "-Iinclude",
         "src/trade/trade_action_stream_evaluators.cpp",
         "tests/native/trade_action_stream_evaluators_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_evaluators_behavior(evaluators_test_binary, case, description):
    """Check stream transformation behavior in isolated native process."""
    result = subprocess.run([str(evaluators_test_binary), case], capture_output=True, text=True)
    assert result.returncode == 0, f"Case {case} failed with output: {result.stderr}"


ORIGINAL = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = PROJECT_ROOT / "src/trade/trade_action_stream_evaluators.cpp"
COMPILER = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = PROJECT_ROOT / "build/tools/wibo"
BINUTILS = PROJECT_ROOT / "build/mips_binutils"

# evaluators file slice is 0x5BF20 to 0x5C4E0 (size 0x5C0 = 1472 bytes).
FILE_OFFSET = 0x5BF20
START_ADDRESS = 0x15BD30
SLICE_SIZE = 0x5C0

FUNCTIONS = (
    ("func_0015BD30", 0x15BD30, 0x190),
    ("func_0015BEC0", 0x15BEC0, 0x130),
    ("func_0015BFF0", 0x15BFF0, 0x170),
    ("func_0015C160", 0x15C160, 0x190),
)
SYMBOLS = {
    "_gp": 0x4EA7C0,
    "D_004E2DA0": 0x4E2DA0,
    "D_004E2DA4": 0x4E2DA4,
    "D_004E2DA8": 0x4E2DA8,
    "D_004E2DB0": 0x4E2DB0,
    "D_004E2DB4": 0x4E2DB4,
    "func_001522C0": 0x1522C0,
}
REQUIRED_FILES = (
    ORIGINAL,
    COMPILER,
    WRAPPER,
    BINUTILS / "mips-linux-gnu-ld",
    BINUTILS / "mips-linux-gnu-objcopy",
)


def run_tool(arguments):
    """Run a local build tool, raising on a nonzero exit status."""
    subprocess.run(arguments, cwd=PROJECT_ROOT, capture_output=True, text=True, check=True)


def compile_evaluators(directory):
    """Compile the current C++ source with the project's verified MWCC flags."""
    run_tool([
        str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
        "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
        "-c", str(SOURCE), "-o", str(directory),
    ])
    return directory / "trade_action_stream_evaluators.o"


def write_linker_script(directory):
    """Place the code and resolve external relocations at true PS2 VRAM addresses."""
    definitions = "\n".join(f"{name} = {address:#x};" for name, address in SYMBOLS.items())
    sections = (
        "\nSECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n"
    )
    script = directory / "evaluators.ld"
    script.write_text(definitions + sections, encoding="utf-8")
    return script


def link_evaluators(directory, object_file):
    """Link the compiled object and return only its relocated text bytes."""
    script = write_linker_script(directory)
    linked = directory / "evaluators.elf"
    binary = directory / "evaluators.bin"
    run_tool([
        str(BINUTILS / "mips-linux-gnu-ld"), "-EL", "-T", str(script),
        "-o", str(linked), str(object_file),
    ])
    run_tool([
        str(BINUTILS / "mips-linux-gnu-objcopy"), "-O", "binary",
        "--only-section=.text", str(linked), str(binary),
    ])
    return binary.read_bytes()


@pytest.fixture(scope="module")
def evaluators_code(tmp_path_factory):
    """Compile and link once for all original-code comparisons."""
    if not all(path.is_file() for path in REQUIRED_FILES):
        pytest.skip("Requires the private SLES-50282 binary and locally supplied PS2 tools")
    directory = tmp_path_factory.mktemp("evaluators_matching")
    object_file = compile_evaluators(directory)
    return link_evaluators(directory, object_file)


@pytest.fixture(scope="module")
def original_slice():
    """Read the target slice directly from the uncommitted game binary."""
    if not ORIGINAL.is_file():
        pytest.skip("Target binary orig/SLES-50282/AOK.ELF is not present")
    with ORIGINAL.open("rb") as handle:
        handle.seek(FILE_OFFSET)
        data = handle.read(SLICE_SIZE)
    assert len(data) == SLICE_SIZE, f"Short read from target binary: {len(data)} != {SLICE_SIZE}"
    return data


@pytest.mark.parametrize("name,address,size", FUNCTIONS)
def test_function_matches_original_slice(evaluators_code, original_slice, name, address, size):
    """Ensure compiled routine identically reproduces PS2 machine code bytes."""
    offset = address - START_ADDRESS
    original_bytes = original_slice[offset:offset + size]
    recompiled_bytes = evaluators_code[offset:offset + size]

    assert len(recompiled_bytes) == size, f"Premature EOF in linked output for {name}"
    assert recompiled_bytes == original_bytes, f"Mismatch in {name} ({size} bytes)"


def test_full_slice_matches(evaluators_code, original_slice):
    """Catch padding or layout regressions across the full object boundary."""
    assert evaluators_code[:SLICE_SIZE] == original_slice
