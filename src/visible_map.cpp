#include "visible_map.h"
#include <cstring>

int D_004E3058 = 0;
int *D_50A5A0[200];

extern "C" {
    void __vec_ctor(void *ptr) { (void)ptr; }
    void *memset(void *dst, int val, int size);
    void *memcpy(void *dst, const void *src, int size);
    void func_226d90(void *stream, void *dst, int size) {
        memcpy(dst, stream, size);
    }
    void func_226f70(void *stream, void *src, int size) {
        memcpy(stream, src, size);
    }
}

void* func_00138760(void *self) {
    return self;
}

void* func_00138770(void *self, int flag) {
    if (self) {
        if ((short)flag > 0) {
            __vec_ctor(self);
        }
    }
    return self;
}

void func_001387C0(VisibleMap *self, int width, int height) {
    self->m_width = width;
    self->m_height = height;
    D_004E3058 = 0;
    if (self->m_height > 0 && self->m_width > 0) {
        self->m_buffer = (int*)memset(self->m_staticBuf, 0, sizeof(self->m_staticBuf));
    } else {
        self->m_buffer = 0;
        self->m_width = 0;
        self->m_height = 0;
    }
    func_00138960(self);
}

void func_00138830(VisibleMap *self, void *stream) {
    func_226d90(stream, &self->m_width, 4);
    func_226d90(stream, &self->m_height, 4);
    if (self->m_height > 0 && self->m_width > 0) {
        self->m_buffer = (int*)memset(self->m_staticBuf, 0, sizeof(self->m_staticBuf));
        func_226d90(stream, self->m_buffer, self->m_height * self->m_width * 4);
        return;
    }
    self->m_buffer = 0;
    self->m_height = 0;
    self->m_width = 0;
}

void func_001388E0(VisibleMap *self, void *stream) {
    func_226f70(stream, &self->m_width, 4);
    func_226f70(stream, &self->m_height, 4);
    if (self->m_height > 0 && self->m_width > 0) {
        func_226f70(stream, self->m_buffer, self->m_height * self->m_width * 4);
    }
}

void func_00138960(VisibleMap *self) {
    for (int y = 0; y < self->m_height; y++) {
        D_50A5A0[y] = self->m_buffer + y * self->m_width;
    }
    for (int y = self->m_height; y < 200; y++) {
        D_50A5A0[y] = 0;
    }
}

void func_001389E0(void *self, int val) {
    (void)self;
    D_004E3058 = val;
}

void func_001389F0(VisibleMap *self) {
    self->m_height = 0;
    func_00138960(self);
    if (self->m_buffer) {
        memset(self->m_staticBuf, 0, sizeof(self->m_staticBuf));
        self->m_buffer = 0;
    }
}
