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
static_assert(offsetof(ActionListItem, val_8) == 0x8, "val_8 at 0x8");
static_assert(offsetof(ActionListItem, next) == 0x28, "next at 0x28");

char D_004E32D0 = 'X';

static int method128_calls = 0;
static void *last_method128_self = nullptr;
static short last_method128_arg1 = -1;
static void *mock_method128_ret = (void *)0x5555;

extern "C" {
short func_00219AC0(void *self);
int func_00219AF0(void *self, int arg1);
int func_00219B30(void *self, const char *arg1);
void *func_00219BA0(void *self);
const char *func_00219BC0(void *self, int index);

static void *mock_method_128(void *self, short arg1) {
    method128_calls++;
    last_method128_self = self;
    last_method128_arg1 = arg1;
    return mock_method128_ret;
}

static void *vtable[100];
}

static void reset_mocks() {
    D_004E32D0 = 'X';
    method128_calls = 0;
    last_method128_self = nullptr;
    last_method128_arg1 = -1;
    mock_method128_ret = (void *)0x5555;
    vtable[0x128 / 4] = (void *)mock_method_128;
    vtable[0x128 / 4 - 2] = (void *)mock_method_128;
}

static ActionListItem *make_node(const char *t, int id) {
    auto *n = (ActionListItem *)std::calloc(1, sizeof(ActionListItem));
    if (t) n->text = strdup(t);
    n->val_8 = id;
    return n;
}

void test_case_219AC0_get_current_index() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    *(short *)(obj + 0x120) = 0;
    *(short *)(obj + 0x128) = 5;
    assert(func_00219AC0(obj) == -1);

    *(short *)(obj + 0x120) = 3;
    *(short *)(obj + 0x128) = 2;
    assert(func_00219AC0(obj) == 2);
}

void test_case_219AF0_find_by_id() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    ActionListItem *n2 = make_node("node2", 300);
    ActionListItem *n1 = make_node("node1", 200);
    ActionListItem *n0 = make_node("node0", 100);
    n0->next = n1;
    n1->next = n2;
    *(ActionListItem **)(obj + 0x11C) = n0;

    assert(func_00219AF0(obj, 100) == 0);
    assert(func_00219AF0(obj, 200) == 1);
    assert(func_00219AF0(obj, 300) == 2);
    assert(func_00219AF0(obj, 999) == -1);

    std::free(n0->text); std::free(n0);
    std::free(n1->text); std::free(n1);
    std::free(n2->text); std::free(n2);
}

void test_case_219B30_find_by_string() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    ActionListItem *n1 = make_node("banana", 2);
    ActionListItem *n0 = make_node("apple", 1);
    n0->next = n1;
    *(ActionListItem **)(obj + 0x11C) = n0;

    assert(func_00219B30(obj, "apple") == 0);
    assert(func_00219B30(obj, "banana") == 1);
    assert(func_00219B30(obj, "orange") == -1);

    std::free(n0->text); std::free(n0);
    std::free(n1->text); std::free(n1);
}

void test_case_219BA0_and_219BC0() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(short *)(obj + 0x128) = 7;

    // 219BA0: calls vtable method 0x128 with field 0x128
    void *res = func_00219BA0(obj);
    assert(res == (void *)0x5555);
    assert(method128_calls == 1);
    assert(last_method128_self == obj);
    assert(last_method128_arg1 == 7);

    // 219BC0: get string at index or empty string
    ActionListItem *n1 = make_node("second_item", 20);
    ActionListItem *n0 = make_node("first_item", 10);
    n0->next = n1;
    *(ActionListItem **)(obj + 0x11C) = n0;

    assert(std::strcmp(func_00219BC0(obj, 0), "first_item") == 0);
    assert(std::strcmp(func_00219BC0(obj, 1), "second_item") == 0);

    const char *empty_res = func_00219BC0(obj, 99);
    assert(empty_res == &D_004E32D0);
    assert(D_004E32D0 == '\0');
    assert(std::strlen(empty_res) == 0);

    std::free(n0->text); std::free(n0);
    std::free(n1->text); std::free(n1);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_219AC0_get_current_index();
    else if (c == 1) test_case_219AF0_find_by_id();
    else if (c == 2) test_case_219B30_find_by_string();
    else if (c == 3) test_case_219BA0_and_219BC0();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
