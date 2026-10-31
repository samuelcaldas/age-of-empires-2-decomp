"""Compare the compiled C++ parsers with their relocated original PS2 code."""

import subprocess
from pathlib import Path

import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/trade/trade_action_stream_parsers.cpp"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
BINUTILS = ROOT / "build/mips_binutils"

# parsers file slice is 0x54D20 to 0x55290 (size 0x570 = 1392 bytes).
FILE_OFFSET = 0x54D20
START_ADDRESS = 0x154B30
SLICE_SIZE = 0x570

FUNCTIONS = (
    ("func_00154B30", 0x154B30, 0x0AC),
    ("func_00154BE0", 0x154BE0, 0x0E4),
    ("func_00154CD0", 0x154CD0, 0x0E4),
    ("func_00154DC0", 0x154DC0, 0x0E0),
    ("func_00154EA0", 0x154EA0, 0x0F8),
    ("func_00154FA0", 0x154FA0, 0x100),
)
SYMBOLS = {
    "_gp": 0x4EA7C0,
    "D_004E2DA0": 0x4E2DA0,
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


def compile_parsers(directory):
    """Compile the current C++ source with the project's verified MWCC flags."""
    run_tool([
        str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
        "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
        "-c", str(SOURCE), "-o", str(directory),
    ])
    return directory / "trade_action_stream_parsers.o"


def write_linker_script(directory):
    """Place the code and resolve external relocations at true PS2 VRAM addresses."""
    definitions = "\n".join(f"{name} = {address:#x};" for name, address in SYMBOLS.items())
    sections = (
        "\nSECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n"
    )
    script = directory / "parsers.ld"
    script.write_text(definitions + sections, encoding="utf-8")
    return script


def link_parsers(directory, object_file):
    """Link the compiled object and return only its relocated text bytes."""
    script = write_linker_script(directory)
    linked = directory / "parsers.elf"
    binary = directory / "parsers.bin"
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
def parsers_code(tmp_path_factory):
    """Compile and link once for all original-code comparisons."""
    directory = tmp_path_factory.mktemp("parsers")
    object_file = compile_parsers(directory)
    return link_parsers(directory, object_file)


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
    assert START_ADDRESS == 0x154B30


@pytest.mark.parametrize("name,address,size", FUNCTIONS)
def test_parsers_function_bytes(parsers_code, name, address, size):
    """Require exact instructions for each function after resolving relocations."""
    offset = address - START_ADDRESS
    assert_same_code(parsers_code[offset:offset + size], read_original(offset, size), address)


def test_parsers_slice_including_padding(parsers_code):
    """Require exact bytes across all six functions and their alignment padding."""
    assert len(parsers_code) == SLICE_SIZE
    assert_same_code(parsers_code, read_original(0, SLICE_SIZE), START_ADDRESS)
