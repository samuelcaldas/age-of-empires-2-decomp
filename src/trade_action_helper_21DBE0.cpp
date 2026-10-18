#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);

// Original VRAM 0x21DBE0 - 0x21DC50
// ELF Evidence:
// - Prologue at 0x21DBE0: addiu sp, sp, -48, saves ra and s0.
// - Call at 0x21DC28 (jal 0x1046D0): passes obj (a0), reg = 0x1F00 (a1, loaded via li a1, 0x1F00 at 0x21DC14), and data derived from a2.
// - Call at 0x21DC30 (jal 0x21C050): passes obj (a0) and mode derived from a3.
// - Epilogue at 0x21DC38: restores ra, s0, deallocates stack, and returns obj.
void *func_0021DBE0(void *obj, int a1, int a2, int a3) {
    if (obj == 0) {
        return 0;
    }
    // Call 1: func_1046D0 with fixed register 0x1F00 and argument a2 (ELF offset 0x21DC28)
    func_1046D0(obj, 0x1F00, (unsigned long long)(unsigned int)a2);

    // Call 2: func_21C050 with argument a3 (ELF offset 0x21DC30)
    func_21C050(obj, a3);

    return obj;
}
}
