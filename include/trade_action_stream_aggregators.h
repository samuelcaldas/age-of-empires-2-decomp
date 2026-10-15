#ifndef TRADE_ACTION_STREAM_AGGREGATORS_H
#define TRADE_ACTION_STREAM_AGGREGATORS_H

union Buffer4 {
    unsigned char b[4];
    int w;
    unsigned int u;
};

extern "C" {
    extern unsigned char *D_004E2DB0;
    extern unsigned char *D_004E2DB4;
    extern int D_004E2DA8;
    extern Buffer4 D_004E2DA0;
    extern int D_004E30A8;
    extern int D_004E30AC;

    void func_001522C0(unsigned char *buf, unsigned char *src);

    void func_001560D0();
    void func_001561F0();
    void func_00156350();
    void func_001564D0();
}

#endif // TRADE_ACTION_STREAM_AGGREGATORS_H
