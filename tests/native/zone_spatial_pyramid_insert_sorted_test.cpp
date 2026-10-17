#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D42A0(void *self, void *list_head, void *node, int flag);
}

struct Node {
    char pad[0x18];
    float val;
    char pad2[4];
    void *next; // at offset 0x20
};

static void test_insert_sorted_flag1_push_front() {
    char head[0x30];
    std::memset(head, 0, sizeof(head));

    Node n1;
    std::memset(&n1, 0, sizeof(n1));
    n1.val = 5.0f;

    func_001D42A0(nullptr, head, &n1, 1);
    assert(*reinterpret_cast<void **>(head + 0x20) == &n1);
}

static void test_insert_sorted_ordered() {
    char head[0x30];
    std::memset(head, 0, sizeof(head));

    Node n1, n2, n3;
    std::memset(&n1, 0, sizeof(n1));
    std::memset(&n2, 0, sizeof(n2));
    std::memset(&n3, 0, sizeof(n3));

    n1.val = 10.0f;
    n2.val = 5.0f;
    n3.val = 20.0f;

    func_001D42A0(nullptr, head, &n1, 0);
    func_001D42A0(nullptr, head, &n2, 0);
    func_001D42A0(nullptr, head, &n3, 0);

    // List should be sorted: n2 (5.0) -> n1 (10.0) -> n3 (20.0)
    Node *first = *reinterpret_cast<Node **>(head + 0x20);
    assert(first == &n2);
    Node *second = reinterpret_cast<Node *>(first->next);
    assert(second == &n1);
    Node *third = reinterpret_cast<Node *>(second->next);
    assert(third == &n3);
    assert(third->next == nullptr);
}

int main(int argc, char **argv) {
    test_insert_sorted_flag1_push_front();
    test_insert_sorted_ordered();
    return 0;
}
