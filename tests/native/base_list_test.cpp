#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "base_list.h"

ListNode s_node_pool[1000];

struct CallRecord {
    void *ptr;
    int size;
};

static CallRecord call_log[10];
static int call_count = 0;
static int free_call_count = 0;

void *__vt__8BaseList = 0;

extern "C" {
    int D_4E35DC = 0;
    char D_4D7A90[32] = {0};
    char D_4D7230[32] = {0};
    int D_10B68F0 = 0;

    void func_366af0(void *a, void *b) { (void)a; (void)b; }
    void func_139580(BaseList *list) {
        if (list && list->m_head) {
            ListNode *node = list->m_head;
            list->m_head = node->next;
            free_call_count++;
            list->FreeNode(node);
        }
    }
    void func_226d90(void *stream, void *dst, int size) {
        (void)stream;
        if (call_count < 10) {
            call_log[call_count].ptr = dst;
            call_log[call_count].size = size;
            memset(dst, 0, size);
            call_count++;
        }
    }
    void func_00226D90(void *stream, void *dst, int size) {
        func_226d90(stream, dst, size);
    }
    void func_226f70(void *stream, void *src, int size) {
        (void)stream;
        if (call_count < 10) {
            call_log[call_count].ptr = src;
            call_log[call_count].size = size;
            call_count++;
        }
    }
    void func_00226F70(void *stream, void *src, int size) {
        func_226f70(stream, src, size);
    }
    void __vec_ctor(void *ptr) { (void)ptr; }
    void func_2639D0(void *a, int b) { (void)a; (void)b; }
    void Cleanup__8BaseListFi(void *a, int b) { (void)a; (void)b; }
    void func_1DC100(void *a, int b) { (void)a; (void)b; }
    void func_1DC180(void *a, int b) { (void)a; (void)b; }
    void func_1DC2E0(void *a, int b) { (void)a; (void)b; }
    void func_3668C0(void *a, int b) { (void)a; (void)b; }
    void func_266840(void *a, int b) { (void)a; (void)b; }
    void func_1DC6B0(void *a, int b) { (void)a; (void)b; }
    void func_1DCAA0(void *a, int b) { (void)a; (void)b; }
    void func_267DD0(void *a, int b) { (void)a; (void)b; }
    void func_1DBEA0(void *a, int b) { (void)a; (void)b; }
    void func_139C80(void *a, int b) { (void)a; (void)b; }
    void func_1DBFC0(void *a, int b) { (void)a; (void)b; }
    void func_139CC0(void *a, int b) { (void)a; (void)b; }
    void func_3669F0(void *a, int b) { (void)a; (void)b; }
    void func_2C2DC0(void *a, int b) { (void)a; (void)b; }
    void func_1DC0B0(void *a, int b) { (void)a; (void)b; }
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

class MockListItem : public ListItem {
public:
    int action_called;
    int save_called;
    MockListItem() : action_called(0), save_called(0) {}
    virtual int Action() { action_called++; return 1; }
    virtual void Save(void *stream) { (void)stream; save_called++; }
};

static void test_init_and_reset() {
    memset(s_node_pool, 0, sizeof(s_node_pool));
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(10);
    list->Reset(20);
    assert(list->m_capacity == 20);
    assert(list->m_head == 0);
    printf("BASE_LIST_TEST_0_INIT_PASSED\n");
}

static void test_node_alloc_free() {
    memset(s_node_pool, 0, sizeof(s_node_pool));
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(10);
    ListNode *node1 = list->AllocNode();
    assert(node1 != 0);
    node1->item = (void*)0x1234;

    ListNode *node2 = list->AllocNode();
    assert(node2 != 0);
    assert(node2 != node1);

    list->FreeNode(node1);
    assert(node1->item == 0);

    list->FreeNode(node2);
    assert(node2->item == 0);
    printf("BASE_LIST_TEST_1_ALLOC_PASSED\n");
}

static void test_add_remove_head_tail() {
    memset(s_node_pool, 0, sizeof(s_node_pool));
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(10);
    WorldObj wobj;
    memset(&wobj, 0, sizeof(wobj));
    wobj.field_39 = 0;
    list->m_field4 = &wobj;

    MockListItem item1;
    MockListItem item2;

    list->AddHead(&item1);
    assert(list->m_head != 0);
    assert(list->m_head->item == &item1);

    list->AddTail(&item2);
    assert(list->m_head->next != 0);
    assert(list->m_head->next->item == &item2);

    void *removed = list->RemoveHead();
    assert(removed == &item1);
    assert(list->m_head->item == &item2);

    list->DeleteHead();
    assert(list->m_head == 0);
    printf("BASE_LIST_TEST_2_ADD_REMOVE_PASSED\n");
}

static void test_action_and_update() {
    memset(s_node_pool, 0, sizeof(s_node_pool));
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(10);
    WorldObj wobj;
    memset(&wobj, 0, sizeof(wobj));
    wobj.field_39 = 0;
    list->m_field4 = &wobj;

    MockListItem item1;
    list->AddHead(&item1);

    list->Action();
    assert(item1.action_called == 1);
    printf("BASE_LIST_TEST_3_ACTION_PASSED\n");
}

static void test_load_save() {
    memset(s_node_pool, 0, sizeof(s_node_pool));
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(10);
    call_count = 0;
    memset(call_log, 0, sizeof(call_log));

    list->Save((void*)0x5678);
    assert(call_count == 1);
    assert(call_log[0].size == 2);
    printf("BASE_LIST_TEST_4_LOAD_SAVE_PASSED\n");
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
    if (mode == 0) test_init_and_reset();
    else if (mode == 1) test_node_alloc_free();
    else if (mode == 2) test_add_remove_head_tail();
    else if (mode == 3) test_action_and_update();
    else if (mode == 4) test_load_save();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
