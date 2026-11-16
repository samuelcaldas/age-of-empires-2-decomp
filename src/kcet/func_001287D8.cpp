typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct TargetStruct {
    u8 pad[0xB0];
    u32 flags;
};

extern "C" s32 func_001287D8(TargetStruct* obj) {
    return (obj->flags & 0x40) != 0;
}
