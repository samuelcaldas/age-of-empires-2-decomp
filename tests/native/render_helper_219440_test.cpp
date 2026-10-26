#include <cassert>
#include <cstring>
#include <iostream>

static int c217b50_calls = 0;
static void *last_217b50_self = nullptr;
static int last_217b50_arg1 = -1;

extern "C" {
void func_00219440(void *self, const char *arg1);

void func_00217B50(void *self, int arg1) {
    c217b50_calls++;
    last_217b50_self = self;
    last_217b50_arg1 = arg1;
}
}

struct MockNode {
    const char *str;
    char pad[0x20];
    MockNode *next; // at offset 0x28 (0x4 + 0x20 = 0x24 in 32-bit? wait!)
};

// In 32-bit MIPS:
// offset 0: pointer str (4 bytes)
// offset 0x28: pointer next (4 bytes)
// So padding between 0x4 and 0x28 is 0x24 (36) bytes!
struct AlignedNode {
    const char *str;
    char pad[0x24];
    AlignedNode *next;
};
static_assert(offsetof(AlignedNode, next) == 0x28, "next must be at offset 0x28");

static void reset_mocks() {
    c217b50_calls = 0;
    last_217b50_self = nullptr;
    last_217b50_arg1 = -1;
}

void test_case_empty_list() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(short *)(obj + 0x128) = 77;
    *(void **)(obj + 0x11C) = nullptr;

    func_00219440(obj, "target");
    assert(*(short *)(obj + 0x128) == 77);
    assert(c217b50_calls == 1);
    assert(last_217b50_self == obj);
    assert(last_217b50_arg1 == 1);
}

void test_case_match_at_index_2() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(short *)(obj + 0x128) = 99;

    AlignedNode node2 = {"third", {}, nullptr};
    AlignedNode node1 = {"second", {}, &node2};
    AlignedNode node0 = {"first", {}, &node1};

    *(void **)(obj + 0x11C) = &node0;

    func_00219440(obj, "third");
    assert(*(short *)(obj + 0x128) == 2);
    assert(c217b50_calls == 1);
    assert(last_217b50_self == obj);
    assert(last_217b50_arg1 == 1);
}

void test_case_no_match() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(short *)(obj + 0x128) = 45;

    AlignedNode node1 = {"second", {}, nullptr};
    AlignedNode node0 = {"first", {}, &node1};

    *(void **)(obj + 0x11C) = &node0;

    func_00219440(obj, "nonexistent");
    assert(*(short *)(obj + 0x128) == 45);
    assert(c217b50_calls == 1);
    assert(last_217b50_self == obj);
    assert(last_217b50_arg1 == 1);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_empty_list();
    else if (c == 1) test_case_match_at_index_2();
    else if (c == 2) test_case_no_match();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
