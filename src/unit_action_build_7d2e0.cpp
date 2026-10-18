#pragma exceptions off
#include "unit_action_build_7d2e0.h"

extern "C" {
    int func_001C0F90(void *self, int category, int index, char *a, char *b, char *c);
}

int func_0027D2E0(void *self, int action_code) {
    char flag = 0;

    switch (action_code) {
    case 0x17:
        return func_001C0F90(self, 0, 14, &flag, &flag, &flag);

    case 0x74:
        return func_001C0F90(self, 0, 0, &flag, &flag, &flag);

    case 0x73:
        return func_001C0F90(self, 0, 1, &flag, &flag, &flag);

    case 0x1f:
        return func_001C0F90(self, 0, 2, &flag, &flag, &flag);

    case 0x5:
        return func_001C0F90(self, 0, 5, &flag, &flag, &flag);

    case 0x6e:
        return func_001C0F90(self, 0, 7, &flag, &flag, &flag);

    case 0x6f:
        return func_001C0F90(self, 0, 8, &flag, &flag, &flag);

    case 0x7:
    case 0x4e:
        return func_001C0F90(self, 0, 6, &flag, &flag, &flag);

    case 0xc:
    case 0xaa:
    case 0xae:
        return func_001C0F90(self, 3, 27, &flag, &flag, &flag);

    case 0x33:
        return func_001C0F90(self, 0, 13, &flag, &flag, &flag);

    case 0x1c:
        return func_001C0F90(self, 0, 9, &flag, &flag, &flag);

    case 0x1d:
        return func_001C0F90(self, 0, 10, &flag, &flag, &flag);

    case 0x7b:
        return func_001C0F90(self, 0, 11, &flag, &flag, &flag);

    case 0xa7:
    case 0x31:
        return func_001C0F90(self, 0, 12, &flag, &flag, &flag);

    case 0xa1:
        return func_001C0F90(self, 1, 22, &flag, &flag, &flag);

    case 0x32:
        return func_001C0F90(self, 1, 42, &flag, &flag, &flag);

    case 0x28:
        return func_001C0F90(self, 1, 48, &flag, &flag, &flag);

    case 0x29:
        return func_001C0F90(self, 1, 46, &flag, &flag, &flag);

    case 0x2a:
        return func_001C0F90(self, 1, 47, &flag, &flag, &flag);

    case 0xe:
        return func_001C0F90(self, 1, 51, &flag, &flag, &flag);

    case 0x18:
        return func_001C0F90(self, 1, 30, &flag, &flag, &flag);

    case 0xa8:
        return func_001C0F90(self, 1, 53, &flag, &flag, &flag);

    case 0xd:
        return func_001C0F90(self, 1, 54, &flag, &flag, &flag);

    case 0xa:
        return func_001C0F90(self, 12, 0, &flag, &flag, &flag);

    case 0x54:
        return func_001C0F90(self, 12, 1, &flag, &flag, &flag);

    case 0x55:
        return func_001C0F90(self, 12, 2, &flag, &flag, &flag);

    case 0x56:
        return func_001C0F90(self, 12, 3, &flag, &flag, &flag);

    case 0x57:
        return func_001C0F90(self, 12, 4, &flag, &flag, &flag);

    case 0x26:
        return func_001C0F90(self, 12, 5, &flag, &flag, &flag);

    case 0x24:
        return func_001C0F90(self, 12, 6, &flag, &flag, &flag);

    case 0x25:
        return func_001C0F90(self, 12, 7, &flag, &flag, &flag);

    case 0x21:
        return func_001C0F90(self, 12, 8, &flag, &flag, &flag);

    case 0x22:
        return func_001C0F90(self, 12, 9, &flag, &flag, &flag);

    case 0x16:
        return func_001C0F90(self, 12, 10, &flag, &flag, &flag);

    case 0x23:
        return func_001C0F90(self, 12, 11, &flag, &flag, &flag);

    case 0xa3:
        return func_001C0F90(self, 4, 6, &flag, &flag, &flag);

    case 0xab:
        return func_001C0F90(self, 4, 7, &flag, &flag, &flag);

    case 0xac:
        return func_001C0F90(self, 1, 41, &flag, &flag, &flag);

    case 0xaf:
        return func_001C0F90(self, 1, 23, &flag, &flag, &flag);

    case 0xad:
        return func_001C0F90(self, 1, 24, &flag, &flag, &flag);

    default:
        return 0;
    }
}
