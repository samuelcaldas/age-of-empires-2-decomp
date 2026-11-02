#include <cassert>
#include <cstdio>

extern "C" {
void* D_4D7780[10] = {0};
void* D_4D77D0[10] = {0};
void* D_4D7898[10] = {0};
void* D_490FA0 = 0;

void* func_100730(unsigned int size) { return NULL; }
void func_00100630(void *ptr) {}
void func_00100670(void *ptr) {}
void func_001452B0(void *self, void *param, int a2, int a3, int a4) {}
void func_00145350(void *self, int a1) {}
int func_00226D90(void *stream, void *buf, int size) { return 0; }
int func_00226F70(void *stream, void *buf, int size) { return 0; }
void* func_332e60(void *container, int id) { return NULL; }
int func_1471A0(void *ptr) { return 0; }
int func_1471C0(void *ptr) { return 0; }
int func_1471D0(void *ptr) { return 0; }
}

#include "../../src/ai/tactical_ai_infantry.cpp"

int main() {
    void *ptr = func_00144FD0();
    assert(ptr == NULL);
    std::printf("tactical_ai_infantry_test passed\n");
    return 0;
}
