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
static_assert(offsetof(ActionListItem, next) == 0x28, "next must be at 0x28");

static int free_calls = 0;
static void *last_freed_ptrs[10];

static int c217b50_calls = 0;
static void *last_217b50_self = nullptr;
static int last_217b50_arg = -1;

static int method28_calls = 0;
static void *last_method28_self = nullptr;
static int last_method28_arg = -1;

extern "C" {
int func_00219990(void *self, int index);

void func_00116F68(void *ptr) {
    if (free_calls < 10) {
        last_freed_ptrs[free_calls] = ptr;
    }
    free_calls++;
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
    std::memset(last_freed_ptrs, 0, sizeof(last_freed_ptrs));
    c217b50_calls = 0;
    last_217b50_self = nullptr;
    last_217b50_arg = -1;
    method28_calls = 0;
    last_method28_self = nullptr;
    last_method28_arg = -1;
    vtable[0x28 / 4] = (void *)mock_method_28;
}

static ActionListItem *make_node(const char *t, const char *et) {
    auto *n = (ActionListItem *)std::calloc(1, sizeof(ActionListItem));
    if (t) n->text = strdup(t);
    if (et) n->extra_text = strdup(et);
    return n;
}

void test_case_out_of_bounds() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(short *)(obj + 0x120) = 2;

    assert(func_00219990(obj, -1) == 0);
    assert(func_00219990(obj, 2) == 0);
    assert(c217b50_calls == 0);
    assert(method28_calls == 0);
}

void test_case_remove_index_0() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(short *)(obj + 0x120) = 2;
    *(short *)(obj + 0x128) = 1;

    ActionListItem *n1 = make_node("second", nullptr);
    ActionListItem *n0 = make_node("first", "extra");
    n0->next = n1;
    *(ActionListItem **)(obj + 0x11C) = n0;

    int res = func_00219990(obj, 0);
    assert(res == 1);
    assert(c217b50_calls == 1);
    assert(method28_calls == 1);
    assert(*(short *)(obj + 0x120) == 1);
    assert(*(ActionListItem **)(obj + 0x11C) == n1);
    assert(free_calls == 3); // text, extra_text, node

    // cleanup remaining
    func_00219990(obj, 0);
}

void test_case_remove_middle_and_clamp_128() {
    reset_mocks();
    unsigned char obj[0x200];
    std::memset(obj, 0, sizeof(obj));
    *(void ***)obj = vtable;
    *(short *)(obj + 0x120) = 3;
    *(short *)(obj + 0x128) = 2; // last index

    ActionListItem *n2 = make_node("third", nullptr);
    ActionListItem *n1 = make_node("second", nullptr);
    ActionListItem *n0 = make_node("first", nullptr);
    n0->next = n1;
    n1->next = n2;
    *(ActionListItem **)(obj + 0x11C) = n0;

    // Remove index 1 ("second")
    int res = func_00219990(obj, 1);
    assert(res == 1);
    assert(*(short *)(obj + 0x120) == 2);
    assert(n0->next == n2);
    // 0x128 was 2, which is >= new_count (2), so clamped to new_count - 1 = 1
    assert(*(short *)(obj + 0x128) == 1);

    // cleanup
    func_00219990(obj, 0);
    func_00219990(obj, 0);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_out_of_bounds();
    else if (c == 1) test_case_remove_index_0();
    else if (c == 2) test_case_remove_middle_and_clamp_128();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
