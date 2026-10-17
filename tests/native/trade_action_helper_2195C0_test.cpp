#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>

struct ActionListItem {
    char *text;
    char *extra_text;
    int val_8;
    int val_c;
    char byte_10;
    char pad_11[0x13];
    char byte_24;
    char pad_25[3];
    ActionListItem *next;
};
static_assert(offsetof(ActionListItem, text) == 0x0, "text at 0x0");
static_assert(offsetof(ActionListItem, extra_text) == 0x4, "extra_text at 0x4");
static_assert(offsetof(ActionListItem, val_8) == 0x8, "val_8 at 0x8");
static_assert(offsetof(ActionListItem, val_c) == 0xC, "val_c at 0xC");
static_assert(offsetof(ActionListItem, byte_10) == 0x10, "byte_10 at 0x10");
static_assert(offsetof(ActionListItem, byte_24) == 0x24, "byte_24 at 0x24");
static_assert(offsetof(ActionListItem, next) == 0x28, "next at 0x28");
static_assert(sizeof(ActionListItem) == 0x2C, "ActionListItem size 0x2C");

static int c217b50_calls = 0;
static void *last_217b50_self = nullptr;
static int last_217b50_arg = -1;

static int method28_calls = 0;
static void *last_method28_self = nullptr;
static int last_method28_arg = -1;

extern "C" {
int func_002195C0(void *self, int insert_pos, const char *str_s4, const char *str_s3, int val_s2, int val_s1);

void *func_001143F8(int n, int size) {
    return std::calloc(n, size);
}

void func_00116F68(void *ptr) {
    std::free(ptr);
}

int func_0011ACD0(const char *str) {
    return (int)std::strlen(str);
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
    c217b50_calls = 0;
    last_217b50_self = nullptr;
    last_217b50_arg = -1;
    method28_calls = 0;
    last_method28_self = nullptr;
    last_method28_arg = -1;
    vtable[0x28 / 4] = (void *)mock_method_28;
}

void test_case_first_node_empty_list() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(short *)(obj + 0x120) = 0;
    *(void **)(obj + 0x11C) = nullptr;

    int res = func_002195C0(obj, 0, "hello", "extra", 123, 456);
    assert(res == 1);
    assert(c217b50_calls == 1);
    assert(method28_calls == 1);
    assert(*(short *)(obj + 0x120) == 1);

    ActionListItem *head = *(ActionListItem **)(obj + 0x11C);
    assert(head != nullptr);
    assert(std::strcmp(head->text, "hello") == 0);
    assert(std::strcmp(head->extra_text, "extra") == 0);
    assert(head->val_8 == 123);
    assert(head->val_c == 456);
    assert(head->next == nullptr);
}

void test_case_sorted_insertion() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(int *)(obj + 0x198) = 1; // sorted flag
    *(short *)(obj + 0x120) = 0;
    *(void **)(obj + 0x11C) = nullptr;

    func_002195C0(obj, 0, "beta", nullptr, 1, 1);
    func_002195C0(obj, 0, "alpha", nullptr, 2, 2);
    func_002195C0(obj, 0, "gamma", nullptr, 3, 3);

    assert(*(short *)(obj + 0x120) == 3);
    ActionListItem *n0 = *(ActionListItem **)(obj + 0x11C);
    assert(std::strcmp(n0->text, "alpha") == 0);
    ActionListItem *n1 = n0->next;
    assert(std::strcmp(n1->text, "beta") == 0);
    ActionListItem *n2 = n1->next;
    assert(std::strcmp(n2->text, "gamma") == 0);
    assert(n2->next == nullptr);
}

void test_case_index_insertion() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(int *)(obj + 0x198) = 0; // index mode
    *(short *)(obj + 0x120) = 0;
    *(void **)(obj + 0x11C) = nullptr;

    func_002195C0(obj, 0, "first", nullptr, 1, 1);
    func_002195C0(obj, 1, "second", nullptr, 2, 2);
    func_002195C0(obj, 1, "inserted_between", nullptr, 3, 3);

    assert(*(short *)(obj + 0x120) == 3);
    ActionListItem *n0 = *(ActionListItem **)(obj + 0x11C);
    assert(std::strcmp(n0->text, "first") == 0);
    ActionListItem *n1 = n0->next;
    assert(std::strcmp(n1->text, "inserted_between") == 0);
    ActionListItem *n2 = n1->next;
    assert(std::strcmp(n2->text, "second") == 0);
    assert(n2->next == nullptr);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_first_node_empty_list();
    else if (c == 1) test_case_sorted_insertion();
    else if (c == 2) test_case_index_insertion();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
