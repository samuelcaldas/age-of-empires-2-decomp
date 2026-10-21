# Network object lifecycle functions

These functions expose a DirectPlay-compatible object and reset its lifecycle state. Analysis uses the original `SLES-50282` ELF at `0x3380E0` through `0x33825C`.

## `0x3380E0`

Stores the singleton object address through the second argument. If the one-byte initialization guard is zero, calls the object initializer, then increments the guard. Returns zero. Candidate extent is 72 bytes against the 96-byte target extent. Its global guard reference emits an unsupported out-of-range `GPREL16` relocation in the exact-match helper; matching is blocked.

## `0x338140`

Calls the callback passed as the first argument with the strings at `0x492C50` and `0x4D20F0`, integer arguments `6` and `0`, then returns zero. The second argument does not affect observable behavior. Current C++ implementation is not an exact match; emitted extent is shorter than the verified 64-byte target extent.

## `0x338180`

Returns without using its object argument. Its function code is 8 bytes; the following 8 bytes are zero alignment padding before the next function. The C++ bytes match the 8-byte function.

## `0x3381A0`

Clears 1088 bytes at object offset 4, 216 bytes at offset 1092, and 2048 bytes at offset 1324. It clears the remaining lifecycle fields at offsets 0, 1312, 3372, 3376, 3380, 3384, 4412, 4540, 4544, 4552, 4556, and 4560; sets offset 1316 to one; and calls `0x338180`. Target extent is 144 bytes. Matching remains unverified.

## `0x338230`

Clears the joined flag at offset 1308, calls the initializer, and returns the object pointer. Target extent is 48 bytes. Matching remains unverified.

## Evidence and limits

Native regression command: `.venv/bin/python -m pytest -q -ra tests/test_network_object_lifecycle_3380e0_native.py` (passed). The first exact-match attempts found emitted extents of 72/96, 56/64, 8/16, and 44/48 bytes; the initializer also initially resolved its local helper instead of an external relocation. No claim of exact binary matching is made. The observed lifecycle code trusts its object and output pointers; it performs no null or bounds checks.
