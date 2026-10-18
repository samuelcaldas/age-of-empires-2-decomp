#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

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

static void test_sub_list_constants_zeroes() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    assert(self->func_0013B470() == 0);
    assert(self->func_0013B490() == 0.0f);
    assert(self->func_0013B4A0() == 0.0f);
    assert(self->func_0013B4B0() == 0.0f);
    assert(self->func_0013B4C0() == 0.0f);
    assert(self->func_0013B510() == 0);
    assert(self->func_0013B6B0() == 0.0f);
    printf("SUB_LIST_CONSTANTS_TEST_0_ZEROES_PASSED\n");
}

static void test_sub_list_constants_ones() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    assert(self->func_0013B480() == 1.0f);
    assert(self->func_0013B520() == 1);
    assert(self->func_0013B530() == 1);
    printf("SUB_LIST_CONSTANTS_TEST_1_ONES_PASSED\n");
}

static void test_sub_list_constants_minus_ones() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    assert(self->func_0013B4D0() == -1);
    assert(self->func_0013B4E0() == -1.0f);
    assert(self->func_0013B4F0() == -1.0f);
    assert(self->func_0013B500() == -1.0f);
    assert(self->func_0013B700() == -1);
    printf("SUB_LIST_CONSTANTS_TEST_2_MINUS_ONES_PASSED\n");
}

static void test_sub_list_constants_noops() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    self->func_0013B540();
    self->func_0013B6E0();
    printf("SUB_LIST_CONSTANTS_TEST_3_NOOPS_PASSED\n");
}

static void test_sub_list_constants_sequence_b550_b600() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    assert(self->func_0013B550() == 0);
    assert(self->func_0013B560() == 0);
    assert(self->func_0013B570() == 0);
    assert(self->func_0013B580() == 0);
    assert(self->func_0013B590() == 0);
    assert(self->func_0013B5A0() == 0);
    assert(self->func_0013B5B0() == 0);
    assert(self->func_0013B5C0() == 0);
    assert(self->func_0013B5D0() == 0);
    assert(self->func_0013B5E0() == 0);
    assert(self->func_0013B5F0() == 0);
    assert(self->func_0013B600() == 0);
    printf("SUB_LIST_CONSTANTS_TEST_4_SEQUENCE_B550_B600_PASSED\n");
}

static void test_sub_list_constants_sequence_b610_b6f0() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    assert(self->func_0013B610() == 0);
    assert(self->func_0013B620() == 0);
    assert(self->func_0013B630() == 0);
    assert(self->func_0013B640() == 0);
    assert(self->func_0013B650() == 0);
    assert(self->func_0013B660() == 0);
    assert(self->func_0013B670() == 0);
    assert(self->func_0013B680() == 0);
    assert(self->func_0013B690() == 0);
    assert(self->func_0013B6A0() == 0);
    assert(self->func_0013B6C0() == 0);
    assert(self->func_0013B6D0() == 0);
    assert(self->func_0013B6F0() == 0);
    printf("SUB_LIST_CONSTANTS_TEST_5_SEQUENCE_B610_B6F0_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-5)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_sub_list_constants_zeroes();
    else if (mode == 1) test_sub_list_constants_ones();
    else if (mode == 2) test_sub_list_constants_minus_ones();
    else if (mode == 3) test_sub_list_constants_noops();
    else if (mode == 4) test_sub_list_constants_sequence_b550_b600();
    else if (mode == 5) test_sub_list_constants_sequence_b610_b6f0();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
