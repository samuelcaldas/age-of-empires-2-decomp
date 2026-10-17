#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

static int g_freed = 0;
static int g_cleared = 0;

struct MockNode {
    void *item_ptr;
    MockNode *next;
    unsigned char mode;
    unsigned char priority;
    unsigned char b10;
    unsigned char ref_count;
};

extern "C" {
void func_001824a0(void *this_ptr) {
    *(void **)this_ptr = 0;
    g_cleared++;
}
int func_002634A0(void *texture) { (void)texture; return 0; }
void func_0026A460() {}
void *func_001831B0(void *pool) {
    (void)pool;
    return malloc(sizeof(MockNode));
}
void func_00183210(void *pool, void *item) {
    (void)pool;
    free(item);
    g_freed++;
}
void *func_001840D0(void *f, void *tex, int p, short x, short y, int fl) {
    (void)f; (void)p; (void)x; (void)y; (void)fl;
    void **entry = (void **)malloc(sizeof(void *) * 4);
    entry[0] = tex;
    return entry;
}
int func_00183740(void *p) { (void)p; return 0; }
void func_00183380(void *p) { (void)p; }
void func_00183920(void *p) { (void)p; }

void *func_00182550(void *this_ptr);
void func_001825d0(void *this_ptr, void *new_items);
void func_00182610(void *this_ptr, void *texture, int priority, short x, short y, int flags);
void func_001827b0(void *this_ptr, void *texture);
}

static void test_set_items() {
    g_cleared = 0;
    void *obj[2] = { (void *)0x1111, 0 };
    func_001825d0(obj, (void *)0x2222);
    assert(g_cleared == 1);
    assert(obj[0] == (void *)0x2222);
}

static void test_insert_empty() {
    void *obj[2] = { 0, 0 };
    func_00182610(obj, (void *)0x1234, 10, 0, 0, 0);
    assert(obj[0] != 0);
    MockNode *node = (MockNode *)obj[0];
    assert(node->ref_count == 0);
    assert(*(void **)node->item_ptr == (void *)0x1234);
    free(node->item_ptr);
    free(node);
}

static void test_insert_duplicate() {
    void *obj[2] = { 0, 0 };
    func_00182610(obj, (void *)0x1234, 10, 0, 0, 0);
    MockNode *node = (MockNode *)obj[0];
    assert(node->ref_count == 0);
    func_00182610(obj, (void *)0x1234, 10, 0, 0, 0);
    assert(node->ref_count == 1);
    free(node->item_ptr);
    free(node);
}

static void test_decrement_ref() {
    void *obj[2] = { 0, 0 };
    func_00182610(obj, (void *)0x1234, 10, 0, 0, 0);
    MockNode *node = (MockNode *)obj[0];
    node->ref_count = 2;
    func_001827b0(obj, (void *)0x1234);
    assert(node->ref_count == 1);
    free(node->item_ptr);
    free(node);
}

static void test_unlink_on_zero() {
    g_freed = 0;
    void *obj[2] = { 0, 0 };
    func_00182610(obj, (void *)0x1234, 10, 0, 0, 0);
    MockNode *node = (MockNode *)obj[0];
    node->ref_count = 0;
    void *entry = node->item_ptr;
    func_001827b0(obj, (void *)0x1234);
    assert(obj[0] == 0);
    assert(g_freed == 1);
    free(entry);
}

static void test_replay() {
    void *obj[2] = { 0, 0 };
    void *ret = func_00182550(obj);
    assert(ret == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    switch (c) {
        case 0: test_set_items(); break;
        case 1: test_insert_empty(); break;
        case 2: test_insert_duplicate(); break;
        case 3: test_decrement_ref(); break;
        case 4: test_unlink_on_zero(); break;
        case 5: test_replay(); break;
        default: return 1;
    }
    return 0;
}
