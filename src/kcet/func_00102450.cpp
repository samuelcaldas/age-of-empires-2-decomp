#pragma exceptions off

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

struct UnwindContext {
    u8 pad_00[0x0C];
    void *field_0c;
    void *field_10;
};

extern "C" {

extern char D_004E27C0[];

/* 0x00102450 */
s32 func_00102450(UnwindContext *ctx) {
    ctx->field_0c = D_004E27C0;
    ctx->field_10 = D_004E27C0;
    return 1;
}

}
