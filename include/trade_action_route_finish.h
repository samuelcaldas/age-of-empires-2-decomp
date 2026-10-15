#ifndef TRADE_ACTION_ROUTE_FINISH_H
#define TRADE_ACTION_ROUTE_FINISH_H

struct ActionEntry {
    short m_pad0;     // 0x0
    short m_type;     // 0x2
    short m_field4;   // 0x4
    short m_field6;   // 0x6
    float m_f8;       // 0x8
    float m_fC;       // 0xC
    float m_f10;      // 0x10
    float m_f14;      // 0x14
};

struct TradeItem2 {
    short m_field0;   // 0x0
    short m_field2;   // 0x2
    short m_field4;   // 0x4
    short pad_06;     // 0x6
    int m_field8;     // 0x8
    int m_fieldC;     // 0xC
    int m_field10;    // 0x10
};

class TradeAction {
public:
    char pad_00[49];
    unsigned char m_entry_count; // offset 49 (0x31)
    unsigned char m_item2_count; // offset 50 (0x32)
    unsigned char m_entry_cap;   // offset 51 (0x33)
    unsigned char m_item2_cap;   // offset 52 (0x34)
    char pad_35[7];
    ActionEntry *m_entries;      // offset 60 (0x3C)
    TradeItem2 *m_items2;        // offset 64 (0x40)

    int AddEntry(short a1, short a2, short a3, float f12, float f13, float f14, float f15, int t0, short t1);
    int AddItem2(short a1, short a2, short a3, int t0, int t1, int t2);
};

extern "C" {
    void* memset(void *s, int c, unsigned int n);
    void* func_100730(void *ptr);
    void* func_00100630(int size);

    int func_001508E0(TradeAction *self, ActionEntry *entry, int a2);
    int func_00150920(TradeAction *self, short a1, short a2, short a3, float f12, float f13, float f14, float f15, int t0, short t1);
    int func_00150CB0(TradeAction *self, TradeItem2 *item);
    int func_00150CE0(TradeAction *self, short a1, short a2, short a3, int t0, int t1, int t2);
}

#endif // TRADE_ACTION_ROUTE_FINISH_H
