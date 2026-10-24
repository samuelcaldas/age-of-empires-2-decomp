from io import BytesIO
from pathlib import Path
import hashlib
import subprocess

from elftools.elf.elffile import ELFFile
import pytest


ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER = ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WRAPPER = ROOT / "build/tools/wibo"
SOURCE = ROOT / "src/network/network_utf16_length_3394b0.cpp"
START, SIZE = 0x3394B0, 0x28
SHA1 = "f478e19f2059d52899b691483ef5c7522e30e17c"


def require_inputs():
    missing = [str(path) for path in (ORIGINAL, COMPILER, WRAPPER) if not path.is_file()]
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))


def virtual_bytes(image, address, size):
    with BytesIO(image) as stream:
        segments = [segment for segment in ELFFile(stream).iter_segments()
                    if segment["p_type"] == "PT_LOAD" and segment["p_vaddr"] <= address
                    and address + size <= segment["p_vaddr"] + segment["p_filesz"]]
    assert len(segments) == 1
    offset = segments[0]["p_offset"] + address - segments[0]["p_vaddr"]
    return image[offset:offset + size]


def test_utf16_length_matches_every_original_byte(tmp_path):
    require_inputs()
    image = ORIGINAL.read_bytes()
    assert hashlib.sha1(image).hexdigest() == SHA1
    output = tmp_path / "utf16-length.o"
    result = subprocess.run(
        [str(WRAPPER), str(COMPILER), "-O3", "-inline", "on", "-msext", "on",
         "-char", "signed", "-sym", "off", "-Iinclude", "-lang=c++", "-c",
         str(SOURCE), "-o", str(output)], cwd=ROOT, capture_output=True, text=True,
        env={**__import__("os").environ, "MWCIncludes": ""},
    )
    assert result.returncode == 0, result.stdout + result.stderr
    with output.open("rb") as stream:
        elf = ELFFile(stream)
        entries = elf.get_section_by_name(".symtab").get_symbol_by_name("func_003394B0")
        assert entries and len(entries) == 1
        function = entries[0]
        assert function["st_size"] == SIZE
        section = elf.get_section(function["st_shndx"])
        actual = section.data()[function["st_value"]:function["st_value"] + SIZE]
        assert not [rel for relsec in elf.iter_sections()
                    if relsec["sh_type"] == "SHT_REL"
                    and relsec["sh_info"] == function["st_shndx"]
                    for rel in relsec.iter_relocations()
                    if function["st_value"] <= rel["r_offset"] < function["st_value"] + SIZE]
    expected = virtual_bytes(image, START, SIZE)
    difference = next((i for i, pair in enumerate(zip(actual, expected))
                       if pair[0] != pair[1]), None)
    assert difference is None, f"bytes differ at {START + difference:#x}"


def test_utf16_length_alignment_padding_is_zero():
    require_inputs()
    image = ORIGINAL.read_bytes()
    assert virtual_bytes(image, START + SIZE, 8) == b"\0" * 8
