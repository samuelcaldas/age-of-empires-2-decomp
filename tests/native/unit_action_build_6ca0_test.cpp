// Tests for func_276CA0 — Milestone 98 (104B)
// Verifies ActionBuild building prototype category and task mode validation.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_6ca0.h"

static void setup_test(unsigned char *self, unsigned char *proto, short type, unsigned char byte_0) {
    std::memset(self, 0, 256);
    std::memset(proto, 0, 256);

    void *proto_ptr = proto;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
#endif

    std::memcpy(proto + 0xE, &type, sizeof(short));
    proto[0] = byte_0;
}

static void test_type_other() {
    unsigned char self[256], proto[256];
    setup_test(self, proto, 5, 0);
    assert(func_276CA0(self, 0) == 1);
    printf("PASS test_type_other\n");
}

static void test_type_9_mode_4() {
    unsigned char self[256], proto[256];
    setup_test(self, proto, 9, 0);
    assert(func_276CA0(self, 4) == 1);
    printf("PASS test_type_9_mode_4\n");
}

static void test_type_9_mode_not_4_byte_0_3c() {
    unsigned char self[256], proto[256];
    setup_test(self, proto, 9, 0x3C);
    assert(func_276CA0(self, 1) == 1);
    printf("PASS test_type_9_mode_not_4_byte_0_3c\n");
}

static void test_type_9_mode_not_4_byte_0_not_3c() {
    unsigned char self[256], proto[256];
    setup_test(self, proto, 9, 0x10);
    assert(func_276CA0(self, 1) == 0);
    printf("PASS test_type_9_mode_not_4_byte_0_not_3c\n");
}

static void test_type_10_mode_4() {
    unsigned char self[256], proto[256];
    setup_test(self, proto, 10, 0);
    assert(func_276CA0(self, 4) == 1);
    printf("PASS test_type_10_mode_4\n");
}

static void test_type_58_mode_not_4_byte_0_not_3c() {
    unsigned char self[256], proto[256];
    setup_test(self, proto, 0x3A, 0x20);
    assert(func_276CA0(self, 2) == 0);
    printf("PASS test_type_58_mode_not_4_byte_0_not_3c\n");
}

int main() {
    test_type_other();
    test_type_9_mode_4();
    test_type_9_mode_not_4_byte_0_3c();
    test_type_9_mode_not_4_byte_0_not_3c();
    test_type_10_mode_4();
    test_type_58_mode_not_4_byte_0_not_3c();
    printf("All unit_action_build_6ca0 tests passed!\n");
    return 0;
}
