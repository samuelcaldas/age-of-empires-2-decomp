#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

char D_10B68F0[32] = {1, 2, 3, 4};

static int func_1dc180_called = 0;
static void *func_1dc180_self = 0;
static int func_1dc2e0_called = 0;
static void *func_1dc2e0_self = 0;
static void *func_1dc2e0_stream = 0;
static int func_1dc6b0_called = 0;
static void *func_1dc6b0_self = 0;
static void *func_1dc6b0_stream = 0;
static int func_1dcaa0_called = 0;
static void *func_1dcaa0_self = 0;
static int func_266840_called = 0;
static void *func_266840_self = 0;
static int func_267dd0_called = 0;
static void *func_267dd0_self = 0;
static int func_3668c0_called = 0;
static void *func_3668c0_obj = 0;
static void *func_3668c0_item = 0;
static int func_00226d90_called = 0;
static int func_00226f70_called = 0;
static char f70_last_written_bytes[8] = {0};

static int base_list_load_called = 0;
static void *base_list_load_stream = 0;
static int base_list_action_called = 0;
static int base_list_save_called = 0;
static void *base_list_save_stream = 0;
static int base_list_free_called = 0;

static int sub_list_v190_called = 0;
static void *sub_list_v190_other = 0;
static int sub_list_v190_a = 0;
static int sub_list_v190_b = 0;
static int sub_list_v201_called = 0;
static BaseList *sub_list_v201_ret = 0;

extern "C" {
    void func_1DC180(void *self) {
        func_1dc180_called++;
        func_1dc180_self = self;
    }
    void func_1DC2E0(void *self, void *stream) {
        func_1dc2e0_called++;
        func_1dc2e0_self = self;
        func_1dc2e0_stream = stream;
    }
    void func_1DC6B0(void *self, void *stream) {
        func_1dc6b0_called++;
        func_1dc6b0_self = self;
        func_1dc6b0_stream = stream;
    }
    void func_1DCAA0(void *self) {
        func_1dcaa0_called++;
        func_1dcaa0_self = self;
    }
    void func_266840(void *self) {
        func_266840_called++;
        func_266840_self = self;
    }
    void func_267DD0(void *self) {
        func_267dd0_called++;
        func_267dd0_self = self;
    }
    void* func_3668C0(void *obj, void *item) {
        func_3668c0_called++;
        func_3668c0_obj = obj;
        func_3668c0_item = item;
        return (void*)0x55AA55AA;
    }
    void func_00226D90(void *stream, void *dst, int size) {
        (void)stream;
        if (dst && size > 0) {
            *(char*)dst = (char)(0x30 + func_00226d90_called);
        }
        func_00226d90_called++;
    }
    void func_00226F70(void *stream, void *src, int size) {
        (void)stream;
        if (src && size > 0 && func_00226f70_called < 8) {
            f70_last_written_bytes[func_00226f70_called] = *(char*)src;
        }
        func_00226f70_called++;
    }
}

void BaseList::Load(void *stream) {
    base_list_load_called++;
    base_list_load_stream = stream;
}
void BaseList::Action() {
    base_list_action_called++;
}
void BaseList::Save(void *stream) {
    base_list_save_called++;
    base_list_save_stream = stream;
}
void BaseList::Free() {
    base_list_free_called++;
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

void* SubList::v190(void *other, int a, int b) {
    sub_list_v190_called++;
    sub_list_v190_other = other;
    sub_list_v190_a = a;
    sub_list_v190_b = b;
    return 0;
}
void* SubList::v193(short) { return 0; }
void* SubList::v194(void*) { return 0; }
void* SubList::v195() { return 0; }
void* SubList::v196(void*) { return 0; }
void* SubList::v197() { return 0; }
void* SubList::v198() { return 0; }
void* SubList::v199(short, void*, float, float, float) { return 0; }
void* SubList::v200() { return 0; }

BaseList* SubList::v201() {
    sub_list_v201_called++;
    return sub_list_v201_ret;
}

static void test_base_list_stream_ops_setup_spatial() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *list = new (sublist_storage) SubList();
    list->m_fieldC5 = 77;

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    BaseList *mock_base = (BaseList*)baselist_storage;
    sub_list_v201_ret = mock_base;

    func_1dc180_called = 0;
    sub_list_v201_called = 0;

    int ret = list->SetupSpatial();
    assert(ret == 1);
    assert(func_1dc180_called == 1);
    assert(func_1dc180_self == list);
    assert(sub_list_v201_called == 1);
    assert(list->m_fieldCC == mock_base);
    assert(list->m_fieldC5 == 0);
    printf("BASE_LIST_STREAM_OPS_TEST_0_SETUP_SPATIAL_PASSED\n");
}

static void test_base_list_stream_ops_setup() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *list = new (sublist_storage) SubList();
    list->m_fieldC5 = 0;

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    BaseList *mock_base = (BaseList*)baselist_storage;
    sub_list_v201_ret = mock_base;

    func_1dc2e0_called = 0;
    func_00226d90_called = 0;
    base_list_load_called = 0;
    sub_list_v201_called = 0;

    void *stream = (void*)0x12345678;
    int ret = list->Setup(stream);
    assert(ret == 1);
    assert(func_1dc2e0_called == 1);
    assert(func_1dc2e0_self == list);
    assert(func_1dc2e0_stream == stream);
    assert(func_00226d90_called == 2);
    assert(list->m_fieldC5 == 0x31);
    assert(sub_list_v201_called == 1);
    assert(list->m_fieldCC == mock_base);
    assert(base_list_load_called == 1);
    assert(base_list_load_stream == stream);
    printf("BASE_LIST_STREAM_OPS_TEST_1_SETUP_PASSED\n");
}

static void test_base_list_stream_ops_create_sublist() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *list = new (sublist_storage) SubList();

    func_3668c0_called = 0;
    void *res = list->CreateSubList();
    assert(res == (void*)0x55AA55AA);
    assert(func_3668c0_called == 1);
    assert(func_3668c0_obj == (void*)D_10B68F0);
    assert(func_3668c0_item == list);
    printf("BASE_LIST_STREAM_OPS_TEST_2_CREATE_SUBLIST_PASSED\n");
}

static void test_base_list_stream_ops_action() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *list = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    BaseList *mock_base = (BaseList*)baselist_storage;
    list->m_fieldCC = mock_base;

    func_266840_called = 0;
    base_list_action_called = 0;

    list->Action();
    assert(func_266840_called == 1);
    assert(func_266840_self == list);
    assert(base_list_action_called == 1);
    printf("BASE_LIST_STREAM_OPS_TEST_3_ACTION_PASSED\n");
}

static void test_base_list_stream_ops_save() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *list = new (sublist_storage) SubList();
    list->m_fieldC5 = 0x4A;

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    BaseList *mock_base = (BaseList*)baselist_storage;
    list->m_fieldCC = mock_base;

    func_1dc6b0_called = 0;
    func_00226f70_called = 0;
    base_list_save_called = 0;
    memset(f70_last_written_bytes, 0, sizeof(f70_last_written_bytes));

    void *stream = (void*)0x87654321;
    list->Save(stream);
    assert(func_1dc6b0_called == 1);
    assert(func_1dc6b0_self == list);
    assert(func_1dc6b0_stream == stream);
    assert(func_00226f70_called == 2);
    assert(f70_last_written_bytes[0] == 0);
    assert(f70_last_written_bytes[1] == 0x4A);
    assert(base_list_save_called == 1);
    assert(base_list_save_stream == stream);
    printf("BASE_LIST_STREAM_OPS_TEST_4_SAVE_PASSED\n");
}

static void test_base_list_stream_ops_free() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *list = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    BaseList *mock_base = (BaseList*)baselist_storage;
    list->m_fieldCC = mock_base;

    func_1dcaa0_called = 0;
    base_list_free_called = 0;

    list->Free();
    assert(func_1dcaa0_called == 1);
    assert(func_1dcaa0_self == list);
    assert(base_list_free_called == 1);
    printf("BASE_LIST_STREAM_OPS_TEST_5_FREE_PASSED\n");
}

static void test_base_list_stream_ops_teardown() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *list = new (sublist_storage) SubList();

    char baselist_storage[sizeof(BaseList)];
    memset(baselist_storage, 0, sizeof(baselist_storage));
    BaseList *mock_base = (BaseList*)baselist_storage;
    list->m_fieldCC = mock_base;

    func_267dd0_called = 0;
    base_list_free_called = 0;

    list->Teardown();
    assert(base_list_free_called == 1);
    assert(func_267dd0_called == 1);
    assert(func_267dd0_self == list);
    printf("BASE_LIST_STREAM_OPS_TEST_6_TEARDOWN_PASSED\n");
}

static void test_base_list_stream_ops_noop() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *list = new (sublist_storage) SubList();
    list->m_fieldC5 = 99;

    list->Noop();
    assert(list->m_fieldC5 == 99);
    printf("BASE_LIST_STREAM_OPS_TEST_7_NOOP_PASSED\n");
}

static void test_base_list_stream_ops_notify() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *list = new (sublist_storage) SubList();
    list->m_fieldC5 = 10;

    sub_list_v190_called = 0;
    list->Notify(list);
    assert(sub_list_v190_called == 0);
    assert(list->m_fieldC5 == 10);

    void *other = (void*)0x99887766;
    list->Notify(other);
    assert(sub_list_v190_called == 1);
    assert(sub_list_v190_other == other);
    assert(sub_list_v190_a == 0);
    assert(sub_list_v190_b == -1);
    assert(list->m_fieldC5 == 11);
    printf("BASE_LIST_STREAM_OPS_TEST_8_NOTIFY_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-8)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_base_list_stream_ops_setup_spatial();
    else if (mode == 1) test_base_list_stream_ops_setup();
    else if (mode == 2) test_base_list_stream_ops_create_sublist();
    else if (mode == 3) test_base_list_stream_ops_action();
    else if (mode == 4) test_base_list_stream_ops_save();
    else if (mode == 5) test_base_list_stream_ops_free();
    else if (mode == 6) test_base_list_stream_ops_teardown();
    else if (mode == 7) test_base_list_stream_ops_noop();
    else if (mode == 8) test_base_list_stream_ops_notify();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
