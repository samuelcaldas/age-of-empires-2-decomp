"""Native semantic regressions and binary matching for trade_action_stream_dispatchers."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_00159500 4-byte stream dispatch loop"),
    ("1", "func_00159580 byte 1 dispatch + loop"),
    ("2", "func_00159620 bytes 0,1 dispatch + loop"),
    ("3", "func_001596E0 bytes 1,0,1 dispatch + loop"),
    ("4", "func_001597B0 byte 2 dispatch + loop"),
    ("5", "func_001599D0 bytes 1,2,3 dispatch + loop"),
]


@pytest.fixture(scope="module")
def dispatchers_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("dispatchers") / "trade-action-stream-dispatchers-test"
    subprocess.run(
        [compiler, "-fno-builtin", "-Iinclude",
         "src/trade/trade_action_stream_dispatchers.cpp",
         "tests/native/trade_action_stream_dispatchers_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_dispatchers_behavior(dispatchers_test_binary, case, description):
    """Check stream dispatch behavior in isolated native process."""
    result = subprocess.run([str(dispatchers_test_binary), case], capture_output=True, text=True)
    assert result.returncode == 0, f"Case {case} failed with output: {result.stderr}"


ORIGINAL = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = PROJECT_ROOT / "src/trade/trade_action_stream_dispatchers.cpp"
COMPILER = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = PROJECT_ROOT / "build/tools/wibo"
BINUTILS = PROJECT_ROOT / "build/mips_binutils"

# dispatchers file slice is 0x596F0 to 0x59CA0 (size 0x5B0 = 1456 bytes).
FILE_OFFSET = 0x596F0
START_ADDRESS = 0x159500
SLICE_SIZE = 0x5B0

FUNCTIONS = (
    ("func_00159500", 0x159500, 0x080),
    ("func_00159580", 0x159580, 0x0A0),
    ("func_00159620", 0x159620, 0x0C0),
    ("func_001596E0", 0x1596E0, 0x0D0),
    ("func_001597B0", 0x1597B0, 0x0A0),
    ("func_00159850", 0x159850, 0x0B0),
    ("func_00159900", 0x159900, 0x0D0),
    ("func_001599D0", 0x1599D0, 0x0E0),
)
SYMBOLS = {
    "_gp": 0x4EA7C0,
    "D_004E2DA0": 0x4E2DA0,
    "D_004E2DA8": 0x4E2DA8,
    "D_004E2DB4": 0x4E2DB4,
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


def compile_dispatchers(directory):
    """Compile the current C++ source with the project's verified MWCC flags."""
    run_tool([
        str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
        "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
        "-c", str(SOURCE), "-o", str(directory),
    ])
    return directory / "trade_action_stream_dispatchers.o"


def write_linker_script(directory):
    """Place the code and resolve external relocations at true PS2 VRAM addresses."""
    definitions = "\n".join(f"{name} = {address:#x};" for name, address in SYMBOLS.items())
    sections = (
        "\nSECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n"
    )
    script = directory / "dispatchers.ld"
    script.write_text(definitions + sections, encoding="utf-8")
    return script


def link_dispatchers(directory, object_file):
    """Link the compiled object and return only its relocated text bytes."""
    script = write_linker_script(directory)
    linked = directory / "dispatchers.elf"
    binary = directory / "dispatchers.bin"
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
def dispatchers_code(tmp_path_factory):
    """Compile and link once for all original-code comparisons."""
    if not all(path.is_file() for path in REQUIRED_FILES):
        pytest.skip("Requires the private SLES-50282 binary and locally supplied PS2 tools")
    directory = tmp_path_factory.mktemp("dispatchers_matching")
    object_file = compile_dispatchers(directory)
    return link_dispatchers(directory, object_file)


def read_original(offset, size):
    """Read only the requested range of the locally supplied original ELF."""
    with ORIGINAL.open("rb") as original:
        original.seek(FILE_OFFSET + offset)
        return original.read(size)


def assert_same_code(actual, expected, address):
    """Fail at the first differing address without dumping proprietary code."""
    assert len(actual) == len(expected), f"Code length differs at {address:#x}"
    differences = (index for index, pair in enumerate(zip(actual, expected)) if pair[0] != pair[1])
    first_difference = next(differences, None)
    assert first_difference is None, f"Instruction bytes differ at {address + first_difference:#x}"


def test_vram_mapping_matches_config():
    """Verify that START_ADDRESS matches the declared segment VRAM in config.yml."""
    assert START_ADDRESS == 0x159500


@pytest.mark.parametrize("name,address,size", FUNCTIONS)
def test_dispatchers_function_bytes(dispatchers_code, name, address, size):
    """Require exact instructions for each function after resolving relocations."""
    offset = address - START_ADDRESS
    assert_same_code(dispatchers_code[offset:offset + size], read_original(offset, size), address)


def test_dispatchers_slice_including_padding(dispatchers_code):
    """Require exact bytes across all eight functions and their alignment padding."""
    assert len(dispatchers_code) == SLICE_SIZE
    assert_same_code(dispatchers_code, read_original(0, SLICE_SIZE), START_ADDRESS)
