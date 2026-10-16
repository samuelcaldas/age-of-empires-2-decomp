"""Check ELF objects, raw bytes, symbols, links, padding, and effective addresses."""

import importlib.util
from pathlib import Path

from elftools.elf.elffile import ELFFile


def load_environment():
    path = Path(__file__).resolve().with_name("trade_action_stream_decoders28_31_environment.py")
    spec = importlib.util.spec_from_file_location("decoder28_31_environment", path)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


ENV = load_environment()
ROOT = LINKER = PROOF = None
NEAR = {"func_001658C0": 496, "func_00166100": 580, "func_00166A70": 648, "func_001675E0": 840}


def require_root(root=None):
    global ROOT, LINKER, PROOF
    ROOT = ENV.require_root(root)
    LINKER, PROOF = ENV.LINKER, ENV.PROOF
    return ROOT


def prepare_build():
    require_root(ROOT)
    ENV.prepare_build()


def run(command):
    ENV.run(command)


def functions(number):
    return ENV.functions(number)


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
        table, found = symbols(elf, [entry[0] for entry in functions(number)])
        indices = set()
        for name, _, size in functions(number):
            symbol = found[name]
            index = symbol["st_shndx"]
            assert isinstance(index, int) and index > 0, (name, index)
            assert symbol["st_info"]["type"] == "STT_FUNC" and symbol["st_size"] == size
            section = elf.get_section(index)
            assert section.name == ".text" and section["sh_size"] == size
            indices.add(index)
        assert len(indices) == 4, f"{number}: expected four distinct .text st_shndx"
        undefined = {entry.name for entry in table.iter_symbols()
                     if entry.name and entry["st_shndx"] == "SHN_UNDEF"}
        assert undefined == set(ENV.SUPPORTS[number].EXTERNAL_SYMBOLS) - {"_gp"}
    return path


def linker_script(path, address, externals):
    assignments = "".join(f"{name} = {value:#x};\n" for name, value in externals.items())
    script = assignments + "SECTIONS {\n" + f"  .text {address:#x} : {{ *(.text) . = ALIGN(16); }}\n"
    path.write_text(script + "  /DISCARD/ : { *(*) }\n}\n", encoding="utf-8")


def link(number, object_path, output, address, entry, garbage_collect):
    script = output.with_suffix(".ld")
    linker_script(script, address, ENV.SUPPORTS[number].EXTERNAL_SYMBOLS)
    command = [LINKER, "-EL", "-m", "elf32ltsmip", "--no-undefined"]
    if garbage_collect:
        command.append("--gc-sections")
    command.extend(["-e", entry, "-T", script, "-o", output, object_path])
    run(command)
    with output.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf.header["e_type"] == "ET_EXEC"
        table = elf.get_section_by_name(".symtab")
        undefined = [entry.name for entry in table.iter_symbols()
                     if entry.name and entry["st_shndx"] == "SHN_UNDEF"]
        assert not undefined, (number, entry, undefined)
        section = elf.get_section_by_name(".text")
        assert section is not None and section["sh_addr"] == address
        _, found = symbols(elf, [entry])
        symbol = found[entry]
        assert symbol["st_info"]["type"] == "STT_FUNC"
        return section.data(), section["sh_addr"], symbol["st_value"], symbol["st_size"]


def sign16(value):
    return value - 0x10000 if value & 0x8000 else value


def check_near(name, actual, expected):
    assert len(actual) == len(expected)
    original_base = int.from_bytes(expected[0x0C:0x10], "little")
    original_store = int.from_bytes(expected[0x14:0x18], "little")
    emitted_store = int.from_bytes(actual[0x14:0x18], "little")
    assert original_base >> 26 == 0x09, f"{name}: original base op must be ADDIU"
    assert ((original_base >> 21) & 31, (original_base >> 16) & 31) == (28, 3), name
    assert (original_store >> 26, emitted_store >> 26) == (0x28, 0x28), name
    assert ((original_store >> 16) & 31, (emitted_store >> 16) & 31) == (2, 2), name
    original_address = ENV.EXPECTED_GP + sign16(original_base & 0xFFFF)
    original_target = original_address + sign16(original_store & 0xFFFF)
    emitted_register = (emitted_store >> 21) & 31
    assert emitted_register in (3, 28), (name, emitted_register)
    emitted_base = int.from_bytes(actual[0x0C:0x10], "little")
    effective_address = _effective_base(name, emitted_register, emitted_base)
    emitted_target = effective_address + sign16(emitted_store & 0xFFFF)
    expected = ENV.EXPECTED_TARGET
    assert original_target == emitted_target == expected, (
        f"{name}: original/effective/expected {original_target:#x}/{emitted_target:#x}/{expected:#x}"
    )
    assert (original_store, emitted_store) == (0xA0620000, 0xA38285E0), (
        name, hex(original_store), hex(emitted_store))
    assert ((original_store >> 21) & 31, emitted_register) == (3, 28), name


def _effective_base(name, register, instruction):
    if register == 28:
        return ENV.EXPECTED_GP
    assert instruction >> 26 == 0x09, f"{name}: emitted base op must be ADDIU"
    assert ((instruction >> 21) & 31, (instruction >> 16) & 31) == (28, 3), name
    return ENV.EXPECTED_GP + sign16(instruction & 0xFFFF)


def compare_code(name, actual, expected):
    if name not in NEAR:
        assert actual == expected, f"raw linked bytes differ for {name}"
        return
    check_near(name, actual, expected)
    differences = [index for index, pair in enumerate(zip(actual, expected)) if pair[0] != pair[1]]
    assert len(actual) - len(differences) == NEAR[name], (name, differences)
    assert differences == list(range(0x14, 0x18)), (name, differences)


def prove_unit(number):
    support = ENV.SUPPORTS[number]
    object_path = check_object(number)
    PROOF.mkdir(parents=True, exist_ok=True)
    start = support.START_ADDRESS
    data, base, _, _ = link(number, object_path, PROOF / f"decoder{number}_combined.elf",
                            start, functions(number)[0][0], False)
    assert base == start and len(data) == support.SLICE_SIZE
    original = support.ORIGINAL.read_bytes()
    mapping = support.original_load_mapping(original)
    assert mapping[0] + start - mapping[1] == support.FILE_OFFSET
    expected = original[support.FILE_OFFSET:support.FILE_OFFSET + support.SLICE_SIZE]
    assert len(expected) == support.SLICE_SIZE
    for name, address, size in functions(number):
        offset = address - start
        if name in NEAR:
            check_near(name, data[offset:offset + size], expected[offset:offset + size])
    for name, address, size in functions(number):
        offset = address - start
        compare_code(name, data[offset:offset + size], expected[offset:offset + size])
    _check_padding(number, data, expected)
    _check_isolated(number, object_path, start, expected)
    return len(functions(number))


def _check_padding(number, data, expected):
    pads = {28: [(0x14C, 4), (0x2FC, 4), (0x4F4, 12), (0x788, 8)],
            29: [(0x1AC, 4), (0x5F8, 8), (0x8DC, 4)],
            30: [(0x434, 12), (0x6CC, 4)], 31: [(0x5B4, 12), (0x90C, 4)]}[number]
    for offset, size in pads:
        assert data[offset:offset + size] == expected[offset:offset + size] == bytes(size)


def _check_isolated(number, object_path, start, expected):
    for name, address, size in functions(number):
        linked, section, symbol, extent = link(
            number, object_path, PROOF / f"{name}_isolated.elf", address, name, True)
        assert section == symbol == address and extent == size
        offset = address - start
        code = linked[symbol - section:symbol - section + size]
        compare_code(name, code, expected[offset:offset + size])


def prove_all():
    require_root(ROOT)
    assert sum(prove_unit(number) for number in range(28, 32)) == 16
    print("PROVED 4 Ninja ET_REL objects, 4 combined ET_EXEC, 16 isolated ET_EXEC")
