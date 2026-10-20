#pragma exceptions off
#include "unit_action_build_7da10.h"

extern "C" {
    int func_001C0F90(void *self, int category, int index, char *a, char *b, char *c);
}

int func_0027DA10(void *self, int action_code) {
    char flag = 0;

    switch (action_code) {
    case 0x3ed3:
    case 0x3ed4:
    case 0x4022:
        return func_001C0F90(self, 7, 0, &flag, &flag, &flag);

    case 0x3ed5:
    case 0x401c:
        return func_001C0F90(self, 7, 2, &flag, &flag, &flag);

    case 0x3ed7:
    case 0x3ed8:
        return func_001C0F90(self, 7, 1, &flag, &flag, &flag);

    case 0x3ed6:
        return func_001C0F90(self, 7, 3, &flag, &flag, &flag);

    case 0x3ecf:
    case 0x3ed0:
    case 0x3ed1:
    case 0x401b:
    case 0x4055:
        return func_001C0F90(self, 6, 0, &flag, &flag, &flag);

    case 0x3ece:
    case 0x4018:
    case 0x4019:
        return func_001C0F90(self, 6, 1, &flag, &flag, &flag);

    case 0x3ee3:
        return func_001C0F90(self, 10, 0, &flag, &flag, &flag);

    case 0x402a:
    case 0x402d:
        return func_001C0F90(self, 5, 4, &flag, &flag, &flag);

    case 0x4028:
    case 0x4029:
        return func_001C0F90(self, 5, 5, &flag, &flag, &flag);

    case 0x3eea:
    case 0x4049:
        return func_001C0F90(self, 5, 8, &flag, &flag, &flag);

    case 0x3ed9:
        return func_001C0F90(self, 5, 1, &flag, &flag, &flag);

    case 0x3eda:
        return func_001C0F90(self, 5, 0, &flag, &flag, &flag);

    case 0x4034:
    case 0x3fb5:
    case 0x3edb:
        return func_001C0F90(self, 5, 2, &flag, &flag, &flag);

    case 0x3f9f:
        return func_001C0F90(self, 5, 3, &flag, &flag, &flag);

    case 0x403b:
        return func_001C0F90(self, 5, 7, &flag, &flag, &flag);

    case 0x3ee4:
        return func_001C0F90(self, 11, 0, &flag, &flag, &flag);

    case 0x3ede:
    case 0x3fa1:
    case 0x403e:
        return func_001C0F90(self, 9, 0, &flag, &flag, &flag);

    case 0x3edd:
        return func_001C0F90(self, 9, 3, &flag, &flag, &flag);

    case 0x3ee0:
    case 0x4037:
        return func_001C0F90(self, 9, 1, &flag, &flag, &flag);

    case 0x3edf:
    case 0x4040:
    case 0x406d:
        return func_001C0F90(self, 9, 2, &flag, &flag, &flag);

    case 0x3ec4:
    case 0x3ec6:
    case 0x4057:
        return func_001C0F90(self, 8, 2, &flag, &flag, &flag);

    case 0x4020:
    case 0x4021:
        return func_001C0F90(self, 8, 1, &flag, &flag, &flag);

    case 0x3fc6:
    case 0x403c:
        return func_001C0F90(self, 8, 0, &flag, &flag, &flag);

    case 0x3ef9:
        return func_001C0F90(self, 4, 0, &flag, &flag, &flag);

    case 0x405a:
        return func_001C0F90(self, 4, 2, &flag, &flag, &flag);

    case 0x405c:
        return func_001C0F90(self, 4, 3, &flag, &flag, &flag);

    case 0x405e:
        return func_001C0F90(self, 4, 4, &flag, &flag, &flag);

    case 0x4060:
        return func_001C0F90(self, 4, 5, &flag, &flag, &flag);

    case 0x3ee5:
    case 0x3ee6:
    case 0x3ee7:
    case 0x3ee8:
    case 0x3ee9:
    case 0x3eeb:
    case 0x3eec:
    case 0x3eed:
    case 0x3eee:
    case 0x3eef:
    case 0x3ef0:
    case 0x40be:
    case 0x3ef1:
        return func_001C0F90(self, 13, 1, &flag, &flag, &flag);

    case 0x3ffd:
        return func_001C0F90(self, 13, 0, &flag, &flag, &flag);

    default:
        return 0;
    }
}
