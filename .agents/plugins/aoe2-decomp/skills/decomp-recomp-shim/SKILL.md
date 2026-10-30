---
name: decomp-recomp-shim
description: Format decompiled C/C++ structures and YAML sidecars to ensure compatibility with native recompilation shims in aoe2-ps2-recomp.
---

# decomp-recomp-shim

Use this skill when preparing decompiled modules (especially KCET PS2 HAL layers in `src/kcet/`) to be consumed by the native recompilation project (`aoe2-ps2-recomp`).

## 1. Type and Layout Rules

1. **Named Structs with Layout Assertions:**
   Never leave raw byte offsets like `*(int *)(p + 108)`. Define a named `struct` and enforce layout:
   ```c
   struct FileRecord {
       u32 id;
       GuestAddr buffer;
       u32 size;
   };
   _Static_assert(sizeof(struct FileRecord) == 12, "FileRecord size mismatch");
   ```
2. **Fixed-Width Types:**
   Use `u8`, `u16`, `u32`, `s32`, `u64`.
   Guest 32-bit pointers must use `typedef u32 GuestAddr;` to avoid pointer truncation or expansion issues on 64-bit host machines.
3. **Symbolic References:**
   Replace raw hardware addresses (`0x4F1510`) with named externs (`D_4F1510`).
4. **Enums and Return Codes:**
   Define named constants/enums for return codes, states, and commands.

## 2. YAML Sidecar Documentation

Every decompiled module consumed by recomp requires a sidecar file at `docs/recomp/<module>.yaml` (e.g. `docs/recomp/kt_file.yaml`).

Format per function:
```yaml
module: kt_file
functions:
  func_00125A70:
    role: table_lookup      # table_lookup | disc_io | state_query | dispatch | kernel_wrapper | hw_access | pure_helper
    purity: memory_only     # memory_only | hardware | os_service | pure
    blocking: none          # none | waits_on:<event> (semaphore, RPC, vsync)
    args:
      - {name: key, type: s32}
      - {name: table, type: "RecordTable8*", note: "sorted by id"}
    returns:
      type: GuestAddr
      values: {0: "not found"}
    memory_effects: []
```
