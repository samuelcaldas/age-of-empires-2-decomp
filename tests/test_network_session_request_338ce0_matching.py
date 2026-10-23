from pathlib import Path
import sys
import tempfile

from elftools.elf.elffile import ELFFile
import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tests"))
import network_match_support as match

SOURCE = ROOT / "src/network_session_request_338ce0.cpp"
NAME = "func_00338CE0"
ADDRESS = 0x338CE0
SIZE = 0x2BC
RELOCATIONS = 40
EXTERNALS = {
    "func_117af8": 0x117AF8,
    "func_117cac": 0x117CAC,
    "func_11abbc": 0x11ABBC,
    "func_11acd0": 0x11ACD0,
    "func_11b170": 0x11B170,
    "func_337840": 0x337840,
    "func_103358": 0x103358,
    "func_2261C0": 0x2261C0,
    "D_004E352C": 0x4E352C,
    "D_0108AFA0": 0x108AFA0,
    "D_00492C60": 0x492C60,
    "D_004D1F18": 0x4D1F18,
    "D_004D1F10": 0x4D1F10,
}


def test_session_request_matches_original_and_padding():
    missing = match.private_inputs_missing()
    if missing:
        pytest.skip("requires original ELF and PS2 tools; missing: " + ", ".join(missing))
    image = match.verified_original_image()
    with tempfile.TemporaryDirectory() as directory:
        object_path = match.compile_object(SOURCE, directory)
        with object_path.open("rb") as stream:
            elf = ELFFile(stream)
            symbols = elf.get_section_by_name(".symtab")
            function = symbols.get_symbol_by_name(NAME)[0]
            relocations = [
                relocation
                for section in elf.iter_sections()
                if section["sh_type"] == "SHT_REL" and section["sh_info"] == function["st_shndx"]
                for relocation in section.iter_relocations()
            ]
            assert len(relocations) == RELOCATIONS
        actual = match.relocated_function(
            object_path, NAME, ADDRESS, SIZE, EXTERNALS, RELOCATIONS,
        )
    expected = match.original_bytes(image, ADDRESS, SIZE)
    match.assert_exact(actual, expected, ADDRESS)
    assert match.original_bytes(image, ADDRESS + SIZE, 4) == b"\0" * 4
