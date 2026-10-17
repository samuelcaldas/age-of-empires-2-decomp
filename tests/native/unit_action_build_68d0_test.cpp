// Tests for func_2768D0 — Milestone 95 (456B)
// Verifies ActionBuild target positioning and task item 0x65 sub-object allocation.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_68d0.h"

static void *g_mock_res = (void *)0x1000;
static int g_has_items = 1;
static void *g_head_item = nullptr;
static int g_free_called = 0;
static void *g_mock_sub_obj = (void *)0x2000;
static void *g_mock_pool_item = (void *)0x3000;
static int g_func_352230_called = 0;
static int g_set_sub_called = 0;
static int g_update_pos_called = 0;

void *D_4E35DC = (void *)0x5555;

extern "C" void *func_332E60(void *, void *, int) {
    return g_mock_res;
}

extern "C" int HasItems__8BaseListFv(void *) {
    return g_has_items;
}

extern "C" void *GetHeadItem__8BaseListFv(void *) {
    return g_head_item;
}

extern "C" void Free__8BaseListFv(void *) {
    g_free_called++;
}

extern "C" void *func_366C60(void *) {
    return g_mock_pool_item;
}

extern "C" void func_352230(void *, void *, void *, void *) {
    g_func_352230_called++;
}

static void *mock_item_type(void *) { return g_mock_res; }
static short mock_item_id(void *) { return 0x65; }
static void mock_update_pos(void *, void *, float, float, float) { g_update_pos_called++; }
static void *mock_create_sub(void *, void *, int, float, float, float) { return g_mock_sub_obj; }
static void mock_set_sub(void *, void *) { g_set_sub_called++; }

static void reset_mocks() {
    g_mock_res = (void *)0x1000;
    g_has_items = 1;
    g_head_item = nullptr;
    g_free_called = 0;
    g_mock_sub_obj = (void *)0x2000;
    g_mock_pool_item = (void *)0x3000;
    g_func_352230_called = 0;
    g_set_sub_called = 0;
    g_update_pos_called = 0;
}

static void test_res_null() {
    reset_mocks();
    g_mock_res = nullptr;
    unsigned char self[1024], owner[8192];
    std::memset(self, 0, sizeof(self));
    std::memset(owner, 0, sizeof(owner));

    void *owner_ptr = owner;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
#endif

    int ret = func_2768D0(self, nullptr, 0);
    assert(ret == 0);
    printf("PASS test_res_null\n");
}

static void test_arg2_zero_existing_match() {
    reset_mocks();
    unsigned char self[1024], owner[8192], res[128], item[64], list[64];
    void *item_vtbl[64];
    std::memset(self, 0, sizeof(self));
    std::memset(owner, 0, sizeof(owner));
    std::memset(res, 0, sizeof(res));
    std::memset(item, 0, sizeof(item));
    std::memset(list, 0, sizeof(list));

    g_mock_res = res;
    g_head_item = item;
    item_vtbl[21] = (void *)mock_item_type;
    item_vtbl[8] = (void *)mock_item_id;
    void *item_vtbl_ptr = item_vtbl;
    std::memcpy(item, &item_vtbl_ptr, sizeof(void *));

    void *owner_ptr = owner;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    void *list_ptr = list;
    std::memcpy(self + 0x198, &list_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    void *list_ptr = list;
    std::memcpy(self + 0xCC, &list_ptr, sizeof(void *));
#endif

    int ret = func_2768D0(self, nullptr, 0);
    assert(ret == 1);
    assert(g_set_sub_called == 0);
    printf("PASS test_arg2_zero_existing_match\n");
}

static void test_arg2_nonzero_update_match() {
    reset_mocks();
    unsigned char self[1024], owner[8192], res[128], item[64], list[64];
    void *item_vtbl[64];
    std::memset(self, 0, sizeof(self));
    std::memset(owner, 0, sizeof(owner));
    std::memset(res, 0, sizeof(res));
    std::memset(item, 0, sizeof(item));
    std::memset(list, 0, sizeof(list));

    g_mock_res = res;
    g_head_item = item;
    item_vtbl[8] = (void *)mock_item_id;
    item_vtbl[15] = (void *)mock_update_pos;
    void *item_vtbl_ptr = item_vtbl;
    std::memcpy(item, &item_vtbl_ptr, sizeof(void *));

    void *owner_ptr = owner;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    void *list_ptr = list;
    std::memcpy(self + 0x198, &list_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    void *list_ptr = list;
    std::memcpy(self + 0xCC, &list_ptr, sizeof(void *));
#endif

    int ret = func_2768D0(self, nullptr, 1);
    assert(ret == 1);
    assert(g_update_pos_called == 1);
    assert(g_set_sub_called == 0);
    printf("PASS test_arg2_nonzero_update_match\n");
}

static void test_create_sub_item_success() {
    reset_mocks();
    g_has_items = 0;
    unsigned char self[1024], owner[8192], res[128], list[64];
    void *self_vtbl[256];
    std::memset(self, 0, sizeof(self));
    std::memset(owner, 0, sizeof(owner));
    std::memset(res, 0, sizeof(res));
    std::memset(list, 0, sizeof(list));

    g_mock_res = res;
    self_vtbl[198] = (void *)mock_create_sub;
    self_vtbl[196] = (void *)mock_set_sub;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *owner_ptr = owner;
#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    void *list_ptr = list;
    std::memcpy(self + 0x198, &list_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    void *list_ptr = list;
    std::memcpy(self + 0xCC, &list_ptr, sizeof(void *));
#endif

    int ret = func_2768D0(self, nullptr, 0);
    assert(ret == 1);
    assert(g_func_352230_called == 1);
    assert(g_free_called == 1);
    assert(g_set_sub_called == 1);
    printf("PASS test_create_sub_item_success\n");
}

int main() {
    test_res_null();
    test_arg2_zero_existing_match();
    test_arg2_nonzero_update_match();
    test_create_sub_item_success();
    printf("All unit_action_build_68d0 tests passed!\n");
    return 0;
}
