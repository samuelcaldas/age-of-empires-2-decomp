"""Compare the compiled C++ unpackers with their relocated original PS2 code."""

import subprocess
from pathlib import Path

import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/trade/trade_action_stream_unpacker.cpp"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
BINUTILS = ROOT / "build/mips_binutils"

# unpacker file slice is 0x53BC0 to 0x540E0 (size 0x520 = 1312 bytes).
FILE_OFFSET = 0x53BC0
START_ADDRESS = 0x1539D0
SLICE_SIZE = 0x520

FUNCTIONS = (
    ("func_001539D0", 0x1539D0, 0x158),
    ("func_00153B30", 0x153B30, 0x118),
    ("func_00153C50", 0x153C50, 0x140),
    ("func_00153D90", 0x153D90, 0x160),
)
SYMBOLS = {
    "_gp": 0x4EA7C0,
    "D_004E2DA0": 0x4E2DA0,
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
pytestmark = pytest.mark.skipif(
    not all(path.is_file() for path in REQUIRED_FILES),
    reason="Requires the private SLES-50282 binary and locally supplied PS2 tools",
)


def run_tool(arguments):
    """Run a local build tool, raising on a nonzero exit status."""
    subprocess.run(arguments, cwd=ROOT, capture_output=True, text=True, check=True)


def compile_unpacker(directory):
    """Compile the current C++ source with the project's verified MWCC flags."""
    run_tool([
        str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
        "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
        "-c", str(SOURCE), "-o", str(directory),
    ])
    return directory / "trade_action_stream_unpacker.o"


def write_linker_script(directory):
    """Place the code and resolve external relocations at true PS2 VRAM addresses."""
    definitions = "\n".join(f"{name} = {address:#x};" for name, address in SYMBOLS.items())
    sections = (
        "\nSECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n"
    )
    script = directory / "unpacker.ld"
    script.write_text(definitions + sections, encoding="utf-8")
    return script


def link_unpacker(directory, object_file):
    """Link the compiled object and return only its relocated text bytes."""
    script = write_linker_script(directory)
    linked = directory / "unpacker.elf"
    binary = directory / "unpacker.bin"
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
def unpacker_code(tmp_path_factory):
    """Compile and link once for all original-code comparisons."""
    directory = tmp_path_factory.mktemp("unpacker")
    object_file = compile_unpacker(directory)
    return link_unpacker(directory, object_file)


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
    assert START_ADDRESS == 0x1539D0


@pytest.mark.parametrize("name,address,size", FUNCTIONS)
def test_unpacker_function_bytes(unpacker_code, name, address, size):
    """Require exact instructions for each function after resolving relocations."""
    offset = address - START_ADDRESS
    assert_same_code(unpacker_code[offset:offset + size], read_original(offset, size), address)


def test_unpacker_slice_including_padding(unpacker_code):
    """Require exact bytes across all four functions and their alignment padding."""
    assert len(unpacker_code) == SLICE_SIZE
    assert_same_code(unpacker_code, read_original(0, SLICE_SIZE), START_ADDRESS)
