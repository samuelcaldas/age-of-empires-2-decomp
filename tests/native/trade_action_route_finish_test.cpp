#include <cassert>
#include <cstddef>
#include <cstdio>
#include "trade_action_route_finish.h"

static_assert(sizeof(ActionEntry) == 24, "ActionEntry ABI");
static_assert(sizeof(TradeItem2) == 20, "TradeItem2 ABI");
static_assert(offsetof(TradeAction, m_entries) == 0x3c, "entry buffer ABI");
static_assert(offsetof(TradeAction, m_items2) == 0x40, "secondary buffer ABI");

extern bool fail_allocation;
extern unsigned int allocation_count;
extern void release_allocations();

static TradeItem2 item(short identifier, int payload) {
    TradeItem2 result = {identifier, -2, -3, 0x1234, 4, 5, payload};
    return result;
}

static void append_to_empty_buffer() {
    TradeAction action = {};
    TradeItem2 incoming = item(-7, 19);
    assert(func_00150CC0(&action, &incoming) == 1);
    assert(action.m_item2_count == 1 && action.m_item2_cap == 1);
    assert(action.m_items2[0].m_field0 == -7 && action.m_items2[0].m_field2 == -2);
    assert(action.m_items2[0].m_field4 == -3);
    assert(action.m_items2[0].pad_06 == 0);
    assert(action.m_items2[0].m_field8 == 4);
    assert(action.m_items2[0].m_fieldC == 5);
    assert(action.m_items2[0].m_field10 == 19);
}

static void append_nonzero_payload_without_shifting() {
    TradeItem2 entries[3] = {item(1, 11), item(2, 22), item(3, 33)};
    TradeAction action = {};
    action.m_items2 = entries;
    action.m_item2_count = 2;
    action.m_item2_cap = 3;
    TradeItem2 incoming = item(8, 99);
    assert(func_00150CC0(&action, &incoming) == 1);
    assert(action.m_item2_count == 3 && action.m_item2_cap == 3);
    assert(entries[0].m_field0 == 1 && entries[1].m_field0 == 2);
    assert(entries[2].m_field0 == 8 && entries[2].m_field10 == 99);
}

static void growth_preserves_fields_not_padding() {
    TradeItem2 entries[2] = {item(1, 11), item(2, 22)};
    TradeAction action = {};
    action.m_items2 = entries;
    action.m_item2_count = action.m_item2_cap = 2;
    TradeItem2 incoming = item(8, 0);
    assert(func_00150CC0(&action, &incoming) == 1);
    assert(action.m_item2_count == 3 && action.m_item2_cap == 3);
    assert(action.m_items2 != entries);
    assert(action.m_items2[0].m_field0 == 1);
    assert(action.m_items2[1].m_field0 == 2);
    assert(action.m_items2[0].pad_06 == 0);
    assert(action.m_items2[1].pad_06 == 0);
    assert(action.m_items2[2].m_field0 == 8);
    assert(action.m_items2[2].m_field10 == 0);
}

static void allocation_failure_preserves_state() {
    TradeItem2 existing = item(1, 11);
    TradeAction action = {};
    action.m_items2 = &existing;
    action.m_item2_count = action.m_item2_cap = 1;
    fail_allocation = true;
    TradeItem2 incoming = item(8, 99);
    assert(func_00150CC0(&action, &incoming) == 0);
    fail_allocation = false;
    assert(action.m_items2 == &existing);
    assert(action.m_item2_count == 1 && action.m_item2_cap == 1);
    assert(existing.m_field0 == 1 && existing.m_field10 == 11);
}

static void append_primary_entry() {
    TradeAction action = {};
    ActionEntry incoming = {-1, -2, -3, -4, 1.5f, 2.5f, 3.5f, 4.5f};
    assert(func_001508F0(&action, &incoming, 1) == 1);
    assert(action.m_entry_count == 1 && action.m_entry_cap == 1);
    assert(action.m_entries[0].m_pad0 == -1);
    assert(action.m_entries[0].m_type == -2);
    assert(action.m_entries[0].m_field4 == -3);
    assert(action.m_entries[0].m_field6 == -4);
    assert(action.m_entries[0].m_f8 == 1.5f);
    assert(action.m_entries[0].m_fC == 2.5f);
    assert(action.m_entries[0].m_f10 == 3.5f);
    assert(action.m_entries[0].m_f14 == 4.5f);
}

static void primary_forward_shift_matches_binary() {
    ActionEntry entries[3] = {{1}, {2}, {3}};
    TradeAction action = {};
    action.m_entries = entries;
    action.m_entry_count = 2;
    action.m_entry_cap = 3;
    ActionEntry incoming = {9};
    assert(func_001508F0(&action, &incoming, 1) == 1);
    assert(action.m_entry_count == 3);
    assert(entries[0].m_pad0 == 9);
    assert(entries[1].m_pad0 == 1 && entries[2].m_pad0 == 1);
}

static void primary_allocation_failure_preserves_state() {
    ActionEntry existing = {7};
    TradeAction action = {};
    action.m_entries = &existing;
    action.m_entry_count = action.m_entry_cap = 1;
    ActionEntry incoming = {9};
    fail_allocation = true;
    assert(func_001508F0(&action, &incoming, 0) == 0);
    fail_allocation = false;
    assert(action.m_entries == &existing && existing.m_pad0 == 7);
    assert(action.m_entry_count == 1 && action.m_entry_cap == 1);
}

static void byte_count_wrap_matches_binary() {
    TradeItem2 entries[255] = {};
    TradeAction action = {};
    action.m_items2 = entries;
    action.m_item2_count = action.m_item2_cap = 255;
    TradeItem2 incoming = item(8, 99);
    assert(func_00150CC0(&action, &incoming) == 1);
    assert(action.m_items2 != entries);
    assert(action.m_item2_count == 0 && action.m_item2_cap == 0);
    assert(action.m_items2[255].m_field0 == 8);
}

typedef void (*RegressionCase)();
static RegressionCase TEST_CASES[] = {
    append_to_empty_buffer, append_nonzero_payload_without_shifting,
    growth_preserves_fields_not_padding, allocation_failure_preserves_state,
    append_primary_entry, primary_forward_shift_matches_binary,
    primary_allocation_failure_preserves_state, byte_count_wrap_matches_binary,
};

int main(int argument_count, char **arguments) {
    assert(argument_count == 2);
    unsigned int index = static_cast<unsigned char>(arguments[1][0]) - '0';
    assert(index < sizeof(TEST_CASES) / sizeof(TEST_CASES[0]));
    TEST_CASES[index]();
    release_allocations();
    std::puts("route buffer regression passed");
    return 0;
}
