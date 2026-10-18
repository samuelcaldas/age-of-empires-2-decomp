#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_123908(void *);
void *func_1046D0(void *obj, int reg, int arg2, int arg3, int t0, int t1, int t2, int t3);
void *func_21C050(void *obj, int mode);

// Original VRAM 0x21DD10 - 0x21DE10 (Size: 0x104 bytes, padding to 0x21DE20: 0x110 bytes)
// File Offset: 0x11DEF0 - 0x11DFF0 in orig/SLES-50282/AOK.ELF (padding to 0x11E000)
// ELF Disassembly Trace:
// - Prologue at 0x21DD10: addiu sp, sp, -96, saves ra, s3, s2, s1, s0.
// - Saves incoming a0 into s1, a1 into s3.
// - Call 1 at 0x21DD30: jal func_123908 with a0 = 0 (unconditional allocation).
// - Stores allocated packet pointer into s0.
// - Bit manipulation block (0x21DD3C - 0x21DD84) transforming s1 and s3 into s1, s2, s3 coordinates:
//     a1_masked = s3 & 0x0E
//     bit0 = s3 & 0x01
//     s1_val = s1 + (((bit0 << 5) + (a1_masked << 6)) & ~0x0F)
//     s2_val = ((s3 >> 6) << 5) + (s3 & 0x10) + (bit0 << 3)
//     s3_val = ((s3 >> 1) & 0x10) + a1_masked
// - Packet write 1 at 0x21DDB4:
//     func_1046D0(s0, 0x1F00, 0, 4, s1_val, 2, s2_val, s3_val)
// - Packet write 2 at 0x21DDE8:
//     func_1046D0(s0, 0x1F00, 0, 4, s1_val + 0x80, 2, s2_val, s3_val + 1)
// - Mode call at 0x21DDF0:
//     func_21C050(s0, 0x1F00)
// - Epilogue at 0x21DDF8 - 0x21DE10: restores ra, s3, s2, s1, s0, jr ra, and deallocates stack.
void *func_0021DD10(int a0, int a1, int a2, int a3, int a4) {
    (void)a2;
    (void)a3;
    (void)a4;

    void *packet = func_123908(0);

    int a1_masked = a1 & 0x0E;
    int v0_calc = ((a1_masked << 5) >> 1) << 2;
    int bit0 = a1 & 0x01;
    int v0_combined = (bit0 << 5) + v0_calc;
    int v0_aligned = (v0_combined >> 4) << 4;
    int s1_val = a0 + v0_aligned;

    int v0_bit0_shift = bit0 << 3;
    int v1_shift6 = a1 >> 6;
    int a0_bit4 = a1 & 0x10;
    int v1_scaled = (v1_shift6 << 5) + a0_bit4;
    int s2_val = v1_scaled + v0_bit0_shift;

    int v0_bit5_shift = (a1 >> 1) & 0x10;
    int s3_val = v0_bit5_shift + a1_masked;

    volatile int stack_sp_0 = 8;
    volatile int stack_sp_8 = 1;
    (void)stack_sp_0;
    (void)stack_sp_8;

    func_1046D0(packet, 0x1F00, 0, 4, s1_val, 2, s2_val, s3_val);
    func_1046D0(packet, 0x1F00, 0, 4, s1_val + 0x80, 2, s2_val, s3_val + 1);
    func_21C050(packet, 0x1F00);

    return packet;
}
}
