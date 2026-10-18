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

static int method9_called = 0;
static int method26_called = 0;

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
void ListItem::Method9(void *a, void *b, void *c) { (void)a; (void)b; (void)c; method9_called++; }
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
void ListItem::Method26() { method26_called++; }

class NodeMgrMockItem : public ListItem {
public:
};

static void test_base_list_node_mgr_add_head() {
    memset(s_node_pool, 0, sizeof(s_node_pool));
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);
    WorldObj wobj;
    memset(&wobj, 0, sizeof(wobj));
    wobj.field_39 = 0;
    list->m_field4 = &wobj;

    NodeMgrMockItem item;
    method9_called = 0;

    list->AddHead(&item);
    assert(list->m_head != 0);
    assert(list->m_head->item == &item);
    assert(method9_called == 1);
    printf("BASE_LIST_NODE_MGR_TEST_0_ADD_HEAD_PASSED\n");
}

static void test_base_list_node_mgr_add_tail() {
    memset(s_node_pool, 0, sizeof(s_node_pool));
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);
    WorldObj wobj;
    memset(&wobj, 0, sizeof(wobj));
    wobj.field_39 = 0;
    list->m_field4 = &wobj;

    NodeMgrMockItem item1;
    NodeMgrMockItem item2;

    list->AddHead(&item1);
    list->AddTail(&item2);
    assert(list->m_head->next != 0);
    assert(list->m_head->next->item == &item2);
    printf("BASE_LIST_NODE_MGR_TEST_1_ADD_TAIL_PASSED\n");
}

static void test_base_list_node_mgr_delete_head() {
    memset(s_node_pool, 0, sizeof(s_node_pool));
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);
    WorldObj wobj;
    memset(&wobj, 0, sizeof(wobj));
    wobj.field_39 = 0;
    list->m_field4 = &wobj;

    NodeMgrMockItem item;
    list->AddHead(&item);

    method26_called = 0;
    list->DeleteHead();
    assert(list->m_head == 0);
    assert(method26_called == 1);
    printf("BASE_LIST_NODE_MGR_TEST_2_DELETE_HEAD_PASSED\n");
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
    if (mode == 0) test_base_list_node_mgr_add_head();
    else if (mode == 1) test_base_list_node_mgr_add_tail();
    else if (mode == 2) test_base_list_node_mgr_delete_head();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
