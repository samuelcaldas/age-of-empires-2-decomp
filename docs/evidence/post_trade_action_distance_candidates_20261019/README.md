# `func_002B8E30`: Docker verification evidence, 2026-10-19

## Outcome and limits

The candidate produces an exact 624-byte slice: 616 code bytes and eight verified
zero-padding bytes. The Docker native/mutation/verifier suite passes all nine
tests. These results do **not** establish historical test-first development.
`configure.py` remains **NonMatching**, pending coordinator review of the process
gap. No merge or push is authorized by this evidence.

The implementation commit is `1b1e7acccc5dea13a7702143c82660551c8869ce`.
Its parent is `1ebe519ec4b15af59e9043a2bb758e83804b30e0`.
The parent has no dedicated C/C++ implementation of `func_002B8E30`. Adding only
the candidate header and fixture results in undefined references at link time;
[parent-link-check.txt](parent-link-check.txt) records that separate prerequisite
failure. It is **not** behavioral Red evidence.

The historical `.venv/bin/pytest` run was on the host. Scratch implementations
already existed before that assertion failure. The earlier heading claiming
"Red-Before-Implementation Chronology" therefore overstated the evidence.
Neither a later mutation run nor the Docker reproduction below repairs that
historical process gap. The native fixture was written at `08:18:20.589Z`, after
the first scratch compilation at `08:15:10.753Z`. The recovered
[historical chronology](historical-chronology.md) records the exact repository
placeholder, setup failures, commands, source-copy event, and original host Red.

## Retrospective placeholder reproduction

A separate archive of the parent received the candidate header, native fixture,
Python tests, and verifier. A temporary placeholder provided this explicit
missing-behavior baseline:

```cpp
#pragma exceptions off
#include "post_trade_action_distance_candidates.h"

extern "C" int func_002B8E30(TradeActionState *self, int *coords) {
    return -1;
}
```

This placeholder is **not** an implementation found in the parent commit. Its
signature uses the candidate's forward-declared type to compile the unchanged
candidate fixture. No production source was reverted or rewritten.

Both iterations ran in the **same Docker container**, with `/workspace` as the
working directory, using this identical focused command:

```sh
python -m pytest -q -ra \
  tests/test_post_trade_action_distance_candidates.py::test_distance_candidates_behavior
```

1. At `2026-10-19T08:43:34.868753+00:00`, the placeholder run failed the executed
   native assertion `res1 == 42`. The native process exited with `-6`; pytest
   exited with `1`: **1 failed**. See [red.txt](red.txt).
2. Only the placeholder source was replaced with the committed candidate source.
   At `2026-10-19T08:43:35.669525+00:00`, the same command exited with `0`:
   **1 passed**. See [green.txt](green.txt).
3. The full focused command below exited with `0`: **9 passed**, no skips.
   See [focused.txt](focused.txt).

```sh
python -m pytest -q -ra \
  tests/test_post_trade_action_distance_candidates.py \
  tests/test_verify_post_trade_action_distance_candidates.py
```

[replay-manifest.json](replay-manifest.json) records UTC timestamps, commands,
exit codes, overlay file hashes, and the source hash for every iteration.
The source SHA-256 values are:

- Placeholder: `46ca091080631f96398059c94b5c77a10907fd4e9fcd793af7847bcb5abf8819`.
- Committed candidate: `d5d792420c0325c4c95776e03427792026cec86829aba9c1320512c7d04f0167`.

## Docker environment and exact launch

Context: `docker-dev`. Image:
`sha256:29a25db120e80393f910e686823843eea0383a02d34e0a33990ae9edaeb7b4b4`.
The image provides Python `3.14.7`, pytest `9.1.1`, splat64 `0.50.1`, native
32-bit compilation support, and Ninja. Network access was disabled. Containers
used the invoking user's numeric user/group IDs and `TZ=America/Sao_Paulo`.

The private original binaries, licensed compilers, wibo, and MIPS binutils were
mounted read-only. Build outputs went into new writable archives, not the shared
root-owned build directory. No shared ownership or permissions changed.

The actual evidence root was
`/tmp/aoe6-distance-evidence-20261019-tE2VNi`. Parent, candidate, and reproduction
archives occupied separate subdirectories. The retained orchestration script is
[replay.py.txt](replay.py.txt); its `.txt` suffix marks an archival record, not a
project tool. The exact launch was:

```sh
evidence_root=/tmp/aoe6-distance-evidence-20261019-tE2VNi
mkdir -p "$evidence_root/reproduction/build/tools" \
  "$evidence_root/reproduction/build/mips_binutils"
set -o pipefail
docker --context docker-dev run --rm --network none \
  --user "$(id -u):$(id -g)" --ulimit core=0 \
  -e TZ=America/Sao_Paulo -e PYTHONPATH=/workspace \
  --mount "type=bind,source=$evidence_root/reproduction,target=/workspace" \
  --mount "type=bind,source=$evidence_root/candidate,target=/candidate,readonly" \
  --mount "type=bind,source=$evidence_root/logs,target=/evidence" \
  --mount "type=bind,source=$evidence_root/replay.py,target=/replay.py,readonly" \
  --mount type=bind,source=/home/samuelcaldas/source/repos/aoe/orig,target=/workspace/orig,readonly \
  --mount type=bind,source=/home/samuelcaldas/source/repos/aoe/compilers,target=/workspace/compilers,readonly \
  --mount type=bind,source=/tmp/aoe_trade_workspace/build/tools/wibo,target=/workspace/build/tools/wibo,readonly \
  --mount type=bind,source=/home/samuelcaldas/source/repos/aoe/.worktrees/trade-destination/build/mips_binutils,target=/workspace/build/mips_binutils,readonly \
  sha256:29a25db120e80393f910e686823843eea0383a02d34e0a33990ae9edaeb7b4b4 \
  python /replay.py 2>&1 | tee "$evidence_root/logs/replay-console.txt"
```

To recreate the archives at a new evidence root, run `git archive <SHA> | tar -x
-C <empty-directory>` for the parent and candidate SHAs above. Create a second
parent archive for the reproduction. Save `replay.py.txt` as `replay.py` and run
the launch with that evidence root. Do not reuse or overwrite another session's
workspace. The private prerequisite paths must exist on the Docker daemon host.

## Target binary comparison

The replay container independently executed:

```sh
python tools/verify_post_trade_action_distance_candidates.py
python tools/verify_trade_action_type_checker.py
```

The distance verifier located the function through symbol `st_shndx`, checked its
616-byte size, resolved six `R_MIPS_26` calls, and compared the full slice with the
private original ELF. Result: **624/624 bytes identical**, including eight
independently checked padding bytes. See [distance-match.txt](distance-match.txt).
The neighboring checker remained exact at **160/160 bytes**. See
[checker-match.txt](checker-match.txt).

The distance code occupies `[0x2B8E30, 0x2B9098)`; padding occupies
`[0x2B9098, 0x2B90A0)`. Calls resolve to `0x332E60`, `0x147170` at four sites,
and `0x269190`. No assembly implementation was introduced.

These matching results and native fixture assertions are separate gates. The
fixture does not establish comprehensive call-order, forwarding, capacity,
empty-pool, null-result, tie, or NaN coverage. Mutation sensitivity does not prove
historical test-first chronology.

## Full regression comparison

Fresh, separate parent and candidate archives used the same image, Python,
private prerequisites, `/workspace` working directory, and default progress
setting. Both checked the original ELF SHA-1:
`f478e19f2059d52899b691483ef5c7522e30e17c`.

| Gate | Parent `1ebe519ec` | Candidate `1b1e7accc` |
| --- | --- | --- |
| Configure | Exit 0 | Exit 0 |
| `ninja -j 2` | Exit 0 | Exit 0 |
| Selected trade subsystem | 106 passed | 115 passed |
| Full pytest suite | 2,601 passed | 2,610 passed |
| Full-suite failures / skips | 0 / 0 | 0 / 0 |
| `python -m flake8 configure.py` | Exit 0 | Exit 0 |

The complete commands, package versions, exit statuses, and timestamps are in
[parent-default-gates.json](parent-default-gates.json) and
[candidate-default-gates.json](candidate-default-gates.json). Retained terminal
results are [parent-default-full.txt](parent-default-full.txt) and
[candidate-default-full.txt](candidate-default-full.txt), with the selected trade
results in [parent-default-subsystem.txt](parent-default-subsystem.txt) and
[candidate-default-subsystem.txt](candidate-default-subsystem.txt).

The [regression inventory](regression-inventory.json) compares JUnit test
identities: all 2,601 common tests passed, nine candidate tests were added, and no
tests were removed or changed status. All four route-finish matching tests ran
and passed after Ninja built their prerequisite object. There are no unavailable
prerequisites or skipped tests in these final runs.

The configure command in each container was:

```sh
python configure.py --version SLES-50282 \
  --compilers /workspace/compilers \
  --binutils /workspace/build/mips_binutils \
  --wrapper /workspace/build/tools/wibo \
  --objdiff /workspace/build/tools/objdiff-cli
```

After configure, each container ran `ninja -j 2`, explicitly checked the route
object target, ran its selected trade tests, then ran:

```sh
python -m pytest -q -ra --junitxml=/evidence/<snapshot>-full.xml
python -m flake8 configure.py
```

The retained [gates-default.py.txt](gates-default.py.txt) script records those
steps. For each of `parent-default` and `candidate-default`, the Docker launch
used the same mount and environment options as the replay, with these changes:

- Mount that snapshot at `/workspace`; do not mount the reproduction archive.
- Mount the retained gate script as `/gates.py` and run
  `python /gates.py <snapshot>` instead of `/replay.py`.
- Add `-e HOME=/tmp` and a read-only mount from
  `/home/samuelcaldas/source/repos/aoe/build/tools/objdiff-cli` to
  `/workspace/build/tools/objdiff-cli`.
- The candidate-input mount is unnecessary for these independent gate runs.

`ninja` succeeded for the repository's default build/progress target. This is not
a claim that a complete game executable was relinked, or that the whole game is
100% C/C++ matched. The candidate remains NonMatching and is verified separately
by the dedicated byte comparator.

### Earlier failed invocation, retained separately

The first pair of Docker attempts added the optional `--no-progress` argument.
Configure initially succeeded, but Ninja's regeneration reached
`tools/project.py:1957` and failed in **both** snapshots:

```text
UnboundLocalError: cannot access local variable 'ok_path' where it is not associated with a value
ninja: error: rebuilding 'build.ninja': subcommand failed
```

That invocation produced **2,576 passed, 30 failed, 4 skipped** for the candidate
and **2,567 passed, 30 failed, 4 skipped** for the parent. Every failure was a
`test_zone_spatial_grid_block27_build` through
`test_zone_spatial_grid_block56_build` Ninja check. The four skipped cases were
`func_001508F0`, `func_00150920`, `func_00150CC0`, and `func_00150CE0` in
`tests/test_ps2_route_finish_matching.py`, each with reason
`requires licensed original ELF and a freshly built MWCC object`.

The regression inventory retains every failed and skipped test identity and its
message for those attempts. They were not green gates. The corrected runs used
fresh archives without `--no-progress`; no repository build-generator code was
changed. The source/compiler prerequisites were otherwise identical.

## Artifact preservation

Raw Docker logs and JUnit XML remain under
`/tmp/aoe6-distance-evidence-20261019-tE2VNi/logs`. The historical host output
remains in the private session transcript. Exported terminal text removes only
trailing horizontal whitespace; [artifact-hashes.json](artifact-hashes.json)
records the raw and exported SHA-256 values. Commands, assertion messages, exit
codes, source hashes, and event ordering are preserved. Original binaries,
compiler binaries, build objects, and disassembly dumps are not part of this
packet.

The coordinator retained NonMatching status after reviewing the chronology and
authorized only a subsequent boundary audit. This packet does not waive the
repository's mandatory test-first policy.
