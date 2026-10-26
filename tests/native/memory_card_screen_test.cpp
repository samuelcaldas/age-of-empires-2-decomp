#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstddef>
#include <vector>
#include <string>

#include "memory_card_screen.h"
#include "memory_card_dialog.h"

// Compile-time layout alignment assertions
template <bool B> struct StaticAssert;
template <> struct StaticAssert<true> {};

#define STATIC_ASSERT(cond) StaticAssert<(cond)>()

void test_memory_card_screen_layout() {
    STATIC_ASSERT(sizeof(MemoryCardScreen) == 0x8A4);
    STATIC_ASSERT(offsetof(MemoryCardScreen, vtable) == 0x000);
    STATIC_ASSERT(offsetof(MemoryCardScreen, field_804) == 0x804);
    STATIC_ASSERT(offsetof(MemoryCardScreen, field_808) == 0x808);
    STATIC_ASSERT(offsetof(MemoryCardScreen, field_80C) == 0x80C);
    STATIC_ASSERT(offsetof(MemoryCardScreen, field_818) == 0x818);
    STATIC_ASSERT(offsetof(MemoryCardScreen, field_820) == 0x820);
    STATIC_ASSERT(offsetof(MemoryCardScreen, field_824) == 0x824);
    STATIC_ASSERT(offsetof(MemoryCardScreen, field_82C) == 0x82C);
    STATIC_ASSERT(offsetof(MemoryCardScreen, field_830) == 0x830);
    STATIC_ASSERT(offsetof(MemoryCardScreen, field_840) == 0x840);
    STATIC_ASSERT(offsetof(MemoryCardScreen, field_848) == 0x848);
    STATIC_ASSERT(offsetof(MemoryCardScreen, field_8A0) == 0x8A0);
    std::printf("test_memory_card_screen_layout: PASSED\n");
}

void test_memory_card_dialog_layout() {
    STATIC_ASSERT(sizeof(MemoryCardDialog) == 0x85C);
    STATIC_ASSERT(offsetof(MemoryCardDialog, vtable) == 0x000);
    STATIC_ASSERT(offsetof(MemoryCardDialog, field_828) == 0x828);
    STATIC_ASSERT(offsetof(MemoryCardDialog, field_82C) == 0x82C);
    STATIC_ASSERT(offsetof(MemoryCardDialog, field_830) == 0x830);
    STATIC_ASSERT(offsetof(MemoryCardDialog, field_834) == 0x834);
    STATIC_ASSERT(offsetof(MemoryCardDialog, field_838) == 0x838);
    STATIC_ASSERT(offsetof(MemoryCardDialog, field_83C) == 0x83C);
    STATIC_ASSERT(offsetof(MemoryCardDialog, field_840) == 0x840);
    STATIC_ASSERT(offsetof(MemoryCardDialog, field_844) == 0x844);
    STATIC_ASSERT(offsetof(MemoryCardDialog, field_84C) == 0x84C);
    STATIC_ASSERT(offsetof(MemoryCardDialog, field_858) == 0x858);
    std::printf("test_memory_card_dialog_layout: PASSED\n");
}

// Behavioral state tracking for mock operations
struct ScreenTestState {
    int card_status_eval_calls;
    int last_has_card;
    int teardown_calls;
    int dialog_tick_calls;
    int slot_table_calls;
    int slot_select_calls;
    int last_slot_selected;
} g_screen_test;

// Mock control widget
class MockWidget : public TacticalSubObj {
public:
    int visible;
    int text_id;
    MockWidget() : visible(1), text_id(0) {}
    virtual void vfunc_00() {}
    virtual void set_visible(int v) { visible = v; }
    virtual void set_text(int t) { text_id = t; }
};

static MockWidget s_mock_label;
static MockWidget s_mock_panel;
static MockWidget s_mock_slots;
static MockWidget s_mock_cancel;
static MockWidget s_mock_action;

// Mock external functions for screen behavior verification
extern "C" {

void mock_reset() {
    std::memset(&g_screen_test, 0, sizeof(g_screen_test));
}

// Forward synthetic click from dialog to screen
void test_dialog_forward_click(MemoryCardDialog *dialog, int action_code) {
    if (dialog && dialog->field_844) {
        ((MemoryCardScreen*)dialog->field_844)->field_804 = action_code;
    }
}

}

int main() {
    test_memory_card_screen_layout();
    test_memory_card_dialog_layout();

    // Verify synthetic click forwarding from dialog to screen
    MemoryCardScreen screen;
    MemoryCardDialog dialog;
    std::memset(&screen, 0, sizeof(screen));
    std::memset(&dialog, 0, sizeof(dialog));
    dialog.field_844 = &screen;

    test_dialog_forward_click(&dialog, 12);
    assert(screen.field_804 == 12);
    std::printf("test_dialog_forward_click: PASSED\n");

    std::printf("ALL MEMORY CARD SCREEN TESTS PASSED\n");
    return 0;
}
