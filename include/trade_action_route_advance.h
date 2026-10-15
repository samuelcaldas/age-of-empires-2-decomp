#ifndef TRADE_ACTION_ROUTE_ADVANCE_H
#define TRADE_ACTION_ROUTE_ADVANCE_H

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
    virtual int v60(); virtual int v61(); virtual int v62(); virtual int v63();
    virtual int v64(); virtual int v65(); virtual int v66();
    virtual float Method276();                             // offset 276 = 0x114 (v67)
    virtual int v68(); virtual int v69();
    V_SLOT_10(7)  // 70-79
    virtual int v80(); virtual int v81(); virtual int v82(); virtual int v83();
    virtual int Method344(int a1, int a2);                 // offset 344 = 0x158 (v84)
    virtual int v85(); virtual int v86();
    virtual TargetObj* Method356();                        // offset 356 = 0x164 (v87)
    virtual int v88(); virtual int v89();
    V_SLOT_10(9)  // 90-99
    V_SLOT_10(10) // 100-109
    virtual int v110(); virtual int v111(); virtual int v112(); virtual int v113(); virtual int v114(); virtual int v115();
    virtual int Method472();                               // offset 472 = 0x1D8 (v116)

    TimerNode *m_node;             // offset 4
    void *m_game;                  // offset 8
    char pad_0C[0x24 - 0xC];       // offset 12..35
    short m_field24;               // offset 36
    char pad_26[0x39 - 0x26];      // offset 38..56
    unsigned char m_field39;       // offset 57
    char pad_3A[0x44 - 0x3A];      // offset 58..67
    float x;                       // offset 68
    float y;                       // offset 72
    float z;                       // offset 76
    char pad_50[0x64 - 0x50];      // offset 80..99
    int m_field64;                 // offset 100
};

class TradeAction {
public:
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8();
    virtual int Method2C(float x, float y);                // offset 44 = 0x2C (v9)
    V_SLOT_10(1)  // 10-19
    V_SLOT_10(2)  // 20-29
    virtual int v30(); virtual int v31(); virtual int v32(); virtual int v33(); virtual int v34();
    virtual int v35(); virtual int v36(); virtual int v37();
    virtual int MethodA0(int a1, float x, float y, float z); // offset 160 = 0xA0 (v38)

    char pad_04[0x2E - 0x4];       // offset 4..45
    unsigned char m_mode;          // offset 46 (0x2E)
    char pad_2F[0x38 - 0x2F];      // offset 47..55
    TargetObj *m_target;           // offset 56 (0x38)
    char pad_3C[0x48 - 0x3C];      // offset 60..71
    short m_field48;               // offset 72 (0x48)
    char pad_4A[0xA4 - 0x4A];      // offset 74..163
    short *m_waypoints;            // offset 164 (0xA4)
    int m_waypoint_count;          // offset 168 (0xA8)
    char pad_AC[0xB0 - 0xAC];      // offset 172..175
    int m_waypoint_cap;            // offset 176 (0xB0)
    char pad_B4[0x154 - 0xB4];     // offset 180..339
    float m_field154;              // offset 340 (0x154)
    float m_field158;              // offset 344 (0x158)
};

extern "C" {
    void* func_332e60(void *timer, int id);
    int func_00202B10(void *game);
    void* func_001510D0(void *self);
    int func_001471A0(void *arg);
    int func_1AAB30();
    extern float D_004E2824;

    int func_0014B310(TradeAction *self, int a1, int a2);
    int func_0014B8E0(void *self);
}

#endif // TRADE_ACTION_ROUTE_ADVANCE_H
