#ifndef TRADE_ACTION_MARKET_ROUTE_CALC_H
#define TRADE_ACTION_MARKET_ROUTE_CALC_H

struct TimerNode {
    char pad_00[14];
    short m_id;
    char pad_10[12];
    float m_radius; // offset 28
};

class TargetObj {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual void vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual void vfn69();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual int Method300(float x, float y); // offset 300 = 0x12C (v73)

    TimerNode *m_node;             // offset 4
    void *m_game;                  // offset 8
    char pad_0C[0x44 - 0xC];       // offset 12..67
    float x;                       // offset 68
    float y;                       // offset 72
    float z;                       // offset 76
};

class TradeAction {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual int Method60(int out_x, int out_y); // offset 96 = 0x60 (v22)

    char pad_04[0x38 - 0x4];
    TargetObj *m_target;           // offset 56 (0x38)
    char pad_3C[0x44 - 0x3C];
    short m_field44;               // offset 68 (0x44)
    char pad_46[10];               // offset 70..79
    float m_field50;               // offset 80 (0x50)
    float m_field54;               // offset 84 (0x54)
};

extern "C" {
    int func_123350(float val);
    int func_001AAB30();
    int func_269FF0(void *target, ...);
    int func_0014BDC0(void *self, void *p208, int x, int y);
    int func_269E50(void *target, int x, int y);
    int func_00149D90(void *self, int x, int y);

    int func_0014F250(TradeAction *self, int *out_x, int a2, int a3);
}

#endif // TRADE_ACTION_MARKET_ROUTE_CALC_H
