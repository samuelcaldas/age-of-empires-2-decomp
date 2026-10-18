#pragma exceptions off
#include "unit_action_build_7a830.h"

extern "C" {
    int func_226D90(void *stream, const void *src, unsigned long size);
}

#if defined(__LP64__) || defined(_LP64)
#define LIST_HEAD_OFFSET 0x1E0
#define NODE_NEXT_OFFSET 0x20
#else
#define LIST_HEAD_OFFSET 0x1E0
#define NODE_NEXT_OFFSET 0x18
#endif

static void write_header_fields(void *self, void *stream) {
    char dummy = 0;
    func_226D90(stream, &dummy, 1);
    func_226D90(stream, (char *)self + 0x5DC, 4);
    func_226D90(stream, (char *)self + 0x5D8, 4);
    func_226D90(stream, (char *)self + 0x5E0, 4);
    func_226D90(stream, (char *)self + 0x5E4, 4);
    func_226D90(stream, &dummy, 1);
}

static int count_nodes(void *self) {
    int count = 0;
    void *current = *(void **)((char *)self + LIST_HEAD_OFFSET);
    while (current != 0) {
        count++;
        current = *(void **)((char *)current + NODE_NEXT_OFFSET);
    }
    return count;
}

static void write_node_entries(void *self, void *stream) {
    int count = count_nodes(self);
    func_226D90(stream, &count, 4);
    void *current = *(void **)((char *)self + LIST_HEAD_OFFSET);
    while (current != 0) {
        func_226D90(stream, (char *)current + 0x0, 1);
        func_226D90(stream, (char *)current + 0x4, 4);
        func_226D90(stream, (char *)current + 0xC, 4);
        func_226D90(stream, (char *)current + 0x10, 4);
        func_226D90(stream, (char *)current + 0x14, 4);
        func_226D90(stream, (char *)current + 0x8, 4);
        current = *(void **)((char *)current + NODE_NEXT_OFFSET);
    }
}

static void write_scalar_properties(void *self, void *stream) {
    for (int offset = 0x5EC; offset <= 0x628; offset += 4) {
        func_226D90(stream, (char *)self + offset, 4);
    }
}

static void write_array_properties(void *self, void *stream) {
    for (int i = 0; i < 8; ++i) {
        func_226D90(stream, (char *)self + 0x62C + (i * 2), 2);
    }
    for (int i = 0; i < 8; ++i) {
        func_226D90(stream, (char *)self + 0x63C + (i * 4), 4);
    }
    for (int i = 0; i < 8; ++i) {
        func_226D90(stream, (char *)self + 0x65C + (i * 2), 2);
    }
    for (int i = 0; i < 8; ++i) {
        func_226D90(stream, (char *)self + 0x66C + (i * 4), 4);
    }
}

static void write_trailing_fields(void *self, void *stream) {
    func_226D90(stream, (char *)self + 0x68C, 4);
    func_226D90(stream, (char *)self + 0x690, 4);
    func_226D90(stream, (char *)self + 0x694, 4);
    func_226D90(stream, (char *)self + 0x698, 2);
    func_226D90(stream, (char *)self + 0x69A, 2);
    char dummy = 0;
    func_226D90(stream, &dummy, 1);
}

void func_0027A830(void *self, void *stream) {
    write_header_fields(self, stream);
    write_node_entries(self, stream);
    write_scalar_properties(self, stream);
    write_array_properties(self, stream);
    write_trailing_fields(self, stream);
}
