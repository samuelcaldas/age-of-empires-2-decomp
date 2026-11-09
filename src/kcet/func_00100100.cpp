#pragma exceptions off

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" {

s32 func_00122640(s64 a, s64 b);

s32 func_00100100(s64 a, s64 b) {
    return func_00122640(a, b) != 0;
}

}
