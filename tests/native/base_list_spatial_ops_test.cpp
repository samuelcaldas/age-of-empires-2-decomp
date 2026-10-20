#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "base_list.h"

ListNode s_node_pool[1000];
void *__vt__8BaseList = 0;
char D_10B68F0_buf[64] = {0};

static int setup_spatial_called = 0;
static int setup_spatial_flag_called = 0;
static int setup_called = 0;
static int setup_flag_called = 0;
static int cleanup_called = 0;

extern "C" {
    char *D_10B68F0 = D_10B68F0_buf;
    int D_4E35DC = 0;
    void __vec_ctor(void *ptr) { (void)ptr; }
    void func_366af0(void *a, void *b) { (void)a; (void)b; }
    void func_226d90(void *a, void *b, int c) { (void)a; (void)b; (void)c; }
    void func_226f70(void *a, void *b, int c) { (void)a; (void)b; (void)c; }
    void func_139580(BaseList *list) {
        if (list && list->m_head) {
            ListNode *node = list->m_head;
            list->m_head = node->next;
            list->FreeNode(node);
        }
    }

    void func_1DBEA0(void *a, void *b, void *c, int d, float e, float f, float g) {
        (void)a; (void)b; (void)c; (void)d; (void)e; (void)f; (void)g;
        setup_spatial_called++;
    }
    void func_139C80(void *a, void *b, void *c, float d, float e, float f) {
        (void)a; (void)b; (void)c; (void)d; (void)e; (void)f;
        setup_spatial_flag_called++;
    }
    void func_1DBFC0(void *a, void *b, void *c, int d) {
        (void)a; (void)b; (void)c; (void)d;
        setup_called++;
    }
    void func_139CC0(void *a, void *b, void *c) {
        (void)a; (void)b; (void)c;
        setup_flag_called++;
    }
    void func_3669F0(void *a, void *b) { (void)a; (void)b; }
    void func_2C2DC0(int a) { (void)a; }
    void func_1DC0B0(void *a, int b) { (void)a; (void)b; cleanup_called++; }
}

void ListItem::v0() {}
void ListItem::v1() {}
void ListItem::v2() {}
void ListItem::v3() {}
int ListItem::Action() { return 0; }
void ListItem::Save(void *stream) { (void)stream; }
int ListItem::v8() { return 0; }
void ListItem::Method9(void *a, void *b, void *c) { (void)a; (void)b; (void)c; }
bool ListItem::Method10() { return false; }
void ListItem::Method11() {}
bool ListItem::Method12() { return false; }
int ListItem::Method13() { return 0; }
int ListItem::Method14() { return 0; }
int ListItem::Method15(void *other, float x, float y, float z) { (void)other; (void)x; (void)y; (void)z; return 0; }
void ListItem::v16() {}
void ListItem::v17() {}
void ListItem::Method18(int msg) { (void)msg; }
void ListItem::Method19(int a, int b, int c) { (void)a; (void)b; (void)c; }
void ListItem::v20() {}
void* ListItem::v21() { return 0; }
void ListItem::v22() {}
void ListItem::v23() {}
void ListItem::v24() {}
void ListItem::v25() {}
void ListItem::Method26() {}

class SpatialMockItem : public ListItem {
public:
    virtual void Method11() {}
};

static void test_base_list_setup_spatial() {
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);
    list->m_fieldC8 = 99;

    setup_spatial_called = 0;
    setup_spatial_flag_called = 0;

    list->SetupSpatial((void*)0x111, (void*)0x222, 1, 1.0f, 2.0f, 3.0f);
    assert(list->m_fieldC8 == 0);
    assert(setup_spatial_called == 1);
    assert(setup_spatial_flag_called == 1);
    printf("BASE_LIST_SPATIAL_OPS_TEST_0_SETUP_SPATIAL_PASSED\n");
}

static void test_base_list_setup() {
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);
    list->m_fieldC8 = 99;

    setup_called = 0;
    setup_flag_called = 0;

    list->Setup((void*)0x111, (void*)0x222, 1);
    assert(list->m_fieldC8 == 0);
    assert(setup_called == 1);
    assert(setup_flag_called == 1);
    printf("BASE_LIST_SPATIAL_OPS_TEST_1_SETUP_PASSED\n");
}

static void test_base_list_cleanup() {
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);
    SpatialMockItem item;
    list->m_fieldCC = &item;
    list->m_fieldC8 = 10;

    cleanup_called = 0;
    list->Cleanup(1);
    assert(list->m_fieldCC == 0);
    assert(list->m_fieldC8 == 0);
    assert(cleanup_called == 1);
    printf("BASE_LIST_SPATIAL_OPS_TEST_2_CLEANUP_PASSED\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: test mode selector argument required (0-2)\n");
        return 1;
    }
    char *endptr = 0;
    long mode_l = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Error: invalid test mode format '%s'\n", argv[1]);
        return 1;
    }
    int mode = (int)mode_l;
    if (mode == 0) test_base_list_setup_spatial();
    else if (mode == 1) test_base_list_setup();
    else if (mode == 2) test_base_list_cleanup();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
