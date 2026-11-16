typedef unsigned char u8;
typedef unsigned int u32;

struct TargetStruct {
    u8 pad[0xb0];
    u32 flags;
};

extern "C" u32 func_001281B0(TargetStruct* obj) {
    return (obj->flags & 0x10) != 0;
}
