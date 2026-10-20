#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>

#include "unit_action_build_818d0.h"

struct Table2 {
    char pad_0[2976];
    int active_id;        // 0xBA0
};

struct D90160Entry {
    int field_0;
    int field_4;
};

static Table2 g_table2_mock;
static int g_table1c_mock = 0x5555;
static D90160Entry g_d90160_mock[16];
static unsigned char g_d8f45f_mock[4096];

struct DelegationRecord {
    int code;
    void *callback;
    void *param;
};
static std::vector<DelegationRecord> g_delegations;
static void *g_func_141470_called_with = 0;
static int g_func_141470_ret = 0;

extern "C" {
void *D_4E341C = &g_table1c_mock;
void *D_4E3420 = &g_table2_mock;
D90160Entry D_00D90160[16];
unsigned char D_00D8F45F[4096];

void func_002807D0(int code, void (*callback)(int, void *), void *param) {
    DelegationRecord rec;
    rec.code = code;
    rec.callback = (void *)callback;
    rec.param = param;
    g_delegations.push_back(rec);
}

int func_00141470(void *mgr) {
    g_func_141470_called_with = mgr;
    return g_func_141470_ret;
}
}

static void setup_mocks() {
    g_delegations.clear();
    g_func_141470_called_with = 0;
    g_func_141470_ret = 0;
    std::memset(&g_table2_mock, 0, sizeof(g_table2_mock));
    std::memset(D_00D90160, 0, sizeof(D_00D90160));
    std::memset(D_00D8F45F, 0xFF, sizeof(D_00D8F45F));
}

static void test_delegation_path() {
    setup_mocks();
    int dummy = 0x1234;

    // Boundary negative codes [-205, -100]
    func_002818D0(-101, &dummy);
    assert(g_delegations.size() == 1);
    assert(g_delegations[0].code == -101);
    assert(g_delegations[0].callback == (void *)func_002818D0);
    assert(g_delegations[0].param == &dummy);

    func_002818D0(-205, &dummy);
    assert(g_delegations.size() == 2);
    assert(g_delegations[1].code == -205);
    assert(g_delegations[1].callback == (void *)func_002818D0);

    func_002818D0(-150, &dummy);
    assert(g_delegations.size() == 3);
    assert(g_delegations[2].code == -150);

    // Negative codes outside [-205, -100] should not delegate
    func_002818D0(-99, &dummy);
    assert(g_delegations.size() == 3);

    func_002818D0(-206, &dummy);
    assert(g_delegations.size() == 3);

    std::printf("PASS test_delegation_path\n");
}

static void test_jumptable_lookup_path() {
    setup_mocks();
    g_table2_mock.active_id = 3;
    g_func_141470_ret = 42;

    // For all 11 codes (101 to 111):
    for (int code = 101; code <= 111; ++code) {
        int index = code - 101;
        // Case A: field_4 == -1 -> failure, no bitmask modification
        D_00D90160[index].field_0 = 1;
        D_00D90160[index].field_4 = -1;
        int p = 10;
        int offset = (3 << 8) + p;
        D_00D8F45F[offset] = 0xFF;
        func_002818D0(code, (void *)(size_t)p);
        assert(D_00D8F45F[offset] == 0xFF);

        // Case B: field_4 mismatch with func_00141470 -> failure
        D_00D90160[index].field_4 = 999;
        func_002818D0(code, (void *)(size_t)p);
        assert(g_func_141470_called_with == &g_table1c_mock);
        assert(D_00D8F45F[offset] == 0xFF);

        // Case C: field_4 match, field_0 == -1 -> failure
        D_00D90160[index].field_4 = 42;
        D_00D90160[index].field_0 = -1;
        func_002818D0(code, (void *)(size_t)p);
        assert(D_00D8F45F[offset] == 0xFF);

        // Case D: field_4 match, field_0 == 5 -> success, clears bit (5 - 1) = bit 4 = 0x10
        D_00D90160[index].field_0 = 5;
        func_002818D0(code, (void *)(size_t)p);
        assert(D_00D8F45F[offset] == (0xFF & ~0x10));
    }
    std::printf("PASS test_jumptable_lookup_path\n");
}

static void test_direct_id_bitmask_path() {
    setup_mocks();
    g_table2_mock.active_id = 1;
    int p = 15;
    int offset = (1 << 8) + p;

    // Direct ID = 2 (not in 101..111), clears bit (2-1) = bit 1 = 0x02
    assert(D_00D8F45F[offset] == 0xFF);
    func_002818D0(2, (void *)(size_t)p);
    assert(D_00D8F45F[offset] == 0xFD);

    // Direct ID = 8, clears bit 7 = 0x80
    func_002818D0(8, (void *)(size_t)p);
    assert(D_00D8F45F[offset] == (0xFD & ~0x80));

    std::printf("PASS test_direct_id_bitmask_path\n");
}

static void test_param_boundaries() {
    setup_mocks();
    g_table2_mock.active_id = 0;

    // p <= 0: no update
    func_002818D0(1, (void *)0);
    func_002818D0(1, (void *)-1);
    for (int i = 0; i < 4096; ++i) {
        assert(D_00D8F45F[i] == 0xFF);
    }

    // p == 1: valid, offset 1
    func_002818D0(1, (void *)1);
    assert(D_00D8F45F[1] == 0xFE);

    // p == 256: valid, offset 256
    func_002818D0(1, (void *)256);
    assert(D_00D8F45F[256] == 0xFE);

    // p == 257: out of bounds, no update
    func_002818D0(1, (void *)257);
    assert(D_00D8F45F[257] == 0xFF);

    std::printf("PASS test_param_boundaries\n");
}

static void test_alias() {
    setup_mocks();
    int dummy = 0x9999;

    // Test delegation through alias
    func_2818D0(-101, &dummy);
    assert(g_delegations.size() == 1);
    assert(g_delegations[0].code == -101);
    assert(g_delegations[0].param == &dummy);

    // Test direct bitmask clear path through alias
    g_table2_mock.active_id = 2;
    int p = 12;
    func_2818D0(4, (void *)(size_t)p);
    assert(D_00D8F45F[(2 << 8) + p] == (0xFF & ~(1 << 3)));

    // Test jumptable lookup path through alias
    g_func_141470_ret = 42;
    D_00D90160[0].field_0 = 7;
    D_00D90160[0].field_4 = 42;
    int p2 = 25;
    func_2818D0(101, (void *)(size_t)p2);
    assert(D_00D8F45F[(2 << 8) + p2] == (0xFF & ~(1 << 6)));

    std::printf("PASS test_alias\n");
}

int main() {
    test_delegation_path();
    test_jumptable_lookup_path();
    test_direct_id_bitmask_path();
    test_param_boundaries();
    test_alias();
    std::printf("All unit_action_build_818d0 tests passed!\n");
    return 0;
}
