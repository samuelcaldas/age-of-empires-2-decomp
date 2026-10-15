#ifndef TRADE_ACTION_PATHING_H
#define TRADE_ACTION_PATHING_H

#define V_SLOT_10(base) \
    virtual int v##base##0(); virtual int v##base##1(); virtual int v##base##2(); virtual int v##base##3(); virtual int v##base##4(); \
    virtual int v##base##5(); virtual int v##base##6(); virtual int v##base##7(); virtual int v##base##8(); virtual int v##base##9();

struct TimerNode {
    char pad_00[14];
    short m_id;
};

class TargetObj {
public:
    V_SLOT_10(0)  // 0-9
    V_SLOT_10(1)  // 10-19
    V_SLOT_10(2)  // 20-29
    V_SLOT_10(3)  // 30-39
    V_SLOT_10(4)  // 40-49
    V_SLOT_10(5)  // 50-59
    V_SLOT_10(6)  // 60-69
    V_SLOT_10(7)  // 70-79
    V_SLOT_10(8)  // 80-89
    virtual int v90();
    virtual int Method372(int a1);                         // offset 372 = 0x174
    virtual int Method376(int a1);                         // offset 376 = 0x178
    virtual int Method380(float x, float y, float z);      // offset 380 = 0x17C
    virtual int v94();                                     // offset 384 = 0x180
    virtual int Method388(int a1);                         // offset 388 = 0x184
    virtual int Method392(int a1);                         // offset 392 = 0x188
    virtual int Method396(int a1);                         // offset 396 = 0x18C
    virtual int Method400(int a1);                         // offset 400 = 0x190
    virtual int Method404(int a1);                         // offset 404 = 0x194
    virtual int Method408(int a1);                         // offset 408 = 0x198
    virtual int Method412(int a1);                         // offset 412 = 0x19C
    virtual int Method416(int a1);                         // offset 416 = 0x1A0
    virtual int Method420(float x, float y, float z);      // offset 420 = 0x1A4
    virtual int Method424(float x, float y, float z);      // offset 424 = 0x1A8

    TimerNode *m_node;             // offset 4
    void *m_game;                  // offset 8
    char pad_0C[0x24 - 0xC];       // offset 12..35
    short m_field24;               // offset 36
    char pad_26[0x44 - 0x26];      // offset 38..67
    float x;                       // offset 68
    float y;                       // offset 72
    float z;                       // offset 76
};

struct TradeAction {
    void *m_vtable;
    char pad_04[0x34];
    TargetObj *m_target;
    char pad_3C[0xC];
    short m_field48;
    short m_field4A;
    char pad_4C[0x1C];
    short m_field68;
    char pad_6A[0x6];
    int m_field70;
};

extern "C" {
    void func_001471B0(void *self, int code);
    void func_14BD20(void *self, int id, float x, float y, float z);
    void func_14bd90(void *self, int id, int target_id, float x, float y, float z);
    void* func_332e60(void *timer, int id);

    int func_0014A640(TradeAction *self, int a1, int a2);
    int func_0014A6E0(TradeAction *self, int a1, float x, float y, float z);
    int func_0014A7A0(TradeAction *self, int a1, float x, float y, float z);
    int func_0014A880(TradeAction *self, int a1, int a2);
    int func_0014A970(TradeAction *self, int a1, int a2);
    int func_0014AA60(TradeAction *self, int a1, float x, float y, float z);
}

#endif // TRADE_ACTION_PATHING_H
