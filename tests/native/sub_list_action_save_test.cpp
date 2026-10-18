#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

char D_10B68F0[32] = {1, 2, 3, 4};

static int func_3668c0_called = 0;
static void *func_3668c0_obj = 0;
static void *func_3668c0_item = 0;

static int func_2668c0_called = 0;
static void *func_2668c0_world = 0;
static void *func_2668c0_item = 0;
static void *func_2668c0_ret1 = 0;
static void *func_2668c0_ret2 = 0;

static int func_00226f70_called = 0;
static int base_list_action_called = 0;
static int base_list_save_called = 0;
static void *base_list_save_stream = 0;

extern "C" {
    void* func_0013BAD0(SubList *self);
    void func_0013BAE0(SubList *self);
    void func_0013BB70(SubList *self, void *stream);

    void* func_3668C0(void *obj, void *item) {
        func_3668c0_called++;
        func_3668c0_obj = obj;
        func_3668c0_item = item;
        return (void*)0x77889900;
    }

    void* func_2668c0(void *world, void *item) {
        func_2668c0_called++;
        func_2668c0_world = world;
        func_2668c0_item = item;
        if (func_2668c0_called == 1) return func_2668c0_ret1;
        return func_2668c0_ret2;
    }

    void func_00226F70(void *stream, void *src, int size) {
        (void)stream; (void)src; (void)size;
        func_00226f70_called++;
    }
}

void BaseList::Action() {
    base_list_action_called++;
}
void BaseList::Save(void *stream) {
    base_list_save_called++;
    base_list_save_stream = stream;
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
void* SubList::v196(void*) { return 0; }
void* SubList::v197(short, void*, float, float, float) { return 0; }
void* SubList::v198() { return 0; }
void* SubList::v199() { return 0; }
void* SubList::v200() { return 0; }
BaseList* SubList::v201() { return 0; }

static void test_sub_list_action_save_bad0() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    void *dummy_world = (void*)0x11223344;
    self->m_field8 = (WorldContainer*)dummy_world;

    func_3668c0_called = 0;
    void *res = func_0013BAD0(self);
    assert(res == (void*)0x77889900);
    assert(func_3668c0_called == 1);
    assert(func_3668c0_obj == (void*)D_10B68F0);
    assert(func_3668c0_item == dummy_world);
    printf("SUB_LIST_ACTION_SAVE_TEST_0_BAD0_PASSED\n");
}

static void test_sub_list_action_save_bae0_with_fields() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_field34 = (ListItem*)baselist_storage;

    char item1[0x30];
    char item2[0x30];
    memset(item1, 0, sizeof(item1));
    memset(item2, 0, sizeof(item2));
    *(short*)(item1 + 0x24) = 45;
    *(short*)(item2 + 0x24) = 67;

    self->m_field10 = (int)(void*)item1;
    self->m_field14 = (int)(void*)item2;
    func_2668c0_ret1 = item1;
    func_2668c0_ret2 = item2;

    func_2668c0_called = 0;
    base_list_action_called = 0;

    func_0013BAE0(self);
    assert(func_2668c0_called == 2);
    assert(self->m_field18 == 45);
    assert(self->m_field1C == 67);
    assert(base_list_action_called == 1);
    printf("SUB_LIST_ACTION_SAVE_TEST_1_BAE0_WITH_FIELDS_PASSED\n");
}

static void test_sub_list_action_save_bae0_zero_fields() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field10 = 0;
    self->m_field14 = 0;
    self->m_field34 = 0;

    func_2668c0_called = 0;
    base_list_action_called = 0;

    func_0013BAE0(self);
    assert(func_2668c0_called == 0);
    assert(base_list_action_called == 0);
    printf("SUB_LIST_ACTION_SAVE_TEST_2_BAE0_ZERO_FIELDS_PASSED\n");
}

static void test_sub_list_action_save_bb70() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    self->m_field34 = (ListItem*)baselist_storage;

    func_00226f70_called = 0;
    base_list_save_called = 0;
    void *stream = (void*)0x99887766;

    func_0013BB70(self, stream);
    assert(func_00226f70_called >= 10);
    assert(base_list_save_called == 1);
    assert(base_list_save_stream == stream);
    printf("SUB_LIST_ACTION_SAVE_TEST_3_BB70_PASSED\n");
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
    if (mode == 0) test_sub_list_action_save_bad0();
    else if (mode == 1) test_sub_list_action_save_bae0_with_fields();
    else if (mode == 2) test_sub_list_action_save_bae0_zero_fields();
    else if (mode == 3) test_sub_list_action_save_bb70();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
