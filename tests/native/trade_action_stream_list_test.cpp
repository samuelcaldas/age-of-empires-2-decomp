#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

static int g_freed = 0;
static int g_cleared = 0;
static int g_serialized_bytes = 0;

struct MockNode {
    void *item_ptr;
    MockNode *next;
    unsigned char mode;
    unsigned char b9;
    unsigned char b10;
    unsigned char b11;
};

extern "C" {
void func_00100670(void *ptr) { free(ptr); }
int func_00226D90(void *stream, void *buf, int count) {
    (void)stream; (void)buf; (void)count;
    return 0;
}
void func_00226F70(void *stream, void *buf, int count) {
    (void)stream; (void)buf;
    g_serialized_bytes += count;
}
void *func_001831B0(void *pool) {
    (void)pool;
    return malloc(sizeof(MockNode));
}
void func_00183210(void *pool, void *item) {
    (void)pool;
    free(item);
    g_freed++;
}
void *func_00184140(void *f, void *s, int p) {
    (void)f; (void)s; (void)p;
    return (void *)0x1234;
}
void *func_00184280(void *f, void *s, int p) {
    (void)f; (void)s; (void)p;
    return (void *)0x5678;
}
void func_001833A0(void *p, void *s, void *o) { (void)p; (void)s; (void)o; }
void func_00183930(void *p, void *s, void *o) { (void)p; (void)s; (void)o; }
int func_00183740(void *p) { (void)p; return 0; }
void func_00183380(void *p) { (void)p; }
void func_00183920(void *p) { (void)p; }
void func_0026A460() {}
void func_001234E0(int arg) { (void)arg; }
void func_00100190(int a0, int a1) { (void)a0; (void)a1; }

void *func_001820d0(void *this_ptr, void *param);
void *func_001820f0(void *this_ptr, short flag);
void func_00182150(void *this_ptr, void *stream, int param);
int func_001821f0(void *this_ptr, void *stream, int opcode, int param);
void func_001823e0(void *this_ptr, void *stream);
void func_001824a0(void *this_ptr);
}

static void test_ctor() {
    void *obj[3] = {};
    void *ret = func_001820d0(obj, (void *)0xABCD);
    assert(ret == obj);
    assert(obj[0] == 0);
    assert(obj[1] == (void *)0xABCD);
    assert(obj[2] == (void *)0x4D7D70);
}

static void test_dtor() {
    void **obj = (void **)malloc(sizeof(void *) * 3);
    obj[0] = 0; obj[1] = 0; obj[2] = 0;
    func_001820f0(obj, 1);
}

static void test_clear() {
    g_freed = 0;
    MockNode *n2 = (MockNode *)malloc(sizeof(MockNode));
    memset(n2, 0, sizeof(MockNode));
    MockNode *n1 = (MockNode *)malloc(sizeof(MockNode));
    memset(n1, 0, sizeof(MockNode));
    n1->next = n2;

    void *obj[3] = { n1, 0, 0 };
    func_001824a0(obj);
    assert(obj[0] == 0);
    assert(g_freed == 2);
}

static void test_parse_entry() {
    void *obj[3] = { 0, 0, 0 };
    int ret = func_001821f0(obj, (void *)0x999, 1, 0);
    assert(ret == 1);
    assert(obj[0] != 0);
    MockNode *node = (MockNode *)obj[0];
    assert(node->item_ptr == (void *)0x1234);
    free(node);
}

static void test_serialize() {
    g_serialized_bytes = 0;
    MockNode n1 = {};
    n1.mode = 0;
    void *obj[3] = { &n1, 0, 0 };
    func_001823e0(obj, (void *)0x999);
    assert(g_serialized_bytes == 4); // 3 item bytes + 1 terminating zero
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    switch (c) {
        case 0: test_ctor(); break;
        case 1: test_dtor(); break;
        case 2: test_clear(); break;
        case 3: test_parse_entry(); break;
        case 4: test_serialize(); break;
        default: return 1;
    }
    return 0;
}
