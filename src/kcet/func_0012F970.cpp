#pragma exceptions off

typedef unsigned int u32;

struct Struct_12F970 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 flags;
};

extern "C" u32 func_0012F970(Struct_12F970 *p) {
    return p->flags |= 1;
}
