/* Function: func_0012BE30 (0x0012BE30 - 0x0012BE70)
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
asm void func_0012BE30(void *arg0) {
    .word 0x1080000d // 0012BE30:  beqz $a0, 0x12be68
    .word 0x00000000 // 0012BE34:  nop 
    .word 0x8c820000 // 0012BE38:  lw $v0, ($a0)
    .word 0x1040000a // 0012BE3C:  beqz $v0, 0x12be68
    .word 0x00000000 // 0012BE40:  nop 
    .word 0x8c830004 // 0012BE44:  lw $v1, 4($a0)
    .word 0x10600002 // 0012BE48:  beqz $v1, 0x12be54
    .word 0x8c820008 // 0012BE4C:  lw $v0, 8($a0)
    .word 0xac620008 // 0012BE50:  sw $v0, 8($v1)
    .word 0x54400001 // 0012BE54:  bnel $v0, $zero, 0x12be5c
    .word 0xac430004 // 0012BE58:  sw $v1, 4($v0)
    .word 0xac800008 // 0012BE5C:  sw $zero, 8($a0)
    .word 0xac800000 // 0012BE60:  sw $zero, ($a0)
    .word 0xac800004 // 0012BE64:  sw $zero, 4($a0)
    .word 0x03e00008 // 0012BE68:  jr $ra
    .word 0x00000000 // 0012BE6C:  nop 
}
#else

struct CdvdNode {
    s32 active;
    CdvdNode *prev;
    CdvdNode *next;
};

void func_0012BE30(CdvdNode *node) {
    if (node != 0 && node->active != 0) {
        CdvdNode *prev = node->prev;
        CdvdNode *next = node->next;
        if (prev != 0) {
            prev->next = next;
        }
        if (next != 0) {
            next->prev = prev;
        }
        node->next = 0;
        node->active = 0;
        node->prev = 0;
    }
}

#endif

}
