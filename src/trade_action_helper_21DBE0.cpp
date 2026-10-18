#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);

// Original VRAM 0x21DBE0 - 0x21DC48 (Size 0x68 bytes, end-exclusive)
// ELF Disassembly Trace & Reviewer Corrections:
// - Prologue at 0x21DBE0: addiu sp, sp, -48, saves ra (32(sp)) and s0 (16(sp)).
// - Local stack setup & register loading (0x21DBEC - 0x21DC24): loads 0x1F00 into a1 at 0x21DC14.
// - Call 1 at 0x21DC28 (jal 0x1046D0): delay slot at 0x21DC2C clears a2 (paddub a2, zero, zero), passing data = 0.
// - Call 2 at 0x21DC30 (jal 0x21C050): passes obj (a0) and mode a3 (a1 remains 0x1F00).
// - Epilogue at 0x21DC38 - 0x21DC44: restores ra, s0, jr ra, and deallocates stack frame in delay slot.
void *func_0021DBE0(void *obj, int a1, int a2, int a3) {
    if (obj == 0) {
        return 0;
    }

    // Local work variables modeling stack frame spills
    volatile int local_sp_0 = 16;
    volatile int local_sp_8 = 16;
    (void)local_sp_0;
    (void)local_sp_8;
    (void)a1;
    (void)a2;

    // Call 1: func_1046D0 with fixed register 0x1F00 and data = 0 (cleared by delay slot at 0x21DC2C)
    func_1046D0(obj, 0x1F00, 0ULL);

    // Call 2: func_21C050 with argument a3 (ELF offset 0x21DC30)
    func_21C050(obj, a3);

    return obj;
}
}
