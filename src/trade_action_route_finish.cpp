#pragma exceptions off
#include "trade_action_route_finish.h"

int func_00150920(TradeAction *self, short a1, short a2, short a3, float f12, float f13, float f14, float f15, int t0, short t1) {
    if (self->m_entry_cap == self->m_entry_count) {
        int new_cap = self->m_entry_cap + 1;
        ActionEntry *new_entries = (ActionEntry*)func_100730((void*)((long long)new_cap * 24));
        if (!new_entries) {
            return 0;
        }
        for (int i = 0; i < self->m_entry_count; i++) {
            new_entries[i].m_pad0 = self->m_entries[i].m_pad0;
            new_entries[i].m_type = self->m_entries[i].m_type;
            new_entries[i].m_field4 = self->m_entries[i].m_field4;
            new_entries[i].m_field6 = self->m_entries[i].m_field6;
            new_entries[i].m_f8 = self->m_entries[i].m_f8;
            new_entries[i].m_fC = self->m_entries[i].m_fC;
            new_entries[i].m_f10 = self->m_entries[i].m_f10;
            new_entries[i].m_f14 = self->m_entries[i].m_f14;
        }
        if (self->m_entries != 0) {
            func_00100630((int)self->m_entries);
        }
        self->m_entries = new_entries;
        self->m_entry_cap = (unsigned char)new_cap;
    }

    if (t0 != 0 && self->m_entry_count != 0) {
        for (int i = 0; i < self->m_entry_count; i++) {
            self->m_entries[i + 1].m_pad0 = self->m_entries[i].m_pad0;
            self->m_entries[i + 1].m_type = self->m_entries[i].m_type;
            self->m_entries[i + 1].m_field4 = self->m_entries[i].m_field4;
            self->m_entries[i + 1].m_field6 = self->m_entries[i].m_field6;
            self->m_entries[i + 1].m_f8 = self->m_entries[i].m_f8;
            self->m_entries[i + 1].m_fC = self->m_entries[i].m_fC;
            self->m_entries[i + 1].m_f10 = self->m_entries[i].m_f10;
            self->m_entries[i + 1].m_f14 = self->m_entries[i].m_f14;
        }
        self->m_entries[0].m_pad0 = a1;
        self->m_entries[0].m_type = a2;
        self->m_entries[0].m_field4 = t1;
        self->m_entries[0].m_field6 = a3;
        self->m_entries[0].m_f8 = f12;
        self->m_entries[0].m_fC = f13;
        self->m_entries[0].m_f10 = f14;
        self->m_entries[0].m_f14 = f15;
    } else {
        int idx = self->m_entry_count;
        self->m_entries[idx].m_pad0 = a1;
        self->m_entries[idx].m_type = a2;
        self->m_entries[idx].m_field4 = t1;
        self->m_entries[idx].m_field6 = a3;
        self->m_entries[idx].m_f8 = f12;
        self->m_entries[idx].m_fC = f13;
        self->m_entries[idx].m_f10 = f14;
        self->m_entries[idx].m_f14 = f15;
    }

    self->m_entry_count++;
    return 1;
}

int func_001508E0(TradeAction *self, ActionEntry *entry, int a2) {
    return func_00150920(self, entry->m_pad0, entry->m_type, entry->m_field6,
                         entry->m_f8, entry->m_fC, entry->m_f10, entry->m_f14,
                         a2, entry->m_field4);
}

int func_00150CE0(TradeAction *self, short a1, short a2, short a3, int t0, int t1, int t2) {
    if (self->m_item2_cap == self->m_item2_count) {
        int new_cap = self->m_item2_cap + 1;
        TradeItem2 *new_items = (TradeItem2*)func_100730((void*)((long long)new_cap * 20));
        if (new_items == 0) {
            return 0;
        }
        memset(new_items, 0, new_cap * 20);
        for (int i = 0; i < self->m_item2_count; i++) {
            new_items[i] = self->m_items2[i];
        }
        if (self->m_items2 != 0) {
            func_00100630((int)self->m_items2);
        }
        self->m_items2 = new_items;
        self->m_item2_cap = (unsigned char)new_cap;
    }

    if (t2 != 0 && self->m_item2_count != 0) {
        for (int i = 0; i < self->m_item2_count; i++) {
            self->m_items2[i + 1] = self->m_items2[i];
        }
        self->m_items2[0].m_field0 = a1;
        self->m_items2[0].m_field2 = a2;
        self->m_items2[0].m_field4 = a3;
        self->m_items2[0].m_field8 = t0;
        self->m_items2[0].m_fieldC = t1;
        self->m_items2[0].m_field10 = t2;
    } else {
        int idx = self->m_item2_count;
        self->m_items2[idx].m_field0 = a1;
        self->m_items2[idx].m_field2 = a2;
        self->m_items2[idx].m_field4 = a3;
        self->m_items2[idx].m_field8 = t0;
        self->m_items2[idx].m_fieldC = t1;
        self->m_items2[idx].m_field10 = t2;
    }

    self->m_item2_count++;
    return 1;
}

int func_00150CB0(TradeAction *self, TradeItem2 *item) {
    return func_00150CE0(self, item->m_field0, item->m_field2, item->m_field4,
                         item->m_field8, item->m_fieldC, item->m_field10);
}
