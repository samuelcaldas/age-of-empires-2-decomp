#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_buffer_manager_insert.h"

struct ElementTeam {
    char pad_00[0xBA0];
    int team;
};

struct Element {
    char pad_00[0x4];
    unsigned char *type_info; // 0x04
    ElementTeam *team_obj;    // 0x08
    char pad_0C[0x18];        // 0x0C - 0x23
    short flag_24;            // 0x24
    char pad_26[0xA0];        // 0x26 - 0xC5
    unsigned char flag_C6;    // 0xC6
    char pad_C7[0x2D];        // 0xC7 - 0xF3
    char data_F4[16];         // 0xF4
};

struct SpatialGridBufferManager {
    ElementTeam *owner;       // 0x000
    Element *elems[200];      // 0x004
    void *ptrs[200];          // 0x324
    int vals[200];            // 0x644
    short shorts[200];        // 0x964
    short cap;                // 0xAF4
    short count;              // 0xAF6
};

static void test_layout() {
    assert(offsetof(ElementTeam, team) == 0xBA0);
    assert(offsetof(Element, type_info) == 0x04);
    assert(offsetof(Element, team_obj) == 0x08);
    assert(offsetof(Element, flag_24) == 0x24);
    assert(offsetof(Element, flag_C6) == 0xC6);
    assert(offsetof(Element, data_F4) == 0xF4);

    assert(offsetof(SpatialGridBufferManager, owner) == 0x000);
    assert(offsetof(SpatialGridBufferManager, elems) == 0x004);
    assert(offsetof(SpatialGridBufferManager, ptrs) == 0x324);
    assert(offsetof(SpatialGridBufferManager, vals) == 0x644);
    assert(offsetof(SpatialGridBufferManager, shorts) == 0x964);
    assert(offsetof(SpatialGridBufferManager, cap) == 0xAF4);
    assert(offsetof(SpatialGridBufferManager, count) == 0xAF6);
    assert(sizeof(SpatialGridBufferManager) == 0xAF8);
}

static void test_capacity_full() {
    SpatialGridBufferManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.cap = 10;
    mgr.count = 10;

    Element elem;
    std::memset(&elem, 0, sizeof(elem));
    int dummy_val = 123;

    int ret = func_001ECC00(&mgr, &elem, &dummy_val);
    assert(ret == 0);
    assert(mgr.count == 10);
}

static void test_team_mismatch() {
    SpatialGridBufferManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.cap = 10;
    mgr.count = 0;

    ElementTeam owner_team;
    owner_team.team = 1;
    mgr.owner = &owner_team;

    ElementTeam elem_team;
    elem_team.team = 2;

    Element elem;
    std::memset(&elem, 0, sizeof(elem));
    elem.team_obj = &elem_team;

    int dummy_val = 123;
    int ret = func_001ECC00(&mgr, &elem, &dummy_val);
    assert(ret == 0);
    assert(mgr.count == 0);
}

static void test_duplicate_element() {
    SpatialGridBufferManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.cap = 10;
    mgr.count = 1;

    ElementTeam owner_team;
    owner_team.team = 1;
    mgr.owner = &owner_team;

    Element elem;
    std::memset(&elem, 0, sizeof(elem));
    elem.team_obj = &owner_team;

    mgr.elems[0] = &elem;

    int dummy_val = 123;
    int ret = func_001ECC00(&mgr, &elem, &dummy_val);
    assert(ret == 0);
    assert(mgr.count == 1);
}

static void test_insert_success_normal() {
    SpatialGridBufferManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.cap = 10;
    mgr.count = 0;

    ElementTeam owner_team;
    owner_team.team = 3;
    mgr.owner = &owner_team;

    unsigned char type = 0x20;
    Element elem;
    std::memset(&elem, 0, sizeof(elem));
    elem.team_obj = &owner_team;
    elem.type_info = &type;
    elem.flag_24 = 0x1234;
    elem.flag_C6 = 0;

    int dummy_val = 0x55AA;
    int ret = func_001ECC00(&mgr, &elem, &dummy_val);
    assert(ret == 1);
    assert(mgr.count == 1);
    assert(mgr.elems[0] == &elem);
    assert(mgr.ptrs[0] == &dummy_val);
    assert(mgr.vals[0] == 0x55AA);
    assert(mgr.shorts[0] == 0x1234);
}

static void test_insert_success_override_ptr() {
    SpatialGridBufferManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    mgr.cap = 10;
    mgr.count = 0;

    ElementTeam owner_team;
    owner_team.team = 3;
    mgr.owner = &owner_team;

    unsigned char type = 0x35; // >= 0x32
    Element elem;
    std::memset(&elem, 0, sizeof(elem));
    elem.team_obj = &owner_team;
    elem.type_info = &type;
    elem.flag_24 = 0x4321;
    elem.flag_C6 = 1; // > 0

    int dummy_val = 0x9999;
    int ret = func_001ECC00(&mgr, &elem, &dummy_val);
    assert(ret == 1);
    assert(mgr.count == 1);
    assert(mgr.elems[0] == &elem);
    assert(mgr.ptrs[0] == (void *)elem.data_F4);
    assert(mgr.vals[0] == 0x9999);
    assert(mgr.shorts[0] == 0x4321);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_layout();
        test_capacity_full();
        test_team_mismatch();
        test_duplicate_element();
        test_insert_success_normal();
        test_insert_success_override_ptr();
        return 0;
    }

    int test_case = std::atoi(argv[1]);
    switch (test_case) {
    case 0:
        test_layout();
        break;
    case 1:
        test_capacity_full();
        break;
    case 2:
        test_team_mismatch();
        break;
    case 3:
        test_duplicate_element();
        break;
    case 4:
        test_insert_success_normal();
        break;
    case 5:
        test_insert_success_override_ptr();
        break;
    default:
        return 1;
    }
    return 0;
}
