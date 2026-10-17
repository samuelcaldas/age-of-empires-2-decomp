// Tests for func_276690 — Milestone 94 (568B)
// Verifies ActionBuild target positioning, terrain/layer verification, and task item 0x6A sub-object allocation.
#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_build_6690.h"

static void *g_mock_res = (void *)0x1000;
static int g_has_items = 1;
static void *g_head_item = nullptr;
static int g_free_called = 0;
static void *g_mock_sub_obj = (void *)0x2000;
static void *g_mock_pool_item = (void *)0x3000;
static int g_func_360080_called = 0;
static int g_set_sub_called = 0;
static int g_update_pos_called = 0;
static int g_method_26_called = 0;
static int g_last_create_flag = -1;

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

extern "C" void *func_366D50(void *) {
    return g_mock_pool_item;
}

extern "C" void func_360080(void *, void *, void *, void *) {
    g_func_360080_called++;
}

static void *mock_item_type(void *) { return g_mock_res; }
static short mock_item_id(void *) { return 0x6A; }
static void mock_update_pos(void *, void *, float, float, float) { g_update_pos_called++; }
static void mock_method_26(void *) { g_method_26_called++; }

static void *mock_create_sub(void *, void *, int flag, float, float, float) {
    g_last_create_flag = flag;
    return g_mock_sub_obj;
}

static void mock_set_sub(void *, void *) { g_set_sub_called++; }

static void reset_mocks() {
    g_mock_res = (void *)0x1000;
    g_has_items = 1;
    g_head_item = nullptr;
    g_free_called = 0;
    g_mock_sub_obj = (void *)0x2000;
    g_mock_pool_item = (void *)0x3000;
    g_func_360080_called = 0;
    g_set_sub_called = 0;
    g_update_pos_called = 0;
    g_method_26_called = 0;
    g_last_create_flag = -1;
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

    int ret = func_276690(self, nullptr, 0);
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

    int ret = func_276690(self, nullptr, 0);
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

    int ret = func_276690(self, nullptr, 1);
    assert(ret == 1);
    assert(g_update_pos_called == 1);
    assert(g_set_sub_called == 0);
    printf("PASS test_arg2_nonzero_update_match\n");
}

static void test_create_sub_item_flag1_map270() {
    reset_mocks();
    g_has_items = 0;
    unsigned char self[1024], proto[512], owner[8192], map[1024], res[128], list[64];
    void *self_vtbl[256];
    std::memset(self, 0, sizeof(self));
    std::memset(proto, 0, sizeof(proto));
    std::memset(owner, 0, sizeof(owner));
    std::memset(map, 0, sizeof(map));
    std::memset(res, 0, sizeof(res));
    std::memset(list, 0, sizeof(list));

    proto[0xCE] = 1;
    void *non_zero_val = (void *)0x8888;
    std::memcpy(map + 0x270, &non_zero_val, sizeof(void *));

    self_vtbl[26] = (void *)mock_method_26;
    self_vtbl[198] = (void *)mock_create_sub;
    self_vtbl[196] = (void *)mock_set_sub;
    void *self_vtbl_ptr = self_vtbl;
    std::memcpy(self, &self_vtbl_ptr, sizeof(void *));

    void *proto_ptr = proto;
    void *owner_ptr = owner;
    void *map_ptr = map;
    void *list_ptr = list;

#if defined(__LP64__) || defined(_LP64)
    std::memcpy(self + 0x8, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x10, &owner_ptr, sizeof(void *));
    std::memcpy(self + 0x198, &list_ptr, sizeof(void *));
    std::memcpy(owner + 0xE0, &map_ptr, sizeof(void *));
#else
    std::memcpy(self + 0x4, &proto_ptr, sizeof(void *));
    std::memcpy(self + 0x8, &owner_ptr, sizeof(void *));
    std::memcpy(self + 0xCC, &list_ptr, sizeof(void *));
    std::memcpy(owner + 0x70, &map_ptr, sizeof(void *));
#endif

    g_mock_res = res;

    int ret = func_276690(self, nullptr, 0);
    assert(ret == 1);
    assert(g_method_26_called == 1);
    assert(g_last_create_flag == 0x6A);
    assert(g_func_360080_called == 1);
    assert(g_free_called == 1);
    assert(g_set_sub_called == 1);
    printf("PASS test_create_sub_item_flag1_map270\n");
}

int main() {
    test_res_null();
    test_arg2_zero_existing_match();
    test_arg2_nonzero_update_match();
    test_create_sub_item_flag1_map270();
    printf("All unit_action_build_6690 tests passed!\n");
    return 0;
}
