#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

static int func_147180_called = 0;
static void *func_147180_obj = 0;
static short func_147180_s0 = 0;

static int func_1471b0_called = 0;
static void *func_1471b0_obj = 0;
static short func_1471b0_s1 = 0;

static int func_14bd90_called = 0;
static void *func_14bd90_obj = 0;
static short func_14bd90_id1 = 0;
static short func_14bd90_id2 = 0;

static int func_151490_called = 0;
static void *func_151490_obj = 0;
static short func_151490_s0 = 0;
static short func_151490_s1 = 0;
static short func_151490_target_id = 0;
static Vec3 func_151490_v1;
static Vec3 func_151490_v2;

static int func_14bef0_called = 0;
static void *func_14bef0_obj = 0;

extern "C" {
    void func_147180(void *obj, short s0) {
        func_147180_called++;
        func_147180_obj = obj;
        func_147180_s0 = s0;
    }
    void func_1471b0(void *obj, short s1) {
        func_1471b0_called++;
        func_1471b0_obj = obj;
        func_1471b0_s1 = s1;
    }
    void func_14bd90(void *obj, short id1, short id2, float x, float y, float z) {
        (void)x; (void)y; (void)z;
        func_14bd90_called++;
        func_14bd90_obj = obj;
        func_14bd90_id1 = id1;
        func_14bd90_id2 = id2;
    }
    void func_151490(void *obj, short s0, short s1, Vec3 *v1, short target_id, Vec3 *v2) {
        func_151490_called++;
        func_151490_obj = obj;
        func_151490_s0 = s0;
        func_151490_s1 = s1;
        func_151490_target_id = target_id;
        if (v1) func_151490_v1 = *v1;
        if (v2) func_151490_v2 = *v2;
    }
    void func_14bef0(void *obj) {
        func_14bef0_called++;
        func_14bef0_obj = obj;
    }
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
Vec3 SubList::v136() {
    Vec3 v;
    v.x = 10.0f;
    v.y = 20.0f;
    v.z = 30.0f;
    return v;
}
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
void* SubList::v197(short, void*, float, float, float) { return 0; }
void* SubList::v198() { return 0; }
void* SubList::v199() { return 0; }
void* SubList::v200() { return 0; }
BaseList* SubList::v201() { return 0; }

static void test_sub_list_dispatch_null_field_c8() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_fieldC8 = 0;

    func_147180_called = 0;
    self->func_0013B0B0(0x6A, 0, 1.0f, 2.0f, 3.0f);
    assert(func_147180_called == 0);
    printf("SUB_LIST_DISPATCH_TEST_0_NULL_FIELD_C8_PASSED\n");
}

static void test_sub_list_dispatch_with_other() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    void *dummy_target = (void*)0x11223344;
    self->m_fieldC8 = &dummy_target;

    char other_storage[sizeof(SubList) + sizeof(OtherObj)];
    memset(other_storage, 0, sizeof(other_storage));
    SubList *other_sub = new (other_storage) SubList();
    OtherObj *other = (OtherObj*)other_storage;

    NodeItem other_node;
    memset(&other_node, 0, sizeof(other_node));
    other_node.m_fieldE = 33;
    other->m_field4 = &other_node;
    other->m_field24_short = 55;

    func_147180_called = 0;
    func_1471b0_called = 0;
    func_14bd90_called = 0;
    func_151490_called = 0;
    func_14bef0_called = 0;

    self->func_0013B0B0(0x6A, other_sub, 1.0f, 2.0f, 3.0f);
    assert(func_147180_called == 1);
    assert(func_147180_obj == dummy_target);
    assert(func_147180_s0 == 0x2CE);
    assert(func_1471b0_called == 1);
    assert(func_1471b0_s1 == 0x26A);
    assert(func_14bd90_called == 1);
    assert(func_14bd90_id1 == 55);
    assert(func_14bd90_id2 == 33);
    assert(func_151490_called == 1);
    assert(func_151490_s0 == 0x2CE);
    assert(func_151490_s1 == 0x26A);
    assert(func_151490_target_id == 55);
    assert(func_14bef0_called == 1);
    assert(func_14bef0_obj == dummy_target);
    printf("SUB_LIST_DISPATCH_TEST_1_WITH_OTHER_PASSED\n");
}

static void test_sub_list_dispatch_without_other() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    void *dummy_target = (void*)0x55667788;
    self->m_fieldC8 = &dummy_target;

    func_147180_called = 0;
    func_1471b0_called = 0;
    func_14bd90_called = 0;
    func_151490_called = 0;
    func_14bef0_called = 0;

    self->func_0013B0B0(0x01, 0, 1.0f, 2.0f, 3.0f);
    assert(func_147180_called == 1);
    assert(func_147180_s0 == 0x2C6);
    assert(func_1471b0_called == 1);
    assert(func_1471b0_s1 == 0x262);
    assert(func_14bd90_called == 1);
    assert(func_14bd90_id1 == -1);
    assert(func_14bd90_id2 == -1);
    assert(func_151490_called == 1);
    assert(func_151490_target_id == -1);
    assert(func_151490_v2.x == 1.0f);
    assert(func_151490_v2.y == 3.0f);
    assert(func_151490_v2.z == 2.0f);
    assert(func_14bef0_called == 1);
    printf("SUB_LIST_DISPATCH_TEST_2_WITHOUT_OTHER_PASSED\n");
}

static void test_sub_list_dispatch_default_action() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    void *dummy_target = (void*)0x99887766;
    self->m_fieldC8 = &dummy_target;

    func_147180_called = 0;
    func_1471b0_called = 0;

    self->func_0013B0B0(0x99, 0, 1.0f, 2.0f, 3.0f);
    assert(func_147180_called == 1);
    assert(func_147180_s0 == -1);
    assert(func_1471b0_called == 1);
    assert(func_1471b0_s1 == -1);
    printf("SUB_LIST_DISPATCH_TEST_3_DEFAULT_ACTION_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-3)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_sub_list_dispatch_null_field_c8();
    else if (mode == 1) test_sub_list_dispatch_with_other();
    else if (mode == 2) test_sub_list_dispatch_without_other();
    else if (mode == 3) test_sub_list_dispatch_default_action();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
