# Transport initialization at `0x337D40`

The PAL `SLES-50282` function occupies 920 bytes, `[0x337D40, 0x3380D8)`,
including the return delay slot. Evidence comes from this function's original
ELF instructions and referenced strings. No NTSC-J behavior or address is inferred.

## Behavior established by the PAL ELF

1. Create two semaphores. Before each call, write maximum count 1, initial count
   1, and option 0. Other descriptor fields are not initialized here. Store both
   results at `0x4E3560` and `0x4E3564`, without checking failure.
2. Call `0x389120` with `0x4E3548`. Byte-swap its two words into `0x4E3540`.
   Log swapped words, then original words, using `EUI64=%04x:%04x\n`.
   The callee's result is ignored; no stronger callee contract is assumed.
3. Open three sockets through `0x388BA0(60, 2, 0)`, storing results at
   `0x4E353C`, `0x4E3538`, and `0x4E3534`. Negative results do not stop execution.
4. Initialize three 16-byte address records at `0x10890B0`, `0x10890C0`, and
   `0x10890D0`. Set length 16, family 60, and port word `0x3412`. Zero the two
   node words of the first record; set both node words of the third to all ones.
   The middle record's node words and all three four-byte tails remain untouched.
5. Bind receive socket to the first record. Clear that record's port, then bind
   transmit and broadcast sockets to that same record. The middle record is
   initialized but is not passed to bind in this function.
6. Connect the broadcast socket to the third record.
7. Each bind/connect loop calls while result is nonzero, for at most five calls.
   It logs whenever the iteration count reaches five, including success on the
   fifth call. Log line arguments are 320, 328, 334, and 340, respectively.
   Errors do not abort subsequent stages. No cleanup occurs in this function.
8. Populate thread descriptor `0x10931A0`: entry `0x337B30`, stack `0x108B1A0`,
   size `0x8000`, priority 11, and GP `0x4EA7C0`. Other fields remain untouched.
   Create the thread through `0x104B20`. For any nonnegative result, start it
   through `0x104B40(id, 0)` and log `start th_Receiver()\n`, ignoring start's
   result. For a negative result, log the creation error with line argument 353.

Both exit paths preserve the final logger's return register. The source returns
that value; a fixed successful return of 1 is not established by this ELF.
Native mocks return distinct values (71 on thread start, -33 on creation error).
Both hardcoded-return mutants fail the native assertion.

## Behavioral and matching evidence

The native fixture executes the production C++ with `g++ -m32 -std=c++98`.
Its 23 cases cover ordinary execution, unchecked negative semaphore/socket
results, failed thread creation, and each bind/connect stage succeeding on
attempts 1, 2, 4, 5 or never succeeding within five calls. Mocks check call order,
arguments, logs, address contents, descriptor fields, and stored global results.
This is isolated behavior with mocked callees, not a live PS2 transport test.

Before implementation, all 23 cases failed at `assert(calls==expected)` against
the unchanged return-zero stub. Compilation succeeded. After implementation,
all 23 passed. Exact RED and GREEN command (run before and after source changes):

```sh
docker --context docker-dev run --rm --mount "type=bind,source=$(pwd),target=/workspace" aoe-tests:verification python -m pytest -q -ra tests/test_network_transport_init_337d40_native.py
```

MWCC 2.3.1.01, with the shared helper's `-O3 -inline on -msext on -char signed
-sym off` flags, emits exactly 920 bytes. The comparison resolves all 107 `.text`
relocations: 20 `R_MIPS_26`, 34 `R_MIPS_HI16`, 34 `R_MIPS_LO16`, and 19
`R_MIPS_GPREL16`. All 29 undefined external names have explicit original target
addresses in `tests/test_network_transport_init_337d40_matching.py`, including
`_gp`. No external symbol or relocation is masked. PAL result: **920/920 bytes
identical**, no first difference, against SHA1
`f478e19f2059d52899b691483ef5c7522e30e17c`.

```sh
.venv/bin/python tests/test_network_transport_init_337d40_matching.py
.venv/bin/python -m pytest -q -s tests/test_network_transport_init_337d40_matching.py
```

The exact-match pytest asserts every byte, size, and relocation count using
`tests/network_match_support.py`. The executable comparison prints `EXACT 920
bytes` only for equality. Metadata relocation sections are not instruction bytes.

| Version | Size | Bytes | Relocations and targets | Limitation |
|---|---|---|---|---|
| SLES-50282 | 920/920 | 920/920, unmasked | 107/107 resolved; 29 explicit external names | Isolated function comparison; no full project link |
| SLPM-62076 | Not measured | Not compared | Not verified | `orig/SLPM-62076/AOK.ELF` absent |

The PAL object is registered in `configure.py` and the SLES-50282 split and
symbol files. The receiver is now registered separately after its 524-byte
instruction stream and four alignment bytes. The semaphore alias at `0x4E3564`
is not separately registered because `D_004E3560` already spans both words.
NTSC-J remains unverified.

## Regression gates

The prescribed Docker image build passed (cached layers). Subsystem command:

```sh
docker --context docker-dev run --rm --mount "type=bind,source=$(pwd),target=/workspace" aoe-tests:verification python -m pytest -q -ra tests/test_network_transport_init_337d40_native.py tests/test_network_transport_init_337d40_matching.py tests/test_network_send_checked_337840.py tests/test_network_send_checked_337840_matching.py
```

Result: 24 passed, 5 skipped. The five matching skips explicitly report private
ELF/compiler/wibo paths unavailable through their absolute links inside Docker.
Host matching command below independently passed all five tests, including the
previously matched send wrapper. A Docker skip does not establish matching.

```sh
.venv/bin/python -m pytest -q -ra tests/test_network_transport_init_337d40_matching.py tests/test_network_send_checked_337840_matching.py
```

Changed Python tests pass `flake8`. `git diff --check` passes. No artificial RED
is claimed for documentation, formatting, or binary comparison assertions.

The full-suite comparison used the Docker verification image with each isolated
worktree mounted at `/workspace`; the original ELF, licensed compiler directory,
and shared tool directory were mounted read-only at their existing absolute
paths. Both runs configured the PS2 split and built the same nine verifier-object
prerequisites before invoking `python -m pytest -q -ra -p no:cacheprovider tests`.

| Worktree | Passed | Failed | Skipped | Errors | Duration |
|---|---:|---:|---:|---:|---:|
| Clean `main` baseline (`41ccda2ad`) | 4,355 | 36 | 31 | 7 | 314.07 s |
| `network-layer-match` after receiver registration | 4,447 | 35 | 10 | 7 | 272.34 s |

Failure/error IDs are identical except for one baseline-only failure:
`tests/test_tactical_ai_layout_341040_matching.py::test_tactical_ai_func_342170_mwcc_compilation`.
The feature branch has no new failure/error ID. Skip counts differ because the
feature branch includes additional network tests and private-input tests that the
baseline does not contain. These results are not green; they only show no new
failure/error identifier in the paired runs.

Shared failures: `test_zone_spatial_grid_block27.py` through
`test_zone_spatial_grid_block60.py` (34 failures) and one constructor assertion
in `test_tactical_ai_node_item.py`. Shared errors: six native subprocess errors
in `test_item_creator.py` and one in `test_visible_map.py`. The worktrees kept
separate build outputs. These baseline failures and errors were not repaired or
excluded. PAL matching does not complete the full network lifecycle; NTSC-J
remains unverified.

## Integration validation

The network-only suite passed: `python -m pytest -q -ra tests/test_network_*.py`
reported **70 passed**. The registered exact-function gate reports eight C++
functions. It verifies the receiver's 524 executable bytes, its 54 candidate
relocations, four zero alignment bytes, and the next prologue. The initializer
remains 920/920 bytes with 107 candidate relocations resolved.

`configure.py --version SLES-50282 --compilers compilers` and the PAL split
completed. Ninja built the receiver reference object and initializer reference
object; the corresponding C++ base objects were current. A subsequent dry run of
both object pairs reported `ninja: no work to do`.

Paired Docker full-suite runs used isolated clean-main and feature worktrees. Both
runs mounted the same original ELF, licensed compilers and build tools read-only.
They first prepared the same nine verifier prerequisites, then ran
`python -m pytest -q -ra -p no:cacheprovider tests`.

| Worktree | Passed | Failed | Skipped | Errors | Duration |
|---|---:|---:|---:|---:|---:|
| Clean `main` baseline (`41ccda2ad`) | 4,355 | 36 | 31 | 7 | 314.07 s |
| `network-layer-match` after receiver registration | 4,447 | 35 | 10 | 7 | 272.34 s |

Failure/error IDs are identical except for one baseline-only failure:
`tests/test_tactical_ai_layout_341040_matching.py::test_tactical_ai_func_342170_mwcc_compilation`.
The feature branch has no new failure/error ID. Skip counts differ because the
feature branch adds network matching tests that use the private inputs. The full
suite remains red; this comparison does not make its failures passes.

`flake8` passes for modified Python tests. `git diff --check` passes. Five local
Markdown links in `docs/README.md` were already broken on `main`; the changed
network-document links resolve. NTSC-J remains unverified. Overall Task 1 remains
blocked by unmatched session response, join and remaining lifecycle functions,
plus open end-to-end contract questions.
