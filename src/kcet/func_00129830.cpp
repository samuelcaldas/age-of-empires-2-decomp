/* Function: func_00129830 (0x00129830 - 0x001299A8)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
#ifndef NULL
#define NULL 0
#endif

extern "C" {

#if defined(__mips__)
asm void func_00129830(void) {
    .word 0x27bdef60 // addiu $sp, $sp, -0x10a0
    .word 0x3c02ffff // lui $v0, 0xffff
    .word 0xffbe1080 // sd $fp, 0x1080($sp)
    .word 0x27a3003f // addiu $v1, $sp, 0x3f
    .word 0xffb71070 // sd $s7, 0x1070($sp)
    .word 0x3442ffc0 // ori $v0, $v0, 0xffc0
    .word 0xffb61060 // sd $s6, 0x1060($sp)
    .word 0x24170001 // addiu $s7, $zero, 1
    .word 0xffb51050 // sd $s5, 0x1050($sp)
    .word 0x3c1e0049 // lui $fp, 0x49
    .word 0xffb41040 // sd $s4, 0x1040($sp)
    .word 0x3c150049 // lui $s5, 0x49
    .word 0xffb31030 // sd $s3, 0x1030($sp)
    .word 0x24140001 // addiu $s4, $zero, 1
    .word 0xffb21020 // sd $s2, 0x1020($sp)
    .word 0x00629824 // and $s3, $v1, $v0
    .word 0xffb11010 // sd $s1, 0x1010($sp)
    .word 0x00a0902d // move $s2, $a1
    .word 0xffbf1090 // sd $ra, 0x1090($sp)
    .word 0x0080882d // move $s1, $a0
    .word 0xffb01000 // sd $s0, 0x1000($sp)
    .word 0x1000000c // b 0x1298b8
    .word 0x24160002 // addiu $s6, $zero, 2
    .word 0x00000000 // nop 
    .word 0x0c04b6f8 // jal 0x12dbe0
    .word 0x0260202d // move $a0, $s3
    .word 0x10500020 // beq $v0, $s0, 0x12991c
    .word 0x00000000 // nop 
    .word 0x16200022 // bnez $s1, 0x12992c
    .word 0x0000202d // move $a0, $zero
    .word 0x10000004 // b 0x1298bc
    .word 0x00000000 // nop 
    .word 0x0c046378 // jal 0x118de0
    .word 0x00000000 // nop 
    .word 0x0000202d // move $a0, $zero
    .word 0x0c04b57c // jal 0x12d5f0
    .word 0x0240282d // move $a1, $s2
    .word 0x1454fffa // bne $v0, $s4, 0x1298b0
    .word 0x26a4f668 // addiu $a0, $s5, -0x998
    .word 0x0c04b6e0 // jal 0x12db80
    .word 0x0000202d // move $a0, $zero
    .word 0x10560003 // beq $v0, $s6, 0x1298e4
    .word 0x00000000 // nop 
    .word 0x1220fff7 // beqz $s1, 0x1298bc
    .word 0x0000202d // move $a0, $zero
    .word 0x0c04b6b2 // jal 0x12dac8
    .word 0x24100001 // addiu $s0, $zero, 1
    .word 0x10500003 // beq $v0, $s0, 0x1298fc
    .word 0x00000000 // nop 
    .word 0x1220fff1 // beqz $s1, 0x1298bc
    .word 0x0000202d // move $a0, $zero
    .word 0x16200003 // bnez $s1, 0x12990c
    .word 0x00000000 // nop 
    .word 0x0c04a53a // jal 0x1294e8
    .word 0x0000202d // move $a0, $zero
    .word 0x0c04b6e0 // jal 0x12db80
    .word 0x0000202d // move $a0, $zero
    .word 0x1660ffde // bnez $s3, 0x129890
    .word 0x00000000 // nop 
    .word 0x56200004 // bnel $s1, $zero, 0x129930
    .word 0x24100e10 // addiu $s0, $zero, 0xe10
    .word 0x0c04a53a // jal 0x1294e8
    .word 0x0000202d // move $a0, $zero
    .word 0x24100e10 // addiu $s0, $zero, 0xe10
    .word 0x0000202d // move $a0, $zero
    .word 0x0c040cd6 // jal 0x103358
    .word 0x2610ffff // addiu $s0, $s0, -1
    .word 0x0c04b68e // jal 0x12da38
    .word 0x00000000 // nop 
    .word 0x0040302d // move $a2, $v0
    .word 0x27c4f630 // addiu $a0, $fp, -0x9d0
    .word 0x24050007 // addiu $a1, $zero, 7
    .word 0x0c04a562 // jal 0x129588
    .word 0x24070001 // addiu $a3, $zero, 1
    .word 0x14400003 // bnez $v0, 0x129968
    .word 0x00000000 // nop 
    .word 0x10000003 // b 0x129970
    .word 0x0000b82d // move $s7, $zero
    .word 0x1e00fff2 // bgtz $s0, 0x129934
    .word 0x0000202d // move $a0, $zero
    .word 0x16e0ffd2 // bnez $s7, 0x1298bc
    .word 0x0000202d // move $a0, $zero
    .word 0xdfbf1090 // ld $ra, 0x1090($sp)
    .word 0xdfbe1080 // ld $fp, 0x1080($sp)
    .word 0xdfb71070 // ld $s7, 0x1070($sp)
    .word 0xdfb61060 // ld $s6, 0x1060($sp)
    .word 0xdfb51050 // ld $s5, 0x1050($sp)
    .word 0xdfb41040 // ld $s4, 0x1040($sp)
    .word 0xdfb31030 // ld $s3, 0x1030($sp)
    .word 0xdfb21020 // ld $s2, 0x1020($sp)
    .word 0xdfb11010 // ld $s1, 0x1010($sp)
    .word 0xdfb01000 // ld $s0, 0x1000($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd10a0 // addiu $sp, $sp, 0x10a0
}
#else

void func_12DBE0(void *);
void func_118de0(void);
int func_12D5F0(int, int);
int func_12DB80(int);
int func_12DAC8(int);
void func_001294E8(int);
void func_103358(int);
int func_12DA38(int);
int func_00129588(void *, int, int, int);

extern char D_0048F668[];
extern char D_0048F630[];

void func_00129830(int a0, int a1) {
    u8 buf[0x1000 + 0x40];
    u8 *aligned_buf = (u8 *)(((u32)buf + 0x3f) & ~0x3f);
    int flag = 1;

    while (1) {
        while (func_12D5F0(0, a1) != 1) {
            func_118de0();
        }

        if (func_12DB80(0) != 2 && a0 == 0) {
            continue;
        }

        if (func_12DAC8(0) != 1 && a0 == 0) {
            continue;
        }

        if (a0 == 0) {
            func_001294E8(0);
        }
        func_12DB80(0);

        if (aligned_buf != NULL) {
            func_12DBE0(aligned_buf);
        }

        int count = 3600;
        if (a0 == 0) {
            func_001294E8(0);
        }

        do {
            count--;
            func_103358(0);
            int v = func_12DA38(0);
            if (func_00129588(D_0048F630, 7, v, 1) == 0) {
                flag = 0;
                break;
            }
        } while (count > 0);

        if (flag == 0) {
            break;
        }
    }
}
#endif

}
