#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_123908(void *);
void *func_0021DBE0(void *obj, int a1, int a2, int a3);

// Original VRAM 0x21DC50 - 0x21DC94 (Size: 0x44 bytes, padding to 0x21DCA0)
// File Offset: 0x11DE30 - 0x11DE74 in orig/SLES-50282/AOK.ELF
// ELF Disassembly Trace:
// - Prologue at 0x21DC50: addiu sp, sp, -48, saves ra, s1, s0.
// - Saves incoming arguments a0 and a1 into s1 and s0 at 0x21DC60-0x21DC64.
// - Call 1 at 0x21DC68 (jal func_123908): delay slot at 0x21DC6C clears a0 (paddub a0, zero, zero), passing 0.
// - Argument setup at 0x21DC70-0x21DC74: a1 = s1 (input a0), a2 = s0 (input a1).
// - Call 2 at 0x21DC78 (jal func_21DBE0): delay slot at 0x21DC7C forwards v0 (allocated obj from func_123908) in a0.
// - Epilogue at 0x21DC80-0x21DC90: restores ra, s1, s0, jr ra, and deallocates stack frame.
// - Returns result of func_0021DBE0 (unconditional execution, no null check).
void *func_0021DC50(void *a0, int a1, int a2, int a3) {
    (void)a2;
    (void)a3;
    void *packet = func_123908(0);
    return func_0021DBE0(packet, (int)(unsigned long)a0, a1, a3);
}
}
