typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

extern "C" {

#if defined(__mips__)
asm int func_00129428(int a0) {
    .word 0x27bdffc0
    .word 0x3c03004e
    .word 0xffb00010
    .word 0x0080282d
    .word 0xffb10020
    .word 0x2402ffff
    .word 0xffbf0030
    .word 0x8f908428
    .word 0x24692c28
    .word 0x69260007
    .word 0x6d260000
    .word 0xb3a60007
    .word 0xb7a60000
    .word 0x1202000a
    .word 0x24110001
    .word 0x0225200b
    .word 0x0080282d
    .word 0x00051080
    .word 0x03a21821
    .word 0x8c620000
    .word 0x0040f809
    .word 0x0200202d
    .word 0x02021026
    .word 0x0002880b
    .word 0x0220102d
    .word 0xdfbf0030
    .word 0xdfb10020
    .word 0xdfb00010
    .word 0x03e00008
    .word 0x27bd0040
}
#else
struct FuncTable {
    int (*funcs[2])(int);
};

extern struct FuncTable D_4E2C28;
extern int D_004E8428;

int func_00129428(int a0) {
    struct FuncTable local = D_4E2C28;
    int s1 = 1;
    if (D_004E8428 != -1) {
        if (a0) {
            a0 = 1;
        }
        int res = local.funcs[a0](D_004E8428);
        if (res != D_004E8428) {
            s1 = 0;
        }
    }
    return s1;
}
#endif

}
