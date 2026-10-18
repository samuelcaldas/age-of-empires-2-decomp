#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

int D_4E35DC = 0;

static int method3_called = 0;
static void *method3_ret_override = 0;
static int func_366c30_called = 0;
static int func_34fb10_called = 0;
static int func_34fa60_called = 0;
static int func_147180_called = 0;
static int func_1471b0_called = 0;
static int func_14bd90_called = 0;
static int call_method14_ret = 0;

static int sub_list_v190_called = 0;
static void *sub_list_v190_other = 0;
static int sub_list_v190_a = 0;
static int sub_list_v190_b = 0;

static int sub_list_v194_called = 0;
static void *sub_list_v194_p = 0;

static float sub_list_get_range_val = 15.0f;

extern "C" {
    int func_00139EA0(SubList *self, void *other, float *out, float x, float y, float z);
    float func_0013A090();
    int func_0013A0A0(SubList *self, void *other, float *out, float x, float y, float z);
    void func_0013A230(SubList *self, void *other);

    int CallMethod14__8BaseListFv(void*) {
        return call_method14_ret;
    }
    void* func_366c30(void*) {
        func_366c30_called++;
        return (void*)0x77665544;
    }
    void func_34fb10(void*, void*, void*, int, float) {
        func_34fb10_called++;
    }
    void func_34fa60(void*, void*, float, float, float, int, float) {
        func_34fa60_called++;
    }
    void func_147180(void*, int) {
        func_147180_called++;
    }
    void func_1471b0(void*, int) {
        func_1471b0_called++;
    }
    void func_14bd90(void*, int, int, float, float, float) {
        func_14bd90_called++;
    }
}

void* SubListHelper::v0() { return 0; }
void* SubListHelper::Method3(void*, void*, void*, float, float, float, int, int) {
    method3_called++;
    return method3_ret_override;
}

#define DEF_V10(base) \
    void* SubList::v##base##0() { return 0; } void* SubList::v##base##1() { return 0; } \
    void* SubList::v##base##2() { return 0; } void* SubList::v##base##3() { return 0; } \
    void* SubList::v##base##4() { return 0; } void* SubList::v##base##5() { return 0; } \
    void* SubList::v##base##6() { return 0; } void* SubList::v##base##7() { return 0; } \
    void* SubList::v##base##8() { return 0; } void* SubList::v##base##9() { return 0; }

void* SubList::v0() { return 0; }
void* SubList::v1() { return 0; }
void* SubList::v2() { return 0; }
void* SubList::v3(void*) { return 0; }
void* SubList::v4() { return 0; }
void* SubList::v5() { return 0; }
void* SubList::v6() { return 0; }
void* SubList::v7() { return 0; }
void* SubList::v8() { return 0; }
void* SubList::v9() { return 0; }
void* SubList::v10() { return 0; }
void* SubList::v11() { return 0; }
void* SubList::v12() { return 0; }
void* SubList::v13() { return 0; }
void* SubList::v14() { return 0; }
void* SubList::v15() { return 0; }
void* SubList::v16() { return 0; }
void* SubList::v17(void*, void*, void*) { return 0; }
void* SubList::v18() { return 0; }
void* SubList::v19() { return 0; }
void* SubList::v20() { return 0; }
void* SubList::v21(int) { return 0; }
void* SubList::v22(void*) { return 0; }
void* SubList::v23() { return 0; }
void* SubList::v24(void*) { return 0; }
void* SubList::v25() { return 0; }
void* SubList::v26(void*) { return 0; }
void* SubList::v27() { return 0; }
void* SubList::v28() { return 0; }
void* SubList::v29() { return 0; }

DEF_V10(3)
void* SubList::v40() { return 0; }
void* SubList::v41() { return 0; }
void* SubList::v42(void*, float, float, float) { return 0; }
void* SubList::v43() { return 0; }
void* SubList::v44() { return 0; }
void* SubList::v45() { return 0; }
void* SubList::v46() { return 0; }
void* SubList::v47() { return 0; }
void* SubList::v48() { return 0; }
void* SubList::v49() { return 0; }
DEF_V10(5)
DEF_V10(6)
void* SubList::v70() { return 0; }
float SubList::GetRange() { return sub_list_get_range_val; }
void* SubList::v72() { return 0; }
void* SubList::v73() { return 0; }
void* SubList::v74() { return 0; }
void* SubList::v75() { return 0; }
void* SubList::v76() { return 0; }
void* SubList::v77() { return 0; }
void* SubList::v78() { return 0; }
void* SubList::v79() { return 0; }
DEF_V10(8)
DEF_V10(9)
DEF_V10(10)
DEF_V10(11)
DEF_V10(12)
void* SubList::v130() { return 0; }
void* SubList::v131() { return 0; }
void* SubList::v132() { return 0; }
void* SubList::v133() { return 0; }
void* SubList::v134() { return 0; }
void* SubList::v135() { return 0; }
Vec3 SubList::v136() { Vec3 v; v.x = 0; v.y = 0; v.z = 0; return v; }
void* SubList::v137() { return 0; }
void* SubList::v138() { return 0; }
void* SubList::v139() { return 0; }
DEF_V10(14)
DEF_V10(15)
DEF_V10(16)
DEF_V10(17)
DEF_V10(18)

void* SubList::v190(void *other, int a, int b) {
    sub_list_v190_called++;
    sub_list_v190_other = other;
    sub_list_v190_a = a;
    sub_list_v190_b = b;
    return 0;
}
void* SubList::v193(short) { return 0; }
void* SubList::v194(void *p) {
    sub_list_v194_called++;
    sub_list_v194_p = p;
    return 0;
}
void* SubList::v195() { return 0; }
void* SubList::v196(void*) { return 0; }
void* SubList::v197(short, void*, float, float, float) { return 0; }
void* SubList::v198() { return 0; }
void* SubList::v199() { return 0; }
void* SubList::v200() { return 0; }
BaseList* SubList::v201() { return 0; }

static void test_sub_list_queries_ea0_self() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    float out = 999.0f;
    int res = func_00139EA0(self, self, &out, 1.0f, 2.0f, 3.0f);
    assert(res == -1);
    assert(out == 0.0f);
    printf("SUB_LIST_QUERIES_TEST_0_EA0_SELF_PASSED\n");
}

static void test_sub_list_queries_ea0_direct_s0() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    NodeItem node;
    memset(&node, 0, sizeof(node));
    SubListHelper helper;
    node.m_fieldC8 = &helper;
    self->m_field4 = &node;

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->type = 50;
    spatial->f24 = 12.5f;

    method3_ret_override = spatial;
    method3_called = 0;

    void *other = (void*)0x88776655;
    float out = 0.0f;
    int res = func_00139EA0(self, other, &out, 1.0f, 2.0f, 3.0f);
    assert(res == 50);
    assert(out == 12.5f);
    assert(method3_called == 1);
    printf("SUB_LIST_QUERIES_TEST_1_EA0_DIRECT_S0_PASSED\n");
}

static void test_sub_list_queries_ea0_loop_fallback() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    NodeItem node;
    memset(&node, 0, sizeof(node));
    SubListHelper helper;
    node.m_fieldC8 = &helper;
    node.m_fieldCE = 1;
    node.m_fieldE = 42;
    node.m_field0 = 7;
    self->m_field4 = &node;

    WorldContainer world;
    memset(&world, 0, sizeof(world));
    NodeItem item_match;
    memset(&item_match, 0, sizeof(item_match));
    item_match.m_fieldE = 42;
    item_match.m_field0 = 7;
    item_match.m_fieldCE = 1;
    item_match.m_fieldC8 = &helper;

    NodeItem *items[2];
    items[0] = 0;
    items[1] = &item_match;
    world.m_count = 2;
    world.m_items = items;
    self->m_field8 = &world;

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->type = 75;
    spatial->f24 = 25.0f;

    method3_ret_override = spatial;
    method3_called = 0;

    void *other = (void*)0x88776655;
    float out = 0.0f;
    int res = func_00139EA0(self, other, &out, 1.0f, 2.0f, 3.0f);
    assert(res == 75);
    assert(out == 25.0f);
    printf("SUB_LIST_QUERIES_TEST_2_EA0_LOOP_FALLBACK_PASSED\n");
}

static void test_sub_list_queries_ea0_type_104_scale_le_1() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    NodeItem node;
    memset(&node, 0, sizeof(node));
    SubListHelper helper;
    node.m_fieldC8 = &helper;
    self->m_field4 = &node;

    WorldContainer world;
    memset(&world, 0, sizeof(world));
    ScaleInfo scale;
    scale.m_scale = 0.8f;
    world.m_fieldBAC = &scale;
    self->m_field8 = &world;

    OtherObj other;
    memset(&other, 0, sizeof(other));
    NodeItem other_node;
    memset(&other_node, 0, sizeof(other_node));
    other_node.m_fieldE = 3;
    other.m_field4 = &other_node;

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->type = 104;
    spatial->f24 = 99.0f;

    method3_ret_override = spatial;

    float out = 0.0f;
    int res = func_00139EA0(self, &other, &out, 1.0f, 2.0f, 3.0f);
    assert(res == 104);
    assert(out == 1.0f);
    printf("SUB_LIST_QUERIES_TEST_3_EA0_TYPE_104_LE1_PASSED\n");
}

static void test_sub_list_queries_ea0_type_104_scale_gt_1() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    NodeItem node;
    memset(&node, 0, sizeof(node));
    SubListHelper helper;
    node.m_fieldC8 = &helper;
    self->m_field4 = &node;

    WorldContainer world;
    memset(&world, 0, sizeof(world));
    ScaleInfo scale;
    scale.m_scale = 2.5f;
    world.m_fieldBAC = &scale;
    self->m_field8 = &world;

    OtherObj other;
    memset(&other, 0, sizeof(other));
    NodeItem other_node;
    memset(&other_node, 0, sizeof(other_node));
    other_node.m_fieldE = 3;
    other.m_field4 = &other_node;

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->type = 104;
    spatial->f24 = 99.0f;

    method3_ret_override = spatial;
    sub_list_get_range_val = 18.5f;

    float out = 0.0f;
    int res = func_00139EA0(self, &other, &out, 1.0f, 2.0f, 3.0f);
    assert(res == 104);
    assert(out == 18.5f);
    printf("SUB_LIST_QUERIES_TEST_4_EA0_TYPE_104_GT1_PASSED\n");
}

static void test_sub_list_queries_func_0013a090() {
    float res = func_0013A090();
    assert(res == 0.0f);
    printf("SUB_LIST_QUERIES_TEST_5_A090_PASSED\n");
}

static void test_sub_list_queries_a0a0_self() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    float out = 0.0f;
    int res = func_0013A0A0(self, self, &out, 0, 0, 0);
    assert(res == 0);
    printf("SUB_LIST_QUERIES_TEST_6_A0A0_SELF_PASSED\n");
}

static void test_sub_list_queries_a0a0_method14() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    call_method14_ret = 1;
    void *other = (void*)0x11223344;
    float out = 0.0f;
    int res = func_0013A0A0(self, other, &out, 0, 0, 0);
    assert(res == 1);
    printf("SUB_LIST_QUERIES_TEST_7_A0A0_METHOD14_PASSED\n");
}

static void test_sub_list_queries_a0a0_with_other() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_fieldC5 = 5;

    void *c8_target = (void*)0x44332211;
    self->m_fieldC8 = &c8_target;

    OtherObj other;
    memset(&other, 0, sizeof(other));
    NodeItem node;
    memset(&node, 0, sizeof(node));
    node.m_fieldE = 22;
    other.m_field4 = &node;
    other.m_field24_short = 33;

    call_method14_ret = 0;
    func_366c30_called = 0;
    func_34fb10_called = 0;
    func_147180_called = 0;
    func_1471b0_called = 0;
    func_14bd90_called = 0;
    sub_list_v194_called = 0;

    float out = 0.0f;
    int res = func_0013A0A0(self, &other, &out, 1.0f, 2.0f, 3.0f);
    assert(res == 0);
    assert(func_366c30_called == 1);
    assert(func_34fb10_called == 1);
    assert(func_147180_called == 1);
    assert(func_1471b0_called == 1);
    assert(func_14bd90_called == 1);
    assert(sub_list_v194_called == 1);
    assert(sub_list_v194_p == (void*)0x77665544);
    assert(self->m_fieldC5 == 6);
    printf("SUB_LIST_QUERIES_TEST_8_A0A0_WITH_OTHER_PASSED\n");
}

static void test_sub_list_queries_a0a0_without_other() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_fieldC5 = 10;

    void *c8_target = (void*)0x44332211;
    self->m_fieldC8 = &c8_target;

    call_method14_ret = 0;
    func_366c30_called = 0;
    func_34fa60_called = 0;
    func_147180_called = 0;
    func_1471b0_called = 0;
    func_14bd90_called = 0;
    sub_list_v194_called = 0;

    float out = 0.0f;
    int res = func_0013A0A0(self, 0, &out, 1.0f, 2.0f, 3.0f);
    assert(res == 0);
    assert(func_366c30_called == 1);
    assert(func_34fa60_called == 1);
    assert(func_147180_called == 1);
    assert(func_1471b0_called == 1);
    assert(func_14bd90_called == 1);
    assert(sub_list_v194_called == 1);
    assert(sub_list_v194_p == (void*)0x77665544);
    assert(self->m_fieldC5 == 11);
    printf("SUB_LIST_QUERIES_TEST_9_A0A0_WITHOUT_OTHER_PASSED\n");
}

static void test_sub_list_queries_a230_notify() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_fieldC5 = 20;

    sub_list_v190_called = 0;
    func_0013A230(self, self);
    assert(sub_list_v190_called == 0);
    assert(self->m_fieldC5 == 20);

    void *other = (void*)0x99887766;
    func_0013A230(self, other);
    assert(sub_list_v190_called == 1);
    assert(sub_list_v190_other == other);
    assert(sub_list_v190_a == 1);
    assert(sub_list_v190_b == -1);
    assert(self->m_fieldC5 == 21);
    printf("SUB_LIST_QUERIES_TEST_10_A230_NOTIFY_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-10)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_sub_list_queries_ea0_self();
    else if (mode == 1) test_sub_list_queries_ea0_direct_s0();
    else if (mode == 2) test_sub_list_queries_ea0_loop_fallback();
    else if (mode == 3) test_sub_list_queries_ea0_type_104_scale_le_1();
    else if (mode == 4) test_sub_list_queries_ea0_type_104_scale_gt_1();
    else if (mode == 5) test_sub_list_queries_func_0013a090();
    else if (mode == 6) test_sub_list_queries_a0a0_self();
    else if (mode == 7) test_sub_list_queries_a0a0_method14();
    else if (mode == 8) test_sub_list_queries_a0a0_with_other();
    else if (mode == 9) test_sub_list_queries_a0a0_without_other();
    else if (mode == 10) test_sub_list_queries_a230_notify();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
