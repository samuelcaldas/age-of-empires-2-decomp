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
extern const char D_490AE0[] = "ERR";

static void *last_item_ptr = (void*)0x8888;
static int factory_called = 0;
static int init_called = 0;

extern "C" {
    int D_4E35DC = 0;

    void __vec_ctor(void *ptr) { (void)ptr; }
    void func_139580(BaseList *list) { (void)list; }
    void func_226d90(void *s, void *d, int sz) { (void)s; (void)d; (void)sz; }
    void func_226f70(void *s, void *d, int sz) { (void)s; (void)d; (void)sz; }

    void func_118DE0(const char *msg) {
        (void)msg;
    }
    void* func_366BC0(void *arg) { (void)arg; factory_called++; return last_item_ptr; }
    void* func_366BE0(void *arg) { (void)arg; factory_called++; return last_item_ptr; }
    void* func_366BF0(void *arg) { (void)arg; factory_called++; return last_item_ptr; }
    void* func_366C00(void *arg) { (void)arg; factory_called++; return last_item_ptr; }
    void* func_366C10(void *arg) { (void)arg; factory_called++; return last_item_ptr; }
    void* func_366C20(void *arg) { (void)arg; factory_called++; return last_item_ptr; }
    void* func_366C30(void *arg) { (void)arg; factory_called++; return last_item_ptr; }

    void func_347C80(void *item, void *stream, int cap) { (void)item; (void)stream; (void)cap; init_called++; }
    void func_34B730(void *item, void *stream, int cap) { (void)item; (void)stream; (void)cap; init_called++; }
    void func_34BC10(void *item, void *stream, int cap) { (void)item; (void)stream; (void)cap; init_called++; }
    void func_34E1B0(void *item, void *stream, int cap) { (void)item; (void)stream; (void)cap; init_called++; }
    void func_34E300(void *item, void *stream, int cap) { (void)item; (void)stream; (void)cap; init_called++; }
    void func_34E610(void *item, void *stream, int cap) { (void)item; (void)stream; (void)cap; init_called++; }
    void func_34FA10(void *item, void *stream, int cap) { (void)item; (void)stream; (void)cap; init_called++; }
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

static void test_create_item_type_9() {
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);
    factory_called = 0;
    init_called = 0;

    void *item = list->CreateItem((void*)0x1234, 9);
    assert(item == last_item_ptr);
    assert(factory_called == 1);
    assert(init_called == 1);
    printf("ITEM_CREATOR_TEST_0_TYPE9_PASSED\n");
}

static void test_create_item_type_2() {
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);

    void *item = list->CreateItem((void*)0x1234, 2);
    assert(item == 0);
    printf("ITEM_CREATOR_TEST_1_TYPE2_PASSED\n");
}

static void test_create_item_unknown() {
    char storage[sizeof(BaseList)];
    memset(storage, 0, sizeof(storage));
    BaseList *list = new (storage) BaseList(5);

    void *item = list->CreateItem((void*)0x1234, 999);
    assert(item == 0);
    printf("ITEM_CREATOR_TEST_2_UNKNOWN_PASSED\n");
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
    if (mode == 0) test_create_item_type_9();
    else if (mode == 1) test_create_item_type_2();
    else if (mode == 2) test_create_item_unknown();
    else {
        fprintf(stderr, "Error: invalid test mode %d\n", mode);
        return 1;
    }
    return 0;
}
