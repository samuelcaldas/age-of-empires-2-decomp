#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

static int sub_list_v21_called = 0;
static int sub_list_v21_arg = -1;
static int sub_list_v22_called = 0;
static void *sub_list_v22_item = (void*)0xFFFFFFFF;

extern "C" {
    int func_0013BD90(SubList *self);
    int func_0013BE10(SubList *self);
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

static void test_sub_list_validate_bd90_ge_7() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char target1[0x40];
    char target2[0x40];
    memset(target1, 0, sizeof(target1));
    memset(target2, 0, sizeof(target2));
    target1[0x39] = 7;
    target2[0x39] = 8;
    self->m_field10 = (int)(void*)target1;
    self->m_field14 = (int)(void*)target2;

    sub_list_v21_called = 0;
    sub_list_v22_called = 0;

    int res = func_0013BD90(self);
    assert(res == 1);
    assert(sub_list_v21_called == 1);
    assert(sub_list_v21_arg == 0);
    assert(sub_list_v22_called == 1);
    assert(sub_list_v22_item == 0);
    printf("SUB_LIST_VALIDATE_TEST_0_BD90_GE7_PASSED\n");
}

static void test_sub_list_validate_bd90_lt_7() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char target1[0x40];
    char target2[0x40];
    memset(target1, 0, sizeof(target1));
    memset(target2, 0, sizeof(target2));
    target1[0x39] = 6;
    target2[0x39] = 5;
    self->m_field10 = (int)(void*)target1;
    self->m_field14 = (int)(void*)target2;

    sub_list_v21_called = 0;
    sub_list_v22_called = 0;

    int res = func_0013BD90(self);
    assert(res == 1);
    assert(sub_list_v21_called == 0);
    assert(sub_list_v22_called == 0);
    printf("SUB_LIST_VALIDATE_TEST_1_BD90_LT7_PASSED\n");
}

static void test_sub_list_validate_be10_ge_7() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char target1[0x40];
    char target2[0x40];
    memset(target1, 0, sizeof(target1));
    memset(target2, 0, sizeof(target2));
    target1[0x39] = 10;
    target2[0x39] = 20;
    self->m_field10 = (int)(void*)target1;
    self->m_field14 = (int)(void*)target2;

    sub_list_v21_called = 0;
    sub_list_v22_called = 0;

    int res = func_0013BE10(self);
    assert(res == 1);
    assert(sub_list_v21_called == 1);
    assert(sub_list_v21_arg == 0);
    assert(sub_list_v22_called == 1);
    assert(sub_list_v22_item == 0);
    printf("SUB_LIST_VALIDATE_TEST_2_BE10_GE7_PASSED\n");
}

static void test_sub_list_validate_be10_null() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field10 = 0;
    self->m_field14 = 0;

    sub_list_v21_called = 0;
    sub_list_v22_called = 0;

    int res = func_0013BE10(self);
    assert(res == 1);
    assert(sub_list_v21_called == 0);
    assert(sub_list_v22_called == 0);
    printf("SUB_LIST_VALIDATE_TEST_3_BE10_NULL_PASSED\n");
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
    if (mode == 0) test_sub_list_validate_bd90_ge_7();
    else if (mode == 1) test_sub_list_validate_bd90_lt_7();
    else if (mode == 2) test_sub_list_validate_be10_ge_7();
    else if (mode == 3) test_sub_list_validate_be10_null();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
