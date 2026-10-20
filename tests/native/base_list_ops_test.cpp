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

static int method13_called = 0;
static int method14_called = 0;
static int method15_called = 0;
static int v8_type = 42;

extern "C" {
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

class OpsMockItem : public ListItem {
public:
    virtual int v8() { return v8_type; }
    virtual int Method13() { method13_called++; return 100; }
    virtual int Method14() { method14_called++; return 200; }
    virtual int Method15(void *other, float x, float y, float z) {
        (void)other; (void)x; (void)y; (void)z;
        method15_called++; return 300;
    }
};

static void test_base_list_ops_remove_head() {
    memset(s_node_pool, 0, sizeof(s_node_pool));
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);
    WorldObj wobj;
    memset(&wobj, 0, sizeof(wobj));
    wobj.field_39 = 0;
    list->m_field4 = &wobj;

    OpsMockItem item;
    list->AddHead(&item);
    assert(list->HasItems() == 1);

    void *removed = list->RemoveHead();
    assert(removed == &item);
    assert(list->HasItems() == 0);
    printf("BASE_LIST_OPS_TEST_0_REMOVE_HEAD_PASSED\n");
}

static void test_base_list_ops_contains_and_find() {
    memset(s_node_pool, 0, sizeof(s_node_pool));
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);
    WorldObj wobj;
    memset(&wobj, 0, sizeof(wobj));
    wobj.field_39 = 0;
    list->m_field4 = &wobj;

    v8_type = 42;
    OpsMockItem item;
    list->AddHead(&item);

    assert(list->Contains(42) == 1);
    assert(list->Contains(99) == 0);
    assert(list->FindItem(42) == &item);
    assert(list->FindItem(99) == 0);
    assert(list->GetHeadItem() == &item);
    printf("BASE_LIST_OPS_TEST_1_CONTAINS_FIND_PASSED\n");
}

static void test_base_list_ops_calls() {
    memset(s_node_pool, 0, sizeof(s_node_pool));
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);
    WorldObj wobj;
    memset(&wobj, 0, sizeof(wobj));
    wobj.field_39 = 0;
    list->m_field4 = &wobj;

    OpsMockItem item;
    list->AddHead(&item);

    method13_called = 0;
    method14_called = 0;
    method15_called = 0;

    assert(list->CallMethod13() == 100);
    assert(method13_called == 1);

    assert(list->CallMethod14() == 200);
    assert(method14_called == 1);

    assert(list->CallMethod15() == 300);
    assert(method15_called == 1);
    printf("BASE_LIST_OPS_TEST_2_CALLS_PASSED\n");
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
    if (mode == 0) test_base_list_ops_remove_head();
    else if (mode == 1) test_base_list_ops_contains_and_find();
    else if (mode == 2) test_base_list_ops_calls();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
