#pragma exceptions off

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

struct Struct_0012A0E0 {
    u8 pad[0x1C];
    s32 field_1C;
};

extern "C" {

s32 func_0012A0E0(const Struct_0012A0E0* self) {
    return self->field_1C;
}

}
