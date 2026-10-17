// Tests for func_275940 — Milestone 85 (112B)
// Verifies prototype rate and range lookups, including ID 4 entry overriding.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_5940.h"

static void setup_test(unsigned char *self, unsigned char *proto, unsigned char *entries) {
    std::memset(self, 0, 512);
    std::memset(proto, 0, 512);
    std::memset(entries, 0, 256);

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif

    unsigned char default_rate = 15;
    std::memcpy(proto + 0xE8, &default_rate, sizeof(unsigned char));

    short range = 6;
    std::memcpy(proto + 0x11C, &range, sizeof(short));
}

static void test_default_rate_when_entries_null() {
    unsigned char self[512], proto[512], entries[256];
    setup_test(self, proto, entries);

    short rate = 0, range = 0;
    func_275940(self, &rate, &range);

    assert(rate == 15);
    assert(range == 6);
    printf("PASS test_default_rate_when_entries_null\n");
}

static void test_entry_override_rate() {
    unsigned char self[512], proto[512], entries[256];
    setup_test(self, proto, entries);

    void *entries_ptr = entries;
    std::memcpy(proto + 0xEC, &entries_ptr, sizeof(void *));
    short count = 2;
    std::memcpy(proto + 0xEA, &count, sizeof(short));

    // Entry 0: ID 2, val 99
    short id0 = 2, val0 = 99;
    std::memcpy(entries, &id0, sizeof(short));
    std::memcpy(entries + 2, &val0, sizeof(short));

    // Entry 1: ID 4, val 42 (matches)
    short id1 = 4, val1 = 42;
    std::memcpy(entries + 4, &id1, sizeof(short));
    std::memcpy(entries + 6, &val1, sizeof(short));

    short rate = 0, range = 0;
    func_275940(self, &rate, &range);

    assert(rate == 42);
    assert(range == 6);
    printf("PASS test_entry_override_rate\n");
}

int main() {
    test_default_rate_when_entries_null();
    test_entry_override_rate();
    printf("All unit_action_build_5940 tests passed!\n");
    return 0;
}
