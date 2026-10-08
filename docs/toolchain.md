# Toolchain

**Status: unverified.** No compiler has been identified for any target yet.
Every compiler setting in `configure.py` is a placeholder marked `TODO`. This
document lists how to identify each toolchain from the original binaries, and
what `configure.py` expects.

## What the build needs

| Platform | Compiler                 | Assembler / linker       | How it is provided                       |
|----------|--------------------------|--------------------------|------------------------------------------|
| PC       | Microsoft C/C++ (version TBD) | MSVC `link`, PDB output | `--compilers <DIR>`. Licensed, not downloaded. |
| PC       | (run under wibo on Linux) | wibo 1.2.0 (auto-downloaded) | `ninja tools`                        |
| PS2      | EE GCC (version TBD)     | MIPS binutils 2.45       | `--compilers <DIR>` for EE GCC. binutils is downloaded. |

`configure.py` refuses to run without `--compilers` (see `require_toolchain`),
because the Microsoft and EE toolchains are licensed. The MIPS binutils is
downloaded from the `dbalatoni13/mips-binutils` release (see `mips_binutils_url`
in `tools/download_tool.py`). It is a generic MIPS binutils, not the original EE
toolchain.

## Splitting the PC binary needs IDA exports

The PC split uses `delink` v0.16.1, downloaded from `dbalatoni13/delink` (see
`delink_url` in `tools/download_tool.py`). It runs `delink ida-split` on the
exe, and that command reads two files exported from IDA Pro:

- `config/<VERSION>/symbols.json`: the IDA database export (`delink_ida_version`)
- `config/<VERSION>/splits.json`: function and section ranges per source unit

Neither file can be generated from the binary alone. Until both exist, `ninja`
stops with:

```
ninja: error: rebuilding 'build.ninja': 'config/<VERSION>/splits.json', needed by ..., missing and no known rule to make it
```

This is expected for a fresh bootstrap. IDA Pro is commercial, so the PC target
depends on access to it, or to an equivalent exporter that writes the same
format.

The PS2 split does not need IDA. `splat` reads `config.yml` directly, and its
`ninja -n` dry run resolves.

## Identifying the PC compiler

The PE file records the linker and build tools in its Rich header. Use
`pefile` (`pip install pefile`) to read it:

```sh
python3 -c "import pefile, sys; pe = pefile.PE(sys.argv[1]); print(pe.OPTIONAL_HEADER.MajorLinkerVersion, pe.OPTIONAL_HEADER.MinorLinkerVersion); print(pe.parse_rich_header())" orig/AGE2_X1_1_0C_EN/age2_x1.exe
```

Result for `AGE2_X1_1_0C_EN` (`age2_x1.exe`, SHA-1 `c95a1e8c…`):

- Linker: `MajorLinkerVersion 5`, `MinorLinkerVersion 10` (link 5.10).
- Rich header: one tool entry besides 333 unmarked objects. `prodid 0x0006`,
  build `1668`.
- Per the `dishather/richprint` `comp_id.txt` table, `0x0006 / 1668` is
  `VS97 (5.0) SP3 cvtres 5.00.1668`, and `link 5.10.7303` is also VS97 SP3.
- The binary contains the string `Microsoft Visual C++ Runtime Library`, which
  does not identify a version.

Status: **the linker and resource compiler point to VS97 (MSVC 5.0) SP3. The
`cl.exe` build is not confirmed**, because no compiler entry appears in the
Rich header. `configure.py` sets `linker_version = "Win32/VS97-SP3-unconfirmed"`.
The `/Ox` optimisation flags are still a guess.

## Identifying the PS2 compiler

The ELF `.comment` section records the compiler version string:

```sh
readelf -p .comment orig/SLES-50282/AOK.ELF
readelf -S orig/SLES-50282/AOK.ELF | grep -E 'symtab|debug'
```

- **Result for SLES-50282 (`AOK.ELF` / `EN/AGE2_PS2.ELF`):**
  - Compiler string in `.comment`: `MW MIPS C Compiler (2.3.1.01)` / `PlayStation2`.
  - Toolchain: **Metrowerks CodeWarrior for PlayStation 2, compiler version 2.3.1.01** (`MWCCPS2` in splat).
  - Symbols: Stripped. `.symtab` has 0 entries and no `.debug_*` / DWARF sections are present.
- `compiler: MWCCPS2` updated in `config/SLES-50282/config.yml`.
- `linker_version = "PS2/mwcc-2.3.1.01"` updated in `configure.py`.

## Expected `--compilers` layout

`--compilers <DIR>` points at the directory the compiler binaries come from. For
PC this is the Microsoft tools root, so `cl.exe` and `link.exe` are inside it.
For PS2 it is the CodeWarrior PS2 tools root.

The directory is not committed. Keep it outside the repository or in an ignored
path such as `build/compilers`.

## Checklist before any object is added

- [~] PC toolchain partly identified from the Rich header (VS97 SP3 linker and
      resource compiler). `cl.exe` build still to confirm
- [x] PS2 compiler identified from `.comment`, `linker_version` updated (`MW MIPS C Compiler 2.3.1.01`)
- [ ] Optimisation and debug flags confirmed by compiling a known function and
      diffing it against the original (objdiff)
- [ ] `--compilers` path documented in the README quick start
