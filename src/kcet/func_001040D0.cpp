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

void func_118de0(const char *fmt, ...);

#if defined(__mips__)
asm void func_001040D0(sceDmaChan *chan, void *tag, u32 chcr_mode) {
    .word 0x27bdffa0
    .word 0xffb40040
    .word 0xffb30030
    .word 0x00c0a02d
    .word 0xffb10010
    .word 0x00a0982d
    .word 0xffb00000
    .word 0x3c110100
    .word 0xffbf0050
    .word 0x0080802d
    .word 0xffb20020
    .word 0x8e020000
    .word 0x30420100
    .word 0x10400018
    .word 0x3c120049
    .word 0x2631ffff
    .word 0x06210011
    .word 0x00000000
    .word 0x0c046378
    .word 0x2644d5e0
    .word 0x8e040000
    .word 0x00041202
    .word 0x30420001
    .word 0x1040000a
    .word 0x00000000
    .word 0x2405feff
    .word 0x00851824
    .word 0x0000102d
    .word 0x0060202d
    .word 0x00000000
    .word 0x00000000
    .word 0x1440fffa
    .word 0x00000000
    .word 0xae030000
    .word 0x8e020000
    .word 0x30420100
    .word 0x1440ffeb
    .word 0x2631ffff
    .word 0x3c02ffff
    .word 0x8e030010
    .word 0x3442ffff
    .word 0x54620001
    .word 0xae130010
    .word 0x8e020000
    .word 0x2403fff3
    .word 0x2404fffe
    .word 0xae140020
    .word 0x00431024
    .word 0xdfbf0050
    .word 0x34420008
    .word 0xdfb40040
    .word 0x00441024
    .word 0xdfb30030
    .word 0x34420100
    .word 0xdfb20020
    .word 0xae020000
    .word 0xdfb10010
    .word 0xdfb00000
    .word 0x03e00008
    .word 0x27bd0060
}
#else
void func_001040D0(sceDmaChan *chan, void *tag, u32 chcr_mode) {
    if (chan->chcr & 0x100) {
        int timeout = 0x1000000;
        while (--timeout >= 0) {
            if (!(chan->chcr & 0x100)) {
                break;
            }
        }
        if (timeout < 0) {
            func_118de0((const char *)0x48D5E0);
            if ((chan->chcr >> 8) & 1) {
                chan->chcr &= ~0x101;
            }
        }
    }
    if (chan->madr != 0xFFFFFFFF) {
        chan->madr = (u32)tag;
    }
    chan->tadr = chcr_mode;
    chan->chcr = ((chan->chcr & ~0xD) | 8) & ~2 | 0x100;
}
#endif

}
