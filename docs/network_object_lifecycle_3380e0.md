# Network object lifecycle functions

These functions expose a DirectPlay-compatible object and reset its lifecycle state. Analysis uses the original `SLES-50282` ELF at `0x3380E0` through `0x33825C`.

## `0x3380E0`

Stores the singleton object address through the second argument. If the one-byte initialization guard is zero, calls the object initializer, then increments the guard. Returns zero. Candidate emits 72 bytes against the 84-byte function extent plus 12 zero padding bytes. Its global guard reference emits an unsupported out-of-range `GPREL16` relocation in the exact-match helper; matching is blocked.

## `0x338140`

Calls the callback passed as the first argument with the strings at `0x492C50` and `0x4D20F0`, integer arguments `6` and `0`, then returns zero. The second argument does not affect observable behavior. Candidate emits 56 bytes against the 60-byte function extent plus 4 zero padding bytes. It matches 19 of 56 candidate bytes; the first difference is `0x338150`.

## `0x338180`

Returns without using its object argument. Its function code is 8 bytes; the following 8 bytes are zero alignment padding before the next function. The C++ bytes match the 8-byte function.

## `0x3381A0`

Clears 1088 bytes at object offset 4, 216 bytes at offset 1092, and 2048 bytes at offset 1324. It clears the remaining lifecycle fields at offsets 0, 1312, 3372, 3376, 3380, 3384, 4412, 4540, 4544, 4552, 4556, and 4560; sets offset 1316 to one; and calls `0x338180`. Target function extent is 144 bytes with four call relocations. Candidate matches 133/144 bytes; first difference is `0x338210`.

## `0x338230`

Clears the joined flag at offset 1308, calls the initializer, and returns the object pointer. The function extent is 44 bytes, followed by 4 zero padding bytes. Candidate function bytes match exactly with one call relocation.

## Evidence and limits

Native regression command: `.venv/bin/python -m pytest -q -ra tests/test_network_object_lifecycle_3380e0_native.py` (passed). The first exact-match attempts found emitted extents of 72/96, 56/64, 8/16, and 44/48 bytes; the initializer also initially resolved its local helper instead of an external relocation. No claim of exact binary matching is made. The observed lifecycle code trusts its object and output pointers; it performs no null or bounds checks.
