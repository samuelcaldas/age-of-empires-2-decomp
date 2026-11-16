typedef unsigned char u8;
typedef int s32;

struct Context {
    u8 pad[0x98];
    s32 counter;
};

extern "C" s32 func_00127BD8(Context* ctx) {
    return ++ctx->counter;
}
