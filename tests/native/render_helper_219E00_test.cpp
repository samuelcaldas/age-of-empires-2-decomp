#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>

struct ActionListItem {
    char *text;
    char *extra_text;
    int val_8;
    void *val_c;
    char byte_10;
    char pad_11[3];
    void *val_14;
    void *val_18;
    void *val_1c;
    void *val_20;
    char byte_24;
    char pad_25[3];
    ActionListItem *next;
};
static_assert(offsetof(ActionListItem, val_14) == 0x14, "val_14 at 0x14");
static_assert(offsetof(ActionListItem, val_20) == 0x20, "val_20 at 0x20");
static_assert(offsetof(ActionListItem, byte_24) == 0x24, "byte_24 at 0x24");
static_assert(offsetof(ActionListItem, next) == 0x28, "next at 0x28");

static int method28_calls = 0;
static void *last_method28_self = nullptr;
static int last_method28_arg = -1;

static int c217dd0_calls = 0;
static void *last_217dd0_self = nullptr;
static int last_217dd0_arg1 = -1;
static int last_217dd0_arg2 = -1;
static int last_217dd0_arg3 = -1;

extern "C" {
void func_00219E00(void *self, int arg1);
void func_00219E20(void *self, int index, void *arg2, void *arg3, void *arg4, void *arg5);
int func_00219E90(void *self, int arg1, int arg2);
void func_00219F00(void *self, int arg1);
int func_00219F20(void *self, int index);

void func_00217DD0(void *self, int arg1, int arg2, int arg3) {
    c217dd0_calls++;
    last_217dd0_self = self;
    last_217dd0_arg1 = arg1;
    last_217dd0_arg2 = arg2;
    last_217dd0_arg3 = arg3;
}

static void mock_method_28(void *self, int arg) {
    method28_calls++;
    last_method28_self = self;
    last_method28_arg = arg;
}

static void *vtable[20];
}

static void reset_mocks() {
    method28_calls = 0;
    last_method28_self = nullptr;
    last_method28_arg = -1;

    c217dd0_calls = 0;
    last_217dd0_self = nullptr;
    last_217dd0_arg1 = -1;
    last_217dd0_arg2 = -1;
    last_217dd0_arg3 = -1;

    vtable[0x28 / 4] = (void *)mock_method_28;
    vtable[0x28 / 4 - 2] = (void *)mock_method_28;
}

void test_case_219E00_and_219F00() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;

    func_00219E00(obj, 12345);
    assert(*(int *)(obj + 0x19C) == 12345);
    assert(method28_calls == 1);
    assert(last_method28_self == obj);
    assert(last_method28_arg == 1);

    func_00219F00(obj, 67890);
    assert(*(int *)(obj + 0x1C8) == 67890);
    assert(method28_calls == 2);
}

void test_case_219E20_and_219F20() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;

    ActionListItem node1 = {};
    node1.byte_24 = 42;
    ActionListItem node0 = {};
    node0.byte_24 = 7;
    node0.next = &node1;
    *(ActionListItem **)(obj + 0x11C) = &node0;

    // test func_00219F20
    assert(func_00219F20(obj, 0) == 7);
    assert(func_00219F20(obj, 1) == 42);
    assert(func_00219F20(obj, 5) == 1); // out of bounds defaults to 1

    // test func_00219E20 on node 1
    func_00219E20(obj, 1, (void *)0x14, (void *)0x18, (void *)0x1C, (void *)0x20);
    assert(node1.val_14 == (void *)0x14);
    assert(node1.val_18 == (void *)0x18);
    assert(node1.val_1c == (void *)0x1C);
    assert(node1.val_20 == (void *)0x20);
    assert(node1.byte_10 == 1);
    assert(method28_calls == 1);

    // out of bounds does not call method28
    func_00219E20(obj, 99, nullptr, nullptr, nullptr, nullptr);
    assert(method28_calls == 1);
}

void test_case_219E90_scroll_delta() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    // hi > 0: arg2 = (1 << 16)
    int res1 = func_00219E90(obj, 0, (1 << 16));
    assert(res1 == 1);
    assert(c217dd0_calls == 1);
    assert(last_217dd0_self == obj);
    assert(last_217dd0_arg1 == 3);
    assert(last_217dd0_arg2 == 0);
    assert(last_217dd0_arg3 == 1);

    // hi < 0: arg2 = (-1 << 16)
    int res2 = func_00219E90(obj, 0, (-1 << 16));
    assert(res2 == 1);
    assert(c217dd0_calls == 2);
    assert(last_217dd0_arg1 == 2);
    assert(last_217dd0_arg2 == 0);
    assert(last_217dd0_arg3 == 1);

    // hi == 0: arg2 = 0x000000FF
    int res0 = func_00219E90(obj, 0, 0xFF);
    assert(res0 == 0);
    assert(c217dd0_calls == 2); // unchanged
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_219E00_and_219F00();
    else if (c == 1) test_case_219E20_and_219F20();
    else if (c == 2) test_case_219E90_scroll_delta();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
