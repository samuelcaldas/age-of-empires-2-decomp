"""Verify the registered 2184D0 object, its BREAK, and a no-undefined link."""

import argparse
import importlib.util
from pathlib import Path
import subprocess
import tempfile

from elftools.elf.elffile import ELFFile


def load_elf_proof():
    """Load the adjacent ELF checks without relying on sys.path."""
    module_path = Path(__file__).resolve().with_name(
        "verify_trade_action_helper_2184D0_elf.py"
    )
    spec = importlib.util.spec_from_file_location("trade_action_helper_2184D0_elf", module_path)
    if spec is None or spec.loader is None:
        raise ImportError(f"cannot load ELF proof module from {module_path}")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


elf_proof = load_elf_proof()
START = elf_proof.START
FUNCTION_SIZE = elf_proof.FUNCTION_SIZE
SLICE_SIZE = elf_proof.SLICE_SIZE
FUNCTION = elf_proof.FUNCTION
EXTERNALS = elf_proof.EXTERNALS
GP = 0x4EA7C0


def link_candidate(linker, candidate, directory, text_indices, main_index):
    """Link every real text section while placing the entry at its original VRAM."""
    script = directory / "candidate.ld"
    definitions = "".join(f"{name} = {address:#x};\n"
                          for name, address in EXTERNALS.items())
    definitions += f"_gp = {GP:#x};\n"
    private_sections = " ".join(
        f"*(.text_{index})" for index in text_indices if index != main_index
    )
    script.write_text(
        definitions + f"SECTIONS {{ .entry {START:#x} : {{ *(.text_{main_index}) }} "
        f".private 0x219000 : {{ {private_sections} }} "
        "/DISCARD/ : { *(*) } }\n"
    )
    output = directory / "candidate.elf"
    subprocess.run([str(linker), "-EL", "-m", "elf32ltsmip", "--no-undefined",
                    "-T", str(script), "-o", str(output), str(candidate)], check=True)
    return output


def inspect_link(path, original, private_bytes):
    """Verify final symbols and report complete unmasked extent metrics."""
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        elf_proof.require(elf.header["e_type"] == "ET_EXEC", "output is not ET_EXEC")
        table = elf.get_section_by_name(".symtab")
        elf_proof.require(not [symbol.name for symbol in table.iter_symbols()
                               if symbol.name and symbol["st_shndx"] == "SHN_UNDEF"],
                          "linked output has unresolved symbols")
        function = elf_proof.unique_symbol(table, FUNCTION)
        elf_proof.require(function["st_value"] == START, "entry is not at original address")
        entry_section = elf.get_section(function["st_shndx"])
        generated = entry_section.data()[:function["st_size"]]
        private = elf.get_section_by_name(".private")
        elf_proof.require(private is not None and private["sh_size"] >= private_bytes,
                          "private helper sections were cropped")
        linked_private_bytes = private["sh_size"]
    overlap = min(len(generated), len(original))
    equal = sum(left == right for left, right in zip(generated[:overlap], original[:overlap]))
    different = overlap - equal
    missing = len(original) - overlap
    extra = max(0, len(generated) - len(original))
    code_overlap = min(len(generated), FUNCTION_SIZE)
    code_equal = sum(left == right for left, right in
                     zip(generated[:code_overlap], original[:code_overlap]))
    code_different = code_overlap - code_equal
    code_missing = FUNCTION_SIZE - code_overlap
    code_extra = max(0, len(generated) - FUNCTION_SIZE)
    padding = generated[FUNCTION_SIZE:SLICE_SIZE]
    padding_equal = sum(byte == 0 for byte in padding)
    padding_different = len(padding) - padding_equal
    padding_missing = 8 - len(padding)
    padding_extra = max(0, len(padding) - 8)
    print(f"ET_EXEC: {FUNCTION}={START:#x}, size={len(generated)}, unresolved=0, _gp={GP:#x}")
    print(f"Raw unmasked 848-byte slice: equal={equal}, different={different}, "
          f"missing={missing}, extra={extra}; overlap={overlap}")
    print(f"Original 840-byte code range: equal={code_equal}, different={code_different}, "
          f"missing={code_missing}, extra={code_extra}")
    print(f"Original 8-byte tail padding: equal={padding_equal}, "
          f"different={padding_different}, missing={padding_missing}, extra={padding_extra}")
    print(f"Linked entry bytes={len(generated)}, retained private .text bytes={private_bytes}, "
          f"linked private extent={linked_private_bytes} "
          f"(alignment padding={linked_private_bytes - private_bytes}); "
          f"full linked code extent={linked_private_bytes + len(generated)}")


def main():
    """Run source-object, original-slice, and GNU final-link checks."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--object", type=Path,
                        default=Path("build/SLES-50282/src/trade/trade_action_helper_2184D0.o"))
    parser.add_argument("--original", type=Path, default=Path("orig/SLES-50282/AOK.ELF"))
    parser.add_argument("--linker", type=Path,
                        default=Path("build/mips_binutils/mips-linux-gnu-ld"))
    arguments = parser.parse_args()
    for path in (arguments.object, arguments.original, arguments.linker):
        elf_proof.require(path.is_file(), f"missing input {path}")
    original = elf_proof.original_slice(arguments.original)
    with tempfile.TemporaryDirectory(prefix="trade-action-helper-2184D0-") as temporary:
        directory = Path(temporary)
        candidate = directory / "candidate.o"
        indices = elf_proof.rename_text_sections(arguments.object, candidate)
        main_index, text_indices, private_bytes, external_count = elf_proof.inspect_object(
            arguments.object
        )
        elf_proof.require(indices == text_indices, "section-index mapping changed")
        linked = link_candidate(arguments.linker.resolve(), candidate, directory,
                                text_indices, main_index)
        inspect_link(linked, original, private_bytes)
    print(f"ET_REL .text sections={len(indices)}, private bytes={private_bytes}, "
          f"real external symbols={external_count}; BREAK7 verified through grid_count st_shndx")


if __name__ == "__main__":
    try:
        main()
    except (OSError, RuntimeError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"BLOCKER: {error}") from error
