# ADR 0001: Target editions

- Status: accepted for bootstrap, with open verification items (see below)
- Date: 2026-10-08

## Context

The project decompiles Age of Empires II (Ensemble Studios, Microsoft / Konami)
for PC and PlayStation 2. A matching decompilation needs a fixed, unmodified
original binary to compare against. Its value depends on:

1. The binary being stable: no later patches, mods, or re-engineering.
2. The compiler being identifiable, so it can be matched.
3. Debug information or leftover symbols, if any exist, to speed up matching.

## Decision

| Id                  | Platform | Edition                                  | Role      |
|---------------------|----------|------------------------------------------|-----------|
| `AGE2_X1_1_0C_EN`   | PC       | The Conquerors 1.0c, `age2_x1/age2_x1.exe`  | Primary   |
| `EMPIRES2_2_0A_EN`  | PC       | Age of Kings 2.0a, `empires2.exe`        | Secondary |
| `SLES-50282`        | PS2 PAL  | Age of Kings, boot ELF (`AOK.ELF`)       | Primary   |
| `SLPM-62076`        | PS2 NTSC-J | Age of Kings, boot ELF (`AOK.ELF`)     | Secondary |

Rationale:

- **PC primary = The Conquerors 1.0c.** It is the last official PC patch of the
  game's engine and includes the Age of Kings content. It is the most complete
  official PC binary. The English build is pinned because each localization is
  a different binary.
- **PC secondary = Age of Kings 2.0a.** The base game's last official patch. It
  shares the engine with the expansion. Matching both lets the shared code be
  checked against two builds.
- **PS2 primary = SLES-50282 (PAL).** It is the PAL release with English menus,
  gameplay and voices, and the best documented PS2 disc in the sources we could
  reach. The PCSX2 wiki lists it.
- **PS2 secondary = SLPM-62076 (NTSC-J).** A separate Japanese release. Its text
  is in Shift-JIS, which is why `sjiswrap` is wired in `configure.py`.

Excluded:

- **HD Edition (2013) and Definitive Edition (2019).** They ship a modified,
  re-engineered Genie engine, with DRM and different binaries per platform. There
  is no fixed original to match.
- **UserPatch and other community patches.** They change the executable, so the
  bytes are no longer the original.
- **"Complete Edition" repacks.** They bundle changed files.
- **Forgotten Empires (`age2_x2.exe`).** A total-conversion mod, not an edition.
- **Xbox and other ports.** Not in scope.

## Consequences

- A `config/<VERSION>/` directory exists for each target above.
- The PS2 Age of Kings disc does not include The Conquerors content. The PS2
  build is therefore a separate code base, and PC-to-PS2 code reuse must be
  checked rather than assumed.
- Revision matters. PAL SLES-50282 exists in more than one revision with
  different hashes (one dump is labelled v2.00). The exact revision is pinned in
  `config/<VERSION>/build.sha1` once it is known.

## Open verification items

1. **PS2 symbols (Verified for SLES-50282).** Both `SLES_502.82` and `EN/AGE2_PS2.ELF`
   are stripped of debug symbols (`.symtab` has 0 entries, no `.debug_*` sections).
   However, string tables retain full source file paths (`kt_*.c`, `tribegam.cpp`,
   `obmanager.cpp`, `com_hand.cpp`).
2. **PS2 developer (Verified).** Ported by Konami Computer Entertainment Tokyo
   (`kt_*` wrapper layer) on top of Ensemble Studios' Genie engine codebase.
3. **Patch number of the PC binaries.** Confirm from the file's version resource
   or the in-game banner after dumping.
4. **Language of each dump.** Confirm English for `AGE2_X1_1_0C_EN` and
   `EMPIRES2_2_0A_EN`. SLES-50282 English game binary is at `EN/AGE2_PS2.ELF`.
5. **Compilers (Verified for SLES-50282).** The `.comment` section identifies
   `MW MIPS C Compiler (2.3.1.01)` (Metrowerks CodeWarrior for PlayStation 2).
   See `docs/toolchain.md`.
6. **Which PC file holds the game code (Open).** `age2_x1.exe` (pinned) looks
   like a SafeDisc loader: VS97 SP3 linker, `.txt` sections. The `age2_x1.icd`
   shipped alongside has VC++ 6.0 Rich entries, SafeDisc sections (`THIS_COD`,
   `THIS_DAT`), and entropy 7.90. If the game code is in the `.icd`, the PC
   target should move to it, and decryption has to be solved first. Check by
   reading the `.icd` entry point or by testing whether its code sections are
   readable. See `docs/toolchain.md`.

## Sources

- PC version history, executable paths, and the `age2_x1` folder layout:
  - [PCGamingWiki: Age of Empires II: The Age of Kings](https://www.pcgamingwiki.com/wiki/Age_of_Empires_II:_The_Age_of_Kings)
    (latest base-game patch 2.0a)
  - [PCGW Community: The Conquerors expansion patch](https://community.pcgamingwiki.com/files/file/119-age-of-empires-ii-the-conquerors-expansion-patch/)
    (latest expansion patch 1.0c)
  - [UserPatch installation guide](http://userpatch.aiscripters.net/guide.html)
    (`age2_x1` subfolder for `age2_x1.exe`)
  - [Forgotten Empires install guide](https://www.forgottenempires.net/install)
    (default install path)
- PS2 disc codes and release info:
  - [PSX Data Center: SLES-50282 (PAL)](https://psxdatacenter.com/psx2/games2/SLES-50282.html)
  - [PSX Data Center: SLPM-62076 (NTSC-J)](https://psxdatacenter.com/psx2/games2/SLPM-62076.html)
  - [PCSX2 Wiki: Age of Empires II: The Age of Kings](https://wiki.pcsx2.net/Age_of_Empires_II:_The_Age_of_Kings)
  - [cdromance: PAL v2.00 dump](https://cdromance.org/ps2-iso/age-of-empires-ii-the-age-of-kings-v2-00-europe/)
    (evidence of multiple revisions)
  - [Collector's guide (Japanese PS2 release)](https://museum.enjoygamejapan.online/en/games/age-of-empires-ii-the-age-of-kings/)
    (The Conquerors content missing from the PS2 port)
- Community landscape (what does not exist yet):
  - [openage](https://github.com/SFTtech/openage): clean-room engine clone; reads
    the original assets but ships no binaries. Useful for file formats, not for
    matching.
  - [Genie Engine (Wikipedia)](https://en.wikipedia.org/wiki/Genie_Engine)
  - [Age of Empires II (Wikipedia)](https://en.wikipedia.org/wiki/Age_of_Empires_II)

The Cutting Room Floor page for the PS2 release
(`tcrf.net/Age_of_Empires_II:_The_Age_of_Kings_(PlayStation_2)`) could not be
read during bootstrap. Its fetch returned unrelated text, and a second attempt
was blocked. Its notes on debug builds and revisions are still open (item 1).
