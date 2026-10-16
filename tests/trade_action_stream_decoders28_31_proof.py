"""Portable configure, Ninja-object, linked-byte, symbol, and address proofs."""

import importlib.util
from pathlib import Path
import re
import subprocess
import sys

from elftools.elf.elffile import ELFFile

ROOT = None
LINKER = None
PROOF = None
SUPPORTS = {}
NEAR = {"func_001658C0": 496, "func_00166100": 580,
        "func_00166A70": 648, "func_001675E0": 840}
EXPECTED_GP = 0x4EA7C0
EXPECTED_TARGET = 0x4E2DA0


def require_root(root=None):
    global ROOT, LINKER, PROOF, SUPPORTS
    selected = Path(root or Path.cwd()).resolve()
    assert Path.cwd().resolve() == selected, "proof ROOT must be the current working directory"
    assert (selected / "configure.py").is_file() and (selected / "config/SLES-50282/config.yml").is_file()
    if root is None:
        git_dir = subprocess.run(["git", "-C", str(selected), "rev-parse", "--git-dir"],
                                 cwd=selected, text=True, capture_output=True, check=True).stdout.strip()
        common_dir = subprocess.run(["git", "-C", str(selected), "rev-parse", "--git-common-dir"],
                                    cwd=selected, text=True, capture_output=True, check=True).stdout.strip()
        assert (selected / git_dir).resolve() != (selected / common_dir).resolve(), "default ROOT must be a worktree"
    ROOT, LINKER, PROOF = selected, selected / "build/mips_binutils/mips-linux-gnu-ld", selected / "build/advisor-decoders28-31-proof"
    SUPPORTS = {number: load_support(number) for number in range(28, 32)}
    assert LINKER.is_file(), f"missing linker {LINKER}"
    return ROOT


def load_support(number):
    name = f"trade_action_stream_decoders{number}_support"
    path = ROOT / "tests" / f"{name}.py"
    spec = importlib.util.spec_from_file_location(name, path)
    assert spec is not None and spec.loader is not None, f"cannot load {path}"
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def run(command):
    assert ROOT is not None and Path.cwd().resolve() == ROOT, "commands must run from validated ROOT"
    subprocess.run([str(item) for item in command], cwd=ROOT, check=True)


def prepare_build():
    require_root(ROOT)
    run([sys.executable, ROOT / "configure.py", "--version", "SLES-50282",
         "--compilers", ROOT / "compilers"])
    targets = [f"build/SLES-50282/src/trade_action_stream_decoders{n}.o" for n in range(28, 32)]
    run(["ninja", "-t", "clean", *targets])
    for target in targets:
        run(["ninja", "-v", target])
    check_configuration()


def functions(number):
    return SUPPORTS[number].FUNCTIONS


def check_configuration():
    config = (ROOT / "config/SLES-50282/config.yml").read_text(encoding="utf-8")
    symbols_file = (ROOT / "config/SLES-50282/symbols.txt").read_text(encoding="utf-8")
    configure = (ROOT / "configure.py").read_text(encoding="utf-8")
    for number, support in SUPPORTS.items():
        name = f"trade_action_stream_decoders{number}"
        segment = (f"  - name: {name}\n    type: code\n    start: 0x{support.FILE_OFFSET:X}\n"
                   f"    vram: 0x{support.START_ADDRESS:X}\n    subsegments:\n"
                   f"      - [0x{support.FILE_OFFSET:X}, asm, {name}]\n")
        assert config.count(segment) == 1, f"{name}: configuration segment must occur exactly once"
        assert len(re.findall(rf'Object\(\s*NonMatching,\s*"{name}",', configure)) == 1, name
        for function, address, size in functions(number):
            declaration = f"{function} = 0x{address:X}; // type:func size:0x{size:X} absolute:True"
            assert symbols_file.splitlines().count(declaration) == 1, function
    assert "    start: 0x67EF0\n" in config, "post_base boundary mismatch"
    assert EXPECTED_GP == SUPPORTS[28].EXTERNAL_SYMBOLS["_gp"]
    assert EXPECTED_TARGET == SUPPORTS[28].EXTERNAL_SYMBOLS["D_004E2DA0"]


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
        assert undefined == set(SUPPORTS[number].EXTERNAL_SYMBOLS) - {"_gp"}
    return path


def linker_script(path, address, externals):
    assignments = "".join(f"{name} = {value:#x};\n" for name, value in externals.items())
    path.write_text(assignments + "SECTIONS {\n" + f"  .text {address:#x} : {{ *(.text) . = ALIGN(16); }}\n"
                    + "  /DISCARD/ : { *(*) }\n}\n", encoding="utf-8")


def link(number, object_path, output, address, entry, garbage_collect):
    script = output.with_suffix(".ld")
    linker_script(script, address, SUPPORTS[number].EXTERNAL_SYMBOLS)
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


def check_near(name, actual, expected):
    assert len(actual) == len(expected)
    original_base_word = int.from_bytes(expected[0x0C:0x10], "little")
    original_store = int.from_bytes(expected[0x14:0x18], "little")
    emitted_store = int.from_bytes(actual[0x14:0x18], "little")
    assert original_base_word >> 26 == 0x09, f"{name}: original base op must be ADDIU"
    assert ((original_base_word >> 21) & 31, (original_base_word >> 16) & 31) == (28, 3), name
    assert (original_store >> 26, emitted_store >> 26) == (0x28, 0x28), name
    assert ((original_store >> 16) & 31, (emitted_store >> 16) & 31) == (2, 2), name
    original_base = EXPECTED_GP + sign16(original_base_word & 0xFFFF)
    original_target = original_base + sign16(original_store & 0xFFFF)
    emitted_base_register = (emitted_store >> 21) & 31
    assert emitted_base_register in (3, 28), (name, emitted_base_register)
    emitted_base_word = int.from_bytes(actual[0x0C:0x10], "little")
    if emitted_base_register == 3:
        assert emitted_base_word >> 26 == 0x09, f"{name}: emitted base op must be ADDIU"
        assert ((emitted_base_word >> 21) & 31, (emitted_base_word >> 16) & 31) == (28, 3), name
        emitted_base = EXPECTED_GP + sign16(emitted_base_word & 0xFFFF)
    else:
        emitted_base = EXPECTED_GP
    emitted_target = emitted_base + sign16(emitted_store & 0xFFFF)
    assert original_target == emitted_target == EXPECTED_TARGET, (
        f"{name}: original/effective/expected {original_target:#x}/{emitted_target:#x}/{EXPECTED_TARGET:#x}"
    )
    assert (original_store, emitted_store) == (0xA0620000, 0xA38285E0), (name, hex(original_store), hex(emitted_store))
    assert ((original_store >> 21) & 31, emitted_base_register) == (3, 28), name


def compare_code(name, actual, expected):
    if name in NEAR:
        check_near(name, actual, expected)
        differences = [index for index, pair in enumerate(zip(actual, expected)) if pair[0] != pair[1]]
        assert len(actual) - len(differences) == NEAR[name], (name, differences)
        assert differences == list(range(0x14, 0x18)), (name, differences)
    else:
        assert actual == expected, f"raw linked bytes differ for {name}"


def prove_unit(number):
    support = SUPPORTS[number]
    object_path = check_object(number)
    PROOF.mkdir(parents=True, exist_ok=True)
    start = support.START_ADDRESS
    data, section_address, _, _ = link(number, object_path, PROOF / f"decoder{number}_combined.elf",
                                       start, functions(number)[0][0], False)
    assert section_address == start and len(data) == support.SLICE_SIZE
    original = support.ORIGINAL.read_bytes()
    mapping = support.original_load_mapping(original)
    assert mapping[0] + start - mapping[1] == support.FILE_OFFSET
    expected_slice = original[support.FILE_OFFSET:support.FILE_OFFSET + support.SLICE_SIZE]
    assert len(expected_slice) == support.SLICE_SIZE
    for name, address, size in functions(number):
        offset = address - start
        if name in NEAR:
            check_near(name, data[offset:offset + size], expected_slice[offset:offset + size])
    for name, address, size in functions(number):
        offset = address - start
        compare_code(name, data[offset:offset + size], expected_slice[offset:offset + size])
    pads = {28: [(0x14C, 4), (0x2FC, 4), (0x4F4, 12), (0x788, 8)],
            29: [(0x1AC, 4), (0x5F8, 8), (0x8DC, 4)],
            30: [(0x434, 12), (0x6CC, 4)], 31: [(0x5B4, 12), (0x90C, 4)]}[number]
    for offset, size in pads:
        assert data[offset:offset + size] == expected_slice[offset:offset + size] == bytes(size)
    for name, address, size in functions(number):
        linked, section_address, symbol_address, symbol_size = link(
            number, object_path, PROOF / f"{name}_isolated.elf", address, name, True)
        assert section_address == symbol_address == address and symbol_size == size
        offset = address - start
        compare_code(name, linked[symbol_address - section_address:symbol_address - section_address + size],
                     expected_slice[offset:offset + size])
    return len(functions(number))


def prove_all():
    require_root(ROOT)
    total = sum(prove_unit(number) for number in range(28, 32))
    assert total == 16
    print("PROVED 4 Ninja ET_REL objects, 4 combined ET_EXEC, 16 isolated ET_EXEC")
