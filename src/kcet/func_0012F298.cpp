#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void *func_0012F298(void *a0, s32 a1) {
    .word 0x27bdffb0 // 0012F298:  addiu $sp, $sp, -0x50
    .word 0xffb20020 // 0012F29C:  sd $s2, 0x20($sp)
    .word 0xffb10010 // 0012F2A0:  sd $s1, 0x10($sp)
    .word 0x00a0902d // 0012F2A4:  move $s2, $a1
    .word 0x0080882d // 0012F2A8:  move $s1, $a0
    .word 0xffb30030 // 0012F2AC:  sd $s3, 0x30($sp)
    .word 0xffbf0040 // 0012F2B0:  sd $ra, 0x40($sp)
    .word 0x0c04bb4a // 0012F2B4:  jal 0x12ed28
    .word 0xffb00000 // 0012F2B8:  sd $s0, ($sp)
    .word 0x0040982d // 0012F2BC:  move $s3, $v0
    .word 0x56600012 // 0012F2C0:  bnel $s3, $zero, 0x12f30c
    .word 0x8e260018 // 0012F2C4:  lw $a2, 0x18($s1)
    .word 0x3c100049 // 0012F2C8:  lui $s0, 0x49
    .word 0x0240202d // 0012F2CC:  move $a0, $s2
    .word 0x0c04b78a // 0012F2D0:  jal 0x12de28
    .word 0x26100288 // 0012F2D4:  addiu $s0, $s0, 0x288
    .word 0x0200202d // 0012F2D8:  move $a0, $s0
    .word 0x0040302d // 0012F2DC:  move $a2, $v0
    .word 0x0c046378 // 0012F2E0:  jal 0x118de0
    .word 0x0220282d // 0012F2E4:  move $a1, $s1
    .word 0x3c04004e // 0012F2E8:  lui $a0, 0x4e
    .word 0x3c050049 // 0012F2EC:  lui $a1, 0x49
    .word 0x3c070049 // 0012F2F0:  lui $a3, 0x49
    .word 0x24842d40 // 0012F2F4:  addiu $a0, $a0, 0x2d40
    .word 0x24a50068 // 0012F2F8:  addiu $a1, $a1, 0x68
    .word 0x24e702c8 // 0012F2FC:  addiu $a3, $a3, 0x2c8
    .word 0x0c048de4 // 0012F300:  jal 0x123790
    .word 0x24060664 // 0012F304:  addiu $a2, $zero, 0x664
    .word 0x8e260018 // 0012F308:  lw $a2, 0x18($s1)
    .word 0x0260202d // 0012F30C:  move $a0, $s3
    .word 0x0c04bc82 // 0012F310:  jal 0x12f208
    .word 0x0220282d // 0012F314:  move $a1, $s1
    .word 0x0040982d // 0012F318:  move $s3, $v0
    .word 0x16600012 // 0012F31C:  bnez $s3, 0x12f368
    .word 0x0260102d // 0012F320:  move $v0, $s3
    .word 0x3c100049 // 0012F324:  lui $s0, 0x49
    .word 0x0240202d // 0012F328:  move $a0, $s2
    .word 0x0c04b78a // 0012F32C:  jal 0x12de28
    .word 0x26100288 // 0012F330:  addiu $s0, $s0, 0x288
    .word 0x0200202d // 0012F334:  move $a0, $s0
    .word 0x0220282d // 0012F338:  move $a1, $s1
    .word 0x0c046378 // 0012F33C:  jal 0x118de0
    .word 0x0040302d // 0012F340:  move $a2, $v0
    .word 0x3c040049 // 0012F344:  lui $a0, 0x49
    .word 0x3c050049 // 0012F348:  lui $a1, 0x49
    .word 0x3c070049 // 0012F34C:  lui $a3, 0x49
    .word 0x248402e0 // 0012F350:  addiu $a0, $a0, 0x2e0
    .word 0x24a50068 // 0012F354:  addiu $a1, $a1, 0x68
    .word 0x24e702c8 // 0012F358:  addiu $a3, $a3, 0x2c8
    .word 0x0c048de4 // 0012F35C:  jal 0x123790
    .word 0x2406066a // 0012F360:  addiu $a2, $zero, 0x66a
    .word 0x0260102d // 0012F364:  move $v0, $s3
    .word 0xdfbf0040 // 0012F368:  ld $ra, 0x40($sp)
    .word 0xdfb30030 // 0012F36C:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012F370:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012F374:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012F378:  ld $s0, ($sp)
    .word 0x03e00008 // 0012F37C:  jr $ra
    .word 0x27bd0050 // 0012F380:  addiu $sp, $sp, 0x50
}
#else
void *func_0012ED28(void *a0, s32 a1);
u32 func_0012DE28(u32 a0);
int func_118de0(const char *fmt, ...);
void func_123790(const char *expr, const char *file, s32 line, const char *func);
void *func_0012F208(const char *name, void *arg1, s32 count);

extern const char D_490288[];
extern const char D_490068[];
extern const char D_4902C8[];
extern const char D_4E2D40[];
extern const char D_4902E0[];

struct HeaderStruct {
    char pad[0x18];
    s32 count;
};

void *func_0012F298(HeaderStruct *a0, s32 a1) {
    const char *name = (const char *)func_0012ED28(a0, a1);
    if (name == 0) {
        func_118de0(D_490288, a0, func_0012DE28(a1));
        func_123790(D_4E2D40, D_490068, 0x664, D_4902C8);
    }
    void *filedata = func_0012F208(name, a0, a0->count);
    if (filedata == 0) {
        func_118de0(D_490288, a0, func_0012DE28(a1));
        func_123790(D_4902E0, D_490068, 0x66A, D_4902C8);
    }
    return filedata;
}
#endif

}
