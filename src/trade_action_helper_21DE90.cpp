#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4);
void *func_221B60(void *obj);
void *func_221AC0(void *obj);

// Original VRAM 0x21DE90 - 0x21DF48 (Size: 0xC0 bytes / 192 bytes, end-exclusive)
// File Offset: 0x11E070 - 0x11E130 in orig/SLES-50282/AOK.ELF
// ELF Disassembly Trace:
// - Prologue at 0x21DE90: addiu sp, sp, -160, saves ra, s7..s0.
// - Saves incoming arguments a0..t3 into s6..s0, s7.
// - Call 1 at 0x21DED8: jal func_221B60 with a0 = 0xC (in delay slot at 0x21DEBC).
// - Prepares sign-extended (short) parameters a1, a2, a3, forwards t0..t3, and stores s7 on stack 0(sp).
// - Call 2 at 0x21DF0C: jal func_0021DF50 with a0 = v0 (buffer allocated by func_221B60).
// - Call 3 at 0x21DF14: jal func_221B60 with a0 = 0x100 (in delay slot at 0x21DF18).
// - Call 4 at 0x21DF1C: jal func_221AC0.
// - Epilogue at 0x21DF24 - 0x21DF4C: restores ra, s7..s0, jr ra, and deallocates stack frame.
// - Returns result of func_0021DF50 (unconditional execution, no null check).
void *func_0021DE90(void *obj, int a1, int a2, int a3, int a4, int t0, int t1, int t2, int t3) {
    (void)t0;
    (void)t1;
    (void)t2;
    (void)t3;

    void *buf = func_221B60((void *)0xC);

    short s_a0 = (short)(unsigned long)obj;
    short s_a1 = (short)a1;
    short s_a2 = (short)a2;

    func_0021DF50(buf, (int)s_a0, (int)s_a1, (int)s_a2, a3);
    func_221B60((void *)0x100);
    func_221AC0(buf);

    return buf;
}
}
