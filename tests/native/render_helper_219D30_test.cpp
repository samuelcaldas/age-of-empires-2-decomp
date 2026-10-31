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
static_assert(offsetof(ActionListItem, val_c) == 0xC, "val_c at 0xC");
static_assert(offsetof(ActionListItem, next) == 0x28, "next at 0x28");

struct SubItem {
    char pad0[8];
    SubItem *next; // offset 8
};
static_assert(offsetof(SubItem, next) == 0x8, "next at 0x8");

static int free_calls = 0;
static int func_100670_calls = 0;
static int c217b50_calls = 0;
static void *last_217b50_self = nullptr;
static int last_217b50_arg = -1;

static int method28_calls = 0;
static void *last_method28_self = nullptr;
static int last_method28_arg = -1;

extern "C" {
void func_00219D30(void *self);

void func_00116F68(void *ptr) {
    free_calls++;
    std::free(ptr);
}

void func_116F68(void *ptr) {
    func_00116F68(ptr);
}

void func_100670(void *ptr) {
    func_100670_calls++;
    std::free(ptr);
}

void func_00217B50(void *self, int arg1) {
    c217b50_calls++;
    last_217b50_self = self;
    last_217b50_arg = arg1;
}

static void mock_method_28(void *self, int arg) {
    method28_calls++;
    last_method28_self = self;
    last_method28_arg = arg;
}

static void *vtable[20];
}

static void reset_mocks() {
    free_calls = 0;
    func_100670_calls = 0;
    c217b50_calls = 0;
    last_217b50_self = nullptr;
    last_217b50_arg = -1;
    method28_calls = 0;
    last_method28_self = nullptr;
    last_method28_arg = -1;
    vtable[8] = (void *)mock_method_28;
    vtable[0x28 / 4] = (void *)mock_method_28;
}

void test_case_empty_list_clear() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(void **)(obj + 0x11C) = nullptr;
    *(short *)(obj + 0x120) = 5;

    func_00219D30(obj);
    assert(free_calls == 0);
    assert(func_100670_calls == 0);
    assert(*(short *)(obj + 0x120) == 0);
    assert(*(void **)(obj + 0x11C) == nullptr);
    assert(c217b50_calls == 1);
    assert(method28_calls == 1);
}

void test_case_list_with_subitems_clear() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(short *)(obj + 0x120) = 2;

    // Sub items for node 0
    auto *sub1 = (SubItem *)std::calloc(1, sizeof(SubItem));
    auto *sub0 = (SubItem *)std::calloc(1, sizeof(SubItem));
    sub0->next = sub1;

    // Node 1
    auto *n1 = (ActionListItem *)std::calloc(1, sizeof(ActionListItem));
    n1->text = strdup("n1");

    // Node 0
    auto *n0 = (ActionListItem *)std::calloc(1, sizeof(ActionListItem));
    n0->text = strdup("n0");
    n0->extra_text = strdup("n0_extra");
    n0->val_c = sub0;
    n0->next = n1;

    *(ActionListItem **)(obj + 0x11C) = n0;

    func_00219D30(obj);

    // sub0 and sub1 freed via 100670
    assert(func_100670_calls == 2);
    // n0->text, n0->extra_text, n0, n1->text, n1 freed via 116F68 = 5 frees
    assert(free_calls == 5);

    assert(*(void **)(obj + 0x11C) == nullptr);
    assert(*(short *)(obj + 0x120) == 0);
    assert(c217b50_calls == 1);
    assert(last_217b50_self == obj);
    assert(last_217b50_arg == 1);
    assert(method28_calls == 1);
    assert(last_method28_self == obj);
    assert(last_method28_arg == 1);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_empty_list_clear();
    else if (c == 1) test_case_list_with_subitems_clear();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
