#ifndef TRADE_ACTION_STREAM_DISPATCHERS_H
#define TRADE_ACTION_STREAM_DISPATCHERS_H

union Buffer4 {
    unsigned char b[4];
    unsigned char bytes[4];
    int w;
    int word;
    unsigned int u;
};

extern "C" {
    extern Buffer4 D_004E2DA0;
    extern unsigned char *D_004E2DB4;
    extern int D_004E2DA8;

    void func_00159500();
    void func_00159580();
    void func_00159620();
    void func_001596E0();
    void func_001597B0();
    void func_00159850();
    void func_00159900();
    void func_001599D0();
}

#endif // TRADE_ACTION_STREAM_DISPATCHERS_H
