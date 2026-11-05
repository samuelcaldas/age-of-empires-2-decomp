#include <cstdint>
#include <cassert>
#include <cstring>
#include <iostream>

// Structures inferred from assembly
struct Node {
    int32_t val0;      // offset 0
    int32_t val4;      // offset 4
    float fval8;       // offset 8
    float fval12;      // offset 12 (or priority/sort key)
    Node* next;        // offset 16
    Node* prev;        // offset 20
};

extern "C" {
    void func_002279E0(void* ctx, Node* node);
    void func_00227A00(void* ctx, Node* node);
    void func_00227BE0(void* ctx, Node* node);
}

int main() {
    Node node;
    std::memset(&node, 0x55, sizeof(node));

    func_002279E0(nullptr, &node);
    assert(node.val0 == -1);
    assert(node.val4 == -1);
    assert(node.fval8 == 0.0f);
    assert(node.fval12 == 0.0f);
    assert(node.next == nullptr);
    assert(node.prev == nullptr);

    Node n1, n2;
    std::memset(&n1, 0, sizeof(n1));
    std::memset(&n2, 0, sizeof(n2));
    n1.next = &n2;
    n2.prev = &n1;

    func_00227BE0(nullptr, &n1);
    assert(n1.next == nullptr);
    assert(n1.prev == nullptr);
    assert(n2.prev == nullptr);

    std::cout << "All kt_gs_render_2279e0 behavioral tests passed!" << std::endl;
    return 0;
}
