#ifndef TRADE_ACTION_STREAM_SERIALIZERS_H
#define TRADE_ACTION_STREAM_SERIALIZERS_H

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

    void func_00157D30();
    void func_00157DB0();
    void func_00157E50();
    void func_00157F10();
    void func_00157FE0();
    void func_00158080();
    void func_00158130();
    void func_00158200();
}

#endif // TRADE_ACTION_STREAM_SERIALIZERS_H
