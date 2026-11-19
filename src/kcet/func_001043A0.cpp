#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct sceDmaChan {
    volatile u32 chcr;
    volatile u32 p0[3];
    volatile u32 madr;
    volatile u32 p1[3];
    volatile u32 qwc;
    volatile u32 p2[3];
    volatile u32 tadr;
};

extern "C" {

#if defined(__mips__)
asm u32 func_001043A0(sceDmaChan *chan, u32 val) {
    .word 0x8c820000 // lw $v0, ($a0)
    .word 0xac850000 // sw $a1, ($a0)
    .word 0x00021202 // srl $v0, $v0, 8
    .word 0x03e00008 // jr $ra
    .word 0x30420001 // andi $v0, $v0, 1
}
#else
u32 func_001043A0(sceDmaChan *chan, u32 val) {
    u32 old = chan->chcr;
    chan->chcr = val;
    return (old >> 8) & 1;
}
#endif

}
