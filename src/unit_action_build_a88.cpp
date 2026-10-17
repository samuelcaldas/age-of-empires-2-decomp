#pragma exceptions off
#include "unit_action_build_a88.h"

static bool is_resource_94(short type) {
    return (type == 2 || type == 4 || type == 19 || type == 20 || type == 21);
}

static bool is_resource_a0(short type) {
    switch (type) {
        case 0:
        case 6:
        case 12:
        case 13:
        case 22:
        case 23:
        case 24:
        case 26:
        case 28:
        case 35:
        case 36:
        case 44:
        case 45:
        case 46:
        case 47:
        case 50:
        case 51:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
            return true;
        default:
            return false;
    }
}

void func_00272A88(void *self, float amount) {
#if defined(__LP64__) || defined(_LP64)
    void *proto = *(void **)((char *)self + 0x8);
    void *owner = *(void **)((char *)self + 0x10);
#else
    void *proto = *(void **)((char *)self + 0x4);
    void *owner = *(void **)((char *)self + 0x8);
#endif
    short type = *(short *)((char *)proto + 0xE);
    void *stats = *(void **)((char *)owner + 0xBAC);

    if (is_resource_94(type)) {
        *(float *)((char *)stats + 0x94) += amount;
        return;
    }
    if (is_resource_a0(type)) {
        *(float *)((char *)stats + 0xA0) += amount;
        return;
    }
}
