#ifndef TRADE_ACTION_ROUTE_SEARCH_H
#define TRADE_ACTION_ROUTE_SEARCH_H

#define V_SLOT_10(base) \
    virtual int v##base##0(); virtual int v##base##1(); virtual int v##base##2(); virtual int v##base##3(); virtual int v##base##4(); \
    virtual int v##base##5(); virtual int v##base##6(); virtual int v##base##7(); virtual int v##base##8(); virtual int v##base##9();

struct TimerNode {
    char pad_00[14];
    short m_id;
};

class TargetObj {
public:
    virtual void vfn0();
    void *m_node_ptr;              // offset 4
    void *m_game;                  // offset 8
    char pad_0C[0x39 - 0xC];       // offset 12..56
    unsigned char m_field39;       // offset 57
    char pad_3A[0x44 - 0x3A];      // offset 58..67
    float x;                       // offset 68
    float y;                       // offset 72
    float z;                       // offset 76

    TimerNode* GetNode() { return (TimerNode*)m_node_ptr; }
};

struct RouteItem {
    char pad[2];
    short m_id;
    char pad_04[20];
};

class TradeAction {
public:
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8();
    virtual int Method2C(int a1, float x, float y);       // offset 44 = 0x2C (v9)
    virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14();
    virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19();
    virtual int Method58(short id);                        // offset 88 = 0x58 (v20)

    char pad_04[45];
    unsigned char m_item_count;    // offset 49 (0x31)
    char pad_32[6];
    TargetObj *m_target;           // offset 56 (0x38)
    RouteItem *m_items;            // offset 60 (0x3C)
};

extern "C" {
    void* func_332e60(void *timer, int id);
    extern int *D_F99910[];
    extern int D_F99930[];

    int func_0014C110(TradeAction *self, int mode, int *results, int *p_count, int max_results);
    int func_0014C420(TradeAction *self, int a1);
}

#endif // TRADE_ACTION_ROUTE_SEARCH_H
