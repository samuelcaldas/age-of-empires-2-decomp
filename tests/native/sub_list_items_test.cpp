#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

static int method3_call_count = 0;
static void *method3_ret_override = 0;
static void *method3_first_ret = 0;

static void *func_1c2680_ret = 0;
static void *func_1c26d0_ret = 0;
static int contains_ret = 0;
static void *create_item_ret = 0;

static int sub_list_v196_called = 0;
static void *sub_list_v196_arg = 0;

static int base_list_add_head_called = 0;
static void *base_list_add_head_item = 0;
static int base_list_add_tail_called = 0;
static void *base_list_add_tail_item = 0;
static int base_list_free_called = 0;
static int base_list_call_method13_ret = 0;
static int base_list_call_method13_called = 0;

extern "C" {
    void* func_1c2680(void *container, short index) {
        (void)container; (void)index;
        return func_1c2680_ret;
    }
    void* func_1c26d0(void *container, short id) {
        (void)container; (void)id;
        return func_1c26d0_ret;
    }
}

void* SubListHelper::v0() { return 0; }
void* SubListHelper::Method3(void*, void*, void*, float, float, float, int, int) {
    method3_call_count++;
    if (method3_call_count == 1) {
        return method3_first_ret;
    }
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
float SubList::GetRange() { return 0.0f; }
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

void* SubList::v190(void*, int, int) { return 0; }
void* SubList::v193(short) { return 0; }
void* SubList::v194(void*) { return 0; }
void* SubList::v195() { return 0; }
void* SubList::v196(void *p) {
    sub_list_v196_called++;
    sub_list_v196_arg = p;
    return 0;
}
void* SubList::v197(short, void*, float, float, float) { return 0; }
void* SubList::v198() { return 0; }
void* SubList::v199() { return 0; }
void* SubList::v200() { return 0; }
BaseList* SubList::v201() { return 0; }

int BaseList::Contains(int) { return contains_ret; }
void* BaseList::CreateItem(void*, float, void*, float, float) { return create_item_ret; }
void BaseList::AddHead(void *item) {
    base_list_add_head_called++;
    base_list_add_head_item = item;
}
void BaseList::AddTail(void *item) {
    base_list_add_tail_called++;
    base_list_add_tail_item = item;
}
void BaseList::Free() {
    base_list_free_called++;
}
int BaseList::CallMethod13() {
    base_list_call_method13_called++;
    return base_list_call_method13_ret;
}

static void test_sub_list_items_func_0013a700_self() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    NodeItem node;
    memset(&node, 0, sizeof(node));
    self->m_field4 = &node;

    NodeItem *res = self->func_0013A700(self, 1.0f, 2.0f, 3.0f);
    assert(res == &node);
    printf("SUB_LIST_ITEMS_TEST_0_A700_SELF_PASSED\n");
}

static void test_sub_list_items_func_0013a700_direct_match() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    NodeItem node;
    memset(&node, 0, sizeof(node));
    SubListHelper helper;
    node.m_fieldC8 = &helper;
    node.m_fieldCE = 1;
    self->m_field4 = &node;

    void *dummy_match = (void*)0x12345678;
    method3_call_count = 0;
    method3_first_ret = dummy_match;
    method3_ret_override = dummy_match;

    void *other = (void*)0x88776655;
    NodeItem *res = self->func_0013A700(other, 1.0f, 2.0f, 3.0f);
    assert(res == &node);
    assert(method3_call_count == 1);
    printf("SUB_LIST_ITEMS_TEST_1_A700_DIRECT_MATCH_PASSED\n");
}

static void test_sub_list_items_func_0013a700_loop_fallback() {
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

    void *dummy_match = (void*)0x12345678;
    method3_call_count = 0;
    method3_first_ret = 0; // first call returns 0
    method3_ret_override = dummy_match; // loop call returns match

    void *other = (void*)0x88776655;
    NodeItem *res = self->func_0013A700(other, 1.0f, 2.0f, 3.0f);
    assert(res == &item_match);
    assert(method3_call_count == 2);
    printf("SUB_LIST_ITEMS_TEST_2_A700_LOOP_FALLBACK_PASSED\n");
}

static void test_sub_list_items_func_0013a870_null_or_contains() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    sub_list_v196_called = 0;
    func_1c2680_ret = 0;
    self->func_0013A870(10);
    assert(sub_list_v196_called == 0);

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->type = 50;
    func_1c2680_ret = spatial;
    contains_ret = 1;

    self->func_0013A870(10);
    assert(sub_list_v196_called == 0);
    printf("SUB_LIST_ITEMS_TEST_3_A870_NULL_OR_CONTAINS_PASSED\n");
}

static void test_sub_list_items_func_0013a870_creates() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->type = 50;

    void *created = (void*)0x998877;
    func_1c2680_ret = spatial;
    contains_ret = 0;
    create_item_ret = created;
    sub_list_v196_called = 0;

    self->func_0013A870(10);
    assert(sub_list_v196_called == 1);
    assert(sub_list_v196_arg == created);
    printf("SUB_LIST_ITEMS_TEST_4_A870_CREATES_PASSED\n");
}

static void test_sub_list_items_func_0013a910_null_or_contains() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    sub_list_v196_called = 0;
    func_1c26d0_ret = 0;
    self->func_0013A910(20);
    assert(sub_list_v196_called == 0);

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->type = 50;
    func_1c26d0_ret = spatial;
    contains_ret = 1;

    self->func_0013A910(20);
    assert(sub_list_v196_called == 0);
    printf("SUB_LIST_ITEMS_TEST_5_A910_NULL_OR_CONTAINS_PASSED\n");
}

static void test_sub_list_items_func_0013a910_creates() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->type = 50;

    void *created = (void*)0x554433;
    func_1c26d0_ret = spatial;
    contains_ret = 0;
    create_item_ret = created;
    sub_list_v196_called = 0;

    self->func_0013A910(20);
    assert(sub_list_v196_called == 1);
    assert(sub_list_v196_arg == created);
    printf("SUB_LIST_ITEMS_TEST_6_A910_CREATES_PASSED\n");
}

static void test_sub_list_items_func_0013a9b0_add_head() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    base_list_add_head_called = 0;
    self->func_0013A9B0(0);
    assert(base_list_add_head_called == 0);

    void *item = (void*)0x112233;
    self->func_0013A9B0(item);
    assert(base_list_add_head_called == 1);
    assert(base_list_add_head_item == item);
    printf("SUB_LIST_ITEMS_TEST_7_A9B0_ADD_HEAD_PASSED\n");
}

static void test_sub_list_items_func_0013a9d0_free_and_add_head() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    base_list_free_called = 0;
    base_list_add_head_called = 0;
    self->func_0013A9D0(0);
    assert(base_list_free_called == 1);
    assert(base_list_add_head_called == 0);

    void *item = (void*)0x445566;
    self->func_0013A9D0(item);
    assert(base_list_free_called == 2);
    assert(base_list_add_head_called == 1);
    assert(base_list_add_head_item == item);
    printf("SUB_LIST_ITEMS_TEST_8_A9D0_FREE_ADD_HEAD_PASSED\n");
}

static void test_sub_list_items_func_0013aa20_add_tail() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    base_list_add_tail_called = 0;
    self->func_0013AA20(0);
    assert(base_list_add_tail_called == 0);

    void *item = (void*)0x778899;
    self->func_0013AA20(item);
    assert(base_list_add_tail_called == 1);
    assert(base_list_add_tail_item == item);
    printf("SUB_LIST_ITEMS_TEST_9_AA20_ADD_TAIL_PASSED\n");
}

static void test_sub_list_items_func_0013aa40() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    base_list_free_called = 0;
    base_list_call_method13_called = 0;
    base_list_call_method13_ret = 1;

    self->func_0013AA40();
    assert(base_list_call_method13_called == 1);
    assert(base_list_free_called == 0);

    base_list_call_method13_ret = 0;
    self->func_0013AA40();
    assert(base_list_call_method13_called == 2);
    assert(base_list_free_called == 1);
    printf("SUB_LIST_ITEMS_TEST_10_AA40_PASSED\n");
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
    if (mode == 0) test_sub_list_items_func_0013a700_self();
    else if (mode == 1) test_sub_list_items_func_0013a700_direct_match();
    else if (mode == 2) test_sub_list_items_func_0013a700_loop_fallback();
    else if (mode == 3) test_sub_list_items_func_0013a870_null_or_contains();
    else if (mode == 4) test_sub_list_items_func_0013a870_creates();
    else if (mode == 5) test_sub_list_items_func_0013a910_null_or_contains();
    else if (mode == 6) test_sub_list_items_func_0013a910_creates();
    else if (mode == 7) test_sub_list_items_func_0013a9b0_add_head();
    else if (mode == 8) test_sub_list_items_func_0013a9d0_free_and_add_head();
    else if (mode == 9) test_sub_list_items_func_0013aa20_add_tail();
    else if (mode == 10) test_sub_list_items_func_0013aa40();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
