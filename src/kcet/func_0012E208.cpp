/* Function: func_0012E208 (0x0012E208 - 0x0012E2F0)
 * Origin: SLES-50282, KCET kt_mc_2 module (originally compiled with ee-gcc -O2 -G0)
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
asm void func_0012E208(void *a0, s32 a1, s32 a2) {
    .word 0x27bdffa0 // 0012E208:  addiu $sp, $sp, -0x60
    .word 0xffb00020 // 0012E20C:  sd $s0, 0x20($sp)
    .word 0xffb20040 // 0012E210:  sd $s2, 0x40($sp)
    .word 0x00a0802d // 0012E214:  move $s0, $a1
    .word 0xffb10030 // 0012E218:  sd $s1, 0x30($sp)
    .word 0x00c0902d // 0012E21C:  move $s2, $a2
    .word 0xffbf0050 // 0012E220:  sd $ra, 0x50($sp)
    .word 0x2e020003 // 0012E224:  sltiu $v0, $s0, 3
    .word 0x14400007 // 0012E228:  bnez $v0, 0x12e248
    .word 0x0080882d // 0012E22C:  move $s1, $a0
    .word 0x3c040049 // 0012E230:  lui $a0, 0x49
    .word 0x3c060049 // 0012E234:  lui $a2, 0x49
    .word 0x24840068 // 0012E238:  addiu $a0, $a0, 0x68
    .word 0x24c60110 // 0012E23C:  addiu $a2, $a2, 0x110
    .word 0x0c0450c8 // 0012E240:  jal 0x114320
    .word 0x240502ba // 0012E244:  addiu $a1, $zero, 0x2ba
    .word 0x16200005 // 0012E248:  bnez $s1, 0x12e260
    .word 0x27a80010 // 0012E24C:  addiu $t0, $sp, 0x10
    .word 0x0c04b8bc // 0012E250:  jal 0x12e2f0
    .word 0x0000202d // 0012E254:  move $a0, $zero
    .word 0x0040882d // 0012E258:  move $s1, $v0
    .word 0x27a80010 // 0012E25C:  addiu $t0, $sp, 0x10
    .word 0x24030001 // 0012E260:  addiu $v1, $zero, 1
    .word 0x24060001 // 0012E264:  addiu $a2, $zero, 1
    .word 0x27a20014 // 0012E268:  addiu $v0, $sp, 0x14
    .word 0x00000000 // 0012E26C:  nop
    .word 0xac430000 // 0012E270:  sw $v1, ($v0)
    .word 0x24c6ffff // 0012E274:  addiu $a2, $a2, -1
    .word 0x2442fffc // 0012E278:  addiu $v0, $v0, -4
    .word 0x00000000 // 0012E27C:  nop
    .word 0x00000000 // 0012E280:  nop
    .word 0x04c1fffa // 0012E284:  bgez $a2, 0x12e270
    .word 0x00000000 // 0012E288:  nop
    .word 0x0240382d // 0012E28C:  move $a3, $s2
    .word 0x03a0202d // 0012E290:  move $a0, $sp
    .word 0x0200282d // 0012E294:  move $a1, $s0
    .word 0x0c049810 // 0012E298:  jal 0x126040
    .word 0x24060002 // 0012E29C:  addiu $a2, $zero, 2
    .word 0x1a00000e // 0012E2A0:  blez $s0, 0x12e2dc
    .word 0xdfbf0050 // 0012E2A4:  ld $ra, 0x50($sp)
    .word 0x0220202d // 0012E2A8:  move $a0, $s1
    .word 0x0200302d // 0012E2AC:  move $a2, $s0
    .word 0x03a0282d // 0012E2B0:  move $a1, $sp
    .word 0x00000000 // 0012E2B4:  nop
    .word 0x94a20000 // 0012E2B8:  lhu $v0, ($a1)
    .word 0x24c6ffff // 0012E2BC:  addiu $a2, $a2, -1
    .word 0xa4820000 // 0012E2C0:  sh $v0, ($a0)
    .word 0x94a30002 // 0012E2C4:  lhu $v1, 2($a1)
    .word 0x24a50004 // 0012E2C8:  addiu $a1, $a1, 4
    .word 0xa4830002 // 0012E2CC:  sh $v1, 2($a0)
    .word 0x14c0fff9 // 0012E2D0:  bnez $a2, 0x12e2b8
    .word 0x24840010 // 0012E2D4:  addiu $a0, $a0, 0x10
    .word 0xdfbf0050 // 0012E2D8:  ld $ra, 0x50($sp)
    .word 0xdfb20040 // 0012E2DC:  ld $s2, 0x40($sp)
    .word 0xdfb10030 // 0012E2E0:  ld $s1, 0x30($sp)
    .word 0xdfb00020 // 0012E2E4:  ld $s0, 0x20($sp)
    .word 0x03e00008 // 0012E2E8:  jr $ra
    .word 0x27bd0060 // 0012E2EC:  addiu $sp, $sp, 0x60
}
#else

struct McSlot {
    u16 port;
    u16 slot;
    u8 pad[12];
};

extern const char D_490068[];
extern const char D_490110[];

void func_114320(const char *file, int line, const char *assertion);
void *func_0012E2F0(int);
void func_00126040(u16 *out_ports, int n_pad, int mode, int flag, int *p_ports);

void func_0012E208(McSlot *buf, int n_card, int flag) {
    u16 out_ports[8];
    int ports[2];
    int count;
    int i;
    McSlot *p;
    u16 *src;

    if ((unsigned int)n_card >= 3) {
        func_114320(D_490068, 0x2BA, D_490110);
    }
    if (buf == 0) {
        buf = (McSlot *)func_0012E2F0(0);
    }
    for (i = 1; i >= 0; i--) {
        ports[i] = 1;
    }
    count = n_card;
    func_00126040(out_ports, count, 2, flag, ports);
    if (count > 0) {
        p = buf;
        src = out_ports;
        for (i = count; i != 0; i--) {
            p->port = src[0];
            p->slot = src[1];
            src += 2;
            p = (McSlot *)((u8 *)p + 0x10);
        }
    }
}

#endif

}
