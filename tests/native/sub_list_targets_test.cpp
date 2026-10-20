#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

static void *func_332e60_ret = 0;
static void *func_332e60_mgr = 0;
static int func_332e60_id = 0;
static int func_332e60_called = 0;

static int method50_called = 0;
static void *method50_player = 0;
static short method50_id = 0;
static int method50_zero = -1;

static int method51_called = 0;
static void *method51_player = 0;

static int sub_list_v21_called = 0;
static int sub_list_v22_called = 0;
static int mock_action_called = 0;
static int mock_action_ret = 42;

extern "C" {
    void* func_332e60(void *mgr, int id) {
        func_332e60_called++;
        func_332e60_mgr = mgr;
        func_332e60_id = id;
        return func_332e60_ret;
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
void* SubList::v21(int) { sub_list_v21_called++; return 0; }
void* SubList::v22(void*) { sub_list_v22_called++; return 0; }
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

void ListItem::v0() {}
void ListItem::v1() {}
void ListItem::v2() {}
void ListItem::v3() {}
int ListItem::Action() {
    mock_action_called++;
    return mock_action_ret;
}
void ListItem::Save(void*) {}
int ListItem::v8() { return 0; }
void ListItem::Method9(void*, void*, void*) {}
bool ListItem::Method10() { return false; }
void ListItem::Method11() {}
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

#define DEF_TARGET_V10(base) \
    void* TargetEntity::v##base##0() { return 0; } void* TargetEntity::v##base##1() { return 0; } \
    void* TargetEntity::v##base##2() { return 0; } void* TargetEntity::v##base##3() { return 0; } \
    void* TargetEntity::v##base##4() { return 0; } void* TargetEntity::v##base##5() { return 0; } \
    void* TargetEntity::v##base##6() { return 0; } void* TargetEntity::v##base##7() { return 0; } \
    void* TargetEntity::v##base##8() { return 0; } void* TargetEntity::v##base##9() { return 0; }

DEF_TARGET_V10(0)
DEF_TARGET_V10(1)
DEF_TARGET_V10(2)
DEF_TARGET_V10(3)
DEF_TARGET_V10(4)

void TargetEntity::Method50(void *player, short id, int zero) {
    method50_called++;
    method50_player = player;
    method50_id = id;
    method50_zero = zero;
}
void TargetEntity::Method51(void *player) {
    method51_called++;
    method51_player = player;
}

static void test_sub_list_targets_be90_action() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char item_storage[sizeof(ListItem)];
    memset(item_storage, 0, sizeof(item_storage));
    ListItem *item = new (item_storage) ListItem();
    item->m_field8 = (void*)1;
    self->m_field34 = item;

    mock_action_called = 0;
    mock_action_ret = 88;
    int res = func_0013BE90(self);
    assert(res == 88);
    assert(mock_action_called == 1);
    printf("SUB_LIST_TARGETS_TEST_0_BE90_ACTION_PASSED\n");
}

static void test_sub_list_targets_be90_flags() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char item_storage[sizeof(ListItem)];
    memset(item_storage, 0, sizeof(item_storage));
    ListItem *item = new (item_storage) ListItem();
    item->m_field8 = 0;
    self->m_field34 = item;

    self->m_fieldC = 1;
    assert(func_0013BE90(self) == 1);

    self->m_fieldC = 0;
    assert(func_0013BE90(self) == 0);
    printf("SUB_LIST_TARGETS_TEST_1_BE90_FLAGS_PASSED\n");
}

static void test_sub_list_targets_bf50_set_new() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field4_short = 7;

    // Set up world pointer structure
    char world_buf[0xC00];
    memset(world_buf, 0, sizeof(world_buf));
    void *dummy_mgr = (void*)0x998877;
    *(void**)(world_buf + 0xB98) = dummy_mgr;

    char player_buf[16];
    memset(player_buf, 0, sizeof(player_buf));
    *(void**)(player_buf + 8) = world_buf;
    self->m_field8 = (WorldContainer*)player_buf;

    char old_entity_storage[sizeof(TargetEntity)];
    memset(old_entity_storage, 0, sizeof(old_entity_storage));
    TargetEntity *old_entity = new (old_entity_storage) TargetEntity();
    self->m_field10 = (int)(void*)old_entity;
    self->m_field18 = 50;

    char new_entity_storage[sizeof(TargetEntity) + 0x30];
    memset(new_entity_storage, 0, sizeof(new_entity_storage));
    TargetEntity *new_entity = new (new_entity_storage) TargetEntity();
    *(short*)((char*)new_entity + 0x24) = 75;

    func_332e60_called = 0;
    func_332e60_ret = old_entity;
    method51_called = 0;
    method50_called = 0;

    func_0013BF50(self, new_entity);
    assert(func_332e60_called == 1);
    assert(func_332e60_mgr == dummy_mgr);
    assert(func_332e60_id == 50);
    assert(method51_called == 1);
    assert(method51_player == player_buf);
    assert(self->m_field10 == (int)(void*)new_entity);
    assert(self->m_field18 == 75);
    assert(method50_called == 1);
    assert(method50_player == player_buf);
    assert(method50_id == 7);
    printf("SUB_LIST_TARGETS_TEST_2_BF50_SET_NEW_PASSED\n");
}

static void test_sub_list_targets_bf50_clear() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char world_buf[0xC00];
    memset(world_buf, 0, sizeof(world_buf));
    void *dummy_mgr = (void*)0x998877;
    *(void**)(world_buf + 0xB98) = dummy_mgr;

    char player_buf[16];
    memset(player_buf, 0, sizeof(player_buf));
    *(void**)(player_buf + 8) = world_buf;
    self->m_field8 = (WorldContainer*)player_buf;

    char old_entity_storage[sizeof(TargetEntity)];
    memset(old_entity_storage, 0, sizeof(old_entity_storage));
    TargetEntity *old_entity = new (old_entity_storage) TargetEntity();
    self->m_field10 = (int)(void*)old_entity;
    self->m_field18 = 50;

    func_332e60_called = 0;
    func_332e60_ret = old_entity;
    method51_called = 0;

    func_0013BF50(self, 0);
    assert(func_332e60_called == 1);
    assert(method51_called == 1);
    assert(self->m_field10 == 0);
    assert(self->m_field18 == -1);
    printf("SUB_LIST_TARGETS_TEST_3_BF50_CLEAR_PASSED\n");
}

static void test_sub_list_targets_c010_set_new() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field4_short = 14;

    char world_buf[0xC00];
    memset(world_buf, 0, sizeof(world_buf));
    void *dummy_mgr = (void*)0x998877;
    *(void**)(world_buf + 0xB98) = dummy_mgr;

    char player_buf[16];
    memset(player_buf, 0, sizeof(player_buf));
    *(void**)(player_buf + 8) = world_buf;
    self->m_field8 = (WorldContainer*)player_buf;

    char old_entity_storage[sizeof(TargetEntity)];
    memset(old_entity_storage, 0, sizeof(old_entity_storage));
    TargetEntity *old_entity = new (old_entity_storage) TargetEntity();
    self->m_field14 = (int)(void*)old_entity;
    self->m_field1C = 60;

    char new_entity_storage[sizeof(TargetEntity) + 0x30];
    memset(new_entity_storage, 0, sizeof(new_entity_storage));
    TargetEntity *new_entity = new (new_entity_storage) TargetEntity();
    *(short*)((char*)new_entity + 0x24) = 85;

    func_332e60_called = 0;
    func_332e60_ret = old_entity;
    method51_called = 0;
    method50_called = 0;

    func_0013C010(self, new_entity);
    assert(func_332e60_called == 1);
    assert(func_332e60_id == 60);
    assert(method51_called == 1);
    assert(self->m_field14 == (int)(void*)new_entity);
    assert(self->m_field1C == 85);
    assert(method50_called == 1);
    assert(method50_id == 14);
    printf("SUB_LIST_TARGETS_TEST_4_C010_SET_NEW_PASSED\n");
}

static void test_sub_list_targets_c010_clear() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char world_buf[0xC00];
    memset(world_buf, 0, sizeof(world_buf));
    void *dummy_mgr = (void*)0x998877;
    *(void**)(world_buf + 0xB98) = dummy_mgr;

    char player_buf[16];
    memset(player_buf, 0, sizeof(player_buf));
    *(void**)(player_buf + 8) = world_buf;
    self->m_field8 = (WorldContainer*)player_buf;

    char old_entity_storage[sizeof(TargetEntity)];
    memset(old_entity_storage, 0, sizeof(old_entity_storage));
    TargetEntity *old_entity = new (old_entity_storage) TargetEntity();
    self->m_field14 = (int)(void*)old_entity;
    self->m_field1C = 60;

    func_332e60_called = 0;
    func_332e60_ret = old_entity;
    method51_called = 0;

    func_0013C010(self, 0);
    assert(func_332e60_called == 1);
    assert(method51_called == 1);
    assert(self->m_field14 == 0);
    assert(self->m_field1C == -1);
    printf("SUB_LIST_TARGETS_TEST_5_C010_CLEAR_PASSED\n");
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
    if (mode == 0) test_sub_list_targets_be90_action();
    else if (mode == 1) test_sub_list_targets_be90_flags();
    else if (mode == 2) test_sub_list_targets_bf50_set_new();
    else if (mode == 3) test_sub_list_targets_bf50_clear();
    else if (mode == 4) test_sub_list_targets_c010_set_new();
    else if (mode == 5) test_sub_list_targets_c010_clear();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
