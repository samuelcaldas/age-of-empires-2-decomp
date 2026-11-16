/* Function: func_0012C128 (0x0012C128 - 0x0012C1CC)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012C128(s32 a0, s32 a1, void *a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3) {
    .word 0x27bdff60 // 0012C128:  addiu $sp, $sp, -0xa0
    .word 0xffb10020 // 0012C12C:  sd $s1, 0x20($sp)
    .word 0xffb00010 // 0012C130:  sd $s0, 0x10($sp)
    .word 0x0080882d // 0012C134:  move $s1, $a0
    .word 0x00c0802d // 0012C138:  move $s0, $a2
    .word 0xffb70080 // 0012C13C:  sd $s7, 0x80($sp)
    .word 0xffb60070 // 0012C140:  sd $s6, 0x70($sp)
    .word 0x0160b82d // 0012C144:  move $s7, $t3
    .word 0xffb50060 // 0012C148:  sd $s5, 0x60($sp)
    .word 0x0140b02d // 0012C14C:  move $s6, $t2
    .word 0xffb40050 // 0012C150:  sd $s4, 0x50($sp)
    .word 0x0120a82d // 0012C154:  move $s5, $t1
    .word 0xffb30040 // 0012C158:  sd $s3, 0x40($sp)
    .word 0x0100a02d // 0012C15C:  move $s4, $t0
    .word 0xffb20030 // 0012C160:  sd $s2, 0x30($sp)
    .word 0x00e0982d // 0012C164:  move $s3, $a3
    .word 0x00a0902d // 0012C168:  move $s2, $a1
    .word 0xffbf0090 // 0012C16C:  sd $ra, 0x90($sp)
    .word 0x0c04afb0 // 0012C170:  jal 0x12bec0
    .word 0x0200202d // 0012C174:  move $a0, $s0
    .word 0x0220202d // 0012C178:  move $a0, $s1
    .word 0x0240282d // 0012C17C:  move $a1, $s2
    .word 0x0200302d // 0012C180:  move $a2, $s0
    .word 0x0260382d // 0012C184:  move $a3, $s3
    .word 0x0280402d // 0012C188:  move $t0, $s4
    .word 0x02a0482d // 0012C18C:  move $t1, $s5
    .word 0x02c0502d // 0012C190:  move $t2, $s6
    .word 0x02e0582d // 0012C194:  move $t3, $s7
    .word 0x0c04b01a // 0012C198:  jal 0x12c068
    .word 0xafa20000 // 0012C19C:  sw $v0, ($sp)
    .word 0xdfbf0090 // 0012C1A0:  ld $ra, 0x90($sp)
    .word 0xdfb70080 // 0012C1A4:  ld $s7, 0x80($sp)
    .word 0xdfb60070 // 0012C1A8:  ld $s6, 0x70($sp)
    .word 0xdfb50060 // 0012C1AC:  ld $s5, 0x60($sp)
    .word 0xdfb40050 // 0012C1B0:  ld $s4, 0x50($sp)
    .word 0xdfb30040 // 0012C1B4:  ld $s3, 0x40($sp)
    .word 0xdfb20030 // 0012C1B8:  ld $s2, 0x30($sp)
    .word 0xdfb10020 // 0012C1BC:  ld $s1, 0x20($sp)
    .word 0xdfb00010 // 0012C1C0:  ld $s0, 0x10($sp)
    .word 0x03e00008 // 0012C1C4:  jr $ra
    .word 0x27bd00a0 // 0012C1C8:  addiu $sp, $sp, 0xa0
}
#else

void *func_0012BEC0(void *a0);
s32 func_0012C068(s32 a0, s32 a1, void *a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, void *req);

s32 func_0012C128(s32 a0, s32 a1, void *a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3) {
    void *req = func_0012BEC0(a2);
    return func_0012C068(a0, a1, a2, a3, t0, t1, t2, t3, req);
}

#endif

}
