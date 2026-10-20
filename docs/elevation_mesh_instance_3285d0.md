# Elevation mesh instance constructor at 0x3285D0

`func_003285D0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_elevation_mesh_instance.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **56/56 instruction bytes (100.00%)**
against the original ELF binary after resolving one `R_MIPS_26` call relocation
to base constructor `func_1A2C20` and two relocations (`R_MIPS_HI16` and
`R_MIPS_LO16`) to vtable `D_4DEBF0`.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x3285D0, 0x328608)`, file `[0x2287B0, 0x2287E8)`.
  The function spans 56 instruction bytes (0x38), followed by 8 bytes of
  alignment-padding nops up to `0x328610`. Symbol size is `0x38`.
- Stack frame: 32 bytes (`addiu $sp, $sp, -0x20`), saving `$ra` (0x10)
  and `$s0` (0x00).

## Observable behavior

1. Forward `this` pointer in `$a0` to base constructor `func_1A2C20`.
2. Install virtual method table: set `this->m_vtable = (void *)D_4DEBF0`.
3. Initialize instance state: set `this->m_field_DC = 0` (4 bytes at offset `0xDC`).
4. Return `this` pointer in `$v0`.

## Compatibility and alias retention

The symbol `func_3285d0 = 0x3285D0;` is actively referenced by callers such as
`tactical_ai_action_manager.cpp`. Both the sized canonical symbol
`func_003285D0` and the legacy un-prefixed alias `func_3285d0` are retained in
`config/SLES-50282/symbols.txt`.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_instance.py \
  tests/test_tactical_ai_combat_subsystem_elevation_mesh_instance_matching.py
```

The focused test run comprises **6 passing tests, zero skips**:
- One 32-bit native contract test with UBSan validating base constructor
  forwarding, vtable installation, field zeroing, and `this` return value.
- Four production source mutations independently compiled and verified
  rejected (omitted base ctor, omitted vtable, corrupted field DC, wrong return).
- One matching test compiling fresh with Ninja/MWCC and verifying 100.00%
  byte-for-byte identity against the pinned ELF binary.

The WIP/BIN boundary and registered object list remain unchanged.
