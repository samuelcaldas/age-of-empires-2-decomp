#include <cassert>
#include <cstddef>
#include <cstring>
#include <iostream>

static int c219430_calls = 0;
static void *last_219430_self = nullptr;
static short last_219430_arg1 = -1;

extern "C" {
int func_002194D0(void *self, int arg1);

void func_00219430(void *self, short arg1) {
    c219430_calls++;
    last_219430_self = self;
    last_219430_arg1 = arg1;
}
}

struct TestNode {
    char pad0[8];
    int id;
    char pad1[0x1C];
    TestNode *next;
};
static_assert(offsetof(TestNode, id) == 0x8, "id must be at offset 0x8");
static_assert(offsetof(TestNode, next) == 0x28, "next must be at offset 0x28");

static void reset_mocks() {
    c219430_calls = 0;
    last_219430_self = nullptr;
    last_219430_arg1 = -1;
}

void test_case_empty_list() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void **)(obj + 0x11C) = nullptr;

    int res = func_002194D0(obj, 42);
    assert(res == -1);
    assert(c219430_calls == 0);
}

void test_case_match_at_index_0() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    TestNode node0 = {{}, 42, {}, nullptr};
    *(void **)(obj + 0x11C) = &node0;

    int res = func_002194D0(obj, 42);
    assert(res == 0);
    assert(c219430_calls == 1);
    assert(last_219430_self == obj);
    assert(last_219430_arg1 == 0);
}

void test_case_match_at_index_2() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    TestNode node2 = {{}, 999, {}, nullptr};
    TestNode node1 = {{}, 200, {}, &node2};
    TestNode node0 = {{}, 100, {}, &node1};
    *(void **)(obj + 0x11C) = &node0;

    int res = func_002194D0(obj, 999);
    assert(res == 2);
    assert(c219430_calls == 1);
    assert(last_219430_self == obj);
    assert(last_219430_arg1 == 2);
}

void test_case_no_match() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    TestNode node1 = {{}, 200, {}, nullptr};
    TestNode node0 = {{}, 100, {}, &node1};
    *(void **)(obj + 0x11C) = &node0;

    int res = func_002194D0(obj, 555);
    assert(res == -1);
    assert(c219430_calls == 0);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_empty_list();
    else if (c == 1) test_case_match_at_index_0();
    else if (c == 2) test_case_match_at_index_2();
    else if (c == 3) test_case_no_match();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
