// Tests for func_276D10 — Milestone 99 (52B)
// Verifies ActionBuild building type exclusion filter (rejects types 2 and 21).
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_6d10.h"

static void setup_test(unsigned char *self, unsigned char *proto, short type) {
    std::memset(self, 0, 256);
    std::memset(proto, 0, 256);

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif

    std::memcpy(proto + 0xE, &type, sizeof(short));
}

static void test_type_21() {
    unsigned char self[256], proto[256];
    setup_test(self, proto, 0x15);
    assert(func_276D10(self) == 0);
    printf("PASS test_type_21\n");
}

static void test_type_2() {
    unsigned char self[256], proto[256];
    setup_test(self, proto, 2);
    assert(func_276D10(self) == 0);
    printf("PASS test_type_2\n");
}

static void test_type_valid() {
    unsigned char self[256], proto[256];
    setup_test(self, proto, 1);
    assert(func_276D10(self) == 1);
    setup_test(self, proto, 9);
    assert(func_276D10(self) == 1);
    setup_test(self, proto, 10);
    assert(func_276D10(self) == 1);
    setup_test(self, proto, 58);
    assert(func_276D10(self) == 1);
    printf("PASS test_type_valid\n");
}

int main() {
    test_type_21();
    test_type_2();
    test_type_valid();
    printf("All unit_action_build_6d10 tests passed!\n");
    return 0;
}
