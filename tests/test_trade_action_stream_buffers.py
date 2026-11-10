"""Native semantic regressions and binary matching for trade_action_stream_buffers."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_00152F30 4-byte copy + stage 3-byte stream"),
    ("1", "func_00153050 4-byte copy + stage 3-byte stream"),
    ("2", "func_00153170 4-byte copy + stage 3-byte stream"),
    ("3", "func_00153290 4-byte unrolled loop stream"),
    ("4", "func_00153350 1-byte copy + 4-byte unrolled loop stream"),
]


@pytest.fixture(scope="module")
def buffers_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("buffers") / "trade-action-stream-buffers-test"
    subprocess.run(
        [compiler, "-fno-builtin", "-Iinclude",
         "src/trade/trade_action_stream_buffers.cpp",
         "tests/native/trade_action_stream_buffers_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_buffers_behavior(buffers_test_binary, case, description):
    """Check stream transformation behavior in isolated native process."""
    result = subprocess.run([str(buffers_test_binary), case], capture_output=True, text=True)
    assert result.returncode == 0, f"Case {case} failed with output: {result.stderr}"


ORIGINAL = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = PROJECT_ROOT / "src/trade/trade_action_stream_buffers.cpp"
COMPILER = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = PROJECT_ROOT / "build/tools/wibo"
BINUTILS = PROJECT_ROOT / "build/mips_binutils"

FILE_OFFSET = 0x53120
START_ADDRESS = 0x152F30
SLICE_SIZE = 0x510

FUNCTIONS = (
    ("func_00152F30", 0x152F30, 0x120),
    ("func_00153050", 0x153050, 0x120),
    ("func_00153170", 0x153170, 0x120),
    ("func_00153290", 0x153290, 0xC0),
    ("func_00153350", 0x153350, 0xF0),
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


def run_tool(arguments):
    """Run a local build tool, raising on a nonzero exit status."""
    subprocess.run(arguments, cwd=PROJECT_ROOT, capture_output=True, text=True, check=True)


def compile_buffers(directory):
    """Compile the current C++ source with the project's verified MWCC flags."""
    run_tool([
        str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
        "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
        "-c", str(SOURCE), "-o", str(directory),
    ])
    return directory / "trade_action_stream_buffers.o"


def write_linker_script(directory):
    """Place the code and resolve external relocations at true PS2 VRAM addresses."""
    definitions = "\n".join(f"{name} = {address:#x};" for name, address in SYMBOLS.items())
    sections = (
        "\nSECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n"
    )
    script_path = directory / "buffers.ld"
    script_path.write_text(f"{definitions}\n{sections}")
    return script_path


def link_buffers(object_path, linker_script, directory):
    """Link the compiled object into a relocated ELF for exact comparison."""
    output_path = directory / "trade_action_stream_buffers.elf"
    run_tool([
        str(BINUTILS / "mips-linux-gnu-ld"), "-EL", "-m", "elf32ltsmip",
        "-T", str(linker_script), str(object_path), "-o", str(output_path),
    ])
    return output_path


def extract_text_section(elf_path, directory):
    """Extract the linked machine code bytes."""
    output_path = directory / "buffers.bin"
    run_tool([
        str(BINUTILS / "mips-linux-gnu-objcopy"), "-O", "binary",
        "--only-section=.text", str(elf_path), str(output_path),
    ])
    return output_path.read_bytes()


def read_original_slice():
    """Read the byte slice from the authentic PS2 PAL ELF."""
    with ORIGINAL.open("rb") as stream:
        stream.seek(FILE_OFFSET)
        data = stream.read(SLICE_SIZE)
    assert len(data) == SLICE_SIZE, f"wanted {SLICE_SIZE:#x} bytes, got {len(data):#x}"
    return data


@pytest.mark.parametrize("name,address,size", FUNCTIONS)
def test_trade_action_stream_buffers_matching(name, address, size, tmp_path):
    """Compare MWCC compilation against original machine code byte-for-byte."""
    missing = [str(path) for path in REQUIRED_FILES if not path.exists()]
    if missing:
        pytest.skip(f"missing matching prerequisite: {missing[0]}")

    object_path = compile_buffers(tmp_path)
    linker_script = write_linker_script(tmp_path)
    elf_path = link_buffers(object_path, linker_script, tmp_path)
    compiled_bytes = extract_text_section(elf_path, tmp_path)
    original_bytes = read_original_slice()

    offset = address - START_ADDRESS
    compiled_function = compiled_bytes[offset:offset + size]
    original_function = original_bytes[offset:offset + size]

    assert compiled_function == original_function, (
        f"{name} at {address:#x} diverges from authentic SLES-50282 binary"
    )
