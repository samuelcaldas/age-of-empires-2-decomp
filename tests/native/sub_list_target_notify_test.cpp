#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "sub_list.h"

static int sub_list_v17_called = 0;
static void *sub_list_v17_a = 0;
static void *sub_list_v17_b = 0;
static void *sub_list_v17_c = 0;

static int list_item_method9_called = 0;
static void *list_item_method9_a = 0;
static void *list_item_method9_b = 0;
static void *list_item_method9_c = 0;

static int player_method17_called = 0;
static int player_method17_val = 0;

struct MasterObjects {
    char pad_00[4];
    void **m_table;
    short m_count;
};

struct MasterStaticObject {
    char pad0[6];
    short id;
    char pad1[0x2C];
    int type1;
    int type2;
    int type3;
    int type4;
};

extern "C" {
    void func_0013C0D0(SubList *self, void *param1);
    void func_0013C250(SubList *self);
}

#define DEF_PLAYER_V10(base) \
    void* PlayerContext::v##base##0() { return 0; } void* PlayerContext::v##base##1() { return 0; } \
    void* PlayerContext::v##base##2() { return 0; } void* PlayerContext::v##base##3() { return 0; } \
    void* PlayerContext::v##base##4() { return 0; } void* PlayerContext::v##base##5() { return 0; } \
    void* PlayerContext::v##base##6() { return 0; } void* PlayerContext::v##base##7() { return 0; } \
    void* PlayerContext::v##base##8() { return 0; } void* PlayerContext::v##base##9() { return 0; }

DEF_PLAYER_V10(0)
void* PlayerContext::v10() { return 0; }
void* PlayerContext::v11() { return 0; }
void* PlayerContext::v12() { return 0; }
void* PlayerContext::v13() { return 0; }
void* PlayerContext::v14() { return 0; }
void* PlayerContext::v15() { return 0; }
void* PlayerContext::v16() { return 0; }
void* PlayerContext::Method17(int val) {
    player_method17_called++;
    player_method17_val = val;
    return 0;
}

void ListItem::v0() {}
void ListItem::v1() {}
void ListItem::v2() {}
void ListItem::v3() {}
int ListItem::Action() { return 0; }
void ListItem::Save(void*) {}
int ListItem::v8() { return 0; }
void ListItem::Method9(void *a, void *b, void *c) {
    list_item_method9_called++;
    list_item_method9_a = a;
    list_item_method9_b = b;
    list_item_method9_c = c;
}
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
void* SubList::v17(void *a, void *b, void *c) {
    sub_list_v17_called++;
    sub_list_v17_a = a;
    sub_list_v17_b = b;
    sub_list_v17_c = c;
    return 0;
}
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
void* SubList::v197() { return 0; }
void* SubList::v198() { return 0; }
void* SubList::v199(short, void*, float, float, float) { return 0; }
void* SubList::v200() { return 0; }
BaseList* SubList::v201() { return 0; }

static void test_sub_list_target_notify_null_field30() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();
    self->m_field30 = 0;

    char item_storage[sizeof(ListItem)];
    memset(item_storage, 0, sizeof(item_storage));
    ListItem *item = new (item_storage) ListItem();
    self->m_field34 = item;

    sub_list_v17_called = 0;
    list_item_method9_called = 0;

    void *param1 = (void*)0x12345678;
    func_0013C0D0(self, param1);

    assert(sub_list_v17_called == 1);
    assert(sub_list_v17_a == param1);
    assert(sub_list_v17_b == 0);
    assert(sub_list_v17_c == 0);
    assert(list_item_method9_called == 1);
    assert(list_item_method9_a == param1);
    assert(list_item_method9_b == 0);
    assert(list_item_method9_c == 0);
    printf("SUB_LIST_TARGET_NOTIFY_TEST_0_NULL_FIELD30_PASSED\n");
}

static void test_sub_list_target_notify_match_found() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char old_target_buf[16];
    memset(old_target_buf, 0, sizeof(old_target_buf));
    *(short*)(old_target_buf + 6) = 15;
    self->m_field30 = old_target_buf;

    char player_storage[sizeof(PlayerContext)];
    memset(player_storage, 0, sizeof(player_storage));
    PlayerContext *player = new (player_storage) PlayerContext();
    player->m_target_type = 77;
    self->m_field8 = (WorldContainer*)(void*)player;

    char item_storage[sizeof(ListItem)];
    memset(item_storage, 0, sizeof(item_storage));
    ListItem *item = new (item_storage) ListItem();
    self->m_field34 = item;

    MasterStaticObject static_obj;
    memset(&static_obj, 0, sizeof(static_obj));
    static_obj.id = 15;
    static_obj.type1 = 77;

    void *table[1] = {&static_obj};
    MasterObjects header;
    memset(&header, 0, sizeof(header));
    header.m_count = 1;
    header.m_table = table;

    char param1_buf[0xD0];
    memset(param1_buf, 0, sizeof(param1_buf));
    *(MasterObjects**)(param1_buf + 0xC8) = &header;

    sub_list_v17_called = 0;
    list_item_method9_called = 0;
    player_method17_called = 0;

    func_0013C0D0(self, param1_buf);
    assert(player_method17_called == 1);
    assert(player_method17_val == 77);
    assert(sub_list_v17_called == 1);
    assert(sub_list_v17_a == param1_buf);
    assert(sub_list_v17_b == old_target_buf);
    assert(sub_list_v17_c == &static_obj);
    assert(list_item_method9_called == 1);
    assert(self->m_field30 == &static_obj);
    printf("SUB_LIST_TARGET_NOTIFY_TEST_1_MATCH_FOUND_PASSED\n");
}

static void test_sub_list_target_notify_not_found() {
    char sublist_storage[sizeof(SubList)];
    memset(sublist_storage, 0, sizeof(sublist_storage));
    SubList *self = new (sublist_storage) SubList();

    char old_target_buf[16];
    memset(old_target_buf, 0, sizeof(old_target_buf));
    *(short*)(old_target_buf + 6) = 99; // ID 99 does not exist in table
    self->m_field30 = old_target_buf;

    MasterStaticObject static_obj;
    memset(&static_obj, 0, sizeof(static_obj));
    static_obj.id = 15;

    void *table[1] = {&static_obj};
    MasterObjects header;
    memset(&header, 0, sizeof(header));
    header.m_count = 1;
    header.m_table = table;

    char param1_buf[0xD0];
    memset(param1_buf, 0, sizeof(param1_buf));
    *(MasterObjects**)(param1_buf + 0xC8) = &header;

    sub_list_v17_called = 0;
    list_item_method9_called = 0;

    func_0013C0D0(self, param1_buf);
    assert(sub_list_v17_called == 0);
    assert(list_item_method9_called == 0);
    assert(self->m_field30 == old_target_buf);
    printf("SUB_LIST_TARGET_NOTIFY_TEST_2_NOT_FOUND_PASSED\n");
}

static void test_sub_list_target_notify_func_0013c250() {
    func_0013C250(0);
    printf("SUB_LIST_TARGET_NOTIFY_TEST_3_C250_PASSED\n");
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
    if (mode == 0) test_sub_list_target_notify_null_field30();
    else if (mode == 1) test_sub_list_target_notify_match_found();
    else if (mode == 2) test_sub_list_target_notify_not_found();
    else if (mode == 3) test_sub_list_target_notify_func_0013c250();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
