#ifndef RENDER_MANAGER_PALETTE_TABLE_TEST_SUPPORT_H
#define RENDER_MANAGER_PALETTE_TABLE_TEST_SUPPORT_H

#include "render_manager_palette_table.h"
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <stdint.h>

struct MockStream {
    int data[9];
    int read_pos;
};

static inline void init_mock_stream(MockStream *stream, int f0) {
    stream->read_pos = 0;
    stream->data[0] = f0;
    for (int i = 1; i < 9; i++) {
        stream->data[i] = i * 100;
    }
}

extern "C" {
int func_226D90(void *stream, void *dst, int size) {
    MockStream *s = static_cast<MockStream *>(stream);
    if (s && s->read_pos < 9 && size == 4) {
        std::memcpy(dst, &s->data[s->read_pos++], 4);
        return 4;
    }
    return 0;
}

void *func_100730(int size) {
    return std::malloc(size);
}

void func_100630(void *ptr) {
    std::free(ptr);
}

void func_100670(void *ptr) {
    std::free(ptr);
}

int func_21BC30(const void *arg0, void *buf, int arg2, int capacity, int arg4) {
    (void)arg0; (void)buf; (void)arg2; (void)capacity; (void)arg4;
    return 0;
}

void *func_117AF8(void *dst, const void *src, int len) {
    if (reinterpret_cast<uintptr_t>(src) == 0x01ED7000) {
        return std::memset(dst, 0x42, len);
    }
    return std::memcpy(dst, src, len);
}

void func_1AE350(SubObj6C *sub, void *dest_palette) {
    unsigned char *d = static_cast<unsigned char *>(dest_palette);
    if (sub) {
        for (int i = 0; i < 256; i++) {
            d[i * 4 + 0] = static_cast<unsigned char>(sub->field_5C[i]);
            d[i * 4 + 1] = static_cast<unsigned char>(sub->field_5C[i]);
            d[i * 4 + 2] = static_cast<unsigned char>(sub->field_5C[i]);
            d[i * 4 + 3] = 0xFF;
        }
    }
}

extern const unsigned char D_003921F4[256] = {};
}

#endif
