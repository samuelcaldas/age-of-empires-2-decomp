# Combat subsystem controller instance destructor at 0x3292A0

`func_003292A0` is reproduced in pure C++ in
`src/tactical_ai_combat_subsystem_controller_destructor.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches **104/104 instruction bytes (100.00%)**
after resolving relocations `D_004DED20` (R_MIPS_HI16/LO16), `func_32E820` (R_MIPS_26),
`func_318760` (R_MIPS_26), and `func_100670` (R_MIPS_26).

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x3292A0, 0x329308)`, file `[0x229480, 0x2294E8)`.
  The function spans 104 instruction bytes (`0x68`), followed by 8 bytes of
  alignment-padding nops up to `0x329310`. Symbol size is `0x68`.
- Stack frame: 48 bytes (`addiu $sp, $sp, -0x30`), saving `$ra` (0x20),
  `$s1` (0x10), and `$s0` (0x00) with 128-bit store instructions (`sq`).

## Observable behavior

1. Null check: if `self == nullptr`, return `nullptr` immediately without performing cleanup.
2. Install virtual method table: `self->m_vtable = D_004DED20`.
3. Member cleanup: invoke `func_32E820(self)`.
4. Base class destructor: invoke `func_318760(self, 0)`.
5. Conditional delete dispatch: if `(short)flags > 0`, invoke operator delete `func_100670(self)`.
6. Return `self` pointer.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q \
  tests/test_tactical_ai_combat_subsystem_controller_destructor.py \
  tests/test_tactical_ai_combat_subsystem_controller_destructor_matching.py
```

The focused test run comprises **9 passing tests, zero skips**:

- One 32-bit native contract process with UBSan and NDEBUG protection validating
  null guard, member cleanup, base destructor invocation, conditional delete dispatch,
  and return value.
- Seven production source mutations independently compiled and verified
  rejected with exact expected assertion diagnostics (inverted null check, omitted
  vtable installation, omitted member cleanup, omitted base destructor, corrupted base
  destructor flags argument, inverted delete flag check, omitted operator delete).
- One exact matching test compiling fresh with Ninja/MWCC and verifying
  100.00% byte-for-byte identity against the pinned ELF binary.
