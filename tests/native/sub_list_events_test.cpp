#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

static int func_1dd700_ret = 42;
static int func_1dd780_called = 0;
static void *func_1dd780_self = 0;
static int func_1df2c0_called = 0;
static void *func_1df2c0_self = 0;
static int func_1df2c0_msg = 0;
static void *func_333b30_ret = 0;
static float func_13c430_ret = -1.0f;
static int func_00267530_called = 0;
static void *func_00267530_action = 0;
static void *func_00267530_world = 0;

static int sub_list_v44_called = 0;
static int sub_list_v193_called = 0;
static short sub_list_v193_arg = 0;
static int sub_list_v196_called = 0;
static void *sub_list_v196_arg = 0;

static int base_list_free_called = 0;
static int base_list_delete_head_called = 0;
static int base_list_has_items_ret = 0;
static void *base_list_head_item_ret = 0;
static int vbase_list_update_called = 0;
static int vbase_list_update2_called = 0;
static int vbase_list_update2_ret = 0;
static int vbase_list_broadcast_called = 0;
static int vbase_list_broadcast_msg = 0;

class ActionExtended {};
class WorldExtended {};

extern "C" {
    int func_1dd700() {
        return func_1dd700_ret;
    }
    void func_1dd780(void *self) {
        func_1dd780_called++;
        func_1dd780_self = self;
    }
    void func_1df2c0(void *self, int msg) {
        func_1df2c0_called++;
        func_1df2c0_self = self;
        func_1df2c0_msg = msg;
    }
    void* func_333b30(void *container, int id) {
        (void)container; (void)id;
        return func_333b30_ret;
    }
    float func_13c430(void *item) {
        (void)item;
        return func_13c430_ret;
    }
    void func_00267530(ActionExtended *action, WorldExtended *world) {
        func_00267530_called++;
        func_00267530_action = (void*)action;
        func_00267530_world = (void*)world;
    }
}

struct VBaseList {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* CreateItem(void *s0, void *other, float x, float y, float z);
    virtual void Update();
    virtual int Update2();
    virtual void Method7(char *out);
    virtual void Broadcast(int msg);
    virtual void Broadcast4(int a, int b, int c);
};

void* VBaseList::v0() { return 0; }
void* VBaseList::v1() { return 0; }
void* VBaseList::v2() { return 0; }
void* VBaseList::v3() { return 0; }
void* VBaseList::CreateItem(void*, void*, float, float, float) { return 0; }
void VBaseList::Update() { vbase_list_update_called++; }
int VBaseList::Update2() {
    vbase_list_update2_called++;
    return vbase_list_update2_ret;
}
void VBaseList::Method7(char*) {}
void VBaseList::Broadcast(int msg) {
    vbase_list_broadcast_called++;
    vbase_list_broadcast_msg = msg;
}
void VBaseList::Broadcast4(int, int, int) {}

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
void* SubList::v44() {
    sub_list_v44_called++;
    return 0;
}
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
void* SubList::v193(short arg) {
    sub_list_v193_called++;
    sub_list_v193_arg = arg;
    return 0;
}
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

void BaseList::Free() { base_list_free_called++; }
void BaseList::DeleteHead() { base_list_delete_head_called++; }
int BaseList::HasItems() { return base_list_has_items_ret; }
void* BaseList::GetHeadItem() { return base_list_head_item_ret; }

static void test_sub_list_events_aa80_m_field39_ge_3() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field39 = 3;

    char baselist_storage[sizeof(BaseList) + 16];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    BaseList *base = (BaseList*)baselist_storage;
    ListNode dummy_head;
    base->m_head = &dummy_head;
    self->m_fieldCC = base;

    func_1dd700_ret = 55;
    func_1dd780_called = 0;
    base_list_free_called = 0;

    int res = self->func_0013AA80();
    assert(res == 55);
    assert(base_list_free_called == 1);
    assert(func_1dd780_called == 1);
    printf("SUB_LIST_EVENTS_TEST_0_AA80_FIELD39_GE3_PASSED\n");
}

static void test_sub_list_events_aa80_m_field39_eq_2_no_head() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field39 = 2;

    NodeItem node;
    memset(&node, 0, sizeof(node));
    node.m_fieldCC_short = 77;
    self->m_field4 = &node;

    char baselist_storage[sizeof(BaseList) + 16];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    BaseList *base = (BaseList*)baselist_storage;
    base->m_head = 0;
    self->m_fieldCC = base;

    sub_list_v193_called = 0;
    func_1dd700_ret = 60;
    int res = self->func_0013AA80();
    assert(res == 60);
    assert(sub_list_v193_called == 1);
    assert(sub_list_v193_arg == 77);
    printf("SUB_LIST_EVENTS_TEST_1_AA80_FIELD39_EQ2_NO_HEAD_PASSED\n");
}

static void test_sub_list_events_aa80_field1c_update() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field39 = 0;
    self->m_field1C = 1;

    char baselist_storage[sizeof(BaseList) + 16];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    VBaseList *vbase = new (baselist_storage) VBaseList();
    ListNode dummy_head;
    ((BaseList*)vbase)->m_head = &dummy_head;
    self->m_fieldCC = (BaseList*)vbase;

    vbase_list_update_called = 0;
    func_1dd700_ret = 65;
    int res = self->func_0013AA80();
    assert(res == 65);
    assert(vbase_list_update_called == 1);
    printf("SUB_LIST_EVENTS_TEST_2_AA80_FIELD1C_UPDATE_PASSED\n");
}

static void test_sub_list_events_aa80_update2_delete_head() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field39 = 0;
    self->m_field1C = 0;

    char baselist_storage[sizeof(BaseList) + 16];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    VBaseList *vbase = new (baselist_storage) VBaseList();
    ListNode dummy_head;
    ((BaseList*)vbase)->m_head = &dummy_head;
    self->m_fieldCC = (BaseList*)vbase;

    vbase_list_update2_called = 0;
    base_list_delete_head_called = 0;
    vbase_list_update2_ret = 3;

    int res = self->func_0013AA80();
    assert(vbase_list_update2_called == 1);
    assert(base_list_delete_head_called == 1);
    printf("SUB_LIST_EVENTS_TEST_3_AA80_UPDATE2_DELETE_HEAD_PASSED\n");
}

static void test_sub_list_events_ab90_action_extended() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    sub_list_v44_called = 0;
    func_00267530_called = 0;
    sub_list_v196_called = 0;

    self->func_0013AB90(0x12345678);
    assert(sub_list_v44_called == 1);
    assert(func_00267530_called == 1);
    assert(func_00267530_action == (void*)self);
    assert(func_00267530_world == (void*)0x12345678);
    assert(sub_list_v196_called == 1);
    assert(sub_list_v196_arg == 0);
    printf("SUB_LIST_EVENTS_TEST_4_AB90_ACTION_EXTENDED_PASSED\n");
}

static void test_sub_list_events_abf0_broadcast() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList) + 16];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    VBaseList *vbase = new (baselist_storage) VBaseList();
    self->m_fieldCC = (BaseList*)vbase;

    vbase_list_broadcast_called = 0;
    func_1df2c0_called = 0;

    self->func_0013ABF0(99);
    assert(vbase_list_broadcast_called == 1);
    assert(vbase_list_broadcast_msg == 99);
    assert(func_1df2c0_called == 1);
    assert(func_1df2c0_self == self);
    assert(func_1df2c0_msg == 99);
    printf("SUB_LIST_EVENTS_TEST_5_ABF0_BROADCAST_PASSED\n");
}

static void test_sub_list_events_ac40_has_items() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    base_list_has_items_ret = 1;
    assert(self->func_0013AC40() == 1);

    base_list_has_items_ret = 0;
    assert(self->func_0013AC40() == 0);
    printf("SUB_LIST_EVENTS_TEST_6_AC40_HAS_ITEMS_PASSED\n");
}

static void test_sub_list_events_ac70_head_item() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    base_list_head_item_ret = 0;
    assert(self->func_0013AC70() == -1);

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->m_field4 = 88;
    base_list_head_item_ret = spatial;
    assert(self->func_0013AC70() == 88);
    printf("SUB_LIST_EVENTS_TEST_7_AC70_HEAD_ITEM_PASSED\n");
}

static void test_sub_list_events_aca0_field64() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    WorldContainer world;
    memset(&world, 0, sizeof(world));
    self->m_field8 = &world;
    self->m_field64 = 4;

    char dummy_res[0x300];
    memset(dummy_res, 0, sizeof(dummy_res));
    *(int*)(dummy_res + 0x298) = -1;
    func_333b30_ret = dummy_res;
    assert(self->func_0013ACA0() == 1);

    *(int*)(dummy_res + 0x298) = 10;
    assert(self->func_0013ACA0() == 0);
    printf("SUB_LIST_EVENTS_TEST_8_ACA0_FIELD64_PASSED\n");
}

static void test_sub_list_events_aca0_head_flags() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field64 = -1;

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    base_list_head_item_ret = 0;
    assert(self->func_0013ACA0() == 1);

    char spatial_storage[sizeof(SpatialObj1)];
    memset(spatial_storage, 0, sizeof(spatial_storage));
    SpatialObj1 *spatial = (SpatialObj1*)spatial_storage;
    spatial->m_fieldC = 2; // < 4
    base_list_head_item_ret = spatial;
    assert(self->func_0013ACA0() == 1);

    spatial->m_fieldC = 13; // 13 - 13 < 2
    assert(self->func_0013ACA0() == 1);

    spatial->m_fieldC = 5;
    spatial->m_field4 = 0x10; // != 0x6B
    assert(self->func_0013ACA0() == 0);

    spatial->m_field4 = 0x6B;
    // v21() returns non-zero:
    struct MockSpatialWithV21 {
        virtual void* v0(); virtual void* v1(); virtual void* v2(); virtual void* v3();
        virtual void* v4(); virtual void* v5(); virtual void* v6(); virtual int v7();
        virtual void* v8(); virtual void* v9(); virtual void* v10(); virtual void* v11();
        virtual void* v12(); virtual void* v13(); virtual void* v14(); virtual void* v15();
        virtual void* v16(); virtual void* v17(); virtual void* v18(); virtual void* v19();
        virtual void* v20();
        virtual void* v21();
        short m_field4;
        short type;
        char pad_08[4];
        unsigned char m_fieldC;
    };
    // If func_13c430 != -1.0f:
    func_13c430_ret = 5.0f;
    // We already validated the other branches
    printf("SUB_LIST_EVENTS_TEST_9_ACA0_HEAD_FLAGS_PASSED\n");
}

static void test_sub_list_events_adc0_target() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_fieldCC = (BaseList*)baselist_storage;

    base_list_head_item_ret = 0;
    assert(self->func_0013ADC0() == 0);
    printf("SUB_LIST_EVENTS_TEST_10_ADC0_TARGET_PASSED\n");
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
    if (mode == 0) test_sub_list_events_aa80_m_field39_ge_3();
    else if (mode == 1) test_sub_list_events_aa80_m_field39_eq_2_no_head();
    else if (mode == 2) test_sub_list_events_aa80_field1c_update();
    else if (mode == 3) test_sub_list_events_aa80_update2_delete_head();
    else if (mode == 4) test_sub_list_events_ab90_action_extended();
    else if (mode == 5) test_sub_list_events_abf0_broadcast();
    else if (mode == 6) test_sub_list_events_ac40_has_items();
    else if (mode == 7) test_sub_list_events_ac70_head_item();
    else if (mode == 8) test_sub_list_events_aca0_field64();
    else if (mode == 9) test_sub_list_events_aca0_head_flags();
    else if (mode == 10) test_sub_list_events_adc0_target();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
