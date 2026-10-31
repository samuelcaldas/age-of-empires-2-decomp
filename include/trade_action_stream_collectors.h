#ifndef TRADE_ACTION_STREAM_COLLECTORS_H
#define TRADE_ACTION_STREAM_COLLECTORS_H

union Buffer4 {
    unsigned char b[4];
    unsigned char bytes[4];
    int w;
    int word;
    unsigned int u;
};

extern "C" {
    extern Buffer4 D_004E2DA0;
    extern unsigned char *D_004E2DB0;
    extern unsigned char *D_004E2DB4;
    extern int D_004E30A8;
    extern int D_004E30AC;
    extern int D_004E2DA8;

    void func_001522C0(unsigned char *buf, unsigned char *src);

    void func_00156670();
    void func_001567A0();
    void func_00156920();
    void func_00156AC0();
}

#endif // TRADE_ACTION_STREAM_COLLECTORS_H
