"""Independent Ninja-object, linked-byte, symbol, and address proofs for decoders28-31."""

from importlib import import_module
from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile

ROOT = Path("/home/samuelcaldas/source/repos/aoe/.worktrees/advisor-decoders28-31")
LINKER = Path("/home/samuelcaldas/source/repos/aoe/build/mips_binutils/mips-linux-gnu-ld")
PROOF = ROOT / "build/advisor-decoders28-31-proof"
SUPPORTS = {number: import_module(f"trade_action_stream_decoders{number}_support") for number in range(28, 32)}
NEAR = {
    "func_001658C0": 496, "func_00166100": 580,
    "func_00166A70": 648, "func_001675E0": 840,
}


def require_root():
    assert Path.cwd().resolve() == ROOT.resolve(), "proof must run from candidate worktree"


def run(command):
    require_root()
    arguments = [str(item) for item in command]
    if arguments[0] == "ninja":
        ninja_file = ROOT / "build.ninja"
        content = ninja_file.read_text(encoding="utf-8")
        invalid_default = "default build/SLES-50282/main.dol\n"
        object_default = "default build/SLES-50282/src/trade_action_stream_decoders28.o\n"
        if invalid_default in content:
            ninja_file.write_text(content.replace(invalid_default, object_default), encoding="utf-8")
    subprocess.run(arguments, cwd=ROOT, check=True)


def functions(number):
    return SUPPORTS[number].FUNCTIONS


def symbols(elf, names):
    table = elf.get_section_by_name(".symtab")
    assert table is not None, "missing symbol table"
    found = {}
    for name in names:
        matches = table.get_symbol_by_name(name)
        assert matches and len(matches) == 1, f"expected one {name}"
        found[name] = matches[0]
    return table, found


def check_object(number):
    path = ROOT / f"build/SLES-50282/src/trade_action_stream_decoders{number}.o"
    assert path.is_file(), f"missing Ninja ET_REL object {path}"
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf.header["e_type"] == "ET_REL"
        names = [entry[0] for entry in functions(number)]
        table, found = symbols(elf, names)
        indices = set()
        for name, _, size in functions(number):
            symbol = found[name]
            index = symbol["st_shndx"]
            assert isinstance(index, int) and index > 0, (name, index)
            assert symbol["st_info"]["type"] == "STT_FUNC"
            assert symbol["st_size"] == size
            section = elf.get_section(index)
            assert section.name == ".text" and section["sh_size"] == size
            indices.add(index)
        assert len(indices) == 4, f"{number}: expected four distinct .text st_shndx"
        undefined = {entry.name for entry in table.iter_symbols()
                     if entry.name and entry["st_shndx"] == "SHN_UNDEF"}
        expected = set(SUPPORTS[number].EXTERNAL_SYMBOLS) - {"_gp"}
        assert undefined == expected, (undefined, expected)
    return path


def linker_script(path, address, externals):
    assignments = "".join(f"{name} = {value:#x};\n" for name, value in externals.items())
    script = assignments + (
        "SECTIONS {\n"
        f"  .text {address:#x} : {{ *(.text) . = ALIGN(16); }}\n"
        "  /DISCARD/ : { *(*) }\n}\n"
    )
    path.write_text(script, encoding="utf-8")


def link(number, object_path, output, address, externals, entry, garbage_collect):
    require_root()
    script = output.with_suffix(".ld")
    linker_script(script, address, externals)
    command = [LINKER, "-EL", "-m", "elf32ltsmip", "--no-undefined"]
    if garbage_collect:
        command.append("--gc-sections")
    command.extend(["-e", entry, "-T", script, "-o", output, object_path])
    run(command)
    with output.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf.header["e_type"] == "ET_EXEC"
        table = elf.get_section_by_name(".symtab")
        unresolved = [entry.name for entry in table.iter_symbols()
                      if entry.name and entry["st_shndx"] == "SHN_UNDEF"]
        assert not unresolved, (number, entry, unresolved)
        section = elf.get_section_by_name(".text")
        assert section is not None and section["sh_addr"] == address
        _, found = symbols(elf, [entry])
        symbol = found[entry]
        assert symbol["st_info"]["type"] == "STT_FUNC"
        return section.data(), section["sh_addr"], symbol["st_value"], symbol["st_size"]


def sign16(value):
    return value - 0x10000 if value & 0x8000 else value


def check_near(name, actual, expected, externals):
    assert len(actual) == len(expected)
    original_word = int.from_bytes(expected[0x14:0x18], "little")
    emitted_word = int.from_bytes(actual[0x14:0x18], "little")
    original_base = externals["_gp"] + sign16(int.from_bytes(expected[0x0C:0x10], "little") & 0xFFFF)
    original_target = original_base + sign16(original_word & 0xFFFF)
    emitted_target = externals["_gp"] + sign16(emitted_word & 0xFFFF)
    target = externals["D_004E2DA0"]
    assert original_target == emitted_target == target, (
        f"{name}: original/effective/expected {original_target:#x}/"
        f"{emitted_target:#x}/{target:#x}"
    )
    assert (original_word, emitted_word) == (0xA0620000, 0xA38285E0), name
    assert ((original_word >> 21) & 31, (emitted_word >> 21) & 31) == (3, 28), name


def compare_code(name, actual, expected, externals):
    if name in NEAR:
        check_near(name, actual, expected, externals)
        differences = [index for index, pair in enumerate(zip(actual, expected))
                       if pair[0] != pair[1]]
        assert len(actual) - len(differences) == NEAR[name], name
        assert differences == list(range(0x14, 0x18)), (name, differences)
        return
    assert actual == expected, f"raw linked bytes differ for {name}"


def prove_unit(number, external_override=None):
    support = SUPPORTS[number]
    object_path = check_object(number)
    externals = dict(support.EXTERNAL_SYMBOLS)
    externals.update(external_override or {})
    PROOF.mkdir(parents=True, exist_ok=True)
    combined_path = PROOF / f"decoder{number}_combined.elf"
    start = support.START_ADDRESS
    data, section_address, _, _ = link(
        number, object_path, combined_path, start, externals,
        functions(number)[0][0], False,
    )
    assert section_address == start and len(data) == support.SLICE_SIZE
    original = support.ORIGINAL.read_bytes()
    assert support.original_load_mapping(original)[0] + start - support.original_load_mapping(original)[1] == support.FILE_OFFSET
    expected_slice = original[support.FILE_OFFSET:support.FILE_OFFSET + support.SLICE_SIZE]
    assert len(expected_slice) == support.SLICE_SIZE
    for name, address, size in functions(number):
        offset = address - start
        if name in NEAR:
            check_near(name, data[offset:offset + size], expected_slice[offset:offset + size], externals)
    for name, address, size in functions(number):
        offset = address - start
        expected = expected_slice[offset:offset + size]
        compare_code(name, data[offset:offset + size], expected, externals)
    pads = [
        (0x14C, 4), (0x2FC, 4), (0x4F4, 12), (0x788, 8),
    ] if number == 28 else [
        (0x1AC, 4), (0x5F8, 8), (0x8DC, 4),
    ] if number == 29 else [
        (0x434, 12), (0x6CC, 4),
    ] if number == 30 else [(0x5B4, 12), (0x90C, 4)]
    for offset, size in pads:
        assert data[offset:offset + size] == expected_slice[offset:offset + size]
        assert expected_slice[offset:offset + size] == bytes(size)
    isolated = 0
    for name, address, size in functions(number):
        output = PROOF / f"{name}_isolated.elf"
        linked, sec_address, symbol_address, symbol_size = link(
            number, object_path, output, address, externals, name, True,
        )
        assert sec_address == symbol_address == address and symbol_size == size
        code = linked[symbol_address - sec_address:symbol_address - sec_address + size]
        offset = address - start
        compare_code(name, code, expected_slice[offset:offset + size], externals)
        isolated += 1
    return len(functions(number)), isolated


def prove_all(external_override=None):
    require_root()
    total = isolated = 0
    for number in range(28, 32):
        unit_total, unit_isolated = prove_unit(number, external_override)
        total += unit_total
        isolated += unit_isolated
    assert (total, isolated) == (16, 16)
    print(f"PROVED 4 Ninja ET_REL objects, 4 combined ET_EXEC, {isolated} isolated ET_EXEC")
