#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);

// Original VRAM 0x21DBE0 - 0x21DC48 (Size 0x68 bytes, end-exclusive)
// ELF Disassembly Trace:
// - Prologue at 0x21DBE0: addiu sp, sp, -48, saves ra (32(sp)) and s0 (16(sp)).
// - Local stack setup (0x21DBEC - 0x21DC24): stores 16 at sp+0 and sp+8, performs bitwise/shift operations on a2.
// - Call at 0x21DC28 (jal 0x1046D0): passes obj (a0), reg = 0x1F00 (a1), and data derived from a2.
// - Call at 0x21DC30 (jal 0x21C050): passes obj (a0) and mode a3.
// - Epilogue at 0x21DC38 - 0x21DC44: restores ra, s0, jr ra, and deallocates stack frame in delay slot.
void *func_0021DBE0(void *obj, int a1, int a2, int a3) {
    if (obj == 0) {
        return 0;
    }

    // Local work variables modeling stack frame spills (sp+0 = 16, sp+8 = 16)
    volatile int local_sp_0 = 16;
    volatile int local_sp_8 = 16;
    (void)local_sp_0;
    (void)local_sp_8;

    // Derived register value and parameter handling
    unsigned long long reg_data = (unsigned long long)(unsigned int)a2;

    // Call 1: func_1046D0 with fixed register 0x1F00 and argument a2 (ELF offset 0x21DC28)
    func_1046D0(obj, 0x1F00, reg_data);

    // Call 2: func_21C050 with argument a3 (ELF offset 0x21DC30)
    func_21C050(obj, a3);

    return obj;
}
}
