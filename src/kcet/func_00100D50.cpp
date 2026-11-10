#pragma exceptions off

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern "C" const u8* func_00100D50(const u8* src, s32* dst) {
    s32 b0 = (s8)src[0];
    if ((b0 & 1) == 0) {
        *dst = b0 >> 1;
        return src + 1;
    }

    u32 b1 = src[1];
    if ((b0 & 2) == 0) {
        *dst = ((b0 >> 2) << 8) | b1;
        return src + 2;
    }

    u32 b2 = src[2];
    if ((b0 & 4) == 0) {
        *dst = ((b0 >> 3) << 16) | (b1 << 8) | b2;
        return src + 3;
    }

    *dst = src[3] | ((b2 << 8) | (((b0 >> 3) << 24) | (b1 << 16)));
    return src + 4;
}
