# Age of Empires II Decompilation

Work-in-progress matching decompilation of **Age of Empires II** for:

- **PC**: Age of Empires II: The Conquerors 1.0c (primary), Age of Kings 2.0a (secondary)
- **PlayStation 2**: Age of Kings, PAL `SLES-50282` (primary), NTSC-J `SLPM-62076` (secondary)

The choice of editions and the reasons for it are in
[ADR 0001](docs/adr/0001-target-editions.md).

**Status: matching in progress.** Multiple slices and functions have been matched in pure C++ against original binaries. Verified status, matching bytes, and telemetry can be inspected via the [observability tool](docs/observability.md).

Expected dynamic dashboard (pending GitHub Pages activation): `https://samuelcaldas.github.io/age-of-empires-2-decomp/`

Badges (generated statically; subject to GitHub image cache):
- Verified C++: `![Verified C++](build/observability/site/badges/bytes.svg)`
- Verification State: `![State](build/observability/site/badges/state.svg)`
- Last Verified: `![Last Verified](build/observability/site/badges/verified-at.svg)`

This repository does **not** contain any game assets or original binaries. You
need your own copy of the game.

## Quick start

1. Create the virtual environment and install dependencies:

   ```sh
   python3 -m venv .venv
   .venv/bin/pip install -r requirements.txt
   ```

2. Place the original files as described in [docs/game_files.md](docs/game_files.md).

3. Configure one version. The compilers are licensed and must be supplied
   (see [docs/toolchain.md](docs/toolchain.md)):

   ```sh
   .venv/bin/python configure.py --version AGE2_X1_1_0C_EN --compilers <DIR>
   ```

   `configure.py` exits with the expected path if a binary is missing, or with
   the expected and actual SHA-1 if a pinned hash does not match.

4. Build (once objects have been registered):

   ```sh
   ninja
   ```

## Documentation

- [docs/README.md](docs/README.md): index of all project docs
- [docs/game_files.md](docs/game_files.md): where each original file comes from and how to verify it
- [docs/toolchain.md](docs/toolchain.md): compilers, how to identify them, what is still unverified
- [docs/observability.md](docs/observability.md): decompilation progress observatory, tmux dashboard, and metric badges
- [docs/adr/0001-target-editions.md](docs/adr/0001-target-editions.md): edition decision and sources
- [docs/agy_orchestration.md](docs/agy_orchestration.md): delegating tasks to the agy CLI through `scripts/agy/`

## Method

The layout follows the [Need for Speed: Most Wanted decompilation](https://github.com/samuelcaldas/nfsmw-decomp):
a generated `build.ninja` from `configure.py`, a per-version `config/<VERSION>/`
directory, original binaries kept under `orig/`, and objdiff for comparison.
`tools/` is copied from that project and kept close to upstream.

Formatting follows the same setup: `.clang-format` and `.clang-tidy` for C/C++,
and `.flake8` for Python.
