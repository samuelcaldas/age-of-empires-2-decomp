#ifndef TRADE_ACTION_ROUTE_FINISH_H
#define TRADE_ACTION_ROUTE_FINISH_H

struct ActionEntry {
    short m_pad0;
    short m_type;
    short m_field4;
    short m_field6;
    float m_f8;
    float m_fC;
    float m_f10;
    float m_f14;
};

struct TradeItem2 {
    short m_field0;
    short m_field2;
    short m_field4;
    short pad_06;
    int m_field8;
    int m_fieldC;
    int m_field10;
};

struct TradeAction {
    char pad_00[0x31];
    unsigned char m_entry_count;
    unsigned char m_item2_count;
    unsigned char m_entry_cap;
    unsigned char m_item2_cap;
    char pad_35[7];
    ActionEntry *m_entries;
    TradeItem2 *m_items2;
};

extern "C" {
    void *memset(void *buffer, int value, unsigned int size);
    void *func_100730(int size);
    void func_00100630(void *buffer);

    /** Insert unpacked entry fields; return zero when allocation fails. */
    int func_00150920(TradeAction *self, short identifier, short type, short field6,
                      float field8, float field_c, float field10, float field14, int prepend, short field4);
    /** Unpack entry fields and forward the insertion mode; return success. */
    int func_001508F0(TradeAction *self, ActionEntry *entry, int prepend);
    /** Append unpacked item fields; return zero when allocation fails. */
    int func_00150CE0(TradeAction *self, short identifier, short field2, short field4,
                      int field8, int field_c, int field10);
    /** Unpack item fields and return the append result. */
    int func_00150CC0(TradeAction *self, TradeItem2 *item);
}

#endif
