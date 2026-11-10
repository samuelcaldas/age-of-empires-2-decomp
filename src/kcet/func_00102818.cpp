#pragma exceptions off

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef unsigned long long u64;

struct sceGsGParam {
    s16 interlace;
    s16 omode;
    s16 ffmode;
    s16 version;
    s32 field_08;
    s32 field_0c;
};

extern "C" {

extern sceGsGParam D_00389B80;

/* 0x00102818 */
sceGsGParam *func_00102818(void) {
    return &D_00389B80;
}

}
