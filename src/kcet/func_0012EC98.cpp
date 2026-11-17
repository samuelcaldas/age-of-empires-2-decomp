#pragma exceptions off

typedef signed int s32;
typedef unsigned char u8;

struct DeviceContext {
    u8 pad[0x1C];
    s32 state;
};

extern "C" s32 func_0012EC98(DeviceContext *dev) {
    return (dev->state != 0) ? -3 : 0;
}
