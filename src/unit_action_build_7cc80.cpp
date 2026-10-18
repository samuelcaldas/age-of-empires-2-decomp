#pragma exceptions off
#include "unit_action_build_7cc80.h"

extern "C" {
    int func_001C0F90(void *self, int category, int index, char *a, char *b, char *c);
}

int func_0027CC80(void *self, int action_code) {
    char flag = 0;

    switch (action_code) {
    case 0x3f00:
    case 0x3f01:
    case 0x3f02:
        return func_001C0F90(self, 3, 13, &flag, &flag, &flag);

    case 0x3f03:
    case 0x3f04:
    case 0x3f05:
    case 0x3f06:
        return func_001C0F90(self, 3, 2, &flag, &flag, &flag);

    case 0x3f07:
    case 0x3f08:
    case 0x3f09:
        return func_001C0F90(self, 3, 4, &flag, &flag, &flag);

    case 0x3f0a:
    case 0x3f0b:
    case 0x3f0c:
    case 0x3f0d:
        return func_001C0F90(self, 3, 15, &flag, &flag, &flag);

    case 0x3f0e:
    case 0x3f0f:
        return func_001C0F90(self, 3, 20, &flag, &flag, &flag);

    case 0x3f10:
    case 0x3f11:
    case 0x3f12:
    case 0x3f13:
    case 0x3f14:
        return func_001C0F90(self, 3, 3, &flag, &flag, &flag);

    case 0x3f15:
        return func_001C0F90(self, 3, 12, &flag, &flag, &flag);

    case 0x3f32:
    case 0x3f1a:
    case 0x3f1b:
        return func_001C0F90(self, 3, 8, &flag, &flag, &flag);

    case 0x3f1c:
        return func_001C0F90(self, 3, 9, &flag, &flag, &flag);

    case 0x3f1d:
    case 0x3f1e:
    case 0x3f1f:
    case 0x3f20:
        return func_001C0F90(self, 3, 1, &flag, &flag, &flag);

    case 0x3f21:
    case 0x3f22:
    case 0x3f23:
        return func_001C0F90(self, 3, 6, &flag, &flag, &flag);

    case 0x3f24:
    case 0x3f25:
    case 0x3f26:
    case 0x3f27:
    case 0x3f28:
        return func_001C0F90(self, 3, 16, &flag, &flag, &flag);

    case 0x3f29:
    case 0x3f2a:
        return func_001C0F90(self, 3, 17, &flag, &flag, &flag);

    case 0x3f2b:
    case 0x3f2c:
    case 0x3f2d:
        return func_001C0F90(self, 3, 14, &flag, &flag, &flag);

    case 0x3f2e:
    case 0x3f2f:
        return func_001C0F90(self, 3, 21, &flag, &flag, &flag);

    case 0x3f30:
    case 0x3f31:
        return func_001C0F90(self, 3, 18, &flag, &flag, &flag);

    case 0x3f36:
        return func_001C0F90(self, 3, 19, &flag, &flag, &flag);

    case 0x401d:
    case 0x3f37:
    case 0x3f38:
    case 0x3f39:
        return func_001C0F90(self, 3, 10, &flag, &flag, &flag);

    case 0x3f4a:
        return func_001C0F90(self, 3, 5, &flag, &flag, &flag);

    case 0x3f4b:
    case 0x3f4c:
        return func_001C0F90(self, 3, 7, &flag, &flag, &flag);

    case 0x3fb7:
        return func_001C0F90(self, 3, 22, &flag, &flag, &flag);

    case 0x3fd8:
    case 0x3fd9:
    case 0x3fda:
    case 0x3fdb:
        return func_001C0F90(self, 3, 0, &flag, &flag, &flag);

    case 0x4050:
        return func_001C0F90(self, 3, 23, &flag, &flag, &flag);

    case 0x4067:
        return func_001C0F90(self, 3, 24, &flag, &flag, &flag);

    case 0x406f:
        return func_001C0F90(self, 3, 25, &flag, &flag, &flag);

    case 0x4078:
        return func_001C0F90(self, 3, 26, &flag, &flag, &flag);

    default:
        return 0;
    }
}
