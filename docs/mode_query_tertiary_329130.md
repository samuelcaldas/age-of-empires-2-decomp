# Mode query tertiary at 0x329130

`func_00329130` is reproduced in pure C++ in
`src/mode_query_tertiary_329130.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **180/180 instruction bytes (100.00%)**
after resolving three relocations (`D_004E2EA0`, `func_1A5010`, `D_004E3180`).

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x329130, 0x3291E4)`, file `[0x229310, 0x2293C4)`.
  The function spans 180 instruction bytes (`0xB4`). Symbol size is `0xB4`.
- Stack frame: 64 bytes (`addiu $sp, $sp, -0x40`), saving `$ra` (0x20),
  `$s1` (0x10), and `$s0` (0x00) with 128-bit store instructions (`sq`).
- Local variables: `short x` at `0x3C($sp)`, `short y` at `0x3E($sp)`, and
  `int extra` at `0x38($sp)`.

## Observable behavior

1. Guard clause: if global `D_004E2EA0` is null, return 0 immediately.
2. Invoke `func_1A5010(self, a1, a2, &x, &y, &extra)` to extract coordinates.
3. If query extraction succeeds:
   - Access secondary subsystem pointer at `self + 0x120`.
   - Invoke virtual query method at vtable offset `0xB8`:
     `mgr->query(0, (float)x + 0.5f, (float)y + 0.5f)`.
   - Mask result to 8-bit unsigned char.
4. Notify global context: invoke virtual method at vtable offset `0x18`:
   `((GlobalContextNotify *)D_004E3180)->notify(0, 0)`.
5. Return query result (0 if query extraction failed).

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_mode_query_tertiary_329130.py \
  tests/test_mode_query_tertiary_329130_matching.py
```

The focused test run comprises **9 passing tests, zero skips**:

- One 32-bit native contract process with UBSan validating null global guard,
  rejected query execution, active query dispatch with 0.5f float offsets,
  return value masking, and global notification contracts.
- Seven production source mutations independently compiled and verified
  rejected with exact expected assertion diagnostics (inverted global guard,
  inverted query condition, corrupted float coordinate offset, corrupted
  mask, omitted global notification, corrupted notification argument,
  corrupted return value).
- One exact matching test compiling fresh with Ninja/MWCC and verifying
  100.00% byte-for-byte identity against the pinned ELF binary.
