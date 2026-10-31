"""Compare the compiled C++ aggregators with their relocated original PS2 code."""

import subprocess
from pathlib import Path

import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/trade/trade_action_stream_aggregators.cpp"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
BINUTILS = ROOT / "build/mips_binutils"

# aggregators file slice is 0x562C0 to 0x56860 (size 0x5A0 = 1440 bytes).
FILE_OFFSET = 0x562C0
START_ADDRESS = 0x1560D0
SLICE_SIZE = 0x5A0

FUNCTIONS = (
    ("func_001560D0", 0x1560D0, 0x120),
    ("func_001561F0", 0x1561F0, 0x160),
    ("func_00156350", 0x156350, 0x180),
    ("func_001564D0", 0x1564D0, 0x1A0),
)
SYMBOLS = {
    "_gp": 0x4EA7C0,
    "D_004E2DA0": 0x4E2DA0,
    "D_004E2DA8": 0x4E2DA8,
    "D_004E2DB0": 0x4E2DB0,
    "D_004E2DB4": 0x4E2DB4,
    "D_004E30A8": 0x4E30A8,
    "D_004E30AC": 0x4E30AC,
    "func_001522C0": 0x1522C0,
}
REQUIRED_FILES = (
    ORIGINAL,
    COMPILER,
    WRAPPER,
    BINUTILS / "mips-linux-gnu-ld",
    BINUTILS / "mips-linux-gnu-objcopy",
)
pytestmark = pytest.mark.skipif(
    not all(path.is_file() for path in REQUIRED_FILES),
    reason="Requires the private SLES-50282 binary and locally supplied PS2 tools",
)


def run_tool(arguments):
    """Run a local build tool, raising on a nonzero exit status."""
    subprocess.run(arguments, cwd=ROOT, capture_output=True, text=True, check=True)


def compile_aggregators(directory):
    """Compile the current C++ source with the project's verified MWCC flags."""
    run_tool([
        str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
        "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
        "-c", str(SOURCE), "-o", str(directory),
    ])
    return directory / "trade_action_stream_aggregators.o"


def write_linker_script(directory):
    """Place the code and resolve external relocations at true PS2 VRAM addresses."""
    definitions = "\n".join(f"{name} = {address:#x};" for name, address in SYMBOLS.items())
    sections = (
        "\nSECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n"
    )
    script = directory / "aggregators.ld"
    script.write_text(definitions + sections, encoding="utf-8")
    return script


def link_aggregators(directory, object_file):
    """Link the compiled object and return only its relocated text bytes."""
    script = write_linker_script(directory)
    linked = directory / "aggregators.elf"
    binary = directory / "aggregators.bin"
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
def aggregators_code(tmp_path_factory):
    """Compile and link once for all original-code comparisons."""
    directory = tmp_path_factory.mktemp("aggregators")
    object_file = compile_aggregators(directory)
    return link_aggregators(directory, object_file)


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
    assert START_ADDRESS == 0x1560D0


@pytest.mark.parametrize("name,address,size", FUNCTIONS)
def test_aggregators_function_bytes(aggregators_code, name, address, size):
    """Require exact instructions for each function after resolving relocations."""
    offset = address - START_ADDRESS
    assert_same_code(aggregators_code[offset:offset + size], read_original(offset, size), address)


def test_aggregators_slice_including_padding(aggregators_code):
    """Require exact bytes across all four functions and their alignment padding."""
    assert len(aggregators_code) == SLICE_SIZE
    assert_same_code(aggregators_code, read_original(0, SLICE_SIZE), START_ADDRESS)
