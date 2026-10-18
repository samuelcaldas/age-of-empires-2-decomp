// Tests for func_0027A830 — Milestone 132 (1148B)
// Verifies CombatManager savegame serialization stream writer.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7a830.h"

static int g_writes_called = 0;
static size_t g_total_bytes_written = 0;

extern "C" int func_226D90(void *, const void *, unsigned long size) {
    g_writes_called++;
    g_total_bytes_written += size;
    return 1;
}

static void test_serialization() {
    unsigned char self[0x1000], node[64];
    std::memset(self, 0x22, sizeof(self));
    std::memset(node, 0x33, sizeof(node));

    void *node_ptr = node;
    void *null_ptr = nullptr;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x1E0, &node_ptr, sizeof(void *));
    std::memcpy(node + 0x20, &null_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x1E0, &node_ptr, sizeof(void *));
    std::memcpy(node + 0x18, &null_ptr, sizeof(void *));
#endif

    g_writes_called = 0;
    g_total_bytes_written = 0;

    int dummy_stream = 1;
    func_0027A830(self, &dummy_stream);

    assert(g_writes_called > 0);
    assert(g_total_bytes_written > 50);

    printf("PASS test_serialization\n");
}

int main() {
    test_serialization();
    printf("All unit_action_build_7a830 tests passed!\n");
    return 0;
}
