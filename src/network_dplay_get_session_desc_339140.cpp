#include "network_dplay_3380e0.h"

extern "C" {
    void func_117AF8(void *dst, const void *src, int size);
}

extern "C" int func_00339140(void *self, void *desc, unsigned int *size_ptr) {
    char *out = static_cast<char *>(desc);
    char *base = static_cast<char *>(self);
    if (!desc) {
        *size_ptr = 80;
        return 0;
    }
    if (*size_ptr < 80u) {
        return static_cast<int>(0x8877001Eu);
    }
    if (!size_ptr) {
        return static_cast<int>(0x80070057u);
    }
    func_117AF8(out, base + 1092, 80);
    *reinterpret_cast<char **>(out + 48) = base + 1172;
    *reinterpret_cast<char **>(out + 52) = base + 1300;
    return 0;
}
