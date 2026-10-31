#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "zone_spatial_grid_clear_tables.h"

struct SpatialGridTables {
    char pad_00[0x12B41C];
    char field_12B41C;
    int field_12B420;
    int field_12B424;
    int field_12B428;
    int field_12B42C;
    int field_12B430;
    int field_12B434;
    int field_12B438;
    int field_12B43C;
    int field_12B440;
    int field_12B444;
    int field_12B448;
    int field_12B44C;
    char buffer_12B450[0x80];
    char buffer_12B4D0[0xA0];
    int field_12B570;
    int field_12B574;
    int field_12B578;
    int field_12B57C;
    int field_12B580;
    char pad_12B5A4[0x12B5A4 - 0x12B580 - 4];
    int field_12B5A4;
    int field_12B5A8;
    int field_12B5AC;
};

extern "C" {
extern int D_00947960[];
extern int D_004E3294;
extern int D_004E3298;
extern int D_004E329C;
extern int D_004E32A0;
extern int D_004E32A4;
extern int D_004E32A8;
extern int D_004E32AC;
extern int D_004E32B0;

static int g_func_117CAC_calls = 0;
static int g_func_001EE850_calls = 0;
static int g_func_1EE8C0_calls = 0;
static int g_func_001EE8F0_calls = 0;

void func_117CAC(void *dst, int val, int size) {
    g_func_117CAC_calls++;
    std::memset(dst, val, size);
}

void func_001EE850(void *self, int p1, int p2, int p3) {
    (void)self;
    assert(p1 == 0 && p2 == 0 && p3 == 0);
    g_func_001EE850_calls++;
}

void func_1EE8C0(void *self, int p1, int p2, int p3) {
    (void)self;
    assert(p1 == 0 && p2 == 0 && p3 == 0);
    g_func_1EE8C0_calls++;
}

void func_001EE8F0(void *self, int p1, float p2) {
    (void)self;
    assert(p1 == 0 && p2 == 0.0f);
    g_func_001EE8F0_calls++;
}
}

static void test_layout() {
    assert(offsetof(SpatialGridTables, field_12B41C) == 0x12B41C);
    assert(offsetof(SpatialGridTables, field_12B420) == 0x12B420);
    assert(offsetof(SpatialGridTables, field_12B44C) == 0x12B44C);
    assert(offsetof(SpatialGridTables, buffer_12B450) == 0x12B450);
    assert(offsetof(SpatialGridTables, buffer_12B4D0) == 0x12B4D0);
    assert(offsetof(SpatialGridTables, field_12B570) == 0x12B570);
    assert(offsetof(SpatialGridTables, field_12B574) == 0x12B574);
    assert(offsetof(SpatialGridTables, field_12B578) == 0x12B578);
    assert(offsetof(SpatialGridTables, field_12B57C) == 0x12B57C);
    assert(offsetof(SpatialGridTables, field_12B580) == 0x12B580);
    assert(offsetof(SpatialGridTables, field_12B5A4) == 0x12B5A4);
    assert(offsetof(SpatialGridTables, field_12B5A8) == 0x12B5A8);
    assert(offsetof(SpatialGridTables, field_12B5AC) == 0x12B5AC);
    assert(sizeof(SpatialGridTables) == 0x12B5B0);
}

static SpatialGridTables *create_initialized_tables() {
    SpatialGridTables *tables = (SpatialGridTables *)std::malloc(sizeof(SpatialGridTables));
    assert(tables != nullptr);
    std::memset(tables, 0xCC, sizeof(SpatialGridTables));

    D_00947960[0] = 1;
    D_00947960[1] = 2;
    D_00947960[2] = 3;
    D_00947960[3] = 4;

    D_004E3294 = 10;
    D_004E3298 = 20;
    D_004E329C = 30;
    D_004E32A0 = 40;
    D_004E32A4 = 50;
    D_004E32A8 = 60;
    D_004E32AC = 70;
    D_004E32B0 = 80;

    g_func_117CAC_calls = 0;
    g_func_001EE850_calls = 0;
    g_func_1EE8C0_calls = 0;
    g_func_001EE8F0_calls = 0;
    return tables;
}

static void test_clear_first_fields() {
    SpatialGridTables *tables = create_initialized_tables();
    func_001ED200(tables);

    assert(tables->field_12B41C == 0);
    assert(tables->field_12B420 == 0);
    assert(tables->field_12B424 == 0);
    assert(tables->field_12B428 == 0);
    assert(tables->field_12B42C == 0);
    assert(tables->field_12B430 == 0);
    assert(tables->field_12B43C == 0);
    assert(tables->field_12B440 == 0);
    assert(tables->field_12B434 == 0);
    assert(tables->field_12B438 == 0);
    assert(tables->field_12B578 == 0);
    assert(tables->field_12B444 == 0);
    assert(tables->field_12B448 == 0);
    assert(tables->field_12B44C == 0);

    std::free(tables);
}

static void test_clear_buffers() {
    SpatialGridTables *tables = create_initialized_tables();
    func_001ED200(tables);

    assert(g_func_117CAC_calls == 2);
    for (int i = 0; i < 0x80; ++i) {
        assert(tables->buffer_12B450[i] == 0);
    }
    for (int i = 0; i < 0xA0; ++i) {
        assert(tables->buffer_12B4D0[i] == 0);
    }

    std::free(tables);
}

static void test_sub_calls() {
    SpatialGridTables *tables = create_initialized_tables();
    func_001ED200(tables);

    assert(g_func_001EE850_calls == 1);
    assert(g_func_1EE8C0_calls == 1);
    assert(g_func_001EE8F0_calls == 1);

    std::free(tables);
}

static void test_second_fields() {
    SpatialGridTables *tables = create_initialized_tables();
    func_001ED200(tables);

    assert(tables->field_12B57C == 0);
    assert(tables->field_12B580 == 0);
    assert(tables->field_12B570 == 0);
    assert(tables->field_12B5AC == 0);
    assert(tables->field_12B5A4 == 0);
    assert(tables->field_12B5A8 == 0);
    assert(tables->field_12B574 == -1);

    std::free(tables);
}

static void test_global_clears() {
    SpatialGridTables *tables = create_initialized_tables();
    func_001ED200(tables);

    assert(D_00947960[0] == 0);
    assert(D_00947960[1] == 0);
    assert(D_00947960[2] == 0);
    assert(D_00947960[3] == 0);

    assert(D_004E3294 == 0);
    assert(D_004E3298 == 0);
    assert(D_004E329C == 0);
    assert(D_004E32A0 == 0);
    assert(D_004E32A4 == 0);
    assert(D_004E32A8 == 0);
    assert(D_004E32AC == 0);
    assert(D_004E32B0 == 0);

    std::free(tables);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_layout();
        test_clear_first_fields();
        test_clear_buffers();
        test_sub_calls();
        test_second_fields();
        test_global_clears();
        std::cout << "PASS" << std::endl;
        return 0;
    }

    int case_id = std::atoi(argv[1]);
    switch (case_id) {
    case 0:
        test_layout();
        break;
    case 1:
        test_clear_first_fields();
        break;
    case 2:
        test_clear_buffers();
        break;
    case 3:
        test_sub_calls();
        break;
    case 4:
        test_second_fields();
        break;
    case 5:
        test_global_clears();
        break;
    default:
        return 2;
    }

    std::cout << "PASS" << std::endl;
    return 0;
}
