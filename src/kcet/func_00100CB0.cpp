#pragma exceptions off

typedef unsigned char u8;
typedef unsigned int u32;

extern "C" const u8* func_00100CB0(const u8* src, u32* dst) {
    u32 b0 = src[0];
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

    u32 b3 = src[3];
    *dst = ((b0 >> 3) << 24) | (b1 << 16) | (b2 << 8) | b3;
    return src + 4;
}
