#ifndef TRADE_ACTION_STREAM_DECODERS4_H
#define TRADE_ACTION_STREAM_DECODERS4_H

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
    extern int D_004E2DA4;

    void func_001522C0(unsigned char *buf, unsigned char *src);

    void func_0015B660();
    void func_0015B7C0();
    void func_0015B930();
    void func_0015BA50();
    void func_0015BBB0();
}

#endif // TRADE_ACTION_STREAM_DECODERS4_H
