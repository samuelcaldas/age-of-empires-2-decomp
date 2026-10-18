#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021DD10(void *obj, int a1);

// Original VRAM 0x21DE20 - 0x21DE84 (Size: 0x64 bytes; padding to 0x21DE90: 0x70 bytes)
// File Offset: 0x11E000 - 0x11E064 in orig/SLES-50282/AOK.ELF
// Callsite at 0x224F68 passes 3 arguments and ignores return value (void return).
// ELF Disassembly Trace:
// - Prologue at 0x21DE20: addiu sp, sp, -64, saves ra, s2, s1, s0.
// - Saves a0 into s2 (base pointer), a1 into s1 (base index), a2 into s0 (count).
// - Jumps to loop condition check at 0x21DE68.
// - For count == 0, falls through to epilogue without writing v0.
// - Loop body at 0x21DE44:
//     func_0021DD10(s2, s1);
//     s1++;
//     if ((idx & 0x0F) == 0) {
//         s2 += 0x400;
//     }
//     s0--;
// - Loops while s0 != 0.
// - Epilogue at 0x21DE70 - 0x21DE84: restores ra, s2, s1, s0, jr ra, and deallocates stack frame.
void func_0021DE20(void *base, int base_idx, int count) {
    char *ptr = (char *)base;
    int idx = base_idx;

    while (count != 0) {
        func_0021DD10(ptr, idx);
        idx++;
        if ((idx & 0x0F) == 0) {
            ptr += 0x400;
        }
        count--;
    }
}
}
