# Trade-action helper at `0x218350`

`src/trade_action_helper_218350.cpp` reconstructs the original helper at
`0x218350`. The source is byte-identical to commit
`273c7d9b96ad0c83f4c0d9cd511c6a3b33963a78` (SHA-256
`f2fd912590fa70260f66762a326125881ce5160d779988e7b82d296c5a5d8fec`). Its
registered object remains **NonMatching**.

The original PAL ELF has SHA-1
`f478e19f2059d52899b691483ef5c7522e30e17c`. The file-backed mapping places the
`0x218350..0x2184D0` slice at file offset `0x118530`; disassembly confirms
`0x17C` bytes of function code followed by four zero padding bytes. The
configuration records the function symbol as `0x17C` bytes and keeps the final
four bytes as binary padding.

The seven native cases exercise the three early guards and reset at `+0x38`,
callback ordering and arguments, the NULL `ABA00` result path, manager-field
reload, loop-limit reload, and per-iteration vtable/flag reloads. The full
Docker suite passes with 349 passed and no skips. Seven deliberate production
mutations were rejected by the native assertions, including stale loop state, a
removed NULL-result guard, reordered cleanup calls, incorrect callback
arguments, and a delayed reset.

A fresh MWCC PS2 compile produced an ELF32/MIPS relocatable object with one
`.text` section (section index 5), a function symbol with `st_shndx` 5 and size
`0x18C`, and six `.rel.text` entries. The external calls are represented by
relocations, not embedded addresses. An isolated GNU link with `--no-undefined`
resolved those calls to the original addresses and set `_gp` to `0x4EA7C0`; the
linked `.text` is `0x18C` bytes. Against the original `0x17C`-byte function,
the full-length byte comparison has 380 overlapping bytes (122 equal, 258
different), zero missing original bytes, and 16 extra candidate bytes. Against
the whole `0x180` slice including four padding bytes, it has 384 overlapping
bytes (123 equal, 261 different), zero missing slice bytes, and 12 extra
candidate bytes. These raw metrics do not mask instructions or assert matching;
the candidate remains non-matching.

The first fresh Ninja run exposed a stale ignored `.splache` cache after a clean
had removed generated assembler output: the cache treated the missing
`trade_action_helper_218350.s` as already split, causing repeated split and
configure regeneration. The safe correction was to remove only that ignored
cache and rerun the normal checked configure command and explicit Ninja targets.
This regenerated the assembly and both helper objects without changing the
build generator, skipping regeneration, or bypassing configure. The rebased
Ninja, configure, full-suite, mutation, object, and isolated-link artifacts are
retained under `/tmp/aoe-advisor-helper218350-proof-rebased/`.
