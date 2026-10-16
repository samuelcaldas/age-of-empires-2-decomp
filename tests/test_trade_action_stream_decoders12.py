"""Compare the compiled C++ decoders12 with their relocated original PS2 code."""

import subprocess
from pathlib import Path

import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/trade_action_stream_decoders12.cpp"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
BINUTILS = ROOT / "build/mips_binutils"

# PT_LOAD VRAM derivation:
# p_vaddr = 0x100000, p_offset = 0x1E0 -> VRAM = file_offset + 0xFFE20.
# decoders12 slice: file 0x5F400 to 0x5F630 (size 0x230 = 560 bytes).
FILE_OFFSET = 0x5F400
START_ADDRESS = FILE_OFFSET + 0xFFE20  # 0x15F220
SLICE_SIZE = 0x230

# Function offsets and sizes:
# func_0015F220: 0x15F220, 272 bytes (0x110)
# func_0015F330: 0x15F330, 276 bytes (0x114)
# Tail padding: 12 bytes (0x224 to 0x230)
F220_OFFSET = 0x0
F220_SIZE = 0x110

F330_OFFSET = 0x110
F330_SIZE = 0x114

TAIL_PAD_OFFSET = 0x224
TAIL_PAD_SIZE = 0xC

FUNCTIONS = [
    ("func_0015F220", START_ADDRESS + F220_OFFSET, F220_SIZE),
    ("func_0015F330", START_ADDRESS + F330_OFFSET, F330_SIZE),
]

SYMBOLS = {
    "_gp": 0x4EA7C0,
    "D_004E2DA0": 0x4E2DA0,
    "D_004E2DA4": 0x4E2DA4,
    "D_004E2DAC": 0x4E2DAC,
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


def compile_decoders(directory):
    """Compile the current C++ source with the project's verified MWCC flags."""
    run_tool([
        str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
        "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
        "-c", str(SOURCE), "-o", str(directory),
    ])
    return directory / "trade_action_stream_decoders12.o"


def write_linker_script(directory):
    """Place the code and resolve external relocations at true PS2 VRAM addresses."""
    definitions = "\n".join(f"{name} = {address:#x};" for name, address in SYMBOLS.items())
    sections = (
        "\nSECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n"
    )
    script = directory / "decoders12.ld"
    script.write_text(definitions + sections, encoding="utf-8")
    return script


def link_decoders(directory, object_file):
    """Link the compiled object and return only its relocated text bytes."""
    script = write_linker_script(directory)
    linked = directory / "decoders12.elf"
    binary = directory / "decoders12.bin"
    run_tool([
        str(BINUTILS / "mips-linux-gnu-ld"), "-EL", "--no-undefined", "-T", str(script),
        "-o", str(linked), str(object_file),
    ])
    run_tool([
        str(BINUTILS / "mips-linux-gnu-objcopy"), "-O", "binary",
        "--only-section=.text", str(linked), str(binary),
    ])
    return binary.read_bytes()


@pytest.fixture(scope="module")
def decoder_code(tmp_path_factory):
    """Compile and link once for all original-code comparisons."""
    directory = tmp_path_factory.mktemp("decoders12")
    object_file = compile_decoders(directory)
    return link_decoders(directory, object_file)


def read_original(offset, size):
    """Read only the requested range of the locally supplied original ELF."""
    with ORIGINAL.open("rb") as original:
        original.seek(FILE_OFFSET + offset)
        return original.read(size)


def assert_same_code(actual, expected, address):
    """Fail at the first differing address without dumping proprietary code."""
    assert len(actual) == len(expected), f"Code length differs at {address:#x}: {len(actual)} vs {len(expected)}"
    differences = (index for index, pair in enumerate(zip(actual, expected)) if pair[0] != pair[1])
    first_difference = next(differences, None)
    assert first_difference is None, f"Instruction bytes differ at {address + first_difference:#x}"


def test_vram_mapping_matches_pt_load():
    """Verify that START_ADDRESS is derived strictly from PT_LOAD offset + vaddr."""
    header = ORIGINAL.read_bytes()[:0x54]
    p_offset = int.from_bytes(header[0x38:0x3C], "little")  # 0x1E0
    p_vaddr = int.from_bytes(header[0x3C:0x40], "little")   # 0x100000
    pt_load_diff = p_vaddr - p_offset                       # 0xFFE20
    assert START_ADDRESS == FILE_OFFSET + pt_load_diff, (
        f"START_ADDRESS {START_ADDRESS:#x} drift from PT_LOAD {FILE_OFFSET + pt_load_diff:#x}"
    )


def test_slice_total_extent(decoder_code):
    """Verify full 560-byte slice length emitted by compiler and linker."""
    assert len(decoder_code) == SLICE_SIZE


@pytest.mark.parametrize("name,address,size", FUNCTIONS)
def test_decoder_function_bytes(decoder_code, name, address, size):
    """Require exact instructions for each function after resolving relocations."""
    offset = address - START_ADDRESS
    assert_same_code(decoder_code[offset:offset + size], read_original(offset, size), address)


def test_tail_alignment_padding(decoder_code):
    """Require exact 12-byte zero padding at end of slice."""
    actual_pad = decoder_code[TAIL_PAD_OFFSET:TAIL_PAD_OFFSET + TAIL_PAD_SIZE]
    expected_pad = read_original(TAIL_PAD_OFFSET, TAIL_PAD_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + TAIL_PAD_OFFSET)


def test_complete_slice_exact_bytes(decoder_code):
    """Require exact bytes across both functions and their alignment padding."""
    assert len(decoder_code) == SLICE_SIZE
    assert_same_code(decoder_code, read_original(0, SLICE_SIZE), START_ADDRESS)
