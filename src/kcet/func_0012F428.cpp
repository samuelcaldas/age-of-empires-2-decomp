typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;

struct TargetStruct {
    u8 pad[4];
    s16 field_4;
};

extern "C" s32 func_0012F428(TargetStruct* a0) {
    return a0->field_4 == 2;
}
