#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm int func_0012E340(void *a0) {
    .word 0x27bdffc0
    .word 0xffb00020
    .word 0xffbf0030
    .word 0x0c04a264
    .word 0x0080802d
    .word 0x00021c3a
    .word 0xa7a20010
    .word 0xa7a30012
    .word 0x8ba20013
    .word 0x9ba20010
    .word 0xaba20003
    .word 0xbba20000
    .word 0x12000006
    .word 0x97a60000
    .word 0x8a020003
    .word 0x9a020000
    .word 0xaba20003
    .word 0xbba20000
    .word 0x97a60000
    .word 0x3c04ffff
    .word 0x97a30002
    .word 0x00441024
    .word 0x2405ffff
    .word 0x0005283c
    .word 0x34a5ffff
    .word 0x00461025
    .word 0x00031c38
    .word 0x00451024
    .word 0xdfbf0030
    .word 0x00621025
    .word 0xdfb00020
    .word 0x03e00008
    .word 0x27bd0040
}
#else

int func_0012E340(void *a0) {
    return 0;
}

#endif

}
