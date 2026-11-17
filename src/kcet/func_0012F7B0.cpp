#pragma exceptions off

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Item {
    u8 pad[0x18];
    u32 val;
    u8 pad2[0x4];
};

struct Container {
    u8 pad[0x1c];
    char *items;
};

extern "C" u32 func_0012F7B0(Container *a0, s32 a1) {
    a1 <<= 5;
    a1 += (s32)a0->items;
    return ((Item *)a1)->val > 0;
}
