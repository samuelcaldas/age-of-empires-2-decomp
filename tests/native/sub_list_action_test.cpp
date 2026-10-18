#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

static int method3_called = 0;
static void *method3_ret_override = 0;
static void *method3_first_ret = 0;
static int call_method15_ret = 0;
static void *create_item_ret = 0;

static int sub_list_v24_called = 0;
static void *sub_list_v24_item = 0;

static int sub_list_v42_called = 0;
static void *sub_list_v42_other = 0;

static int sub_list_v194_called = 0;
static void *sub_list_v194_p = 0;

static int sub_list_v197_called = 0;
static short sub_list_v197_action = 0;
static void *sub_list_v197_other = 0;

static int mock_method16_called = 0;
static void *mock_method16_world = 0;
static int mock_method17_called = 0;
static void *mock_method17_world = 0;

class NodeItemBaseData {
public:
    char pad_00[0xA0];
};

class NodeActionTarget : public NodeItemBaseData {
public:
    virtual void* v0(); virtual void* v1(); virtual void* v2(); virtual void* v3();
    virtual void* v4(); virtual void* v5(); virtual void* v6(); virtual void* v7();
    virtual void* v8(); virtual void* v9(); virtual void* v10(); virtual void* v11();
    virtual void* v12(); virtual void* v13(); virtual void* v14(); virtual void* v15();
    virtual void Method16(void *world);
    virtual void Method17(void *world);
};

void* NodeActionTarget::v0() { return 0; }
void* NodeActionTarget::v1() { return 0; }
void* NodeActionTarget::v2() { return 0; }
void* NodeActionTarget::v3() { return 0; }
void* NodeActionTarget::v4() { return 0; }
void* NodeActionTarget::v5() { return 0; }
void* NodeActionTarget::v6() { return 0; }
void* NodeActionTarget::v7() { return 0; }
void* NodeActionTarget::v8() { return 0; }
void* NodeActionTarget::v9() { return 0; }
void* NodeActionTarget::v10() { return 0; }
void* NodeActionTarget::v11() { return 0; }
void* NodeActionTarget::v12() { return 0; }
void* NodeActionTarget::v13() { return 0; }
void* NodeActionTarget::v14() { return 0; }
void* NodeActionTarget::v15() { return 0; }
void NodeActionTarget::Method16(void *world) {
    mock_method16_called++;
    mock_method16_world = world;
}
void NodeActionTarget::Method17(void *world) {
    mock_method17_called++;
    mock_method17_world = world;
}

struct VBaseList {
    virtual void* v0();
    virtual void* v1();
    virtual void* CreateItem(void *s0, void *other, float x, float y, float z);
};

void* VBaseList::v0() { return 0; }
void* VBaseList::v1() { return 0; }
void* VBaseList::CreateItem(void *s0, void *other, float x, float y, float z) {
    (void)s0; (void)other; (void)x; (void)y; (void)z;
    return create_item_ret;
}

struct SpatialObjV8 {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual int v8();
};

void* SpatialObjV8::v0() { return 0; }
void* SpatialObjV8::v1() { return 0; }
void* SpatialObjV8::v2() { return 0; }
void* SpatialObjV8::v3() { return 0; }
void* SpatialObjV8::v4() { return 0; }
void* SpatialObjV8::v5() { return 0; }
int SpatialObjV8::v8() { return 88; }

extern "C" {
    void func_0013A280(SubList *self, void *other, int a2, int mode, float x, float y, float z);
    void func_0013A6A0(SubList *self);
    void func_0013A6C0();
    void func_0013A6D0(SubList *self);
    void func_0013A6F0();

    int CallMethod15__8BaseListFv(void *list, void *other, float x, float y, float z) {
        (void)list; (void)other; (void)x; (void)y; (void)z;
        return call_method15_ret;
    }
}

void* SubListHelper::v0() { return 0; }
void* SubListHelper::Method3(void*, void*, void*, float, float, float, int, int) {
    method3_called++;
    if (method3_called == 1 && method3_first_ret) {
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
void* SubList::v24(void *item) {
    sub_list_v24_called++;
    sub_list_v24_item = item;
    return 0;
}
void* SubList::v25() { return 0; }
void* SubList::v26(void*) { return 0; }
void* SubList::v27() { return 0; }
void* SubList::v28() { return 0; }
void* SubList::v29() { return 0; }

DEF_V10(3)
void* SubList::v40() { return 0; }
void* SubList::v41() { return 0; }
void* SubList::v42(void *other, float, float, float) {
    sub_list_v42_called++;
    sub_list_v42_other = other;
    return 0;
}
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
void* SubList::v194(void *p) {
    sub_list_v194_called++;
    sub_list_v194_p = p;
    return 0;
}
void* SubList::v195() { return 0; }
void* SubList::v196(void*) { return 0; }
void* SubList::v197(short action_id, void *other, float, float, float) {
    sub_list_v197_called++;
    sub_list_v197_action = action_id;
    sub_list_v197_other = other;
    return 0;
}
void* SubList::v198() { return 0; }
void* SubList::v199() { return 0; }
void* SubList::v200() { return 0; }
BaseList* SubList::v201() { return 0; }

static int base_list_has_items_ret = 0;
static void *base_list_head_item_ret = 0;
static int base_list_head_field30_ret = 0;

int BaseList::HasItems() { return base_list_has_items_ret; }
void* BaseList::GetHeadItem() { return base_list_head_item_ret; }
int BaseList::GetHeadItemField30() { return base_list_head_field30_ret; }

void ListItem::v0() {}
void ListItem::v1() {}
void ListItem::v2() {}
void ListItem::v3() {}
int ListItem::Action() { return 0; }
void ListItem::Save(void*) {}
int ListItem::v8() { return 0; }
void ListItem::Method9(void*, void*, void*) {}
bool ListItem::Method10() { return false; }
void ListItem::Method11() {}
bool ListItem::Method12() { return false; }
int ListItem::Method13() { return 0; }
int ListItem::Method14() { return 0; }
int ListItem::Method15(void*, float, float, float) { return 0; }
void ListItem::v16() {}
void ListItem::v17() {}
void ListItem::Method18(int) {}
void ListItem::Method19(int, int, int) {}
void ListItem::v20() {}
void* ListItem::v21() { return 0; }
void ListItem::v22() {}
void ListItem::v23() {}
void ListItem::v24() {}
void ListItem::v25() {}
void ListItem::Method26() {}

class MockActionItem : public ListItem {
public:
    void *m_v21_val;
    int m_v8_val;
    int m_method15_ret;
    virtual void* v21() { return m_v21_val; }
    virtual int v8() { return m_v8_val; }
    virtual int Method15(void*, float, float, float) { return m_method15_ret; }
};

static void test_sub_list_action_self_guard() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    sub_list_v197_called = 0;
    func_0013A280(self, self, 0, 0, 1.0f, 2.0f, 3.0f);
    assert(sub_list_v197_called == 0);
    printf("SUB_LIST_ACTION_TEST_0_SELF_GUARD_PASSED\n");
}

static void test_sub_list_action_head_field30() {
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

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    MockActionItem head_item;
    head_item.m_v8_val = 12;

    method3_first_ret = 0;
    method3_ret_override = spatial;
    base_list_head_field30_ret = (int)spatial;
    call_method15_ret = 1;
    base_list_head_item_ret = &head_item;
    base_list_has_items_ret = 0;
    sub_list_v197_called = 0;

    void *other = (void*)0x88776655;
    func_0013A280(self, other, 0, 0, 1.0f, 2.0f, 3.0f);
    assert(sub_list_v197_called == 1);
    assert(sub_list_v197_action == 12);
    assert(sub_list_v197_other == other);
    printf("SUB_LIST_ACTION_TEST_1_HEAD_FIELD30_PASSED\n");
}

static void test_sub_list_action_has_items_type9() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    NodeItem node;
    memset(&node, 0, sizeof(node));
    SubListHelper helper;
    node.m_fieldC8 = &helper;
    self->m_field4 = &node;

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    void *other = (void*)0x88776655;
    MockActionItem head_item;
    head_item.m_v21_val = other;
    head_item.m_v8_val = 9;
    head_item.m_method15_ret = 1;

    method3_first_ret = 0;
    method3_ret_override = 0;
    base_list_head_field30_ret = 0;
    base_list_has_items_ret = 1;
    base_list_head_item_ret = &head_item;
    sub_list_v197_called = 0;

    func_0013A280(self, other, 0, -1, 1.0f, 2.0f, 3.0f);
    assert(sub_list_v197_called == 1);
    assert(sub_list_v197_action == 9);
    assert(sub_list_v197_other == other);
    printf("SUB_LIST_ACTION_TEST_2_HAS_ITEMS_TYPE9_PASSED\n");
}

static void test_sub_list_action_create_item() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    NodeItem node;
    memset(&node, 0, sizeof(node));
    SubListHelper helper;
    node.m_fieldC8 = &helper;
    self->m_field4 = &node;

    char baselist_storage[sizeof(BaseList) + 16];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    VBaseList *vbase = new (baselist_storage) VBaseList();
    self->m_fieldCC = (BaseList*)vbase;

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->type = 50;

    char v8_storage[sizeof(SpatialObjV8)];
    memset(v8_storage, 0, sizeof(v8_storage));
    SpatialObjV8 *v8_obj = new (v8_storage) SpatialObjV8();

    method3_first_ret = 0;
    method3_ret_override = spatial;
    base_list_head_field30_ret = 0;
    base_list_has_items_ret = 0;
    create_item_ret = v8_obj;

    sub_list_v197_called = 0;
    sub_list_v194_called = 0;

    void *other = (void*)0x88776655;
    func_0013A280(self, other, 0, 0, 1.0f, 2.0f, 3.0f);
    assert(sub_list_v197_called == 1);
    assert(sub_list_v197_action == 88);
    assert(sub_list_v197_other == other);
    assert(sub_list_v194_called == 1);
    assert(sub_list_v194_p == v8_obj);
    printf("SUB_LIST_ACTION_TEST_3_CREATE_ITEM_PASSED\n");
}

static void test_sub_list_action_field_a4_gt_0() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    NodeItem node;
    memset(&node, 0, sizeof(node));
    SubListHelper helper;
    node.m_fieldC8 = &helper;
    node.m_fieldA4 = 5.0f;
    self->m_field4 = &node;

    char baselist_storage[sizeof(BaseList) + 16];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    VBaseList *vbase = new (baselist_storage) VBaseList();
    self->m_fieldCC = (BaseList*)vbase;

    method3_first_ret = 0;
    method3_ret_override = 0;
    base_list_head_field30_ret = 0;
    base_list_has_items_ret = 0;
    create_item_ret = 0;

    sub_list_v197_called = 0;
    sub_list_v42_called = 0;

    void *other = (void*)0x88776655;
    func_0013A280(self, other, 0, -1, 1.0f, 2.0f, 3.0f);
    assert(sub_list_v197_called == 1);
    assert(sub_list_v197_action == 1);
    assert(sub_list_v197_other == other);
    assert(sub_list_v42_called == 1);
    assert(sub_list_v42_other == other);
    printf("SUB_LIST_ACTION_TEST_4_FIELD_A4_GT0_PASSED\n");
}

static void test_sub_list_action_loop_fallback_v24() {
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

    char baselist_storage[sizeof(BaseList) + 16];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    VBaseList *vbase = new (baselist_storage) VBaseList();
    self->m_fieldCC = (BaseList*)vbase;

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->type = 7; // type 7 triggers loop search

    char spatial_storage2[sizeof(SpatialObj1)];
    memset(spatial_storage2, 0, sizeof(spatial_storage2));
    SpatialObj1 *spatial2 = (SpatialObj1*)spatial_storage2;
    spatial2->type = 5;

    // First call returns spatial (type 7), loop call returns spatial2 (type 5)
    method3_called = 0;
    method3_first_ret = spatial;
    method3_ret_override = spatial2;
    base_list_head_field30_ret = 0;
    base_list_has_items_ret = 0;
    create_item_ret = 0;
    sub_list_v24_called = 0;

    void *other = (void*)0x88776655;
    func_0013A280(self, other, 0, -1, 1.0f, 2.0f, 3.0f);
    assert(sub_list_v24_called == 1);
    assert(sub_list_v24_item == &item_match);
    printf("SUB_LIST_ACTION_TEST_5_LOOP_V24_PASSED\n");
}

static void test_sub_list_action_func_0013a6a0() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char target_storage[sizeof(NodeActionTarget)];
    memset(target_storage, 0, sizeof(target_storage));
    NodeActionTarget *target = new (target_storage) NodeActionTarget();
    self->m_field4 = (NodeItem*)target;

    void *dummy_world = (void*)0x11223344;
    self->m_field8 = (WorldContainer*)dummy_world;

    mock_method16_called = 0;
    func_0013A6A0(self);
    assert(mock_method16_called == 1);
    assert(mock_method16_world == dummy_world);
    printf("SUB_LIST_ACTION_TEST_6_A6A0_PASSED\n");
}

static void test_sub_list_action_func_0013a6c0() {
    func_0013A6C0();
    printf("SUB_LIST_ACTION_TEST_7_A6C0_PASSED\n");
}

static void test_sub_list_action_func_0013a6d0() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char target_storage[sizeof(NodeActionTarget)];
    memset(target_storage, 0, sizeof(target_storage));
    NodeActionTarget *target = new (target_storage) NodeActionTarget();
    self->m_field4 = (NodeItem*)target;

    void *dummy_world = (void*)0x55667788;
    self->m_field8 = (WorldContainer*)dummy_world;

    mock_method17_called = 0;
    func_0013A6D0(self);
    assert(mock_method17_called == 1);
    assert(mock_method17_world == dummy_world);
    printf("SUB_LIST_ACTION_TEST_8_A6D0_PASSED\n");
}

static void test_sub_list_action_func_0013a6f0() {
    func_0013A6F0();
    printf("SUB_LIST_ACTION_TEST_9_A6F0_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-9)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_sub_list_action_self_guard();
    else if (mode == 1) test_sub_list_action_head_field30();
    else if (mode == 2) test_sub_list_action_has_items_type9();
    else if (mode == 3) test_sub_list_action_create_item();
    else if (mode == 4) test_sub_list_action_field_a4_gt_0();
    else if (mode == 5) test_sub_list_action_loop_fallback_v24();
    else if (mode == 6) test_sub_list_action_func_0013a6a0();
    else if (mode == 7) test_sub_list_action_func_0013a6c0();
    else if (mode == 8) test_sub_list_action_func_0013a6d0();
    else if (mode == 9) test_sub_list_action_func_0013a6f0();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
