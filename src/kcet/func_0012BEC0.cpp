/* Function: func_0012BEC0 (0x0012BEC0 - 0x0012BFB8)
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
asm void *func_0012BEC0(s32 arg0) {
    .word 0x27bdffd0 // 0012BEC0:  addiu $sp, $sp, -0x30
    .word 0x3c02004f // 0012BEC4:  lui $v0, 0x4f
    .word 0xffb10010 // 0012BEC8:  sd $s1, 0x10($sp)
    .word 0x24451400 // 0012BECC:  addiu $a1, $v0, 0x1400
    .word 0xffb00000 // 0012BED0:  sd $s0, ($sp)
    .word 0x24110004 // 0012BED4:  addiu $s1, $zero, 4
    .word 0xffbf0020 // 0012BED8:  sd $ra, 0x20($sp)
    .word 0x1080000d // 0012BEDC:  beqz $a0, 0x12bf14
    .word 0x0000802d // 0012BEE0:  move $s0, $zero
    .word 0x00a0182d // 0012BEE4:  move $v1, $a1
    .word 0x24a600e0 // 0012BEE8:  addiu $a2, $a1, 0xe0
    .word 0x8c620000 // 0012BEEC:  lw $v0, ($v1)
    .word 0x50400005 // 0012BEF0:  beql $v0, $zero, 0x12bf08
    .word 0x24630038 // 0012BEF4:  addiu $v1, $v1, 0x38
    .word 0x8c620014 // 0012BEF8:  lw $v0, 0x14($v1)
    .word 0x10440029 // 0012BEFC:  beq $v0, $a0, 0x12bfa4
    .word 0x0200102d // 0012BF00:  move $v0, $s0
    .word 0x24630038 // 0012BF04:  addiu $v1, $v1, 0x38
    .word 0x0066102a // 0012BF08:  slt $v0, $v1, $a2
    .word 0x5440fff8 // 0012BF0C:  bnel $v0, $zero, 0x12bef0
    .word 0x8c620000 // 0012BF10:  lw $v0, ($v1)
    .word 0x8ca20000 // 0012BF14:  lw $v0, ($a1)
    .word 0x10000007 // 0012BF18:  b 0x12bf38
    .word 0x0000202d // 0012BF1C:  move $a0, $zero
    .word 0x1000001d // 0012BF20:  b 0x12bf98
    .word 0x0000282d // 0012BF24:  move $a1, $zero
    .word 0x28820004 // 0012BF28:  slti $v0, $a0, 4
    .word 0x10400005 // 0012BF2C:  beqz $v0, 0x12bf44
    .word 0x24a50038 // 0012BF30:  addiu $a1, $a1, 0x38
    .word 0x8ca20000 // 0012BF34:  lw $v0, ($a1)
    .word 0x5440fffb // 0012BF38:  bnel $v0, $zero, 0x12bf28
    .word 0x24840001 // 0012BF3C:  addiu $a0, $a0, 1
    .word 0x00a0802d // 0012BF40:  move $s0, $a1
    .word 0x12000017 // 0012BF44:  beqz $s0, 0x12bfa4
    .word 0x0200102d // 0012BF48:  move $v0, $s0
    .word 0x0200202d // 0012BF4C:  move $a0, $s0
    .word 0x0c0450f0 // 0012BF50:  jal 0x1143c0
    .word 0x24050038 // 0012BF54:  addiu $a1, $zero, 0x38
    .word 0x0c04af9c // 0012BF58:  jal 0x12be70
    .word 0x00000000 // 0012BF5C:  nop 
    .word 0x0040282d // 0012BF60:  move $a1, $v0
    .word 0x50a0000d // 0012BF64:  beql $a1, $zero, 0x12bf9c
    .word 0xae050004 // 0012BF68:  sw $a1, 4($s0)
    .word 0x8ca30008 // 0012BF6C:  lw $v1, 8($a1)
    .word 0x10600008 // 0012BF70:  beqz $v1, 0x12bf94
    .word 0x0000202d // 0012BF74:  move $a0, $zero
    .word 0x24840001 // 0012BF78:  addiu $a0, $a0, 1
    .word 0x0224102a // 0012BF7C:  slt $v0, $s1, $a0
    .word 0x1440ffe7 // 0012BF80:  bnez $v0, 0x12bf20
    .word 0x0060282d // 0012BF84:  move $a1, $v1
    .word 0x8ca20008 // 0012BF88:  lw $v0, 8($a1)
    .word 0x1440fffa // 0012BF8C:  bnez $v0, 0x12bf78
    .word 0x0040182d // 0012BF90:  move $v1, $v0
    .word 0xacb00008 // 0012BF94:  sw $s0, 8($a1)
    .word 0xae050004 // 0012BF98:  sw $a1, 4($s0)
    .word 0xae000008 // 0012BF9C:  sw $zero, 8($s0)
    .word 0x0200102d // 0012BFA0:  move $v0, $s0
    .word 0xdfbf0020 // 0012BFA4:  ld $ra, 0x20($sp)
    .word 0xdfb10010 // 0012BFA8:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012BFAC:  ld $s0, ($sp)
    .word 0x03e00008 // 0012BFB0:  jr $ra
    .word 0x27bd0030 // 0012BFB4:  addiu $sp, $sp, 0x30
}
#else

struct CdvdNode {
    s32 active;
    CdvdNode *prev;
    CdvdNode *next;
    u8 pad[0x8];
    s32 id;
    u8 rest[0x20];
};

extern CdvdNode D_004F1400[4];

void func_001143C0(void *ptr, s32 size);
CdvdNode *func_0012BE70(void);

CdvdNode *func_0012BEC0(s32 arg0) {
    CdvdNode *node;
    s32 i;

    if (arg0 != 0) {
        for (node = D_004F1400; node < &D_004F1400[4]; node++) {
            if (node->active != 0 && node->id == arg0) {
                return 0;
            }
        }
    }

    for (node = D_004F1400, i = 0; i < 4; i++, node++) {
        if (node->active == 0) {
            break;
        }
    }

    if (i >= 4) {
        return 0;
    }

    func_001143C0(node, sizeof(CdvdNode));
    CdvdNode *req = func_0012BE70();
    if (req != 0) {
        node->prev = req;
        CdvdNode *cur = req->next;
        if (cur == 0) {
            req->next = node;
            node->prev = req;
        } else {
            s32 count = 0;
            while (count <= 4) {
                count++;
                if (cur->next == 0) {
                    cur->next = node;
                    node->prev = cur;
                    break;
                }
                cur = cur->next;
            }
            if (count > 4) {
                node->prev = 0;
            }
        }
    }
    node->next = 0;
    return node;
}

#endif

}
