// Tests for func_00280670 (and func_280670) — Milestone 150 (8B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_80670.h"

static void test_clears_flag() {
    char flag = 0x5A;
    void *dummy_self = (void *)0x1000;
    func_00280670(dummy_self, &flag);
    assert(flag == 0);
    printf("PASS test_clears_flag\n");
}

static void test_multiple_values() {
    const char initial_values[] = { 1, 0x7F, -1, 0x42, -128, 55 };
    const size_t count = sizeof(initial_values) / sizeof(initial_values[0]);

    for (size_t i = 0; i < count; ++i) {
        char flag = initial_values[i];
        void *dummy_self = (void *)0x2000;
        func_00280670(dummy_self, &flag);
        assert(flag == 0);
    }
    printf("PASS test_multiple_values\n");
}

static void test_does_not_modify_neighbors() {
    unsigned char buf[3];
    buf[0] = 0xAA;
    buf[1] = 0xBB;
    buf[2] = 0xCC;

    void *dummy_self = (void *)0x3000;
    func_00280670(dummy_self, (char *)&buf[1]);
    assert(buf[0] == 0xAA);
    assert(buf[1] == 0x00);
    assert(buf[2] == 0xCC);
    printf("PASS test_does_not_modify_neighbors\n");
}

static void test_alias() {
    char flag = 0x33;
    void *dummy_self = (void *)0x4000;
    func_280670(dummy_self, &flag);
    assert(flag == 0);
    printf("PASS test_alias\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) {
            test_clears_flag();
            return 0;
        } else if (case_num == 1) {
            test_multiple_values();
            return 0;
        } else if (case_num == 2) {
            test_does_not_modify_neighbors();
            return 0;
        } else if (case_num == 3) {
            test_alias();
            return 0;
        }
    }
    test_clears_flag();
    test_multiple_values();
    test_does_not_modify_neighbors();
    test_alias();
    printf("All unit_action_build_80670 tests passed!\n");
    return 0;
}
