#ifndef TRADE_ACTION_STREAM_DECODERS2_H
#define TRADE_ACTION_STREAM_DECODERS2_H

union Buffer4 {
    unsigned char b[4];
    int w;
    unsigned int u;
};

extern "C" {
    extern unsigned char *D_004E2DB0;
    extern unsigned char *D_004E2DB4;
    extern Buffer4 D_004E2DA0;
    extern int D_004E2DA4;

    void func_001522C0(unsigned char *buf, unsigned char *src);

    void func_0015A710();
    void func_0015A7F0();
    void func_0015A8F0();
    void func_0015A9F0();
    void func_0015AAF0();
}

#endif // TRADE_ACTION_STREAM_DECODERS2_H
