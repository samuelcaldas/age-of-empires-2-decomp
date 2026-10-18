#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021DC50(void *obj, int a1);

// Original VRAM 0x21DCA0 - 0x21DD08 (Size: 0x68 bytes; padding to 0x21DD10: 0x70 bytes)
// File Offset: 0x11DE80 - 0x11DEE8 in orig/SLES-50282/AOK.ELF
// Callsite at 0x224F38 passes 3 arguments: a0 (base), a1 (base_idx), a2 (count).
// ELF Disassembly Trace:
// - Prologue at 0x21DCA0: addiu sp, sp, -80, saves ra, s3, s2, s1, s0.
// - Saves a0 into s3 (base pointer), a1 into s2 (base index), a2 into s1 (count).
// - Jumps to loop condition check at 0x21DCE0 with s0 = 0 (loop index) in delay slot.
// - Loop body at 0x21DCD0: calls 2-argument func_0021DC50(s3, s2 + s0), increments s0++, advances s3 += 0x400.
// - Loops while s0 < s1.
// - Epilogue at 0x21DCEC - 0x21DD04: restores ra, s3, s2, s1, s0, jr ra, and deallocates stack frame.
void *func_0021DCA0(void *base, int base_idx, int count) {
    char *ptr = (char *)base;
    void *last_result = 0;
    for (int i = 0; i < count; ++i) {
        last_result = func_0021DC50(ptr, base_idx + i);
        ptr += 0x400;
    }
    return last_result;
}
}
