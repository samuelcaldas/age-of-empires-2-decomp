#pragma exceptions off
#include <cstring>
#include "unit_action_build_7a390.h"

extern "C" {
    void *func_117CAC(void *dest, int val, size_t size);
    void func_100670(void *ptr);
}

#if defined(__LP64__) || defined(_LP64)
#define LIST_HEAD_OFFSET 0x1E0
#define NODE_NEXT_OFFSET 0x20
#else
#define LIST_HEAD_OFFSET 0x1E0
#define NODE_NEXT_OFFSET 0x18
#endif

static void clear_node_list(void *self) {
    void *current = *(void **)((char *)self + LIST_HEAD_OFFSET);
    while (current != 0) {
        void *next = *(void **)((char *)current + NODE_NEXT_OFFSET);
        func_117CAC(current, 0, 0x1C);
        *(void **)((char *)self + LIST_HEAD_OFFSET) = next;
        current = next;
    }
}

void *func_0027A390(void *self, int deallocate_flag) {
    if (self == 0) return 0;
    func_117CAC(self, 0, 0x1E0);
    clear_node_list(self);
    if (deallocate_flag > 0) {
        func_100670(self);
    }
    return self;
}
