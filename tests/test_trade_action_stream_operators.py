"""Native semantic regressions and binary matching for trade_action_stream_operators."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0015C2F0 3-byte lead + 4-byte stream loop + 3-byte trail"),
    ("1", "func_0015C490 1-byte read + mask + write"),
    ("2", "func_0015C4E0 1-byte read at offset 1 + mask + write"),
    ("3", "func_0015C530 2-byte read + mask + write"),
    ("4", "func_0015C5B0 2-byte read at offset -1 + mask + shift + write"),
    ("5", "func_0015C640 3-byte read + mask + write"),
    ("6", "func_0015C6E0 3-byte read at offset -1 + mask + write"),
    ("7", "func_0015C780 2-byte read + 1-byte read + write"),
    ("8", "func_0015C850 1-byte read + 2-byte read + write"),
]


@pytest.fixture(scope="module")
def operators_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("operators") / "trade-action-stream-operators-test"
    subprocess.run(
        [compiler, "-fno-builtin", "-Iinclude",
         "src/trade/trade_action_stream_operators.cpp",
         "tests/native/trade_action_stream_operators_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_operators_behavior(operators_test_binary, case, description):
    """Check stream transformation behavior in isolated native process."""
    result = subprocess.run([str(operators_test_binary), case], capture_output=True, text=True)
    assert result.returncode == 0, f"Case {case} failed with output: {result.stderr}"


ORIGINAL = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = PROJECT_ROOT / "src/trade/trade_action_stream_operators.cpp"
COMPILER = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = PROJECT_ROOT / "build/tools/wibo"
BINUTILS = PROJECT_ROOT / "build/mips_binutils"

# operators file slice is 0x5C4E0 to 0x5CB10 (size 0x630 = 1584 bytes).
FILE_OFFSET = 0x5C4E0
START_ADDRESS = 0x15C2F0
SLICE_SIZE = 0x630

FUNCTIONS = (
    ("func_0015C2F0", 0x15C2F0, 0x1A0),
    ("func_0015C490", 0x15C490, 0x50),
    ("func_0015C4E0", 0x15C4E0, 0x50),
    ("func_0015C530", 0x15C530, 0x80),
    ("func_0015C5B0", 0x15C5B0, 0x90),
    ("func_0015C640", 0x15C640, 0xA0),
    ("func_0015C6E0", 0x15C6E0, 0xA0),
    ("func_0015C780", 0x15C780, 0xD0),
    ("func_0015C850", 0x15C850, 0xD0),
)
SYMBOLS = {
    "_gp": 0x4EA7C0,
    "D_004E2DA0": 0x4E2DA0,
    "D_004E2DA4": 0x4E2DA4,
    "D_004E2DA8": 0x4E2DA8,
    "D_004E2DB0": 0x4E2DB0,
    "D_004E2DB4": 0x4E2DB4,
    "D_004E30A8": 0x4E30A8,
    "D_004E30B0": 0x4E30B0,
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


def compile_operators(directory):
    """Compile the current C++ source with the project's verified MWCC flags."""
    run_tool([
        str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
        "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
        "-c", str(SOURCE), "-o", str(directory),
    ])
    return directory / "trade_action_stream_operators.o"


def write_linker_script(directory):
    """Place the code and resolve external relocations at true PS2 VRAM addresses."""
    definitions = "\n".join(f"{name} = {address:#x};" for name, address in SYMBOLS.items())
    sections = (
        "\nSECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n"
    )
    script = directory / "operators.ld"
    script.write_text(definitions + sections, encoding="utf-8")
    return script


def link_operators(directory, object_file):
    """Link the compiled object and return only its relocated text bytes."""
    script = write_linker_script(directory)
    linked = directory / "operators.elf"
    binary = directory / "operators.bin"
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
def operators_code(tmp_path_factory):
    """Compile and link once for all original-code comparisons."""
    if not all(path.is_file() for path in REQUIRED_FILES):
        pytest.skip("Requires the private SLES-50282 binary and locally supplied PS2 tools")
    directory = tmp_path_factory.mktemp("operators_matching")
    object_file = compile_operators(directory)
    return link_operators(directory, object_file)


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
def test_function_matches_original_slice(operators_code, original_slice, name, address, size):
    """Ensure compiled routine identically reproduces PS2 machine code bytes."""
    offset = address - START_ADDRESS
    original_bytes = original_slice[offset:offset + size]
    recompiled_bytes = operators_code[offset:offset + size]

    assert len(recompiled_bytes) == size, f"Premature EOF in linked output for {name}"
    assert recompiled_bytes == original_bytes, f"Mismatch in {name} ({size} bytes)"


def test_full_slice_matches(operators_code, original_slice):
    """Catch padding or layout regressions across the full object boundary."""
    assert operators_code[:SLICE_SIZE] == original_slice
