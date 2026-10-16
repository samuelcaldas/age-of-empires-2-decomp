#include <cassert>
#include <climits>
#include <cstddef>
#include <cstring>
#include "tactical_ai_mode_ops.h"

static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
static_assert(sizeof(TacticalModeManager) == 408, "TacticalModeManager ABI size");
static_assert(offsetof(TacticalModeManager, m_field194) == 404, "m_field194 offset");

static void test_set_and_get_mode() {
    TacticalModeManager mgr;
    std::memset(&mgr, 0xA5, sizeof(mgr));

    const int test_values[] = { 0, 1, 2, 3, 4, 100, -1, INT_MIN, INT_MAX };
    const int count = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < count; i++) {
        func_00309310(&mgr, test_values[i]);
        assert(mgr.m_field194 == test_values[i]);
        assert(func_00309320(&mgr) == test_values[i]);
    }

    // Verify padding is untouched
    unsigned char *raw = reinterpret_cast<unsigned char *>(&mgr);
    for (int i = 0; i < 404; i++) {
        assert(raw[i] == 0xA5);
    }
}

int main() {
    test_set_and_get_mode();
    return 0;
}
