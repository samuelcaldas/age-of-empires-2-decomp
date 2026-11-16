/* Function: func_0012BA68 (0x0012BA68 - 0x0012BB1C)
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
asm void func_0012BA68(void *a0, void *a1) {
    .word 0x27bdffc0 // 0012BA68:  addiu $sp, $sp, -0x40
    .word 0x3c02004f // 0012BA6C:  lui $v0, 0x4f
    .word 0xffb20020 // 0012BA70:  sd $s2, 0x20($sp)
    .word 0xffb10010 // 0012BA74:  sd $s1, 0x10($sp)
    .word 0x00a0902d // 0012BA78:  move $s2, $a1
    .word 0xffb00000 // 0012BA7C:  sd $s0, ($sp)
    .word 0x2451d300 // 0012BA80:  addiu $s1, $v0, -0x2d00
    .word 0x0080802d // 0012BA84:  move $s0, $a0
    .word 0xffbf0030 // 0012BA88:  sd $ra, 0x30($sp)
    .word 0x2405006c // 0012BA8C:  addiu $a1, $zero, 0x6c
    .word 0x0c0450f0 // 0012BA90:  jal 0x1143c0
    .word 0x0220202d // 0012BA94:  move $a0, $s1
    .word 0x24020001 // 0012BA98:  addiu $v0, $zero, 1
    .word 0x0200202d // 0012BA9C:  move $a0, $s0
    .word 0xae220008 // 0012BAA0:  sw $v0, 8($s1)
    .word 0x0c04ae7e // 0012BAA4:  jal 0x12b9f8
    .word 0xae200004 // 0012BAA8:  sw $zero, 4($s1)
    .word 0x2405ffff // 0012BAAC:  addiu $a1, $zero, -1
    .word 0x0000202d // 0012BAB0:  move $a0, $zero
    .word 0x26230034 // 0012BAB4:  addiu $v1, $s1, 0x34
    .word 0xac650000 // 0012BAB8:  sw $a1, ($v1)
    .word 0x24840001 // 0012BABC:  addiu $a0, $a0, 1
    .word 0x24630004 // 0012BAC0:  addiu $v1, $v1, 4
    .word 0x2c820002 // 0012BAC4:  sltiu $v0, $a0, 2
    .word 0x00000000 // 0012BAC8:  nop 
    .word 0x1440fffa // 0012BACC:  bnez $v0, 0x12bab8
    .word 0x00000000 // 0012BAD0:  nop 
    .word 0x2402ffff // 0012BAD4:  addiu $v0, $zero, -1
    .word 0xae22003c // 0012BAD8:  sw $v0, 0x3c($s1)
    .word 0xae22004c // 0012BADC:  sw $v0, 0x4c($s1)
    .word 0xae220040 // 0012BAE0:  sw $v0, 0x40($s1)
    .word 0xae220044 // 0012BAE4:  sw $v0, 0x44($s1)
    .word 0x0c04ab7e // 0012BAE8:  jal 0x12adf8
    .word 0xae220048 // 0012BAEC:  sw $v0, 0x48($s1)
    .word 0x0c04ab40 // 0012BAF0:  jal 0x12ad00
    .word 0x00000000 // 0012BAF4:  nop 
    .word 0x0c04aada // 0012BAF8:  jal 0x12ab68
    .word 0x00000000 // 0012BAFC:  nop 
    .word 0x0240202d // 0012BB00:  move $a0, $s2
    .word 0xdfbf0030 // 0012BB04:  ld $ra, 0x30($sp)
    .word 0xdfb20020 // 0012BB08:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012BB0C:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012BB10:  ld $s0, ($sp)
    .word 0x0804ae2a // 0012BB14:  j 0x12b8a8
    .word 0x27bd0040 // 0012BB18:  addiu $sp, $sp, 0x40
}
#else

struct CdvdServerData {
    u8 pad0[4];
    s32 f_4;
    s32 f_8;
    u8 padC[0x28];
    s32 f_34[2];
    s32 f_3c;
    s32 f_40;
    s32 f_44;
    s32 f_48;
    s32 f_4c;
};

extern CdvdServerData D_004ED300;

void *func_001143C0(void *dst, s32 size);
void *func_0012B9F8(void *a0);
void *func_0012ADF8(void);
void *func_0012AD00(void);
void *func_0012AB68(void);
void *func_0012B648(void *a0);

void *func_0012BA68(void *a0, void *a1) {
    func_001143C0(&D_004ED300, 0x6c);
    D_004ED300.f_8 = 1;
    D_004ED300.f_4 = 0;
    func_0012B9F8(a0);
    for (u32 i = 0; i < 2; i++) {
        D_004ED300.f_34[i] = -1;
    }
    D_004ED300.f_3c = -1;
    D_004ED300.f_4c = -1;
    D_004ED300.f_40 = -1;
    D_004ED300.f_44 = -1;
    D_004ED300.f_48 = -1;
    func_0012ADF8();
    func_0012AD00();
    func_0012AB68();
    return func_0012B648(a1);
}

#endif

}
