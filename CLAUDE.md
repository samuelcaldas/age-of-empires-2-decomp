# CLAUDE.md

Guidance for Claude Code when working in this repository.

## Project

A matching decompilation of Age of Empires II for PC and PlayStation 2. Targets
and their roles are in [docs/adr/0001-target-editions.md](docs/adr/0001-target-editions.md).

| Version            | Platform   | Role      | Original file                        |
|--------------------|------------|-----------|--------------------------------------|
| `AGE2_X1_1_0C_EN`  | PC         | Primary   | `orig/AGE2_X1_1_0C_EN/age2_x1.exe`   |
| `EMPIRES2_2_0A_EN` | PC         | Secondary | `orig/EMPIRES2_2_0A_EN/empires2.exe` |
| `SLES-50282`       | PS2 PAL    | Primary   | `orig/SLES-50282/AOK.ELF`            |
| `SLPM-62076`       | PS2 NTSC-J | Secondary | `orig/SLPM-62076/AOK.ELF`            |

Original binaries are never committed. Their layout and checksums are in
[docs/game_files.md](docs/game_files.md).

## Commands

```sh
# Configure a version (generates build.ninja; objdiff.json appears after the first split)
.venv/bin/python configure.py --version <VERSION> --compilers <DIR>

# Build the registered objects
ninja
```

`configure.py` checks the original binary and the compiler directory before it
writes anything. Do not bypass those checks. Only the configure step and the
PS2 `ninja -n` dry run have been verified. The PC split additionally needs
IDA-exported `splits.json` and `symbols.json` (see `docs/toolchain.md`).

## Layout

- `configure.py`: project configuration. Versions, platform flags, and object lists.
- `tools/`: build generator copied from the dtk template and the nfsmw project.
  `project.py` and the helper scripts are kept close to upstream. Lint warnings
  in them are inherited. Fix upstream, not here.
- `config/<VERSION>/`: `config.yml` (slicer config), `build.sha1` (pinned hash).
  `splits.json`, `symbols.json`, and `symbols.txt` are added once a binary is analysed.
- `orig/<VERSION>/`: original binaries. Ignored by git.
- `docs/`: game files, toolchain, and decisions (`docs/adr/`).

## Rules for this repository

- Never commit game files, dumps, ISOs, or compiler binaries. `.gitignore` covers
  them; check `git status` before committing.
- Object lists in `configure.py` stay empty until a function has been split and
  its object is ready to match.
- Pin the hash of a binary in `config/<VERSION>/build.sha1` once it has been
  verified. Do not pin an unverified hash.
- Compiler and flag settings marked `TODO` are guesses. Replace them with
  verified values and update `docs/toolchain.md`.
- Keep `docs/` in step with the code. Update the relevant doc in the same change.
