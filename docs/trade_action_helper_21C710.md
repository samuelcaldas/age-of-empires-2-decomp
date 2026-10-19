# Trade action helper `0x21C710` subsystem

`src/trade_action_helper_21C710.cpp` reconstructs the four functions in slice
`[0x21C710, 0x21C990)` in pure C++. All four functions achieve **100.00% exact
byte-for-byte matching** against the original PlayStation 2 PAL binary across all
632 code bytes. The unit is registered as **Matching** in `configure.py` following
independent relocation-resolved review.

## Architecture and function contracts

The unit implements Graphics Synthesizer (GS) register-write packets for display
and texture pipeline configuration:

- Fallback packet allocation: if the input packet pointer is null, `func_123908(0)`
  allocates and returns a new packet object.
- Packet header setup: invokes `func_104448(packet, 0, 0, 0)`.
- 128-bit tag setting: loads quadword `*(u128 *)D_00392B30` and passes it by
  value to `func_1045E8(packet, tag)` via `lq a1, 0(v0)`.
- Register-specific payload assembly:
  - `func_0021C710`: writes register `0x14` directly with `unsigned long a1`.
  - `func_0021C790`: writes register `0x16` directly with `unsigned long a1`.
  - `func_0021C810`: packs a 3-component bitfield for register `0x3B` using:
    `((unsigned long long)a1) | (((unsigned long long)a2) << 15) | (((unsigned long long)a3) << 32)`.
  - `func_0021C8D0`: packs a 3-component bitfield for register `0x4F` using:
    `((unsigned long long)a1) | (((unsigned long long)a2) << 24) | (((unsigned long long)a3) << 32)`.
- Packet finalization: invokes `func_104600(packet)` and returns the packet pointer.

Numeric register IDs (`0x14`, `0x16`, `0x3B`, `0x4F`) are used directly without
relying on unverified descriptive names.

| Function | VRAM range | Code size | Register | Matching |
|---|---|---|---|---|
| `func_0021C710` | `[0x21C710, 0x21C790)` | 128 B (`0x80`) | `0x14` | **100.00%** |
| `func_0021C790` | `[0x21C790, 0x21C810)` | 128 B (`0x80`) | `0x16` | **100.00%** |
| `func_0021C810` | `[0x21C810, 0x21C8CC)` | 188 B (`0xBC`) | `0x3B` | **100.00%** |
| `func_0021C8D0` | `[0x21C8D0, 0x21C98C)` | 188 B (`0xBC`) | `0x4F` | **100.00%** |

## Binary mapping and raw evidence

The PAL `SLES-50282` ELF SHA-1 is `f478e19f2059d52899b691483ef5c7522e30e17c`.
Its file-backed `PT_LOAD` segment maps `p_offset=0x1E0` to `p_vaddr=0x100000`,
yielding `file_offset = VRAM - 0xFFE20`.

- Prior slice `trade_action_helper_21C410` ends at `0x21C710` (zero gap, zero overlap).
- `func_0021C710`: original file offset `0x11C8F0`–`0x11C970` (code size 128 B, zero pad 0 B).
- `func_0021C790`: original file offset `0x11C970`–`0x11C9F0` (code size 128 B, zero pad 0 B).
- `func_0021C810`: original file offset `0x11C9F0`–`0x11CAAC` (code size 188 B, zero pad `[0x21C8CC, 0x21C8D0)` 4 B).
- `func_0021C8D0`: original file offset `0x11CAB0`–`0x11CB6C` (code size 188 B, zero pad `[0x21C98C, 0x21C990)` 4 B).
- Next slice `trade_action_helper_21C990` starts at `0x21C990` (file offset `0x11CB70`).
- Total slice: 632 B code + 8 B padding = 640 B (`0x280`).

## Relocations

The compiled relocatable object emits 32 relocations across 8 relocation sections:

- 20 call relocations in `.rel.text` (`R_MIPS_26`): `func_123908` (x4), `func_104448` (x4), `func_1045E8` (x4), `func_1046A8` (x4), `func_104600` (x4).
- 8 absolute data relocation records in `.rel.text` (`R_MIPS_HI16` / `R_MIPS_LO16`): four pairs for `D_00392B30`.
- 4 metadata relocations in `.rel.mwcats` (`R_MIPS_32`): each at offset `0x4` referencing the function's own symbol.
- 0 GP accesses.

All decoded instruction-encoded `SHT_REL` addends are zero.

## Exact target comparison and environment

The dedicated matching test is preserved in
`tests/test_trade_action_helper_21C710_matching.py`. It compiles the actual source
with MWCC PS2 2.3.1.01 using:
`-O3 -inline on -msext on -char signed -sym off -Iinclude -lang=c++`.

It resolves calls to `func_123908` (`0x123908`), `func_104448` (`0x104448`),
`func_1045E8` (`0x1045E8`), `func_1046A8` (`0x1046A8`), and `func_104600` (`0x104600`),
and data references to `D_00392B30` (`0x392B30`). Each function's code bytes match
its original range exactly.

### Docker verification execution
To ensure that symlinked compiler directories resolve without skips, run the
container with dual bind mounts exposing both the worktree and the parent repository:

```sh
docker --context docker-dev run --rm --network host --user $(id -u):$(id -g) \
  -v /home/samuelcaldas/source/repos/aoe/.worktrees/trade-action-217930:/workspace \
  -v /home/samuelcaldas/source/repos/aoe:/home/samuelcaldas/source/repos/aoe:ro \
  -w /workspace \
  -e TZ=America/Sao_Paulo -e PYTHONPATH=/workspace \
  aoe4-verification-final:20261018 \
  /opt/venv/bin/pytest tests/test_trade_action_helper_21C710.py tests/test_trade_action_helper_21C710_matching.py -v
```

## Native tests and TDD evidence

Native regressions in `tests/test_trade_action_helper_21C710.py` and
`tests/native/trade_action_helper_21C710_test.cpp` verify:
1. `func_0021C710`: existing/null packet paths, tag value forwarding, and register `0x14` direct write.
2. `func_0021C790`: existing/null packet paths, tag value forwarding, and register `0x16` direct write.
3. `func_0021C810`: existing/null packet paths, 3-component bitfield packing, and register `0x3B` write.
4. `func_0021C8D0`: existing/null packet paths, 3-component bitfield packing, and register `0x4F` write.

### Red evidence
The Red baseline command executed against unchanged production source:
```sh
pytest tests/test_trade_action_helper_21C710.py tests/test_trade_action_helper_21C710_matching.py -v
```
Failed with 6 failures and 1 pass:
- 4 native tag assertion failures: `Assertion g_last_tag.words[0] == 0x00008000 failed` across all 4 functions.
- 1 matcher size failure: `func_0021C710 size mismatch: got 76, expected 128`.
- 1 matcher manifest failure: `expected 7 relocs in .rel.text, got 3`.
- 1 pass on initial original padding check.
Logged locally in `build/abi-21c710-red.log`. Note: `build/` is in `.gitignore`,
so local log files are untracked artifacts.

### Green evidence
After implementing `src/trade_action_helper_21C710.cpp`, all 7 tests passed with zero skips:
```sh
============================== 7 passed in 0.63s ===============================
```
Logged locally in `build/abi-21c710-green.log`.

## Mutation testing scope and caveats

Tests in `tests/test_trade_action_helper_21C710_matching.py` verify rejection
of corrupt manifests and padding:
- Code relocation mutation: altering an expected call relocation offset (e.g. `0x1C` -> `0x24`)
  raises `AssertionError: code relocation mismatch in func_0021C710`.
- Metadata relocation mutation: altering an expected `.rel.mwcats` symbol (e.g. to `D_WRONG_SYM`)
  raises `AssertionError: metadata relocation mismatch in func_0021C790`.
- Padding mutation: injecting a non-zero byte into `pad_c810`
  raises `AssertionError: pad_c810 not all zero`.
Caveat: these tests validate the strictness of the verification manifest and
boundary checks against corrupted inputs.
