#include <cstdint>
#include <cstring>

struct Node {
    int32_t val0;
    int32_t val4;
    float fval8;
    float fval12;
    Node* next;
    Node* prev;
};

extern "C" {

void func_002279E0(void* a0, Node* a1) {
    a1->val0 = -1;
    a1->val4 = -1;
    a1->next = nullptr;
    a1->prev = nullptr;
    a1->fval8 = 0.0f;
    a1->fval12 = 0.0f;
}

void func_00227A00(void* a0, Node* a1) {
    if (a1->next != nullptr) {
        a1->next->prev = nullptr;
        a1->next = nullptr;
    }
}

void func_00227BE0(void* a0, Node* a1) {
    if (a1->prev != nullptr) {
        a1->prev->next = a1->next;
    }
    if (a1->next != nullptr) {
        a1->next->prev = a1->prev;
    }
    a1->next = nullptr;
    a1->prev = nullptr;
}

}
