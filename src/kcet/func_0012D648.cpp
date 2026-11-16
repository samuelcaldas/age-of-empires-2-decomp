/* Function: func_0012D648 (0x0012D648 - 0x0012D7E0)
 * Origin: SLES-50282, KCET kt_sound / kt_file module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" {

#if defined(__mips__)
asm void func_0012D648(void) {
    .word 0x27bdffd0 // 0012D648:  addiu $sp, $sp, -0x30
    .word 0x838284e9 // 0012D64C:  lb $v0, -0x7b17($gp)
    .word 0xffbf0020 // 0012D650:  sd $ra, 0x20($sp)
    .word 0xffb10010 // 0012D654:  sd $s1, 0x10($sp)
    .word 0x1440005c // 0012D658:  bnez $v0, 0x12d7cc
    .word 0xffb00000 // 0012D65C:  sd $s0, ($sp)
    .word 0xff808848 // 0012D660:  sd $zero, -0x77b8($gp)
    .word 0x0000182d // 0012D664:  move $v1, $zero
    .word 0x3c04000f // 0012D668:  lui $a0, 0xf
    .word 0x3484ffff // 0012D66C:  ori $a0, $a0, 0xffff
    .word 0x64630001 // 0012D670:  daddiu $v1, $v1, 1
    .word 0xff838848 // 0012D674:  sd $v1, -0x77b8($gp)
    .word 0x0083102a // 0012D678:  slt $v0, $a0, $v1
    .word 0x00000000 // 0012D67C:  nop 
    .word 0x00000000 // 0012D680:  nop 
    .word 0x1040fffa // 0012D684:  beqz $v0, 0x12d670
    .word 0x00000000 // 0012D688:  nop 
    .word 0x0000202d // 0012D68C:  move $a0, $zero
    .word 0x0c041d72 // 0012D690:  jal 0x1075c8
    .word 0x3c110049 // 0012D694:  lui $s1, 0x49
    .word 0x3c02004f // 0012D698:  lui $v0, 0x4f
    .word 0x1000000e // 0012D69C:  b 0x12d6d8
    .word 0x24501640 // 0012D6A0:  addiu $s0, $v0, 0x1640
    .word 0x00000000 // 0012D6A4:  nop 
    .word 0x0000182d // 0012D6A8:  move $v1, $zero
    .word 0x3c04000f // 0012D6AC:  lui $a0, 0xf
    .word 0x3484ffff // 0012D6B0:  ori $a0, $a0, 0xffff
    .word 0x00000000 // 0012D6B4:  nop 
    .word 0x64630001 // 0012D6B8:  daddiu $v1, $v1, 1
    .word 0x0083102a // 0012D6BC:  slt $v0, $a0, $v1
    .word 0x00000000 // 0012D6C0:  nop 
    .word 0x00000000 // 0012D6C4:  nop 
    .word 0x00000000 // 0012D6C8:  nop 
    .word 0x1040fffa // 0012D6CC:  beqz $v0, 0x12d6b8
    .word 0x00000000 // 0012D6D0:  nop 
    .word 0xff838848 // 0012D6D4:  sd $v1, -0x77b8($gp)
    .word 0x0200202d // 0012D6D8:  move $a0, $s0
    .word 0x24050020 // 0012D6DC:  addiu $a1, $zero, 0x20
    .word 0x0c041f0e // 0012D6E0:  jal 0x107c38
    .word 0x0000302d // 0012D6E4:  move $a2, $zero
    .word 0x04430004 // 0012D6E8:  bgezl $v0, 0x12d6fc
    .word 0x8e020024 // 0012D6EC:  lw $v0, 0x24($s0)
    .word 0x0c046378 // 0012D6F0:  jal 0x118de0
    .word 0x2624ff08 // 0012D6F4:  addiu $a0, $s1, -0xf8
    .word 0x8e020024 // 0012D6F8:  lw $v0, 0x24($s0)
    .word 0x5040ffea // 0012D6FC:  beql $v0, $zero, 0x12d6a8
    .word 0xff808848 // 0012D700:  sd $zero, -0x77b8($gp)
    .word 0x0c0413e8 // 0012D704:  jal 0x104fa0
    .word 0x0000202d // 0012D708:  move $a0, $zero
    .word 0xff808848 // 0012D70C:  sd $zero, -0x77b8($gp)
    .word 0x3c04000f // 0012D710:  lui $a0, 0xf
    .word 0x3484ffff // 0012D714:  ori $a0, $a0, 0xffff
    .word 0x0000182d // 0012D718:  move $v1, $zero
    .word 0x00000000 // 0012D71C:  nop 
    .word 0x64630001 // 0012D720:  daddiu $v1, $v1, 1
    .word 0xff838848 // 0012D724:  sd $v1, -0x77b8($gp)
    .word 0x0083102a // 0012D728:  slt $v0, $a0, $v1
    .word 0x00000000 // 0012D72C:  nop 
    .word 0x00000000 // 0012D730:  nop 
    .word 0x1040fffa // 0012D734:  beqz $v0, 0x12d720
    .word 0x00000000 // 0012D738:  nop 
    .word 0x0000202d // 0012D73C:  move $a0, $zero
    .word 0x0c041d72 // 0012D740:  jal 0x1075c8
    .word 0x3c110049 // 0012D744:  lui $s1, 0x49
    .word 0x3c02004f // 0012D748:  lui $v0, 0x4f
    .word 0x10000010 // 0012D74C:  b 0x12d790
    .word 0x24501680 // 0012D750:  addiu $s0, $v0, 0x1680
    .word 0x00000000 // 0012D754:  nop 
    .word 0x0000182d // 0012D758:  move $v1, $zero
    .word 0x3c040049 // 0012D75C:  lui $a0, 0x49
    .word 0x3c05000f // 0012D760:  lui $a1, 0xf
    .word 0x34a5ffff // 0012D764:  ori $a1, $a1, 0xffff
    .word 0x64620001 // 0012D768:  daddiu $v0, $v1, 1
    .word 0x0040182d // 0012D76C:  move $v1, $v0
    .word 0xff838848 // 0012D770:  sd $v1, -0x77b8($gp)
    .word 0x00a3102a // 0012D774:  slt $v0, $a1, $v1
    .word 0x00000000 // 0012D778:  nop 
    .word 0x1040fffa // 0012D77C:  beqz $v0, 0x12d768
    .word 0x00000000 // 0012D780:  nop 
    .word 0x8e050024 // 0012D784:  lw $a1, 0x24($s0)
    .word 0x0c046378 // 0012D788:  jal 0x118de0
    .word 0x2484ff40 // 0012D78C:  addiu $a0, $a0, -0xc0
    .word 0x0200202d // 0012D790:  move $a0, $s0
    .word 0x24050030 // 0012D794:  addiu $a1, $zero, 0x30
    .word 0x0c041f0e // 0012D798:  jal 0x107c38
    .word 0x0000302d // 0012D79C:  move $a2, $zero
    .word 0x04430004 // 0012D7A0:  bgezl $v0, 0x12d7b4
    .word 0x8e020024 // 0012D7A4:  lw $v0, 0x24($s0)
    .word 0x0c046378 // 0012D7A8:  jal 0x118de0
    .word 0x2624ff28 // 0012D7AC:  addiu $a0, $s1, -0xd8
    .word 0x8e020024 // 0012D7B0:  lw $v0, 0x24($s0)
    .word 0x5040ffe8 // 0012D7B4:  beql $v0, $zero, 0x12d758
    .word 0xff808848 // 0012D7B8:  sd $zero, -0x77b8($gp)
    .word 0x0c0413e8 // 0012D7BC:  jal 0x104fa0
    .word 0x0000202d // 0012D7C0:  move $a0, $zero
    .word 0x24020001 // 0012D7C4:  addiu $v0, $zero, 1
    .word 0xa38284e9 // 0012D7C8:  sb $v0, -0x7b17($gp)
    .word 0xdfbf0020 // 0012D7CC:  ld $ra, 0x20($sp)
    .word 0xdfb10010 // 0012D7D0:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012D7D4:  ld $s0, ($sp)
    .word 0x03e00008 // 0012D7D8:  jr $ra
    .word 0x27bd0030 // 0012D7DC:  addiu $sp, $sp, 0x30
}
#else

typedef struct SifRpcClientData {
    void *header;
    u32 command;
    void *buff;
    void *gp;
    void *func;
    void *para;
    void *serve;
    u32 pad[9];
} SifRpcClientData;

extern s8 D_004E2CA9;
extern u64 D_004E3008;
extern SifRpcClientData D_004F1640;
extern SifRpcClientData D_004F1680;
extern const char D_0048FF08[];
extern const char D_0048FF28[];
extern const char D_0048FF40[];

int func_1075C8(int);
int func_107C38(SifRpcClientData *, int, int);
int func_118de0(const char *, ...);
int func_104FA0(int);

void func_0012D648(void) {
    if (D_004E2CA9 != 0) {
        return;
    }

    D_004E3008 = 0;
    while (D_004E3008 <= 0xFFFFF) {
        D_004E3008++;
    }

    func_1075C8(0);

    while (1) {
        if (func_107C38(&D_004F1640, 0x20, 0) < 0) {
            func_118de0(D_0048FF08);
        }
        if (D_004F1640.serve != 0) {
            break;
        }
        D_004E3008 = 0;
        func_104FA0(0);
        while (D_004E3008 <= 0xFFFFF) {
            D_004E3008++;
        }
    }

    D_004E3008 = 0;
    while (D_004E3008 <= 0xFFFFF) {
        D_004E3008++;
    }

    func_1075C8(0);

    while (1) {
        if (func_107C38(&D_004F1680, 0x30, 0) < 0) {
            func_118de0(D_0048FF28);
        }
        if (D_004F1680.serve != 0) {
            break;
        }
        D_004E3008 = 0;
        while (D_004E3008 <= 0xFFFFF) {
            D_004E3008++;
        }
        func_118de0(D_0048FF40, D_004F1680.serve);
        func_104FA0(0);
    }

    D_004E2CA9 = 1;
}

#endif

}
