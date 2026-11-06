#include "kt_gs_render_229af0.h"

// Stub state for native behavioral testing
static int s_00100850_called = 0;
static int s_00236f50_called = 0;
static int s_0022c1f0_called = 0;
static int s_0022cf90_called = 0;
static int s_0022b2b0_called = 0;
static int s_00227480_called = 0;
static int s_002276d0_called = 0;
static int s_00227830_called = 0;
static int s_00227900_called = 0;

extern "C" {

int func_00100850(int x) {
    s_00100850_called++;
    return 1;
}

int func_00236F50(void* a0, void* a1, void* a2) {
    s_00236f50_called++;
    return 0;
}

int func_0022C1F0(void* a0, void* a1, void* a2) {
    s_0022c1f0_called++;
    return 0;
}

int func_0022CF90(void* a0, void* a1, void* a2, int a3) {
    s_0022cf90_called++;
    return 0;
}

int func_0022B2B0(void* a0, void* a1, void* a2) {
    s_0022b2b0_called++;
    return 0;
}

void func_00227480(void) {
    s_00227480_called++;
}

void func_002276D0(void* a0) {
    s_002276d0_called++;
}

void func_00227830(void* a0) {
    s_00227830_called++;
}

void func_00227900(void* a0, void* a1) {
    s_00227900_called++;
}

void func_00229AF0(void* a0) {
    if (func_00100850(6008)) {
        func_00236F50(a0, (char*)a0 + 5244, (void*)5232);
    }
    if (func_00100850(5232)) {
        func_0022C1F0(a0, (char*)a0 + 68, (void*)7244);
    }
    if (func_00100850(7244)) {
        func_0022CF90(a0, (char*)a0 + 11192, (void*)4024, 1);
    }
    if (func_00100850(4024)) {
        func_0022B2B0(a0, (char*)a0 + 18328, a0);
    }
    func_00227480();
}

int func_00229BC0(void* a0, void* a1, int a2, int a3, void* t0, void* t1) {
    int* p = (int*)a0;
    p[14] = a2;
    p[15] = a3 & 0xFF;
    p[16] = (int)(long)t0;
    return 1;
}

void func_00229C50(void* a0) {
    int* p = (int*)a0;
    p[14] = 0;
    p[15] = -1;
    p[16] = 0;
    func_00227830(a0);
    func_00227900(a0, 0);
}

}
