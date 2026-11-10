"""Native semantic regressions and binary matching for zone_spatial_grid_destroy_static_node_pool."""

from pathlib import Path
import shutil
import subprocess

import pytest


PROJECT_ROOT = Path(__file__).resolve().parents[1]
CASES = [
    ("0", "func_001EB2A0 destroy 256 static nodes with element size 0x2C"),
]


@pytest.fixture(scope="module")
def destroy_test_binary(tmp_path_factory):
    """Compile real source with test driver."""
    compiler = shutil.which("g++")
    if compiler is None:
        pytest.skip("native tests require g++")
    binary = tmp_path_factory.mktemp("destroy_pool") / "zone-destroy-pool-test"
    subprocess.run(
        [compiler, "-fno-builtin", "-Iinclude",
         "src/zone/zone_spatial_grid_destroy_static_node_pool.cpp",
         "tests/native/zone_spatial_grid_destroy_static_node_pool_test.cpp",
         "-o", str(binary)],
        cwd=PROJECT_ROOT, check=True, capture_output=True, text=True,
    )
    return binary


@pytest.mark.parametrize("case,description", CASES, ids=[case[1] for case in CASES])
def test_destroy_static_node_pool_behavior(destroy_test_binary, case, description):
    """Check static node pool destruction behavior in isolated native process."""
    result = subprocess.run([str(destroy_test_binary), case], capture_output=True, text=True)
    assert result.returncode == 0, f"Case {case} failed with output: {result.stderr}"


ORIGINAL = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
SOURCE = PROJECT_ROOT / "src/zone/zone_spatial_grid_destroy_static_node_pool.cpp"
COMPILER = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = PROJECT_ROOT / "build/tools/wibo"
BINUTILS = PROJECT_ROOT / "build/mips_binutils"

FILE_OFFSET = 0xEB470
START_ADDRESS = 0x1EB2A0
SLICE_SIZE = 0x20

FUNCTIONS = (
    ("func_001EB2A0", 0x1EB2A0, 0x1C),
)
SYMBOLS = {
    "D_9397F0": 0x9397F0,
    "func_00100340": 0x100340,
    "func_001E4040": 0x1E4040,
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


def compile_destroy(directory):
    """Compile the current C++ source with the project's verified MWCC flags."""
    run_tool([
        str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
        "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++",
        "-c", str(SOURCE), "-o", str(directory),
    ])
    return directory / "zone_spatial_grid_destroy_static_node_pool.o"


def write_linker_script(directory):
    """Place the code at true PS2 VRAM addresses and declare external symbols."""
    definitions = "\n".join(f"{name} = {address:#x};" for name, address in SYMBOLS.items())
    sections = (
        "\nSECTIONS {\n"
        f"  .text {START_ADDRESS:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n"
    )
    script_path = directory / "destroy.ld"
    script_path.write_text(f"{definitions}\n{sections}")
    return script_path


def link_destroy(object_path, linker_script, directory):
    """Link the compiled object into a relocated ELF for exact comparison."""
    output_path = directory / "zone_spatial_grid_destroy_static_node_pool.elf"
    run_tool([
        str(BINUTILS / "mips-linux-gnu-ld"), "-EL", "-m", "elf32ltsmip",
        "-T", str(linker_script), str(object_path), "-o", str(output_path),
    ])
    return output_path


def extract_text_section(elf_path, directory):
    """Extract the linked machine code bytes."""
    output_path = directory / "destroy.bin"
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
def test_zone_spatial_grid_destroy_static_node_pool_matching(name, address, size, tmp_path):
    """Compare MWCC compilation against original machine code byte-for-byte."""
    missing = [str(path) for path in REQUIRED_FILES if not path.exists()]
    if missing:
        pytest.skip(f"missing matching prerequisite: {missing[0]}")

    object_path = compile_destroy(tmp_path)
    linker_script = write_linker_script(tmp_path)
    elf_path = link_destroy(object_path, linker_script, tmp_path)
    compiled_bytes = extract_text_section(elf_path, tmp_path)
    original_bytes = read_original_slice()

    offset = address - START_ADDRESS
    compiled_function = compiled_bytes[offset:offset + size]
    original_function = original_bytes[offset:offset + size]

    assert compiled_function == original_function, (
        f"{name} at {address:#x} diverges from authentic SLES-50282 binary"
    )
