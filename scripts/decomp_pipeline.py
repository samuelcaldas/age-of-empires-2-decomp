"""Iterative decompilation, staging, compilation, diffing and registration pipeline.

Provides programmatic and idempotent actions for:
1. Extracting/staging disassembly and initial C scaffolds from ELF.
2. Compiling staging drafts using MWCC PS2.
3. Diffing compiled drafts against the original binary using objdiff-cli and binary slices.
4. Promoting 100% matched functions into project structure (config.yml, symbols.txt,
   configure.py, include/, src/ and tests/).
"""

from __future__ import annotations

import argparse
from pathlib import Path
import shutil
import struct
import subprocess
import sys
from typing import Dict, List, Optional, Tuple

from elftools.elf.elffile import ELFFile

PROJECT_ROOT = Path(__file__).resolve().parents[1]
STAGING_DIR = PROJECT_ROOT / "staging"
ORIGINAL_ELF = PROJECT_ROOT / "orig/SLES-50282/AOK.ELF"
COMPILER_PATH = PROJECT_ROOT / "compilers/PS2/mwcc-2.3.1.01/mwccps2.exe"
WIBO_PATH = PROJECT_ROOT / "build/tools/wibo"
OBJDIFF_PATH = PROJECT_ROOT / "build/tools/objdiff-cli"
CONFIG_YML = PROJECT_ROOT / "config/SLES-50282/config.yml"
SYMBOLS_TXT = PROJECT_ROOT / "config/SLES-50282/symbols.txt"
CONFIGURE_PY = PROJECT_ROOT / "configure.py"


def get_original_bytes(vram: int, size: int) -> bytes:
    """Read bytes from the original SLES-50282 ELF based on VRAM address."""
    if not ORIGINAL_ELF.is_file():
        raise FileNotFoundError(f"Original ELF not found at {ORIGINAL_ELF}")
    with ORIGINAL_ELF.open("rb") as f:
        elf = ELFFile(f)
        for seg in elf.iter_segments():
            if seg["p_type"] == "PT_LOAD":
                start = seg["p_vaddr"]
                end = start + seg["p_filesz"]
                if start <= vram < end:
                    offset = seg["p_offset"] + (vram - start)
                    f.seek(offset)
                    return f.read(size)
    raise ValueError(f"Address 0x{vram:X} not found in PT_LOAD segments")


def stage_function(func_name: str, vram: int, size: int) -> Path:
    """Create a staging directory and initial C++ draft scaffold for a function.

    Idempotent: if staging file already exists, it is preserved.
    """
    STAGING_DIR.mkdir(parents=True, exist_ok=True)
    target_file = STAGING_DIR / f"{func_name}.cpp"
    if not target_file.exists():
        scaffold = f"""#pragma exceptions off
#include <stddef.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

extern "C" {{

// Target: {func_name} (0x{vram:08X}, size: 0x{size:X})
void {func_name}(void) {{
    // TODO: implement matching C logic
}}

}}
"""
        target_file.write_text(scaffold)
    return target_file


def compile_draft(source_path: Path, output_obj: Optional[Path] = None, cflags: Optional[List[str]] = None) -> Tuple[bool, str, Path]:
    """Compile a staging C++ file using MWCC PS2 via wibo."""
    if output_obj is None:
        output_obj = source_path.with_suffix(".o")

    if not COMPILER_PATH.is_file() or not WIBO_PATH.is_file():
        return False, f"Missing toolchain: {COMPILER_PATH} or {WIBO_PATH}", output_obj

    if cflags is None:
        cflags = [
            "-O3", "-inline", "on", "-msext", "on",
            "-char", "signed", "-sym", "off",
            "-Iinclude", "-lang=c++"
        ]

    cmd = [str(WIBO_PATH), str(COMPILER_PATH)] + cflags + ["-c", str(source_path), "-o", str(output_obj)]
    res = subprocess.run(cmd, cwd=PROJECT_ROOT, capture_output=True, text=True)
    success = (res.returncode == 0) and output_obj.is_file()
    output_msg = res.stdout + ("\n" + res.stderr if res.stderr else "")
    return success, output_msg, output_obj


def extract_compiled_symbol_bytes(obj_path: Path, symbol_name: str) -> Tuple[bytes, List[dict]]:
    """Extract symbol bytes and relocation info from a compiled ELF object."""
    with obj_path.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        if not symtab:
            raise ValueError(f"No .symtab found in {obj_path}")

        matches = symtab.get_symbol_by_name(symbol_name)
        if not matches:
            # Fallback: check stripped or mangled
            all_syms = [s.name for s in symtab.iter_symbols() if s.name]
            raise ValueError(f"Symbol {symbol_name} not found in {obj_path}. Available: {all_syms}")
        sym = matches[0]
        sec_idx = sym["st_shndx"]
        sec = elf.get_section(sec_idx)
        data = sec.data()
        sym_offset = sym["st_value"]
        sym_size = sym["st_size"]
        raw_bytes = data[sym_offset:sym_offset + sym_size]

        rel_sec = elf.get_section_by_name(f".rela{sec.name}") or elf.get_section_by_name(f".rel{sec.name}")
        relocs = []
        if rel_sec:
            for rel in rel_sec.iter_relocations():
                r_offset = rel["r_offset"]
                if sym_offset <= r_offset < sym_offset + sym_size:
                    rel_sym = symtab.get_symbol(rel["r_info_sym"])
                    relocs.append({
                        "offset": r_offset - sym_offset,
                        "type": rel["r_info_type"],
                        "symbol": rel_sym.name if rel_sym else ""
                    })
        return raw_bytes, relocs


def diff_draft(func_name: str, vram: int, size: int, obj_path: Path, known_symbols: Optional[Dict[str, int]] = None) -> dict:
    """Compare compiled symbol against original bytes, taking relocations into account."""
    orig_bytes = get_original_bytes(vram, size)
    raw_bytes, relocs = extract_compiled_symbol_bytes(obj_path, func_name)

    actual_size = len(raw_bytes)
    size_match = (actual_size == size)

    # Relocation-patched matching check
    patched_bytes = bytearray(raw_bytes)
    if known_symbols:
        for rel in relocs:
            sym_name = rel["symbol"]
            target_addr = known_symbols.get(sym_name)
            if target_addr is not None:
                offset = rel["offset"]
                rel_type = rel["type"]
                # MIPS R_MIPS_26 (JAL): (addr >> 2) & 0x3FFFFFF
                if rel_type == 4:  # R_MIPS_26
                    inst = struct.unpack("<I", patched_bytes[offset:offset+4])[0]
                    inst = (inst & 0xFC000000) | ((target_addr >> 2) & 0x03FFFFFF)
                    patched_bytes[offset:offset+4] = struct.pack("<I", inst)
                # MIPS R_MIPS_HI16
                elif rel_type == 5:
                    inst = struct.unpack("<I", patched_bytes[offset:offset+4])[0]
                    hi = ((target_addr + 0x8000) >> 16) & 0xFFFF
                    inst = (inst & 0xFFFF0000) | hi
                    patched_bytes[offset:offset+4] = struct.pack("<I", inst)
                # MIPS R_MIPS_LO16
                elif rel_type == 6:
                    inst = struct.unpack("<I", patched_bytes[offset:offset+4])[0]
                    lo = target_addr & 0xFFFF
                    inst = (inst & 0xFFFF0000) | lo
                    patched_bytes[offset:offset+4] = struct.pack("<I", inst)

    mismatches = []
    min_len = min(len(orig_bytes), len(patched_bytes))
    for i in range(0, min_len, 4):
        chunk_orig = orig_bytes[i:i+4]
        chunk_comp = patched_bytes[i:i+4]
        if chunk_orig != chunk_comp:
            mismatches.append({
                "offset": i,
                "orig": chunk_orig.hex(),
                "compiled": chunk_comp.hex()
            })

    is_match = (size_match and len(mismatches) == 0)
    match_pct = 100.0 if is_match else max(0.0, (1.0 - (len(mismatches) * 4 / max(size, actual_size))) * 100.0)

    return {
        "func_name": func_name,
        "vram": vram,
        "expected_size": size,
        "actual_size": actual_size,
        "size_match": size_match,
        "is_match": is_match,
        "match_percentage": round(match_pct, 2),
        "mismatches": mismatches,
        "relocations": relocs
    }


def promote_to_project(
    func_name: str,
    module_name: str,
    source_cpp: Path,
    header_name: str,
    vram: int,
    file_offset: int,
    size: int
) -> bool:
    """Promote a 100% matched draft to official src/, config.yml and configure.py.

    Idempotent: updates or adds entries without duplicate sections.
    """
    dest_cpp = PROJECT_ROOT / "src" / module_name / f"{source_cpp.name}"
    dest_cpp.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(source_cpp, dest_cpp)

    # 1. Update config.yml
    config_text = CONFIG_YML.read_text()
    obj_unit = f"{module_name}/{source_cpp.stem}"
    if f"- [{hex(file_offset)}, asm, {obj_unit}]" not in config_text and f"- [{hex(file_offset).upper()}, asm, {obj_unit}]" not in config_text:
        # Segment definition
        new_segment = f"""  - name: {source_cpp.stem}
    type: code
    start: {hex(file_offset)}
    vram: {hex(vram)}
    subsegments:
      - [{hex(file_offset)}, asm, {obj_unit}]
"""
        # Append or insert before matching boundary
        config_text += new_segment
        CONFIG_YML.write_text(config_text)

    # 2. Update symbols.txt
    symbols_text = SYMBOLS_TXT.read_text()
    sym_entry = f"{func_name} = 0x{vram:X}; // type:func size:0x{size:X} absolute:True"
    if sym_entry not in symbols_text:
        SYMBOLS_TXT.write_text(symbols_text.rstrip() + f"\n{sym_entry}\n")

    # 3. Update configure.py if not present
    configure_text = CONFIGURE_PY.read_text()
    obj_entry = f'Object(\n                    Matching,\n                    "{obj_unit}",\n                    cflags=config.cflags,\n                    toolchain_version="PS2/mwcc-2.3.1.01",\n                ),'
    if f'"{obj_unit}"' not in configure_text:
        # Insert inside PS2 objects list
        target_marker = 'Object(\n                    Matching,\n                    "kcet/kt_thread_spawn_220c60",'
        if target_marker in configure_text:
            configure_text = configure_text.replace(target_marker, f'{obj_entry}\n                {target_marker}')
            CONFIGURE_PY.write_text(configure_text)

    return True


def main():
    parser = argparse.ArgumentParser(description="Decompilation staging, compile and matching tool.")
    subparsers = parser.add_subparsers(dest="command", required=True)

    # stage
    p_stage = subparsers.add_parser("stage", help="Stage a new function draft in staging/")
    p_stage.add_argument("--func", required=True, help="Function name (e.g. func_00220C60)")
    p_stage.add_argument("--vram", required=True, type=lambda x: int(x, 0), help="VRAM address (e.g. 0x220C60)")
    p_stage.add_argument("--size", required=True, type=lambda x: int(x, 0), help="Function size in bytes")

    # compile
    p_comp = subparsers.add_parser("compile", help="Compile a staging file")
    p_comp.add_argument("--source", required=True, type=Path, help="Path to .cpp file")
    p_comp.add_argument("--output", type=Path, help="Path to output .o file")

    # diff
    p_diff = subparsers.add_parser("diff", help="Diff compiled draft against original ELF")
    p_diff.add_argument("--func", required=True, help="Function name")
    p_diff.add_argument("--vram", required=True, type=lambda x: int(x, 0), help="VRAM address")
    p_diff.add_argument("--size", required=True, type=lambda x: int(x, 0), help="Function size in bytes")
    p_diff.add_argument("--obj", required=True, type=Path, help="Path to compiled .o")

    # promote
    p_promo = subparsers.add_parser("promote", help="Promote 100%% matched draft to codebase")
    p_promo.add_argument("--func", required=True, help="Function name")
    p_promo.add_argument("--module", default="kcet", help="Subdirectory under src/")
    p_promo.add_argument("--source", required=True, type=Path, help="Path to matched .cpp file")
    p_promo.add_argument("--header", required=True, help="Header filename")
    p_promo.add_argument("--vram", required=True, type=lambda x: int(x, 0), help="VRAM address")
    p_promo.add_argument("--offset", required=True, type=lambda x: int(x, 0), help="Original ELF file offset")
    p_promo.add_argument("--size", required=True, type=lambda x: int(x, 0), help="Function size in bytes")

    args = parser.parse_args()

    if args.command == "stage":
        target = stage_function(args.func, args.vram, args.size)
        print(f"Staged function {args.func} at {target}")

    elif args.command == "compile":
        ok, msg, out_obj = compile_draft(args.source, args.output)
        print(f"Compiled: {'SUCCESS' if ok else 'FAILED'}")
        if msg.strip():
            print(msg.strip())
        sys.exit(0 if ok else 1)

    elif args.command == "diff":
        res = diff_draft(args.func, args.vram, args.size, args.obj)
        print(f"Match: {res['is_match']} ({res['match_percentage']}%)")
        if not res["is_match"]:
            print(f"Mismatches: {len(res['mismatches'])}")
            for m in res["mismatches"][:5]:
                print(f"  +0x{m['offset']:02X}: orig={m['orig']} compiled={m['compiled']}")
        sys.exit(0 if res["is_match"] else 1)

    elif args.command == "promote":
        promote_to_project(args.func, args.module, args.source, args.header, args.vram, args.offset, args.size)
        print(f"Promoted {args.func} to src/{args.module}/{args.source.name}")


if __name__ == "__main__":
    main()
