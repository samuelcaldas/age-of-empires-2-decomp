#include "network_session_dispatch_3378d0.h"

extern int D_004E3530;
extern int D_004E352C;
extern char D_0108AFA0[512];
extern char D_01087ED0[];

extern "C" {
    extern const char D_004D1EE8[];
    extern const char D_004D1EF0[];
    extern const char D_004D1F00[];
    extern const char D_004D1F10[];
    extern const char D_004D1F18[];
    int func_117a64(const char *left, const char *right, int count);
    void func_117af8(void *destination, const void *source, int count);
    int func_003385C0(void *destination, const char *message, int value, int flags);
}

int func_003378D0(const char *message) {
    if (func_117a64(message, D_004D1EE8, 6) == 0) {
        D_004E3530 = 2;
        return 0;
    }
    if (func_117a64(message, D_004D1EF0, 9) == 0 ||
        func_117a64(message, D_004D1F00, 11) == 0) {
        if (D_004E3530 != 1) {
            D_004E3530 = 0;
            D_004E352C = 0;
        }
        return 0;
    }
    if (func_117a64(message, D_004D1F10, 6) == 0 ||
        func_117a64(message, D_004D1F18, 7) == 0) {
        func_117af8(D_0108AFA0, message, 512);
        return 1;
    }
    func_003385C0(D_01087ED0, message, *(const int *)(message + 12), 0);
    return 0;
}
