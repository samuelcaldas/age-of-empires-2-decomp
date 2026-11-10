"""Native semantic regressions and binary matching for trade_action_stream_mutators."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_0015A1D0 1-byte mutator"),
    ("1", "func_0015A210 2-byte mutator"),
    ("2", "func_0015A280 2-byte mutator copy"),
    ("3", "func_0015A2F0 3-byte mutator"),
    ("4", "func_0015A380 3-byte mutator copy"),
    ("5", "func_0015A410 4-byte mutator"),
    ("6", "func_0015A4B0 4-byte mutator copy"),
    ("7", "func_0015A550 5-byte mutator (4+1)"),
    ("8", "func_0015A630 5-byte mutator copy (4+1)"),
]


@pytest.fixture(scope="module")
def mutators_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("mutators") / "trade-action-stream-mutators-test"
    subprocess.run(
        [compiler, "-fno-builtin", "-Iinclude",
         "src/trade/trade_action_stream_mutators.cpp",
         "tests/native/trade_action_stream_mutators_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_mutators_behavior(mutators_test_binary, case, description):
    """Check stream mutation behavior in isolated native process."""
    result = subprocess.run([str(mutators_test_binary), case], capture_output=True, text=True)
    assert result.returncode == 0, f"Case {case} failed with output: {result.stderr}"


ORIGINAL = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = PROJECT_ROOT / "src/trade/trade_action_stream_mutators.cpp"
COMPILER = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = PROJECT_ROOT / "build/tools/wibo"
BINUTILS = PROJECT_ROOT / "build/mips_binutils"

# mutators file slice is 0x5A3C0 to 0x5A900 (size 0x540 = 1344 bytes).
FILE_OFFSET = 0x5A3C0
START_ADDRESS = 0x15A1D0
SLICE_SIZE = 0x540

FUNCTIONS = (
    ("func_0015A1D0", 0x15A1D0, 0x040),
    ("func_0015A210", 0x15A210, 0x070),
    ("func_0015A280", 0x15A280, 0x070),
    ("func_0015A2F0", 0x15A2F0, 0x090),
    ("func_0015A380", 0x15A380, 0x090),
    ("func_0015A410", 0x15A410, 0x0A0),
    ("func_0015A4B0", 0x15A4B0, 0x0A0),
    ("func_0015A550", 0x15A550, 0x0E0),
    ("func_0015A630", 0x15A630, 0x0E0),
)
SYMBOLS = {
    "_gp": 0x4EA7C0,
    "D_004E2DA0": 0x4E2DA0,
    "D_004E2DA4": 0x4E2DA4,
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


def compile_mutators(directory):
    """Compile the current C++ source with the project's verified MWCC flags."""
    run_tool([
        str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
        "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
        "-c", str(SOURCE), "-o", str(directory),
    ])
    return directory / "trade_action_stream_mutators.o"


def write_linker_script(directory):
    """Place the code and resolve external relocations at true PS2 VRAM addresses."""
    definitions = "\n".join(f"{name} = {address:#x};" for name, address in SYMBOLS.items())
    sections = (
        "\nSECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n"
    )
    script = directory / "mutators.ld"
    script.write_text(definitions + sections, encoding="utf-8")
    return script


def link_mutators(directory, object_file):
    """Link the compiled object and return only its relocated text bytes."""
    script = write_linker_script(directory)
    linked = directory / "mutators.elf"
    binary = directory / "mutators.bin"
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
def mutators_code(tmp_path_factory):
    """Compile and link once for all original-code comparisons."""
    if not all(path.is_file() for path in REQUIRED_FILES):
        pytest.skip("Requires the private SLES-50282 binary and locally supplied PS2 tools")
    directory = tmp_path_factory.mktemp("mutators_matching")
    object_file = compile_mutators(directory)
    return link_mutators(directory, object_file)


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
def test_function_matches_original_slice(mutators_code, original_slice, name, address, size):
    """Ensure compiled routine identically reproduces PS2 machine code bytes."""
    offset = address - START_ADDRESS
    original_bytes = original_slice[offset:offset + size]
    recompiled_bytes = mutators_code[offset:offset + size]

    assert len(recompiled_bytes) == size, f"Premature EOF in linked output for {name}"
    assert recompiled_bytes == original_bytes, f"Mismatch in {name} ({size} bytes)"


def test_full_slice_matches(mutators_code, original_slice):
    """Catch padding or layout regressions across the full object boundary."""
    assert mutators_code[:SLICE_SIZE] == original_slice
