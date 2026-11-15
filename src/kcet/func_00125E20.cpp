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
    u8 pad[0x8C];
    s32 field_8C;
};

extern "C" s32 func_00125E20(TargetStruct* self) {
    return self->field_8C = -1;
}
