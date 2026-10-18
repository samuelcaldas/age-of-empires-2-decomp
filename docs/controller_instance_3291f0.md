# Combat subsystem controller instance constructor at 0x3291F0

`func_003291F0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_instance.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **164/164 instruction bytes (100.00%)**
after resolving relocations `func_318340` (R_MIPS_26) and `D_004DED20` (R_MIPS_HI16/LO16).

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x3291F0, 0x329294)`, file `[0x2293D0, 0x229474)`.
  The function spans 164 instruction bytes (`0xA4`), followed by 12 bytes of
  alignment-padding nops up to `0x3292A0`. Symbol size is `0xA4`.
- Stack frame: 32 bytes (`addiu $sp, $sp, -0x20`), saving `$ra` (0x10)
  and `$s0` (0x00) with 128-bit store instructions (`sq`).

## Observable behavior

1. Invoke base class constructor: `func_318340(self)`.
2. Install virtual method table: `self->m_vtable = D_004DED20`.
3. Initialize scalar instance fields:
   - `m_field_DC = 10`
   - `m_field_3408 = 0`, `m_field_340C = 0`, `m_field_3410 = 0`
   - `m_field_3414 = -1`, `m_field_3418 = -1`
   - `m_field_341C = 1`
   - `m_field_3420 = 0`, `m_field_3424 = 0`, `m_field_3428 = 0`, `m_field_342C = 0`, `m_field_3430 = 0`
4. Reset 10-slot tracking tables:
   - For `i = 0..9`: `m_field_3434[i] = 0`, `m_field_345C[i] = -1`
5. Initialize trailing attributes:
   - `m_field_3484 = 0`
   - `m_field_2398 = 41` (0x29)
6. Return `self` pointer.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_instance.py \
  tests/test_tactical_ai_combat_subsystem_controller_instance_matching.py
```

The focused test run comprises **9 passing tests, zero skips**:

- One 32-bit native contract process with UBSan and NDEBUG protection validating
  base constructor invocation, vtable installation, scalar fields, slot table reset,
  and return value.
- Seven production source mutations independently compiled and verified
  rejected with exact expected assertion diagnostics (omitted base call, corrupted
  vtable pointer, corrupted field DC, corrupted field 2398, corrupted scalar flag
  field 341C, corrupted zero table entry, corrupted negative table entry).
- One exact matching test compiling fresh with Ninja/MWCC and verifying
  100.00% byte-for-byte identity against the pinned ELF binary.
