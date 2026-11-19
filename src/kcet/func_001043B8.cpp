#pragma exceptions off

typedef unsigned int u32;

struct DmaChannel {
    volatile u32 reg0;
    volatile u32 reg4;
    volatile u32 reg8;
};

extern "C" void func_001043B8(DmaChannel *chan, u32 val) {
    chan->reg0 = val;
    chan->reg8 = 0;
    chan->reg4 = val;
}
