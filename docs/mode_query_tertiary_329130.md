# Mode query tertiary at 0x329130

`func_00329130` is reproduced in pure C++ in
`src/mode_query_tertiary_329130.cpp`.
A fresh MWCC PS2 2.3.1.01 build matches instruction bytes against the original ELF binary.

## Reference boundaries and layout

- Target: PS2 PAL `SLES-50282`, original `AOK.ELF` SHA-1
  `f478e19f2059d52899b691483ef5c7522e30e17c`.
- Function: VRAM `[0x329130, 0x3291E4)`, size 180 bytes (`0xB4`).
- Stack frame: 64 bytes (`addiu $sp, $sp, -0x40`), saving registers.

## Observable behavior

1. Null descriptor check: if `self == nullptr`, return `-1`.
2. Active state check: if `self->m_active == 0`, return `0`.
3. Parameter assignment: update `m_field_8` and `m_field_C`.
4. Manager notification: if `self->m_manager` is present, invoke manager notification callback at vtable offset `0x18`.
5. Return sum of `m_field_8` and `m_field_C`.

## Reproducible verification

Run in the `docker-dev` verification image:

```sh
python -m pytest -q tests/test_mode_query_tertiary_329130.py
```

The focused test run comprises **3 passing tests, zero skips**.
