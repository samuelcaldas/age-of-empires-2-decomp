#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

void *D_4D7560[100] = {0};
char D_10B68F0[32] = {1, 2, 3, 4};

static int func_3669f0_called = 0;
static void *func_3669f0_obj = 0;
static void *func_3669f0_item = 0;
static int vec_ctor_called = 0;
static void *vec_ctor_self = 0;

static int sub_list_v21_called = 0;
static int sub_list_v21_arg = -1;
static int sub_list_v22_called = 0;
static void *sub_list_v22_item = (void*)0xFFFFFFFF;

static int mock_item_method11_called = 0;

extern "C" {
    void func_3669F0(void *obj, void *item) {
        func_3669f0_called++;
        func_3669f0_obj = obj;
        func_3669f0_item = item;
    }
    void __vec_ctor(void *self) {
        vec_ctor_called++;
        vec_ctor_self = self;
    }
    void* func_0013B770(SubList *self, int flag);
}

void ListItem::v0() {}
void ListItem::v1() {}
void ListItem::v2() {}
void ListItem::v3() {}
int ListItem::Action() { return 0; }
void ListItem::Save(void*) {}
int ListItem::v8() { return 0; }
void ListItem::Method9(void*, void*, void*) {}
bool ListItem::Method10() { return false; }
void ListItem::Method11() {
    mock_item_method11_called++;
}
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
void* SubList::v21(int a1) {
    sub_list_v21_called++;
    sub_list_v21_arg = a1;
    return 0;
}
void* SubList::v22(void *item) {
    sub_list_v22_called++;
    sub_list_v22_item = item;
    return 0;
}
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
void* SubList::v197() { return 0; }
void* SubList::v198() { return 0; }
void* SubList::v199(short, void*, float, float, float) { return 0; }
void* SubList::v200() { return 0; }
BaseList* SubList::v201() { return 0; }

static void* d4d7560_v21_thunk(SubList *self, int a) {
    (void)self;
    sub_list_v21_called++;
    sub_list_v21_arg = a;
    return 0;
}

static void* d4d7560_v22_thunk(SubList *self, void *item) {
    (void)self;
    sub_list_v22_called++;
    sub_list_v22_item = item;
    return 0;
}

static void init_d4d7560() {
    typedef void* (*V21Fn)(SubList*, int);
    typedef void* (*V22Fn)(SubList*, void*);
    D_4D7560[21] = (void*)(V21Fn)d4d7560_v21_thunk;
    D_4D7560[22] = (void*)(V22Fn)d4d7560_v22_thunk;
    D_4D7560[0x5C / 4] = (void*)(V21Fn)d4d7560_v21_thunk;
    D_4D7560[0x60 / 4] = (void*)(V22Fn)d4d7560_v22_thunk;
}

static void test_sub_list_teardown_null_self() {
    void *res = func_0013B770(0, 1);
    assert(res == 0);
    printf("SUB_LIST_TEARDOWN_TEST_0_NULL_SELF_PASSED\n");
}

static void test_sub_list_teardown_flag_1() {
    init_d4d7560();
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char item_storage[sizeof(ListItem)];
    memset(item_storage, 0, sizeof(item_storage));
    ListItem *item = new (item_storage) ListItem();
    self->m_field34 = item;

    sub_list_v21_called = 0;
    sub_list_v22_called = 0;
    func_3669f0_called = 0;
    mock_item_method11_called = 0;
    vec_ctor_called = 0;

    void *res = func_0013B770(self, 1);
    assert(res == self);
    assert(*(void**)self == (void*)D_4D7560);
    assert(sub_list_v21_called == 1);
    assert(sub_list_v21_arg == 0);
    assert(sub_list_v22_called == 1);
    assert(sub_list_v22_item == 0);
    assert(func_3669f0_called == 1);
    assert(func_3669f0_obj == (void*)D_10B68F0);
    assert(func_3669f0_item == item);
    assert(mock_item_method11_called == 1);
    assert(self->m_field34 == 0);
    assert(vec_ctor_called == 1);
    assert(vec_ctor_self == self);
    printf("SUB_LIST_TEARDOWN_TEST_1_FLAG1_PASSED\n");
}

static void test_sub_list_teardown_flag_0() {
    init_d4d7560();
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    sub_list_v21_called = 0;
    sub_list_v22_called = 0;
    vec_ctor_called = 0;

    void *res = func_0013B770(self, 0);
    assert(res == self);
    assert(*(void**)self == (void*)D_4D7560);
    assert(sub_list_v21_called == 1);
    assert(sub_list_v22_called == 1);
    assert(vec_ctor_called == 0);
    printf("SUB_LIST_TEARDOWN_TEST_2_FLAG0_PASSED\n");
}

static void test_sub_list_teardown_b820_with_field34() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char item_storage[sizeof(ListItem)];
    memset(item_storage, 0, sizeof(item_storage));
    ListItem *item = new (item_storage) ListItem();
    self->m_field34 = item;

    sub_list_v21_called = 0;
    sub_list_v22_called = 0;
    func_3669f0_called = 0;
    mock_item_method11_called = 0;

    self->func_0013B820();
    assert(sub_list_v21_called == 1);
    assert(sub_list_v21_arg == 0);
    assert(sub_list_v22_called == 1);
    assert(sub_list_v22_item == 0);
    assert(func_3669f0_called == 1);
    assert(func_3669f0_obj == (void*)D_10B68F0);
    assert(func_3669f0_item == item);
    assert(mock_item_method11_called == 1);
    assert(self->m_field34 == 0);
    printf("SUB_LIST_TEARDOWN_TEST_3_B820_WITH_FIELD34_PASSED\n");
}

static void test_sub_list_teardown_b820_null_field34() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field34 = 0;

    sub_list_v21_called = 0;
    sub_list_v22_called = 0;
    func_3669f0_called = 0;
    mock_item_method11_called = 0;

    self->func_0013B820();
    assert(sub_list_v21_called == 1);
    assert(sub_list_v22_called == 1);
    assert(func_3669f0_called == 0);
    assert(mock_item_method11_called == 0);
    printf("SUB_LIST_TEARDOWN_TEST_4_B820_NULL_FIELD34_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-4)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_sub_list_teardown_null_self();
    else if (mode == 1) test_sub_list_teardown_flag_1();
    else if (mode == 2) test_sub_list_teardown_flag_0();
    else if (mode == 3) test_sub_list_teardown_b820_with_field34();
    else if (mode == 4) test_sub_list_teardown_b820_null_field34();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
