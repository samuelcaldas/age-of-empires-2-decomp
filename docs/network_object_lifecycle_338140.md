# DirectPlay-compatible interface callback (`0x338140`)

The function invokes the callback from argument one with the strings at `0x492C50` and `0x4D20F0`, followed by `6` and `0`, then returns zero. Argument two has no observable effect. Native regression coverage is in `tests/native/network_object_lifecycle_3380e0_test.cpp`. The candidate has four relocations and matches 19 of 56 emitted bytes; its first difference is `0x338150`, where MWCC omits a register copy and shifts the function body. Exact matching is not established. The callback pointer is trusted without validation.
