#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void *func_0012E4E8(u32 a0) {
    .word 0x27bdffc0 // 0012E4E8:  addiu $sp, $sp, -0x40
    .word 0xafa40000 // 0012E4EC:  sw $a0, ($sp)
    .word 0xffb10020 // 0012E4F0:  sd $s1, 0x20($sp)
    .word 0x0000202d // 0012E4F4:  move $a0, $zero
    .word 0xffb00010 // 0012E4F8:  sd $s0, 0x10($sp)
    .word 0xffbf0030 // 0012E4FC:  sd $ra, 0x30($sp)
    .word 0x0c04b8bc // 0012E500:  jal 0x12e2f0
    .word 0x0000882d // 0012E504:  move $s1, $zero
    .word 0x0c04b8c8 // 0012E508:  jal 0x12e320
    .word 0x0040802d // 0012E50C:  move $s0, $v0
    .word 0x87a70000 // 0012E510:  lh $a3, ($sp)
    .word 0x0040302d // 0012E514:  move $a2, $v0
    .word 0x2404ffff // 0012E518:  addiu $a0, $zero, -1
    .word 0x10e4001e // 0012E51C:  beq $a3, $a0, 0x12e598
    .word 0x97a80000 // 0012E520:  lhu $t0, ($sp)
    .word 0x97a50002 // 0012E524:  lhu $a1, 2($sp)
    .word 0x00051400 // 0012E528:  sll $v0, $a1, 0x10
    .word 0x00021c03 // 0012E52C:  sra $v1, $v0, 0x10
    .word 0x1064001a // 0012E530:  beq $v1, $a0, 0x12e59c
    .word 0x0220102d // 0012E534:  move $v0, $s1
    .word 0x18c00018 // 0012E538:  blez $a2, 0x12e59c
    .word 0x0000202d // 0012E53C:  move $a0, $zero
    .word 0x86020002 // 0012E540:  lh $v0, 2($s0)
    .word 0x54430006 // 0012E544:  bnel $v0, $v1, 0x12e560
    .word 0x24840001 // 0012E548:  addiu $a0, $a0, 1
    .word 0x86020000 // 0012E54C:  lh $v0, ($s0)
    .word 0x50470011 // 0012E550:  beql $v0, $a3, 0x12e598
    .word 0x0200882d // 0012E554:  move $s1, $s0
    .word 0x24840001 // 0012E558:  addiu $a0, $a0, 1
    .word 0x00000000 // 0012E55C:  nop
    .word 0x0086102a // 0012E560:  slt $v0, $a0, $a2
    .word 0x1040000c // 0012E564:  beqz $v0, 0x12e598
    .word 0x26100010 // 0012E568:  addiu $s0, $s0, 0x10
    .word 0x00051400 // 0012E56C:  sll $v0, $a1, 0x10
    .word 0x86030002 // 0012E570:  lh $v1, 2($s0)
    .word 0x00021403 // 0012E574:  sra $v0, $v0, 0x10
    .word 0x5462fff9 // 0012E578:  bnel $v1, $v0, 0x12e560
    .word 0x24840001 // 0012E57C:  addiu $a0, $a0, 1
    .word 0x00081400 // 0012E580:  sll $v0, $t0, 0x10
    .word 0x86030000 // 0012E584:  lh $v1, ($s0)
    .word 0x00021403 // 0012E588:  sra $v0, $v0, 0x10
    .word 0x5462fff4 // 0012E58C:  bnel $v1, $v0, 0x12e560
    .word 0x24840001 // 0012E590:  addiu $a0, $a0, 1
    .word 0x0200882d // 0012E594:  move $s1, $s0
    .word 0x0220102d // 0012E598:  move $v0, $s1
    .word 0xdfbf0030 // 0012E59C:  ld $ra, 0x30($sp)
    .word 0xdfb10020 // 0012E5A0:  ld $s1, 0x20($sp)
    .word 0xdfb00010 // 0012E5A4:  ld $s0, 0x10($sp)
    .word 0x03e00008 // 0012E5A8:  jr $ra
    .word 0x27bd0040 // 0012E5AC:  addiu $sp, $sp, 0x40
}
#else

struct McTableEntry {
    s16 port;
    s16 slot;
    u8 pad[12];
};

void *func_0012E2F0(int idx);
int func_0012E320(void);

void *func_0012E4E8(u32 a0) {
    s16 target_port = (s16)(a0 & 0xFFFF);
    s16 target_slot = (s16)(a0 >> 16);
    void *result = 0;
    int count;
    McTableEntry *entry;
    int i;

    entry = (McTableEntry *)func_0012E2F0(0);
    count = func_0012E320();
    if (target_port == -1 || target_slot == -1) {
        return 0;
    }
    for (i = 0; i < count; i++, entry++) {
        if (entry->slot == target_slot && entry->port == target_port) {
            result = entry;
            break;
        }
    }
    return result;
}

#endif

}
