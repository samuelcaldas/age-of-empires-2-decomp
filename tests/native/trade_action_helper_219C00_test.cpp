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
static_assert(offsetof(ActionListItem, val_1c) == 0x1C, "val_1c at 0x1C");
static_assert(offsetof(ActionListItem, next) == 0x28, "next at 0x28");

char D_004E32D4 = 'Z';

static int method12C_calls = 0;
static void *last_method12C_self = nullptr;

extern "C" {
int func_00219C00(void *self, int index, void **loc120, void **loc124, void **loc128, void **loc12C, int selector = 0);
const char *func_00219C90(void *self, int index);
int func_00219CD0(void *self);
int func_00219CE0(void *self, int index);
void func_00219D20(void *self);

static void mock_method_12C(void *self) {
    method12C_calls++;
    last_method12C_self = self;
}

static void *vtable[100];
}

static void reset_mocks() {
    D_004E32D4 = 'Z';
    method12C_calls = 0;
    last_method12C_self = nullptr;
    vtable[0x12C / 4] = (void *)mock_method_12C;
}

static ActionListItem *make_full_node(const char *t, const char *et, int id, void *vc, char b10) {
    auto *n = (ActionListItem *)std::calloc(1, sizeof(ActionListItem));
    if (t) n->text = strdup(t);
    if (et) n->extra_text = strdup(et);
    n->val_8 = id;
    n->val_c = vc;
    n->byte_10 = b10;
    n->val_14 = (void *)0x1414;
    n->val_18 = (void *)0x1818;
    n->val_1c = (void *)0x1C1C;
    n->val_20 = (void *)0x2020;
    return n;
}

void test_case_219C00_and_219C90() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));

    ActionListItem *n1 = make_full_node("second", "second_extra", 200, (void *)0x2222, 1);
    ActionListItem *n0 = make_full_node("first", "first_extra", 100, (void *)0x1111, 0);
    n0->next = n1;
    *(ActionListItem **)(obj + 0x11C) = n0;

    void *l120 = nullptr;
    void *l124 = nullptr;
    void *l128 = (void *)0x9999;
    void *l12C = (void *)0x8888;

    // Node 0: byte_10 is 0, so loc128/loc12C untouched
    func_00219C00(obj, 0, &l120, &l124, &l128, &l12C, 0);
    assert(std::strcmp((char *)l120, "first") == 0);
    assert(l124 == (void *)0x1111);
    assert(l128 == (void *)0x9999); // untouched
    assert(l12C == (void *)0x8888); // untouched

    // Node 1 with selector 0: byte_10 is 1, receives val_14 and val_18
    func_00219C00(obj, 1, &l120, &l124, &l128, &l12C, 0);
    assert(std::strcmp((char *)l120, "second") == 0);
    assert(l124 == (void *)0x2222);
    assert(l128 == (void *)0x1414);
    assert(l12C == (void *)0x1818);

    // Node 1 with selector 1: byte_10 is 1, receives val_1c and val_20
    func_00219C00(obj, 1, &l120, &l124, &l128, &l12C, 1);
    assert(l128 == (void *)0x1C1C);
    assert(l12C == (void *)0x2020);

    // func_00219C90
    assert(std::strcmp(func_00219C90(obj, 0), "first_extra") == 0);
    assert(std::strcmp(func_00219C90(obj, 1), "second_extra") == 0);
    const char *empty_res = func_00219C90(obj, 99);
    assert(empty_res == &D_004E32D4);
    assert(D_004E32D4 == '\0');

    std::free(n0->text); std::free(n0->extra_text); std::free(n0);
    std::free(n1->text); std::free(n1->extra_text); std::free(n1);
}

void test_case_219CD0_219CE0_219D20() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(short *)(obj + 0x128) = 1; // current index

    ActionListItem *n1 = make_full_node("n1", nullptr, 555, nullptr, 0);
    ActionListItem *n0 = make_full_node("n0", nullptr, 333, nullptr, 0);
    n0->next = n1;
    *(ActionListItem **)(obj + 0x11C) = n0;

    // func_00219CE0
    assert(func_00219CE0(obj, 0) == 333);
    assert(func_00219CE0(obj, 1) == 555);
    assert(func_00219CE0(obj, 9) == -1);

    // func_00219CD0 (fetches at field 0x128 = 1)
    assert(func_00219CD0(obj) == 555);

    // func_00219D20 calls vtable method 0x12C
    func_00219D20(obj);
    assert(method12C_calls == 1);
    assert(last_method12C_self == obj);

    std::free(n0->text); std::free(n0);
    std::free(n1->text); std::free(n1);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_219C00_and_219C90();
    else if (c == 1) test_case_219CD0_219CE0_219D20();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
