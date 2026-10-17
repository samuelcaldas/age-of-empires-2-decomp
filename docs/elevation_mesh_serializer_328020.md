# Descriptor serializer at 0x328020

`func_00328020` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_elevation_mesh_serializer.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **224/224 instruction bytes (100%)**
after resolving four `R_MIPS_26` writer-call relocations. This is an isolated
function result, not a claim that the surrounding subsystem or full linked
executable matches. The descriptive file and structure names are provisional;
the original class name and the meaning of its metadata are not established.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x328020, 0x328100)`, file `[0x228200, 0x2282E0)`.
  The mapping is checked through the ELF's `PT_LOAD` segment, not assumed from
  a slicer label. All 224 bytes are instructions, with no trailing padding.
- 32-bit descriptor: buffer-pointer table at `0x00`, integer metadata table
  at `0x04`, signed entry-count table at `0x08`, an unknown four-byte field at
  `0x0C`, and signed descriptor count at `0x10`. Native tests assert these
  offsets, the 20-byte modeled extent, and four-byte pointers/integers.
- The modeled extent covers accessed fields; it does not prove the original
  allocation's complete size.

## Observable behavior

1. Call the writer at `0x226F70` with `(stream, self + 0x10, 4)`, including
   zero and negative descriptor counts.
2. For each signed index below the current descriptor count, write four bytes
   from `table4[index]`, then four bytes from `table8[index]`.
3. After all metadata writes, iterate again. For each positive signed
   `table8[index]`, write `table0[index]` with the low 32 bits of
   `table8[index] << 3` as its byte size. Zero/negative entries produce no
   payload call. Positive entries forward their buffer pointer even if null.
4. Both loops reload the descriptor count after each iteration. The first
   condition is also evaluated after the header writer returns.

The original has no input guards and no established meaningful return value.
Its valid-input preconditions are retained rather than inventing null-input
behavior. Unsigned shifting avoids C++ signed-overflow undefined behavior while
preserving the reference `sll` instruction. Declaring the shared loop index in
the parent function, and passing it by reference to inline helpers, reproduces
the original register allocation without assembly or compiler intrinsics.

## Reproducible verification

Run in the `docker-dev` verification image with the licensed original,
compiler, and wibo paths mounted read-only when they are external symlinks:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_serializer.py \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_serializer_matching.py
```

The focused run has **9 passing tests, no skips**:

- One 32-bit native contract process compiled with warnings as errors and
  UndefinedBehaviorSanitizer checks source addresses, stream receiver, byte
  sizes, copied contents, zero/one/multiple entries, negative counts, skipped
  payloads, null payload forwarding, wrapped byte sizes, and a writer that
  modifies the descriptor count.
- Seven actual production-source mutations are independently compiled and
  rejected: suppressed empty header, wrong metadata source, wrong payload
  scale, an extra zero-length payload, suppressed null payload, reversed
  serialization phases, and unsigned loop comparisons. The earlier null-call
  smoke test was not mutation testing and has been removed.
- One matching test verifies the pinned original hash, invokes Ninja to compile
  a fresh MWCC object, selects code by the function symbol's section index,
  resolves exactly four writer-call relocations, and asserts literal equality
  of all 224 bytes. It never substitutes a stale prebuilt object. Missing
  licensed prerequisites cause a clearly reported skip outside this setup.

## Wider validation and limits

After rebasing the focused change onto upstream `f6b0b2a4`, the full Docker
pytest run completed with **420 passed, 939 skipped, zero failures**, including
all nine focused tests without skips. Of the skipped cases, 894 explicitly
require the missing `build/mips_binutils/mips-linux-gnu-ld`; the other 45 report
private-original/tool prerequisites. This is not a fully exercised project-wide
matching result; skipped tests remain unverified. Flake8 passes for
`configure.py` and both serializer Python test files. File-size, Python
function-length, documentation-link, and focused-symbol checks also pass.

The regular configure/Ninja path was attempted, but does not produce a clean
full build in this environment. The slicer reports existing symbols without
segments (including `func_00268800`), and Ninja attempts tool downloads that
fail because the verification container intentionally has no network. A direct
project-wide objdiff report also fails because
`build/SLES-50282/obj/trade_action_stream_decoders95.o` is absent. No fresh
cumulative matching percentage or byte count is claimed. These limitations do
not affect the fresh standalone Ninja/MWCC comparison described above.

Only the verified function symbol is added; existing writer aliases are retained.
The registered object list and slicer configuration remain unchanged. On the
focused upstream baseline, the unsplit BIN starts at file `0x207D60` and covers
both the earlier worktree's WIP frontier `0x310960` (file `0x210B40`) and this
function. Neither frontier is advanced by this change. The function has not
been split into the main linked build. The next contiguous reference function
begins at `0x328100`; no behavior or matching claim is made for it here.
