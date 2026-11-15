#pragma exceptions off

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Struct_00126D50 {
    u8 pad[0xb0];
    u32 flags;
};

extern "C" u32 func_00126D50(Struct_00126D50* a0) {
    return a0->flags & 0x40000;
}
