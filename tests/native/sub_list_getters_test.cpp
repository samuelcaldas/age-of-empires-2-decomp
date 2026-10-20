#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

static int func_123350_called = 0;
static float func_123350_last_val = 0.0f;
static int func_1378c0_called = 0;
static void *func_1378c0_obj = 0;
static int func_1378c0_a1 = 0;
static int func_1378c0_a2 = 0;

extern "C" {
    int func_123350(float val) {
        func_123350_called++;
        func_123350_last_val = val;
        return (int)val;
    }
    void func_1378c0(void *obj, int a1, int a2) {
        func_1378c0_called++;
        func_1378c0_obj = obj;
        func_1378c0_a1 = a1;
        func_1378c0_a2 = a2;
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

static void test_sub_list_getters_b360() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field90.x = 1.0f;
    self->m_field90.y = 2.0f;
    self->m_field90.z = 3.0f;

    Vec3 res = self->func_0013B360();
    assert(res.x == 1.0f);
    assert(res.y == 2.0f);
    assert(res.z == 3.0f);
    printf("SUB_LIST_GETTERS_TEST_0_B360_PASSED\n");
}

static void test_sub_list_getters_b380() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field7C = 17.5f;

    assert(self->func_0013B380() == 17.5f);
    printf("SUB_LIST_GETTERS_TEST_1_B380_PASSED\n");
}

static void test_sub_list_getters_b390() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field8C_short = 42;

    assert(self->func_0013B390() == 42);
    printf("SUB_LIST_GETTERS_TEST_2_B390_PASSED\n");
}

static void test_sub_list_getters_b3a0() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_fieldB4 = 1024;

    assert(self->func_0013B3A0() == 1024);
    printf("SUB_LIST_GETTERS_TEST_3_B3A0_PASSED\n");
}

static void test_sub_list_getters_b3b0() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_fieldC0 = 2048;

    assert(self->func_0013B3B0() == 2048);
    printf("SUB_LIST_GETTERS_TEST_4_B3B0_PASSED\n");
}

static void test_sub_list_getters_b3c0() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field9C.x = 4.0f;
    self->m_field9C.y = 5.0f;
    self->m_field9C.z = 6.0f;

    Vec3 res = self->func_0013B3C0();
    assert(res.x == 4.0f);
    assert(res.y == 5.0f);
    assert(res.z == 6.0f);
    printf("SUB_LIST_GETTERS_TEST_5_B3C0_PASSED\n");
}

static void test_sub_list_getters_b3e0() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field68 = 12.25f;

    assert(self->func_0013B3E0() == 12.25f);
    printf("SUB_LIST_GETTERS_TEST_6_B3E0_PASSED\n");
}

static void test_sub_list_getters_b3f0() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    assert(self->func_0013B3F0() == 0);
    printf("SUB_LIST_GETTERS_TEST_7_B3F0_PASSED\n");
}

static void test_sub_list_getters_b400() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    assert(self->func_0013B400() == 0);
    printf("SUB_LIST_GETTERS_TEST_8_B400_PASSED\n");
}

static void test_sub_list_getters_b410() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    assert(self->func_0013B410() == 0);
    printf("SUB_LIST_GETTERS_TEST_9_B410_PASSED\n");
}

static void test_sub_list_getters_b420() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field44 = 10.0f;
    self->m_field48 = 20.0f;

    WorldContainer world;
    memset(&world, 0, sizeof(world));
    void *dummy_b94 = (void*)0x998877;
    world.m_fieldB94 = dummy_b94;

    func_123350_called = 0;
    func_1378c0_called = 0;

    self->func_0013B420(&world);
    assert(func_123350_called == 2);
    assert(func_1378c0_called == 1);
    assert(func_1378c0_obj == dummy_b94);
    assert(func_1378c0_a1 == 20);
    assert(func_1378c0_a2 == 20);
    printf("SUB_LIST_GETTERS_TEST_10_B420_PASSED\n");
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
    if (mode == 0) test_sub_list_getters_b360();
    else if (mode == 1) test_sub_list_getters_b380();
    else if (mode == 2) test_sub_list_getters_b390();
    else if (mode == 3) test_sub_list_getters_b3a0();
    else if (mode == 4) test_sub_list_getters_b3b0();
    else if (mode == 5) test_sub_list_getters_b3c0();
    else if (mode == 6) test_sub_list_getters_b3e0();
    else if (mode == 7) test_sub_list_getters_b3f0();
    else if (mode == 8) test_sub_list_getters_b400();
    else if (mode == 9) test_sub_list_getters_b410();
    else if (mode == 10) test_sub_list_getters_b420();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
