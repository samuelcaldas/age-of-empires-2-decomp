#ifndef TRADE_ACTION_MARKET_MANAGER_H
#define TRADE_ACTION_MARKET_MANAGER_H

#define V_SLOT_10(base) \
    virtual int v##base##0(); virtual int v##base##1(); virtual int v##base##2(); virtual int v##base##3(); virtual int v##base##4(); \
    virtual int v##base##5(); virtual int v##base##6(); virtual int v##base##7(); virtual int v##base##8(); virtual int v##base##9();

struct Message {
    short m_id;
    short pad_02;
    short m_action_id;
    short pad_06;
    int m_param;
    int m_data;
};

class TargetObj {
public:
    virtual void vfn0();
    void *m_node_ptr;              // offset 4
    void *m_game;                  // offset 8
    char pad_0C[0x24 - 0xC];       // offset 12..35
    short m_field24;               // offset 36
    char pad_26[0x64 - 0x26];      // offset 38..99
    int m_field64;                 // offset 100
};

class TradeAction {
public:
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(); virtual int v6();
    virtual int Method24(void *msg);                       // offset 36 = 0x24 (v7)
    virtual int v8();
    virtual int Method2C(int a1, float x, float y);        // offset 44 = 0x2C (v9)

    char pad_04[0x38 - 0x4];       // offset 4..55
    TargetObj *m_target;           // offset 56 (0x38)
    char pad_3C[0x44 - 0x3C];      // offset 60..67
    short m_field44;               // offset 68 (0x44)
    char pad_46[2];                // offset 70..71
    short m_field48;               // offset 72 (0x48)
    short m_field4A;               // offset 74 (0x4A)
    char pad_4C[0xA4 - 0x4C];      // offset 76..163
    short *m_waypoints;            // offset 164 (0xA4)
    int m_waypoint_count;          // offset 168 (0xA8)
    char pad_AC[0xB0 - 0xAC];      // offset 172..175
    int m_waypoint_cap;            // offset 176 (0xB0)
};

extern "C" {
    void* func_333b30(void *timer, int id);
    int func_1BBE40(void *obj, int mode);
    void* func_332e60(void *timer, int id);
    void func_00147CE0(void *self, void *msg);
    void func_26AD30(void *target, int a1, int a2);
    void func_00150F50(void *self, int a1);
    void* func_001510D0(void *self, int id);
    int func_00202B10(void *game);
    void func_0014C480(void *self);
    void func_00148050(void *self);
    void func_151230(void *self);
    void func_0014BCE0(void *self);
    void func_001471B0(void *self, int code);
    void func_00149D30(void *self);

    int func_0014D290(TradeAction *self, Message *msg, int param);
}

#endif // TRADE_ACTION_MARKET_MANAGER_H
