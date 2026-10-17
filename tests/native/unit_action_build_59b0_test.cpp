// Tests for func_2759B0 — Milestone 86 (136B)
// Verifies prototype rate and range lookups, including ID 3 entry overriding
// and fallback to proto->field_E8 if ID 3 entry is absent.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_59b0.h"

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

    unsigned char default_rate = 22;
    std::memcpy(proto + 0xE8, &default_rate, sizeof(unsigned char));

    short range = 8;
    std::memcpy(proto + 0x142, &range, sizeof(short));
}

static void test_fallback_rate() {
    unsigned char self[512], proto[512], entries[256];
    setup_test(self, proto, entries);

    short rate = 0, range = 0;
    func_2759B0(self, &rate, &range);
    assert(rate == 22);
    assert(range == 8);
    printf("PASS test_fallback_rate\n");
}

static void test_entry_rate_override() {
    unsigned char self[512], proto[512], entries[256];
    setup_test(self, proto, entries);

    void *entries_ptr = entries;
    std::memcpy(proto + 0xEC, &entries_ptr, sizeof(void *));
    short count = 1;
    std::memcpy(proto + 0xEA, &count, sizeof(short));

    short id0 = 3, val0 = 55;
    std::memcpy(entries, &id0, sizeof(short));
    std::memcpy(entries + 2, &val0, sizeof(short));

    short rate = 0, range = 0;
    func_2759B0(self, &rate, &range);
    assert(rate == 55);
    assert(range == 8);
    printf("PASS test_entry_rate_override\n");
}

int main() {
    test_fallback_rate();
    test_entry_rate_override();
    printf("All unit_action_build_59b0 tests passed!\n");
    return 0;
}
