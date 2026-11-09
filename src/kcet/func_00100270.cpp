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

void func_001001f0(s64 b, s64 a);

s32 func_00100270(s64 a, s64 b) {
    func_001001f0(b, a);
    return 1;
}

}
