#pragma exceptions off

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct TargetStruct {
    u8 pad[0xb0];
    u32 flags;
};

extern "C" {

u32 func_001277F8(TargetStruct* obj) {
    u32 v = obj->flags;
    obj->flags = v & ~0x10000;
    return ~0x10000;
}

}
