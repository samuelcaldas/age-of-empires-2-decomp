"""Prove decoder44–51 Ninja objects against the immutable PAL ELF."""

import hashlib
import importlib.util
from pathlib import Path

from elftools.elf.elffile import ELFFile


def load_environment():
    path = Path(__file__).resolve().with_name("trade_action_stream_decoders44_51_environment.py")
    spec = importlib.util.spec_from_file_location("decoder44_51_environment", path)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


ENV = load_environment()
ROOT = LINKER = PROOF = None


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


def get_symbols(elf, names):
    table = elf.get_section_by_name(".symtab")
    assert table is not None, "missing .symtab"
    result = {}
    for name in names:
        matches = table.get_symbol_by_name(name)
        assert matches and len(matches) == 1, f"expected one symbol {name}"
        result[name] = matches[0]
    return table, result


def check_object(number):
    path = ROOT / f"build/SLES-50282/src/trade_action_stream_decoders{number}.o"
    assert path.is_file(), f"missing Ninja object {path}"
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf.header["e_type"] == "ET_REL"
        table, found = get_symbols(elf, [entry[0] for entry in functions(number)])
        section_indices = set()
        for name, _, size in functions(number):
            symbol = found[name]
            index = symbol["st_shndx"]
            assert isinstance(index, int) and index > 0
            assert symbol["st_info"]["type"] == "STT_FUNC" and symbol["st_size"] == size
            section = elf.get_section(index)
            assert section.name == ".text" and section["sh_size"] == size
            section_indices.add(index)
        executable = {section.name for section in elf.iter_sections()
                      if section["sh_flags"] & 0x4 and section["sh_size"]}
        assert executable == {".text"}, (number, executable)
        assert len(section_indices) == 4, f"{number}: functions need unique .text sections"
        undefined = {item.name for item in table.iter_symbols()
                     if item.name and item["st_shndx"] == "SHN_UNDEF"}
        expected = set(ENV.SUPPORTS[number].EXTERNAL_SYMBOLS) - {"_gp"}
        assert undefined == expected, (undefined, expected)
    return path


def link(number, object_path, output, address, entry, isolated):
    support = ENV.SUPPORTS[number]
    script = output.with_suffix(".ld")
    assignments = "".join(
        f"{name} = {value:#x};\n"
        for name, value in support.EXTERNAL_SYMBOLS.items()
    )
    script.write_text(assignments + "SECTIONS {\n"
                      + f" .text {address:#x} : {{ *(.text) . = ALIGN(16); }}\n"
                      + " /DISCARD/ : { *(*) }\n}\n")
    command = [LINKER, "-EL", "-m", "elf32ltsmip", "--no-undefined"]
    if isolated:
        command.append("--gc-sections")
    command.extend(["-e", entry, "-T", script, "-o", output, object_path])
    run(command)
    with output.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf.header["e_type"] == "ET_EXEC"
        table = elf.get_section_by_name(".symtab")
        unresolved = [item.name for item in table.iter_symbols()
                      if item.name and item["st_shndx"] == "SHN_UNDEF"]
        assert not unresolved, (number, unresolved)
        for name, expected_address in support.EXTERNAL_SYMBOLS.items():
            matches = table.get_symbol_by_name(name)
            assert matches and len(matches) == 1, name
            assert matches[0]["st_value"] == expected_address, (name, matches[0]["st_value"])
        section = elf.get_section_by_name(".text")
        assert section is not None and section["sh_addr"] == address
        executable = {item.name for item in elf.iter_sections()
                      if item["sh_flags"] & 0x4 and item["sh_size"]}
        assert executable == {".text"}, (number, executable)
        _, symbols = get_symbols(elf, [entry])
        symbol = symbols[entry]
        assert symbol["st_info"]["type"] == "STT_FUNC"
        return section.data(), section["sh_addr"], symbol["st_value"], symbol["st_size"]


def prove_unit(number):
    support = ENV.SUPPORTS[number]
    object_path = check_object(number)
    PROOF.mkdir(parents=True, exist_ok=True)
    base = support.START_ADDRESS
    actual, section_address, _, _ = link(
        number, object_path, PROOF / f"decoder{number}_combined.elf",
        base, functions(number)[0][0], False)
    assert section_address == base and len(actual) == support.SLICE_SIZE
    original = support.ORIGINAL.read_bytes()
    assert hashlib.sha1(original).hexdigest() == support.ORIGINAL_SHA1, "original ELF SHA-1 mismatch"
    mapping = support.original_load_mapping(original)
    assert mapping[0] + base - mapping[1] == support.FILE_OFFSET
    expected = original[support.FILE_OFFSET:support.FILE_OFFSET + support.SLICE_SIZE]
    assert len(expected) == support.SLICE_SIZE
    spans = [(address - base, size, name) for name, address, size in functions(number)]
    spans.extend(_padding_spans(support))
    code_bytes = sum(size for _, _, size in functions(number))
    _check_slice_coverage(number, spans, support.SLICE_SIZE)
    for name, address, size in functions(number):
        offset = address - base
        assert actual[offset:offset + size] == expected[offset:offset + size], name
    _check_padding(support, actual, expected)
    _check_isolated(number, object_path, base, expected)
    print(f"UNIT {number}: {code_bytes}/{support.SLICE_SIZE} code/padding bytes exact")
    return len(functions(number))


def _padding_spans(support):
    spans = []
    for index in range(1, 5):
        offset = getattr(support, f"PAD{index}_OFFSET", None)
        size = getattr(support, f"PAD{index}_SIZE", None)
        if offset is not None and size is not None:
            spans.append((offset, size, None))
    return spans


def _check_slice_coverage(number, spans, slice_size):
    cursor = 0
    for offset, size, _ in sorted(spans):
        assert offset == cursor, (number, "uncovered/overlapping slice bytes", cursor, offset)
        cursor += size
    assert cursor == slice_size, (number, "slice extent", cursor, slice_size)


def _check_padding(support, actual, expected):
    for offset, size, _ in _padding_spans(support):
        assert actual[offset:offset + size] == expected[offset:offset + size]
        assert actual[offset:offset + size] == bytes(size), (offset, size)


def _check_isolated(number, object_path, base, expected):
    for name, address, size in functions(number):
        linked, section, symbol, extent = link(
            number, object_path, PROOF / f"{name}_isolated.elf", address, name, True)
        assert section == symbol == address and extent == size
        assert size <= len(linked) <= size + 15, (name, len(linked), size)
        assert linked[size:] == bytes(len(linked) - size), (name, "unexpected executable tail")
        offset = address - base
        assert linked[symbol - section:symbol - section + size] == expected[offset:offset + size], name


def prove_all():
    require_root(ROOT)
    assert sum(prove_unit(number) for number in range(44, 52)) == 32
    print("PROVED 8 Ninja ET_REL, 8 combined and 32 isolated no-undefined ET_EXEC links")
