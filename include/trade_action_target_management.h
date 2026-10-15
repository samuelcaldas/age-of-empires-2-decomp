#ifndef TRADE_ACTION_TARGET_MANAGEMENT_H
#define TRADE_ACTION_TARGET_MANAGEMENT_H

#define V_SLOT_10(base) \
    virtual int v##base##0(); virtual int v##base##1(); virtual int v##base##2(); virtual int v##base##3(); virtual int v##base##4(); \
    virtual int v##base##5(); virtual int v##base##6(); virtual int v##base##7(); virtual int v##base##8(); virtual int v##base##9();

struct Vector3 {
    float x, y, z;
};

struct RouteObj {
    char pad_00[24];
    int m_flags;       // offset 24 = 0x18
    char pad_1C[8];
    char m_count;      // offset 32 = 0x20
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
    V_SLOT_10(9)  // 90-99
    V_SLOT_10(10) // 100-109
    V_SLOT_10(11) // 110-118
    virtual int Method484(float x, float y, float z); // offset 484 = 0x1E4 (v119)
    virtual int Method488();                           // offset 488 = 0x1E8 (v120)

    char pad_04[4];
    void *m_game;                  // offset 8
};

class TradeAction {
public:
    char pad_00[56];
    TargetObj *m_target;           // offset 56 (0x38)
    char pad_3C[0x68 - 0x3C];
    short m_field68;               // offset 104 (0x68)
    short m_field6A;               // offset 106 (0x6A)
    short m_field6C;               // offset 108 (0x6C)
    unsigned char m_field6E;       // offset 110 (0x6E)
    char pad_6F;
    int m_field70;                 // offset 112 (0x70)
    int m_field74;                 // offset 116 (0x74)
    int m_field78;                 // offset 120 (0x78)
    int m_field7C;                 // offset 124 (0x7C)
    int m_field80;                 // offset 128 (0x80)
    int m_field84;                 // offset 132 (0x84)
    int m_field88;                 // offset 136 (0x88)
    char pad_8C[0x164 - 0x8C];
    RouteObj *m_route_obj;         // offset 356 (0x164)
    int m_field168;                // offset 360 (0x168)
};

extern "C" {
    void* func_1fd4e0(Vector3 *out, RouteObj *route, int idx);
    void func_1FC810(RouteObj *route);
    void* func_332e60(void *mgr, short id);
    void func_00145E30(void *ptr, Vector3 *p1, Vector3 *p2);

    int func_001512A0(TradeAction *self);
    int func_001513E0(void *self);
    void func_001513F0(void *self);
    int func_00151400(TradeAction *self);
    void func_00151440(TradeAction *self);
    int func_00151480(TradeAction *self, short a1, short a2, Vector3 *p1, short t0, Vector3 *p2);
}

#endif // TRADE_ACTION_TARGET_MANAGEMENT_H
