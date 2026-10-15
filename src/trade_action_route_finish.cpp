#pragma exceptions off
#pragma inline_depth(4)
#include "trade_action_route_finish.h"

static inline void release_buffer(void *buffer) {
    if (buffer) func_00100630(buffer);
}

static inline void copy_entry(ActionEntry *destination, TradeAction *self, int index) {
    destination[index].m_pad0 = self->m_entries[index].m_pad0;
    destination[index].m_type = self->m_entries[index].m_type;
    destination[index].m_field4 = self->m_entries[index].m_field4;
    destination[index].m_field6 = self->m_entries[index].m_field6;
    destination[index].m_f8 = self->m_entries[index].m_f8;
    destination[index].m_fC = self->m_entries[index].m_fC;
    destination[index].m_f10 = self->m_entries[index].m_f10;
    destination[index].m_f14 = self->m_entries[index].m_f14;
}

static inline void copy_entries(TradeAction *self, ActionEntry *entries) {
    for (int index = 0; index < self->m_entry_count; index++)
        copy_entry(entries, self, index);
}

static inline void replace_entries(TradeAction *self, ActionEntry *entries, int capacity) {
    copy_entries(self, entries);
    release_buffer(self->m_entries);
    self->m_entries = entries;
    self->m_entry_cap = (unsigned char)capacity;
}

static inline void shift_entry(TradeAction *self, int index) {
    self->m_entries[index + 1].m_pad0 = self->m_entries[index].m_pad0;
    self->m_entries[index + 1].m_type = self->m_entries[index].m_type;
    self->m_entries[index + 1].m_field4 = self->m_entries[index].m_field4;
    self->m_entries[index + 1].m_field6 = self->m_entries[index].m_field6;
    self->m_entries[index + 1].m_f8 = self->m_entries[index].m_f8;
    self->m_entries[index + 1].m_fC = self->m_entries[index].m_fC;
    self->m_entries[index + 1].m_f10 = self->m_entries[index].m_f10;
    self->m_entries[index + 1].m_f14 = self->m_entries[index].m_f14;
}

static inline void shift_entries(TradeAction *self) {
    for (int index = 0; index < self->m_entry_count; index++) shift_entry(self, index);
}

static inline void append_entry(TradeAction *self, short identifier, short type, short field6,
                               float field8, float field_c, float field10, float field14, short field4) {
    self->m_entries[self->m_entry_count].m_pad0 = identifier;
    self->m_entries[self->m_entry_count].m_type = type;
    self->m_entries[self->m_entry_count].m_field4 = field4;
    self->m_entries[self->m_entry_count].m_field6 = field6;
    self->m_entries[self->m_entry_count].m_f8 = field8;
    self->m_entries[self->m_entry_count].m_fC = field_c;
    self->m_entries[self->m_entry_count].m_f10 = field10;
    self->m_entries[self->m_entry_count].m_f14 = field14;
}

static inline void prepend_entry(TradeAction *self, short identifier, short type, short field6,
                                float field8, float field_c, float field10, float field14, short field4) {
    self->m_entries[0].m_pad0 = identifier;
    self->m_entries[0].m_type = type;
    self->m_entries[0].m_field4 = field4;
    self->m_entries[0].m_field6 = field6;
    self->m_entries[0].m_f8 = field8;
    self->m_entries[0].m_fC = field_c;
    self->m_entries[0].m_f10 = field10;
    self->m_entries[0].m_f14 = field14;
}

static inline void insert_entry(TradeAction *self, short identifier, short type, short field6,
                                float field8, float field_c, float field10, float field14, int prepend, short field4) {
    if (prepend && self->m_entry_count) goto insert_front;
    append_entry(self, identifier, type, field6, field8, field_c, field10, field14, field4);
    return;
insert_front:
    shift_entries(self);
    prepend_entry(self, identifier, type, field6, field8, field_c, field10, field14, field4);
}

int func_00150920(TradeAction *self, short identifier, short type, short field6,
                  float field8, float field_c, float field10, float field14, int prepend, short field4) {
    int capacity;
    ActionEntry *entries;
    if (self->m_entry_cap != self->m_entry_count) goto insert;
    capacity = self->m_entry_cap + 1;
    entries = (ActionEntry *)func_100730((int)((long long)capacity * sizeof(ActionEntry)));
    if (!entries) return 0;
    replace_entries(self, entries, capacity);
insert:
    insert_entry(self, identifier, type, field6, field8, field_c, field10, field14, prepend, field4);
    self->m_entry_count++;
    return 1;
}

int func_001508F0(TradeAction *self, ActionEntry *entry, int prepend) {
    return func_00150920(self, entry->m_pad0, entry->m_type, entry->m_field6,
                         entry->m_f8, entry->m_fC, entry->m_f10, entry->m_f14,
                         prepend, entry->m_field4);
}

static inline void copy_item(TradeItem2 *destination, TradeAction *self, int index) {
    destination[index].m_field0 = self->m_items2[index].m_field0;
    destination[index].m_field2 = self->m_items2[index].m_field2;
    destination[index].m_field4 = self->m_items2[index].m_field4;
    destination[index].m_field8 = self->m_items2[index].m_field8;
    destination[index].m_fieldC = self->m_items2[index].m_fieldC;
    destination[index].m_field10 = self->m_items2[index].m_field10;
}

static inline void replace_items(TradeAction *self, TradeItem2 *items, int capacity) {
    int index;
    memset(items, 0, capacity * sizeof(TradeItem2));
    for (index = 0; index < capacity; index++) items[index].m_field0 = -1;
    for (index = 0; index < self->m_item2_count; index++) copy_item(items, self, index);
    release_buffer(self->m_items2);
    self->m_items2 = items;
    self->m_item2_cap = (unsigned char)capacity;
}

static inline void append_item(TradeAction *self, short identifier, short field2, short field4,
                              int field8, int field_c, int field10) {
    self->m_items2[self->m_item2_count].m_field0 = identifier;
    self->m_items2[self->m_item2_count].m_field2 = field2;
    self->m_items2[self->m_item2_count].m_field4 = field4;
    self->m_items2[self->m_item2_count].m_field8 = field8;
    self->m_items2[self->m_item2_count].m_fieldC = field_c;
    self->m_items2[self->m_item2_count].m_field10 = field10;
}

int func_00150CE0(TradeAction *self, short identifier, short field2, short field4,
                  int field8, int field_c, int field10) {
    int capacity;
    TradeItem2 *items;
    if (self->m_item2_cap != self->m_item2_count) goto append;
    capacity = self->m_item2_cap + 1;
    items = (TradeItem2 *)func_100730((int)((long long)capacity * sizeof(TradeItem2)));
    if (!items) return 0;
    replace_items(self, items, capacity);
append:
    append_item(self, identifier, field2, field4, field8, field_c, field10);
    self->m_item2_count++;
    return 1;
}

int func_00150CC0(TradeAction *self, TradeItem2 *item) {
    return func_00150CE0(self, item->m_field0, item->m_field2, item->m_field4,
                         item->m_field8, item->m_fieldC, item->m_field10);
}
