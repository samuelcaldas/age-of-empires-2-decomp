# Game files

This repository contains no game assets or original binaries. You must own the
game and supply the files yourself. Editions and their rationale are in
[ADR 0001](adr/0001-target-editions.md).

## Layout

Each target has one folder under `orig/`, which is ignored by git (only the
`.gitkeep` is tracked):

| Version            | Expected file                          | Where it comes from                                                        |
|--------------------|----------------------------------------|----------------------------------------------------------------------------|
| `AGE2_X1_1_0C_EN`  | `orig/AGE2_X1_1_0C_EN/age2_x1.exe`     | `age2_x1\age2_x1.exe` in the installed The Conquerors folder (1.0c)        |
| `EMPIRES2_2_0A_EN` | `orig/EMPIRES2_2_0A_EN/empires2.exe`   | `empires2.exe` in the install root (2.0a)                                  |
| `SLES-50282`       | `orig/SLES-50282/AOK.ELF`              | English game ELF (`EN/AGE2_PS2.ELF`) on PAL disc, copied and renamed       |
| `SLPM-62076`       | `orig/SLPM-62076/AOK.ELF`              | Boot ELF named in `SYSTEM.CNF` on the NTSC-J disc, copied and renamed      |

The PC installs use the default path `C:\Program Files\Microsoft Games\Age of Empires II\`
for the base game. The Conquerors lives in its `age2_x1` subfolder.

Patched or widescreen builds (for example `age2_x1_1.0c_1920x1080.exe`) are
**not** the original. Use the file from an unmodified 1.0c or 2.0a install.

**Note:** the 1.0c install also ships `age2_x1.icd` (2.6 MB) next to
`age2_x1.exe`. `age2_x1.exe` looks like the SafeDisc loader, and `age2_x1.icd`
may hold the game code. Which file to target is still open (ADR 0001, item 6).
The pinned hash covers `age2_x1.exe` only.

## Extracting PS2 boot ELFs

The PAL release (`SLES-50282`) is a multi-language disc containing a launcher ELF
and localized game executables:

1. Open the disc image with any ISO 9660 tool (for example `7z x aoe2.iso`).
2. `SYSTEM.CNF` contains `BOOT2 = cdrom0:\SLES_502.82;1`, which is the multilingual
   bootloader/launcher (`1.5 MB`).
3. The actual Age of Empires II game engines reside in language subdirectories:
   - `EN/AGE2_PS2.ELF` (`4.0 MB`, English build, primary matching target)
   - `FR/AGE2_PS2.ELF` (French)
   - `GR/AGE2_PS2.ELF` (German)
   - `IT/AGE2_PS2.ELF` (Italian)
   - `SP/AGE2_PS2.ELF` (Spanish)
4. Copy `EN/AGE2_PS2.ELF` to `orig/SLES-50282/AOK.ELF`.

For a full breakdown of every file, overlay (`.BIN`), audio container (`DATA.CAT`),
master DRS archive (`ALL_DATA.BIN`), and IOP module on the disc, see
[PS2 Disc Architecture & File Catalog](ps2_disc_architecture.md).

## Verifying a dump

Hash the file and compare it with `config/<VERSION>/build.sha1`:

```sh
sha1sum orig/<VERSION>/<file>
```

`build.sha1` uses the `sha1sum` format (`<sha1>  <path>`). The first token is
the pinned value. The PS2 `config.yml` has a `sha1:` key as well, and the two
must match.

Pinned values for `SLES-50282` (v2.00):
- `orig/SLES-50282/AOK.ELF` (`EN/AGE2_PS2.ELF`): `f478e19f2059d52899b691483ef5c7522e30e17c`
- `orig/SLES-50282/SLES_502.82`: `2f5139c1cb45c6b22b93e0c32bbea8e94a7b4a5f`
- `aoe2.iso`: `77a9cec2083a7c3d82518b3ae47371b55ec2e7ce`

## Fail-fast behavior

`python3 configure.py --version <VERSION>` checks the original binary before it
generates any build file:

- Missing file: exits with the expected path and a pointer to this document.
- Pinned hash does not match: exits with the expected and actual SHA-1.

Nothing is written to `build/` when either check fails.
