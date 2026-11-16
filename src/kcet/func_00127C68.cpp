typedef unsigned char u8;
typedef unsigned int u32;

struct TargetStruct {
    u8 pad[0xB0];
    u32 flags;
};

extern "C" u32 func_00127C68(TargetStruct* self) {
    return self->flags & 4;
}
