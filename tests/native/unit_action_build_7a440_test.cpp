// Tests for func_0027A440 — Milestone 131 (1000B)
// Verifies CombatManager savegame deserialization stream reader.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7a440.h"

static int g_reads_called = 0;
static size_t g_total_bytes_read = 0;

extern "C" int func_226F70(void *, void *dest, unsigned long size) {
    g_reads_called++;
    g_total_bytes_read += size;
    std::memset(dest, 0x11, size);
    return 1;
}

static void test_deserialization() {
    unsigned char self[0x1000], node[64];
    std::memset(self, 0, sizeof(self));
    std::memset(node, 0, sizeof(node));

    void *node_ptr = node;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x1E0, &node_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x1E0, &node_ptr, sizeof(void *));
#endif

    g_reads_called = 0;
    g_total_bytes_read = 0;

    int dummy_stream = 1;
    func_0027A440(self, &dummy_stream);

    assert(g_reads_called > 0);
    assert(g_total_bytes_read > 50);

    // Verify fields populated
    assert(*(int *)(self + 0x5DC) == 0x11111111);
    assert(*(int *)(self + 0x5D8) == 0x11111111);
    assert(*(short *)(self + 0x698) == 0x1111);

    printf("PASS test_deserialization\n");
}

int main() {
    test_deserialization();
    printf("All unit_action_build_7a440 tests passed!\n");
    return 0;
}
