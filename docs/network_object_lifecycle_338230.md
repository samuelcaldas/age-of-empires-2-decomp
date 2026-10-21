# Object destructor-like reset (`0x338230`)

The function clears the joined flag at object offset 1308, calls `0x3381A0`, and returns the original object pointer. The target function code is 44 bytes, followed by 4 zero padding bytes. The 44 emitted function bytes match exactly, with one call relocation. The function trusts its object pointer and performs no bounds checks.
