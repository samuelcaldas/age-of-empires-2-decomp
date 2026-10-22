# Object initializer (`0x3381A0`)

The function clears 1088 bytes at offset 4, 216 bytes at offset 1092, and 2048 bytes at offset 1324. It resets the lifecycle fields at offsets 0, 1312, 3372, 3376, 3380, 3384, 4412, 4540, 4544, 4552, 4556, and 4560; sets offset 1316 to one; and calls `0x338180`. Target extent is 144 bytes with four call relocations. The candidate matches 133 of 144 bytes; first difference is `0x338210`, where MWCC schedules the reset store in the call delay slot. The function trusts its object pointer and performs no bounds checks.
