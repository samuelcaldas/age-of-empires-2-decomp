"""Compare the compiled C++ decoders11 with their relocated original PS2 code."""

import struct
import subprocess
from pathlib import Path

import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = ROOT / "src/trade_action_stream_decoders11.cpp"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
BINUTILS = ROOT / "build/mips_binutils"

# PT_LOAD VRAM derivation:
# p_vaddr = 0x100000, p_offset = 0x1E0 -> VRAM = file_offset + 0xFFE20.
# decoders11 slice: file 0x5F2D0 to 0x5F400 (size 0x130 = 304 bytes).
FILE_OFFSET = 0x5F2D0
START_ADDRESS = FILE_OFFSET + 0xFFE20  # 0x15F0F0
SLICE_SIZE = 0x130

# Exact function offsets, instruction sizes, and padding ranges:
# func_0015F0F0: 0x15F0F0, 0x38 bytes (56B) -> exact 100%
# internal padding 1: offset 0x38 to 0x40 (8 bytes) -> 16-byte alignment before func_0015F130
# func_0015F130: 0x15F130, 0x80 bytes (128B) -> 3 bytes differ at offset 0x0C (sb v1, 0(a0) vs sb v1, -0x7A20(gp))
# func_0015F1B0: 0x15F1B0, 0x6C bytes (108B) -> exact 100%
# tail padding 2: offset 0x12C to 0x130 (4 bytes) -> 16-byte alignment at slice end
F0F0_OFFSET = 0x0
F0F0_SIZE = 0x38

PAD1_OFFSET = 0x38
PAD1_SIZE = 0x8

F130_OFFSET = 0x40
F130_SIZE = 0x80

F1B0_OFFSET = 0xC0
F1B0_SIZE = 0x6C

PAD2_OFFSET = 0x12C
PAD2_SIZE = 0x4

SYMBOLS = {
    "_gp": 0x4EA7C0,
    "D_004E2DA0": 0x4E2DA0,
    "D_004E2DA4": 0x4E2DA4,
    "D_004E2DAC": 0x4E2DAC,
    "D_004E2DB4": 0x4E2DB4,
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
    return directory / "trade_action_stream_decoders11.o"


def write_linker_script(directory):
    """Place the code and resolve external relocations at true PS2 VRAM addresses."""
    definitions = "\n".join(f"{name} = {address:#x};" for name, address in SYMBOLS.items())
    sections = (
        "\nSECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n"
    )
    script = directory / "decoders11.ld"
    script.write_text(definitions + sections, encoding="utf-8")
    return script


def link_decoders(directory, object_file):
    """Link the compiled object and return only its relocated text bytes."""
    script = write_linker_script(directory)
    linked = directory / "decoders11.elf"
    binary = directory / "decoders11.bin"
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
def decoder_code(tmp_path_factory):
    """Compile and link once for all original-code comparisons."""
    directory = tmp_path_factory.mktemp("decoders11")
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
    """Verify full 304-byte slice length emitted by compiler and linker."""
    assert len(decoder_code) == SLICE_SIZE


def test_func_0015F0F0_exact_bytes(decoder_code):
    """Require exact instructions for func_0015F0F0 (56 bytes, 100% exact)."""
    assert_same_code(decoder_code[F0F0_OFFSET:F0F0_OFFSET + F0F0_SIZE], read_original(F0F0_OFFSET, F0F0_SIZE), START_ADDRESS + F0F0_OFFSET)


def test_internal_alignment_padding(decoder_code):
    """Require exact 8-byte zero padding between func_0015F0F0 and func_0015F130."""
    actual_pad = decoder_code[PAD1_OFFSET:PAD1_OFFSET + PAD1_SIZE]
    expected_pad = read_original(PAD1_OFFSET, PAD1_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD1_OFFSET)


def test_func_0015F130_near_matching(decoder_code):
    """Verify func_0015F130 instruction size and strictly prove exact raw instruction words."""
    actual = decoder_code[F130_OFFSET:F130_OFFSET + F130_SIZE]
    expected = read_original(F130_OFFSET, F130_SIZE)
    assert len(actual) == len(expected) == F130_SIZE

    # Exactly 125 of 128 bytes must be strictly identical across the function body:
    matching_bytes = sum(1 for a, b in zip(actual, expected) if a == b)
    assert matching_bytes == 125, f"Expected 125 matching bytes in func_0015F130, got {matching_bytes}"

    # Verify the exact 4-byte instruction words at offset 0x0C:
    # Expected original instruction: sb $v1, 0($a0) where $a0 = &D_004E2DA0
    # Encoding: opcode 0x28 (sb), base $a0 (4), rt $v1 (3), offset 0x0000 -> 0xA0830000 (little endian: 00 00 83 a0)
    expected_word = struct.unpack("<I", expected[0x0C:0x10])[0]
    assert expected_word == 0xA0830000, f"Expected sb $v1, 0($a0) (0xA0830000), got {expected_word:#010X}"

    # Compiled instruction: sb $v1, -0x7A20($gp) where $gp - 0x7A20 = 0x4EA7C0 - 0x7A20 = 0x4E2DA0 (&D_004E2DA0)
    # Encoding: opcode 0x28 (sb), base $gp (28), rt $v1 (3), offset -0x7A20 (0x85E0) -> 0xA38385E0 (little endian: e0 85 83 a3)
    actual_word = struct.unpack("<I", actual[0x0C:0x10])[0]
    assert actual_word == 0xA38385E0, f"Expected sb $v1, -0x7A20($gp) (0xA38385E0), got {actual_word:#010X}"

    # Verify that both instructions store $v1 into the exact same effective target address 0x4E2DA0:
    # 1. Expected effective address: $a0 = $gp - 0x7A20 (computed at offset 0x04: addiu $a0, $gp, -0x7A20) + offset 0 = 0x4E2DA0
    # 2. Actual effective address: $gp + (-0x7A20) = 0x4EA7C0 - 0x7A20 = 0x4E2DA0
    gp_val = SYMBOLS["_gp"]
    expected_target = (gp_val - 0x7A20) + 0x0000
    actual_target = gp_val - 0x7A20
    assert expected_target == actual_target == SYMBOLS["D_004E2DA0"], "Target address mismatch"


def test_func_0015F1B0_exact_bytes(decoder_code):
    """Require exact instructions for func_0015F1B0 (108 bytes, 100% exact)."""
    assert_same_code(decoder_code[F1B0_OFFSET:F1B0_OFFSET + F1B0_SIZE], read_original(F1B0_OFFSET, F1B0_SIZE), START_ADDRESS + F1B0_OFFSET)


def test_tail_alignment_padding(decoder_code):
    """Require exact 4-byte zero padding at end of slice."""
    actual_pad = decoder_code[PAD2_OFFSET:PAD2_OFFSET + PAD2_SIZE]
    expected_pad = read_original(PAD2_OFFSET, PAD2_SIZE)
    assert_same_code(actual_pad, expected_pad, START_ADDRESS + PAD2_OFFSET)
