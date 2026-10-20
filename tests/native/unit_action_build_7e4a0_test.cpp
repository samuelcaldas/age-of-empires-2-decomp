// Tests for func_0027E4A0 (and func_27E4A0) — Milestone 146 (5088B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_7e4a0.h"

struct ActionDescriptor {
    int cat;
    int idx;
    int a3;
    int t0;
    int t1;
    int t2;
    int t3;
};

static const ActionDescriptor k_descriptors[113] = {
    {1, 20, 107, 0, 0, 0, -1},
    {1, 21, 109, 0, 0, 0, -1},
    {1, 22, 190, 0, 0, 0, -1},
    {1, 41, 188, 0, 0, 0, -1},
    {1, 23, 36, 0, 0, 0, -1},
    {1, 24, 116, 0, 0, 0, -1},
    {1, 25, 32, 0, 0, 0, -1},
    {1, 26, 72, 0, 0, 0, 4159},
    {1, 27, 77, 1, 0, 0, 4163},
    {1, 28, 33, 0, 0, 0, -1},
    {1, 29, 34, 0, 0, 0, -1},
    {1, 30, 115, 0, 0, 0, -1},
    {1, 31, 66, 1, 0, 0, 4161},
    {1, 32, 65, 1, 0, 0, 4153},
    {1, 33, 76, 1, 0, 0, 4165},
    {1, 34, 75, 1, 0, 0, 4164},
    {1, 35, 68, 1, 0, 0, 4162},
    {1, 36, 89, 1, 0, 0, 4166},
    {1, 37, 83, 1, 0, 0, 4184},
    {1, 38, 73, 1, 0, 0, 4185},
    {1, 39, 85, 1, 0, 0, 4167},
    {1, 42, 70, 0, 1, 0, 4170},
    {1, 43, 86, 1, 0, 0, 4183},
    {1, 44, 71, 1, 0, 0, 4187},
    {1, 45, 90, 1, 0, 0, 4189},
    {1, 46, 67, 0, 1, 0, 4192},
    {1, 47, 82, 0, 1, 0, 4193},
    {1, 48, 78, 0, 1, 0, 4194},
    {1, 51, 68, 0, 1, 0, 4195},
    {1, 53, 79, 0, 1, 0, 4196},
    {1, 54, 84, 0, 1, 0, 4197},
    {1, 55, 114, 0, 0, 0, -1},
    {0, 0, 66, 0, 0, 0, 4151},
    {0, 1, 86, 0, 0, 0, 4154},
    {0, 2, 82, 0, 0, 0, 4173},
    {0, 5, 83, 0, 0, 0, 4152},
    {0, 6, 76, 0, 0, 0, 4174},
    {0, 7, 80, 0, 0, 0, 4171},
    {0, 8, 85, 0, 0, 0, 4172},
    {0, 9, 69, 0, 0, 0, 4168},
    {0, 10, 67, 0, 0, 0, 4169},
    {0, 11, 71, 0, 0, 0, 4188},
    {0, 12, 46, 0, 0, 0, -1},
    {0, 13, 73, 0, 0, 0, 4156},
    {0, 14, 84, 0, 0, 0, 4158},
    {2, 0, 37, 0, 0, 0, -1},
    {2, 1, 39, 0, 0, 0, -1},
    {2, 2, 38, 0, 0, 0, -1},
    {2, 3, 40, 0, 0, 0, -1},
    {3, 0, 69, 0, 0, 0, 16344},
    {3, 1, 73, 0, 0, 0, 16157},
    {3, 2, 83, 0, 0, 0, 16131},
    {3, 3, 68, 0, 0, 0, 16144},
    {3, 4, 66, 0, 0, 0, 16135},
    {3, 5, 80, 0, 0, 0, 16202},
    {3, 6, 77, 0, 0, 0, 16161},
    {3, 7, 87, 0, 0, 0, 16203},
    {3, 8, 84, 0, 0, 0, 16178},
    {3, 9, 74, 0, 0, 0, 16156},
    {3, 20, 86, 0, 0, 0, 16142},
    {3, 10, 191, 0, 0, 0, 16185},
    {3, 12, 70, 0, 0, 0, 16149},
    {3, 13, 65, 0, 0, 0, 16128},
    {3, 14, 76, 0, 0, 0, 16171},
    {3, 15, 89, 0, 0, 0, 16138},
    {3, 16, 78, 0, 0, 0, 16164},
    {3, 17, 75, 0, 0, 0, 16169},
    {3, 18, 85, 0, 0, 0, 16176},
    {3, 19, 79, 0, 0, 0, 16182},
    {3, 23, 90, 0, 0, 0, 16464},
    {3, 24, 71, 0, 0, 0, 16487},
    {3, 25, 82, 0, 0, 0, 16495},
    {3, 26, 81, 0, 0, 0, 16504},
    {3, 27, 88, 0, 0, 0, 4155},
    {4, 0, 67, 0, 0, 0, 16121},
    {4, 6, 66, 0, 0, 0, 4191},
    {4, 7, 87, 0, 0, 0, 4709},
    {5, 0, 70, 0, 0, 0, 16090},
    {5, 1, 84, 0, 0, 0, 16089},
    {5, 2, 65, 0, 0, 0, 16436},
    {5, 3, 67, 0, 0, 0, 16287},
    {5, 4, 82, 0, 0, 0, 16426},
    {5, 5, 68, 0, 0, 0, 16424},
    {5, 7, 80, 0, 0, 0, 16443},
    {5, 8, 76, 0, 0, 0, 16106},
    {6, 0, 83, 0, 0, 0, 16079},
    {6, 1, 69, 0, 0, 0, 16078},
    {7, 0, 65, 0, 0, 0, 16083},
    {7, 1, 82, 0, 0, 0, 16087},
    {7, 2, 67, 0, 0, 0, 16085},
    {7, 3, 69, 0, 0, 0, 16086},
    {8, 0, 83, 0, 0, 0, 16326},
    {8, 1, 67, 0, 0, 0, 16416},
    {8, 2, 78, 0, 0, 0, 16068},
    {9, 0, 82, 0, 0, 0, 16094},
    {9, 2, 65, 0, 0, 0, 16095},
    {9, 3, 67, 0, 0, 0, 16093},
    {9, 1, 78, 0, 0, 0, 16096},
    {10, 0, 84, 0, 0, 0, 16099},
    {11, 0, 84, 0, 0, 0, 16100},
    {12, 5, 90, 0, 0, 0, 4180},
    {12, 6, 88, 0, 0, 0, 4178},
    {12, 7, 67, 0, 0, 0, 4179},
    {12, 8, 65, 0, 0, 0, 4175},
    {12, 9, 68, 0, 0, 0, 4176},
    {12, 10, 78, 0, 0, 0, 4157},
    {12, 11, 79, 0, 0, 0, 4177},
    {12, 1, 87, 0, 0, 0, 4701},
    {12, 2, 81, 0, 0, 0, 4702},
    {12, 3, 69, 0, 0, 0, 4703},
    {12, 4, 70, 0, 0, 0, 4704},
    {13, 0, 82, 0, 0, 0, 16097},
    {13, 1, 84, 0, 0, 0, 16101},
};

static int g_func_1C1070_called = 0;
static void *g_last_self = nullptr;
static int g_last_cat = -1;
static int g_last_idx = -1;
static int g_last_a3 = -1;
static int g_last_t0 = -1;
static int g_last_t1 = -1;
static int g_last_t2 = -1;
static int g_last_t3 = -1;

extern "C" {
    void func_1C1070(void *self, int cat, int idx, int a3, int t0, int t1, int t2, int t3) {
        g_func_1C1070_called++;
        g_last_self = self;
        g_last_cat = cat;
        g_last_idx = idx;
        g_last_a3 = a3;
        g_last_t0 = t0;
        g_last_t1 = t1;
        g_last_t2 = t2;
        g_last_t3 = t3;
    }
}

static void test_all_registrations() {
    unsigned char dummy_self[32];
    for (int i = 0; i < 113; ++i) {
        g_func_1C1070_called = 0;
        g_last_self = nullptr;
        g_last_cat = -1;
        g_last_idx = -1;

        func_0027E4A0(dummy_self, k_descriptors[i].cat, k_descriptors[i].idx);

        assert(g_func_1C1070_called == 1);
        assert(g_last_self == dummy_self);
        assert(g_last_cat == k_descriptors[i].cat);
        assert(g_last_idx == k_descriptors[i].idx);
        assert(g_last_a3 == k_descriptors[i].a3);
        assert(g_last_t0 == k_descriptors[i].t0);
        assert(g_last_t1 == k_descriptors[i].t1);
        assert(g_last_t2 == k_descriptors[i].t2);
        assert(g_last_t3 == k_descriptors[i].t3);
    }
    printf("PASS test_all_registrations (113 configurations verified)\n");
}

static void test_unhandled_category() {
    unsigned char dummy_self[32];
    int unhandled_cats[] = {-1, 14, 15, 99, 1000};
    for (int cat : unhandled_cats) {
        g_func_1C1070_called = 0;
        func_0027E4A0(dummy_self, cat, 0);
        assert(g_func_1C1070_called == 0);
    }
    printf("PASS test_unhandled_category\n");
}

static void test_alias() {
    unsigned char dummy_self[32];
    g_func_1C1070_called = 0;
    func_27E4A0(dummy_self, 1, 20);
    assert(g_func_1C1070_called == 1);
    assert(g_last_cat == 1);
    assert(g_last_idx == 20);
    assert(g_last_a3 == 107);
    printf("PASS test_alias\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) {
            test_all_registrations();
            return 0;
        } else if (case_num == 1) {
            test_unhandled_category();
            return 0;
        } else if (case_num == 2) {
            test_alias();
            return 0;
        } else {
            fprintf(stderr, "Unknown test case %d\n", case_num);
            return 1;
        }
    }
    test_all_registrations();
    test_unhandled_category();
    test_alias();
    printf("All unit_action_build_7e4a0 tests passed!\n");
    return 0;
}
