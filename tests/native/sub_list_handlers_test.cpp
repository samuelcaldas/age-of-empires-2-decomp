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

static int sub_list_v26_called = 0;
static void *sub_list_v26_item = 0;

static int base_list_has_items_ret = 0;
static void *base_list_head_item_ret = 0;
static int base_list_contains_ret = 0;
static int base_list_contains_id = 0;

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
void* SubList::v26(void *item) {
    sub_list_v26_called++;
    sub_list_v26_item = item;
    return 0;
}
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
void* SubList::v196(void*) { return 0; }
void* SubList::v197() { return 0; }
void* SubList::v198() { return 0; }
void* SubList::v199(short, void*, float, float, float) { return 0; }
void* SubList::v200() { return 0; }
BaseList* SubList::v201() { return 0; }

int BaseList::HasItems() { return base_list_has_items_ret; }
void* BaseList::GetHeadItem() { return base_list_head_item_ret; }
int BaseList::Contains(int id) {
    base_list_contains_id = id;
    return base_list_contains_ret;
}

static void test_sub_list_handlers_ae00_direct_match() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    NodeItem node;
    memset(&node, 0, sizeof(node));
    SubListHelper helper;
    node.m_fieldC8 = &helper;
    self->m_field4 = &node;

    void *dummy_match = (void*)0x12345678;
    method3_call_count = 0;
    method3_first_ret = dummy_match;
    method3_ret_override = dummy_match;

    void *res = self->func_0013AE00(0, 0, 1.0f, 2.0f, 3.0f);
    assert(res == dummy_match);
    assert(method3_call_count == 1);
    printf("SUB_LIST_HANDLERS_TEST_0_AE00_DIRECT_MATCH_PASSED\n");
}

static void test_sub_list_handlers_ae00_loop_fallback() {
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

    void *dummy_match = (void*)0x88776655;
    method3_call_count = 0;
    method3_first_ret = 0; // first call returns 0
    method3_ret_override = dummy_match; // loop call returns match
    sub_list_v26_called = 0;

    void *res = self->func_0013AE00(0, 0, 1.0f, 2.0f, 3.0f);
    assert(res == dummy_match);
    assert(method3_call_count == 2);
    assert(sub_list_v26_called == 1);
    assert(sub_list_v26_item == &item_match);
    printf("SUB_LIST_HANDLERS_TEST_1_AE00_LOOP_FALLBACK_PASSED\n");
}

static void test_sub_list_handlers_ae00_no_match() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    NodeItem node;
    memset(&node, 0, sizeof(node));
    SubListHelper helper;
    node.m_fieldC8 = &helper;
    node.m_fieldCE = 0;
    self->m_field4 = &node;

    method3_call_count = 0;
    method3_first_ret = 0;
    method3_ret_override = 0;

    void *res = self->func_0013AE00(0, 0, 1.0f, 2.0f, 3.0f);
    assert(res == 0);
    printf("SUB_LIST_HANDLERS_TEST_2_AE00_NO_MATCH_PASSED\n");
}

static void test_sub_list_handlers_af70_empty() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    base_list_has_items_ret = 0;
    assert(self->func_0013AF70() == 0);
    printf("SUB_LIST_HANDLERS_TEST_3_AF70_EMPTY_PASSED\n");
}

static void test_sub_list_handlers_af70_has_items() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->m_fieldC = 27;

    base_list_has_items_ret = 1;
    base_list_head_item_ret = spatial;
    assert(self->func_0013AF70() == 27);
    printf("SUB_LIST_HANDLERS_TEST_4_AF70_HAS_ITEMS_PASSED\n");
}

static void test_sub_list_handlers_afc0_field_d0() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    NodeItem node;
    memset(&node, 0, sizeof(node));
    node.m_fieldD0 = 33.5f;
    self->m_field4 = &node;

    assert(self->func_0013AFC0() == 33.5f);
    printf("SUB_LIST_HANDLERS_TEST_5_AFC0_FIELD_D0_PASSED\n");
}

static void test_sub_list_handlers_afd0_null_base() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_fieldCC = 0;

    assert(self->func_0013AFD0() == 0);
    printf("SUB_LIST_HANDLERS_TEST_6_AFD0_NULL_BASE_PASSED\n");
}

static void test_sub_list_handlers_afd0_sum() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->m_field4 = 100;
    spatial->m_fieldC = 25;

    base_list_head_item_ret = spatial;
    assert(self->func_0013AFD0() == 125);
    printf("SUB_LIST_HANDLERS_TEST_7_AFD0_SUM_PASSED\n");
}

static void test_sub_list_handlers_b020_null_base() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_fieldCC = 0;

    assert(self->func_0013B020() == -1);
    printf("SUB_LIST_HANDLERS_TEST_8_B020_NULL_BASE_PASSED\n");
}

static void test_sub_list_handlers_b020_head_exists() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->m_field4 = 42;

    base_list_head_item_ret = spatial;
    assert(self->func_0013B020() == 42);
    printf("SUB_LIST_HANDLERS_TEST_9_B020_HEAD_EXISTS_PASSED\n");
}

static void test_sub_list_handlers_b070() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_fieldCC = 0;

    assert(self->func_0013B070(99) == 0);

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    base_list_contains_ret = 1;
    assert(self->func_0013B070(99) == 1);
    assert(base_list_contains_id == 99);
    printf("SUB_LIST_HANDLERS_TEST_10_B070_PASSED\n");
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
    if (mode == 0) test_sub_list_handlers_ae00_direct_match();
    else if (mode == 1) test_sub_list_handlers_ae00_loop_fallback();
    else if (mode == 2) test_sub_list_handlers_ae00_no_match();
    else if (mode == 3) test_sub_list_handlers_af70_empty();
    else if (mode == 4) test_sub_list_handlers_af70_has_items();
    else if (mode == 5) test_sub_list_handlers_afc0_field_d0();
    else if (mode == 6) test_sub_list_handlers_afd0_null_base();
    else if (mode == 7) test_sub_list_handlers_afd0_sum();
    else if (mode == 8) test_sub_list_handlers_b020_null_base();
    else if (mode == 9) test_sub_list_handlers_b020_head_exists();
    else if (mode == 10) test_sub_list_handlers_b070();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
